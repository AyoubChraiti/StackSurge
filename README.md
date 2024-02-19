# efficient-sorting-algorithm - PushSwap

![Screenshot](https://i.imgur.com/pfaWg86.png))

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Description

PushSwap is a sorting algorithm project that aims to efficiently sort a stack of integers using a predefined set of operations. The project is part of [1337](#1337) curriculum and is implemented in C.

## Installation

To compile the PushSwap program, use the following command:

```bash
make
```

This will generate the executable file push_swap.

## Usage
Execute the program with a list of integers as command-line arguments:

```
bash
Copy code
./push_swap 4 2 8 1 3
```
This will display the list of operations to sort the stack in ascending order.

## Algorithm Overview
PushSwap employs a carefully crafted algorithm designed for optimal sorting efficiency.
The algorithm leverages a combination of push and swap operations to achieve a minimal number of steps in sorting the stack.
A detailed explanation of the algorithm's logic and efficiency considerations can be found in the source code.

## Examples
Here are some examples showcasing the usage of PushSwap with different input stacks and their corresponding sorted outputs:

Examples:

```bash
./push_swap 4 2 8 1 3
Output:

bash
Operations: sa pb pb sa sa pa pa pa pa
Example 2:

bash
./push_swap 5 2 7 1 4
Output:

bash
Operations: pb pb sa pa sa pa pa
```
