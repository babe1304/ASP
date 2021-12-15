#include <iostream>

using namespace std;

void Zamijeni(string *prvi, string *drugi) {
    string temp;
    temp = *prvi;
    *prvi = *drugi;
    *drugi = temp;
}

void BubbleSortPoboljsani(string A[], int n, int smjer) {
    bool happend = false;
    for (int i = 0; happend == false; i++) {
        happend = true;
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] < A[j + 1] && smjer == 1) {
                happend = false;
                Zamijeni(&A[j], &A[j + 1]);
            } 
            if (A[j] > A[j + 1] && smjer == 0) {
                happend = false;
                Zamijeni(&A[j], &A[j + 1]);
            }  
        }
    }
}

int main(void) {
    string A[] = {"Ivo", "Marko", "Juraj", "Pero"};
    BubbleSortPoboljsani(A, 4, 0);
    for (int i = 0; i < 4; i++) cout << A[i] << " ";
    cout << endl;
    BubbleSortPoboljsani(A, 4, 1);
    for (int i = 0; i < 4; i++) cout << A[i] << " ";

    return EXIT_SUCCESS;
}