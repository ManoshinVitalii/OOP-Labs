#include "figure.h"

class Hexagon final: public Figure {
    public:
        Hexagon();
        Hexagon(const vector<Point> & points);
        Hexagon(const Hexagon & other);
        Hexagon(const Hexagon && other);
        Hexagon &operator = (const Hexagon &other);
        Hexagon &operator = (const Hexagon &&other);
        virtual ~Hexagon() noexcept = default;
        operator double() const override;
        Point getCenter() const override;
    private:
        bool isEqual(const Figure &other) const override;
        bool valid(const vector<Point> &p) const override;
        void print(ostream &os) const override;
        void input(istream &os) override;
};
