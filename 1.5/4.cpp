#include <iostream>

int main(void) {
    int month, year, isLeap;
    std::cin >> month >> year;
    if (year % 400 == 0) {
       isLeap = 1;
    } else if (year % 100 == 0) {
        isLeap = 0;
    } else if (year % 4 == 0) {
        isLeap = 1;
    } else {
        isLeap = 0;
    }
    
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            std::cout << 31 << '\n';
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            std::cout << 30 << '\n';
            break;
        case 2:
            isLeap ? std::cout << 29 << '\n' : std::cout << 28 << '\n';
            break;
    }
}