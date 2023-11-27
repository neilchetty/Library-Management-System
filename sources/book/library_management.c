#include "book/library_management.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addBook(struct Book book) {
    struct bookNode* newNode = (struct bookNode*)malloc(sizeof(struct bookNode));
    if(newNode == NULL) {
        perror("Memory Allocation Failed For New Book! \n");
        return;
    }
    newNode->book = book;
    newNode->next = NULL;
    if(booksHead == NULL) {
        newNode->prev = NULL;
        booksHead = newNode;
        booksTail = newNode;
    }
    else {
        newNode->prev = booksTail;
        booksTail->next = newNode;
        booksTail = newNode;
    }
}

struct bookNode* deleteBook(const char* ISBN) {
    struct bookNode* current = booksHead;
    while(current != NULL) {
        if(strcmp(current->book.ISBN, ISBN)==0) {
            if(current->prev == NULL) {
                booksHead = current->next;
                if(booksHead == NULL) booksTail = NULL;
            }
            else {
                current->prev->next = current->next;
            }
            return current;
        }
        current = current->next;
    }
    return current;
}

struct bookNode* searchBook(const char* ISBN) {
    struct bookNode* current = booksHead;
    while(current != NULL) {
        if(strcmp(current->book.ISBN, ISBN)==0) return current;
        current = current->next;
    }
    return current;
}

void displayLibrary() {
    struct bookNode* current = booksHead;
    while(current != NULL) {
        struct Book currentBook = current->book;
        printf("%s|%s|%s|%d\n", currentBook.ISBN, currentBook.title,
            currentBook.author, currentBook.quantity);
        current = current->next;
    }
}
