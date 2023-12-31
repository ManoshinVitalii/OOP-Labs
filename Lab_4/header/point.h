#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 0.01;
const double PI = acos(-1);

template <typename T>
class Point final {
    private:
        T x;
        T y;
    public:
        Point();
        Point(T _x, T _y);
        Point(const Point &other);
        Point &operator = (const Point &other);
        virtual ~Point();
        T getX() const;
        T getY() const;
        double distance(const Point &other) const;
        bool operator == (const Point &other) const;
        bool operator != (const Point &other) const;    
        friend ostream& operator << (ostream &os, const Point<T>&point) {
                return os << "x = " << point.x << ", y = " << point.y << endl;
        }
        friend istream& operator >> (istream& is,const Point<T>& point) {
            is >> point.x; is >> point.y;
            return is;
        }
        friend Point getAv(const vector<Point<T>> &p) {
            double sumX = 0, sumY = 0;
            for (size_t i = 0; i < p.size(); i++) {
                sumX += p[i].getX();
                sumY += p[i].getY();
            }
            return Point(sumX / p.size(), sumY / p.size());
        }
        friend bool operator < (const Point<T> &point1, const Point<T> &point2) {
            if(abs(point1.x - point2.x) > EPS) return point1.x < point2.x;
            return point1.y < point2.y;
        }
};

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
