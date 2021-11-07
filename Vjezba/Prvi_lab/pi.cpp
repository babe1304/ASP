#include <iostream>
#include <math.h>

using namespace std;

double pi(int n) {
    if (n <= 0) return 0;

    double numPi = pi(n - 1) + 4 * pow(-1, n + 1) / (2*n - 1);
    return numPi ;
}

int main(void) {
    int n;
    cout << "Unesi n ";
    cin >> n;
    
    double *A = new double[n];
    for (int i = 0; i < n; i++) {
        A[i] = pi(i + 1);
        cout << A[i] << endl;
    }
    return EXIT_SUCCESS;
}