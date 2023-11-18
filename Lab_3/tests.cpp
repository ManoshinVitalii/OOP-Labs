#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include "array.h"
#include <gtest/gtest.h>

TEST(test_01, Test)
{
    Point a(2, 3);
    Point b(2, 3);

    ASSERT_TRUE(a == b);
}

TEST(test_02, Test)
{
    Point a(2, 3);
    Point b(2, 3);

    ASSERT_FALSE(a != b);
}

TEST(test_03, Test)
{
    Point a(0, 0), b(0, 1), c(1, 0);
    vector<Point>v {a, b, c};
    Triangle t(v);
    ASSERT_TRUE((double(t) - 0.5) < EPS);
}

TEST(test_04, Test)
{
    Point a(1, 2), b(3, 2), c(2, 4);
    vector<Point>v {a, b, c};
    Triangle t(v);
    ASSERT_TRUE((double(t) - 2) < EPS);
}

TEST(test_05, Test)
{
    Point a(0, 0), b(3, 0), c(3, 3);
    vector<Point>v {a, b, c};
    Triangle t(v);
    ASSERT_TRUE((double(t) - 4.5) < EPS);
}

TEST(test_06, Test)
{
    Point a(1, 2), b(1, 2), c(1, 7);
    vector<Point>v {a, b, c};
    ASSERT_ANY_THROW(Triangle t(v));
}

TEST(test_07, Test)
{
    Point a(1, 2), b(1, 2), c(1, 2);
    vector<Point>v {a, b, c};
    ASSERT_ANY_THROW(Triangle t(v));
}

TEST(test_08, Test)
{
    Point a(1, 2), b(1, 2), c(1, 2);
    vector<Point>v {a, b, c};
    ASSERT_ANY_THROW(Triangle t(v));
}

TEST(test_09, Test)
{
    Point a(0, 0), b(3, 0), c(3, 3);
    vector<Point>v {a, b, c};
    Triangle t(v);
    Point d = t.getCenter();
    ASSERT_TRUE(d.getX() == 2 && d.getY() == 1);
}

TEST(test_10, Test)
{
    Point a(-1, 1), b(1, 1), c(3, 1);
    vector<Point>v {a, b, c};
    Triangle t(v);
    Point d = t.getCenter();
    ASSERT_TRUE(d.getX() == 1 && d.getY() == 1);
}

TEST(test_11, Test)
{
    Point a(1, 2), b(3, 2), c(2, 5);
    vector<Point>v {a, b, c};
    Triangle t(v);
    Point d = t.getCenter();
    ASSERT_TRUE(d.getX() == 2 && d.getY() == 3);
}

TEST(test_12, Test)
{
    Point a(1, 0), b(1, 0), c(3, 1), d(2, 2), e(2, 1), f(0, 1);
    vector<Point>v {a, b, c, d, e, f};
    ASSERT_ANY_THROW(Hexagon t(v));
}

TEST(test_13, Test)
{
    Point a(1, 0), b(2, 0), c(3, 1), d(2, 0), e(2, 1), f(0, 1);
    vector<Point>v {a, b, c, d, e, f};
    ASSERT_ANY_THROW(Hexagon t(v));
}

TEST(test_14, Test)
{
    Point a(0, 1), b(0, 1), c(3, 1), d(6, 0), e(2, 1), f(0, 1);
    vector<Point>v {a, b, c, d, e, f};
    ASSERT_ANY_THROW(Hexagon t(v));
}

TEST(test_15, Test)
{
    Point a(1, 0), b(2, 0), c(3, 1), d(2, 2), e(1, 2), f(0, 1);
    vector<Point>v {a, b, c, d, e, f};
    Hexagon t(v);
    ASSERT_TRUE((double(t) - 4) < EPS);
}

TEST(test_16, Test)
{
    Point a(1, 0), b(2, 0), c(3, 0), d(3, 1), e(2, 1), f(1, 1);
    vector<Point>v {a, b, c, d, e, f};
    Hexagon t(v);
    ASSERT_TRUE((double(t) - 2) < EPS);
}

TEST(test_17, Test)
{
    Point a(1, 0), b(2, 0), c(3, 0), d(3, 1), e(2, 1), f(1, 1);
    vector<Point>v {a, b, c, d, e, f};
    Hexagon t(v);
    Point g = t.getCenter();
    ASSERT_TRUE(g.getX() == 2 && g.getY() == 0.5);
}

TEST(test_18, Test)
{
    Point a(1, 0), b(1, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point>v {a, b, c, d, e, f, g, h};
    ASSERT_ANY_THROW( Octagon t(v));
}

TEST(test_19, Test)
{
    Point a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point>v {a, b, c, d, e, f, g, h};
    Octagon t(v);
    ASSERT_TRUE((double(t) - 7) < EPS);
}

TEST(test_20, Test)
{
    Point a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point>v {a, b, c, d, e, f, g, h};
    Octagon t(v);
    Point i = t.getCenter();
    ASSERT_TRUE(i.getX() == 1.5 && i.getY() == 1.5);
}

TEST(test_21, test00) {
    Point a(1, 0), b(2, 0), c(3, 1), d(4, 0);
    Triangle t1({a, b, c});
    Triangle t2({b, c, d});
    Triangle t3({b, d, a});
    FigureArray ar(vector<Figure *> {&t1, &t2, &t3});
    ASSERT_TRUE((double(ar) - double(t1) - double(t2) - double(t3)) < EPS);
}

TEST(test_22, test00) {
    Point a(1, 0), b(2, 0), c(3, 1), d(4, 0);
    Triangle t1({a, b, c});
    Triangle t2({b, c, d});

    FigureArray ar(vector<Figure *> {&t1, &t2});
    ASSERT_TRUE(double(ar) == 1.5);
}

TEST(test_23, test00) {
    Point a(1, 0), b(2, 0), c(3, 1);
    Triangle t1({a, b, c});
    Triangle t2({a, b, c});
    ASSERT_TRUE(t1 == t2);
}

TEST(test_24, test00) {
    Point a(1, 0), b(2, 0), c(3, 1), d(1, 2);
    Triangle t1({a, b, c});
    Triangle t2({d, c, a});
    ASSERT_FALSE(t1 == t2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
