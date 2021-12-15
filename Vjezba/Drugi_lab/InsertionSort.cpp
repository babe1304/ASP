#include <iostream>
#include <string>

using namespace std;

struct Zapis {
    int pos_broj;
    string mjesto;
};

void insertionSort(Zapis A[], int n, char smjer) {
    Zapis temp;
    int i, j;
    for (i = 1; i < n; i++) {
        temp = A[i];
        if (smjer == '0') {
            for (j = i; j >= 1 && A[j - 1].pos_broj > temp.pos_broj; j--) A[j] = A[j - 1];
            A[j] = temp;
        } else {
            for (j = i; j >= 1 && A[j - 1].pos_broj < temp.pos_broj; j--) A[j] = A[j - 1];
            A[j] = temp;
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    Zapis A[n];
    srand(0);
    for (int i = 0; i < n; i++) {
        cin >> A[i].mjesto >> A[i].pos_broj;
    }
    for (int i = 0; i < n; i++) cout << A[i].mjesto << " " << A[i].pos_broj << " ";
    cout << endl;
    insertionSort(A, n, '0');
    for (int i = 0; i < n; i++) cout << A[i].mjesto << " " << A[i].pos_broj << " ";
    cout << endl;
    insertionSort(A, n, '1');
    for (int i = 0; i < n; i++) cout << A[i].mjesto << " " << A[i].pos_broj << " ";

    return EXIT_SUCCESS;
}