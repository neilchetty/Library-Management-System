#ifndef TRANSACTION_FILE_HANDLING_H
#define TRANSACTION_FILE_HANDLING_H

#include <stdio.h>

void saveTransactionDataToFileHelper(FILE* output);
void loadTransactionDataFromFileHelper(FILE* input, int numberOfLines);

#endif //TRANSACTION_FILE_HANDLING_H
