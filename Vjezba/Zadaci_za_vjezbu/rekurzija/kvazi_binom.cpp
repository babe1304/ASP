#include <iostream>

using namespace std;

int K(int n, int m) {
    if (n < 0 || m > n) return 0;
    else if (m == n || m == 0) return 1;
    return K(n - 1, m - 1) + m * K(n - 1, m + 1);
}

int main(void) {
    cout << K(7, 4);

    return EXIT_SUCCESS;
}