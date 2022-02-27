#include <iostream>

using namespace std;

template <typename T> class Stack {
    private:
        const static int MAX = 100;
        T stackArray[MAX];
        int top = -1;

    public:
        bool push(T el) {
           if (top >= MAX - 1) return false;
           stackArray[++top] = el;
           return true;
        }

        bool pop(T &el) {
            if (top <= -1) return false;
            el = stackArray[top];
            top--;
            return true;
        }

        T peek() {
            if (top < 0) throw runtime_error("Stog je prazan");
            return stackArray[top];
        }

        void print() {
            cout << "Vrh -> 🤣 ";
            for (int i = top; i > -1; i--) cout << stackArray[i] << " ";
            cout << "-> Dno 👍";
        }
};

template <class T> void sveDoNajmanjeg(Stack<T> *S) {
    T el, min;
    bool bio = false;
    Stack<T> pom;
    if (!S->pop(min)) return;
    pom.push(min);
    while (S->pop(el)) {
        if (min > el) min = el;
        pom.push(el);
    }
    while (pom.pop(el)) S->push(el);
    while (S->pop(el)) {
        if (!bio) {
            if (el == min) bio = true;
            pom.push(el);
        }
    }
    while (pom.pop(el)) S->push(el);
}

int main(void) {
    Stack<int>* S;
    S->push(8);
    S->push(1);
    S->push(7);
    S->push(2);
    S->push(1);
    S->print();
    sveDoNajmanjeg(S);
    S->print();
    return 0;
}