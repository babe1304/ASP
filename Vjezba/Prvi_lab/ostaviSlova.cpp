#include <iostream>

using namespace std;

char *ostaviSlova(string ulaz) {
    int n = ulaz.size();
    char *izlaz = new char[n];
    int b = 0;

    for (char znak : ulaz) {
        if (isalpha(znak)) *(izlaz + b++) = znak; 
    }
    *(izlaz + b) = '\0';
    return izlaz;
}

int main(void) {
    string ulaz = "asp12_i_ASP13";
    char *izlaz = ostaviSlova(ulaz);

    cout << izlaz;

    delete []izlaz;
    return EXIT_SUCCESS;
}