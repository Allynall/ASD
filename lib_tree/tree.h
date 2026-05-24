#include <iostream>
#include <iomanip>
#include "../lib_node/node.h"
#include "../lib_queue_through_list/queue_through_list..h"

template <class TKey, class TValue>
struct NodeTr {
	std::pair<TKey, TValue> data;
	NodeTr* left;
	NodeTr* right;
	NodeTr* parent; 
	size_t height;   

	NodeTr() : data(std::pair<TKey, TValue>()), left(nullptr), right(nullptr), parent(nullptr), height(1) {}

	NodeTr(std::pair<TKey, TValue> data_, NodeTr* left_, NodeTr* right_)
		: data(data_), left(left_), right(right_), parent(nullptr), height(1) {
	};

	NodeTr(const TKey& key, const TValue& value)
		: data(std::make_pair(key, value)), left(nullptr), right(nullptr), parent(nullptr), height(1) {
	};

	NodeTr(const NodeTr& other) {
		data = other.data;
		left = other.left;
		right = other.right;
		parent = other.parent;
		height = other.height;
	}
	~NodeTr() = default;

	friend std::ostream& operator<<(std::ostream& os, const NodeTr& node) {
		os << "(" << node.data.first << ", " << node.data.second << ")";
		return os;
	}
};
template <class TKey, class TValue>
class Tree {
	NodeTr<TKey, TValue>* _root;
public:

	Tree(); //++
	~Tree(); //++

	void insert(const TKey&, const TValue);  //++
	TValue* find(const TKey&) const noexcept; //++
	void erase(const TKey&); //

	void clear() noexcept; //++
	bool is_empty() const noexcept; //++

	void print_w() const noexcept; //++
	void print_DLCR() const noexcept;  //++
	void print_DLRC() const noexcept; //++
	void print_DCLR() const noexcept; //+

private:
	void clear_rec(NodeTr<TKey, TValue>* node) noexcept; //+
	void print_DLCR_rec(NodeTr<TKey, TValue>* node) const; //+
	void print_DLRC_rec(NodeTr<TKey, TValue>* node) const; //+
	void print_DCLR_rec(NodeTr<TKey, TValue>* node) const; //+
};

template <class TKey, class TValue>
Tree<TKey, TValue>::Tree() : _root(nullptr){
}

template <class TKey, class TValue>
Tree<TKey, TValue>::~Tree() {
	clear();
}

template <class TKey, class TValue>
bool Tree<TKey, TValue>::is_empty() const noexcept {
	return _root == nullptr;
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::clear_rec(NodeTr<TKey, TValue>* node) noexcept {
	if (!node) return;

	clear_rec(node->left);
	clear_rec(node->right);
	delete node;
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::clear() noexcept {
	clear_rec(_root);
	_root = nullptr;
}


template <class TKey, class TValue>
void Tree<TKey, TValue>::insert(const TKey& key, const TValue val) {
	NodeTr<TKey, TValue>* node = new NodeTr<TKey, TValue>(key, val);
	if (is_empty()) {
		_root = node;
		return;
	}
	if (find(key) != nullptr) {
		throw std::logic_error("The key is busy");
	}
	NodeTr<TKey, TValue>* cur = nullptr;
	QueueThroughList<NodeTr<TKey, TValue>*> q;  
	q.push(_root);
	while (1) {
		cur = q.head();
		q.pop();
		if (!cur->left) {
			cur->left = node;
			return;
		}
		if (!cur->right) {
			cur->right = node;
			return;
		}
		q.push(cur->left);
		q.push(cur->right);
	}
}

template <class TKey, class TValue>
TValue* Tree<TKey, TValue>::find(const TKey& key) const noexcept {
	if (is_empty()) {
		return nullptr;
	}

	NodeTr<TKey, TValue>* current = _root;
	QueueThroughList<NodeTr<TKey, TValue>*> q;  
	q.push(current);

	while (!q.is_empty()) {
		current = q.head();
		q.pop();

		if (current->data.first == key) {
			return &(current->data.second);
		}

		if (current->left) {
			q.push(current->left);
		}
		if (current->right) {
			q.push(current->right);
		}
	}

	return nullptr;
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::erase(const TKey& key) {
	if (is_empty()) {
		throw std::logic_error("Tree is empty");
	}

	NodeTr<TKey, TValue>* node_to_delete = nullptr;
	NodeTr<TKey, TValue>* last_parent = nullptr;
	NodeTr<TKey, TValue>* last = _root;

	QueueThroughList<NodeTr<TKey, TValue>*> q;
	q.push(_root);

	while (!q.is_empty()) {
		NodeTr<TKey, TValue>* cur = q.head(); 
		q.pop();

		if (cur->data.first == key) {
			node_to_delete = cur;
		}
		if (cur->left) {
			last_parent = cur; 
			last = cur->left; 
			q.push(cur->left);
		}
		if (cur->right) {
			last_parent = cur; 
			last = cur->right; 
			q.push(cur->right);
		}
	}

	if (!node_to_delete) {
		throw std::logic_error("Key not found");
	}

	if (node_to_delete != last) {
		node_to_delete->data = last->data;
	}


	if (!last_parent) {
		delete _root; 
		_root = nullptr;
	}
	else if (last_parent->right == last) {
		delete last_parent->right; 
		last_parent->right = nullptr;
	}
	else {
		delete last_parent->left;  
		last_parent->left = nullptr;
	}
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::print_w() const noexcept {
	if (is_empty()) return;
	QueueThroughList<NodeTr<TKey, TValue>*> q; 
	NodeTr<TKey, TValue>* cur = nullptr;
	q.push(_root);
	while (!q.is_empty()) {
		cur = q.head();
		q.pop(); 
		std::cout << "(" << cur->data.second << ") ";
		if (cur->left) {
			q.push(cur->left);
		}
		if (cur->right) {
			q.push(cur->right);
		}
	}
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::print_DLCR() const noexcept {
	if (is_empty()) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}

	print_DLCR_rec(_root);
	std::cout << std::endl;
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::print_DCLR() const noexcept {
	if (is_empty()) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}

	print_DCLR_rec(_root);
	std::cout << std::endl;
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::print_DLRC() const noexcept {
	if (is_empty()) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}

	print_DLRC_rec(_root);
	std::cout << std::endl;
}

template <class TKey, class TValue>
void Tree<TKey, TValue>::print_DLCR_rec(NodeTr<TKey, TValue>* node) const {
	if (node == nullptr) {
		return;
	}
	print_DLCR_rec(node->left);
	std::cout << "(" << node->data.second << ") ";
	print_DLCR_rec(node->right);

}

template <class TKey, class TValue>
void Tree<TKey, TValue>::print_DCLR_rec(NodeTr<TKey, TValue>* node) const {
	if (node == nullptr) {
		return;
	}


	std::cout << "(" << node->data.second << ") ";
	print_DCLR_rec(node->left);
	print_DCLR_rec(node->right);

}


template <class TKey, class TValue>
void Tree<TKey, TValue>::print_DLRC_rec(NodeTr<TKey, TValue>* node) const {
	if (node == nullptr) {
		return;
	}

	print_DLRC_rec(node->left);
	print_DLRC_rec(node->right);
	std::cout << "(" << node->data.second << ") ";

}

