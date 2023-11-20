#include "../../headers/cli/command_line_tool.h"

void displayMainMenu() {
    printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n");
    printf("1 - BOOKS MANAGEMENT SUBMENU\n");
    printf("2 - USERS MANAGEMENT SUBMENU\n");
    printf("3 - TRANSACTION MANAGEMENT SUBMENU\n");
    printf("4 - IMPORT/EXPORT DATA\n");
    printf("5 - EXIT THE WHOLE PROGRAM (SAVES DATA AUTOMATICALLY)\n");
    int choice;
    scanf("%d", &choice);
    if(choice==5) return;
    displayMainMenuHelper(choice);
}

void displayMainMenuHelper(const int choice) {
    switch (choice) {
        case 1: {
            displayBookMenu();
            break;
        }
        case 2: {
            displayUserMenu();
            break;
        }
        case 3: {
            displayTransactionMenu();
            break;
        }
        case 4: {
            displayDataMenu();
            break;
        }
        default: {
            printf("***WRONG CHOICE ENTERED***\n");
            break;
        }
    }
}

void displayBookMenu() {
    printf("BOOKS MANAGEMENT SUBMENU\n");
    printf("1 - Add Book\n");
    printf("2 - Search Book\n");
    printf("3 - Delete Book\n");
    printf("4 - Display Whole Library\n");
    printf("5 - Return To Main Menu\n");
    int choice;
    scanf("%d", &choice);
    if(choice==5) {
        displayMainMenu();
        return;
    }
    displayBookMenuHelper(choice);
    displayBookMenu();
}

void displayUserMenu() {
    printf("USERS MANAGEMENT SUBMENU\n");
    printf("1 - Add User\n");
    printf("2 - Search User\n");
    printf("3 - Delete User\n");
    printf("4 - Display All User\n");
    printf("5 - Return To Main Menu\n");
    int choice;
    scanf("%d", &choice);
    if(choice==5) {
        displayMainMenu();
        return;
    }
    displayUserMenuHelper(choice);
    displayUserMenu();
}

void displayTransactionMenu() {
    printf("TRANSACTION MANAGEMENT SUBMENU\n");
    printf("1 - Add Transaction\n");
    printf("2 - Delete Transaction\n");
    printf("3 - Display Transaction\n");
    printf("4 - Return To Main Menu\n");
    int choice;
    scanf("%d", &choice);
    if(choice==4) {
        displayMainMenu();
        return;
    }
    displayTransactionMenuHelper(choice);
    displayTransactionMenu();
}

void displayDataMenu() {
    printf("DATA MANAGEMENT SUBMENU\n");
    printf("Library -> data/library.txt\n");
    printf("User -> data/user.txt\n");
    printf("Transaction -> data/transaction.txt\n");
    printf("1 - Import Data\n");
    printf("2 - Export Data\n");
    printf("3 - Return To Main Menu\n");
    int choice;
    scanf("%d", &choice);
    if(choice==3) {
        displayMainMenu();
        return;
    }
    displayDataMenuHelper(choice);
    displayDataMenu();
}

void displayBookMenuHelper(const int choice) {
    switch (choice) {
        case 1: {
            struct Book book;
            printf("ISBN: ");
            scanf(" %[^\n]", book.ISBN);
            printf("Book Name: ");
            scanf(" %[^\n]", book.title);
            printf("Book Author: ");
            scanf(" %[^\n]", book.author);
            printf("Available Quantity: ");
            scanf("%d", &book.quantity);
            addBook(book);
            printf("Added Book!\n");
            break;
        }
        case 2: {
            char ISBN[20];
            printf("ISBN Number: ");
            scanf(" %[^\n]", ISBN);
            displayBook(searchBook(ISBN)->book);
            break;
        }
        case 3: {
            char ISBN[20];
            printf("ISBN Number: ");
            scanf(" %[^\n]", ISBN);
            deleteBook(ISBN);
            printf("Deleted Book!\n");
            break;
        }
        case 4: {
            displayLibrary();
            break;
        }
        default: {
            printf("***WRONG CHOICE ENTERED***\n");
            break;
        }
    }
}

void displayUserMenuHelper(const int choice) {
    switch (choice) {
        case 1: {
            struct User user;
            printf("Serial Number: ");
            scanf("%d", &user.serialNumber);
            printf("Name: ");
            scanf(" %[^\n]", user.name);
            printf("Is User Admin? (0/1): ");
            scanf("%d", &user.isPriviliged);
            addUser(user);
            printf("Added User!\n");
            break;
        }
        case 2: {
            int serialNumber;
            printf("Serial Number: ");
            scanf("%d", &serialNumber);
            displayUser(searchUser(serialNumber)->user);
            break;
        }
        case 3: {
            int serialNumber;
            printf("Serial Number: ");
            scanf("%d", &serialNumber);
            deleteUser(serialNumber);
            printf("Deleted User!\n");
            break;
        }
        case 4: {
            displayAllUser();
            break;
        }
        default: {
            printf("***WRONG CHOICE ENTERED***\n");
            break;
        }
    }
}

void displayTransactionMenuHelper(const int choice) {
    switch (choice) {
        case 1: {
            int serialNumber, startDate, endDate;
            char ISBN[20];
            printf("Serial Number: ");
            scanf("%d", &serialNumber);
            printf("ISBN Number: ");
            scanf(" %[^\n]", ISBN);
            printf("StartDate (DDMMYY): ");
            scanf("%d", &startDate);
            printf("EndDate (DDMMYY): ");
            scanf("%d", &endDate);
            addTransaction(serialNumber, ISBN, startDate, endDate);
            printf("Transaction Added!\n");
            break;
        }
        case 2: {
            int serialNumber;
            printf("Serial Number: ");
            scanf("%d", &serialNumber);
            char ISBN[20];
            printf("ISBN: ");
            scanf(" [^\n]", ISBN);
            removeTransaction(serialNumber, ISBN);
            printf("Transaction Deleted!\n");
            break;
        }
        case 3: {
            int serialNumber;
            printf("Serial Number: ");
            scanf("%d", &serialNumber);
            displayTransaction(serialNumber);
            break;
        }
        default: {
            printf("***WRONG CHOICE ENTERED***\n");
            break;
        }
    }
}

void displayDataMenuHelper(const int choice) {
    switch (choice) {
        case 1: {
            loadDataFromFile();
            break;
        }
        case 2: {
            saveDataToFile();
            break;
        }
        default: {
            printf("***WRONG CHOICE ENTERED***\n");
            break;
        }
    }
}
