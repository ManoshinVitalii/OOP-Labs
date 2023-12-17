#pragma once
#include "./node.h"

#include <iostream>

template <typename T>
class Iterator {
    private:
        Node<T> *node;
    public:
        Iterator() = default;
        explicit Iterator(Node<T> *node);
        Node<T> *getNode() const;
        Iterator<T> &operator++();
        Iterator<T> &operator+(int64_t num);
        T operator*() const;
        T operator->() const;
        bool operator==(const Iterator<T> &other) const;
        bool operator!=(const Iterator<T> &other) const;
        ~Iterator() = default;
};

template <typename T>
Iterator<T>::Iterator(Node<T> *othernode) {
    node = othernode;
}

template <typename T>
Node<T> *Iterator<T>::getNode() const {
    return node;
}

template <typename T>
Iterator<T> &Iterator<T>::operator++() {
    if (node) 
        node = node->getNext();
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator+(int64_t num) {
    while (num && node)    
        node = node->getNext(),--num;
    return *this;
}

template <typename T>
T Iterator<T>::operator*() const {
    return node->getValue();
}

template <typename T>
T Iterator<T>::operator->() const {
    return node->getValue();
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T> &other) const {
    return node == other.node;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const {
    return !(*this == other);
}

template <typename T>
class ConstIterator {
    private:
        const Node<T> *node;
    public:
        ConstIterator() = default;
        explicit ConstIterator(const Node<T> *node);     
        const Node<T> *getNode() const;
        const ConstIterator<T> &operator++();
        const ConstIterator<T> &operator+(int64_t num);
        const T &operator*() const;
        const T &operator->() const;
        bool operator==(const ConstIterator<T> &other) const;
        bool operator!=(const ConstIterator<T> &other) const;
        ~ConstIterator() = default;
};

template <typename T>
ConstIterator<T>::ConstIterator(const Node<T> *othernode) {
    node = othernode;
}

template <typename T>
const Node<T> *ConstIterator<T>::getNode() const {
    return node;
}

template <typename T>
const ConstIterator<T> &ConstIterator<T>::operator++() {
    if (node) 
        node = node->getNext();
    return *this;
}

template <typename T>
const ConstIterator<T> &ConstIterator<T>::operator+(int64_t num) {
    while (num && node)   
        node = node->getNext(), --num;
    return *this;
}

template <typename T>
const T &ConstIterator<T>::operator*() const {
    return node->getValue();
}

template <typename T>
const T &ConstIterator<T>::operator->() const {
    return node->getValue();
}

template <typename T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &other) const {
    return node == other.node;
}

template <typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &other) const {
    return !(*this == other);
}
