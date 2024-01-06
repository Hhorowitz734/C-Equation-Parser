# Equation Parser and Abstract Syntax Tree (AST) Visualizer

## Description
This project is designed to efficiently process mathematical equations by lexing, parsing, and converting them into abstract syntax tree (AST) representations or prefix notation. The primary goal is to provide a clear and interactive way to understand the underlying structure of mathematical expressions.

---

## Features
- Lexer: This feature robustly tokenizes and lexes any given mathematical equation, transforming it from a standard string input into a sequence of tokens. These tokens represent the fundamental elements of the equation, such as numbers, operators, and parentheses. The lexer is designed to handle a wide range of mathematical expressions, ensuring accuracy and efficiency in breaking down complex equations into manageable, computer-readable components.
- Parser: The AST-Based Parser is a designed to transform a stream of tokens, derived from mathematical equations, into a structured Abstract Syntax Tree (AST). This feature stands as the core interpreter between the initial lexical analysis and the final computational representation of the equation.
- Visualizer: The visualizer serves as an integral part of the project, offering a graphical representation of the Abstract Syntax Tree (AST) generated from parsed mathematical expressions. It takes the head node output by the parser and constructs a visual tree structure, accurately depicting the hierarchical relationships and operational logic of the equation. This feature is interactive, allowing users to explore different parts of the tree in detail. It's engineered to dynamically adjust to various tree sizes and complexities, ensuring clarity and readability irrespective of the depth or breadth of the tree.
- [TODO] Intuitive Prefix Notation Converter: This module will efficiently convert parsed mathematical expressions into prefix notation (Polish notation). It's designed to facilitate an alternative view of the equation where operators precede their operands, streamlining the computational process for certain types of algorithmic evaluations. This feature is particularly beneficial for educational purposes and in computational scenarios where prefix notation is preferred.

---

## Installation Instructions

This guide will walk you through the process of setting up and installing the EquationParser project on your system.

### Prerequisites

Before you begin, ensure that you have the following prerequisites installed on your machine:

- CMake (version 3.10 or higher)
- A C compiler that supports C11 standard (e.g., GCC, Clang)
- Raylib (version 4.5.0)
- CUnit for testing

You can install Raylib and CUnit via a package manager like Homebrew on macOS or the respective package manager for your operating system.

### Step 1: Clone the Repository

First, clone the EquationParser repository from its source. This step assumes you have `git` installed:

```bash
git clone https://github.com/Hhorowitz734/C-Equation-Parser
cd EquationParser
```

### Step 2: Install Raylib and CUnit

If you haven't already installed Raylib and CUnit, you can do so using Homebrew on macOS:

```bash
brew install raylib
brew install cunit
```

For other operating systems, please refer to the official documentation for Raylib and CUnit for installation instructions.

### Step 3: Build the Project

Once the prerequisites are installed, you can build the project using CMake:

```bash
mkdir build
cd build
cmake ..
make
```

This will compile the main application along with the necessary libraries.

### Step 4: Run Tests

To ensure everything is set up correctly, run the included tests:

```bash
ctest
```

This command will execute all the tests defined in the CMake configuration, such as LexerTest, StackTest, QueueTest, and ParserTest.

### Step 5: Running the Application

After successfully building the project and passing the tests, you can run the EquationParser application after updating your equation in the main.c.

```bash
./equationparser
```

This command will start the application. Follow any on-screen instructions to interact with the program.

### Troubleshooting

If you encounter any issues during installation or running the application, email me at hhorowitz734@gmail.com.

## Images
![Tree Image](/images/tree.png "Tree Visualization")
