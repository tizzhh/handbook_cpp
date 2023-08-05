#include <iostream>

int main(void) {
    int n;
    std::cin >> n;
    int guests[n];
    for (int i = 0; i != n; ++i) {
        std::cin >> guests[i];
    }
    for (int i = 1; i <= n; ++i) {
        int pos = 0;
        for (; guests[pos] != i; ++pos);
        ++pos;
        std::cout << pos << ' ';
    }
    std::cout << '\n';
}