#ifndef BOOK_FILE_HANDLING_H
#define BOOK_FILE_HANDLING_H

#include <stdio.h>

void saveDataToFile();
void saveBookDataToFileHelper(FILE* output);
int numberOfLines(FILE* input);
void loadDataFromFile();
void loadBookDataFromFileHelper(FILE*, int numberOfLines);

#endif //BOOK_FILE_HANDLING_H
