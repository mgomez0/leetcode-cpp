#include "ListNode.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next){
           return head;
       }

       ListNode* reversed_list_head = reverseList(head->next);
       head->next->next = head;
       head->next = nullptr;
       return reversed_list_head;
       
    }
};