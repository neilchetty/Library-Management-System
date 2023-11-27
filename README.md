## Library Management System in C

### Release Info:
* Linux users can directly download executable from release page and use it.

### Build Instructions:
* CMake is needed to build this. Please refer https://cmake.org/

* Build Commands:
```
git clone https://github.com/neilchetty/Library-Management-System.git
cd Library-Management-System/
mkdir build && cd build
cmake ..
cmake --build .
```
* Executable file should be present in:
```
build/bin/LibraryManagementSystem (Linux)
build/bin/Debug/LibraryManagementSystem.exe (Windows)
```

### Features:
* Add unlimited books to library
* Add unlimited number of users
* Add data when a user borrows a book and returns the book
* Data is stored in ```.txt``` file after exiting the program
* Import/Export Data across any os
* Build up your library from ```.txt``` file
* Interactive CLI Interface
* Automatic storing of whole data on unexpected exit of program

### Info:
* This is the end sem project for course ```CS102``` Offered by Indian Institute Of Information Technology Design And Manufacturing, Kurnool
* This is project is released under GPLv2 License
