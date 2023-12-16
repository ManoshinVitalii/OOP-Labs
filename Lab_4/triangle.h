#include "figure.h"

template <typename T>
class Triangle final: public Figure<T>{
    friend ostream& operator << (ostream& os, const Triangle<T> &fig) {
        os << "Triangle\n" << fig.points;
        return os;
    }
    friend std::istream& operator >> (istream& is, const Triangle<T> &fig) {
        vector<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < 3; ++i) {
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
        Triangle();
        Triangle(const vector<Point<T>> & points);
        Triangle(const Triangle & other);
        Triangle(const Triangle &&other);
        virtual ~Triangle() noexcept = default;
        operator double() const override;
        Point<T> getCenter() const override;
        Triangle &operator=(const Triangle &other);
        Triangle &operator=(const Triangle &&other);
    private:
        bool isEqual(const Figure<T> &other) const override;
        bool valid(const vector<Point<T>> &p) const override;
};
