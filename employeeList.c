#include "employeeList.h"

EmployeeNode createEmployeeList() {
    EmployeeList newEmpList;
    newEmpList = (EmployeeList)malloc(sizeof(EmployeeList));
    newEmpList->Employee = NULL;
    newEmpList->next = NULL;
    return newEmpList;
}
