#include "figure.h"

Figure::Figure() {
    vector<Point> vpoints;
    points = vpoints;
}

Figure::Figure(const Figure &other) : points(other.points) {}

Figure::Figure(const Figure &&other) noexcept{
    points = move(other.points);
}

ostream& operator << (ostream& os, const Figure& p) {
    p.print(os);
    return os;
}

istream& operator >> (istream& is, Figure& f) {
    f.input(is);
    return is;
}

vector<Point> Figure::getPoints() const{
    return points;
}

bool operator == (const Figure& lhs, const Figure& rhs) {
    if (typeid(lhs) != typeid(rhs)) {
        return 0;
    }
    return lhs.isEqual(rhs);
}
