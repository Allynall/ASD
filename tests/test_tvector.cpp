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

//bool test_47_find_all_elem() {
//    int arr[14] = { 1, 2, 3, 4, 5, 10, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr, 14);
//    int* actual_res = find_elems(vec1, 10);
//    int expected_res[2] = { 5, 9 };
//    for (int i = 0; i < 2; i++) {
//        if (actual_res[i] != expected_res[i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool test_49_find_first_elem_in_empty_mass() {
//    TVector<int> vec1;
//
//    bool expected_result = true;
//    bool actual_result = false;
//    try {
//        find_first(vec1, 6);
//    }
//    catch (const std::exception& ex) {
//        actual_result = true;
//    }
//
//    return TestSystem::check(expected_result, actual_result);
//}
//
//bool test_50_find_last_elem_in_empty_mass() {
//    TVector<int> vec1;
//
//    bool expected_result = true;
//    bool actual_result = false;
//    try {
//        find_last(vec1, 6);
//    }
//    catch (const std::exception& ex) {
//        actual_result = true;
//    }
//
//    return TestSystem::check(expected_result, actual_result);
//}
//bool test_51_find_all_elem_in_empty_mass() {
//    TVector<int> vec1;
//
//    bool expected_result = true;
//    bool actual_result = false;
//    try {
//        find_elems(vec1, 6);
//    }
//    catch (const std::exception& ex) {
//        actual_result = true;
//    }
//
//    return TestSystem::check(expected_result, actual_result);
//}
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

//bool test_35_arr_and_size_constructor() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec(arr, 14);
//    if (vec.size() != 14) return false;
//    if (vec.capacity() != 15) return false;
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (vec.data()[i] != arr[i]) {
//            return false;
//        }
//    }
//    for (size_t i = 0; i < vec.size(); i++) {
//        if (vec.states()[i] != busy) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool test_36_arr_and_size_null_constructor() {
//    const char* arr = nullptr;
//    TVector<char> vec(arr, 0);
//    return TestSystem::check(arr, vec.data()) &&
//        TestSystem::check((size_t)0, vec.capacity()) &&
//        TestSystem::check((size_t)0, vec.size());
//}
//
//bool test_37_copy_constructor() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr, 14);
//    TVector<int> vec2(vec1);
//    if (vec2.size() != 14) return false;
//    if (vec2.capacity() != 15) return false;
//    for (size_t i = 0; i < vec2.size(); i++) {
//        if (vec1.data()[i] != vec2.data()[i]) return false;
//    }
//    return true;
//}
//
//bool test_38_null_copy_constructor() {
//    const char* arr = nullptr;
//    TVector<char> vec1(arr, 0);
//    TVector<char> vec2(vec1);
//    return TestSystem::check(vec1.data(), vec2.data()) &&
//        TestSystem::check((size_t)0, vec2.capacity()) &&
//        TestSystem::check((size_t)0, vec2.size());
//}
//
//bool test_39_assign() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec(arr, 14);
//    vec.assign(4, 444);
//    int expected_res[4] = { 444, 444, 444, 444 };
//    for (int i = 0; i < 4; i++) {
//        if (vec[i] != expected_res[i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool test_40_assign_in_empty_vec() {
//    TVector<int> vec;
//    vec.assign(4, 444);
//    int expected_res[4] = { 444, 444, 444, 444 };
//    for (int i = 0; i < 4; i++) {
//        if (vec[i] != expected_res[i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool test_41_assign_zero_count() {
//    TVector<int> vec;
//    vec.assign(0, 42);
//    return vec.size() == 0 && vec.capacity() == STEP_OF_CAPACITY;
//}
//
//bool test_42_assign_large_count() {
//    TVector<int> vec;
//    int huge = 1000000;
//    vec.assign(huge, 42);
//
//    if (vec.size() != huge) {
//        return false;
//    }
//
//    for (int i = 0; i < huge; i += 1000) {
//        if (vec[i] != 42) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool test_repeated_assign() {
//    TVector<int> vec;
//    vec.assign(10, 1);
//    vec.assign(5, 2);
//
//    if (vec.size() != 5) {
//        return false;
//    }
//
//    for (int i = 0; i < 5; ++i) {
//        if (vec[i] != 2) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool test_53_clear() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec(arr, 14);
//    vec.clear();
//    if (vec.size() != 0) return false;
//    for (size_t i = 0; i < vec.capacity(); ++i) {
//        if (vec.states()[i] != empty) return false;
//    }
//    return true;
//}
//
//bool test_54_null_clear() {
//    TVector<char> vec;
//    vec.clear();
//    if (vec.size() != 0) return false;
//    if (vec.capacity() != STEP_OF_CAPACITY) return false;
//    return true;
//}
//
//bool test_55_reserve_return() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec(arr, 14);
//    vec.reserve(13);
//    if (vec.capacity() != 15) return false;
//    return true;
//}
//
//bool test_56_reserve() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec(arr, 14);
//    vec.reserve(17);
//    if (vec.capacity() != 17) return false;
//    return true;
//}
//
//bool test_57_reserve_null_arr() {
//    TVector<int> vec;
//    vec.reserve(5);
//    if (vec.capacity() != 15) return false;
//    if (vec.size() != 0) return false;
//    return true;
//}
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
//
//bool test_70_overload_equal_empty_vec() {
//    TVector<int> vec1(5);
//    TVector<int> vec2;
//
//    vec1 = vec2;
//
//    if (vec1.size() != 0) return false;
//    if (vec1.capacity() != 15) return false;
//
//    return true;
//}
//
//bool test_71_overload_self_sealing() {
//    int expected_data[5] = { 1, 2, 3, 4, 5 };
//    int expected_states[5] = { 1, 1, 1, 1, 1 };
//    TVector<int> vec1(expected_data, 5);
//    const size_t expected_capacity = vec1.capacity();
//    const size_t expected_size = vec1.size();
//
//    vec1 = vec1;
//
//    for (size_t i = 0; i < vec1.size(); i++) {
//        if (vec1.data()[i] != expected_data[i]) return false;
//        if (vec1.states()[i] != expected_states[i]) return false;
//    }
//
//    return TestSystem::check(vec1.capacity(), expected_capacity) &&
//        TestSystem::check(vec1.size(), expected_size);
//}
//
//bool test_72_comparison_operator_false() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    int arr2[7] = { 1, 2, 3, 4, 5, 6, 7 };
//    TVector<int> vec2(arr2, 7);
//
//    bool expected_res = false;
//    bool actual_res = (vec1 == vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_73_comparison_operator_true() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    TVector<int> vec2(vec1);
//
//    bool expected_res = true;
//    bool actual_res = (vec1 == vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_74_comparison_operator_partially_filled() {
//    TVector<int> vec1(10);
//    TVector<int> vec2(10);
//    for (int i = 0; i < 5; ++i) {
//        vec1[i] = i;
//        vec2[i] = i;
//    }
//    bool expected_res = true;
//    bool actual_res = (vec1 == vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_75_comparison_operator_empty_vecs() {
//    TVector<int> vec1;
//    TVector<int> vec2;
//
//    bool expected_res = true;
//    bool actual_res = (vec1 == vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_76_comparison_operator_with_erase() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    TVector<int> vec2(5);
//
//    vec1.erase_elem(6);
//
//    bool expected_res = false;
//    bool actual_res = (vec1 == vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_77_comparison_operator_with_reserve() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    TVector<int> vec2(vec1);
//
//    vec1.reserve(35);
//
//    bool expected_res = true;
//    bool actual_res = (vec1 == vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_78_comparison_operator_deleted() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    int arr2[15] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec2(arr2, 15);
//
//    vec1.pop_front_elem();
//
//    bool expected_res = true;
//    bool actual_res = (vec1 == vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_79_operator_not_equal_false() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    int arr2[7] = { 1, 2, 3, 4, 5, 6, 7 };
//    TVector<int> vec2(arr2, 7);
//
//    bool expected_res = true;
//    bool actual_res = (vec1 != vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_80_operator_not_equal_true() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    TVector<int> vec2(vec1);
//
//    bool expected_res = false;
//    bool actual_res = (vec1 != vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_81_operator_not_equal_partially_filled() {
//    TVector<int> vec1(10);
//    TVector<int> vec2(10);
//    for (int i = 0; i < 5; ++i) {
//        vec1[i] = i;
//        vec2[i] = i;
//    }
//
//    bool expected_res = false;
//    bool actual_res = (vec1 != vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_82_operator_not_equal_empty_vecs() {
//    TVector<int> vec1;
//    TVector<int> vec2;
//
//    bool expected_res = false;
//    bool actual_res = (vec1 != vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_83_operator_not_equal_with_erase() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    TVector<int> vec2(5);
//
//    vec1.erase_elem(6);
//
//    bool expected_res = true;
//    bool actual_res = (vec1 != vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_84_operator_not_equal_with_reserve() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    TVector<int> vec2(vec1);
//
//    vec1.reserve(35);
//
//    bool expected_res = false;
//    bool actual_res = (vec1 != vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_85_operator_not_equal_deleted() {
//    int arr1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec1(arr1, 16);
//    int arr2[15] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec2(arr2, 15);
//
//    vec1.pop_front_elem();
//
//    bool expected_res = false;
//    bool actual_res = (vec1 != vec2);
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_86_operator_square_brackets() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//
//    int expected_res = 8;
//    int actual_res = vec[7];
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//bool test_87_operator_square_brackets_first_last() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//
//    return TestSystem::check(1, vec[0]) &&
//        TestSystem::check(16, vec[15]);
//}
//
//bool test_88_operator_square_brackets_with_delete() {
//    //ненужный
//    return true;
//
//}
//
//bool test_89_operator_square_brackets_deleted_elems() {
//    int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//    TVector<int> vec(arr, 16);
//
//    vec.erase_elems(4, 3);
//
//    int expected_res = 7;
//    int actual_res = vec[3];
//
//    return TestSystem::check(expected_res, actual_res);
//}
//
//
//bool test_90_at() {
//    int arr[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//    TVector<int> vec1(arr, 14);
//    int expected_res = 1;
//    int actual_res = vec1.at(1);
//    return TestSystem::check(actual_res, expected_res);
//}
//
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
