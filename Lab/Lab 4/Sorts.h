/*
 * Name: Grayson Whitaker
 * Date Submitted: 2/20/2023
 * Lab Section: 002
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <ctime>
#include <cstdlib>

template <class T>
std::vector<T> mergeSort(std::vector<T> lst, int low, int high){
    std::vector<T> sorted;
    // base case
    if(low == high){
        sorted.push_back(lst[low]);
        return sorted;
    }
    // recursive case, split the list into two halves and sort them
    int mid = (low + high) / 2;
    std::vector<T> half1 = mergeSort(lst, low, mid);
    std::vector<T> half2 = mergeSort(lst, mid + 1, high);
    // merge the two sorted lists
    int half1Index = 0;
    int half2Index = 0;
    // increment through the two lists
    while(half1Index < half1.size() && half2Index < half2.size()){
        // if the half1 element is less than the half2 element, add the half1 element to the sorted list
        if(half1[half1Index] < half2[half2Index]){
            sorted.push_back(half1[half1Index]);
            half1Index++;
        }
        // if the half2 element is less than the half1 element, add the half2 element to the sorted list
        else{
            sorted.push_back(half2[half2Index]);
            half2Index++;
        }
    }
    // if there are any elements left in the half1 list, add them to the sorted list
    while(half1Index < half1.size()){
        sorted.push_back(half1[half1Index]);
        half1Index++;
    }
    // if there are any elements left in the half2 list, add them to the sorted list
    while(half2Index < half2.size()){
        sorted.push_back(half2[half2Index]);
        half2Index++;
    }
    return sorted;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    // set the low and high indices, then call the recursive mergeSort function
    int lowIndex = 0;
    int highIndex = lst.size() - 1;
    return mergeSort(lst, lowIndex, highIndex);
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst, int low, int high){
    // base case
    if(low >= high){
        return lst;
    }
    // set pivot to random value between low and high and set pivotValue to the value at the pivot
    srand(time(0));
    int pivot = rand() % (high - low + 1) + low;
    T pivotValue = lst[pivot];
    // swap pivot with the first element
    T temp = lst[low];
    lst[low] = lst[pivot];
    lst[pivot] = temp;
    // set the pivotIndex to the first element
    int pivotIndex = low;
    // loop through the list
    for(int i = low + 1; i <= high; i++){
        // if the element is less than the pivot, swap it with the element at the pivotIndex and increment the pivotIndex
        if(lst[i] < pivotValue){
            pivotIndex++;
            temp = lst[i];
            lst[i] = lst[pivotIndex];
            lst[pivotIndex] = temp;
        }
    }
    // swap the pivot value with the element at the pivotIndex
    temp = lst[pivotIndex];
    lst[pivotIndex] = lst[low];
    lst[low] = temp;
    // call quickSort on the left and right halves
    lst = quickSort(lst, low, pivotIndex - 1);
    lst = quickSort(lst, pivotIndex + 1, high);
    return lst;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    // set the low and high indices, then call the recursive quickSort function
    int lowIndex = 0;
    int highIndex = lst.size() - 1;
    return quickSort(lst, lowIndex, highIndex);
}
