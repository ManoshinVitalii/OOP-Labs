#include <gtest/gtest.h>
#include "solve.h"

TEST(test_01, basic_test_set) 
{
    ASSERT_TRUE(solve(1,5)==5);
}

TEST(test_02, basic_test_set) 
{
    ASSERT_TRUE(solve(2,5)==4);
}

TEST(test_03, basic_test_set) 
{
    ASSERT_TRUE(solve(3,5)==3);
}

TEST(test_04, basic_test_set) 
{
    ASSERT_TRUE(solve(4,5)==4);
}

TEST(test_05, basic_test_set) 
{
    ASSERT_TRUE(solve(10,50)==50);
}

TEST(test_06, basic_test_set) 
{
    ASSERT_TRUE(solve(6,5)==-1);
}

TEST(test_07, basic_test_set) 
{
    ASSERT_TRUE(solve(2,1)==-1);
}

TEST(test_08, basic_test_set) 
{
    ASSERT_TRUE(solve(1,1)==1);
}

TEST(test_09, basic_test_set) 
{
    ASSERT_TRUE(solve(1000000000 , 2100000000)==2000000000);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}