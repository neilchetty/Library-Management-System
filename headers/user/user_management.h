#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include "user.h"

struct userNode {
    struct User user;
    struct userNode* prev;
    struct userNode* next;
};

extern struct userNode* usersHead;
extern struct userNode* usersTail;

void addUser(struct User user);
struct userNode* deleteUser(int userId);
struct userNode* searchUser(int userId);
void displayAllUser();

#endif //USER_MANAGEMENT_H
