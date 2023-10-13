#include <gtest/gtest.h>
#include "solve1.h"

TEST(test_01, lvalue_copy_3) {
    string s = "321";
    string z = "963";
    Decimal a(s);
    Decimal b(z);
    a += b;
    ASSERT_EQ(a.getstring(), "1284");
}

TEST(test_02, lvalue_copy_3) {
    string s = "321";
    Decimal a(s);
    Decimal b(s);
    a -= b;
    ASSERT_EQ(a.getstring(), "0");
}


TEST(test_03, lvalue_copy_3) {
    string s = "321";
    Decimal a(s);
    Decimal b;
    b = a;
    ASSERT_EQ(b.getstring(), s);
}

TEST(test_04, lvalue_copy_3) {
    string s = "321";
    Decimal a(s);
    Decimal b(s);
    a += b;
    ASSERT_EQ(a.getstring(),"642");
}

TEST(test_05, lvalue_copy_3) {
    string s = "0";
    Decimal a(s);
    Decimal b(s);
    a += b;
    ASSERT_EQ(a.getstring(),"0");
}

TEST(test_06, lvalue_copy_3) {
    string s = "0";
    Decimal a(s);
    Decimal b(s);
    a -= b;
    ASSERT_EQ(a.getstring(),"0");
}

TEST(test_07, lvalue_copy_3) {
    string s = "123";
    string z = "1";
    Decimal a(s);
    Decimal b(z);
    a -= b;
    ASSERT_EQ(a.getstring(),"122");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
