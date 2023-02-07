/*
 * Name: Grayson Whitaker
 * Date Submitted: 2/14/2023
 * Section: 003
 * Assignment Name: Queue Implementation Using a Circular Array
 */

#include "IntegerArrayQueue.h"

// function to enqueue a value into the queue, returns:
//      true: the value was successfully enqueued
//      false: the queue is full
bool IntegerArrayQueue::enqueue(int value){
    // if the queue is full (back is two positions before front), return false
    if (front - back == 2 || (back == size - 1 && front == 1) || (back == size - 2 && front == 0)) return false;
    else{
        // add the value to the back of the queue and increment the back index by one (or wrap around to the front of the array)
        back = (back + 1) % size;
        array[back] = value;
        return true;
    }
}

// function to dequeue a value from the queue, returns:
//      0: the queue is empty
//      otherwise: the value at the front of the queue
int IntegerArrayQueue::dequeue(){
    // if the queue is empty (back is one position before front), return 0
    if (front - back == 1 || (back == size - 1 && front == 0)) return 0;
    else{
        // return the value at the front of the queue and increment the front index by one (or wrap around to the front of the array)
        int returnValue = array[front];
        front = (front + 1) % size;
        return returnValue;
    }
}