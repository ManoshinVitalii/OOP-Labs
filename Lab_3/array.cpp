#include "array.h"

FigureArray::FigureArray() : sz(0), capacity(0), arr(nullptr) {}

FigureArray::FigureArray(const initializer_list<Figure *> &l) {
    sz = l.size();
    capacity = sz;
    arr = new Figure *[sz];
    int i = 0;
    for (Figure *f : l)   
        arr[i++] = f;  
}

FigureArray::FigureArray(const vector<Figure *> &v) {
    sz = v.size();
    capacity = sz;
    arr = new Figure *[sz];
    int i = 0;
    for (Figure *f : v)   
        arr[i++] = f;   
}

Figure **FigureArray::getArr() {
    return arr;
}

void FigureArray::push_back(Figure *fg) {
    if (sz < capacity) {
        arr[sz + 1] = fg;
    } else {
        Figure **newArray = new Figure *[capacity + 1];
        memcpy(newArray, arr, sz * sizeof(Figure *));
        delete[] arr;
        arr = newArray;
        ++sz;
        capacity++;
        newArray[sz - 1] = fg;
    }
}

void FigureArray::pop_back() {
    if (sz == 0)   
        throw range_error("can't pop from empty array");    
    else  
        --sz;  
}

void FigureArray::erase(int idx) {
    if (idx > sz) 
        throw range_error("index is bigger, than size");
    for (int i = idx; i < sz - 1; i++)
        arr[i] = arr[i + 1];   
    --sz;
}

int FigureArray::getSize() {
    return sz;
}

int FigureArray::getCapacity() {
    return capacity;
}

FigureArray::operator double() {
    if (sz == 0)   
        throw range_error("can't calculate sum of squares of empty arr");  
    double res = 0;
    for (int i = 0; i < sz; i++) 
        res += double(*arr[i]); 
    return res;
}

ostream &operator<<(ostream &os, const FigureArray &f) {
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
