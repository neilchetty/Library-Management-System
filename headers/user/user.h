#ifndef USER_H
#define USER_H

#include "../transaction/transaction.h"

struct User {
    int serialNumber;
    char name[100];
    int isPriviliged;
    struct Transaction transaction[5];
};

void displayUser(struct User user);

#endif //USER_H
