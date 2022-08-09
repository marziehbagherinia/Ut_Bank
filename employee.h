#ifndef Employee_H
#define Employee_H
#include<stdlib.h>
#include <string.h>

#define MAXLEN 128
#define PASSLEN 6
#define PROFIT 0.18
#define SIXDIGITT 899999
#define FIRST6DIGIT 100000
#define ever (;;)
#define LEASTCREDIT -10000

typedef char name[MAXLEN];
typedef char username[MAXLEN];
typedef char phoneNumber[12];
typedef char familyName[MAXLEN];
typedef char password[PASSLEN];
typedef long int accountNumber;

struct Employee
{
    username username;
    password password;
    phoneNumber phoneNumber;
};
typedef struct Employee Employee;
Employee* initEmployee(username u, password p, phoneNumber pn);

#endif