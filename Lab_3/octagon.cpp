#include "octagon.h"

bool Octagon::valid(const vector<Point> &p) const {
    if (p.size() != 8)
        return 0;
    vector<Point> v = p;
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < 7; ++i) {
        Point p1 = v[i], p2 = v[i + 1];
        if (fabs(p1.getX() - p2.getX()) < EPS && fabs(p1.getY() - p2.getY()) < EPS)
            return 0;
    }
    return 1;
}

Octagon::operator double() const {
    double ans = 0;
    for(int i = 0; i < 8; ++i) {
        Point p1 = points[i], p2 = points[(i + 1) % 8];
        ans += p1.getX() * p2.getY() - p1.getY() * p2.getX();
    }
    return fabs(ans * 0.5);
}

Octagon::Octagon() : Figure() {}

Octagon::Octagon(const vector<Point> & vpoints) {
    if (!valid(vpoints))
        throw range_error("Error! Square Constructor: invalid points");
    else 
        points = vpoints;
}

Octagon::Octagon(const Octagon &other) : Figure(other) {}

Octagon::Octagon(const Octagon &&other) : Figure(other) {}

bool Octagon::isEqual(const Figure &other) const {
       for(int i = 0; i < 8; ++i) {
        if(fabs(points[i].getX() - other.getPoints()[i].getX()) >EPS) return 0;
        if(fabs(points[i].getY() - other.getPoints()[i].getY()) >EPS) return 0;
    }
    return 1;
}

Point Octagon::getCenter() const {
    Point tmp = getAv(this->points);
    return tmp;
}

void Octagon::print(ostream& os) const{
    for (size_t i = 0; i < 8; i++) 
        os << points[i];   
}

void Octagon::input(istream &is) {
    vector<Point> tmpV;
    Point tmp;
    for (size_t i = 0; i < 8; ++i) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!valid(tmpV)) 
        throw range_error("Error! Square Constructor: invalid points");
     else 
        points = tmpV;
}

Octagon &Octagon::operator=(const Octagon &other) {
    points = other.points;
    return *this;
}

Octagon &Octagon::operator=(const Octagon &&other) {
    points = move(other.points);
    return *this;
}
