#include <iostream>

using namespace std;

class Osoba {
    string ime;
    unsigned short int godine;

    public:
        Osoba(string ime, int godine) : ime(ime), godine(godine) {}
        Osoba() {}
        bool operator<(const Osoba &other) {
            if (this->godine < other.godine) return true;
            else if (this->godine == other.godine) {
                if (this->ime[0] < other.ime[0]) return true;
                else return false;
            }
            else return false;
        }

        void print() {
            cout << this->ime << " " << this->godine << " ";
        }

};

template <class T> void insertionSort(T A[], int n) {
    T temp;
    int i, j;
    for (i = 0; i < n; i++) {
        temp = A[i];
        for (j = i; j >= 1 && temp < A[j - 1]; j--) A[j] = A[j - 1];
        A[j] = temp;
    }
}

int main(void) {
    Osoba osobe[] = {{"Ana",20},{"Ivo",9}, {"Marko",9}, {"Lidija",22}, {"Pero",19}};
    /*for (int i = 0; i < 10; i++) {
        string ime; int godine;
        cin >> ime >> godine;
        osobe[i] = Osoba(ime, godine);
    }*/

    insertionSort(osobe, 5);
    for (int i = 0; i < 5; i++) osobe[i].print();

    return EXIT_SUCCESS;
}