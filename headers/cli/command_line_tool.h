#ifndef COMMAND_LINE_TOOL_H
#define COMMAND_LINE_TOOL_H

#include "../book/library_management.h"
#include "../user/user_management.h"
#include "../book/book_file_handling.h"
#include "../transaction/transaction_management.h"

void displayMainMenu();
void displayMainMenuHelper(int choice);
void displayBookMenu();
void displayBookMenuHelper(int choice);
void displayUserMenu();
void displayUserMenuHelper(int choice);
void displayTransactionMenu();
void displayTransactionMenuHelper(int choice);
void displayDataMenu();
void displayDataMenuHelper(int choice);

#endif //COMMAND_LINE_TOOL_H
