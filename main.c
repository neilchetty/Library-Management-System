#include "headers/cli/command_line_tool.h"
#include <stddef.h>
#include <stdlib.h>

struct bookNode* booksHead = NULL;
struct bookNode* booksTail = NULL;
struct userNode* usersHead = NULL;
struct userNode* usersTail = NULL;

int main() {
    displayMainMenu();
    atexit(saveDataToFile);
    at_quick_exit(saveDataToFile);
}
