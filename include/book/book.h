#ifndef BOOKS_H
#define BOOKS_H

struct Book {
    char ISBN[13];
    char title[100];
    char author[100];
    int quantity;
};

void displayBook(struct Book book);

#endif //BOOKS_H
