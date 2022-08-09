#include"costumer.h"

int userId = 0;

Credit initCredit() {
    Credit newCredit = (Credit)malloc(sizeof(Credit));
    newCredit->next = NULL;
    newCredit->quantity = 0;
    newCredit->transaction = NULL;
    return newCredit;
}

Customer* initCustomer(username u, password p, phoneNumber pn) {
    Customer* newCust = (Customer*)malloc(sizeof(Customer));
    strcpy(newCust->username, u);
    strcpy(newCust->password, p);
    strcpy(newCust->phoneNumber, pn);
    newCust->credit = initCredit();
    newCust->cash = 0;
    newCust->id = userId;
    userId++;
    return newCust;
}