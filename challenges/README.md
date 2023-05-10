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

## Challenge#4

Write a program to read elements in an array and find the sum of the array elements. Ask user for input. You must use VLA for the size.

```C
input elements: 10, 20, 30, 40, 50

OUTPUT
sum of all elements = 150
```
## Challenge#5

Write program that uses flexible array member inside structure. 

- Create structure named `myArray` with length member and flexible array member.
- Read size of the array from user input.
- Allocate requested by user memory.
- Set the length member and fill the array with dummy data and print the array.

hint init arraay pointer to null.

## Challenge#6

Complex Numbers calculations.

## Challenge#7

Write a program to Covert `Decimal` to `Binary` and another one to convert `Binary` to 
`Decimal`

## Challenge#8

Write bitwise operators using program. The program needs to read 2 integesr form the user. Print the reuslts for;
- `~` operator to each number; 
- `&` ,`|`, `^`;
- the `<<` and `>>` to a specific (one) number.
- show the result as binary strings. ( d2b function).

example;
enter int: 10
enter int: 11

`~` => 10 (1010) --> -1011
`~` => 11 (1011) --> -1100
`&` => 10 (1010) and 11 (1011)--> 1010
.....

## Challenge#9

Write a program that takes unput of any number from user and:
- check if nth bit of the number is set(1) or not.
- set the nth bit of a given number as 1.

enter number: 10 (1010)
enter nth bit to check(0-31): 2

the 2 bit is set to 0

Bit set successfully.

Number before setting 2 bit: 10(in decimal)
Number after setting 2 bit: 14(in decimal)

##  Challenge#10

Bitfields with on screen box.

Write a program that contains bitfields in onscreen box:
- The box can be opaque or transparent.
- Fill color is selected from palette of collorst: [black, red, green, yellow, blue, magenta, cyan, white].
- A border can be shown or hidden.
- Border color is selected from the same palette used for fill color.
- Border can use one of three line stypes: [solid, dotted, dashed].

Bit assign:
- 1 bit for opaque or transparent.
- 1 bit for border is shown or hidden.
- 3 bits for 8 variants of colors.
- 2 bit unit for 3 variants of border styles.
- Total 10 bits.

notes:
- Padding to place the fill info on first bit.
- Border info on second bit.
- Colors usual representation is the left bit to represent blue intensity, the middle - green, and right bit red intensity.

black:   000
red:     001
green:   010
blue:    100
yellow:  011
magenta: 101
cyan:    110
white:   111 

##  Challenge#11

Write a C program that uses `setjmp` and `longjmp` funtions to handle uncoverable program error.
- When error is raised, give back control to main input loop, and start over.
- Create function `error_recovery` that prints error message, and ues `longjmp` to transfer control.
- Main function should have forever loop with 
`setjmp`.
- Dummy error for error_recovery.

## Challenge#12

Use `goto` statement to draw a asterix tree:

## Challenge#13

Chalenges to use different `io` char function.

* Write a program in C to count the numbers of words and characters in a file, 
or input.

this program can take zero command line arguments or one command line argument.
    - if arg => name of file
    - if no arg => use stdin. 

* Write a program in C to uppercase to downcase and vice versa.
    - if arg => name of file
    - if no arg => use stdin. 
    - use temp file to store the converted char.
    - rename temp file to original file.
    - use `isupper(ch)`, `tolower`, `toupper`.

## Challenge#14

Write a C program that takes two command line arguments:
- char
- filename

Print only line in a file that contains the provided as input character.
- define lines in file by `'\n'`
- Asume that no line is more that 256 chars.

Require to use `fgets()` or `getline()` for reading of the file.
-use `puts` for display.

Hello there,
nice to meet you,
have a great day!

example run: `./a.out n test.out` => `nice to meet you,`

# Challenge#15

Write a program that takes as input:
- a set of numbers from a file 
and write even, odd or prime numbers to:
- standart output.

permited fscanf or (fgets and sscanf).