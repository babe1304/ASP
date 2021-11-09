#include <iostream>

using namespace std;

template <typename T> int binarnoTrazi(T polje[], int n, T x) {
    int left = 0;
    int right = n - 1;
    int mid = n / 2;
    int index = -1;

    while (right >= left) {
        mid = (right + left) / 2;

        if (x > polje[mid]) left = mid + 1;
        else if (x < polje[mid]) right = mid - 1;
        else {
            index = mid;
            break;
        }
    }
    return index;
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