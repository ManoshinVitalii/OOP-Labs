#pragma once

#include "./allocator.h"
#include "./node.h"
#include "./iterator.h"

template <typename T, class Allocator = Allocator<Node<T>>>
class Queue {
    private:
        Allocator alloc;
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        size_t sz = 0;
    public:
        Queue();
        Queue(const T &value, size_t n);
        Queue(const std::initializer_list<T> &value);
        Queue(const Queue &other);
        Queue(Queue &&other);
        size_t size() const;
        bool empty() const;
        void push(const T &val);
        void pop();
        T back();
        T front();
        void clear() noexcept;
        Iterator<T> begin() const;
        Iterator<T> end() const;
        ConstIterator<T> CBegin() const;
        ConstIterator<T> CEnd() const;
        template <typename U>
        friend ostream &operator<<(ostream &os, const Queue<U> &l);
        ~Queue();
};

template <typename T, class Allocator>
void Queue<T, Allocator>::push(const T &val) {
    if (this->empty()) {
        sz = 1;
        head = alloc.allocate(1);
        head->setValue(val);
        tail = head;
        return;
    }
    Node<T> *ptr = alloc.allocate(1);
    ptr->setValue(val);
    ptr->setNext(tail);
    tail->setPrev(ptr);
    tail = ptr;
    ++sz;
}

template <typename T, class Allocator>
void Queue<T, Allocator>::pop() {
    if (this->empty())  
        throw length_error("Error! Queue pop: list empty");
    Node<T> *delNode = head;
    if (this->size() > 1)   
        head = head->getPrev();
    else
        head = nullptr, tail = nullptr;  
    alloc.deallocate(delNode, 1);
    --sz;
}

template <typename T, class Allocator>
T Queue<T, Allocator>::back() {
    return tail->getValue();
}

template <typename T, class Allocator>
T Queue<T, Allocator>::front() {
    return head->getValue();
}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue() : head(nullptr), tail(nullptr), sz(0) {}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue(const T &value, size_t n) {
    Node<T> *ptr = alloc.allocate(1);
    ptr->setValue(value);
    tail = ptr;
    head = ptr;
    for (size_t i = 1; i < n; ++i) {
        ptr = alloc.allocate(1);
        ptr->setValue(value);
        ptr->setPrev(head);
        head->setNext(ptr);
        head = ptr;
    }
    sz = n;
}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue(const std::initializer_list<T> &value) {
    auto it = value.begin();
    Node<T> *ptr = alloc.allocate(1);
    ptr->setValue(*it);
    tail = ptr;
    head = ptr;
    for (size_t i = 1; i < value.size(); ++i) {
        ptr = alloc.allocate(1);
        ptr->setValue(*it);
        ptr->setPrev(head);
        head->setNext(ptr);
        head = ptr;
        ++it;
    }
    sz = value.size();
}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue(const Queue &other) {
    if (other.empty()) {
        head = nullptr;
        tail = nullptr;
        sz = 0;
        return;
    }
    Node<T> *otherptr = other.tail;
    Node<T> *ptr = alloc.allocate(1);
    ptr->setValue(otherptr->getValue());
    head = ptr;
    tail = ptr;

    for (size_t i = 1; i < other.size(); ++i) {
        otherptr = otherptr->getNext();
        ptr = alloc.allocate(1);
        ptr->setValue(otherptr->getValue());
        ptr->setPrev(head);
        head->setNext(ptr);
        head = ptr;
    }
    sz = other.size();
}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue(Queue &&other) {
    this->head = other.head;
    other.head = nullptr;
    sz = other.size();
}

template <typename T, typename Allocator>
Queue<T, Allocator>::~Queue() {
    alloc.free();
}

template <typename T, class Allocator>
size_t Queue<T, Allocator>::size() const {
    return sz;
}

template <typename T, class Allocator>
bool Queue<T, Allocator>::empty() const {
    return (sz == 0);
}

template <typename T, typename Allocator>
void Queue<T, Allocator>::clear() noexcept {
    int size = this->size();
    for (int i = 0; i < size; ++i) {
        this->pop();
    }
}

template <typename T, typename Allocator>
Iterator<T> Queue<T, Allocator>::begin() const {
    Iterator<T> begin(tail);
    return begin;
}

template <typename T, typename Allocator>
Iterator<T> Queue<T, Allocator>::end() const {
    Iterator<T> end(head);
    return end;
}

template <typename T, typename Allocator>
ConstIterator<T> Queue<T, Allocator>::CBegin() const {
    ConstIterator<T> begin(tail);
    return begin;
}

template <typename T, typename Allocator>
ConstIterator<T> Queue<T, Allocator>::CEnd() const {
    ConstIterator<T> end(head);
    return end;
}

template <typename U>
ostream &operator<<(ostream &os, const Queue<U> &q) {
    if (q.empty())  
        return os; 
    int size = q.size();
    Node<U> *tmp = q.tail;
    for (int i = 0; i < size; ++i) {
        os << tmp->getValue() << ' ';
        tmp = tmp->getNext();
    }
    os << endl;
    return os;
}
