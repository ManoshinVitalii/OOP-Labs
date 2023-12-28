#include "header/triangle.h"
#include "header/octagon.h"
int main() {
    vector<Point<int>>v {{0, 0}, {0, 1}, {1, 1}};
    Triangle t(v);
    cout << double(t) << endl;
    Point<double> a(1, 0), b(2, 0), c(3, 1), d(3, 2), e(2, 3), f(1, 3), g(0, 2), h(0, 1);
    vector<Point<double>>v2 {a, b, c, d, e, f, g, h};
    Octagon<double> t2(v2);
    cout << double(t2) << endl;

    return 0;
}
