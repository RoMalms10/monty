# Monty Language Interpreter
## Synopsis
This project was built in an effort to learn about stacks and queues and how to implement them by interpreting monty scripts (files that end in .m).

## Environment
This project was built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox.

## Repository Contents
#### Files ending in .c

> calc\_func.c - *Contains functions used to perform calculations on the stack*

| Function Name | Function Description |
| :-----------: | :------------------- |
| add           | adds the top two elements of the stack |
| sub           | subtracts the top number form the second number of the stack |
| divf          | divides the top number from the second nubmer of the stack |
| mul           | multiplies the top two elements of the stack |
| mod           | mods the top number by the second number of the stack |

> error.c - *Contains functions that deal with error messages and freeing memory*

| Function Name | Function Description |
| :-----------: | :------------------- |
| exit_function | handles errors and frees memory before exiting |
| free_list     | free a stack_t list |
| free_buf      | free getline buffer |
| free_token    | Frees malloc'd tokens |

> functions.c - *Contains functions that deal with basics of creating a stack*

| Function Name | Function Description |
| :-----------: | :------------------- |
| add_stack     | adds a node at the beginning of the stack |
| tokenize      | tokenizes a line in a file into separate strings |
| pall          | prints all integers in the stack, starting from the top |
| push          | adds a node to the top of the stack in stack mode, bottom of the stack in queue mode |

> functions_2.c - *Contains functions that read and manipulate the stack*

| Function Name | Function Description |
| :-----------: | :------------------- |
| pint          | prints the number at the top of the stack |
| pop           | deletes the top element of the stack |
| swap          | swaps the top two numbers in the stack |
| nop           | literally does nothing |

> functions_4.c - *Contains more function that read and manipulate the stack*

| Function Name | Function Description |
| :-----------: | :------------------- |
| pchar         | prints the ASCII equivalent of the value stored in the top of stack |
| pstr          | prints the ASCII equivalent of the values stored in all of the stack |
| rotl          | move the top of the stack to the bottom |
| rotr          | move the bottom of the stack to the top |

> monty.c - *Contains the main function*

| Function Name | Function Description |
| :-----------: | :------------------- |
| main          | entry point of the program |

> op_finder.c - *Contains the file that finds which opcode is being called*

| Function Name | Function Description |
| :-----------: | :------------------- |
| find_op       | searches for the opcode being called by the file |

#### Other files

- monty.h - *Header file; Contains function, struct and global variable declarations*
- AUTHORS - *Contains the Authors of this program along with their emails*
- bytecodes - *A directory containing test files used while making this program*

## How to install
1. Clone the repository below

`https://github.com/RoMalms10/monty`

2. \(optional) Compile the program again

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

3. Run the program with the following usage:
   - Usage: `monty <file.m>`
   - ex: `./monty ./bytecodes/00.m`

## Example
```
RoMalms10$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
RoMalms10$ ./monty ./bytecodes/000.m
3
2
1
0
6
5
4
3
2
1
0
RoMalms10$
```

## Bugs
No bugs found yet
   
## Authors
* [**Robert Malmstein**](https://github.com/RoMalms10)
* [**Thomas Dumont**](https://github.com/vilyanare)
