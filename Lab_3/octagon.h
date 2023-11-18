#include "figure.h"

class Octagon final: public Figure {
    public:
        Octagon();
        Octagon(const vector<Point> & points);
        Octagon(const Octagon & other);
        Octagon(const Octagon &&other);
        virtual ~Octagon() noexcept = default;
        operator double() const override;
        Point getCenter() const override;
        Octagon &operator=(const Octagon &other);
        Octagon &operator=(const Octagon &&other);
    private:
        bool isEqual(const Figure &other) const override;
        bool valid(const vector<Point> &p) const override;
        void print(ostream &os) const override;
        void input(istream &os) override;
};
