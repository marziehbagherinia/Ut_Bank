#ifndef EmployeeList_H
#define EmployeeList_H
#include "employee.h"
#include <string.h>
struct NodeEmployee
{
    Employee* Employee;
    struct NodeEmployee* next;
};

typedef struct NodeEmployee* EmployeeList;
typedef struct NodeEmployee* EmployeeNode;
EmployeeNode createEmployeeNode();

#endif