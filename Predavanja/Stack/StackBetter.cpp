#include <iostream>
#include <string>

using namespace std;

template <class T> class Stack {
   template <class X> struct Atom {
      X data;
      Atom<X> *next;
   };

   Atom<T> *head = nullptr;

 public:
   bool push(T data) {
      Atom<T> *newElement = new (nothrow) Atom<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }

   bool pop(T &el) {
       if (head == nullptr) return false;

       el = head->data;
       Atom<T>* tbd = head;
       head = head->next;
       delete tbd;
       return true;
   }
};

int main(void) {
    Stack<string> s;
    string el;

    s.push("Prvi");
    s.push("Drugi");
    s.push("Treci");
    s.pop(el);
    cout << el << endl;
    s.pop(el);
    cout << el << endl;
    s.pop(el);
    cout << el << endl;

    return EXIT_SUCCESS;
}