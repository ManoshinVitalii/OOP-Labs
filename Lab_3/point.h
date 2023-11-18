#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 0.01;
const double PI = acos(-1);

class Point final {
    private:
        double x;
        double y;
    public:
        Point();
        Point(double _x, double _y);
        Point(const Point &other);
        Point &operator = (const Point &other);
        virtual ~Point();
        double getX() const;
        double getY() const;
        double distance(const Point &other) const;
        bool operator == (const Point &other) const;
        bool operator != (const Point &other) const;    
        friend ostream& operator << (ostream &os, const Point& point);
        friend istream& operator >> (istream& is, Point& point);
        friend Point getAv(const vector<Point> &p);
        friend bool operator < (const Point &point1, const Point &point2);
};
