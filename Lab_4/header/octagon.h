#include "figure.h"

template <typename T>
class Octagon final: public Figure<T> {
    friend ostream& operator << (ostream& os, const Octagon<T> &fig) {
        os << "Octagon\n" << fig.points;
        return os;
    }
    friend std::istream& operator >> (istream& is, const Octagon<T> &fig) {
        vector<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < 8; ++i) {
            is >> tmp;
            tmpV.push_back(tmp);
        }
        if (!valid(tmpV)) {
            throw range_error("Error! Square Constructor: invalid points");
        } else {
            Figure<T>::points = tmpV;
        }   
        return is;
    }
    public:
        Octagon();
        Octagon(const vector<Point<T>> & points);
        Octagon(const Octagon & other);
        Octagon(const Octagon &&other);
        virtual ~Octagon() noexcept = default;
        operator double() const override;
        Point<T> getCenter() const override;
        Octagon &operator=(const Octagon &other);
        Octagon &operator=(const Octagon &&other);
    private:
        bool isEqual(const Figure<T> &other) const override;
        bool valid(const vector<Point<T>> &p) const override;
};


template <typename T>
bool Octagon<T>::valid(const vector<Point<T>> &p) const {
    if (p.size() != 8)
        return 0;
    vector<Point<T>> v = p;
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < 7; ++i) {
        Point<T> p1 = v[i], p2 = v[i + 1];
        if (fabs(p1.getX() - p2.getX()) < EPS && fabs(p1.getY() - p2.getY()) < EPS)
            return 0;
    }
    return 1;
}

template <typename T>
Octagon<T>::operator double() const {
    double ans = 0;
    for(int i = 0; i < 8; ++i) {
        Point<T> p1 = Figure<T>::points[i], p2 = Figure<T>::points[(i + 1) % 8];
        ans += p1.getX() * p2.getY() - p1.getY() * p2.getX();
    }
    return fabs(ans * 0.5);
}

template <typename T>
Octagon<T>::Octagon() : Figure<T>() {}

template <typename T>
Octagon<T>::Octagon(const vector<Point<T>> & vpoints) {
    if (!valid(vpoints))
        throw range_error("Error! Square Constructor: invalid points");
    else 
        Figure<T>::points = vpoints;
}

template <typename T>
Octagon<T>::Octagon(const Octagon<T> &other) : Figure<T>(other) {}

template <typename T>
Octagon<T>::Octagon(const Octagon<T> &&other) : Figure<T>(other) {}

template <typename T>
bool Octagon<T>::isEqual(const Figure<T> &other) const {
       for(int i = 0; i < 8; ++i) {
        if(fabs(Figure<T>::points[i].getX() - other.getPoints()[i].getX()) >EPS) return 0;
        if(fabs(Figure<T>::points[i].getY() - other.getPoints()[i].getY()) >EPS) return 0;
    }
    return 1;
}

template <typename T>
Point<T> Octagon<T>::getCenter() const {
    Point<T> tmp = getAv(this->points);
    return tmp;
}

template <typename T>
Octagon<T> &Octagon<T>::operator=(const Octagon<T> &other) {
    Figure<T>::points = other.points;
    return *this;
}

template <typename T>
Octagon<T> &Octagon<T>::operator=(const Octagon<T> &&other) {
    Figure<T>::points = move(other.points);
    return *this;
}
