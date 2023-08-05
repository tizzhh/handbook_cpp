#include <iostream>
#include <vector>

int main(void) {
    std::string pass;
    std::cin >> pass;
    
    int lower = 0, upper = 0, digit = 0, special = 0;
    if (pass.size() < 8 || pass.size() > 14) {
        std::cout << "abs\n";
        return 0;
    }
    for (char ch : pass) {
        if (ch < 33 || ch > 126) {
            std::cout << "NO\n";
            return 0;
        } else if (ch >= 'A' && ch <= 'Z') {
            upper = 1;
        } else if (ch >= 'a' && ch <= 'z') {
            lower = 1;
        } else if (ch >= '0' && ch <= '9') {
            digit = 1;
        } else {
            special = 1;
        }
    }
    if (upper + digit + lower + special >= 3) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}