#include <iostream>
using namespace std;
template <class T> class Queue {
 private:
   static const int MAX = 100;
   T queue[MAX];
   int write = 0;
   int read = 0;

 public:
   bool enqueue(T item) {
      if ((write + 1) % MAX == read)
         return false;
      queue[write] = item;
      write = (write + 1) % MAX;
      return true;
   }
   bool dequeue(T &item) {
      if (write == read)
         return false;
      item = queue[read];
      read = (read + 1) % MAX;
      return true;
   }
   int count() {
      if (write >= read) {
         return (write - read); // standardno
      } else {
         return (write - read + MAX); // cirkularnost
      }
   }
};

template <class T> Queue<T> *split(Queue<T> *q) {
    int count = 0;
    T el;
    Queue<T>* nepar = new Queue<T>();
    Queue<T> par;
    while (q->dequeue(el)) {
        if (count % 2 == 1) nepar->enqueue(el);
        else par.enqueue(el);
        count++;
    }

    while (par.dequeue(el)) q->enqueue(el);

    return nepar;
}

int main(void) {
    Queue<int>* red;
    red->enqueue(0);
    red->enqueue(1);
    red->enqueue(2);
    red->enqueue(3);
    red->enqueue(4);
    red->enqueue(5);
    red->enqueue(6);

    Queue<int>* izlaz;
    izlaz = split(red);

    int i;
    while (izlaz->dequeue(i)) cout << i << " ";

    return EXIT_SUCCESS;
}