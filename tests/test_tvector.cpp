//#include <windows.h>
//#include <iostream>
#include <gtest/gtest.h>
#include "../lib_tvector/tvector.h"

TEST(TestTVectorLib, push_front_elem) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    

    // Act
    vec1.push_front_elem(4);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(15, vec1.size());
    EXPECT_EQ(4, vec1.front());
}

TEST(TestTVectorLib, push_back_elem) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });


    // Act
    vec1.push_back_elem(4);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(15, vec1.size());
    EXPECT_EQ(4, vec1.back());
}

TEST(TestTVectorLib, insert_elem) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });


    // Act
    vec1.insert_elem(4, 5);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(15, vec1.size());
    EXPECT_EQ(4, vec1[4]);
}

TEST(TestTVectorLib, push_front_elem_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act
    vec1.push_front_elem(555);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(1, vec1.size());
    EXPECT_EQ(555, vec1.front());
    EXPECT_EQ(555, vec1.back());
}


TEST(TestTVectorLib, push_back_elem_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act
    vec1.push_back_elem(555);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(1, vec1.size());
    EXPECT_EQ(555, vec1.front());
    EXPECT_EQ(555, vec1.back());
}

TEST(TestTVectorLib, insert_elem_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act
    vec1.insert_elem(1, 1);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(1, vec1.size());
    EXPECT_EQ(1, vec1.front());
    EXPECT_EQ(1, vec1.back());
}
TEST(TestTVectorLib, push_front_elems) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    int mass[2] = { 555, 666 };

    // Act
    vec1.push_front_elems(mass, 2);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(16, vec1.size());
    EXPECT_EQ(555, vec1.front());
    EXPECT_EQ(666, vec1[1]);
    EXPECT_EQ(1, vec1[2]);
}
TEST(TestTVectorLib, push_back_elems) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    int mass[2] = { 555, 666 };

    // Act
    vec1.push_back_elems(mass, 2);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(16, vec1.size());
    EXPECT_EQ(666, vec1.back());
    EXPECT_EQ(555, vec1[14]);
    EXPECT_EQ(14, vec1[13]);
}
TEST(TestTVectorLib, insert_elems) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    int mass[2] = { 555, 666 };

    // Act
    vec1.insert_elems(6, mass, 2);

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(16, vec1.size());
    EXPECT_EQ(555, vec1[5]);
    EXPECT_EQ(666, vec1[6]);
    EXPECT_EQ(6, vec1[7]);
    EXPECT_EQ(5, vec1[4]);
}
TEST(TestTVectorLib, push_front_elems_in_empty_mass) {
    // Arrange
    int arr_1[4] = { 555, 666, 777, 888 };
    int mass[4] = { 555, 666, 777, 888 };

    TVector<int> vec1, expected_result(arr_1, 4);
    vec1.push_front_elems(mass, 4);

    // Act
    TVector<int> actual_result = vec1;

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestTVectorLib, push_back_elems_in_empty_mass) {
    // Arrange
    int arr_1[4] = { 555, 666, 777, 888 };
    int mass[4] = { 555, 666, 777, 888 };

    TVector<int> vec1, expected_result(arr_1, 4);
    vec1.push_back_elems(mass, 4);

    // Act
    TVector<int> actual_result = vec1;

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestTVectorLib, insert_elems_in_empty_mass) {
    // Arrange
    int arr_1[4] = { 555, 666, 777, 888 };
    int mass[4] = { 555, 666, 777, 888 };

    TVector<int> vec1, expected_result(arr_1, 4);
    vec1.insert_elems(1, mass, 4);

    // Act
    TVector<int> actual_result = vec1;

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestTVectorLib, insert_elem_error) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr, 14);

    // Act & Assert
    ASSERT_ANY_THROW(vec1.insert_elem(5, 16));
}
TEST(TestTVectorLib, insert_elems_error) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int mass[4] = { 555, 666, 777, 888 };
    TVector<int> vec1(arr, 14);

    // Act & Assert
    ASSERT_ANY_THROW(vec1.insert_elems(18, mass, 4));
}
TEST(TestTVectorLib, pop_front_elem) {
    // Arrange

    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    vec1.pop_front_elem();

    // Assert
    EXPECT_EQ(13, vec1.size());
    EXPECT_EQ(2, vec1.front()); 
}

TEST(TestTVectorLib, pop_back_elem) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    vec1.pop_front_elem();

    // Assert
    EXPECT_EQ(13, vec1.size());
    EXPECT_EQ(13, vec1.back()); //поправить фронт
}
TEST(TestTVectorLib, erase_elem) {
    // Arrange


    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 }); //!!!!
    vec1.erase_elem(4);

    // Assert
    EXPECT_EQ(13, vec1.size());
    EXPECT_EQ(3, vec1[2]);
    EXPECT_EQ(5, vec1[3]);
    EXPECT_EQ(6, vec1[4]);
    
}
TEST(TestTVectorLib, pop_front_elems) {
    // Arrange

    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    vec1.pop_front_elems(2);

    EXPECT_EQ(12, vec1.size());
    EXPECT_EQ(3, vec1.front());
    EXPECT_EQ(4, vec1[1]);
    EXPECT_EQ(5, vec1[2]);
}

TEST(TestTVectorLib, pop_back_elems) {
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    vec1.pop_back_elems(2);

    EXPECT_EQ(12, vec1.size());
    EXPECT_EQ(12, vec1.back());
    EXPECT_EQ(11, vec1[10]);
}

TEST(TestTVectorLib, erase_elems) { //изменить
    // Arrange
    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    vec1.pop_back_elems(2);

    EXPECT_EQ(12, vec1.size());
    EXPECT_EQ(12, vec1.back());
    EXPECT_EQ(11, vec1[10]);
}
TEST(TestTVectorLib, pop_front_elem_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act & Assert
    ASSERT_ANY_THROW(vec1.pop_front_elem());
}
TEST(TestTVectorLib, pop_back_elem_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act & Assert
    ASSERT_ANY_THROW(vec1.pop_back_elem());
}
TEST(TestTVectorLib, erase_elem_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act & Assert
    ASSERT_ANY_THROW(vec1.erase_elem(4));
}
TEST(TestTVectorLib, erase_elem_error) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr, 14);

    // Act & Assert
    ASSERT_ANY_THROW(vec1.erase_elem(15));
}
TEST(TestTVectorLib, pop_front_elems_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act & Assert
    ASSERT_ANY_THROW(vec1.pop_front_elems(2));
}
TEST(TestTVectorLib, pop_back_elems_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act & Assert
    ASSERT_ANY_THROW(vec1.pop_back_elems(2));
}
TEST(TestTVectorLib, erase_elems_in_empty_mass) {
    // Arrange
    TVector<int> vec1;

    // Act & Assert
    ASSERT_ANY_THROW(vec1.erase_elems(4, 2));
}
TEST(TestTVectorLib, pop_front_elems_error) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr, 14);

    // Act & Assert
    ASSERT_ANY_THROW(vec1.pop_front_elems(15));
}

TEST(TestTVectorLib, pop_back_elems_error) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr, 14);

    // Act & Assert
    ASSERT_ANY_THROW(vec1.pop_back_elems(15));
}

TEST(TestTVectorLib, erase_elems_error) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr, 14);

    // Act & Assert
    ASSERT_ANY_THROW(vec1.erase_elems(4, 15));
}

TEST(TestTVectorLib, erase_elems_pos_out_of_range) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr, 14);

    // Act & Assert
    ASSERT_ANY_THROW(vec1.erase_elems(-1, 10));
}
TEST(TestTVectorLib, find_first_elem) {
    // Arrange
    int arr_1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr_1, 14);

    int actual_result = find_first(vec1, 6);
    int expected_result = 5;

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTVectorLib, not_find_first_elem) {
    // Arrange
    int arr_1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr_1, 14);

    int actual_result = find_first(vec1, 111);
    int expected_result = -1;

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTVectorLib, find_last_elem) {
    // Arrange
    int arr_1[14] = { 1, 2, 3, 4, 5, 10, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr_1, 14);

    int actual_result = find_last(vec1, 10);
    int expected_result = 9;

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTVectorLib, not_find_last_elem) {
    // Arrange
    int arr_1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr_1, 14);

    int actual_result = find_last(vec1, 111);
    int expected_result = -1;

    // Assert
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTVectorLib, not_find_elems) {
    // Arrange
    int arr_1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr_1, 14);

    int* find = find_elems(vec1, 111);
    int not_find[1] = { -1 };

    bool actual_result = true;
    bool expected_result = true;

    for (int i = 0; i < 1; i++) {
        if (find[i] != not_find[i]) {
            actual_result = false;
        }
    }
    // Assert
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestTVectorLib, find_all_elem) {
    // Arrange
    int arr_1[14] = { 1, 2, 3, 4, 5, 10, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec1(arr_1, 14);

    int* find = find_elems(vec1, 10);

    int actual_result = true;

    int* find_res = find_elems(vec1, 10);
    int expected_res[2] = { 5, 9 };

    for (int i = 0; i < 1; i++) {
        if (find[i] != expected_res[i]) {
            actual_result = false;
        }
    }
    // Assert
    EXPECT_EQ(true, actual_result);
}

TEST(TestTVectorLib, find_first_elem_in_empty_mass) {
    // Arrang
    TVector<int> vec1;

    ASSERT_ANY_THROW(find_first(vec1, 6));
}

TEST(TestTVectorLib, find_last_elem_in_empty_mass) {
    // Arrang
    TVector<int> vec1;

    ASSERT_ANY_THROW(find_last(vec1, 6));
}

TEST(TestTVectorLib, find_all_elem_in_empty_mass) {
    // Arrang
    TVector<int> vec1;

    ASSERT_ANY_THROW(find_elems(vec1, 6));
}

//bool test_52_emplace() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr, 14);
//    vec1.emplace(7, 11037);
//    int expected_res[14] = { 1, 2, 3, 4, 5, 6, 11037, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec2(expected_res, 14);
//
//    if (vec1 != vec2) {
//        return false;
//    }
//    return true;
//}
TEST(TestTVectorLib, randomize) { 


    TVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });
    randomize(vec1);
    // Assert
    EXPECT_EQ(14, vec1.size());
    EXPECT_EQ(15, vec1.capacity());
}
TEST(TestTVectorLib, randomize_empty_mass) {
    // Arrange

    bool actual_result = true;
    bool expected_result = true;

    TVector<int> vec1;
    randomize(vec1);

    if (vec1.size() != 0 || vec1.capacity() != 15) {
        actual_result = false;
    }
    // Assert
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestTVectorLib, default_constructor) {
    // Arrange
    TVector<int> vec;

    // Assert
    EXPECT_EQ((size_t)15, vec.capacity());
    EXPECT_EQ((size_t)0, vec.size());
}
TEST(TestTVectorLib, default_constructor_char) {
    // Arrange
    TVector<char> vec;

    // Assert
    EXPECT_EQ((size_t)15, vec.capacity());
    EXPECT_EQ((size_t)0, vec.size());
}
TEST(TestTVectorLib, size_null_constructor) {
    // Arrange
    TVector<int> vec(0);

    // Assert
    EXPECT_EQ((size_t)15, vec.capacity());
    EXPECT_EQ((size_t)0, vec.size());
}
TEST(TestTVectorLib, size_constructor) {
    // Arrange
    TVector<int> vec(7);

    // Assert
    EXPECT_EQ((size_t)15, vec.capacity());
    EXPECT_EQ((size_t)7, vec.size());
}

TEST(TestTVectorLib, arr_and_size_constructor) {
    // Arrange
    int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
    TVector<int> vec(arr, 7);

    // Assert
    EXPECT_EQ((size_t)15, vec.capacity());
    EXPECT_EQ((size_t)7, vec.size());
    EXPECT_EQ(vec.front(), 1);
    EXPECT_EQ(vec.back(), 7);
}

TEST(TestTVectorLib, arr_and_size_null_constructor) {
    // Arrange
    char* arr = nullptr;
    TVector<char> vec(arr, 0);

    // Assert
    EXPECT_EQ((size_t)0, vec.capacity());
    EXPECT_EQ((size_t)0, vec.size());
}

TEST(TestTVectorLib, copy_constructor) {
    // Arrange
    int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
    TVector<int> vec1(arr, 7), vec2(vec1);

    // Assert
    EXPECT_EQ(vec1.capacity(), vec2.capacity());
    EXPECT_EQ(vec1.size(), vec2.size());
    EXPECT_EQ(vec1.front(), vec2.front());
    EXPECT_EQ(vec1.back(), vec2.back());
}

TEST(TestTVectorLib, clear) {
    // Arrange
    const char* arr = nullptr;
    TVector<char> vec1(arr, 0), vec2(vec1);

    // Assert
    EXPECT_EQ(vec1.capacity(), vec2.capacity());
    EXPECT_EQ(vec1.size(), vec2.size());
}
TEST(TestTVectorLib, null_copy_constructor) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec(arr, 14);
    vec.clear();

    // Assert
    EXPECT_EQ(vec.states()[0], empty);
    EXPECT_EQ(0, vec.size());
}

TEST(TestTVectorLib, null_clear) {
    // Arrange
    TVector<int> vec;
    vec.clear();

    // Assert
    EXPECT_EQ(vec.states()[0], empty);
    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(15, vec.capacity());
}

TEST(TestTVectorLib, reserve_less) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec(arr, 14);
    vec.reserve(13);

    // Assert
    EXPECT_EQ(15, vec.capacity());
}

TEST(TestTVectorLib, reserve_more) {
    // Arrange
    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    TVector<int> vec(arr, 14);
    vec.reserve(17);

    // Assert
    EXPECT_EQ(17, vec.capacity());
}
TEST(TestTVectorLib, reserve_return) {
    // Arrange
    TVector<int> vec;
    vec.reserve(5);

    // Assert
    EXPECT_EQ(15, vec.capacity());
    EXPECT_EQ(0, vec.size());
}
//
//bool test_58_shrink_to_fit_null_size() {
//    TVector<int> vec;
//    vec.shrink_to_fit();
//    if (vec.capacity() != 0) return false;
//    if (vec.size() != 0) return false;
//    if (vec.data() != nullptr) return false;
//    if (vec.states() != nullptr) return false;
//    return true;
//}
//
//bool test_59_shrink_to_fit() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//    vec.shrink_to_fit();
//    if (vec.capacity() != 16) return false;
//    for (size_t i = 0; i < vec.capacity(); i++) {
//        if (vec.states()[i] != busy) return false;
//    }
//
//    return true;
//}
//bool test_60_shrink_to_fit_after_empty_reserve() {
//    TVector<int> vec;
//    vec.reserve(5);
//
//    if (vec.capacity() < 5) return false;
//    if (vec.size() != 0) return false;
//
//    vec.shrink_to_fit();
//
//    if (vec.capacity() != 0) return false;
//    if (vec.size() != 0) return false;
//    if (vec.data() != nullptr) return false;
//    if (vec.states() != nullptr) return false;
//
//    return true;
//}
//
//bool test_61_resize_decrease() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//
//    vec.resize(13);
//
//    if (vec.size() != 13) return false;
//    for (size_t i = vec.size(); i < vec.capacity(); i++) {
//        if (vec.states()[i] != empty) return false;
//    }
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (arr[i] != vec.data()[i]) return false;
//        if (vec.states()[i] != busy) return false;
//    }
//
//    return true;
//}
//
//bool test_63_resize_increase_empty_vec() {
//    TVector<int> vec;
//
//    vec.resize(3);
//
//    if (vec.size() != 3) return false;
//
//
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (vec.states()[i] != busy) return false;
//    }
//
//    return true;
//}
//
//bool test_62_resize_increase() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//
//    vec.resize(19);
//
//    if (vec.size() != 19) return false;
//
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (vec.states()[i] != busy) return false;
//    }
//    for (size_t i = vec.size(); i < vec.capacity(); i++) {
//        if (vec.states()[i] != empty) return false;
//    }
//
//    return true;
//}
//
//bool test_64_resize_with_value_decrease() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//
//    vec.resize(13, 111);
//
//    vec.print_elems();
//    if (vec.size() != 13) return false;
//    for (size_t i = vec.size(); i < vec.capacity(); i++) {
//        if (vec.states()[i] != empty) return false;
//    }
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (arr[i] != vec.data()[i]) return false;
//        if (vec.states()[i] != busy) return false;
//    }
//
//    return true;
//}
//
//bool test_65_resize_with_value_increase_empty_vec() {
//    TVector<int> vec;
//
//    vec.resize(3, 777);
//
//    if (vec.size() != 3) return false;
//
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (vec.data()[i] != 777) return false;
//        if (vec.states()[i] != busy) return false;
//    }
//
//    return true;
//}
//
//bool test_66_resize_with_value_increase() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//
//    vec.resize(19, 777);
//
//    if (vec.size() != 19) return false;
//
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (vec.states()[i] != busy) return false;
//    }
//
//    for (size_t i = 16; i < 19; i++) {
//        if (vec.data()[i] != 777) return false;
//    }
//
//    return true;
//}
//
//bool test_67_destructor() {
//    TVector<int> vec;
//    vec.push_back_elem(111);
//
//    vec.~TVector();
//
//    if (vec.size() != 0) {
//        return false;
//    }
//    if (vec.capacity() != 0) {
//        return false;
//    }
//    if (vec.data() != nullptr) {
//        return false;
//    }
//    if (vec.states() != nullptr) {
//        return false;
//    }
//    return true;
//}
//bool test_68_overload_equal() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    int arr2[7] = { 1, 2, 3, 4, 5, 6, 7 };
//    TVector<int> vec2(arr2, 7);
//    vec2 = vec1;
//    for (size_t i = 0; i < vec1.size(); i++) {
//        if (vec1.data()[i] != vec2.data()[i]) return false;
//        if (vec1.states()[i] != vec2.states()[i]) return false;
//    }
//    return TestSystem::check(vec1.capacity(), vec2.capacity()) &&
//        TestSystem::check(vec1.size(), vec2.size());
//}
//
//bool test_69_overload_equal_same_vecs() {
//    int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
//    TVector<int> vec1(arr, 7);
//    TVector<int> vec2(vec1);
//    vec2 = vec1;
//    for (size_t i = 0; i < vec1.size(); i++) {
//        if (vec1.data()[i] != vec2.data()[i]) return false;
//        if (vec1.states()[i] != vec2.states()[i]) return false;
//    }
//    return TestSystem::check(vec1.capacity(), vec2.capacity()) &&
//        TestSystem::check(vec1.size(), vec2.size());
//}

TEST(TestTVectorLib, overload_equal_empty_vec) {


    TVector<int> vec1(5), vec2;
    vec1 = vec2;
    // Assert
    EXPECT_EQ(vec1.size(), vec2.size());
    EXPECT_EQ(vec1.capacity(), vec2.capacity());
}
TEST(TestTVectorLib, overload_self_sealing) {


    TVector<int> vec1(5);
    vec1 = vec1;
    // Assert
    EXPECT_EQ(vec1.size(), vec1.size());
    EXPECT_EQ(vec1.capacity(), vec1.capacity());
}

TEST(TestTVectorLib, comparison_operator_false) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int arr2[7] = { 1, 2, 3, 4, 5, 6, 7 };
    TVector<int> vec1(arr1, 16), vec2(arr2, 7);
    // Assert
    EXPECT_FALSE(vec1 == vec2);
}
TEST(TestTVectorLib, comparison_operator_true) {
    int arr1[7] = { 1, 2, 3, 4, 5, 6, 7};
    TVector<int> vec1(arr1, 7), vec2(arr1, 7);
    // Assert
    EXPECT_TRUE(vec1 == vec2);
}

TEST(TestTVectorLib, comparison_operator_empty_vec) {
    TVector<int> vec1, vec2;
    // Assert
    EXPECT_TRUE(vec1 == vec2);
}
TEST(TestTVectorLib, comparison_operator_with_erase) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr1, 16);

    vec1.erase_elem(6);
    // Assert
    EXPECT_FALSE(vec1 == vec2);
}
TEST(TestTVectorLib, comparison_operator_with_reserve) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr1, 16);

    vec1.reserve(35);
    // Assert
    EXPECT_TRUE(vec1 == vec2);
}
TEST(TestTVectorLib, comparison_operator_deleted) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int arr2[15] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr2, 15);

    vec1.pop_front_elem();
    // Assert
    EXPECT_TRUE(vec1 == vec2);
}
TEST(TestTVectorLib, operator_not_equal) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int arr2[15] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr2, 15);
    // Assert
    EXPECT_TRUE(vec1 != vec2);
}
TEST(TestTVectorLib, operator_not_equal_false) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr1, 16);
    // Assert
    EXPECT_FALSE(vec1 != vec2);
}
TEST(TestTVectorLib, operator_not_equal_empty_vecs) {
    TVector<int> vec1, vec2;
    // Assert
    EXPECT_FALSE(vec1 != vec2);
}
TEST(TestTVectorLib, operator_not_equal_with_erase) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr1, 16);

    vec1.erase_elem(6);
    // Assert
    EXPECT_TRUE(vec1 != vec2);
}
TEST(TestTVectorLib, operator_not_equal_with_reserve) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr1, 16);

    vec1.reserve(35);
    // Assert
    EXPECT_FALSE(vec1 != vec2);
}
TEST(TestTVectorLib, operator_not_equal_deleted) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int arr2[15] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec1(arr1, 16), vec2(arr2, 15);

    vec1.pop_front_elem();
    // Assert
    EXPECT_FALSE(vec1 != vec2);
}
TEST(TestTVectorLib, operator_square_brackets) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec(arr1, 16);

    // Assert
    EXPECT_EQ(8, vec[7]);
}
TEST(TestTVectorLib, operator_square_brackets_first_last) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec(arr1, 16);

    // Assert
    EXPECT_EQ(1, vec[0]);
    EXPECT_EQ(16, vec[15]);
}
TEST(TestTVectorLib, at) {
    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    TVector<int> vec(arr1, 16);

    // Assert
    EXPECT_EQ(1, vec.at(1));
}
//bool test_94_pop_front_elem_after_push_front_elem() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int expected_result[15] = { 2, 1, 1, 1, 1, 1,1, 1, 1, 1,1, 1, 1, 1, 1 };
//    TVector<int> vec1(arr, 14), vec2(expected_result, 15);
//    vec1.push_front_elem(4);
//    vec1.pop_front_elem();
//
//    if (vec1.size() != 14) {
//        return false;
//    }
//
//    for (int i = 0; i < 15; i++) {
//        if (vec1.states()[i] != expected_result[i]) {
//            return false;
//        }
//    }
//    return true;
//
//}
//bool test_95_pop_back_elem_after_push_back_elem() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int expected_result[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
//    TVector<int> vec1(arr, 14), vec2(expected_result, 15);
//    vec1.push_back_elem(4);
//    vec1.pop_back_elem();
//
//    if (vec1.size() != 14) {
//        return false;
//    }
//
//
//
//    for (int i = 0; i < 15; i++) {
//        if (vec1.states()[i] != expected_result[i]) {
//            return false;
//        }
//    }
//    return true;
//
//}
//bool test_96_erase_elem_after_insert_elem() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int expected_result[15] = { 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
//    TVector<int> vec1(arr, 14), vec2(expected_result, 15);
//    vec1.insert_elem(4, 4);
//    vec1.erase_elem(4);
//
//    if (vec1.size() != 14) {
//        return false;
//    }
//
//    for (int i = 0; i < 15; i++) {
//        if (vec1.states()[i] != expected_result[i]) {
//            return false;
//        }
//    }
//    return true;
//
//}
//bool test_97_pop_front_elems_after_push_front_elems() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    int arr2[2] = { 1, 2 };
//    int expected_result[18] = { 2, 2, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1, 1, 1, 1, 1, 1 };
//    TVector<int> vec1(arr1, 16), vec2(expected_result, 18);
//    vec1.push_front_elems(arr2, 2);
//    vec1.pop_front_elems(2);
//
//    if (vec1.size() != 16) {
//        return false;
//    }
//    for (int i = 0; i < 18; i++) {
//        if (vec1.states()[i] != expected_result[i]) {
//            return false;
//        }
//    }
//    return true;
//
//}
//bool test_98_pop_back_elems_after_push_back_elems() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    int arr2[2] = { 1, 2 };
//    int expected_result[18] = { 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1, 1, 1, 1, 1, 1, 0, 0 };
//    TVector<int> vec1(arr1, 16), vec2(expected_result, 18);
//    vec1.push_back_elems(arr2, 2);
//    vec1.pop_back_elems(2);
//
//    if (vec1.size() != 16) {
//        return false;
//    }
//    for (int i = 0; i < 18; i++) {
//        if (vec1.states()[i] != expected_result[i]) {
//            return false;
//        }
//    }
//    return true;
//
//}
//bool test_99_erase_elems_after_insert_elems() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    int arr2[2] = { 1, 2 };
//    int expected_result[18] = { 1, 1, 2, 2, 1, 1,1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1 };
//    TVector<int> vec1(arr1, 16), vec2(expected_result, 18);
//    vec1.insert_elems(3, arr2, 2);
//    vec1.erase_elems(3, 2);
//
//    if (vec1.size() != 16) {
//        return false;
//    }
//    for (int i = 0; i < 18; i++) {
//        if (vec1.states()[i] != expected_result[i]) {
//            return false;
//        }
//    }
//    return true;
//
//}
//bool test_103_pop_front_elem_after_emplace_elem() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int expected_result[14] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
//    TVector<int> vec1(arr, 14), vec2(expected_result, 14);
//    vec1.emplace(1, 5);
//    vec1.pop_front_elem();
//
//    if (vec1.size() != 13) {
//        return false;
//    }
//
//    for (int i = 0; i < 14; i++) {
//        if (vec1.states()[i] != expected_result[i]) {
//            return false;
//        }
//    }
//    return true;
//
//}
//bool test_104_pop_back_elem_after_emplace_elem() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 13);
//    vec1.emplace(14, 5);
//    vec1.pop_back_elem();
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_105_erase_elem_after_emplace_elem() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[13] = { 1, 5, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 13);
//    vec1.emplace(2, 5);
//    vec1.erase_elem(3);
//
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//    return true;
//
//}
//bool test_106_erase_elems_after_emplace_elem() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[10] = { 1, 5, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 10);
//    vec1.emplace(2, 5);
//    vec1.erase_elems(3, 4);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_107_emplace_elem_after_erase_elem() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[13] = { 1, 5, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 13);
//    vec1.erase_elem(3);
//    vec1.emplace(2, 5);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_108_emplace_elem_after_erase_elems() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[12] = { 1, 2, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 12);
//    vec1.erase_elems(3, 2);
//    vec1.emplace(3, 5);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//
//bool test_100_found_elem_after_pop_elem() {
//    int arr[14] = { 1, 2, 3, 4, 1, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int expected_result = 3;
//    TVector<int> vec1(arr, 14);
//    vec1.erase_elem(1);
//    int actual_result = find_first(vec1, 1);
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_101_found_elem_after_pop_elems() {
//    int arr[14] = { 1, 2, 3, 1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int expected_result = 1;
//    TVector<int> vec1(arr, 14);
//    vec1.erase_elems(1, 2);
//    int actual_result = find_first(vec1, 1);
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_102_found_all_elems_after_pop_elems() {
//    int arr[14] = { 1, 2, 3, 1, 5, 6, 7, 8, 9, 10, 1, 12, 1, 14 };
//    int arr2[3] = { 1, 8, 10 };
//    TVector<int> vec1(arr, 14), vec2(arr2, 3);
//    vec1.erase_elems(1, 2);
//    int* arr3 = find_elems(vec1, 1);
//    TVector<int> vec3(arr3, 3);
//    bool expected_result = true;
//    bool actual_result = false;
//    if (vec2 == vec3) {
//        actual_result = true;
//    }
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_109_push_front_elem_after_clear() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[1] = { 3 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 1);
//    vec1.clear();
//    vec1.push_front_elem(3);
//
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_110_push_back_elem_after_clear() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[1] = { 3 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 1);
//    vec1.clear();
//    vec1.push_back_elem(3);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_111_insert_elem_after_clear() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[1] = { 3 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 1);
//    vec1.clear();
//    vec1.insert_elem(3, 1);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_112_push_front_elems_after_clear() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[3] = { 1, 2, 3 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 3);
//    vec1.clear();
//    vec1.push_front_elems(arr2, 3);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_113_push_back_elems_after_clear() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[3] = { 1, 2, 3 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 3);
//    vec1.clear();
//    vec1.push_back_elems(arr2, 3);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_114_insert_elems_after_clear() {
//    int arr1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    int arr2[3] = { 1, 2, 3 };
//    TVector<int> vec1(arr1, 14), vec2(arr2, 3);
//    vec1.clear();
//    vec1.insert_elems(1, arr2, 3);
//
//    bool expected_result = true;
//    bool actual_result = vec1 == vec2;
//    return TestSystem::check(expected_result, actual_result);
//
//}
//bool test_insert_string_element() {
//    TVector<std::string> vec;
//
//    // 2. Вставляем строку в начало
//    vec.push_back_elem("Hello");
//    vec.print_elems();
//    return true;
//}
