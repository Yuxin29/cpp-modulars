# 🕹️ C++ Modular Projects

This repository contains a set of **independent C++ modules**, each designed to solve a specific task or demonstrate a particular concept. Each module is **self-contained** and can be compiled and run individually.  

📦 **Features**

- 🧱 Modular and self-contained C++ code  
- ✅ Easy to compile and test each module separately  
- 🧠 Demonstrates core C++ concepts like classes, inheritance, templates, and data structures  
- 💥 Proper memory management and error handling  
- 🔄 Designed for learning and experimentation  

🗺️ **Project Structure**

- Each module resides in its own folder or directory  
- Typically includes:  
  - `main.cpp` — entry point for the module  
  - Other `.cpp` and `.hpp` files — modular implementation of features  
  - Optional `Makefile` for easy compilation  

🏗️ **what I learned**

# 🕹️ C++ Module 00

C++ Module 00 introduces new coders to the basics of C++, including namespaces, classes, member functions, constructors, initialization lists, static and const variables, and standard I/O streams. Through exercises like Megaphone, My Awesome PhoneBook, and recreating Account.cpp, students practice class design, object instantiation, encapsulation, and basic string and array manipulation while gaining confidence compiling and running C++ programs.



🚀 **Build & Run**  
⚙️ ***Requirements***

- `g++` or `clang++`  
- Standard C++17 or later  

🏗️ **Compilation**

1. Navigate to the module directory:  
```bash
cd ModuleName

    Compile the module using g++:

g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o ModuleName

    Run the module:

./ModuleName

💻 Usage Example

    Example for a module called VectorModule:

cd VectorModule
g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o VectorModule
./VectorModule

📁 Module Guidelines

    Each module should be independent and not rely on other modules

    Use header files (.hpp) for declarations and .cpp for implementation

    Keep code modular and reusable
