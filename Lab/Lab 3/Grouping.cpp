/*
 * Name: Graysin Whitaker
 * Date Submitted: 2/13/2023
 * Lab Section: 002
 * Assignment Name: Lab 3: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// parameterized constructor to read in a file to a grid and find groups
Grouping::Grouping(string filename){
    // open file
    ifstream readFile(filename);
    // read file into grid as 0 for "." and 1 for "X"
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            char c;
            readFile >> c;
            if(c == 'X'){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
    // close file
    readFile.close();
    // loop through grid and call findGroup on each filled square
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(grid[i][j] == 1){
                // add new group to groups
                groups.push_back(vector<GridSquare>());
                findGroup(i, j);
            }
        }
    }
}

// function to group a filled sqauare and all adjacent filled squares, recursively
void Grouping::findGroup(int r, int c){
    // add square to group
    groups[groups.size()-1].push_back(GridSquare(r, c));
    // mark square as part of group
    grid[r][c] = 2;
    // check above
    if(r > 0 && grid[r-1][c] == 1){
        findGroup(r-1, c);
    }
    // check below
    if(r < 9 && grid[r+1][c] == 1){
        findGroup(r+1, c);
    }
    // check left
    if(c > 0 && grid[r][c-1] == 1){
        findGroup(r, c-1);
    }
    // check right
    if(c < 9 && grid[r][c+1] == 1){
        findGroup(r, c+1);
    }
}

//Simple main function to test Grouping
//Be sure to comment out main() before submitting
// int main()
// {
//     Grouping input1("input3.txt");
//     input1.printGroups();
    
//     return 0;
// }

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}