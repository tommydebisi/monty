#   Interpreter for Monty ByteCodes files
![stack_project](./stack_project.jpg)

**Monty** 0.98 is a scripting language that is first compiled into **Monty** byte codes **(Just like Python)**. It relies on a unique **stack**, with specific instructions to manipulate it.

## Aims & Objectives 🌟
***By completing this project i must be able to:***
-   Know what a **stack** is and to use it.
-   Know the common use cases of **stacks and queues**.
-   Know the common implementation of **stacks and queues**.

## Functions Implemented🌟
|   **Opcodes** |   **Function**    |
|   ----------  |   --------------  |
|   `push`      |    pushes an element to the **stack** |
|   `pall`      |   prints all the values on the **stack**, starting from the top of the **stack**. |
|   `pint`      |    prints the value at the top of the **stack**.  |
|   `pop`       |   removes the top element of the **stack**.   |
|   `swap`      |   swaps the top two elements of the **stack**.    |
|   `add`       |   adds the top two elements of the **stack**. |
|   `nop`       |   doesn't do anything |
|   `sub`       |   subtracts the top element of the **stack** from the second top element of the **stack**.    |
|   `div`       |   divides the second top element of the **stack** by the top element of the **stack**.    |
|   `mul`       |    multiplies the second top element of the **stack** with the top element of the **stack**.  |
|   `mod`       |   computes the rest of the division of the second top element of the **stack** by the top element of the **stack**.   |
|   `pchar`     |    prints the char at the top of the **stack**    |
|   `pstr`      |   prints the string starting at the top of the **stack**. |
|   `rotl`      |   rotates the **stack** to the top.   |
|   `rotr`      |   rotates the **stack** to the bottom.    |
|   `stack`     |    sets the format of the data to a **stack (LIFO)**. |
|   `queue`     |   sets the format of the data to a **queue (FIFO)**.  |

***Other functions implemented:***
-   Use of comments with `#` preceeding comment
<br><br>

##  Compilation 🏃🏻
***Your code should be compiled this way:*** <br>
`$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
<br><br>

## Examples 🔥
```
Tom_tola@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
Tom_tola@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
Tom_tola@ubuntu:~/monty$
```

##  Authors 🤝🏽
**Adebisi Oluwatomiwa** <br>
**Odelola Oluwatolamise** <br>
