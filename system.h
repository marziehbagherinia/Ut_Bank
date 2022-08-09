#ifndef System_H
#define System_H

#include <stdlib.h>
#include"costumerList.h"
#include"employeeList.h"
#include"tools.h"

struct System
{ 
    CustomerList customerList;
    EmployeeList employeeList;
    double netWorth;
    Employee* currentEmployee;
    Employee* currentEmployee2;
    Customer* currentCustumer;
};

typedef struct System Bank;

void initBank(Bank* Bank);
void startSystem(Bank* bank);
void handleLoginManager(Bank* bank);
void handleSignUpCustomer(Bank* bank, username username, password password, phoneNumber phoneNumber);
void handleLoginCustomer(Bank* bank, username username, password password);
void handleLogOut(Bank* bank);
void handleChangeCredit(Bank* bank, username username, double quantity, int selection);
void handleDelUser(Bank* bank, username username);
void handleTransfer(Bank* bank, username user, double quantity);
void handleManagerView(Bank* bank, username userName);
void handleUserView(Bank* bank);
void writeInFile(char* input);
void readFile();
void reafFromFile(Bank* bank);
void saveInf(char* res, Bank* bank);

#endif