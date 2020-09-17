#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        bool flag = false;
        int sum = 0;
        for(auto i = s.begin(); i != s.end(); ++i){
            if(*i == 'I'){
                sum += 1;
            }
            
            if(*i == 'V'){
                sum += 5;
                if(*(prev(i,1)) == 'I'){
                    sum +=4;
                }
                
            }
            
            if(*i == 'X'){
                sum += 10;
                if(*(prev(i,1)) ==  'I'){
                    sum-=1;;
                } 
            }

            if(*i == 'L'){
                sum += 50;
                if(*(prev(i,1)) ==  'X'){
                    sum-=10;;
                } 
            }

            
            if(*i == 'C'){
                sum += 100;
                if(*(prev(i,1)) ==  'X'){
                    sum-=10;;
                }
            }

            if(*i == 'D'){
                sum += 500;
                if(*(prev(i,1)) ==  'C'){
                    sum-=100;;
                }
            } 

            if(*i == 'M'){
                sum += 1000;
                if(*(prev(i,1)) ==  'C'){
                    sum-=100;;
                }
            } 
            

             
        }
        return sum;
    }
};