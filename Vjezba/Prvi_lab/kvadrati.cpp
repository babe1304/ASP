#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int *kvadrati(int *polje) {
    int s = 0;
    while (*(polje + s) != 0) s++;
    
    int *novo_polje = new int[s];
    for (int i = 0; i < s; i++) novo_polje[i] = 0;

    time_t t;
    int n;

    srand((unsigned) time(&t));

    for (int i = 0; i < s; i++) {
        while (novo_polje[n] != 0) n = rand() % s;
        novo_polje[n] = polje[i] * polje[i];
    }

    return novo_polje;
}

int main(void) {
    int n;
    cout << "Upisi n ";
    cin >> n;

    int *A = new int[n];
    int *B = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Upisi clan ";
        cin >> A[i];
    }

    B = kvadrati(A);
    
    for (int i = 0; i < n; i++) cout << B[i] << " ";

    delete[] A;
    delete[] B;
    return EXIT_SUCCESS;
}