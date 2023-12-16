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
