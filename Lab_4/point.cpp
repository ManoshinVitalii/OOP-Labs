#include "point.h"

template <typename T>
Point<T>::Point() : x(0), y(0) {}

template <typename T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}

template <typename T>
Point<T>::Point(const Point<T> &other) : x(other.x), y(other.y) {}

template <typename T>
Point<T> &Point<T>::operator=(const Point<T> &other) {
    y = other.y;
    x = other.x;
    return *this;
}
template <typename T>
Point<T>::~Point() {}

template <typename T>
T Point<T>::getX() const {
    return x;
}

template <typename T>
T Point<T>::getY() const {
    return y;
}

template <typename T>
double Point<T>::distance(const Point<T> &other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

template <typename T>
bool Point<T>::operator == (const Point<T> &other) const {
    return this->distance(other) < EPS;
}

template <typename T>
bool Point<T>::operator != (const Point<T> &other) const {
    return !(*this == other);
}
