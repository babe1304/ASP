#include <iostream>
#include <string>

using namespace std;

template <class T> struct ListElement {
   T data;
   ListElement<T> *next;
};

template <class T> class ListIterator {
 private:
   ListElement<T> *ptr = nullptr;

 public:
   ListIterator<T>() : ptr(nullptr) {}
   ListIterator<T>(ListElement<T> *ptr) : ptr(ptr) {}
   ListIterator<T>* operator++() { // prefix ++
      if (ptr)
         ptr = ptr->next;
      return this;
   }
   ListIterator<T> operator++(int i) { // postfix ++
      ListIterator<T> tmp = *this;
      ++(*this);
      return tmp;
   }
   bool operator!=(const ListIterator<T> &other) { return ptr != other.ptr; }
   T &operator*() { return ptr->data; }
};

template <class T> class List {
 private:
   ListElement<T> *head = nullptr;

 public:
   bool Insert(T data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool Append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
      return true;
   }
   bool InsertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
                               // imati implementiran operator >
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      ListElement<T> **p;
      for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      return true;
   }

   typedef ListIterator<T> iterator;
   iterator begin() { return iterator(head); }
   iterator end() { return iterator(); }

   //prvi dio zadatka
   T& at(int k) {
       int size = 0;
       for (iterator it = this->begin(); it != this->end(); size++, it++);
       if (k < 0 || k >= size) throw runtime_error("Pogrešan broj"); 
       iterator it = this->begin();
       for (int i = 0; i < k; i++, it++);
       return *it; 
   }
};

int main(void) {

    List<int> l;
    l.Insert(4);
    l.Insert(5);
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);
    cout << l.at(2);

    return EXIT_SUCCESS;
}