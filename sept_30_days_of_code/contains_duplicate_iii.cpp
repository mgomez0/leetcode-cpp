using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int,int> mp; //value -> index
        int size = nums.size();
        int i = 0;
        for(auto elem : nums){
            mp[elem] = i;
            i++;
        }

        i = 0;
        int j = size - 1;

        while(i < j){
            if(abs(mp[i] - mp[j]) <= k && abs(i-j) <= t){
                return true;
            }

            else if(abs(mp[i] - mp[j]) > k && abs(i-j) > t){
                j--;
            }
        }

        return false;
    }
 
};


int main(){
    vector<int> nums = {1,2,3,1};
    int k = 3;
    int t = 0;

    Solution sol;
    sol.containsNearbyAlmostDuplicate(nums, k, t);
}