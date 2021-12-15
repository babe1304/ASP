#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

//jednostrani selection sort
void selection2Sort(int A[], int n, char smjer) {
    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if (A[min] >= A[j] && smjer == '0') min = j;
            if (A[min] <= A[j] && smjer == '1') min = j;
        }
        swap(A[min], A[i]);
    }
}

//obostrani selection sort
void selection2Sort2(int A[], int n, char smjer) {
    int min, max;
    for (int i = 0; i < n; i++) {
        min = i; max = i;
        for (int j = i; j < n - i; j++) {
            if (A[min] > A[j]) min = j;
            if (A[max] < A[j]) max = j;
        }
        if (smjer == '1') {
            swap(A[min], A[i]);
            swap(A[max], A[n - i - 1]);
        } else {
            swap(A[max], A[i]);
            swap(A[min], A[n - i - 1]);
        }
    }
}

int main(void) {
    int A[10];
    srand(0);
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 20;
        cout << A[i] << " ";
    }
    cout << endl;

    selection2Sort2(A, 10, '1');
    for (int i = 0; i < 10; i++) cout << A[i] << " ";
    cout << endl;
    selection2Sort2(A, 10, '0');
    for (int i = 0; i < 10; i++) cout << A[i] << " ";

    return EXIT_SUCCESS;
}