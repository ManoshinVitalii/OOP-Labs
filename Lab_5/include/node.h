#pragma once

template <typename T>
class Node {
    private:
        T val;
        Node* prev;
        Node* next;
    public:
        Node() = default;
        const T & getValue() const;
        void setValue(const T & _val);
        Node* getNext() const;
        Node* getPrev() const;
        void setNext(Node* ptr);
        void setPrev(Node* ptr);
        ~Node() = default;
};

template <typename T>
const T & Node<T>::getValue() const {
    return val;
}

template <typename T>
void Node<T>::setValue(const T & _val) {
    val = _val;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
Node<T>* Node<T>::getPrev() const {
    return prev;
}

template <typename T>
void Node<T>::setNext(Node* ptr) {
    next = ptr;
}

template <typename T>
void Node<T>::setPrev(Node* ptr) {
    prev = ptr;
}
