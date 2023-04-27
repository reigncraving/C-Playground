# C practice. 
This repository will hold any projects related to `C Programming language` exercise,
and related environment for compiling and debuging. It will include all 
example C programms.

## C Language specifics

C provides 3 storage classes:

1. Auto
2. Register
3. Extern
4. Static

- `Register` is small set of data, taking place that is part of the  CPU
It can hold instructions, storage address, and any kind of data.
It is used to define local variables that should be stored in a register,
instead of RAM. This make the `Register` much faster than normal variables. It 
is `only` used with local variables.

  Good use of the `Register storage class` is when a variable gets used all the0 
  time in a program, and this will make it even faster. But this is a 
  compiler's choice whether to store marked variable, and some time the 
  compiler puts there variables for optimization automaticaly.

  When added variable scope is local to the block it's defined, the size
  is equal to the registry size, and you cannot obtain address inside of the
  `register`, nor have the unary '&' operator applyed to that variable, because 
  it does not have memory location.

  ```C
  register int x;
  ```

- `External variables` - Functions in different files can communicate through
them => extension of the concept for `global variables`. `External Variables` can
be changed by a function in separate file => /mnt/e/C/C-Playground/project1a 
globally defined variable from another file. Prefixed with `extern`. To use it
must be declared as signature, mustnot be initialized. Variable needs to be
global to be used as extern.

  ```
    <file1 int n = 3> <== <file2 extern int n;>
  ```

  **file2 is the one accessing it, so the extern is palced there.
  Functions declared as `extern` can be accessed in any file in program, and it
  does not need to be defined (since it's defined in eternal file) in the header 
  of the file caller. Any variable defined outside of block or function is 
  considered `external` by default.

- `Static variables` - When a variable needs to be defined as global but not
external ( not available outside of the file). The static declaration more 
accurately reflects the viarble usage (no conflicts). Prefixed with `static`.

  Applied to `local varibles` => Tells compiler to keep the var during the life
  time of a program Preserve the state from last execution run, and no new memory
  will allocated for them on later calls. Scope is local for where they are
  declared. These variable are alocated on the
  `heap` not on the `stack`.

  Applied to `global variable` => Variable in scope only for current file.

  Applied to `function` => Same file only execution and call.

  `Static variable` should not be declared in the body of `structures`.

- `Auto variable` - exist only in block they are created, destroyed on scope change.
Keyworld is not used, also conflicts with C++. 

- `Local variables` -exist in functions bodies or block code. All variables of this
type have `automatic` storage by default, word auto is not used explicitly. No access 
from another functions => local scope.

### placeholders

- `%c`   => char
- `%i`   => interger
- `%lld` => long long
- `%lf`  => long precision floating-point value (double)
- `%f`   => single precision floating-point value (float)
- `%zd`  => size_t (unsigned long)
- `%s`   => string (null terminated, array of chars)

## Typedef

Makes the program more readable by defining own name for exising data type. 
`typedef int Number;`, `typedef int* i_pointer;`

This will make the name Number to be equal to `int` type => Creating an `alias`. The compiler will treat this as normal integer, this makes the program more readable.

Good example use is to cover the 4-byte system integer, some system use `long` for example and typdef can be changed once in the program based on the system and will update all instances.

The `typedef` is handled by the `compiler`.

common practices:
- Do not use `typedef` with structs. (only hides `struct` word)
- Use it for portable types.

typedef vs define

typedef is handle by the compiler and is good for typecheking, but define could replace typedef as well, depends on the case. The precompiler is good for cheking if header already exists before defining a constant. 
`#define` will replace every instance of the keyword in the file were as `typedef` is more of a alias.

The advantage of using typedef with pointers is that we can declare any number of pointers in a single statement

```C
typedef int* int_pointer;
int_pointer = a, b, c;
```

## Define (Preprocessor)

`Define` statement (constants) is a preprocessor directive, ( like all other preprocessor directives ) begins with `#`.
 - Can be preceded by spaces and tabs.
 - Allows for space between `#` and following part.

good example is the `#include` preprocessor directive.

`Define` is used to define `symbolic` or `manifest` `constants` in a program.
- directives run untill the first newline following the `#`.
- Name consists of only uppercase latters and underscores.

example of defining a constant:

```C
#define OK 1
```
Anywhere in the code the name `OK` will return 1. Preprocessor makes replacement of all calls to the constant. Easy to maintain as one place to change the defined value.

another way of creating constants is by using the keywokd `consts` on variables.

## Variable Length Array (VLA)

Array taking expression when created, still fixed in size. It means you can use variable when specifying `array dimentions` when first creating the array.

`size_t` - data type return from `sizeof` operator.

```C
#include <stdio.h>

int main(void) {

  size_t size = 3;
  /* not supported in c89 */
  float arr[size];


  return 0;
}

```
To use this feature with support `__STDC_NO_VLA__` symbol must be defined as 1

```c
#ifdef __STDC_NO_VLA__
  printf("VLA not supporterd");
  exit(1);
#endif
```
note: Linux cores do not used VLAs ( considered slow and fragile. )

Avoid VLAs as function variables, instead use `pointers` and `allocations`.

## Flexible Array Members

Feature form `c99` standard, it features a dynamic array dimensions inside of 
`struct`. Flexible array member's size can be changed at runtime.

example: 
```C
struct s {
  int arraySize;
  int array[]; // flexible array memeber
}; 

/*Allocation: */
  /*...*/
  int desiredSize = 5;
  /* structure pointer => structure named s */
  struct s *ptr; 

  /* 
  *
  * allocate size of one struct size for all members and 
  * desiredSize is allocation for the flexible array member
  * how many elements will that array hold.
  */
  ptr = malloc( sizeof( struct s ) + desiredSize * sizeof ( int ) );
  /*...*/
```
a flexible array is declared by empty square brakets `[]`. Flexible array must be
declared only as `last member` of the struct, and there must at least one more 
member ( cannot be only member ). Flexible array cannot be member of another struct.
Struct with flexible array cannot be statically initialized => allocated dynamically 
only, cannot fix the size of the array at compile time.

Its debatable whether is good practice or not, someconsider it not portable (c99).

## Complex Number Types

`Complex number` is a number of form: `a + bi`
- `i` is the square root of minus one;
- `a` and `b` are real numbers;

`a` is the real part, while `bi` is the imaginary part of the complex number

operations: 

- `modulus` of complex number `a + bi is `√(a^2 + b^2)`;
- `equality`` a + bi` is eq to `c + di` if `a` == `c` && `b` == `d`;
- `audition` sum of complex numbers `a + bi` and `c +di` is `(a + c) + (b +d)i`;
- `multiplication` the product of the complex numbers `a + bi` and `c + di` is
  `(ac - bd) + (ad + bd)i`
- `division` the result of dividing `a + bi` by `c + di` is
  `(ac + bd) / (c^2 + d^2) +((bc - ad) / (c^2 + d^2))`;
- `conjugate` `a + bi` => `a - bi`;

`C99` standart introduces support for complex numbers. `C11` is not obliged, it's 
optional.

guard: 

```C
#ifdef __STDC_NO_COMPLEX__
  printf("Complex numbers are supported");
  exit(1);
#else
  printf("Complex numbers are not supporterd");
#endif
```
types in C: 

`float _Complex` => stores complex number with real and imaginery part as type float.
`double _Complex`, `long_double_Complex`,

`float _Imaginery` => stores imaginery number as float
`double _Imaginery`

`_Complex` => keyword is like `_Bool` to avoid braking existing code.

header `complex.h`

Functions:

`creal()` => returns the real part of number;
`cimag()` => returns the imaginery part of the number;

## Designated Initializers

Allow for specifying of which element of `array`, `struct` or `union` are to be 
initialized by the values following an array index or filed by name ( struct and union only)

Useful for struct with large number of fields, to be used with 
default elements set to values.

```C
int a[3] = { [1] = 23, [2] = 15 };
/* or */
int a[3] = { [1]23, [2]15 };
/* range [first...last] = value */
int a[] = { [0...10] = 1 };

/* struct */
struct point { int x, y; };

struct point p = { .y = 2, .x = 3}; 
/* or */
struct point p = { .y: 2, .x: 3}; 
/* or withoud specifying the fields */
struct point p = { 2, 3 }; 
/* with array of points */
struct point p[3] = { [0].x = 3, [2].y = 3 };

```

## Type Qualifiers

Type qualifiers are used infront of variable to tell the compiler more about the
intended use of the variable.

- `const` - variable value won't be change through program life time. The     compiler will place that variable into read-only memory(compiler optimization).

```C
/* with pointers :*/
int * const ptr; // constant pointer address cannot change.
const int *ptr; // value pointed to must remain constant.
const int * const *ptr; // both constants, pointer + value.

/* passing const as parameter to function: */
void print(const int array[], int size) {}; // can't change data to which array poinst.

/* adds a copy of the second param to the end of first param */
char *strcat(char *restict s1, const char * restrict s2); // second param won't be changed it's const.

/* in header files const can get included in differen files.*/
static const double pi = 3.14159; // with static each file gets copy of the data.
```
define vs const. #define is preprocessor directive and it is not scope controlled,
where const is a as regular variable, it can be typecast, has scope ( function scope, global scope).
the use of `const` also allow for type checking by the compiler (vs precompiler).

- `volatile` - (compiler optimization) specifies to compiler that this variable will change it's value.
opposite to `const`. This will optimize the compiler not to cache the value => Not to optimize it.
Used on embeded systems, or where resources are scarse. Using `volatile` tells the
compiler not to optimize for the use of `registry` as faster memory (caching).

Three types od variable should use `volatile`:
 1. memory-mapped peripheral registers
 2. global variables ( non stack )
 3. global variables accessed by multiple tasks in multi-threaded app

```C
volatile int var // var is volatile
volatile int *ptr // points to volatile address

/* 
* do not change in program, allow for storage in memory to be 
* access by other processes.
*/
const volatile int *loc 
```
- `restrict` - (Compiler optimization) The compiler can choose to ignore it, used
with pointer, and it tells the compiler that a pointer is the only refence to 
a certain value. The compiler won't do additional optimization between declaration 
and usage of said pointer. Not supported in `C++`.

```C
int * restrict ptr 
```

`C99` standart adde new ones:

-`constancy`
-`volatility`

## Bit Manipulations

### Bitwise operators

`word` => two `bytes`

bit manipulation is algorithmically manipulation bits of data shorter than a `word`.
Bitwise manipulations are faster than calculations.

fields of use:
- low-level device control
- error detection
- correction algorithms
- data compression
- encryption algorithms
- optimization

C supports:

- `&` - Binary `AND` operator copies bit if it exist in both operands
- `|` - Binary `OR` operator copies a bit if it exist in either operand
- `^` - Binary `XOR` operator copies a bit if it is set in one operand but not both.
- `~` - Binary `Ones Compliment Operator` is unary and has the effect of `flipping`bits. `Bitwise Negation operator`. (adds +1)

This operator operates on bits individually and not on values as compared to 
logical operators (&&, ||, !).

```C
    /* bitwise operation: */
  

    /* Manual AND: if 1 and 1 => 1    */
    /* if 0 and 1 => 0                */
    /* 25 in binary: 0000000000011001 */
    /* 77 in binary: 0000000001001101 */
    /* ------------------------------ */
    /*  9            0000000000001001 */

    /* Manual OR: if there is 1 in either => 1 */
    /* 147 in binary: 10010011        */
    /* 61 in binary:  00111101        */
    /* ------------------------------ */
    /* 191            10111111        */

    /* Manual XOR: if there is 1 in one but not both => 1 */
    /* 147 in binary: 10010011        */
    /* 61 in binary:  00111101        */
    /* ------------------------------ */
    /* 174            10101110        */

    /* Comliment: flip the bits       */
    /* 154 in binary: 10011010        */
    /* ------------------------------ */
    /* 174            01100101        */
    /* in twos compilent eq -155:     */
    /* 155 in binary  10011011 +1     */
    /* take possive and add 1         */

    short int w1;

    w1 &= ~1;

    /* w1 is ANDed with the correct value in any machine b/c the ones 
    compliment of 1 is calculated and consist of as many leftmost bits as 
    necessary to fill the size of an int (31 lefmost bits on 32-bit integer
    sytem).*/
   
    short int temp = 0;
    short int n1 = 10;
    short int n2 = 12;

    /* swap */
    temp =  n1;
    n1 = n2;
    n2 = temp;

    /* do not need temp variable */
    n1 ^= n2;
    n2 ^= n1;

```
### Shifting

Each of the shifting operators creates new value by shifting accordingly bits in a pattern indicated number of bits.

- `<<` `left-shift` operator. Vacated (empty) bits are set to 0;
- `>>` `right-shift` operator. Vacated (empty) bits are set to 0 if value is unsigned.

```C
    /* integer in most system is represented by 32 bits. */
    int i = 1;
    /* 0000 0000 0000 0000 0000 0000 0000 0001 */

    int i1 = 3;
    /* 0000 0000 0000 0000 0000 0000 0000 0011 */

    int result = 0;

    result = i1 << 1;
    /* shift by one                            */
    /* 0000 0000 0000 0000 0000 0000 0000 0110 */
```

### Bitmasks

`Bitmask` is data that is used for bitwise operations, using a mask, multiple bits
in a `Byte` can be set either on or off, or inverted from on to off, in a single
bitwise operation. It can be used for state manage as 32 bit state management.

- check if particular bit is set to on or off.
- set bit on of off.
- must be as wide as the bytes to mask.

Turning bits off:

```C
int const MASK = 2; // 00000010
int flags = 12; 

flags = flags & MASK;

/* This will make all of the bits of number to be set to 0, except for the 1 bit
in the mask.*/

```
- any bit combined with `0` using `&` will yeild `0`, `1` will be unchained: 
  1 & 1 => 1;
  0 & 1 => 0;
  0 & 0 => 0;


Turning bits on:

```C
flags = flags | MASK;
```
sets number 1 in flags to 1 and leaves all the other bits unchanged.
  any bit combined with 0 by `|` returns itself.
  any bit combined with 1 by `|` returns 1.


turning bits off using AND:

```C
flags = flags &~MASK;
```
- a 1 combined with any bit using `&` is the same bit. This leaves all bits other
than 1 unchanged. A bit 0 combined with any but using `&` is 0,bit 1 is set to 0.

Toggling bits with XOR:

turning it on if it's off and turning it on if it's off.

```C
flags = flags ^ MASK;
```

Check a value of a bit:

```C
if ((flags & MASK) == MASK) {
  puts ("True");
}
```

### Pack Data:

Flags of a state can be represented by turning on and off a single bit. 

Two methods are available to pack this information together to make better use of memory
(instead of using Boolean for example).

- `Bit fields` - struct
- `Bitwise operators` - variable

#### using Bitwise operators: 

Unsigned int / long varaible is used to hold the information, or a structure the
same size as the unsigned int to hold the state.


example:
One integer variable could hold five different values:
  - 3 flags (f1, f2, f3);
  - type (integer) 1..255
  - index (integer) 0..100_000

```C
unsigned int packed_data;
```
packed_data => 32 bits:

```

  3   1  1  1      8             18
[000][0][0][0][00000000][000000000000000000]
  |   |  |  |      |              |
  |   f1 f2 f3    type           index
unsused 
```

```C
/* to set type field of packed_data to 8, when type field is 0*/
int n = 8; 
packed_data |= n << 18;

/* make type field ot 0 */

packed_data &=~(0xff << 18);

/* Set the type field of packed_data to value contained in the eight low-order bits of n: */
packed_data = (packed_data &~(0xff << 18)) | ((n & 0xff) << 18);

```

#### Reading values from bit fields:

To read type field of above example: 

```C
n = (packed_data >> 18) & 0xff;
```

representing color values with unsigned long:

```C
#define BYTE_MASK 0xff

unsigned long color = 0x002a162f;
unsigned char blue, green, red;

red = color & BYTE_MASK;
green = (color >> 8) & BYTE_MASK;
blue = (color >> 16) & BYTE_MASK;
```

### Bitfields

Use bitfields in a `struct`, and this fields will represent individual
or group of bits in a value. A bit field allows for specifying the number of bits in which an int member of a structure is stored.
It uses a special syntax for defining field of bits, and should use
explicit declaration of int (singned or unsigned) to avoid hardware problems. It is declared by following and unsgined int member name with a colon `:`. Integer constant is defined after the colon and represents the width of the field (number of bits starts from 0). a `bitfield` is accesed as any other member of a structure.

It is possible to define an unnamed bit field to be used for padding in the struct. 

```C
unsigned int : 1;
```

An unnamed bit field with 0 width is used to align the next
bitfield on a new storage unit boundary.

```C
unsigned int : 0;
```

`C99` and `C11` allow type `_Bool` as bit field.

## Advanced Control flows

### Goto

`goto` makes the program jump to a peticular line of code. To know where
to jump a `label` is made with variable name conventions. The label need
to be palced directlu before the statement to wich a new branch is to be
made, and must appear in the same function as `goto`.

syntax: 

```C
goto label;
/*...*/
label : statement
```

```C
int test(void) {
  goto print;
  /*..*/
  print: printf("Jumped here!");
  /*...*/
}

```

It is not considered as best practice, and and can make code hard to read.

Useful usage is when a break is needed from nested loop:

```C
int i, j, k = 0;

for(i = 0; i < 10; i++) {
  for(i = 0; i < 10; i++) {
    for(i = 0; i < 10; i++) {
      /*...*/
      if (condition) {
        goto loop_break;
      }
       /*...*/ 
    }
  }
}

loop_break: 
/*...*/ 
```
### Null statement:

The `null statement` is expression with the expression missing;
It does nothing it represents nothing. Often used in loops (for, while,do).

C allows for use of `;`. 

```C
while (condition) 
;

for ( ;(c = getchar()) != EOF; putchar (c) );

/* counts chars in input */
for ( count = 0; getchar() != EOF; ++count ) 

/* go to outer else */
if (condition) {
  if (condition) {
    /*...*/ 
    else
    ;
  else
  /*...*/ 
  }
}

```
Without the null statement the compiler takes the next in line as body of the loop.
That is why the null statement is needed.

### Comma operator:

`,` => lowest precedence in C, binary operator used in expresions. All operators in C produce valie,
the value of comma operator is the rightmost expression.

```C
/* in a loop: */
int sum+= arr[i], ++i;

/* 1 is assigned to i, 3 is discarded*/
int i(3, 1);

for ( i = 0, j = 0; i < 10, i++, j++) { /*...*/ }

char c, d;
int x = 1, y = 3;

```

### setjmp and longjump:

`setjmp()` and `longjump()` functions perform more complex control flow. Normal 
flow in C consist of function calls and branching operators (if, while, do).

These functions are mainly used as error handling, and recovery in C.
- `setjmp` is like `try`, `begin`. Copies program counter, and the current pointer
of the top of the `stack`.

```C
/* j saves current context, needs to be called first. */
int setjmp(jmp_buf j);
```
- `longjmp` is used as `throw`. Invoked after `setjmp` and goes to the place where
`setjmp` is saved, destroying the variable holding the state (`j`) and restores the
process state, as it was.

This is refered as `unwinding the stack`.

```C
#include <setjmp.h>
#include <stdio.h>

/* set the buffer */
jmp_buf buffer;


int main(void) {
    /* on the return i is set to 22 in longjmp */
    int i = setjmp(buffer);
    printf("i=%d\n", i);

    /* Exit not to cause infinite loop */
    if ( i != 0 ) exit(0);

    /* The return value of longjmp sets the i */
    longjmp(buffer, 22);
    printf("Test line, should not be printed\n");\

    return 0;
}
```

The `<setjmp.h>` header file is required to use `setjmp` or `longjmp`.
Good use of this functions is to use them to bubble up error deeply nested in function
calls to a upper level function, that will handle it. It's like `goto` but unlike it 
it, it  can be used between functions and files.




## Compile:

Compiler generates intermediate object files for each source it compiles. 
(file.o for windows file.obj)
```
basic flags: 
-c => compile do not link
-o => object file
```
Replacing the `'c'` extension of the `'o'` for object file passed to compiler will 
tells it to use the object files instead (already compiled ones).This could be 
used with compilers that do not delete the object files.

An `object file` is the real output from the compilation phase. It's mostly machine 
code, but has info that allows a linker to see what symbols are in it as well as 
symbols it requires in order to work. (For reference, "symbols" are basically 
names of global objects, functions, etc.) 

A `linker` takes all these object files and combines them to form one executable 
(assuming that it can, i.e.: that there aren't any duplicate or undefined symbols). 
A lot of compilers will do this for you (they run the linker on their own) 
if you don't tell them to "just compile" using command-line options. 

Most compilers and IDEs are smart enough to re-compile only changed files or
the one without object file.

```
gcc compile -c mod1.o mod2.o -o test
```

Compile multiple sources:

```
gcc <file or files> -o <executable object file>
```

Incremental compilation technique:

```
gcc -c mod1.c  # compiles mod1.c => mod1.o
gcc -c mod2.c  # compiles mod2.c => mod2.o
gcc -c mod3.c  # compiles mod3.c => mod3.o
```

custom script:
```shell
./build/compile.h helloworld/helloworld.c
```
with multiple files:

```
./build/compile.sh project1/sources/project1.c project1/sources/favorite_number.c 

```
when compiling multiple files the compiler compiles them independently, it does
not know of each structure, function return types, arguments. There need to be
a specification for the compiler to use.

## Make

Make is a utility that specifies a list of files and their dependencies in a
special file => `Makefile`

The make program automatically recompiles files only when necessary
- based on the modification times of a file.
- If `.c` file is newer than `.o` file it will re-compile it. (don't have to
  delete the object files to re-compile)
- You can specify source files that depend on header files (dependencies)

Example Makefile:

```
SRC = mod1.c mod2.c main.c

OBJ = mod1.o mod2.o main.o

# what to compile (name, $(PROG) => ENV variable)
PROG=myProgram$(PROG):$(OBJ)
# must be written with leading tab:
    gcc $(OBJ) -o $(PROG)

# Last line in Makefile declares depended files:
# each object file depends ont it's corresponding source file and
# if source file changes, the object file must be rebuilt
$(OBJ):$(SRC)
```

run make:
```
make
```

Make  will compile each file individually and link in the end.

## debug

`.vscode/launch.json` = script to laung debug on brake point in vscode using `gdb`

## C Coding Standard

https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html
