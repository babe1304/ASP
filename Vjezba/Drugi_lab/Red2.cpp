#include <iostream>

using namespace std;

class Red {
    struct Cvor {
        double data;
        Cvor* next;
    };

    Cvor* ulaz = nullptr;
    Cvor* izlaz = nullptr;

    public:
        bool dodaj(double broj) {
            Cvor* newEl = new (nothrow) Cvor;
            if (!newEl) return false;
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

        bool skini(double* broj) {
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
    int n = 10;
    double broj;
    //cin >> n;
    for (int i = 0; i < n; i++) {
        //cin >> broj;
        r.dodaj(i);
    }

    while (r.skini(&broj)) cout << broj << " ";

    return EXIT_SUCCESS;
}