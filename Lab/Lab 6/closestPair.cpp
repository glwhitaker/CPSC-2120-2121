/*
	* Name: Grayson Whitaker
	* Date Submitted: 3/13/2023
	* Lab Section: 002
	* Assignment Name: Lab 6: Finding the Closest Pair of Points
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

// returns the minimum distance between the point p and the points in the cell without comparing the point to itself or to points already compared
double checkMinimum(const int k, const vector<point> currentCell, const vector<point> compareCell, double minimum){
	for(int i = 0; i < compareCell.size(); i++){
		// if in the current compareCell, do not compare point to itself, do not compare two points more than once
		if(currentCell[i].x == compareCell[i].x && currentCell[i].y == compareCell[i].y && i >= k){
			break;
		}
		// calculate the distance between the point and the current point in the compareCell
		double distance = sqrt(pow(currentCell[k].x - compareCell[i].x, 2) + pow(currentCell[k].y - compareCell[i].y, 2));
		// if the distance is less than the minimum, set the minimum to the distance
		if(distance < minimum){
			minimum = distance;
		}
	}
	// return the minimum distance
	return minimum;
}

/*
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Uses "spatial hashing" where the #of cells scales with the #of points
  and finds the distance between the closest pair of points returned
  as a double type value
*/
double closestPair(string filename){
	// Open the file and read in the number of points\
	// return 0 if the file cannot be opened
	ifstream inputFile(filename);
	if(!inputFile){
		return 0;
	}
	int numPoints;
	inputFile >> numPoints;

	// create 2D vector of cells to hold the points using b to scale size
	// b = sqrt(numPoints) because the number of cells should scale with the number of points
	int b = sqrt(numPoints);
	vector<vector<vector<point>>> cellTable(b, vector<vector<point>>(b));

	// Read in the points and put them in the cell table
	for(int i = 0; i < numPoints; i++){
		point p;
		inputFile >> p.y >> p.x;
		cellTable[(int)(p.y * b)][(int)(p.x * b)].push_back(p);
	}

	// close the file
	inputFile.close();

	// set the minimum to the maximum possible distance
	double minimum = sqrt(2);
	// iterate through the cells in the cell table
	for(int i = 0; i < b; i++){
		for(int j = 0; j < b; j++){
			// get the current cell
			vector<point> currentCell = cellTable[i][j];
			// iterate through the points in the current cell
			for(int k = 0; k < currentCell.size(); k++){
				// check the needed cells, do not need to compare to previous surrounding cells
				// current cell
				minimum = checkMinimum(k, currentCell, currentCell, minimum);
				// right cell
				if(j + 1 < b){
					minimum = checkMinimum(k, currentCell, cellTable[i][j + 1], minimum);
				}
				// bottom cell
				if(i + 1 < b){
					minimum = checkMinimum(k, currentCell, cellTable[i + 1][j], minimum);
				}
				// bottom right cell
				if(i + 1 < b && j + 1 < b){
					minimum = checkMinimum(k, currentCell, cellTable[i + 1][j + 1], minimum);
				}
				// bottom left cell
				if(i + 1 < b && j - 1 >= 0){
					minimum = checkMinimum(k, currentCell, cellTable[i + 1][j - 1], minimum);
				}
			}
		}
	}
	// return the minimum distance between two points
	return minimum;
}

int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}