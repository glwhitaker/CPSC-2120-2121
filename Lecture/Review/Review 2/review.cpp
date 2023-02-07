#include <iostream>
#include "review.h"

int WriteOut(std::string output){
    std::cout << output;

    return 1;
}
int WriteOut(int output){
    std::cout << output;

    return 2;
}
int WriteOut(double output){
    std::cout << output;

    return 3;
}