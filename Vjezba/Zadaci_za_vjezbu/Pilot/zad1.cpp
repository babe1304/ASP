#include <iostream>

int uvecajZaJedan(int n) {
    if (n != 0) {
        int dio = uvecajZaJedan(n/10);
        int drugi_dio = n % 10;
        if (drugi_dio == 9) drugi_dio = 0;
        else drugi_dio++;
        return dio * 10 + drugi_dio;
    }
    return 0;
}

int main(void) {
    std::cout << uvecajZaJedan(195); 
}