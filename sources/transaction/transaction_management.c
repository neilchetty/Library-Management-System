#include "../../headers/transaction/transaction_management.h"
#include "../../headers/user/user_management.h"
#include <stdio.h>
#include <string.h>

void addTransaction(const int serialNumber, char* ISBN, int startDate, int endDate) {
    struct userNode* current = searchUser(serialNumber);
    for(int i = 0; i < 5; i++) {
        if(i==4 && current->user.transaction[i].borrowed==1) {
            perror("User has already borrowed maxium amount of books \n");
            return;
        }
        if(!current->user.transaction[i].borrowed) {
            strcpy(current->user.transaction[i].ISBN, ISBN);
            current->user.transaction[i].startDate = startDate;
            current->user.transaction[i].endDate = endDate;
            current->user.transaction[i].borrowed = 1;
            return;
        }
    }
}

void removeTransaction(const int serialNumber, char* ISBN) {
    struct userNode* current = searchUser(serialNumber);
    for(int i = 0; i < 5; i++) {
        if(current->user.transaction[i].borrowed &&
            !strcmp(current->user.transaction[i].ISBN, ISBN)) {
            current->user.transaction[i].borrowed = 0;
            return;
        }
    }
    perror("Transaction not found for removal\n");
}
