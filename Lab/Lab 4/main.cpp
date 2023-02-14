#include <iostream>
#include "Sorts.h"

using namespace std;

int main(){
    vector<int> vect = {22,14,8,6,10,2,12,16};
    
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;

    vector<int> sortVect = quickSort(vect);

    for(int i = 0; i < sortVect.size(); i++){
        cout << sortVect[i] << " ";
    }
    cout << endl;
}
