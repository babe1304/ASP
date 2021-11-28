#include <iostream>
#include <string>

using namespace std;

template <class T> class List {
   template <class X> struct ListElement {
      X data;
      ListElement<X> *next;
   };

   ListElement<T> *head = nullptr;

 public:
 
   void removeGreaterThan3(T item) {
      ListElement<T>* curr;
      ListElement<T>* prev;
      while (head && head->data > item) {
         ListElement<T>* tmp = head;
         head = head->next;
         delete tmp;
      }
      prev = head;
      curr = head->next;
      while (curr) {
         if (curr->data > item) {
            ListElement<T>* tmp = curr;
            prev->next = curr->next;
            curr = curr->next;
         } else {
            prev = curr;
            curr = curr->next;
         }
      }
      
   }

   void removeGreaterThan1(T item) {
       ListElement<T>* curr;
       while (head && head->data > item) {
           ListElement<T>* tmp = head;
           head = head->next;
           delete tmp;
       }
       curr = head;
       while (curr->next) {
           if (curr->next->data > item) {
               ListElement<T>* tmp = curr->next;
               curr->next = curr->next->next;
               delete tmp;
           } else {
               curr = curr->next;
           }
       }
   } 

   void removeGreaterThan2(T item) {
      ListElement<T>** p = &head;

      while (*p) {
         if ((*p)->data > item) {
            ListElement<T>* tmp = *p;
            *p = (*p)->next;
            delete tmp;
         } else {
            p = &((*p)->next);
         }
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
    List<int> ls;
    ls.append(1);
    ls.append(2);
    ls.append(3);
    ls.append(4);
    ls.append(5);
    ls.append(6);
    ls.append(2);
    ls.append(1);
    ls.append(2);
    ls.print();
    ls.removeGreaterThan1(3);
    ls.print();

   List<int> ls1;
    ls1.append(1);
    ls1.append(2);
    ls1.append(3);
    ls1.append(4);
    ls1.append(5);
    ls1.append(6);
    ls1.append(2);
    ls1.append(1);
    ls1.append(2);
    ls1.print();
    ls1.removeGreaterThan2(3);
    ls1.print();

    List<int> ls2;
    ls2.append(1);
    ls2.append(2);
    ls2.append(3);
    ls2.append(4);
    ls2.append(5);
    ls2.append(6);
    ls2.append(2);
    ls2.append(1);
    ls2.append(2);
    ls2.print();
    ls2.removeGreaterThan3(3);
    ls2.print();

    return EXIT_SUCCESS;
}