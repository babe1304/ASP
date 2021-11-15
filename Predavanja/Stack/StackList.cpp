#include <iostream>

using namespace std;

template <typename T> class StackList {
    private:
        const static int MAX = 100;
        T stackArray[MAX];
        int top = -1;

    public:
        bool Push(T el) {
           if (top >= MAX) return false;
           top++;
           stackArray[top] = el;
           return true;
        }

        bool Pop(T &el) {
            if (top <= -1) return false;
            el = stackArray[top];
            top--;
            return true;
        }
};

int main(void) {
    StackList<int> s;
    s.Push(3);
    s.Push(2);
    s.Push(5);
    s.Push(4);
    s.Push(1);
    
    int el;
    while (s.Pop(el)) cout << el << " ";

    return EXIT_SUCCESS;
}