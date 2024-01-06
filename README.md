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

## Installation
Instructions for setting up and installing your project:

1. Prerequisite: Any prerequisites or dependencies.
2. Step 1: First installation step.
3. Step 2: Further steps...

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

```bash
# Example command
