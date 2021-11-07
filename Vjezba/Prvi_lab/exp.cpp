#include <iostream>

using namespace std;

double exp(double x, int n, int *fakt, double *xpot) {
    if (n < 0) return 0;

    double medu_rez = exp(x, n - 1, fakt, xpot);
    *xpot *= x;
    *fakt *= (n == 0) ? 1 : n;
    
    medu_rez += (*xpot) / (*fakt);
    return medu_rez;
}

int main(void) {
    int n;

    cout << "Upisi n ";
    cin >> n;
    
    double *A = new double[n];
    int fakt = 1;
    double xpot = 1;

    for (int i = 0; i < n; i++) {
        A[i] = exp(1, i, &fakt, &xpot);
        fakt = 1;
        xpot = 1;
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }

    return EXIT_SUCCESS;
}