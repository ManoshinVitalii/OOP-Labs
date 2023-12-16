#include "triangle.cpp"
#include "hexagon.cpp"
#include "octagon.cpp"
#include "array.cpp"
#include "point.cpp"
#include "figure.cpp"
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
    vector<Point<int>>v {a, b, c};
    Triangle t(v);
    ASSERT_TRUE((double(t) - 0.5) < EPS);
}

TEST(test_04, Test)
{
    Point a(1, 2), b(3, 2), c(2, 4);
    vector<Point<int>>v {a, b, c};
    Triangle t(v);
    ASSERT_TRUE((double(t) - 2) < EPS);
}

TEST(test_05, Test)
{
    Point a(0, 0), b(3, 0), c(3, 3);
    vector<Point<int>>v {a, b, c};
    Triangle t(v);
    ASSERT_TRUE((double(t) - 4.5) < EPS);
}


TEST(test_06, Test)
{
    Point a(1, 2), b(1, 2), c(1, 7);
    vector<Point<int>>v {a, b, c};
    ASSERT_ANY_THROW(Triangle t(v));
}

TEST(test_07, Test)
{
    Point a(1, 2), b(1, 2), c(1, 2);
    vector<Point<int>>v {a, b, c};
    ASSERT_ANY_THROW(Triangle t(v));
}

TEST(test_08, Test)
{
    Point a(1, 2), b(1, 2), c(1, 2);
    vector<Point<int>>v {a, b, c};
    ASSERT_ANY_THROW(Triangle t(v));
}

TEST(test_09, Test)
{
    Point a(0, 0), b(3, 0), c(3, 3);
    vector<Point<int>>v {a, b, c};
    Triangle t(v);
    Point d = t.getCenter();
    ASSERT_TRUE(d.getX() == 2 && d.getY() == 1);
}

TEST(test_10, Test)
{
    Point a(-1, 1), b(1, 1), c(3, 1);
    vector<Point<int>>v {a, b, c};
    Triangle t(v);
    Point d = t.getCenter();
    ASSERT_TRUE(d.getX() == 1 && d.getY() == 1);
}

TEST(test_11, Test)
{
    Point a(1, 2), b(3, 2), c(2, 5);
    vector<Point<int>>v {a, b, c};
    Triangle t(v);
    Point d = t.getCenter();
    ASSERT_TRUE(d.getX() == 2 && d.getY() == 3);
}

TEST(test_12, Test)
{
    Point a(1, 0), b(1, 0), c(3, 1), d(2, 2), e(2, 1), f(0, 1);
    vector<Point<int>>v {a, b, c, d, e, f};
    ASSERT_ANY_THROW(Hexagon t(v));
}

TEST(test_13, Test)
{
    Point a(1, 0), b(2, 0), c(3, 1), d(2, 0), e(2, 1), f(0, 1);
    vector<Point<int>>v {a, b, c, d, e, f};
    ASSERT_ANY_THROW(Hexagon t(v));
}

TEST(test_14, Test)
{
    Point a(0, 1), b(0, 1), c(3, 1), d(6, 0), e(2, 1), f(0, 1);
    vector<Point<int>>v {a, b, c, d, e, f};
    ASSERT_ANY_THROW(Hexagon t(v));
}

TEST(test_15, Test)
{
    Point a(1, 0), b(2, 0), c(3, 1), d(2, 2), e(1, 2), f(0, 1);
    vector<Point<int>>v {a, b, c, d, e, f};
    Hexagon t(v);
    ASSERT_TRUE((double(t) - 4) < EPS);
}

TEST(test_16, Test)
{
    Point a(1, 0), b(2, 0), c(3, 0), d(3, 1), e(2, 1), f(1, 1);
    vector<Point<int>>v {a, b, c, d, e, f};
    Hexagon t(v);
    ASSERT_TRUE((double(t) - 2) < EPS);
}

TEST(test_17, Test)
{
    Point<double> a(1, 0), b(2, 0), c(3, 0), d(3, 1), e(2, 1), f(1, 1);
    vector<Point<double>>v {a, b, c, d, e, f};
    Hexagon t(v);
    Point g = t.getCenter();
    ASSERT_TRUE(g.getX() == 2 && g.getY() == 0.5);
}

TEST(test_18, Test)
{
    Point a(0, 2), b(0, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<int>>v {a, b, c, d, e, f, g, h};
    ASSERT_ANY_THROW( Octagon t(v));
}

TEST(test_19, Test)
{
    Point a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<int>>v {a, b, c, d, e, f, g, h};
    Octagon t(v);
    ASSERT_TRUE((double(t) - 7) < EPS);
}

TEST(test_20, Test)
{
    Point<double> a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<double>>v {a, b, c, d, e, f, g, h};
    Octagon t(v);
    Point i = t.getCenter();
    ASSERT_TRUE(i.getX() == 1.5 && i.getY() == 1.5);
}

TEST(test_21, Test) {
    Triangle<double> t({Point(0.79, 1.1), Point(3.37, 1.98), Point(1.32, 3.77)});
    ASSERT_TRUE(fabs(double(t) - 3.2111) < EPS);
}

TEST(test_22, Test) {
    Point<double> a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<double>>v {a, b, c, d, e, f, g, h};
    Octagon<double> t1(v);
    swap(v[0], v[1]);
    Octagon<double> t2(v);
    swap(v[1], v[2]);
    Octagon<double> t3(v);
    FigureArray<Figure<double> *> ar({&t1, &t2, &t3});
    bool flag = 1;
    if (*ar[0] != t1) flag = 0;
    if (*ar[1] != t2) flag = 0;
    if (*ar[2] != t3) flag = 0;
    ASSERT_TRUE(flag);
}

TEST(test_23, Test) {

 Point<double> a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<double>>v {a, b, c, d, e, f, g, h};
    Octagon<double> t1(v);
    swap(v[0], v[1]);
    Octagon<double> t2(v);
    swap(v[1], v[2]);
    Octagon<double> t3(v);
    FigureArray<Figure<double> *> ar({&t1, &t2, &t3});
    ar.push_back(&t2);
    ASSERT_TRUE(*ar[ar.size() - 1] == t2);
}

TEST(test_24, Test) {
    Point<double> a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<double>>v {a, b, c, d, e, f, g, h};
    Octagon<double> t1(v);
    swap(v[0], v[1]);
    Octagon<double> t2(v);
    swap(v[1], v[2]);
    Octagon<double> t3(v);
    FigureArray<Figure<double> *> ar({&t1, &t2, &t3});
    ar.pop_back();
    ASSERT_TRUE(ar.size() == 2 && *ar[ar.size() - 1] == t2);
}


TEST(test_25, Test) {
     Point<double> a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<double>>v {a, b, c, d, e, f, g, h};
    Octagon<double> t1(v);
    swap(v[0], v[1]);
    Octagon<double> t2(v);
    swap(v[1], v[2]);
    Octagon<double> t3(v);
    FigureArray<Figure<double> *> ar({&t1, &t2, &t3});
    ar.erase(1);
    bool flag = 1;
    if (*ar[0] != t1) flag = 0;
    if (*ar[1] != t3) flag = 0;
    ASSERT_TRUE(flag);
}

TEST(test_26, Test) {
     FigureArray<Figure<double> *> ar;
    ASSERT_THROW(ar.erase(1), std::range_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
