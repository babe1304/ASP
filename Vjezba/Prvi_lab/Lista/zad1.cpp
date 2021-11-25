#include <iostream>

using namespace std;

template <typename T> class ListElement {
    T data;
    ListElement<T> *next;
}

template <typename T> class ListIterator {
    private:
        ListElement<T> *ptr = nullptr;

    public:
        ListIterator<T>() : ptr(nullptr) {}
        ListIterator<T>(ListElement<T> *ptr) : ptr(ptr) {}
        ListIterator<T> &operator++();
        ListIterator<T> operator++(int);// postfix ++
        bool operator!=(const ListIterator<T> &other) { return ptr != other.ptr; }
        T &operator*() { return ptr->data; }
}