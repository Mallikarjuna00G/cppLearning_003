# Revisit Notes

**NOTE: This is just a notes captured during my revision and does not have consistency but just my understandings and the points I thought of capturing.**

# ch01: Getting Started

- This chapter introduces most of the basic elements of C++: types, variables, expressions, statements, and functions.
- Along the way, we'll briefly explain how to compile and execute a program.
- After having read this chapter and worked through the exercises, you should be able to write, compile, and execute simple programs.


## 1.1 Writing a Simple C++ Program

A simple version of `main` that does nothing but return a value to the operating system:

```cpp
int main() {
    return 0;
}
```

- A function definition has four elements: a return type, a function name, a (possibly empty) parameter list enclosed in parentheses, and a function body.
- The only statement in this block is a `return`, which is a statement that terminates a function.
- When a `return` statement includes a value, the value returned must have a type that is compatible with the return type of the function.

### 1.1.1 Compiling and Executing Our Program

#### Program Source File Naming Convention

Extensions: `.cc`, `.cxx`, `.cpp`, `.cp`, and `.C`.

#### Running the Compiler from the Command Line

The value returned from `main` is accessed in a system-dependent manner. On both UNIX andWindows systems, after executing the program, you must issue an appropriate echo command.
- On UNIX systems, we obtain the status by writing `$ echo $?`
- To see the status on a Windows system, we write `$ echo %ERRORLEVEL%`

## 1.2 A First Look at Input/Output

- Fundamental to the `iostream` library are two types named `istream` and `ostream`, which represent input and output streams, respectively.
- A *stream* is a sequence of characters read from or written to an IO device.

#### Standard Input and Output Objects

- The library defines four IO objects.
- `cin`, `cout`, `cerr`, `clog`.
- To handle *input*, we use an object of type `istream` named `cin` (pronounced see-in). This object is also referred to as the standard input.
- For *output*, we use an `ostream` object named `cout` (pronounced
see-out). This object is also known as the standard output.
- For *warning and error messages*, we use an `ostream` object named `cerr` (pronounced see-err). This object is also known as standard error.
- For *general information about the execution of the program*, we use an `ostream` object named `clog` (pronounced see-log).

- `istream::cin`
- `ostream::cout`
- `ostream::cerr`
- `ostream::clog`

Header: `iostream`

Writing to `ostream`: the output operator `<<`.
- Two operands to this operator.
- Left operand: `ostream` object (`cout`, `cerr` or `clog`)
- Right operand: value to print.
- The output operator returns its first operand (`ostream` object). This helps in chaining.

`std::endl`:
- A special value called manipulator.
- Writing `endl` has the effect of ending the current line and flushing the buffer associated with that device.

> Programmers often add print statements during debugging. Such statements should always flush the stream. Otherwise, if the program crashes, output may be left in the buffer, leading to incorrect inferences about where the program crashed.

Reading from `istream`: the input operator `>>`.
- Two operands to this operator.
- Left operand: `istream` object (`cin`)
- Right operand: object to store the read stream data.
- The input operator returns its first operand (`ostream` object). This helps in chaining.


When we use an **istream as a condition**, the effect is to test the state of the stream. 
- If the stream is valid—that is, if the stream hasn't encountered an error—then the test succeeds. 
- An `istream` becomes invalid when we hit end-of-file or encounter an invalid input, such as reading a value that is not an integer.
- An `istream` that is in an invalid state will cause the condition to yield false.

```cpp
int a;
while(cin >> a;) {

}

// ------
int b;
cin >> b;
if (cin) {

}

```

> ENTERING AN END-OF-FILE FROM THE KEYBOARD  
- On Windows systems we enter an end-of-file by typing a control-z (hold down the Ctrl key and press z) followed by hitting either the Enter or Return key.
- On UNIX systems, including on Mac OS X machines, end-of-file is usually control-d.

# Ch02: Variables and Basic types

## 2.1 Primitive Built-in Types

- C++ defines a set of primitive types that include the *arithmetic types* and a *special type* named `void`.

### 2.1.1 Arithmetic Types

|Type |Meaning |Minimum Size|
|---|---|---|
|bool |boolean |NA|
|char |character |8 bits|
|wchar_t |wide character |16 bits|
|char16_t |Unicode character |16 bits|
|char32_t |Unicode character |32 bits|
|short |short integer |16 bits|
|int |integer |16 bits|
|long |long integer |32 bits|
|long long |long integer |64 bits|
|float |single-precision floating-point |6 significant digits|
|double |double-precision floating-point |10 significant digits|
|long double |extended-precision floating-point |10 significant digits|

#### List Initialization:

- The language defines several different forms of initialization.
- Four different ways to define an `int` variable named `units_sold` and
initialize it to `0`:

```cpp
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```

* `int units_sold = 0;` - **Copy Initialization**
* `int units_sold = {0};` - **List Initialization** (specifically, copy-list initialization)
* `int units_sold{0};` - **List Initialization** (specifically, direct-list initialization)
* `int units_sold(0);` - **Direct Initialization**

- The compiler will not let us list initialize variables of built-in type if the initializer might lead to the loss of information:

```cpp
long double ld = 3.1415926536;
int a{ld}, b = {ld}; // error: narrowing conversion required
int c(ld), d = ld; // ok: but value will be truncated
```

```cpp
char ld = 'A';
int a{ld}, b = {ld}; // ok: wideninng conversion
int c(ld), d = ld; // ok: widening conversion
```

#### Default Initialization

When we define a variable without an initializer, the variable is default initialized.

**Default Initialization**

* **When it occurs:**
    * When a variable is defined **without an explicit initializer**.
    * When an object is created by `new` without an initializer.
    * When an object is created by an implicitly-defined or defaulted default constructor (and no in-class initializer is provided for a member).

* **What it does (behavior depends on type and context):**
    * **Built-in types (e.g., `int`, `double`, pointers):**
        * **Global/Static:** Automatically **zero-initialized**.
        * **Local (automatic storage duration):** Value is **indeterminate** (garbage). Reading this value before assignment results in **undefined behavior**.
    * **Class types:**
        * The class's **default constructor** is called.
        * If the class has no accessible default constructor, it's a **compilation error**.

### 2.2.2 Variable Declarations and Definitions

- A variable declaration specifies the type and name of a variable.
- A variable definition is a declaration. In addition to specifying the name and type, a definition also allocates storage and may provide the variable with an initial value.

- To obtain a declaration that is not also a definition, we add the `extern` keyword and may not provide an explicit initializer:

```cpp
extern int i; // declares but does not define i
int j; // declares and defines j
```

- An extern that has an initializer is a definition:

```cpp
extern double pi = 3.1416; // definition
```

- It is an error to provide an initializer on an extern inside a function.

- Variables must be defined exactly once but can be declared many times.

- To use the same variable in multiple files, we must define that variable in one—and only one—file. Other files that use that variable must declare—but not define—that variable.

### 2.2.3 Identifiers

- The identifiers we define in our own programs may not contain two consecutive underscores, nor can an identifier begin with an underscore followed immediately by an uppercase letter.

## 2.3 Compound Types

- A compound type is a type that is defined in terms of another type.
- C++ has several compound types, two of which are *references* and *pointers*.

### 2.3.1 References

- A reference defines an alternative name for an object.
- A reference type "refers to" another type.
- In other words, a reference is a compound type that "refers to" another type.
- We define a reference type by writing a declarator of the form `&d`, where `d` is the name being declared.

```cpp
int ival = 1024;
int &refVal = ival; // refVal refers to (is another name for) ival
int &refVal2; // error: a reference must be initialized
```

- We bind the reference (`refval`) to its initializer (`ival`).
- There is no way to rebind a reference to refer to a different object.
- References must be initialized.
- **A reference is not an object**. Instead, a reference is just another name for an already existing object. It is an alias.
- Because references are not objects, **we may not define a reference to a reference**.
- The type of the reference must match the type of the object it is going to refer to. There are some exceptions which will be highlighted later.
- A reference may be bound only to an object, not to a literal or to the result of a more general expression. Some exceptions are there which will be discussed later.

### 2.3.2 Pointers

- A pointer is a compound type that “points to” another type.
- Unlike a reference, a pointer is an object in its own right.
- Like other built-in types, pointers defined at block scope have undefined value if they are not initialized.
- We define a pointer type by writing a declarator of the form `*d`, where `d` is the name being defined.
- A pointer holds the address of another object. We get the address of an object by usin the address-of operator (the `&` operator):

```cpp
int ival = 42;
int *p = &ival; // p holds the address of ival; p is a pointer to ival
```

- We may not define a pointer to a reference as they are not objects.
- The type of the pointer and the type of the object it points to shall match. There are some exceptions which we might note down here later.

The value (i.e., the address) stored in a pointer can be in one of four states:
1. It can point to an object.
2. It can point to the location just immediately past the end of an object.
3. It can be a null pointer, indicating that it is not bound to any object.
4. It can be invalid; values other than the preceding three are invalid.

#### Null Pointers.

Header: `cstdlib`

A null pointer does not point to any object. Code can check whether a pointer is null before attempting to use it. There are several ways to obtain a null pointer:

```cpp
int *p1 = nullptr; // equivalent to int *p1 = 0;
int *p2 = 0; // directly initializes p2 from the literal constant 0
// must #include cstdlib
int *p3 = NULL; // equivalent to int *p3 = 0;
```

- It is illegal to assign an `int` variable to a pointer, even if the variable's value happens to be 0.

```cpp
int zero = 0;
pi = zero; // error: cannot assign an int to a pointer
```

#### `void*` Pointers

- The type `void*` is a special pointer type that can hold the address of any object.
- Like any other pointer, a `void*` pointer holds an address, but the type of the object at that address is unknown:

```cpp
double obj = 3.14, *pd = &obj; // ok: void* can hold the address value of any data pointer type
void *pv = &obj; // obj can be an object of any type
pv = pd; // pv can hold a pointer to any type
```

#### References to Pointers

```cpp
int i = 42;
int *p; // p is a pointer to int
int *&r = p; // r is a reference to the pointer p
r = &i; // r refers to a pointer; assigning &i to r makes p point to i
*r = 0; // dereferencing r yields i, the object to which p points; changes i to 0
```

## 2.4 `const` Qualifier

#### By Default, const Objects Are Local to a File

- When a `const` object is initialized from a compile-time constant, such as in our definition of `bufSize`:

```cpp
const int bufSize = 512; // input buffer size
```

the compiler will usually replace uses of the variable with its  corresponding value during compilation. That is, the compiler will generate code using the value 512 in the places that our code uses `bufSize`.

To substitute the value for the variable, the compiler has to see the variable's initializer. When we split a program into multiple files, every file that uses the `const` must have access to its initializer. In order to see the initializer, the variable must be defined in every file that wants to use the variable's value.

To support this usage, yet avoid multiple definitions of the same variable, `const` variables are defined as local to the file. When we define a `const` with the same name in multiple files, it is as if we had written definitions for separate variables in each file.

Sometimes we have a `const` variable that we want to share across multiple files but whose initializer is not a constant expression. In this case, we don't want the compiler to generate a separate variable in each file. Instead, we want the `const` object to behave like other (non`const`) variables. We want to define the `const` in one file, and declare it in the other files that use that object. To define a single instance of a `const` variable, we use the keyword `extern` on both its definition and declaration(s):

```cpp
// file_1.cc defines and initializes a const that is accessible to other files
extern const int bufSize = fcn();
// file_1.h
extern const int bufSize; // same bufSize as defined in file_1.cc
```

In this program, `file_1.cc` defines and initializes `bufSize`. Because this declaration includes an initializer, it is (as usual) a definition. However, because `bufSize` is `const`, we must specify `extern` in order for `bufSize` to be used in other files.

The declaration in `file_1.h` is also `extern`. In this case, the `extern` signifies that `bufSize` is not local to this file and that its definition will occur elsewhere.

### 2.4.1 References to `const`

```cpp
const int ci = 1024;
const int &r1 = ci; // ok: both reference and underlying object are const
r1 = 42; // error: r1 is a reference to const
int &r2 = ci; // error: nonconst reference to a const object
```

- A reference is not an object, so we cannot make a reference itself `const`. Indeed, because there is no way to make a reference refer to a different object, in some sense all references are `const`.

**Two exceptions to the rule that the type of a reference must match the type of the object to which it refers:**

- The first exception is that we can initialize a reference to `const` from any expression that can be converted to the type of the reference. In particular, we can bind a *reference to `const`* to a *nonconst object*, a *literal*, or a more general *expression*:

```cpp
int i = 42;  // plain int object
const int &r1 = i; // ok: r1 is a reference to const. Referring to non-const object
const int &r2 = 42; // ok: r2 is a reference to const. Referring to literal
const int &r3 = r1 * 2; // ok: r3 is a reference to const. Referring to a general expression.
int &r4 = r * 2; // error: r4 is a plain, nonconst reference. trying to refer to expression.
```

**What happens when we bind a reference to an object of a different type?**

```cpp
double dval = 3.14;
const int &ri = dval;
```

Here `ri` refers to an `int`. Operations on `ri` will be integer operations, but `dval` is a floating-point number, not an integer. To ensure that the object to which `ri` is bound is an `int`, the compiler transforms this code into something like

```cpp
const int temp = dval; // create a temporary const int from the double
const int &ri = temp; // bind ri to that temporary
```

In this case, `ri` is bound to a temporary object.

- A **temporary object** is an unnamed object created by the compiler when it needs a place to store a result from evaluating an expression. C++ programmers often use the word temporary as an abbreviation
for temporary object.

- i.e., what is left in the `ri` is just the truncated value of `dval`. And `ri` is no more 

```cpp
#include <iostream>
using namespace std;

int main() {
  double dval = 3.14;
  const int &ri = dval;  // gets truncated value from dval and creates a temporary object and binds with that. Binding with `dval` does not happen.
  
  cout << dval << endl << ri << endl;
  
  dval = 50.43;
  
  cout << dval << endl << ri << endl;
  
  return 0;
}
```

For the above code, the output will be

```console
3.14
3
50.43
3
```

- Results in compilation error when a *reference to non-const* tries to refer to a object of different type.

```console
$ g++ temp.cpp 
temp.cpp: In function ‘int main()':
temp.cpp:7:14: error: cannot bind non-const lvalue reference of type ‘int&' to a value of type ‘double'
    7 |     int &r = d;
      |              ^
```

for the code

```cpp
#include <iostream>

using namespace std;

int main() {
    double d = 3.14;
    int &r = d;

    return 0;
}
```

- A Reference to `const` May Refer to an Object That Is Not `const`
- But we cannot modify the object through the reference while we can directly modify the object.

```cpp
int i = 42;
int &r1 = i; // r1 bound to i
const int &r2 = i; // r2 also bound to i; but cannot be used to change i
r1 = 0; // r1 is not const; i is now 0
r2 = 0; // error: r2 is a reference to const
```

### 2.4.2 Pointers and `const`

- We can define pointers that point to either `const` or non`const` types.

```cpp
const double pi = 3.14; // pi is const; its value may not be changed
double *ptr = &pi; // error: ptr is a plain pointer
const double *cptr = &pi; // ok: cptr is a pointer to const of type double. cptr may point to a double that is const
*cptr = 42; // error: cannot assign to *cptr

double dval = 3.14; // dval is a double; its value can be changed
cptr = &dval; // ok: but can't change dval through cptr
ptr = &dval;  // ok: can change dval throughh ptr
```

#### `const` Pointers

- In other words *constant pointers* (say `int *const p`). Not same as saying *pointer to const* (say `const int *p`).

```cpp
int errNumb = 0;
int *const curErr = &errNumb; // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const object
```

### 2.4.3 Top-Level `const`

- *Top-level `const`* indicates that an object itself is `const`. *Toplevel `const`* can appear in any object type, i.e., one of the built-in *arithmetic types*, a *class type*, or a *pointer type*.

- *Low-level `const`* appears in the *base type* of *compound types* such as *pointers* or *references*. Note that pointer types, unlike most other types, can have both top-level and low-level `const` independently.

```cpp
int i = 0;  // plain object. non-const.
int *const p1 = &i; // we can't change the value of p1; const is top-level. p1 is an object. p1 is constant pointer.
const int ci = 42; // we cannot change ci; const is top-level. ci is an object.
const int *p2 = &ci; // we can change p2; const is low-level. p2 is an objject. p2 is a pointer to const. Hence const is low-level.
const int *const p3 = p2; // right-most const is top-level, left-most is not. p2 is an object. p2 is a "const pointer to const". Hence has both top and low level const.
const int &r = ci; // const in reference types is always low-level. because r is not an object.

i = ci; // ok: copying the value of ci; top-level const in ci is ignored
p2 = p3; // ok: pointed-to type matches; top-level const in p3 is ignored. p2 is pointer to const (low-level const)

int *p1 = p3; // error: p3 has a low-level const but p1 doesn't. p1 is const pointer (top-level const).
p2 = p3; // ok: p2 has the same low-level const qualification as p3
p2 = &i; // ok: we can convert int* to const int*
int &r = ci; // error: can't bind an ordinary int& to a const int object
const int &r2 = i; // ok: can bind const int& to plain int
```

### 2.4.4 `constexpr` and Constant Expressions

- A *constant expression* is an expression whose value cannot change and that can be evaluated at compile time.
- A literal is a *constant expression*.
- A `const` object that is initialized from a *constant expression* is also a *constant expression*.

- Whether a given object (or expression) is a *constant expression* depends on the types and the initializers. For example:

```cpp
const int max_files = 20; // max_files is a constant expression. Because 20 is a literal and const object is being initialized by a literal. And literal is a constant expression.
const int limit = max_files + 1; // limit is a constant expression. max_files is constant expression and 1 is literal (constant expression). Sum of these two constant expressions results in a constant expression. And const object limit is being initialized with that constant expression. So, limit is a constant expression.
int staff_size = 27; // staff_size is not a constant expression. 27 is a literal (constant expression) but that is being assigned to non-const object staff_size. So, staff_size is not a constant expression.
const int sz = get_size(); // sz is not a constant expression. In this vicinity, it is no where mentioned that get_size results to be constant expression, therefore even when its return value is initialized to const object sz, sz is not a constant expression. To put it other way, return value of get_size() is not know until runtime. So it cannot be a constant expression.
```

#### `constexpr` Variables

- There are several contexts in the language that require *constant expressions*. (Recall that "A *constant expression* is an expression whose value cannot change and that can be evaluated at compile time.").
- We can ask the compiler to verify that a variable is a *constant expression* by declaring the variable in a `constexpr` declaration.

- **Why to have this?:** In a large system, it can be difficult to determine (for certain) that an initializer is a *constant expression*. We might define a `const` variable with an initializer that we think is a *constant expression*. However, when we use that variable in a context that requires a *constant expression* we may discover that the initializer was not a *constant expression*. In general, the definition of an object and its use in such a context can be widely separated.

- Variables declared as `constexpr` are implicitly `const` and must be initialized by constant expressions:

```cpp
constexpr int mf = 20; // 20 is a constant expression
constexpr int limit = mf + 1; // mf + 1 is a constant expression
constexpr int sz = size(); // ok only if size is a constexpr function
```

- Although we cannot use an ordinary function as an initializer for a `constexpr` variable, we'll see that the new standard lets us define certain functions as `constexpr`. Such functions must be simple enough that the compiler can evaluate them at compile time. We can use `constexpr` functions in the initializer of a `constexpr` variable.

#### Literal Types

- Because a *constant expression* is one that can be evaluated at compile time, there are limits on the types that we can use in a `constexpr` declaration. The types we can use in a `constexpr` are known as "literal types" because they are simple enough to have literal values.
- Of the types we have used so far, the *arithmetic*, *reference*, and *pointer* types are literal types.
- *User define classes* and the *library IO* and *string* types are not literal types.

- Although we can define both pointers and reference as `constexpr`s, the objects we use to initialize them are strictly limited. 
- - We can initialize a `constexpr` pointer from the `nullptr` literal or the literal (i.e., constant expression) `0`. 
- - We can also point to (or bind to) an object that remains at a fixed address.
- The address of an object defined outside of any function is a constant expression, and so may be used to initialize a `constexpr` pointer.
- Variables defined inside a function ordinarily are not stored at a fixed address.
- Functions may define variables that exist across calls to that function (`static`). These special local objects also have fixed addresses. Therefore, a `constexpr` reference may be bound to, and a `constexpr` pointer may address, such variables.

#### Pointers and `constexpr`

- When we define a pointer in a `constexpr` declaration, the `constexpr` specifier applies to the pointer, not the type to which the pointer points.

```cpp
const int *p = nullptr; // p is a pointer to a const int
constexpr int *q = nullptr; // q is a const pointer to int
```

- `constexpr` imposes a *top-level `const`* on the *objects* it defines.
- Like any other constant pointer, a `constexpr` pointer may point to a `const` or a non`const` type:

```cpp
constexpr int *np = nullptr; // np is a constant pointer to int that is null
int j = 0;
constexpr int i = 42; // type of i is const int
// i and j must be defined outside any function
constexpr const int *p = &i; // p is a constant pointer to the const int i
constexpr int *p1 = &j; // p1 is a constant pointer to the int j. Just to remind j might vary but &j (address of j) will not vary; so it (&j) is a constant expression.
```

## 2.5 Dealing with Types

### 2.5.1 Type Aliases

- A *type alias* is a name that is a synonym for another type.
- Type aliases let us simplify complicated type definitions, making those types easier to use.

- We can define a type alias in one of two ways.
- - Traditionally, we use a `typedef`:

```cpp
typedef double wages; // wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*
```
- - - Declarations that include `typedef` define type aliases rather than variables.
- - The new standard introduced a second way to define a type alias, via an alias declaration:

```cpp
using SI = Sales_item; // SI is a synonym for Sales_item. Sales_item was user define class (struct actually)
```

```cpp
wages hourly, weekly; // same as double hourly, weekly;
SI item; // same as Sales_item item
```

#### Pointers, `const`, and Type Aliases

- Declarations that use type aliases that represent compound types and `const` can yield surprising results.

For example, the following declarations use the type `pstring`, which is an alias for the the type `char*`:

```cpp
typedef char *pstring;
const pstring cstr = 0; // cstr is a constant pointer to char
const pstring *ps; // ps is a pointer to a constant pointer to char
```

- **Wrong way of interpretation:** Substituting `char *` in place of `pstring`. Results in `const char *cstr = 0`. Meaning pointer to const object of type `char`.
- This "textual substitution" approach fails because `typedef` creates a single, new type name, and `const` applies to that entire type.
- **Right way of interpretation:**
- - Identify the type of `pstring`; which is `(char *)`, means *pointer to `char`*. `pstring` is a pointer type, a compound type.
- - Now apply that to `cstr`. So, will be a pointer to `char`.
- - Now apply the `const`ness to the pointer object. That results in *constant pointer to `char`*.
- - Similarly for `ps`. Before evaluating `pstring`, `ps` by itself is a pointer to something. After evaluating `pstring`, `ps` is a *pointer to (type of `pstring`)*. That is `ps` is a *pointer to pointer to `char`*. At the end, apply the `const`ness to the whole object. Which results in *constant pointer to pointer to `const`*.

### 2.5.2 The `auto` Type Specifier

- Under the new standard, we can let the compiler figure out the type for us by using the `auto` type specifier.
- `auto` tells the compiler to deduce the type from the initializer.
- By implication, a variable that uses `auto` as its type specifier must have an initializer.

```cpp
// the type of item is deduced from the type of the result of adding val1 and val2
auto item = val1 + val2; // item initialized to the result of val1 + val2
```

```cpp
auto i = 0, *p = &i; // ok: i is int and p is a pointer to int
auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi
```

#### Compound Types, `const`, and `auto`

- The type that the compiler infers for `auto` is not always exactly the same as the initializer's type. Instead, the compiler adjusts the type to conform to normal initialization rules.

```cpp
int i = 0, &r = i;
auto a = r; // a is an int (r is an alias for i, which has type int)
```

- `auto` ordinarily ignores *top-level `const`*s but keeps *low-level `const`*.

```cpp
const int ci = i, &cr = ci;
auto b = ci; // b is an int (top-level const in ci is dropped)
auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
auto d = &i; // d is an int* (& of an int object is int*)
auto e = &ci; // e is const int* (& of a const object is low-level const)

const auto f = ci; // deduced type of ci is int; f has type const int. `const` is applied to the deduced type.

auto &g = ci; // g is a const int& that is bound to ci
auto &h = 42; // error: we can't bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal

```

- When we ask for a reference to an auto-deduced type, *top-level `const`*s in the initializer are not ignored. Anyway references do not have top-level `const` because they are not objects.

```cpp
auto k = ci, &l = i; // k is int; l is int&
auto &m = ci, *p = &ci; // m is a const int&; p is a pointer to const int

// error: type deduced from i is int; type deduced from &ci is const int
auto &n = i, *p2 = &ci;
```

In the case of,

```cpp
const int ci = 42;
auto e = &ci;
auto *p = &ci;
```

- When `auto` is combined with a **pointer declarator** (`auto *p = expression;`), `auto` deduces the *base type* that the pointer points to. The `*` explicitly tells the compiler that `p` is a pointer. The expression `&ci` is a *pointer to a `const int`*. So, `auto` deduces the *base type* `const int`, and then the `*` applies, making `p` also a `const int*`.

> So, when a pointer declarator (`auto *p = expression;`) is observed, the base type of the initializer is used and the object is made a pointer to that. When a reference declarator (`auto &p = expression;`) is observed, reference is applied to the type of the initializer as seen.

### 2.5.3 The `decltype` Type Specifier

- Sometimes we want to define a variable with a type that the compiler deduces from an expression but do not want to use that expression to initialize the variable.
- For such cases, the new standard introduced a second type specifier, `decltype`, which returns the type of its operand. The compiler analyzes the expression to determine its type but does not evaluate the expression:

```cpp
decltype(f()) sum = x; // sum has whatever type f returns
```

- Here `f` is not called.
- The way `decltype` handles *top-level `const`* and references differs subtly from the way `auto` does.
- `decltype` does not discard the *top-level `const`* and references when returning the deduced type.

```cpp
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x has type const int
decltype(cj) y = x; // y has type const int& and is bound to x
decltype(cj) z; // error: z is a reference and must be initialized
```

#### `decltype` and References

- When we apply `decltype` to an expression that is not a variable, we get the type that that expression yields.
- Some expressions will cause `decltype` to yield a reference type.
- Generally speaking, `decltype` returns a reference type for expressions that yield objects that can stand on the left-hand side of the assignment.

```cpp
// decltype of an expression can be a reference type
int i = 42, *p = &i, &r = i;
decltype(r + 0) b; // ok: addition yields an int; b is an (uninitialized) int
decltype(*p) c; // error: c is int& and must be initialized
```

**Question:**

// decltype of an expression can be a reference type

```cpp
int i = 42, *p = &i, &r = i;
decltype(r + 0) b; // ok: addition yields an int; b is an (uninitialized) int
decltype(*p) c; // error: c is int& and must be initialized
```

Why `decltype(*p) c; is not treated as/deduced to `decltype(42) c;`? Why dereferencing of p did not complete here?

What if I had written `decltype(*p + 4) c;`?

**Answer:**

You're hitting on a very subtle but important rule of `decltype`! It's one of the trickiest parts of C++ type deduction.

The key difference between `decltype` and `auto` is how they handle expressions, particularly when expressions yield references or act as lvalues.

---

**Why `decltype(*p) c;` is not treated as/deduced to `decltype(42) c;`? Why dereferencing of p did not complete here?**

* **`decltype` works on the *expression's type and value category*, not its runtime value.**
    * `decltype` evaluates the *compile-time type* and *value category* of the expression inside its parentheses. It **does not** actually execute the expression or care about the concrete value at runtime (like `42`).
    * The expression `*p` (dereferencing a pointer) results in an **lvalue reference** to the object `p` points to. Since `p` points to `i` (an `int`), `*p` is an expression of type `int` that *refers to* `i`.
    * Therefore, `decltype(*p)` deduces to `int&` (an lvalue reference to an `int`).
    * You are then trying to declare `int& c;` without an initializer, which is illegal because references must always be initialized to bind to an existing object.

* **Contrast with `auto`:**
    * If you had `auto c = *p;`, `auto`'s deduction rules would drop the reference-ness of `*p`. `c` would be deduced as `int`, and initialized with the *value* of `i` (42). `auto` usually deduces a value type.

---

**What if I had written `decltype(*p + 4) c;`?**

Let's break down `decltype(*p + 4) c;`:

1.  **Expression `*p + 4`:**
    * `*p` results in an `int&` (an lvalue reference to `i`).
    * When you perform an arithmetic operation like `+ 4` on an `int&`, the reference is "dereferenced" to its underlying `int` value.
    * The result of `int + int` is an **rvalue** of type `int`. It's a temporary integer value, not a reference to an existing memory location.

2.  **`decltype(*p + 4)`:**
    * Since the expression `*p + 4` yields an rvalue of type `int`, `decltype` deduces its type as `int`.

3.  **`decltype(*p + 4) c;` becomes `int c;`**
    * This is a legal declaration. `c` would be an `int` variable, and because it's a local variable without an explicit initializer, it would be **default-initialized**, meaning it would have an **indeterminate (garbage) value**.

**In Summary of `decltype`'s behavior:**

* **`decltype(var)`:** Returns the exact type of the variable `var`.
* **`decltype(expr)` (where `expr` is an lvalue expression but *not* a variable):** Returns `T&` (a reference to the type `T` of the expression). This happens because lvalue expressions *refer* to an object.
* **`decltype(expr)` (where `expr` is an rvalue expression):** Returns `T` (the plain value type of the expression). Arithmetic operations and function calls that return by value often produce rvalues.
* **Special case for variables:** `decltype((var))` (with extra parentheses) will treat `var` as an lvalue expression, resulting in `T&`. This is why `decltype(i)` is `int`, but `decltype((i))` is `int&`.

**END: answer**

- Another important difference between `decltype` and `auto` is that the deduction done by `decltype` depends on the form of its given expression. What can be confusing is that enclosing the name of a variable in parentheses affects the type returned by `decltype`. When we apply `decltype` to a variable without any parentheses, we get the type of that variable. If we wrap the variable's name in one or more sets of parentheses, the compiler will evaluate the operand as an expression. A variable is an expression that can be the left-hand side of an assignment. As a result, `decltype` on such an expression yields a reference:

```cpp
// decltype of a parenthesized variable is always a reference
decltype((i)) d; // error: d is int& and must be initialized
decltype(i) e; // ok: e is an (uninitialized) int
```

- Remember that `decltype((variable))` (note, double parentheses) is always a reference type, but `decltype(variable)` is a reference type only if variable is a reference.

## 2.6 Defining Our Own Data Structures

#### Class Data Members

- Under the new standard, we can supply an *in-class initializer* for a data member. When we create objects, the *in-class initializer*s will be used to initialize the data members.
- Members without an initializer are *default initialized*.
- *In-class initializer*s are restricted as to the form we can use: They
must either be enclosed inside curly braces (direct/copy list-initialized) or follow an `=` sign (copy initialization). **We may not specify an `in-class initializer` inside parentheses.**

