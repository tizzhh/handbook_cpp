#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector <std::string> strs;
    std::string temp;
    while(getline(std::cin, temp)) {
        strs.push_back(temp);
    }
    std::sort(strs.rbegin(), strs.rend());
    for (std::string str : strs) {
        std::cout << str << '\n';
    }
}