/*
 * Name: Grayson Whitaker
 * Date Submitted: 3/6/2023
 * Lab Section: 002
 * Assignment Name: Lab 5: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

// Inserts word into the stringset if it is not already there, doubles size of stringset if num_elems == size (rehash values)
void Stringset::insert(string word){
    hash<string> stringHash;
    // if num_elems == size, double size of stringset
    if(num_elems == size){
        // double size
        size *= 2;
        // create new table
        vector<list<string>> newTable(size);
        // increment through old table
        for(int i = 0; i < size / 2; i++){
            // increment through list at index i
            for(auto it = table[i].begin(); it != table[i].end(); it++){
                // get new hash index
                int index = stringHash(*it) % size;
                // insert word at hash index in new table
                newTable[index].push_back(*it);
            }
        }
        // deallocate old table
        vector<list<string>>().swap(table);
        // set table to new table
        table = newTable;
    }
    // get hash index
    int index = stringHash(word) % size;
    // if word is not in the stringset, insert it at the hash index
    if(!find(word)){
        table[index].push_back(word);
        // increment number of elements
        num_elems++;
    }
}

// Returns true if word is in the stringset, false otherwise
bool Stringset::find(string word) const{
    hash<string> stringHash;
    // get hash index
    int index = stringHash(word) % size;
    // increment through list at hash index, if word is found return true
    for(auto it = table[index].begin(); it != table[index].end(); it++){
        if(*it == word){
            return true;
        }
    }
    return false;
}

// Removes word from the stringset if it is there
void Stringset::remove(string word){
    hash<string> stringHash;
    // get hash index
    int index = stringHash(word) % size;
    // increment through list at hash index, if word is found remove it
    for(auto it = table[index].begin(); it != table[index].end(); it++){
        if(*it == word){
            table[index].erase(it);
            // decrement number of elements
            num_elems--;
            break;
        }
    }
}