#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        char* begin = &s.front();
        char* end = &s.back();
        char temp;
        int ctr = s.size()/2;
        while(ctr>0)
        {
            temp = *begin;
            *begin = *end;
            *end = temp;
            begin++;
            end--;
            ctr--;
        }
        
    }
};

int main(){
    Solution sol;
    vector<char> test = {'h','e','l','l','o'};
    sol.reverseString(test);
}