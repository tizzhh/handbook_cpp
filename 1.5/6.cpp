#include <iostream>

int main(void){
    unsigned int a, sum = 0;
    std::cin >> a;
    while(a) {
        sum += a % 10;
        a /= 10;
    }
    std::cout << sum << '\n';
}