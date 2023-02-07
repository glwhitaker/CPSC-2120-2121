#include <iostream>
#include "review.h"

void ReadStdIn(){
    int integerinput;
    double doubleinput;
    std::string stringinput;

    std::cin >> integerinput >> doubleinput >> stringinput;

    std::cout << integerinput << std::endl;
    std::cout << doubleinput << std::endl;
    std::cout << stringinput << std::endl;
}