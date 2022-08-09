#ifndef Customer_H
#define Customer_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "tools.h"

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

struct Transaction
{
	username tranName;
	double transferValue;
	int sendOrRecieve; //send0 recieve1
	struct Transaction* next;
};

typedef struct Transaction* Transaction;

struct Credit
{
	double quantity;
	struct Credit* next;
	Transaction transaction;
};

typedef struct Credit* Credit;


struct Customer
{
    name name;
    familyName familyName;
    username username;
    password password;
    phoneNumber phoneNumber;
    Credit credit;
    double cash;
    int id;
    accountNumber accountNumber;


};

typedef struct Customer Customer;

Credit initCredit();
Customer* initCustomer(username u, password p, phoneNumber pn);

#endif