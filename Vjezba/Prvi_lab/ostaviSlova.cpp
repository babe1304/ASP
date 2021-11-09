#include <iostream>

using namespace std;

char *ostaviSlova(string ulaz) {
    int n = ulaz.size();
    char *izlaz = new char[n];
    int b = 0;

    for (int i = 0; i < n; i++) {
        char znak = ulaz[i];
        if ((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')) {
            *(izlaz + b++) = znak; 
        }
    }
    //*(izlaz + b) = '\0';
    return izlaz;
}

int main(void) {
    string ulaz = "asp12_i_ASP13";
    char *izlaz = ostaviSlova(ulaz);

    cout << izlaz;

    delete []izlaz;
    return EXIT_SUCCESS;
}