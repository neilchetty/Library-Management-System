cmake_minimum_required(VERSION 3.27)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project(LibraryManagementSystem C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c17")
add_executable(LibraryManagementSystem
        main.c
        headers/book/book.h
        headers/book/library_management.h
        headers/book/book_file_handling.h
        sources/book/library_management.c
        sources/book/book_file_handling.c
        sources/book/book.c
        sources/user/user_management.c
        headers/user/user_management.h
        headers/user/user.h
        sources/user/user.c
        sources/user/user_file_handling.c
        headers/user/user_file_handling.h
        sources/transaction/transaction.c
        sources/transaction/transaction_file_handling.c
        sources/transaction/transaction_management.c
        headers/transaction/transaction.h
        headers/transaction/transaction_file_handling.h
        headers/transaction/transaction_management.h
        sources/cli/command_line_tool.c
        headers/cli/command_line_tool.h
)
