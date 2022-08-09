#include"system.h"

#define MANAGERNAME "admin"
#define MANAGERPASS "123"
#define MANAGERPHONE "00000000000"

char** result = 0;
int row = 1;
int write;
char* saveInp = NULL;

void initBank(Bank* bank) {

    Employee* manager;
    
    manager = initEmployee(MANAGERNAME, MANAGERPASS, MANAGERPHONE);

    bank->currentCustumer = NULL;
    bank->currentEmployee = manager;
    bank->currentEmployee2 = manager;
    bank->customerList = createCustomerList();
    bank->netWorth = 0;
}

void writeInFile(char* input) {

    FILE* fPtr = fopen("in.txt", "a");

    fputs(input, fPtr);

    fclose(fPtr);
}

void readFile() {

    char* buffer = 0;

    long length;

    int count = 0;
    int index = 0;

    FILE * myFile = fopen ("in.txt", "rb");

    if (myFile)
    {
      fseek (myFile, 0, SEEK_END);

      length = ftell (myFile);
      
      fseek (myFile, 0, SEEK_SET);

      buffer = (char*)malloc(length * sizeof(char)); 

      if (buffer)
        fread (buffer, sizeof(char), length, myFile);

      fclose (myFile);
    }

    if (buffer)
    {
      for (int i = 0; i < strlen(buffer) - 1; ++i)
      {  
        if (*(buffer + i) == '\n')
            row++;
      }
    }

    result = (char **)malloc(row * sizeof(char *));

    while(count != row)
    {
        for (int i = index; i < strlen(buffer) + 1; ++i)
        {
            if (buffer[i] == '\n')
            {

                result[count] = (char *)malloc((i - index) * sizeof(char));
                

                for (int j = 0; j < i - index; ++j)
                    result[count][j] = buffer[j + index];

                for (int j = i - index; j < strlen(result[count]); ++j)
                    result[count][j] = 0;

                index = i + 1;
                count++;
            }
            
        }

    }

}

void saveInf(char* res, Bank* bank) {

    char* cmd = NULL; char* par1 = NULL; char* par2 = NULL;
    char* inp = NULL; char* par3 = NULL; char* par4 = NULL; 

    getCommand(res, &cmd, &par1, &par2, &par3, &par4);

        if(strcmp(cmd, "login") == 0) {
            if(par3 || par4) {
                wrongFormatErr();
            }
            else {

                if (strcmp(par1, MANAGERNAME) == 0) {
                    handleLoginManager(bank);
                }

                else {
                    handleLoginCustomer(bank, par1, par2);
                }
            }
        }

        else if (strcmp(cmd, "add_user") == 0) {
            if (par4)
                wrongFormatErr();
            else {

                handleSignUpCustomer(bank, par1, par2, par3);
            }
        }

        else if (strcmp(cmd, "logout") == 0) {
            if (par1 || par2|| par3 || par4)
                wrongFormatErr();
            else
                handleLogOut(bank);
        }

        else if (strcmp(cmd, "deposit") == 0) {
            if (par3 || par4)
                wrongFormatErr();
            else 
                handleChangeCredit(bank, par1, atof(par2), 0);
        }

        else if (strcmp(cmd, "withdraw") == 0) {
            if (par3 || par4)
                wrongFormatErr();
            else
                handleChangeCredit(bank, par1, (-1*atof(par2)), 1);
        }

        else if (strcmp(cmd, "Delete") == 0) {
            if (par2 || par3 || par4)
                wrongFormatErr();
            else
                handleDelUser(bank, par1);

        }

        else if (strcmp(cmd, "transfer") == 0) {
            if (par3 || par4)
                wrongFormatErr();
            else
                handleTransfer(bank, par1, atof(par2));
        }

}

void reafFromFile(Bank* bank) {

    readFile();

    if (result == NULL) {
        return;
    }

    for (int i = 0; i < row; ++i)
    {
        saveInf(result[i], bank);
    }

}

void startSystem(Bank* bank) {
    char* cmd = NULL; char* par1 = NULL; char* par2 = NULL;
    char* inp = NULL; char* par3 = NULL; char* par4 = NULL;

    for ever {

        inp = (char*)malloc(MAXLEN*sizeof(char)); //allocate memory for save the input 
        
        saveInp = (char*)malloc(MAXLEN*sizeof(char)); //alocate memory for write in file
        
        fgets(inp, MAXLEN, stdin); //get input from user
        
        strcpy(saveInp, inp);

        inp = strtok(inp, "\n"); 

        getCommand(inp, &cmd, &par1, &par2, &par3, &par4); //break input to words

        if (strcmp(cmd, "exit") == 0) //check the first word to decide
        {
            break;
        }
        
        if(strcmp(cmd, "login") == 0) {
            if(par3 || par4) {
                wrongFormatErr();
            }
            else {

                if (strcmp(par1, MANAGERNAME) == 0) {
                    handleLoginManager(bank);
                }

                else {
                    handleLoginCustomer(bank, par1, par2);

                    if (write == 1)
                        writeInFile(saveInp);
                }
            }
        }


        else if (strcmp(cmd, "add_user") == 0) {
            if (par4)
                wrongFormatErr();
            else {

                handleSignUpCustomer(bank, par1, par2, par3);
                if (write == 1)
                        writeInFile(saveInp);
            }
        }

        else if (strcmp(cmd, "logout") == 0) {
            if (par1 || par2|| par3 || par4) {
                wrongFormatErr();
            }
            else {
                handleLogOut(bank);
            
                if (write == 1)
                        writeInFile(saveInp);
            }
        }

        else if (strcmp(cmd, "deposit") == 0) {
            if (par3 || par4) {
                wrongFormatErr();
            }

            else { 
                handleChangeCredit(bank, par1, atof(par2), 0);
                if (write == 1)
                        writeInFile(saveInp);
            }
        }

        else if (strcmp(cmd, "withdraw") == 0) {
            if (par3 || par4) {
                wrongFormatErr();
            }

            else {
                handleChangeCredit(bank, par1, (-1*atof(par2)), 1);
                if (write == 1)
                        writeInFile(saveInp);
            }
        }

        else if (strcmp(cmd, "Delete") == 0) {
            if (par2 || par3 || par4) {
                wrongFormatErr();
            }

            else {
                handleDelUser(bank, par1);
                if (write == 1)
                        writeInFile(saveInp);
            }        
        }

        else if (strcmp(cmd, "transfer") == 0) {
            if (par3 || par4) {
                wrongFormatErr();
            }
            else {
                handleTransfer(bank, par1, atof(par2));
                if (write == 1)
                        writeInFile(saveInp);
            }
        }

        else if (strcmp(cmd, "view") == 0) {
            if (par1) {
                if (par2 || par3 || par4)
                    wrongFormatErr();
                else
                    handleManagerView(bank, par1);
            }

            else {

                if (par2 || par3 || par4)
                    wrongFormatErr();
                else
                    handleUserView(bank);
            }
        }

        else {
            printf("Bad request\n");
        }

    }
}

void handleSignUpCustomer(Bank* bank, username username, password password, phoneNumber phoneNumber) {
    
    if (!bank->currentEmployee) { //handle errors
        if (bank->currentCustumer) {
            write = 0;
            accessDeniedEr();
        }

        else {
            write = 0;
            logInFirstErr();
        }
        return;
    }

    CustomerNode foundCus = findCustomerbyUsername(bank->customerList, username); //find customer with input username
    
    if (foundCus) {
        usernameIsTakenErr();
        write = 0;
        return;
    }

    Customer* newCus = initCustomer(username, password, phoneNumber); //initialize new customer
    
    addCustomerNodeToList(bank->customerList, newCus);

    write = 1;

}

void handleLoginCustomer(Bank* bank, username username, password password) {
    if (bank->currentEmployee2 || bank->currentCustumer) {
        logOutFirstErr();
        write = 0;
        return;
    }

    CustomerNode foundCust = findCustomerbyUsername(bank->customerList, username);
    
    if (!foundCust) {
        notMatchUsernameErr();
        write = 0;
        return;
    }

    if (strcmp(password, foundCust->customer->password) != 0) {
        wrongPasswordErr();
        write = 0;
        return;
    }

    bank->currentCustumer = foundCust->customer; //change current Customer
    write = 1;
}

void handleLoginManager(Bank* bank) {

    if (bank->currentEmployee2 || bank->currentCustumer) {
        logOutFirstErr();
        write = 0;
        return;
    }

    bank->currentEmployee2 = bank->currentEmployee; //set manager login
    write = 1;
}

void handleLogOut(Bank* bank) {
    if (!bank->currentEmployee2 && !bank->currentCustumer) {
        noUserIn();
        write = 0;
        return;
    }

    else {
        bank->currentCustumer = NULL;
        bank->currentEmployee2 = NULL; //logout all user
    }

    write = 1;
}

void handleDelUser(Bank* bank, username username) {

    if (!bank->currentEmployee2 || bank->currentCustumer) {
        printf("bad Request\n");
        write = 0;
        return;
    }

    CustomerNode foundCust = findCustomerbyUsername(bank->customerList, username);
    
    if (!foundCust) {
        notMatchUsernameErr();
        write = 0;
        return;
    }

    deleteCustomerbyUsername(&(bank->customerList), username); //delete user
    write = 1;
}

void handleChangeCredit(Bank* bank, username username, double quantity, int selection) {

    if (!bank->currentEmployee2) {
        accessDeniedEr();
        write = 0;
        return;
    }

    CustomerNode foundCust = findCustomerbyUsername(bank->customerList, username);
    
    if (!foundCust) {
        notMatchUsernameErr();
        write = 0;
        return;
    }

    changeCredit(foundCust, quantity, selection); //change found user credit
    write = 1;
}

void handleTransfer(Bank* bank, username user, double quantity) {

    if (bank->currentEmployee2 || !bank->currentCustumer) {
        printf("bad Request\n");
        write = 0;
        return;
    }

    CustomerNode firstUser = findCustomerbyUsername(bank->customerList, bank->currentCustumer->username);
    CustomerNode secondUser = findCustomerbyUsername(bank->customerList, user);

    if (!firstUser || !secondUser) {
        notMatchUsernameErr();
        write = 0;
        return;
    }

    transferCash(firstUser, secondUser, quantity); //add transaction for both user
    write = 1;
}

void handleManagerView(Bank* bank, username userName) {
    
    if (!bank->currentEmployee2 || bank->currentCustumer) {
        accessDeniedEr();
        write = 0;
        return;
    }

    CustomerNode foundCust = findCustomerbyUsername(bank->customerList, userName);
    
    if (!foundCust) {
        notMatchUsernameErr();
        write = 0;
        return;
    }

    printInformation(foundCust->customer); //print all information about user
    write = 1;
}

void handleUserView(Bank* bank) {

    if (bank->currentEmployee2 || !bank->currentCustumer) {
        accessDeniedEr();
        write = 0;
        return;
    }

    printInformation(bank->currentCustumer); //print all information about user
    write = 1;
}
