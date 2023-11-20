#ifndef TRANSACTION_H
#define TRANSACTION_H

struct Transaction {
    char ISBN[13];
    int startDate;
    int endDate;
    int borrowed;
};

void displayTransaction(const int serialNumber);

#endif //TRANSACTION_H
