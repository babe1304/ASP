#include <iostream>

using namespace std;

void ispisiVeci(int A[], int m, int B[], int n) {
    if (m >= 1 || n >= 1) {
        if (m > n) {
            cout << A[m - 1] << " - " << A[m - 1] << endl;
            m--;
        } else if (n > m) {
            cout << "- " << B[n - 1] <<  " " << B[n - 1] << endl;
            n--;
        }
        else  {
            cout << A[m - 1] << " " << B[n - 1] << " " << max(A[m - 1], B[n - 1]) << endl;
            n--;
            m--;
        }
        ispisiVeci(A, m, B, n);
    }
}

int main(void) {
    int A[] = {2, 4, 1, 3};
    int B[] = {4, 4, 8};

    ispisiVeci(A, 4, B, 3);
    return EXIT_SUCCESS;
}