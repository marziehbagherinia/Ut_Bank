#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* getCommand(char* str, char** cmd, char** par1, char** par2, char** par3, char** par4);
int isSameString(char* first, char* second);
void wrongFormatErr();
void logOutFirstErr();
void notMatchUsernameErr();
void wrongPasswordErr();
void accessDeniedEr();
void logInFirstErr();
void usernameIsTakenErr();
void leastCreditEr();
void neqQuantityErr();
void noUserIn();