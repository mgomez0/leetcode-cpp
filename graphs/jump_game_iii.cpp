// Given an array of non-negative integers arr, 
// you are initially positioned at start index of the array. 
// When you are at index i, you can jump to i + arr[i] or i - arr[i], 
// check if you can reach to any index with value 0.

// Notice that you can not jump outside of the array at any time.

 

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        int size = arr.size();
        bool visited[size] = {false};
        queue<int> elems;     
        int front;

        elems.push(start);
        while(!elems.empty()){
            front = elems.front();    
            if (arr[front] == 0)
            {
                return true;
            }
            if(visited[front] == true)
            {
                continue;
            }

            if (front + arr[front] < size){
                elems.push(front + arr[front]);
            }

            if(front - arr[front] >= 0){
                elems.push(front - arr[front]);
            }

            visited[front] = true;

        }

        return false;

    }

};