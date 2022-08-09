#include"tools.h"
char* getCommand(char* str, char** cmd, char** par1, char** par2, char** par3, char** par4) {
    char delim[] = " ";
	char *ptr = strtok(str, delim);
    char *remainder;
    *cmd = ptr;
    *par1 = strtok(NULL, delim);
    *par2 = strtok(NULL, delim);
    *par3 = strtok(NULL, delim);
    *par4 = strtok(NULL, delim);
    remainder = strtok(NULL, delim);

    return remainder;
}

int isSameString(char *first, char *second) {
    while(*first == *second) {
        if(first == NULL || second == NULL)
            break; 
        first++;
        second++;
    }
    if(first == NULL && second == NULL)
        return 1;
    else
        return 0;
}

void wrongFormatErr() {
    printf("Wrong Format For Input!\n");
}

void logOutFirstErr() {
    printf("The line is busy\n");
}

void notMatchUsernameErr() {
    printf("There is no customer with this name\n");
}

void wrongPasswordErr() {
    printf("Wrong password\n");
}

void accessDeniedEr() {

    printf("Permission Denied\n");
}

void logInFirstErr() {
    printf("Manager is not online\n");
}

void usernameIsTakenErr() {
    printf("There is another customer with this username\n");
}

void leastCreditEr() {

}

void noUserIn() {
    printf("No useer is online\n");
}