#include <iostream>

using namespace std;

template <typename T> int binarnoTrazi(T polje[], int n, T x) {
    if (polje[n - 1] == x) return n - 1;
    else if (n <= 0) return -1;
    else return binarnoTrazi(polje, n - 1, x);
}

int main(void) {
    int n;
    cout << "Upisi n ";
    cin >> n;

    float *A = new float[n];

    for (int i = 0; i < n; i++) {
        A[i] = 1.1 * i;
        cout << A[i] << endl;
    }

    cout << "Upisi sto zelis traziti ";
    float x;
    cin >> x;

    int index = binarnoTrazi(A, n, x);
    if (index != -1) cout << index;
    else cout << "Broj se ne nalazi u polju.";

    delete[] A;

    return EXIT_SUCCESS;
}