// You are given a data structure of employee information, which
// includes the employee's unique id, their importance value and their
// direct subordinates' id.
// For example, employee 1 is the leader of employee 2, and employee 2 is the leader of
// employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a
// data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], 
// and employee 3 has [3, 5, []]. 
// Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.
// Now given the employee information of a company, and an employee id, you need to return
//  the total importance value of this employee and all their subordinates.
// Runtime: 60 ms, faster than 37.92% of C++ online submissions for Employee Importance.
// Memory Usage: 23.3 MB, less than 13.57% of C++ online submissions for Employee Importance.

#include "Employee.h"
#include <vector>

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int total;
    void helper(std::vector<Employee*> employees, int id){
        for(auto const& i : employees){
            if (i->id == id){
                total += i->importance;
                if(i->subordinates.empty())
                return;
                else{
                    for(auto j: i->subordinates){
                    helper(employees, j);
                    }
                } 
            }
        }
    };

    int getImportance(std::vector<Employee*> employees, int id) {
       helper(employees,id);
       return total;
    }
};


int main(){
    std::vector<int> subordinates_one = {2};
    std::vector<int> subordinates_two = {};
    Employee one = {1,2, subordinates_one};
    Employee two = {2,3,subordinates_two};
    Solution sol;
    std::vector<Employee*> employees;
    employees.push_back(&one);
    employees.push_back(&two);
    sol.helper(employees, 2);
}