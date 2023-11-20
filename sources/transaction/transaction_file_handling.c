#include "../../headers/transaction/transaction_file_handling.h"
#include "../../headers/user/user_management.h"

void saveTransactionDataToFileHelper(FILE* output) {
    struct userNode* current = usersHead;
    while(current != NULL) {
        int count = 0;
        for(int i = 0; i < 5; i++) {
            if(current->user.transaction[i].borrowed==1) count++;
        }
        fprintf(output, "%d %d\n", current->user.serialNumber, count);
        for(int i = 0; i < 5; i++) {
            if(current->user.transaction[i].borrowed==0) continue;
            fprintf(output, "%s|%d|%d\n", current->user.transaction[i].ISBN,
                current->user.transaction[i].startDate, current->user.transaction[i].endDate);
        }
        current = current->next;
    }
}

void loadTransactionDataFromFileHelper(FILE* input, int numberOfLines) {
    int lines = 1;
    while(lines <= numberOfLines) {
        int count, serialNumber;
        fscanf(input, "%d %d\n", &serialNumber, &count);
        struct userNode* current = searchUser(serialNumber);
        if(count==0) lines++;
        for(int i = 1; i <= count; i++) {
            fscanf(input, " %[^|]|%d|%d\n", current->user.transaction[i].ISBN,
                &current->user.transaction[i].startDate, &current->user.transaction[i].endDate);
            current->user.transaction[i].borrowed = 1;
            lines++;
        }
    }
}
