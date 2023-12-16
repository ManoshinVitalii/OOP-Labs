#include "hexagon.h"

template <typename T>
bool Hexagon<T>::valid(const vector<Point<T>> &p) const {
    if (p.size() != 6)
        return 0;
    vector<Point<T>> v = p;
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < 5; ++i) {
        Point<T> p1 = v[i], p2 = v[i + 1];
        if (fabs(p1.getX() - p2.getX()) < EPS && fabs(p1.getY() - p2.getY()) < EPS)
            return 0;
    }
    return 1;
}

template <typename T>
Hexagon<T>::operator double() const {
    double ans = 0;
    for(int i = 0; i < 6; ++i) {
        Point<T> p1 = Figure<T>::points[i], p2 = Figure<T>::points[(i + 1) % 6];
        ans += p1.getX() * p2.getY() - p1.getY() * p2.getX();
    }
    return fabs(ans * 0.5);
}

template <typename T>
Hexagon<T>::Hexagon(const vector<Point<T>> & vpoints) {
    if (!valid(vpoints))
        throw range_error("Error! Square Constructor: invalid points");
    else 
        Figure<T>::points = vpoints;
}

template <typename T>
Hexagon<T>::Hexagon() {
    vector<Point<T>> p;
    Figure<T>::points = p;
}

template <typename T>
Hexagon<T>::Hexagon(const Hexagon<T> &other) : Figure<T>(other) {}

template <typename T>
Hexagon<T>::Hexagon(const Hexagon<T> &&other) : Figure<T>(other) {}

template <typename T>
bool Hexagon<T>::isEqual(const Figure<T> &other) const {
        for(int i = 0; i < 6; ++i) {
        if(fabs(Figure<T>::points[i].getX() - other.getPoints()[i].getX()) >EPS) return 0;
        if(fabs(Figure<T>::points[i].getY() - other.getPoints()[i].getY()) >EPS) return 0;
    }
    return 1;
}

template <typename T>
Point<T> Hexagon<T>::getCenter() const {
    Point<T> tmp = getAv(this->points);
    return tmp;
}

template <typename T>
Hexagon<T> &Hexagon<T>::operator=(const Hexagon<T> &other) {
    Figure<T>::points = other.points;
    return *this;
}

template <typename T>
Hexagon<T> &Hexagon<T>::operator=(const Hexagon<T> &&other) {
    Figure<T>::points = move(other.points);
    return *this;
}
