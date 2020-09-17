
/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_ctr = 0;
        int original_size = nums.size();
        for (int i = 0; i < original_size; i++){
            if(nums[i] == 0){
                zero_ctr++;
            }
        }
        while(zero_ctr != 0){
            nums.push_back(0);
            zero_ctr--;
        }

        for(int i = 0; i < original_size; i++){
            if(nums[i] == 0){
                nums.erase(nums.begin()+i);
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> test = {0,0,1};
    sol.moveZeroes(test);
}