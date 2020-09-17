/*
Runtime: 112 ms, faster than 5.69% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 13.7 MB, less than 98.00% of C++ online submissions for Top K Frequent Elements.
*/


using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ret;
        int max = 0;
        for(auto i: nums){
            mp[i] += 1;
        }
        
        map<int, int>:: iterator it;
        int to_erase;
        while(k > 0){
            max = -1;
            for(it = mp.begin(); it != mp.end(); ++it){
                if(it->second > max){
                     max = it->second;
                     to_erase = it->first;
                }
            }
            
            mp.erase(to_erase);
            ret.push_back(to_erase);
            k--;
        }
        return ret;
    }
};