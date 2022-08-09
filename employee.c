#include "employee.h"

Employee* initEmployee(username u, password p, phoneNumber pn) {
    Employee* newEmp = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmp->username, u);
    strcpy(newEmp->password, p);
    strcpy(newEmp->phoneNumber, pn);
    return newEmp;
}
