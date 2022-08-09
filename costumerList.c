#include"costumerList.h"

CustomerList createCustomerList() {
    CustomerList newCustList;
    newCustList = (CustomerList)malloc(sizeof(CustomerList));
    newCustList->customer = NULL;
    newCustList->next = NULL;
    return newCustList;
}

void addCustomerNodeToList(struct NodeCustomer* list, Customer* customer) {
  
    if (list != NULL)
     {
        if (list->customer == NULL) {

            list->customer = customer;
        }
    
        else {
            CustomerNode curr = list;
            
            while (curr->next != NULL) {
                curr = curr->next;
            }

            curr->next = (CustomerNode)malloc(sizeof(CustomerNode));
            curr->next->customer = customer;
            curr->next->next = NULL;
        } 
     }
}

void printCustomerList(CustomerList list) {
    if (list == NULL)
        return;
    printf("Username: %s\n", list->customer->username);
    printCustomerList(list->next);
}

void deleteCustomerbyUsername(CustomerList *list, username _username) {

    CustomerList temp = *list, prev; 
   
    if (temp != NULL && strcmp(temp->customer->username, _username) == 0) 
    { 
        *list = temp->next;   
        free(temp->customer->credit->transaction);
        free(temp->customer->credit);
        free(temp->customer); 
        free(temp);             
        return; 
    } 

    while (temp != NULL && strcmp(temp->customer->username, _username) != 0) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 

    if (temp == NULL) {
        return; 
    }
  
    prev->next = temp->next; 

    free(temp->customer->credit->transaction);
    free(temp->customer->credit);
    free(temp->customer); 
    free(temp);
}

CustomerNode findCustomerbyUsername(CustomerList list, username username) {
   
    CustomerNode curr = list;

    if (curr != NULL && curr->customer != NULL)
    {
       while (curr != NULL) {

            if (strcmp(curr->customer->username, username) == 0)
                return curr;

            curr = curr->next;
        }
    }
    
    return NULL;
}

void changeCredit(CustomerList list, double _quantity, int selection) {
    if (list == NULL || list->customer == NULL)
        return;

    Credit newCredit = (Credit) malloc(sizeof(Credit));
    newCredit->quantity = _quantity;
    newCredit->next = NULL;
    
    Credit lastCredit;

    if (list->customer->credit != NULL) {
        lastCredit = list->customer->credit;
    }

    else {
        printf("There is no credit\n");
        return;
    }

    if (lastCredit != NULL)
    {
        while(lastCredit->next != NULL) {
            lastCredit = lastCredit->next;
        }

        if (selection == 1)
        {
            if ((-1*(_quantity)) <= list->customer->cash) {
                list->customer->cash += _quantity;
                lastCredit->next = newCredit;
            }

            else {
                printf("Not enough inventory\n");
            }
        }

        else if (selection == 0) {
            list->customer->cash += _quantity;
            lastCredit->next = newCredit;
        }
    }

}

void printCredit(Credit credit) {
    if (credit == NULL)
        return;
    
    if (credit->quantity > 0)
    {
        printf("deposit: %f\n", credit->quantity);
    }

    else if (credit->quantity < 0)
    {
        printf("withDraw: %f\n", credit->quantity);
    }

    printCredit(credit->next);
}

void transferCash(CustomerList firstUser ,CustomerList secondUser, double quantity) {

    if (quantity > firstUser->customer->cash)
    {
        printf("Not enough inventory\n");
        return;
    }
    
    firstUser->customer->cash -= quantity;
    secondUser->customer->cash += quantity;

    Transaction lastTran1 = firstUser->customer->credit->transaction;
    Transaction lastTran2 = secondUser->customer->credit->transaction;

    Transaction newfirstTran = (Transaction)malloc(sizeof(Transaction));
    strcpy(newfirstTran->tranName, secondUser->customer->username);
    newfirstTran->transferValue = quantity;
    newfirstTran->sendOrRecieve = 0;
    newfirstTran->next = NULL;

    Transaction newsecondTran = (Transaction)malloc(sizeof(Transaction));
    strcpy(newsecondTran->tranName, firstUser->customer->username);
    newsecondTran->transferValue = quantity;
    newsecondTran->sendOrRecieve = 1;
    newsecondTran->next = NULL;

    if (lastTran1 == NULL) {
        lastTran1 = newfirstTran;
        firstUser->customer->credit->transaction = newfirstTran;
    }

    else {

        while (lastTran1->next != NULL) {
            lastTran1 = lastTran1->next;
        }

        lastTran1->next = newfirstTran;
    }

    if (lastTran2 == NULL) {
        lastTran2 = newsecondTran;
        secondUser->customer->credit->transaction = newsecondTran;
    }

    else {

        while (lastTran2->next != NULL) {
            lastTran2 = lastTran2->next;
        }

        lastTran2->next = newsecondTran;
    }

}

void printTransaction(Transaction transaction) {

    if (transaction == NULL)
        return;
    
    if (transaction->sendOrRecieve == 0) {

        printf("Transfer to %s\n", transaction->tranName);
    }

    else if(transaction->sendOrRecieve == 1) {

        printf("Transfer from %s\n", transaction->tranName);
    }

    printf("Value of transaction: %f\n", transaction->transferValue);

    printTransaction(transaction->next);
}

void printInformation(Customer* customer) {

    if (customer == NULL) {
        printf("no customer\n");
    }
    else {

        printf("Id: %d\n", customer->id);
        printf("Username: %s\n", customer->username);
        printf("PhoneNumber: %s\n", customer->phoneNumber);
        printf("Cash: %f\n", customer->cash);
        printCredit(customer->credit);
        printTransaction(customer->credit->transaction);
    }
}
