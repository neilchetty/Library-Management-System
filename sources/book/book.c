#include "../../headers/book/book.h"
#include <stdio.h>

void displayBook(struct Book book) {
    printf("Book Details: \n");
    printf("ISBN: %s\n", book.ISBN);
    printf("Book Name: %s\n", book.title);
    printf("Book Author: %s\n", book.author);
    printf("Available Quantity: %d\n", book.quantity);
}
