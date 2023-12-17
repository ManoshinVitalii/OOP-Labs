#pragma once

#include <iostream>
#include <cstdint>
#include <list>
using namespace std;

template <typename T>
class Allocator {
    private:
        list<T*> usedblocks;
        list<T*> freeblocks;
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = size_t;

        Allocator();
        pointer allocate(size_type n);
        void deallocate(pointer ptr, size_type n);
        void free();
        template <class U>
        struct rebind {
            using other = Allocator<U>;
        };
        template <typename... Args>
        void construct(pointer p, Args&&... args);
        void destroy(pointer ptr);
        ~Allocator();
};

template <typename T>
template <typename... Args>
void Allocator<T>::construct(pointer p, Args&&... args) {
    new (p) T(std::forward<Args>(args)...);
}

template <typename T>
Allocator<T>::Allocator() {}

template <typename T>
Allocator<T>::~Allocator() {   
    this->free();
}

template <typename T>
T* Allocator<T>::allocate(size_type n) {
    T* ptr;
    if (!freeblocks.empty() && n == 1) { 
        ptr = freeblocks.front();
        freeblocks.pop_front(); 
        return ptr;
    }
    ptr = (T*)(::operator new(sizeof(T) * n));
    usedblocks.push_back(ptr);
    return ptr;
}

template <typename T>
void Allocator<T>::deallocate(pointer ptr, size_type n) {
    if (freeblocks.size() > usedblocks.size()) 
        throw length_error("Error! deallocate: you want to delete unallocated blocks");
    for (int i = 0; i < n; ++i) 
        freeblocks.push_back(ptr + i * sizeof(T));   
}

template <typename T>
void Allocator<T>::free() {
    int n = usedblocks.size();
    for (int i = 0; i < n; ++i) {
        T* tmp = usedblocks.front();
        usedblocks.pop_front();
        delete(tmp);
    }
}

template <typename T>
void Allocator<T>::destroy(pointer ptr) {
    ptr->~T();
}
