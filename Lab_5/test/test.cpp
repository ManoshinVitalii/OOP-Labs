#include "../include/allocator.h"
#include "../include/queue.h"
#include "../include/iterator.h"

#include <gtest/gtest.h>
#include <map>
#include <vector>

TEST(test_01, testAllocatorManyAlloc)
{
    Allocator<double> test;
    double *ptr = test.allocate(450);
    test.free();

    ASSERT_TRUE(1);
}

TEST(test_02, testAllocatorCheckDestroy)
{
    Allocator<char> test;
    char *ptr = test.allocate(25);
    test.allocate(1);
    test.allocate(1);
    test.destroy(ptr);

    ASSERT_TRUE(1);
}

TEST(test_03, testAllocatorCheckDestructor)
{
    Allocator<char> test;
    char *ptr = test.allocate(25);
    test.allocate(1);
    test.allocate(1);
    ASSERT_TRUE(1);
}

TEST(test_04, testAllocatorCheck)
{
    Allocator<size_t> test;
    size_t *ptr = test.allocate(25);
    test.allocate(300);
    test.allocate(300);
    test.allocate(300);
    test.allocate(300);
    test.free();
    ASSERT_TRUE(1);
}

TEST(test_05, testAllocatorCheckToMap)
{
    map<int, uint64_t, less<uint64_t>, Allocator<pair<const int, uint64_t>>> test;
    for (size_t i = 0; i < 1000; ++i)  
        test[i] = i + 1; 
    ASSERT_TRUE(1);
}

TEST(test_08, testIteratorFLBegin)
{
    Queue<int> test{1, 2, 3, 4};
    begin(test);
    Iterator<int> it = test.begin();
    ASSERT_TRUE(begin(test) == it);
}

TEST(test_09, testIteratorFLEnd)
{
    Queue<int> test{1, 2, 3};
    end(test);
    Iterator<int> it = test.end();

    ASSERT_TRUE(end(test) == it);
}

TEST(test_10, testIteratorFLOperatorStars)
{
    Queue<int> test{1, 2, 3};
    Iterator<int> it = test.begin();
    begin(test);

    ASSERT_TRUE(*std::begin(test) == *it);
}

TEST(test_11, testIteratorFLOperatorPlus)
{
    Queue<int> test{1, 2, 3};
    Iterator<int> it = test.begin() + 2;

    ASSERT_TRUE(*(std::begin(test) + 2) == *it);
}

TEST(test_12, testIteratorFLOperatorEqual)
{
    Queue<int> test{1, 2, 3};
    Iterator<int> it = test.begin();
    Iterator<int> itCopy = test.begin();

    ASSERT_TRUE(itCopy == it);
}

TEST(test_13, testIteratorFLOperatorUnequal)
{
    Queue<int> test{1, 2, 3};
    Iterator<int> it = test.begin();
    Iterator<int> itCopy = test.begin();
    ++itCopy;

    ASSERT_TRUE(itCopy != it);
}

TEST(test_14, testConstIteratorFLBegin)
{
    Queue<int> test{1, 2, 3, 4};
    ConstIterator<int> it = test.CBegin();

    ASSERT_TRUE(*cbegin(test) == *it);
}

TEST(test_15, testConstIteratorFLEnd)
{
    Queue<int> test{1, 2, 3};
    ConstIterator<int> it = test.CEnd();
    ConstIterator<int> itCopy = test.CEnd();

    ASSERT_TRUE(itCopy == it);
}

TEST(test_16, testConstIteratorFLOperatorStars)
{
    Queue<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin();
    cbegin(test);

    ASSERT_TRUE(*begin(test) == *it);
}

TEST(test_17, testIteratorFLOperatorPlus)
{
    Queue<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin() + 2;

    ASSERT_TRUE(*(cbegin(test) + 2) == *it);
}

TEST(test_18, testConstIteratorFLOperatorEqual)
{
    Queue<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin();
    ConstIterator<int> itCopy = test.CBegin();

    ASSERT_TRUE(itCopy == it);
}

TEST(test_19, testConstIteratorFLOperatorUnequal)
{
    Queue<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin();
    ConstIterator<int> itCopy = ++test.CBegin();

    ASSERT_TRUE(itCopy != it);
}

TEST(test_20, testForwardListConstructorInt)
{
    Queue<int> l1;
    Queue<int> l11;
    Queue<int> l2(3, 3);
    Queue<int> l3{3, 3, 3};
    Queue<int> l4{1, 2, 3, 4, 5};
    ASSERT_TRUE(l1.size() == l1.size() && *l2.begin() == *l3.begin());
}

TEST(test_21, testForwardListConstructorUChar)
{
    Queue<unsigned char> l1;
    Queue<unsigned char> l11;
    Queue<unsigned char> l2('1', 3);
    Queue<unsigned char> l3{'1', '1', '1'};
    Queue<unsigned char> l4{'1', '2', '3'};

    ASSERT_TRUE(l1.size() == l1.size() && *l2.begin() == *l3.begin());
}

TEST(test_22, testForwardListSize)
{
    Queue<int> l1{1, 2, 3, 4, 5};
    Queue<int> l2;

    ASSERT_TRUE((l1.size() == 5) && (l2.size() == 0));
}

TEST(test_23, testForwardListEmpty)
{
    Queue<int> l1{1, 2, 3, 4, 5};
    Queue<int> l2;
    ASSERT_TRUE(!(l1.empty()) && l2.empty());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
