#include <iostream>

using namespace std;

struct zapis {
    int sifra;
    string ime;
};

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void obicanBubbleSort(zapis A[], int n, char smjer) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j].sifra < A[j + 1].sifra && smjer == '1') swap(A[j], A[j + 1]);
            if (A[j].sifra > A[j + 1].sifra && smjer == '0') swap(A[j], A[j + 1]);
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    zapis A[n];

    for (int i = 0; i < n; i++) 
        cin >> A[i].sifra >> A[i].ime;
    for (int i = 0; i < n; i++) cout << A[i].sifra << " " << A[i].ime << " ";
    cout << endl;
    obicanBubbleSort(A, n, '0');
    for (int i = 0; i < n; i++) cout << A[i].sifra << " " << A[i].ime << " ";
    cout << endl;
    obicanBubbleSort(A, n, '1');
    for (int i = 0; i < n; i++) cout << A[i].sifra << " " << A[i].ime << " ";

    return EXIT_SUCCESS;
}