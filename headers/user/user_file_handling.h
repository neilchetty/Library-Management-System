#ifndef USER_FILE_HANDLING_H
#define USER_FILE_HANDLING_H

#include <stdio.h>

void saveUserDataToFileHelper(FILE* output);
void loadUserDataFromFileHelper(FILE* input, int numberOfLines);

#endif //USER_FILE_HANDLING_H
