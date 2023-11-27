#include "book/book_file_handling.h"
#include "book/library_management.h"
#include "user/user_file_handling.h"
#include "transaction/transaction_file_handling.h"
#include <stdlib.h>

int numberOfLines(FILE* input) {
    int lines = 0;
    char currentChar = fgetc(input);
    while(currentChar != EOF) {
        if(currentChar == '\n') lines++;
        currentChar = fgetc(input);
    }
    rewind(input);
    return lines;
}

void saveDataToFile() {
    FILE* bookOutput = fopen("data/library.txt", "w");
    FILE* userOutput = fopen("data/user.txt", "w");
    FILE* transactionOutput = fopen("data/transaction.txt", "w");
    if(bookOutput == NULL || userOutput == NULL || transactionOutput == NULL) {
        perror("Cannot Open Output File!\n");
        return;
    }
    saveBookDataToFileHelper(bookOutput);
    saveUserDataToFileHelper(userOutput);
    saveTransactionDataToFileHelper(transactionOutput);
    fclose(bookOutput);
    fclose(userOutput);
    fclose(transactionOutput);
}

void loadDataFromFile() {
    FILE* bookInput = fopen("data/library.txt", "r");
    FILE* userInput = fopen("data/user.txt", "r");
    FILE* transactionInput = fopen("data/transaction.txt", "r");
    if(bookInput == NULL || userInput == NULL || transactionInput == NULL) {
        perror("Cannot Open Input File!\n");
        return;
    }
    int bookLines = numberOfLines(bookInput);
    int userLines = numberOfLines(userInput);
    int transactionLines = numberOfLines(transactionInput);
    loadBookDataFromFileHelper(bookInput, bookLines);
    loadUserDataFromFileHelper(userInput, userLines);
    loadTransactionDataFromFileHelper(transactionInput, transactionLines);
    fclose(bookInput);
    fclose(userInput);
    fclose(transactionInput);
}

void saveBookDataToFileHelper(FILE* output) {
    struct bookNode* current = booksHead;
    while(current != NULL) {
        struct Book currentBook = current->book;
        fprintf(output, "%s|%s|%s|%d\n", currentBook.ISBN, currentBook.title,
            currentBook.author, currentBook.quantity);
        current = current->next;
    }
}

void loadBookDataFromFileHelper(FILE* input, int numberOfLines) {
    for(int line = 0; line < numberOfLines; line++) {
        struct Book currentBook;
        fscanf(input, " %[^|]|%[^|]|%[^|]|%d", currentBook.ISBN, currentBook.title,
            currentBook.author, &currentBook.quantity);
        addBook(currentBook);
    }
}
