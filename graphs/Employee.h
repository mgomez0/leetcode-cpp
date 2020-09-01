#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<vector>
class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

#endif