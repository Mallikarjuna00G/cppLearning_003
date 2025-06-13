# ch06_exrc

## ch06_exrc_6p1

Exercise 6.1: What is the difference between a parameter and an argument?

A **parameter** is the name of a variable in a function's declaration. An **argument** is the actual value passed to that parameter when the function is called.

## ch06_exrc_6p2

Exercise 6.2: Indicate which of the following functions are in error and why. Suggest how you might correct the problems.

(a) 

```cpp
int f() {
    string s;
    // . . .
    return s;
}
```

- Problem is with the return type of the function. It is saying it will return `int` but is actually returning `string`.

**Correction:**

```cpp
string f() {
    string s;
    // . . .
    return s;
}
```

(b) 

```cpp
f2(int i) { /* . . . */ }
```

- No return type is mentioned and no return statement is given.
- If the function does not return anything, then it shall explicitly the return type as `void`.

**Correction:**

```cpp
void f2(int i) { /* . . . */ }
```

(c) 

```cpp
int calc(int v1, int v1) /* . . . */ }
```

- Opening brace of the function body is missing.
- More than one parameter with the same name is incorrect.

**Correction:**

```cpp
int calc(int v1, int v2) {/* . . . */ }
```


(d) 

```cpp
double square(double x) return x * x;
```

- Function is missing the braces for the function body.

**Correction:**

```cpp
double square(double x) {return x * x;}
```

## ch06_exrc_6p6

Exercise 6.6: Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.

Here's a brief explanation:

1.  **Parameter:**
    * **Definition:** A variable declared in a function's parameter list. It receives values (arguments) when the function is called.
    * **Lifetime:** Created when the function is called, destroyed when the function exits.
    * **Scope:** Visible only within the function body.
    * **Usefulness:** To pass data into a function from the caller.

2.  **Local Variable:**
    * **Definition:** A variable declared inside a function (or a block within a function).
    * **Lifetime:** Created when its scope is entered, destroyed when its scope is exited.
    * **Scope:** Visible only from its declaration point to the end of its enclosing block.
    * **Usefulness:** To store temporary data needed for computations within the function.

3.  **Local Static Variable:**
    * **Definition:** A local variable declared with the `static` keyword.
    * **Lifetime:** Created only once, when the function is first called and its definition is encountered. It persists and retains its value between function calls.
    * **Scope:** Visible only from its declaration point to the end of its enclosing block (just like a regular local variable).
    * **Usefulness:** To maintain state across multiple calls to the same function while remaining encapsulated within that function.

**Example Function:**

```cpp
#include <iostream>

void exampleFunction(int parameter_val) { // parameter_val is a PARMETER
    int local_var = 10; // local_var is a LOCAL VARIABLE

    static int static_local_var = 0; // static_local_var is a LOCAL STATIC VARIABLE
    static_local_var++; // Increments its value on each call

    std::cout << "Parameter value: " << parameter_val << std::endl;
    std::cout << "Local variable: " << local_var << std::endl;
    std::cout << "Local static variable: " << static_local_var << std::endl;
}

int main() {
    exampleFunction(5);
    exampleFunction(7);
    return 0;
}
```

## ch06_exrc_6p8

[Chapter6.h](./Chapter6.h)

## ch06_exrc_6p9

```bash
g++ -c fact.cpp
g++ -c factMain.cpp
g++ factMain.o fact.o
./a.out
```