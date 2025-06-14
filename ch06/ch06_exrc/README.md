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

## ch06_exrc_6p12

Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two `int`s. Which version do you think would be easier to use and why?

Using **references** for swapping two `int`s is generally **easier to use** because:

* **Cleaner Syntax:** You don't need to use the dereference operator (`*`) inside the function; you just use the parameter names directly.
* **Safety:** References cannot be null, which eliminates a common source of bugs (null pointer dereferences) that can occur with pointers.
* **Clarity:** It more closely resembles passing by value while still allowing modification, making the code within the function simpler to read and write.

## ch06_exrc_6p13

Exercise 6.13: Assuming `T` is the name of a type, explain the difference between a function declared as void `f(T)` and `void f(T&)`.

* **`void f(T)`:** `T` is passed **by value**. A **copy** of the argument is made, so changes inside `f` do not affect the original object.
* **`void f(T&)`:** `T` is passed **by reference**. The parameter is an **alias** to the original object, so changes inside `f` **directly modify** the original object.

## ch06_exrc_6p14

Exercise 6.14: Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

* **When a parameter SHOULD be a reference (`T&` or `const T&`):**
    * **To modify the original argument:** Example: `void swap(int& a, int& b)` (to change `a` and `b` in the caller).
    * **To avoid costly copies of large objects:** Example: `void print(const std::string& s)` (to read `s` without copying it).

* **When a parameter SHOULD NOT be a reference (i.e., pass by value `T`):**
    * **When you need an independent copy for internal modification:** Example: `int transform(int x)` (if `x` is modified inside `transform` but the original argument should remain unchanged).
    * **When the type is small and cheap to copy:** For built-in types like `int` or `char`, passing by value (`int add(int a, int b)`) is often just as efficient and clearly shows no modification of the original.

## ch06_exrc_6p15

Exercise 6.15: Explain the rationale for the type of each of `find_char`'s parameters. In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the `char` parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to `const`?

```cpp
// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size(); // position of the first occurrence, if any
    occurs = 0; // set the occurrence count parameter

    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i; // remember the first occurrence of c
            ++occurs; // increment the occurrence count
        }
    }
    
    return ret; // count is returned implicitly in occurs
}
```

Here's a brief explanation:

1.  **`const string &s` (reference to `const` string):**
    * **Rationale:** `string` objects can be large, so passing by **reference (`&`) avoids an expensive copy**. It's `const` because `find_char` only needs to **read** the string, not modify it. This allows the function to work with both `const` and non-`const` `string` objects.

2.  **`string::size_type &occurs` (plain reference to `size_type`):**
    * **Rationale:** `occurs` is used to **return information back to the caller by modifying its value**. Since the function *must* change `occurs` (to count occurrences), it must be a non-`const` reference so its modifications are visible outside the function.

3.  **`char c` (pass by value):**
    * **Rationale:** `char` is a very **small, fundamental type** that is cheap to copy. Passing by value is efficient and clearly indicates that the function will not modify the original character. Using a reference would offer no performance benefit and could even be slightly less efficient for such small types.

4.  **What if `s` was a plain `string &s`?**
    * **Consequence:** The function would **lose flexibility**. It would no longer be able to accept `const string` objects or temporary `string` objects (rvalues) as arguments, only non-`const` lvalue `string`s. This unnecessarily restricts its use as `s` is not modified.

5.  **What if `occurs` was a reference to `const` (`const string::size_type &occurs`)?**
    * **Consequence:** A **compilation error** would occur. The function attempts to assign a value to `occurs` (`occurs = 0;`) and increment it (`++occurs;`). If `occurs` were `const`, these operations would be disallowed, as `const` references cannot be modified.

## ch06_exrc_6p16

Exercise 6.16: The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:

```cpp
bool is_empty(string& s) { return s.empty(); }
```

- We are not modifying the `s` in the function.
- So we can make the parameter as `const`.
- This adds an advantage of capability to receive `const`, non-`const` and literals as arguments.

```cpp
bool is_empty(const string& s) { return s.empty(); }
```

## ch06_exrc_6p17

Exercise 6.17: Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

[ch06_exrc_6p17](./ch06_exrc_6p17/)

Yes. They do have the same types except for the `const`ness. Read the answer for the previous question understand the differences of having `const` in parameter.

## ch06_exrc_6p18

Exercise 6.18: Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.

(a) A function named `compare` that returns a `bool` and has two parameters that are references to a class named `matrix`.

```cpp
bool compare(const matrix &m1, const matrix &m2);
```

(b) A function named `change_val` that returns a `vector<int>` iterator and takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.

```cpp
vector<int>::iterator change_val(int a, vector<int>::iterator it);
```

## ch06_exrc_6p19

Exercise 6.19: Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.

```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```

(a) `calc(23.4, 55.1);`: Illegal. There is only form of `calc` function declared and it accepts only on operand. But this statement is passing two operands.

(b) `count("abcda", 'a');`: Ok. For the first parameter we are passing a string literal and the receiving parameter is a `const` reference to a string. For the second parameter we are passing a character and on the receiving end we have `char` parameter.

(c) `calc(66);`: Ok. The argument is an `int` and the parameter is a `double`. The implicit conversion here is acceptable.

(d) `sum(vec.begin(), vec.end(), 3.8);`: Legal.
- 1st argument matches the 1st parameter
- 2nd argument matches the 2nd parameter
- 3rd argument gets truncated to match the 3rd parameter.

## ch06_exrc_6p20

Exercise 6.20: When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

* **When to use `const` references:**
    * When the function needs to **read** an object but **not modify** it.
    * To **avoid the cost of copying** large objects.
    * To allow the function to accept `const` objects, temporary objects (rvalues), and literals as arguments.

* **What happens if you use a plain reference instead of `const` reference:**
    * **Loss of Flexibility:** The function will be unable to accept `const` objects, temporary objects, or literals as arguments, thus limiting its usability.
    * **Misleading Intent:** It implies that the function *might* modify the argument, even if it doesn't.

