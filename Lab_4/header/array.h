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

template <typename T>
FigureArray<T>::FigureArray() : sz{0}, capacity{0}, arr{nullptr} {}

template <typename T>
FigureArray<T>::FigureArray(const initializer_list<T> &list) {
    sz = list.size();
    capacity = sz + 10;
    arr = make_unique<T[]>(capacity);
    int i = 0;
    for (T elem: list) {
        arr[i] = elem;
        ++i;
    }
}

template <typename T>
FigureArray<T>::FigureArray(FigureArray<T> &&other) noexcept {
    sz = other.sz;
    capacity = other.capacity;
    arr = move(other.arr);
}

template <typename T>
FigureArray<T>::FigureArray(const FigureArray<T> &other) {
    sz = other.sz;
    capacity = other.capacity;
    arr = make_unique<T[]>(capacity);
    for (int i = 0; i < other.size(); ++i) 
        arr[i] = other[i];
}

template <typename T>
T &FigureArray<T>::operator[] (const size_t &index) const {
    if (index > sz) 
        throw range_error("index is bigger, than size");
    return arr[index];
}

template <typename T>
size_t FigureArray<T>::size() const {
    return sz;
}

template <typename T>
void FigureArray<T>::push_back(const T &elem) {
    if (sz < capacity) {
        arr[sz] = elem;
    } else {
        unique_ptr<T[]> newArray = make_unique<T[]>(capacity + 5);
        for (int i = 0; i < sz; ++i) 
            newArray[i] = arr[i];       
        newArray[sz] = elem;
        arr = move(newArray);
        capacity += 10;
    }
    ++sz;
}

template <typename T>
void FigureArray<T>::erase(const size_t &idx) {
    if (idx > sz) 
        throw range_error("index is bigger, than size");
    for (size_t i = idx; i < sz - 1; ++i) 
        arr[i] = arr[i + 1]; 
    --sz;
}

template <typename T>
void FigureArray<T>::pop_back() {
    if (sz == 0) 
        throw range_error("can't pop from empty array");  
    --sz;
}

template <typename T>
FigureArray<T> &FigureArray<T>::operator=(const FigureArray<T> &other) {
    sz = other.sz;
    capacity = other.capacity;
    arr = make_unique<T[]>(capacity);

    memcpy(arr.get(), other.arr.get(), other.size() * sizeof(T));
    return *this;
}

template <typename T>
FigureArray<T> &FigureArray<T>::operator=(FigureArray<T> &&other) noexcept{
    swap(sz, other.sz);
    swap(arr, other.arr);
    swap(capacity, other.capacity);
    return *this;
}
