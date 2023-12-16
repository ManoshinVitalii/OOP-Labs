#include "figure.h"

template <typename T>
class Hexagon final: public Figure<T> {
    friend ostream& operator << (ostream& os, const Hexagon<T> &fig) {
        os << "Hexagon\n" << fig.points;
        return os;
    }
    friend std::istream& operator >> (istream& is, const Hexagon<T> &fig) {
        vector<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < 6; ++i) {
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
        Hexagon();
        Hexagon(const vector<Point<T>> & points);
        Hexagon(const Hexagon & other);
        Hexagon(const Hexagon && other);
        Hexagon &operator = (const Hexagon &other);
        Hexagon &operator = (const Hexagon &&other);
        virtual ~Hexagon() noexcept = default;
        operator double() const override;
        Point<T> getCenter() const override;
    private:
        bool isEqual(const Figure<T> &other) const override;
        bool valid(const vector<Point<T>> &p) const override;
};
