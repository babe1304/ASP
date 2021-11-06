#include <iostream>
namespace s1 {
    float const pi = 3.14159;
}
namespace s2 {
    float const pi = 3.14;
}
using namespace std;
using namespace s1;
using namespace s2;

int main(void) {
    cout << s1::pi;
    return 0;
}