#include <iostream>

using namespace std;

class Stog {
    const static int MAX = 10;
    int polje[MAX];
    int top = -1;

    public:
        bool push(int element) {
            if (top + 1 > MAX) return false;
            polje[++top] = element;
            return true;
        }
        
        bool pop(int &el) {
            if (top < 0) return false;
            el = polje[top--];
            return true;
        }
};

int main(void) {
    Stog s, p;
    srand(0);
    for (int i = 0; i < 10; i++) {
        s.push(rand() % 10 + 1);
    }
    int el;
    while (s.pop(el)) {
        cout << el << " ";
        p.push(el);
    }
    cout << endl;
    while (p.pop(el)) cout << el << " ";
}