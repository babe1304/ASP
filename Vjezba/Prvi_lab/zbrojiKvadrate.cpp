#include <iostream>
#include <math.h>

using namespace std;

int zbrojiKvadrate(int polje[], int n) {
    if (n <= 0) return 0;

    int rez = zbrojiKvadrate(polje, n - 1);;

    int zaokruzeni_korijen = round(sqrt(polje[n - 1]));
    if (pow(zaokruzeni_korijen, 2) == polje[n - 1] && polje[n - 1] != 0) 
        rez += polje[n - 1]; 
    
    return rez;
}

int main(void) {
    int n;
    cout << "Unesi broj n: ";
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "unesi clan polja --> ";
        cin >> A[i];
    }

    cout << zbrojiKvadrate(A, n);
}