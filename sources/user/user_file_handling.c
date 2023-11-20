#include "../../headers/user/user_management.h"
#include "../../headers/user/user_file_handling.h"
#include <stdlib.h>
#include <stdio.h>

void saveUserDataToFileHelper(FILE* output) {
    struct userNode* current = usersHead;
    while(current != NULL) {
        struct User currentUser = current->user;
        fprintf(output, "%d|%s|%d\n", currentUser.serialNumber, currentUser.name,
            currentUser.isPriviliged);
        current = current->next;
    }
}

void loadUserDataFromFileHelper(FILE* input, const int numberOfLines) {
    for(int line = 0; line < numberOfLines; line++) {
        struct User currentUser;
        fscanf(input, "%d|%[^|]|%d", &currentUser.serialNumber, currentUser.name,
            &currentUser.isPriviliged);
        addUser(currentUser);
    }
}
