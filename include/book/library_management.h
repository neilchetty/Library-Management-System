#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include "book.h"

struct bookNode {
    struct Book book;
    struct bookNode* prev;
    struct bookNode* next;
};

extern struct bookNode* booksHead;
extern struct bookNode* booksTail;

void addBook(struct Book book);
struct bookNode* deleteBook(const char* ISBN);
struct bookNode* searchBook(const char* ISBN);
void displayLibrary();

#endif //LIBRARY_MANAGEMENT_H
