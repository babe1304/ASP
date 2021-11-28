#include <iostream>

using namespace std;

template <typename T> bool search(const T A[], const size_t n, const T &item) {
    if (n == 0) return false;
    else if (A[n - 1] == item) return true;
    else return search(A, n - 1, item);
}

int main(void) {
    int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    cout << search(B, 10, 4) << endl;
    cout << search(B, 10, 10);
    return EXIT_SUCCESS;
}