# Chalenges

Here all chalenges and problems from various sources will be solved.

## Chalenge#1

Write a small program that declares the following:

- An Int variable with block scope and temporary storage.
- A global double variable that is only accessible inside this file.
- A global float variable that is accesible within the entire program.
- A float local variable with permament storage.
- A register int variable
- A function that is only accesible with the file it is defined.

## Chalenge#2

Write a program that finds the sum of various numbers.
You cannot pass any variables representing the running total to the sum() function => no additional params just one for a number to add up to the sum

example: 

```
int main() {
    printf("%d", sum(25));
    printf("%d", sum(15));
    printf("%d", sum(30));

    return 0;
}

output:
25 40 70
```

## Challenge#3

Create a program that shares a variable among two files.

create main.c
- source file should have global variable used as loop counter
- this file includes a main function (display function from another file) that uses the global variable to iterate through a
loop 5 times
    - inside the loop a function should be invoked that is defined in another file (do not use an include file - header)
    - the display function should take no params.

create another file
- display function is defined here.
    - this function displays the global variable form main.c (incremented by1)