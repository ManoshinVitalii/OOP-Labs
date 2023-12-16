#pragma once
#include "point.h"

template <typename T>
class Figure {
    protected:
        virtual bool isEqual(const Figure &other) const = 0;
        virtual bool valid(const vector<Point<T>> &p) const = 0;
        vector<Point<T>> points;
    public :
        Figure();
        Figure(const Figure &other);
        Figure(const Figure &&other) noexcept;
        ~Figure() = default;
        vector<Point<T>> getPoints() const;
        virtual operator double () const = 0;
        friend bool operator==(const Figure &lhs, const Figure &rhs) {
            if (typeid(lhs) != typeid(rhs)) {
                return 0;
            }
            return lhs.isEqual(rhs);
        }
        virtual Point<T> getCenter() const = 0;
        friend ostream &operator << (ostream& os, const Figure<T>& f) {
            f.print(os);
            return os;
        }
        friend istream &operator >> (istream& is, Figure<T>& f) {
            f.input(is);
            return is;
        }
};
