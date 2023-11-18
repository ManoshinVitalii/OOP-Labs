#include "figure.h"

class Triangle final: public Figure{
    public:
        Triangle();
        Triangle(const vector<Point> & points);
        Triangle(const Triangle & other);
        Triangle(const Triangle &&other);
        virtual ~Triangle() noexcept = default;
        operator double() const override;
        Point getCenter() const override;
        Triangle &operator=(const Triangle &other);
        Triangle &operator=(const Triangle &&other);
    private:
        bool isEqual(const Figure &other) const override;
        bool valid(const vector<Point> &p) const override;
        void print(ostream &os) const override;
        void input(istream &os) override;
};
