#include <iostream>

int main(void){
    int n, sign = 1;
    double sum = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        sum += sign / (double) i ;
        sign = -sign;
    }
    std::cout << sum << '\n';
}