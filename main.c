#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"system.h"

#define MAXLEN 128

int main () {

    srand(time(0));
    rand();
    
    Bank* bank;
    bank = (Bank*)malloc(sizeof(Bank));
    initBank(bank); //initialize a bank
    reafFromFile(bank);
    startSystem(bank); // manage all command
    free(bank);

    return 0;
}