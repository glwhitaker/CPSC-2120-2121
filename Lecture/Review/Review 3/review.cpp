#include <iostream>
#include "review.h"

void ReadStdIn2(){
    std::string input;
    int count = 0;
    while(std::cin >> input && input != "q"){
        count++;
    }

    std::cout << count;
}