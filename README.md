# C++ Modular Projects

This repository contains a set of **independent C++ modules**, each designed to solve a specific task or demonstrate a particular concept. Each module is **self-contained** and can be compiled and run individually.  

**Features**

- Modular and self-contained C++ code  
- Easy to compile and test each module separately  
- Demonstrates core C++ concepts like classes, inheritance, templates, and data structures  
- Proper memory management and error handling  
- Designed for learning and experimentation  

**Project Structure**

- Each module resides in its own folder or directory  
- Typically includes:  
  - `main.cpp` — entry point for the module  
  - Other `.cpp` and `.hpp` files — modular implementation of features  
  - Optional `Makefile` for easy compilation  

**what I learned**

- Module 00: Namespaces, classes, member functions, stdio streams, initialization lists, static, const, iostream
  - ex00 - String manipulation and command-line argument handling
  - ex01 - Classes, Object instantiation, Basic I/O, String manipulation
  - ex02 - File recreation, C++ programming, Object-oriented design
- Module 01: Memory allocation, pointers to members, references, switch statement
  - ex00 - Classes, Member Functions, Pointers, Memory Allocation (stack vs. heap), Destructors
  - ex01 - Arrays of Objects, Memory Allocation (array of objects), Object Initialization
  - ex02 - Pointers, References, Memory Addresses
  - ex03 - Composition, Aggregation, Object Relationships, Constructors, Setters
  - ex04 - File I/O, Content copy to new file, Error Handling
  - ex05 - Member Functions, Pointers to Member Functions, Enumeration, Logging
  - ex06 - Switch Statement, Filtering, Logging
- Module 02: Fixed-point numbers, operator overloading and Orthodox Canonical class form
  - ex00 - Fixed-point numbers, Orthodox Canonical Form
  - ex01 - Constructors (from int and float), Member Functions (toFloat, toInt), Operator Overloading
  - ex02 - Operator Overloading (Comparison, Arithmetic, Increment/Decrement), Static Member Functions (min, max)
- Module 03: Inheritance
  - ex00 - Class implementation
  - ex01 - Inheritance, Constructors/Destructors Chaining, Overriding Member Functions
  - ex02 - Inheritance, Constructors/Destructors Chaining, Overriding Member Functions
- Module 04: Subtype polymorphism, abstract classes, interfaces
  - ex00 - Polymorphism, Inheritance, Virtual Functions
  - ex01 - Memory Management, Deep Copy
  - ex02 - Abstract Classes
  - ex03 - Interfaces / Pure Abstract Classes
- Module 05: Repetition and Exceptions
  - ex00 - Exception handling, class design
  - ex01 - Exception handling, class design, member functions
  - ex02 - Abstract classes, inheritance, polymorphism, execution logic
  - ex03 - Factory method, class design, string manipulation
- Module 06 (to be done):: C++ casts
- Module 07 (to be done): C++ templates
- Module 08 (to be done): Templated containers, iterators, algorithms
- Module 09 (to be done):: STL

**Compilation**

### 1. Clone the Module Directory

```
git clone github.com/snowhp/CPP-Modules
```

## 2. Navigate to the Desired Module/Exercise Directory

```
cd CPP00/ex00
```

## 3. Compile and Run Your Program

```
make
./PROGRAM_EXECUTABLE_NAME
```

**Note:** The executable name depends on the exercise. Most are either the default `a.out` or match the exercise folder name (e.g., `ex00`).

## 4. Supported Make Commands

```
make clean
make fclean
make re
```
