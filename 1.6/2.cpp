#include <iostream>
#include <string>

int main(void) {
    std::string str, str2;
    std::cin >> str;

    str2.push_back(str[0]);
    for (size_t i = 1; i != str.size(); ++i) {
        switch(str[i]) {
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                if (str2.back() != '1') str2.push_back('1');
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                if (str2.back() != '2') str2.push_back('2');
                break;
            case 'd':
            case 't':
                if (str2.back() != '3') str2.push_back('3');
                break;
            case 'l':
                if (str2.back() != '4') str2.push_back('4');
                break;
            case 'm':
            case 'n':
                if (str2.back() != '5') str2.push_back('5');
                break;
            case 'r':
                if (str2.back() != '6') str2.push_back('6');
                break;
        }
    }
    while (str2.size() < 4) {
        str2.push_back('0');
    }
    str2.resize(4);
    std::cout << str2 << '\n';
}