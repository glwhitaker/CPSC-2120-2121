/*
 * Name: Grayson Whitaker
 * Date Submitted: 2/20/2023
 * Lab Section: 002
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target){
    // loop through the vector and return the index of the target if it is found
    for(int i = 0; i < data.size(); i++){
        if(data[i] == target) return i;
    }
    return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){
    int lowIndex = 0;
    int highIndex = data.size() - 1;
    int midIndex = (highIndex + lowIndex) / 2;
    // loop through the vector and return the index of the target if it is found
    while(lowIndex <= highIndex){
        // if the target is found, return the index
        if(data[midIndex] == target){
            return midIndex;
        }
        // if the target is greater than the middle element, set the low index to the middle index + 1
        else if(data[midIndex] < target){
            lowIndex = midIndex + 1;
        }
        // if the target is less than the middle element, set the high index to the middle index - 1
        else if(data[midIndex] > target){
            highIndex = midIndex - 1;
        }
        // recalculate the middle index
        midIndex = (highIndex + lowIndex) / 2;
    }
    return -1;
}
