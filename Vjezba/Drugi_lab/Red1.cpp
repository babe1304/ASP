#include <iostream>

using namespace std;

class Red {
    const static int MAX = 10;
    double polje[MAX];
    int izlaz = 0;
    int ulaz = 0;

    public:
        bool dodaj(double broj) {
            if (ulaz == MAX) return false;
            polje[ulaz++] = broj;
            return true;
        }

        bool skini(double *broj) {
            if (ulaz == izlaz) return false;
            *broj = polje[izlaz++];
            return true;
        }
};

int main(void) {
    Red r;
    for (int i = 0; i < 10; i++) r.dodaj(i);
    double broj;
    while (r.skini(&broj)) cout << broj << " ";

    return EXIT_SUCCESS;
}