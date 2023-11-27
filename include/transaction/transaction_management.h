#ifndef TRANSACTION_MANAGEMENT_H
#define TRANSACTION_MANAGEMENT_H

#include "transaction.h"

void addTransaction(const int serialNumber, char* ISBN, int startDate, int endDate);
void removeTransaction(const int serialNumber, char* ISBN);

#endif //TRANSACTION_MANAGEMENT_H
