#include "../../headers/transaction/transaction.h"
#include "../../headers/user/user_management.h"
#include <stdio.h>

void displayTransaction(const int serialNumber) {
    struct userNode* node = searchUser(serialNumber);
    printf("Transaction Details For User: %d\n", serialNumber);
    for(int i = 0; i < 5; i++) {
        struct Transaction current = node->user.transaction[i];
        if(current.borrowed==1) {
            printf("ISBN: %s\n", current.ISBN);
            printf("Borrowed On: %d\n", current.startDate);
            printf("Due Date: %d\n\n", current.endDate);
        }
    }
}
