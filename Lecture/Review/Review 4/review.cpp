#include <iostream>
#include "review.h"

void ReadWrite(){
    std::string input;
    std::string output;
    while(std::cin >> input && input != "q"){
        output += input + " ";
    }

    std::cout << output << std::endl;
}