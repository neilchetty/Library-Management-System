#include "../../headers/user/user_management.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addUser(struct User user) {
    for(int i = 0; i < 5; i++) user.transaction[i].borrowed = 0;
    struct userNode* newNode = (struct userNode*)malloc(sizeof(struct userNode));
    if(newNode == NULL) {
        perror("Memory Allocation Failed For New User! \n");
        return;
    }
    newNode->user = user;
    newNode->next = NULL;
    if(usersHead == NULL) {
        newNode->prev = NULL;
        usersHead = newNode;
        usersTail = newNode;
    }
    else {
        newNode->prev = usersTail;
        usersTail->next = newNode;
        usersTail = newNode;
    }
}

struct userNode* deleteUser(const int serialNumber) {
    struct userNode* current = usersHead;
    while(current != NULL) {
        if(current->user.serialNumber == serialNumber) {
            if(current->prev == NULL) {
                usersHead = current->next;
                if(usersHead == NULL) usersTail = NULL;
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

struct userNode* searchUser(const int serialNumber) {
    struct userNode* current = usersHead;
    while(current != NULL) {
        if(current->user.serialNumber == serialNumber) return current;
        current = current->next;
    }
    return current;
}

void displayAllUser() {
    struct userNode* current = usersHead;
    while(current != NULL) {
        struct User currentUser = current->user;
        printf("%d|%s|%d\n", currentUser.serialNumber, currentUser.name,
            currentUser.isPriviliged);
        current = current->next;
    }
}
