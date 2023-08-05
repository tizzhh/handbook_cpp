#include <iostream>
#include <string>

int main(void) {
    std::string str;
    std::getline(std::cin, str);
    for (size_t i = 0, j = str.size() - 1; i < j; ++i, --j) {
        while (str[i] == ' ' && i < j) {
            ++i;
        }
        while (str[j] == ' ' && j > i) {
            //std::cout << j << '\n';
            --j;
        }
        if (str[i] != str[j]) {
            //std::cout << i << ' ' << j << '\n';
            std::cout << "NO" << '\n';
            return 0;
        }
    }
    std::cout << "YES" << '\n';
}