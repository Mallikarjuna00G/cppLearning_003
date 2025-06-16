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

## ch06_exrc_6p21

Exercise 6.21: Write a function that takes an `int` and a pointer to an `int` and returns the larger of the `int` value or the value to which the pointer points. What type should you use for the pointer?

[ch06_exrc_6p21](./ch06_exrc_6p21/)

- The type of the pointer shall be `int *`.
- Since we are not going to modify the parameters we are making them `const` parameters.

## ch06_exrc_6p24

Exercise 6.24: Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.

```cpp
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

- First dimension is ignored from the array parameter. So, if the argument array has less than 10 items, we will face a run time error (out-of-range).

- The function should expect the size of the array and accordingly modify the condition statement in the `for `loop.

```cpp
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << endl;
}
```

## ch06_exrc_6p28

Exercise 6.28: In the second version of `error_msg` that has an `ErrCode` parameter, what is the type of `elem` in the `for` loop?

```cpp
void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " " ;
    cout << endl;
}
```

- `elem` is a `const` reference to a `string` element.

## ch06_exrc_6p29

Exercise 6.29: When you use an `initializer_list` in a range `for` would you ever use a reference as the loop control variable? If so, why? If not, why not?

Yes, we would.

**Why:** To **avoid unnecessary copying** of elements. Iterating by `const` reference (`const auto &elem`) is more efficient, especially for large objects like `std::string`, as it prevents a copy from being made for each iteration. Since `initializer_list` elements are always `const`, `const` reference is the only appropriate reference type.

## ch06_exrc_6p30

Exercise 6.30: Compile the version of `str_subrange` as presented on page 223 to see what your compiler does with the indicated errors.

```console
$ g++ -c strSubrange.cpp 
strSubrange.cpp: In function ‘bool str_subrange(const std::string&, const std::string&)':
strSubrange.cpp:18:13: error: return-statement with no value, in function returning ‘bool' [-fpermissive]
   18 |             return; // error #1: no return value; compiler should detect this error
      |             ^~~~~~

```

## ch06_exrc_6p31

Exercise 6.31: When is it valid to return a reference? A reference to `const`?

* **Return `T&` (non-`const` reference):** Valid when returning an **lvalue that will definitely persist** *after* the function returns (e.g., a member of an object passed by reference, an element of a container, or a static/global variable). This allows callers to modify the original object.

* **Return `const T&` (`const` reference):** Valid for returning an **lvalue that will definitely persist** *after* the function returns, but where the caller **should not modify it**. This is common for providing read-only access to members or elements, avoiding copies while maintaining `const`-correctness.

## ch06_exrc_6p32

Exercise 6.32: Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

```cpp
int &get(int *arry, int index) { return arry[index]; }

int main() {
    int ia[10];
    
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

- It is valid.
- The function returns non-`const` reference to each of the index of the array. And then we are assigning `i` value to those positions of the array.
- By the end, the array `ia` will have `{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}`. 

## ch06_exrc_6p34

Exercise 6.34: What would happen if the stopping condition in `factorial` were

```cpp
if (val != 0)
```

`factorial` code was:

```cpp
// calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}
```

- The function will call itself one more time, returning 1 again. But will not go into infinite loop.
- But the only condition is that the parameter shall never be less than 0. If it is, the inifinite looping starts.


## ch06_exrc_6p35

Exercise 6.35: In the call to `factorial`, why did we pass `val - 1` rather than `val--`?

```cpp
// calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}
```

`val - 1` is used because `val--` (postfix decrement) would pass the *original* value of `val` to the recursive call, leading to **infinite recursion**. Using `val - 1` explicitly passes the decremented value without modifying `val` in the same expression, ensuring clarity and correct recursive behavior.

## ch06_exrc_6p36

Exercise 6.36: Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, `decltype`, or a type alias.

```cpp
string (&func())[10];
```

## ch06_exrc_6p37

Exercise 6.37: Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use `decltype`. Which form do you prefer and why?

1. 

```cpp
// reference to an array of ten strings
using strRef = string (&)[10];

strRef func();
```

2. 

```cpp
auto func() -> string (&)[10];
```

3. 

```cpp
string s[10];
string (&sr)[10] = s;

decltype(sr) func();
```

I think I prefer type alias because for me it is easier to grasp.

## ch06_exrc_6p38

Exercise 6.38: Revise the `arrPtr` function on to return a reference to the array.

Given code:

```cpp
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even; // returns a pointer to the array
}
```

Changed:

```cpp
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

// returns a reference to an array of five int elements
decltype(odd) &arrPtr(int i)
{
    return (i % 2) ? odd : even; // returns a reference to the array
}
```

## ch06_exrc_6p39

Exercise 6.39: Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

(a) 

```cpp
int calc(int, int);
int calc(const int, const int);
```

- Top level `const` on objects do not create overloading. These two declarations are same.

(b) 

```cpp
int get();
double get();
```

- This results in compilation error. Function overloading is not possible just with difference in the return type.

(c) 

```cpp
int *reset(int *);
double *reset(double *);
```

- OK. Parameters are different.

## ch06_exrc_6p40

Exercise 6.40: Which, if either, of the following declarations are errors? Why?

(a) 

```cpp
int ff(int a, int b = 0, int c = 0);
```

- This is fine.

(b) 

```cpp
char *init(int ht = 24, int wd, char bckgrnd);
```

- Error. default arguments shall always come at the end in the argument list.

## ch06_exrc_6p41

Exercise 6.41: Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer's intent? Why?

```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');
```

(a) `init();`

- Incorrect. First argument is not a default argument. So atleast one arguments shall be passed.

(b) `init(24,10);`

- Fine. It will be called as `init(24, 10, ' ');`

(c) `init(14, '*');`

- Will not throw any error but might not match the intent of the programmer.
- It will be called as `init(14, '*', ' ');`. The second argument that is being passed undergoes conversion to `int`. And it will be a valid conversion.

## ch06_exrc_6p42

Exercise 6.42: Give the second parameter of `make_plural` (§ 6.3.2, p. 224) a default argument of `'s'`. Test your program by printing singular and plural versions of the words `success` and `failure`.

```cpp
// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
```

[ch06_exrc_6p42](./ch06_exrc_6p42/)

## ch06_exrc_6p43

Exercise 6.43: Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.

(a) `inline bool eq(const BigInt&, const BigInt&) {...}`

- It is an `inline` function. Place in header file.
- This way the expansion during the preprocessing is done without much issues; if the `inline` function undergoes expansion.

(b) `void putValues(int *arr, int size);`

- It is a function prototype. Shall go in header file.
- Needs to go in header files because other files need the blueprint of the function.

## ch06_exrc_6p44

Exercise 6.44: Rewrite the `isShorter` function from § 6.2.2 (p. 211) to be `inline`.

Given code:

```cpp
// compare the length of two strings
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

Modified: 

```cpp
// compare the length of two strings
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

## ch06_exrc_6p45

Exercise 6.45: Review the programs you've written for the earlier exercises and decide whether they should be defined as `inline`. If so, do so. If not, explain why they should not be `inline`.

- **Skipping this task to save time**
- Any function that is smaller in size (say not more than 5 lines); shall be an `inline`.
- Any function that is smaller in size and is called large number of times; shall be an `inline`.
- Any function that is smaller in size and are recursive but only go a smaller depth of recursion; shall be an `inline`.

## ch06_exrc_6p46

Exercise 6.46: Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

Given code:

```cpp
// compare the length of two strings
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

- No.
- Size of the passed strings might vary.
- `std::string::size()` is not a `constexpr` member function.

## ch06_exrc_6p48

Exercise 6.48: Explain what this loop does and whether it is a good use of `assert`:

```cpp
string s;
while (cin >> s && s != sought) { } // empty body
assert(cin);
```

The loop `while (cin >> s && s != sought) { }` continues to read words from `cin` until either an end-of-file (EOF) or invalid input occurs (making `cin >> s` false), or until the word read (`s`) is equal to `sought`.

The `assert(cin);` statement checks the state of `cin` *after* the loop terminates.
* If the loop terminated because `s == sought` (meaning `s != sought` became false), then `cin` would still be in a good state, `assert(cin)` would evaluate `assert(true)`, and the program would continue.
* However, if the loop terminated because `cin >> s` failed (e.g., due to EOF or a non-matching input error), then `cin` would be in a failed state. In a boolean context, a failed `cin` evaluates to `false`. Therefore, `assert(cin)` would evaluate `assert(false)`, which would cause the program to **terminate** (in debug builds).

This `assert` is **not a good use** because `cin` failing is a common and expected scenario for input operations. Assertions are for conditions that indicate a programming bug or an impossible state, not for expected runtime conditions that should be handled gracefully. A more appropriate way to check `cin`'s state would be using an `if` statement or a regular conditional check, allowing the program to respond appropriately (e.g., print an error message, exit cleanly, or retry input) rather than crashing.

## ch06_exrc_6p49

Exercise 6.49: What is a candidate function? What is a viable function?

**Candidate Function:** A function is a **candidate** if its name matches the function being called and it's visible at the point of the call.

**Viable Function:** From the set of candidate functions, a function is **viable** if:
1.  It has the same number of parameters as the arguments in the call, or it can be called with the given arguments after considering default arguments.
2.  The type of each argument can be converted to the type of its corresponding parameter.

## ch06_exrc_6p50

Exercise 6.50: Given the declarations for `f` from page 242, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.

(a) f(2.56, 42) (b) f(42) (c) f(42, 0) (d) f(2.56, 3.14)

The given candidates:

```cpp
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
```

(a) `f(2.56, 42)`:

- Candidates 3 and 4 are viable functions.
- But the call is **ambiguous**.

 (b) `f(42)`
 
 - Candidates 2 and 4 are viable functions
 - 2 is the best match.
 
 (c) `f(42, 0)`
 
 - Candidates 3 and 4 are the viable functions.
 - Candidate 3 is the best option.

(d) `f(2.56, 3.14)`

- Candidates 3 and 4 are the viable functions.
- Candidate 4 is the best match.

## ch06_exrc_6p51

Exercise 6.51: Write all four versions of `f`. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

[ch06_exrc_6p51](./ch06_exrc_6p51/)

```console
g++ -Wall -std=c++11 -g -O0 -c main.cpp
main.cpp: In function ‘int main()':
main.cpp:8:6: error: call of overloaded ‘f(double, int)' is ambiguous
    8 |     f(2.56, 42);
      |     ~^~~~~~~~~~
In file included from main.cpp:2:
functionMatch.hpp:3:6: note: candidate: ‘void f(int, int)'
    3 | void f(int, int);
      |      ^
functionMatch.hpp:4:6: note: candidate: ‘void f(double, double)'
    4 | void f(double, double = 3.14);
      |      ^
make: *** [Makefile:32: main.o] Error 1
```

- Now commenting the fist call `f(2.56, 42);`.

```console
$ make run
./a.out
I am in function: f(int)
I am in function: f(int, int)
I am in function: f(double, double = 3.14)
```

## ch06_exrc_6p52

Exercise 6.52: Given the following declarations, 

```cpp
void manip(int, int);
double dobj;
```

what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?

(a) `manip('a', 'z');` (b) `manip(55.4, dobj);`

Conversions are ranked as follows:
1. An exact match. An exact match happens when:
- The argument and parameter types are identical.
- The argument is converted from an array or function type to the corresponding pointer type.
- A top-level `const` is added to or discarded from the argument.
2. Match through a `const` conversion.
3. Match through a promotion.
4. Match through an arithmetic or pointer conversion.
5. Match through a class-type conversion.

(a) `manip('a', 'z');` 

- The rank is 3 (Match through a promotion). Both the arguments are converted to `int`.

(b) `manip(55.4, dobj);`

- Rank 5. Match through an arithmetic conversion.

## ch06_exrc_6p53

Exercise 6.53: Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

(a) 

```cpp
int calc(int&, int&);
int calc(const int&, const int&);
```

- Based on the rule, "`const`ness on pointers or references do contribute in function overloading", the given two declarations are different.
- When the `const` arguments are used, the second function is called.
- When the non-`const` arguments are used, both the functions are viable but due to exact matching, first function is called.

(b) 

```cpp
int calc(char*, char*);
int calc(const char*, const char*);
```

- Based on the rule, "`const`ness on pointers or references do contribute in function overloading", the given two declarations are different.
- When the `const` arguments are used, the second function is called.
- When the non-`const` arguments are used, both the functions are viable but due to exact matching, first function is called.


(c) 

```cpp
int calc(char*, char*);
int calc(char* const, char* const);
```

- Since, top level `const` cannot contribute for function overloading, these two declarations are essentially the same.

## ch06_exrc_6p54

Exercise 6.54: Write a declaration for a function that takes two `int` parameters and returns an `int`, and declare a `vector` whose elements have this function pointer type.

```cpp
int func(int, int);
typedef decltype(func) *fp;

vector<fp> vfp;
```

OR 

```cpp
int func(int, int);
using fp = int(*)(int, int); // fp is a pointer to a function that takes two ints and returns an int

std::vector<fp> vfp;
```

## ch06_exrc_6p55

Exercise 6.55: Write four functions that add, subtract, multiply, and divide two `int` values. Store pointers to these functions in your vector from the previous exercise.

**NOTE: Check solution given for ch06_exrc_6p56**