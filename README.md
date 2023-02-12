# Simple-Postfix-Calculator

Postfix Calculator

This is a postfix calculator application that evaluates mathematical expressions in postfix notation.

Build with g++ main.cpp -o main

# Features

- Evaluate mathematical expressions in postfix notation.
- Option to swap the places of two numbers in the stack.
- Option to sum all the elements in the stack.
- Option to find the average of all the elements in the stack.

# Usage

The user can enter a mathematical expression in postfix AND in infix notation and the app will return the result. For example, entering "1 2 +" or "1 + 2" will both return 3.

In addition to evaluating mathematical expressions, the app also supports the following options:

- x: Swaps the places of the two numbers at the top of the stack.
- s: Sums all the elements in the stack.
- a: Finds the average of all the elements in the stack.

For example:
- Entering 1 2 x - will return 1 instead of -1.
- Entering 1 2 3 s will return 6.
- Entering 2 4 6 a will return 4.

The app also provides flexibility in the order of entering the options.

For example with the option 's', the used as "s 1 2 3" or even "1 s 2 3".
This makes the app more user-friendly and accommodates different input styles.
