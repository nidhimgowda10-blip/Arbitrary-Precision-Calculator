# Arbitrary Precision Calculator (APC)

## Overview

The **Arbitrary Precision Calculator (APC)** is a C-based calculator that performs arithmetic operations on integers of virtually unlimited size using **Doubly Linked Lists**. It overcomes the size limitations of standard C integer data types by storing each digit as a separate linked-list node.

## Features

* Addition
* Subtraction
* Multiplication
* Division
* Modulus
* Supports very large integer calculations
* Handles positive and negative integers

## Technologies Used

* **C Programming**
* **Doubly Linked Lists**
* **GNU Make**
* **Linux (Ubuntu/WSL)**
* **Visual Studio Code**

## Project Structure

```text
APC/
├── include/
├── source/
├── Makefile
└── README.md
```

## Build

Compile the project using:

```bash
make
```

## Run

```bash
./bin/apc <number1> <operator> <number2>
```

### Example

```bash
./bin/apc 123456789123456789 + 987654321987654321
```

### Output

```text
1111111111111111110
```

## Author

**Nidhi M**
