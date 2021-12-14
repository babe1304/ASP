#include <iostream>

using namespace std;

class Stog {
    int polje[100];
    int top = -1;

    public:
        Stog() {}
        bool push(int broj) {
            if (top + 1 > 100) return false;
            polje[++top] = broj;
            return true;
        }

        void print() {
            cout << "Vrh -> 🤣 ";
            for (int i = top; i > -1; i--) cout << polje[i] << " ";
            cout << "-> Dno 👍";
        }
};

int main(void) {
    Stog s;
    for (int i = 0; i < 101; i++) {
        s.push(i);
    }
    s.print();

    return EXIT_SUCCESS;
}