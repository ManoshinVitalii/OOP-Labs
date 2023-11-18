#include "triangle.h"

bool Triangle::valid(const vector<Point> &p) const {
    if (p.size() != 3)
        return 0;
    vector<Point> v = p;
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < 2; ++i) {
        Point p1 = v[i], p2 = v[i + 1];
        if (fabs(p1.getX() - p2.getX()) < EPS && fabs(p1.getY() - p2.getY()) < EPS)
            return 0;
    }
    return 1;
}

Triangle::operator double() const {
    double ans = 0;
    for(int i = 0; i < 3; ++i) {
        Point p1 = points[i], p2 = points[(i + 1) % 3];
        ans += p1.getX() * p2.getY() - p1.getY() * p2.getX();
    }
    return fabs(ans * 0.5);
}

Point Triangle::getCenter() const {
    Point tmp = getAv(this->points);
    return tmp;
}

Triangle::Triangle() : Figure() {}

Triangle::Triangle(const vector<Point> & vpoints) {
    if (!valid(vpoints))
        throw range_error("Error! Triangle Constructor: invalid points");
    else 
        points = vpoints;
}

Triangle::Triangle(const Triangle &other) {
    points = other.points;
}

Triangle::Triangle(const Triangle &&other) {
    points = move(other.points);
}

void Triangle::print(ostream& os) const{
    for (size_t i = 0; i < 3; i++) 
        os << points[i];   
}

Triangle &Triangle::operator=(const Triangle &other) {
    points = other.points;
    return *this;
}

Triangle &Triangle::operator=(const Triangle &&other) {
    points = move(other.points);
    return *this;
}

bool Triangle::isEqual(const Figure &other) const {
    for(int i = 0; i < 3; ++i) {
        if(fabs(points[i].getX() - other.getPoints()[i].getX()) >EPS) return 0;
        if(fabs(points[i].getY() - other.getPoints()[i].getY()) >EPS) return 0;
    }
    return 1;
}

void Triangle::input(istream &is) {
    vector<Point> tmpV;
    Point tmp;
    for (size_t i = 0; i < 3; ++i) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!valid(tmpV)) 
        throw range_error("Error! Square Constructor: invalid points");
     else 
        points = tmpV;  
}
