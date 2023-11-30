#include <stdio.h>
#include <iostream>

int main() {
    std::string str = "Hello!";
    std::cout << str << std::endl;
    std::cout << str.length() << std::endl;
    std::cout << str[0] << std::endl;
    std::cout << str[str.length()-1] << std::endl;
    str[str.length()-1] = ' ';
    std::cout << str << std::endl;
    str += "Ross";
    std::cout << str << std::endl;
    std::cout << str.find('R') << std::endl;
    std::string newstr = "Hello Ross";
    std::cout << str.compare(newstr) << std::endl;
}
