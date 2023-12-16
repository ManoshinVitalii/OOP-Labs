#pragma once
#include "figure.h"
#include <cstring>
#include <memory>

template <typename T>
class FigureArray {
    friend ostream &operator<<(ostream &os, const FigureArray<T> &f) {
        if (f.sz == 0)
            throw range_error("can't print empty array");
        for (int i = 0; i < f.sz; ++i) {
            int cnt = f.arr[i]->getPoints().size();
            if(cnt == 3) 
                cout << "Triangle\n";   
            if(cnt == 6) 
                cout << "Hexagon\n";   
            if(cnt == 8) 
                cout << "Octagon\n";
        cout << *(f.arr[i]);
        }
        return os;
    }
    private:
        unique_ptr<T[]> arr;
        int sz;
        int capacity;
    public:
        FigureArray();
        FigureArray(const std::initializer_list<T> &list);
        FigureArray(const FigureArray &other);
        FigureArray(FigureArray &&other) noexcept;
        ~FigureArray() = default;

        T & operator[] (const size_t &index) const;
        size_t size() const;

        void push_back(const T &el);
        void erase(const size_t &idx);
        void pop_back();
        FigureArray<T> &operator=(const FigureArray<T> &other);
        FigureArray<T> &operator=(FigureArray<T> &&other) noexcept;
};
