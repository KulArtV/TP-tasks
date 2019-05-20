#include "vector.h"
#include <gtest/gtest.h>
#include <limits>

TEST(AT_FUNCTION, BEFORE_START) {
    Vector<int> v(5, 37);
    ASSERT_ANY_THROW(v.At(-1));
}

TEST(AT_FUNCTION, START) {
    Vector<int> v(5, 37);
    ASSERT_NO_THROW(v.At(0));
}

TEST(AT_FUNCTION, MIDDLE) {
    Vector<int> v(5, 37);
    ASSERT_NO_THROW(v.At(2));
}

TEST(AT_FUNCTION, BEFORE_END) {
    Vector<int> v(5, 37);
    ASSERT_NO_THROW(v.At(4));
}

TEST(AT_FUNCTION, END) {
    Vector<int> v(5, 37);
    ASSERT_ANY_THROW(v.At(5));
}

TEST(AT_FUNCTION, EMPTY_VECTOR) {
    Vector<int> v(0);
    ASSERT_ANY_THROW(v.At(-1));
    ASSERT_ANY_THROW(v.At(0));
    ASSERT_ANY_THROW(v.At(1));
}

TEST(ASSIGN_FUNCTION, ZERO_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_EQ(5, v.At(0));
}

TEST(ASSIGN_FUNCTION, MIDDLE_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_EQ(5, v.At(2));
}

TEST(ASSIGN_FUNCTION, RBEGIN_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_EQ(5, v.At(4));
}

TEST(ASSIGN_FUNCTION, END_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_EQ(5, v.At(5));
}

TEST(OPERATOR_SQUARED_BRACKETS, REND_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_NO_THROW(v[-1]);
}

TEST(OPERATOR_SQUARED_BRACKETS, BEGIN_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_NO_THROW(v[0]);
}

TEST(OPERATOR_SQUARED_BRACKETS, MIDDLE) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_NO_THROW(v[2]);
}

TEST(OPERATOR_SQUARED_BRACKETS, RBEGIN_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_NO_THROW(v[4]);
}

TEST(OPERATOR_SQUARED_BRACKETS, END_ELEMENT) {
    Vector<int> v;
    v.Assign(37, 5);
    ASSERT_NO_THROW(v[5]);
}

TEST(FRONT_FUNCTION, EMPTY_VECTOR) {
    Vector<int> v;
    ASSERT_NO_THROW(v.Front());
}

TEST(FRONT_FUNCTION, NOT_EMPTY_VECTOR) {
    Vector<int> v(2);
    ASSERT_NO_THROW(v.Front());
}

TEST(BACK_FUNCTION, EMPTY_VECTOR) {
    Vector<int> v;
    ASSERT_NO_THROW(v.Back());
}

TEST(BACK_FUNCTION, NOT_EMPTY_VECTOR) {
    Vector<int> v(2);
    ASSERT_NO_THROW(v.Back());
}

TEST(RESERVE_FUNCTION, NON_REALLOC) {
    Vector<int> v(5, 37);
    int* prev_vector_ptr = v.Data();
    v.Reserve(2);
    int* new_vector_ptr = v.Data();
    ASSERT_EQ(prev_vector_ptr, new_vector_ptr);
}

TEST(RESERVE_FUNCTION, REALLOC) {
    Vector<int> v(5, 37);
    int* prev_vector_ptr = v.Data();
    v.Reserve(10);
    int* new_vector_ptr = v.Data();
    ASSERT_NE(prev_vector_ptr, new_vector_ptr);
}

TEST(RESERVE_FUNCTION, MAX_SIZE) {
    Vector<int> v;
    int* prev_vector_ptr = v.Data();
    v.Reserve(v.MaxSize());
    int* new_vector_ptr = v.Data();
    ASSERT_EQ(prev_vector_ptr, new_vector_ptr);
}

TEST(RESERVE_FUNCTION, MORE_THAN_MAX_SIZE) {
    Vector<int> v;
    ASSERT_NO_THROW(v.Reserve(v.MaxSize() + 1));
}

TEST(SIZE_AND_CAPACITY_FUNCTION, SIZE_EQUALS_CAPACITY) {
    Vector<int> v;
    for (int i = 0; i < 4; ++i) {
        v.PushBack(i);
    }
    ASSERT_EQ(v.Size(), v.Capacity());
}

TEST(SIZE_AND_CAPACITY_FUNCTION, SIZE_NOT_EQUALS_CAPACITY) {
    Vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.PushBack(i);
    }
    ASSERT_NE(v.Size(), v.Capacity());
}

TEST(SHRINK_TO_FIT_FUNCTION, SIZE_EQUALS_CAPACITY) {
    Vector<int> v;
    for (int i = 0; i < 4; ++i) {
        v.PushBack(i);
    }
    v.ShrinkToFit();
    ASSERT_EQ(v.Size(), v.Capacity());
}

TEST(SHRINK_TO_FIT_FUNCTION, SIZE_NOT_EQUALS_CAPACITY) {
    Vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.PushBack(i);
    }
    v.ShrinkToFit();
    ASSERT_EQ(v.Size(), v.Capacity());
}

//Resize tests are same as Reserve tests

TEST(PUSH_BACK_FUNCTION, EMPTY_VECTOR) {
    Vector<int> v;
    v.PushBack(1);
    ASSERT_EQ(1, v[0]);
}

TEST(PUSH_BACK_FUNCTION, SMALL_SIZE_VECTOR) {
    Vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.PushBack(i);
    }
    ASSERT_EQ(5, v[5]);
}

TEST(PUSH_BACK_FUNCTION, MAX_SIZE_INT_VECTOR) {
    Vector<int> v;
    int max_size = std::numeric_limits<int>::max() / 5;
    v.Reserve(max_size);
    for (int i = 0; i < max_size; ++i) {
        v.PushBack(i);
    }
    ASSERT_EQ((std::numeric_limits<int>::max() / 5) - 1, *(v.End() - 1));
}

TEST(POP_BACK_FUNCTION, NOT_EMPTY_VECTOR) {
    Vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.PushBack(i);
    }
    int prev_elem = *(v.End() - 1);
    v.PopBack();
    int new_elem = *(v.End() - 1);
    ASSERT_EQ(prev_elem - 1, new_elem);
}

TEST(POP_BACK_FUNCTION, EMPTY_VECTOR) {
    Vector<int> v;
    ASSERT_NO_THROW(v.PopBack());
}

TEST(SWAP_FUNCTION, BOTH_EMPTY) {
    Vector<int> v1, v2;
    ASSERT_NO_THROW(v1.Swap(v2));
}

TEST(SWAP_FUNCTION, ONLY_ONE_EMPTY) {
    Vector<int> v1;
    Vector<int> v2(5, 37);
    ASSERT_NO_THROW(v1.Swap(v2));
}

TEST(SWAP_FUNCTION, NO_ONE_EMPTY) {
    Vector<int> v1(5, 46);
    Vector<int> v2(5, 37);
    v1.Swap(v2);
    ASSERT_EQ(v2[0], 46);
}

template <class T>
::testing::AssertionResult IsSorted(Vector<T>& v) {
    bool isSorted = true;
    for (int i = 0; i < v.Size() - 1; ++i) {
        if (v[i] > v[i + 1]) {
            isSorted = false;
        }
    }
    if (isSorted) {
        return ::testing::AssertionSuccess();
    } else {
        return ::testing::AssertionFailure() << "Vector v is not sorted";
    }
}


TEST(SORT_ALGO, SMALL_VECTOR) {
    Vector<int> v;
    for (int i = 0; i < 50; ++i) {
        v.PushBack((i % 7) * (i % 3));
    }
    Sort<int>(v.Begin(), v.End());
    EXPECT_TRUE(IsSorted(v));
}

TEST(SORT_ALGO, MEDIUM_VECTOR) {
    Vector<int> v;
    for (int i = 0; i < 1e5; ++i) {
        v.PushBack((i % 337) * (i % 221));
    }
    Sort<int>(v.Begin(), v.End());
    EXPECT_TRUE(IsSorted(v));
}

TEST(SORT_ALGO, LARGE_VECTOR) {
    Vector<int> v;
    v.Reserve(static_cast<int>(1e6) * 5);
    for (int i = 0; i < 1e6 * 5; ++i) {
        v.PushBack((i % 2267) * (i % 2397));
    }
    Sort<int>(v.Begin(), v.End());
    EXPECT_TRUE(IsSorted(v));
}

TEST(SORT_ALGO, LARGE_SAME_ELEMENT_VECTOR) {
    Vector<int> v;
    v.Reserve(static_cast<int>(1e6) * 5);
    for (int i = 0; i < 1e6 * 5; ++i) {
        v.PushBack(2);
    }
    Sort<int>(v.Begin(), v.End());
    EXPECT_TRUE(IsSorted(v));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
