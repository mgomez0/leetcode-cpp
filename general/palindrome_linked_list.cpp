/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * 
 *  Runtime: 32 ms, faster than 64.72% of C++ online submissions for Palindrome Linked List.
    Memory Usage: 14.8 MB, less than 36.33% of C++ online submissions for Palindrome Linked List.
 */

#include "ListNode.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        vector<int> vals;
        while(head != nullptr){
            vals.push_back(head->val);
            head = head->next;
        }

        int* ptr_1 = &vals.front();
        int* ptr_2 = &vals.back();
        int ctr = vals.size()/2;
        while(ctr != 0){
            if(*ptr_1 == *ptr_2){
                ptr_1++;
                ptr_2--;
                ctr--;
            } else{
                return false;
            }
        }

        return true; 

    }
};