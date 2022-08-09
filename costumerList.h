#ifndef CustomerList_H
#define CustomerList_H
#include "costumer.h"
#include <string.h>

struct NodeCustomer {
    Customer* customer;
    struct NodeCustomer* next;
};

typedef struct NodeCustomer* CustomerList;
typedef struct NodeCustomer* CustomerNode;
CustomerList createCustomerList();
void addCustomerNodeToList(struct NodeCustomer* list, Customer* Customer);
void printCustomerList(CustomerList list);
void deleteCustomerbyUsername(CustomerList *list, username _username);
CustomerNode findCustomerbyUsername(CustomerList list, username username);
void transferCash(CustomerList firstUser ,CustomerList secondUser, double quantity);
void changeCredit(CustomerList list, double _quantity, int selection);
void printCredit(Credit credit);
void printTransaction(Transaction transaction);
void printInformation(Customer* customer);


#endif