#include <iostream>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        for(int j = nums.size() - i; j > 0; j--){
            if(nums[i] == nums[j] && i != j) return true;
        }
    }
    return false;
}

int main(){
    vector<int> myVect = {1, 2, 3, 4, 1};
    cout << containsDuplicate(myVect);
}