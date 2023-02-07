#include <iostream>
#include "review.h"

std::vector <int> InitializeArray(int size){
    std::vector <int> array;
    for(int i = 0; i < size; i++){
        array.push_back(0);
    }
    return array;
}