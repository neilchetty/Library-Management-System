cmake_minimum_required(VERSION 3.27)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project(LibraryManagementSystem C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c17")
add_executable(LibraryManagementSystem
        main.c
        include/book/book.h
        include/book/library_management.h
        include/book/book_file_handling.h
        sources/book/library_management.c
        sources/book/book_file_handling.c
        sources/book/book.c
        sources/user/user_management.c
        include/user/user_management.h
        include/user/user.h
        sources/user/user.c
        sources/user/user_file_handling.c
        include/user/user_file_handling.h
        sources/transaction/transaction.c
        sources/transaction/transaction_file_handling.c
        sources/transaction/transaction_management.c
        include/transaction/transaction.h
        include/transaction/transaction_file_handling.h
        include/transaction/transaction_management.h
        sources/cli/command_line_tool.c
        include/cli/command_line_tool.h
)
target_include_directories(LibraryManagementSystem PRIVATE include)
