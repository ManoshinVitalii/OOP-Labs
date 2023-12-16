#include "figure.h"

template <typename T>
Figure<T>::Figure() {
    vector<Point<T>> vpoints;
    points = vpoints;
}

template <typename T>
Figure<T>::Figure(const Figure<T> &other) : points(other.points) {}

template <typename T>
Figure<T>::Figure(const Figure<T> &&other) noexcept{
    points = move(other.points);
}

template <typename T>
vector<Point<T>> Figure<T>::getPoints() const{
    return points;
}
