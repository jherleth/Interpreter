# Blip Interpreter 

A simple interpreter for a custom language, **Blip**, built in C++. This program processes commands from a file, supporting variable declarations, assignments, and output.

---

## Project Structure

The project is organized into modular C++ files, each handling a specific part of the interpreter's functionality:

* `main.cpp`: The program's entry point.
* `Interpreter.cpp` / `Interpreter.h`: Contains the core logic for command parsing and evaluation.
* `Input.cpp` / `Parse.h`: Manages input from files and tokenizes the code.
* `SymbolTable.h`: Handles variable storage using a symbol table.

---

## Features

The Blip language includes a concise set of features:

* **Variable Management:** Use `var` to declare and `set` to assign integer values to variables.
* **Input/Output:** `output` prints the value of an expression, while `text` prints a raw string.
* **Expressions:** Supports standard arithmetic (`+`, `-`, `*`, `/`, `%`), logical (`&&`, `||`), and relational operators (`<`, `>`, `==`, `!=`, `<=`, `>=`).
* **Comments:** Single-line comments are supported using `//`.

---

## How to Compile and Run

To get started, you'll need a C++ compiler like `g++`.

1.  **Compile the code:**

    ```bash
    g++ -o blip main.cpp Interpreter.cpp Input.cpp
    ```

2.  **Run the interpreter:**

    The `main.cpp` file is configured to read from a file named `test_grader.blip`. Simply execute the compiled program:

    ```bash
    ./blip test_grader.blip
    ```
---

*Happy coding!*
