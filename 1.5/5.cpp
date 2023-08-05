#include <iostream>

int main(void) {
    int n, k, day, dayoftheweek;
    std::cin >> n >> k;

    dayoftheweek = n;

    for (int i = 0; i < n - 1; ++i) {
        std::cout << "   ";
    }
    
    for (day = 1; day <= k; ++day) {
        if (day < 10) {
            std::cout << ' ';
        }
        std::cout << day;
        if (dayoftheweek == 7) {
            std::cout << '\n';
            dayoftheweek = 1;
        } else {
            std::cout << ' ';
            ++dayoftheweek;
        }
    }
    if (dayoftheweek != 1) {
        std::cout << '\n';
    }
}