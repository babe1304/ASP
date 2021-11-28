#include <iostream>
#include <string>

using namespace std;

bool podnizUNizu(string niz, string podniz, int pocetak) {
    if (podniz[0] == '\0') return true;
    else if (niz[pocetak] == podniz[0]) return podnizUNizu(niz, podniz.substr(1), pocetak + 1);
    else return false;
}

int main(void) {
    string niz = "Dobar dan!", podniz = "dan";
    cout << podnizUNizu(niz, podniz, 0) << endl;
    cout << podnizUNizu(niz, podniz, 6) << endl;

    return EXIT_SUCCESS;
}