## Arbitrary Precision Calculator

This project is an Arbitrary Precision Calculator implemented in C language that can perform arithmetic operations like addition, subtraction, multiplication, and division on large numbers beyond the normal data type limits (e.g., integers or long long).

## Features

Supports very large integers (bigger than 10^100 or more).

Performs basic arithmetic operations:

➕ Addition
➖ Subtraction
✖️ Multiplication
➗ Division

Handles both positive and negative numbers.
Input and output via string-based operations.
Modular and easy-to-understand code structure.

## Concept Overview

Normal C data types (int, long, long long) have size limits.
To handle very large numbers, this project:

Stores numbers as strings.
Performs arithmetic digit-by-digit, just like manual calculation.
Uses linked lists or arrays internally to store results.
Implements functions such as:

add_big_numbers()

subtract_big_numbers()

multiply_big_numbers()

divide_big_numbers()



Enter first number: 999999999999999999999

Choose operation: +

Enter second number: 888888888888888888888

Result: 1888888888888888888887


