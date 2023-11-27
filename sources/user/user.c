#include "user/user.h"
#include <stdio.h>

void displayUser(struct User user) {
    printf("User Details: \n");
    printf("Serial Number: %d\n", user.serialNumber);
    printf("User Name: %s\n", user.name);
    printf("isPriviliged: %d\n", user.isPriviliged);
}
