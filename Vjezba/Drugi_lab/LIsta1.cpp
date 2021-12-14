#include <iostream>

using namespace std;

template <typename T> class Lista {
    template <class X> struct cvor {
        X data;
        cvor<X>* next;
    };

    cvor<T>* head = nullptr;

    public:
        bool upis(T element) {
            cvor<T>* newCvor = new (nothrow) cvor<T>;

            if (newCvor == nullptr) return false;

            newCvor->data = element;
            cvor<T>** p = &head;

            while (*p && (*p)->data < element) p = &((*p)->next);

            newCvor->next = *p;
            *p = newCvor;
            return true;
        }

        void ispis() {
            cvor<T>* p = head;

            while (p) {
                cout << p->data << " ";
                p = p->next;
            }
        }
};

int main(void) {
    Lista<int> lista;
    lista.upis(4);
    lista.upis(5);
    lista.upis(6);
    lista.upis(3);
    lista.upis(2);
    lista.upis(1);
    lista.ispis();

    return EXIT_SUCCESS;
}