#include <iostream>

using namespace std;

void f(int polje[], int n, int m) {
    if (n <= 0) {
        polje[n] = 1;
        return;
    }
    f(polje, n - 1, m);
    polje[n] = polje[n - 1] * m;
    return;
}

int main(void) {
    int n = 5;
    int m = 3;
    int A[n];
    f(A, n, m);
    for (int i = 0; i < n; i++) cout << A[i] << endl;

    return EXIT_SUCCESS;
}