#include <iostream>

using namespace std;

class Stog {
    struct cvor {
        int data;
        cvor* next;
    };

    cvor* top = nullptr;

    public:
        bool push(int element) {
            cvor* newEl = new (nothrow) cvor;
            if (!newEl) return false;

            newEl->data = element;
            
            newEl->next = top;
            top = newEl;
            return true;
        }

        void print() {
            cvor* p = top;
            while (p) {
                cout << p->data << " ";
                p = p->next;
            }
        }
};

int main(void) {
    Stog s;
    srand(0);
    for (int i = 0; i < 101; i++) {
        s.push(rand()%10);
    }
    s.print();

    return EXIT_SUCCESS;
}