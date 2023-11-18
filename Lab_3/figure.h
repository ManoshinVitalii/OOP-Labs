#pragma once
#include "point.h"

class Figure {
    protected:
        virtual bool isEqual(const Figure &other) const = 0;
        virtual bool valid(const vector<Point> &p) const = 0;
        virtual void print(ostream &os) const = 0;
        virtual void input(istream &os) = 0;
        vector<Point> points;
    public :
        Figure();
        Figure(const Figure &other);
        Figure(const Figure &&other) noexcept;
        ~Figure() = default;
        vector<Point> getPoints() const;
        virtual operator double () const = 0;
        friend bool operator==(const Figure &lhs, const Figure &rhs);
        virtual Point getCenter() const = 0;
        friend ostream &operator << (ostream& os, const Figure& f);
        friend istream &operator >> (istream& is, Figure& f);
};
