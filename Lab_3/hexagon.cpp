#include "hexagon.h"

bool Hexagon::valid(const vector<Point> &p) const {
    if (p.size() != 6)
        return 0;
    vector<Point> v = p;
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < 5; ++i) {
        Point p1 = v[i], p2 = v[i + 1];
        if (fabs(p1.getX() - p2.getX()) < EPS && fabs(p1.getY() - p2.getY()) < EPS)
            return 0;
    }
    return 1;
}

Hexagon::operator double() const {
    double ans = 0;
    for(int i = 0; i < 6; ++i) {
        Point p1 = points[i], p2 = points[(i + 1) % 6];
        ans += p1.getX() * p2.getY() - p1.getY() * p2.getX();
    }
    return fabs(ans * 0.5);
}


Hexagon::Hexagon(const vector<Point> & vpoints) {
    if (!valid(vpoints))
        throw range_error("Error! Square Constructor: invalid points");
    else 
        points = vpoints;
}

Hexagon::Hexagon() {
    vector<Point> p;
    points = p;
}

Hexagon::Hexagon(const Hexagon &other) : Figure(other) {}

Hexagon::Hexagon(const Hexagon &&other) : Figure(other) {}

bool Hexagon::isEqual(const Figure &other) const {
        for(int i = 0; i < 6; ++i) {
        if(fabs(points[i].getX() - other.getPoints()[i].getX()) >EPS) return 0;
        if(fabs(points[i].getY() - other.getPoints()[i].getY()) >EPS) return 0;
    }
    return 1;
}
Point Hexagon::getCenter() const {
    Point tmp = getAv(this->points);
    return tmp;
}

void Hexagon::print(ostream& os) const{
    for (int i = 0; i < 6; i++) 
        os << points[i];
}

void Hexagon::input(istream &is) {
    vector<Point> tmpV;
    Point tmp;
    for (int i = 0; i < 6; ++i) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!valid(tmpV)) {
        throw range_error("Error! Square Constructor: invalid points");
    } else {
        points = tmpV;
    }
}

Hexagon &Hexagon::operator=(const Hexagon &other) {
    points = other.points;
    return *this;
}

Hexagon &Hexagon::operator=(const Hexagon &&other) {
    points = move(other.points);
    return *this;
}
