#include <iostream>

using namespace std;

void ispis(float polje[], int n) {
    if (polje[0] < 0) {
        cout << polje[0] << endl;
    }

    if (n >= 0) {
        ispis(polje + 1, n - 1);
    } else {
        return;
    }
}

int main(void) {
    int n;
    float *A = new float[n];
    
    cout << "Upisi broj n ";
    cin >> n;

    for (auto i = 0; i < n; i++) {
        cout << "Upisi n-ti član ";
        cin >> A[i];
    }

    ispis(A, n);

    delete[] A;
    
    return 0;
}