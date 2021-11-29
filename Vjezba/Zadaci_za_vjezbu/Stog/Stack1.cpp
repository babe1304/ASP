#include <iostream>

using namespace std;

template <class T> class Stack {

   template <class X> struct StackElement {
      X item;
      StackElement<X> *next;
   };

   StackElement<T> *top = nullptr;

 public:
   bool push(T item) {
      StackElement<T> *newElement = new (nothrow) StackElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->item = item;
      newElement->next = top;
      top = newElement;
      return true;
   }
   bool pop(T &item) {
      if (top == nullptr)
         return false;
      item = top->item;
      StackElement<T> *tmp = top;
      top = top->next;
      delete tmp;
      return true;
   }
};

template <class T> void remove(Stack<T> *s) {
    Stack<T> s1, s2;
    T el, x;
    
    while (s->pop(el)) {
        s1.push(el);
        while (s->pop(x)) {
            if (x != el) s2.push(x);
        }
        while (s2.pop(x)) s->push(x);
    }

    while (s1.pop(x)) s->push(x);
}

int main(void) {
    Stack<int> ls;
    ls.push(1);
    ls.push(1);
    ls.push(1);
    ls.push(1);
    ls.push(1);
    ls.push(1);
    ls.push(1);

    remove(&ls);

    return EXIT_SUCCESS;
}