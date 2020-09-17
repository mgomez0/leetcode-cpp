//Given an integer array nums, find the contiguous subarray within an array
// (containing at least one number) which has the largest product.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }

        queue<int> q;
        q.push(nums.front());
        int i = 0;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(nums[i++])
        }

    }
};