#include <iostream>

using namespace std;

template <typename T> class StackList {
    private:
        const static int MAX = 100;
        T stackArray[MAX];
        int top = -1;

    public:
        bool Push(T el) {
           if (top >= MAX - 1) return false;
           stackArray[++top] = el;
           return true;
        }

        bool Pop(T &el) {
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

int main(void) {
    StackList<int> s;
    s.Push(3);
    s.Push(2);
    s.Push(5);
    s.Push(4);
    s.Push(1);
    
    s.print();
    int el;
    while (s.Pop(el)) cout << el << " ";

    return EXIT_SUCCESS;
}