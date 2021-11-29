#include <iostream>

using namespace std;

template <class T> class List {
   template <class X> struct ListElement {
      X data;
      ListElement<X> *next;
   };

   ListElement<T> *head = nullptr;

 public:
   void kopirajParne(List<T> &dstList) { //zadatak
      ListElement<T>** p = &head;

      while (*p) {
          if ((*p)->data % 2 == 0) dstList.insert((*p)->data);          
          p = &((*p)->next);
      }
   }

   bool insert(T data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
#if 1
      // elementarno, s jednostrukim pokazivačem
      if (!head) { // prazna lista
         head = newElement;
      } else {
         ListElement<T> *p;
         for (p = head; p->next; p = p->next)
            ; // iteracija na kraj liste
         p->next = newElement;
      }
#else
      // naprednije, s **
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
#endif
      return true;
   }
   bool insertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
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
   bool remove(T data) {
      ListElement<T> **p;
      for (p = &head; *p && data != (*p)->data; p = &((*p)->next))
         ;
      if (*p) {
         ListElement<T> *tmp;
         tmp = *p;
         *p = (*p)->next;
         delete tmp;
         return true;
      } else {
         return false;
      }
   }
   void print() {
      for (ListElement<T> *p = head; p; p = p->next) {
         cout << p->data << " ";
      }
      cout << endl;
   }
   // samo za ilustraciju, nikad tako u stvarnosti
   void printRecursive() { printR(head); }

 private:
   void printR(ListElement<T> *p) {
      if (p == nullptr) {
         cout << endl;
      } else {
         cout << p->data << " ";
         printR(p->next);
      }
   }
};

int main(void) {
    List<int> srcList;
    srcList.append(5);
    srcList.append(4);
    srcList.append(7);
    srcList.append(1);
    srcList.append(6);
    srcList.append(8);
    srcList.append(2);
    srcList.append(3);

    List<int> dstList;
    srcList.kopirajParne(dstList);

    srcList.print();
    dstList.print();

    return EXIT_SUCCESS;
}