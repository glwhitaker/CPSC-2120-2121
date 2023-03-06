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
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
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

	// Find the distance between closest pair of points as a double value, check 8 cells around the cell the point is in
	double minimum = 1.0;
	// iterate through the cells in the cell table
	for(int i = 0; i < b; i++){
		for(int j = 0; j < b; j++){
			// get the current cell
			vector<point> currentCell = cellTable[i][j];
			// iterate through the points in the cell
			for(int k = 0; k < currentCell.size(); k++){
				// iterate through the cells around the cell the point is in
				for(int l = -1; l <= 1; l++){
					for(int m = -1; m <= 1; m++){
						// check if the cell is in the cell table
						if(i + l >= 0 && i + l < b && j + m >= 0 && j + m < b){
							// iterate through the points in the cell
							for(int n = 0; n < cellTable[i + l][j + m].size(); n++){
								// if the points are not the same point
								if(currentCell[k].x != cellTable[i + l][j + m][n].x || currentCell[k].y != cellTable[i + l][j + m][n].y){
									// calculate the distance between the points
									double distance = sqrt(pow(currentCell[k].x - cellTable[i + l][j + m][n].x, 2) + pow(currentCell[k].y - cellTable[i + l][j + m][n].y, 2));
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
	}

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