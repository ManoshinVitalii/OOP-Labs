#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
    y = other.y;
    x = other.x;
    return *this;
}

Point::~Point() {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distance(const Point &other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

bool Point::operator == (const Point &other) const {
    return this->distance(other) < EPS;
}

bool Point::operator != (const Point &other) const {
    return !(*this == other);
}

ostream& operator << (ostream &os, const Point& point) {
    return os << "x = " << point.x << ", y = " << point.y << endl;
}

istream& operator >> (istream& is, Point& point) {
    is >> point.x; is >> point.y;
    return is;
}

Point getAv(const vector<Point> &p) {
    double sumX = 0, sumY = 0;
    for (size_t i = 0; i < p.size(); i++) {
        sumX += p[i].getX();
        sumY += p[i].getY();
    }
    return Point(sumX / p.size(), sumY / p.size());
}

bool operator < (const Point &point1, const Point &point2){
    if(abs(point1.x - point2.x) < EPS) return point1.x < point2.x;
    return point1.y < point2.y;
}

Point operator + (const Point &point1, const Point &point2){
    return {point1.x + point2.x, point1.y + point2.y};
}

Point operator - (const Point &point1, const Point &point2){
    return {point1.x - point2.x, point1.y - point2.y};
}

bool Point::iszero(){
    return fabs(x) < EPS && fabs(y) < EPS;
}
