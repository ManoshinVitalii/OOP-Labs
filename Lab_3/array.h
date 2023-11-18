#include "figure.h"
#include <cstring>

class FigureArray final {
    private:
        Figure **arr;
        int sz;
        int capacity;
    public:
        FigureArray();
        FigureArray(const initializer_list<Figure *> &l);
        FigureArray(const vector<Figure *> &v);
        Figure **getArr();
        void push_back(Figure *fig);
        void pop_back();
        void erase(int idx);
        int getSize();
        int getCapacity();
        operator double();
        friend ostream &operator<<(ostream &os, const FigureArray &f);
};
