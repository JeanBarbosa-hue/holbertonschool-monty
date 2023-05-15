**Holberton School Monty**

This repository contains the source code for the Monty project, developed as part of the curriculum at Holberton School. Monty is a simple interpreter for Monty Bytecode files.
**Table of Contents**

    Introduction
    Installation
    Usage
    Monty Bytecode
    Example
    Creators

**Introduction**

Monty is a project developed at Holberton School to create an interpreter for Monty Bytecode files. Monty Bytecode is a minimalistic language that provides a set of stack-based operations. The interpreter reads a Monty Bytecode file and executes the operations specified in the file.

This project aims to teach various concepts related to programming languages, interpreters, and data structures.
Installation

To run the Monty interpreter locally, follow these steps:

    Clone the repository:

    bash

git clone https://github.com/JeanBarbosa-hue/holbertonschool-monty.git

Change to the project directory:

bash

cd holbertonschool-monty

Compile the source code:

    gcc -Wall -Werror -Wextra -pedantic *.c -o monty

**Usage**

Once the source code is compiled, you can use the Monty interpreter as follows:

bash

./monty <filename>

Replace <filename> with the path to the Monty Bytecode file you want to execute.
Monty Bytecode

Monty Bytecode files are simple text files that contain one operation per line. The interpreter reads these files and executes the operations accordingly.

The Monty Bytecode language supports the following operations:

    push <value>: Pushes an element to the stack.
    pall: Prints all the values on the stack, starting from the top.
    pint: Prints the value at the top of the stack.
    pop: Removes the top element of the stack.
    swap: Swaps the top two elements of the stack.
    add: Adds the top two elements of the stack.
    nop: Does nothing.

Note: The Monty interpreter assumes that the Monty Bytecode files are well-formed and do not contain syntax errors.
Example

Suppose we have a Monty Bytecode file named bytecode.m with the following content:

perl

push 1
push 2
push 3
pall

We can execute this file using the Monty interpreter:

bash

./monty bytecode.m

The output will be:

3
2
1

**Creators**
  Luis Ayala(https://github.com/luisayala323)
  Jean Barbosa(https://github.com/JeanBarbosa-hue)
