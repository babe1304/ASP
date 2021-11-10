#include <iostream>
#include <math.h>

using namespace std;

double f(double z, int k) {
    if (k == 0) return z;
    double rez = (-1 * pow(z, 2) * f(z, k - 1))/((2 * k + 1) * 2 * k);
    return rez;
}

int main(void) {
    double z = 0.5;
    int k = 2;
    cout << f(z, k) << endl;
    k = 10;
    cout << f(z, k) << endl;
    return EXIT_SUCCESS;
}