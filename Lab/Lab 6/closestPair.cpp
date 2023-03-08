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
	// Open the file and read in the number of points
	ifstream inputFile(filename);
	int numPoints;
	inputFile >> numPoints;

	// create 2D vector of cells to hold the points using b to scale size
	// b = sqrt(numPoints) because the number of cells should scale with the number of points
	int b = sqrt(numPoints);
	vector<vector<vector<point>>> cellTable(b, vector<vector<point>>(b));

	// Read in the points and put them in the cell table
	for(int i = 0; i < numPoints; i++){
		point p;
		inputFile >> p.x >> p.y;
		cellTable[(int)(p.x * b)][(int)(p.y * b)].push_back(p);
	}

	// close the file
	inputFile.close();

	// Find the distance between closest pair of points as a double value
	double minimum = 1.0;
	// iterate through the cells in the cell table
	for(int i = 0; i < b; i++){
		for(int j = 0; j < b; j++){
			// get the current cell
			vector<point> currentCell = cellTable[i][j];
			// iterate through the points in the current cell
			for(int k = 0; k < currentCell.size(); k++){
				// iterate through current cell, cell to the right, cell below, and cell to the right and below
				for(int l = 0; l <= 1; l++){
					for(int m = 0; m <= 1; m++){
						// check if the compare cell is in the cell table
						if(i + l < b && j + m < b){
							// get the compare cell
							vector<point> compareCell = cellTable[i + l][j + m];
							// iterate through the points in the compare cell
							for(int n = 0; n < compareCell.size(); n++){
								// if in the same cell, do not compare two points more than once, do not compare point to itself
								if(l == 0 && m == 0 && n >= k){
									break;
								}
								// calculate the distance between the points
								double distance = sqrt(pow(currentCell[k].x - compareCell[n].x, 2) + pow(currentCell[k].y - compareCell[n].y, 2));
								// if the distance is less than the minimum, set the minimum to the distance
								if(distance < minimum){
									minimum = distance;
								}
							}
						}
					}
				}
			}
		}
	}
	
	// return the minimum distance
	return minimum;
}

// int main()
// {
//     double min;
//     string filename;
//     cout << "File with list of points within unit square: ";
//     cin >> filename;
//     min = closestPair(filename);
//     cout << setprecision(16);
//     cout << "Distance between closest pair of points: " << min << endl;
//     return 0;
// }