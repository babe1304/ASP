#include <iostream>

using namespace std;

class Red {
    struct Cvor {
        int data;
        Cvor* next;
    };

    Cvor* ulaz = nullptr;
    Cvor* izlaz = nullptr;

    public:
        bool dodaj(int broj) {
            Cvor* newEl = new (nothrow) Cvor;
            if (!newEl) return false;
            //cout << broj << " ";
            newEl->data = broj;
            newEl->next = nullptr;
            if (!ulaz && !izlaz) {
                ulaz = newEl;
                izlaz = newEl;
                return true;
            }
            ulaz->next = newEl;
            ulaz = newEl;
            return true;
        }

        bool poljeURed(int polje[], int n) {
            if (n <= 0) return true;
            else if (dodaj(polje[n - 1])) {
                cout << polje[n - 1] << " ";
                return poljeURed(polje, n - 1);
            } else return false;
        }

        //za provjeru ispisa
        bool skini(int* broj) {
            if (!izlaz) return false;
            *broj = izlaz->data;
            Cvor* tmp = izlaz;
            izlaz = izlaz->next;
            delete tmp;
            return true;
        }
};

int main(void) {
    Red r;
    int polje[10];
    for (int i = 0; i < 10; i++) {
        polje[i] = i * 2;
        cout << i * 2 << " "; 
    }
    cout << endl;
    r.poljeURed(polje, 10);
    cout << endl;
    int broj;
    while (r.skini(&broj)) cout << broj << " ";

    return EXIT_SUCCESS;
}