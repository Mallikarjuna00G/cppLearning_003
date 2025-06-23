# Revisit Notes

**NOTE: This is just a notes captured during my revision and does not have consistency but just my understandings and the points I thought of capturing.**

# ch05: Statements

Like most languages, C++ provides statements for conditional execution, loops that repeatedly execute the same body of code, and jump statements that interrupt the flow of control. This chapter looks in detail at the statements supported by C++.

## 5.6 try Blocks and Exception Handling

* **Exceptions:** Run-time anomalies (e.g., lost database connection, invalid input) that disrupt normal program flow.
* **Purpose of Exception Handling:** To signal and manage unresolvable problems detected by one part of a program to another part, allowing the detecting part to stop processing while the handling part addresses the issue.
* **C++ Components:**
    * **`throw` expressions:** Used by the detecting part to indicate an unhandleable situation. This "raises" an exception.
    * **`try` blocks:** Code that might `throw` an exception is placed within a `try` block.
    * **`catch` clauses (exception handlers):** Follow a `try` block and are used by the handling part to deal with specific exceptions thrown within the `try` block.
    * **Exception classes:** Used to pass information about the anomaly between the `throw` expression and the `catch` clause.


- If no appropriate `catch` is found, execution is transferred to a library function named `terminate`.

### 5.6.3 Standard Exceptions

#### Table 5.1: Standard Exception Classes Defined in `<stdexcept>`

- Headers: `exception`, `stdexcept`, `type_info` (`bad_cast`)

|||
|---|---|
|`exception` |The most general kind of problem.|
|`runtime_error` |Problem that can be detected only at run time.|
|`range_error` |*Run-time error*: result generated outside the range of values that are meaningful.|
|`overflow_error` |*Run-time error*: computation that overflowed.|
|`underflow_error` |*Run-time error*: computation that underflowed.|
|`logic_error` |Error in the logic of the program.|
|`domain_error` |*Logic error*: argument for which no result exists.|
|`invalid_argument` |*Logic error*: inappropriate argument.|
|`length_error` |*Logic error*: attempt to create an object larger than the maximum size for that type.|
|`out_of_range` |*Logic error*: used a value outside the valid range.|


The exception types define only a single operation named `what`. That function takes no arguments and returns a `const char*` that points to a C-style character string.

# ch06: Functions

This chapter describes how to define and declare functions. We'll cover how arguments are passed to and values returned from functions. In C++, functions can be overloaded, which means that we can use the same name for several different functions. We'll cover both how to overload functions and how the compiler selects the matching version for a particular call from several overloaded functions. The chapter closes by describing pointers to functions.

#### Writing a Function

- factorial of a number `n`.

```cpp
// factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)
int fact(int val)
{
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1)
        ret *= val--; // assign ret * val to ret and decrement val
    return ret; // return the result
}
```

#### Calling a Function

```cpp
int main()
{
    int j = fact(5); // j equals 120, i.e., the result of fact(5)
    cout << "5! is " << j << endl;
    return 0;
}
```

#### Parameters and Arguments

```cpp
fact("hello"); // error: wrong argument type
fact(); // error: too few arguments
fact(42, 10, 0); // error: too many arguments
fact(3.14); // ok: argument is converted to int
```

#### Function Declarations Go in Header Files

- Recall that variables are declared in header files and defined in source files.

### 6.1.3 Separate Compilation

#### Compiling and LinkingMultiple Source Files

```console
$ CC factMain.cc fact.cc # generates factMain.exe or a.out
$ CC factMain.cc fact.cc -o main # generates main or main.exe
```

- Separately compile program as follows:

```console
$ CC -c factMain.cc # generates factMain.o
$ CC -c fact.cc # generates fact.o
$ CC factMain.o fact.o # generates factMain.exe or a.out
$ CC factMain.o fact.o -o main # generates main or main.exe
```

## 6.2 Argument Passing

- Parameter initialization works the same way as variable initialization.

- When a parameter is a reference, we say that its corresponding argument is "**passed by reference**" or that the function is "**called by reference**."

- When the argument value is copied, the parameter and argument are independent objects. We say such arguments are "**passed by value**" or alternatively that the function is "**called by value**."

### 6.2.1 Passing Arguments by Value

#### Pointer Parameters

- Pointers behave like any other nonreference type. When we copy a pointer, the value of the pointer is copied.

```cpp
int n = 0, i = 42;
int *p = &n, *q = &i; // p points to n; q points to i
*p = 42; // value in n is changed; p is unchanged
p = q; // p now points to i; values ini and n are unchanged

```

```cpp
// function that takes a pointer and sets the pointed-to value to zero
void reset(int *ip)
{
    *ip = 0; // changes the value of the object to which ip points
    ip = 0; // changes only the local copy of ip; the argument is unchanged
}
```

```cpp
int i = 42;
reset(&i); // changes i but not the address of i
cout << "i = " << i << endl; // prints i = 0
```

### 6.2.2 Passing Arguments by Reference

```cpp
// function that takes a reference to an int and sets the given object to zero
void reset(int &i) // i is just another name for the object passed to reset
{
    i = 0; // changes the value of the object to which i refers
}
```

```cpp
int j = 42;
reset(j); // j is passed by reference; the value in j is changed
cout << "j = " << j << endl; // printsj = 0
```

#### Using References to Avoid Copies

- It can be inefficient to copy objects of large class types or large containers.

```cpp
// compare the length of two strings
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

#### Using Reference Parameters to Return Additional Information

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

```cpp
auto index = find_char(s, 'o', ctr);
// first occurence is returned by the function.
// Number of occurence is indirectly returned (updated inside the called function because of referencing)
```

### 6.2.3 `const` Parameters and Arguments

- recall,

```cpp
const int ci = 42; // we cannot change ci; const is top-level
int i = ci; // ok: when we copy ci, its top-level const is ignored
int * const p = &i; // const is top-level; we can't assign to p
*p = 0; // ok: changes through p are allowed; i is now 0
```

- Just as in any other initialization, when we copy an argument to initialize a parameter, top-level `const`s are ignored.

- top-level `const`s cannot contribute to function overloading. Because
top-level `const`s are ignored.

```cpp
void fcn(const int i) { /* fcn can read but not write to i */ }
void fcn(int i) { /* . . . */ } // error: redefines fcn(int)
```

#### Pointer or Reference Parameters and `const`

```cpp
int i = 42;
const int *cp = &i; // ok: but cp can't change i (§ 2.4.2 (p. 62))
const int &r = i; // ok: but r can't change i (§ 2.4.1 (p. 61))
const int &r2 = 42; // ok: (§ 2.4.1 (p. 61))
int *p = cp; // error: types of p and cp don't match (§ 2.4.2 (p. 62))
int &r3 = r; // error: types of r3 and r don't match (§ 2.4.1 (p. 61))
int &r4 = 42; // error: can't initialize a plain reference from a literal (§ 2.3.1 (p. 50))
```

- Same initialization rules apply to parameter passing:

```cpp
int i = 0;
const int ci = i;
string::size_type ctr = 0;

reset(&i); // calls the version of reset that has an int* parameter
reset(&ci); // error: can't initialize an int* from a pointer to a const int object
reset(i); // calls the version of reset that has an int& parameter
reset(ci); // error: can't bind a plain reference to the const object ci
reset(42); // error: can't bind a plain reference to a literal
reset(ctr); // error: types don't match; ctr has an unsigned type

// ok: find_char's first parameter is a reference to const
find_char("Hello World!", 'o', ctr);
```

#### Use Reference to `const` When Possible

- It is a some what common mistake to define parameters that a function does not change as (plain) references. Doing so gives the function's caller the misleading impression that the function might change its argument's value.

Had we defined that parameter as a plain `string&`:

```cpp
// bad design: the first parameter should be a const string&
string::size_type find_char(string &s, char c, string::size_type &occurs);
```

we could call `find_char` only on a string object. A call such as `find_char("Hello World", 'o', ctr);` would fail at compile time.

In another example where, we might want to use `find_char` inside a function that determines whether a string represents a sentence:

```cpp
bool is_sentence(const string &s)
{
    // if there's a single period at the end of s, then s is a sentence
    string::size_type ctr = 0;
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}
```

If `find_char` took a plain `string&`, then this call to `find_char` would be a compile-time error. The problem is that `s` is a reference to a `const string`, but `find_char` was (incorrectly) defined to take a plain reference.

### 6.2.4 Array Parameters

- We cannot copy an array, and when we use an array it is (usually) converted to a pointer.
- We cannot pass an array by value.

```cpp
// despite appearances, these three declarations of print are equivalent
// each function has a single parameter of type const int*
void print(const int*);
void print(const int[]); // shows the intent that the function takes an array
void print(const int[10]); // dimension for documentation purposes (at best)
```

```cpp
int i = 0, j[2] = {0, 1};
print(&i); // ok: &i is int*
print(j); // ok: j is converted to an int* that points to j[0]
```

#### Using a Marker to Specify the Extent of an Array

- For C-style character strings

```cpp
void print(const char *cp)
{
if (cp) // if cp is not a null pointer
    while (*cp) // so long as the character it points to is not a null character
        cout << *cp++; // print the character and advance the pointer
}
```

#### Using the Standard Library Conventions

```cpp
void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << endl; // print the current element and advance the pointer
}
```

- To call the above function,

```cpp
int j[2] = {0, 1};
// j is converted to a pointer to the first element in j
// the second argument is a pointer to one past the end of j
print(begin(j), end(j)); // begin and end functions, see § 3.5.3 (p. 118)
```

#### Explicitly Passing a Size Parameter

```cpp
// const int ia[] is equivalent to const int* ia
// size is passed explicitly and used to control access to elements of ia
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}
```

- calling,

```cpp
int j[] = { 0, 1 }; // int array of size 2
print(j, end(j) - begin(j));
```

#### Array Reference Parameters

```cpp
// ok: parameter is a reference to an array; the dimension is part of the type
void print(int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}
```

The parentheses around `&arr` are necessary:

```cpp
f(int &arr[10]) // error: declares arr as an array of references
f(int (&arr)[10]) // ok: arr is a reference to an array of ten ints
```

- Wemay call this function only for an array of exactly ten ints

```cpp
int i = 0, j[2] = {0, 1};
int k[10] = {0,1,2,3,4,5,6,7,8,9};
print(&i); // error: argument is not an array of ten ints
print(j); // error: argument is not an array of ten ints
print(k); // ok: argument is an array of ten ints
```

- We'll see in § 16.1.1 (p. 654) how we might write this function in a way that would allow us to pass a reference parameter to an array of any size.

#### Passing a Multidimensional Array

```cpp
// matrix points to the first element in an array whose elements are arrays of ten ints
void print(int (*matrix)[10], int rowSize) { /* . . . */ }
```

```cpp
// equivalent definition
void print(int matrix[][10], int rowSize) { /* . . . */ }
```

> Again, the parentheses around `*matrix` are necessary:

```cpp
int *matrix[10]; // array of ten pointers
int (*matrix)[10]; // pointer to an array of ten ints
```

### 6.2.5 `main`: Handling Command-Line Options

```cpp
int main(int argc, char *argv[]) { ... }
```

- `argc`, passes the number of strings in that array
- `argv`, is an array of pointers to C-style character strings


```cpp
// alternative definition
int main(int argc, char **argv) { ... }
```

- **The element just past the last pointer is guaranteed to be 0.**

```console
prog -d -o ofile data0
```

Such command-line options are passed to `main` in two (optional) parameters.

Given the previous command line, `argc` would be 5, and `argv` would hold the following C-style character strings:

```cpp
argv[0] = "prog"; // or argv[0] might point to an empty string
argv[1] = "-d";
argv[2] = "-o";
argv[3] = "ofile";
argv[4] = "data0";
argv[5] = 0;
```

> When you use the arguments in `argv`, remember that the optional arguments begin in `argv[1]`; `argv[0]` contains the program's name, not user input.

### 6.2.6 Functions with Varying Parameters

The new standard provides **two primary ways** to write a function that takes a varying number of arguments:
- If all the arguments have the **same type**, we can pass a library type named `initializer_list`.
- If the argument types vary, we can write a special kind of function, known as a **variadic template**, which we'll cover in § 16.4 (p. 699).

C++ also has a special parameter type, **ellipsis**, that can be used to pass a varying number of arguments. However, it is worth noting that this facility ordinarily *should be used only in* programs that need to interface to C functions.

#### `initializer_list` Parameters

We can write a function that takes an unknown number of arguments of a single type by using an `initializer_list` parameter. An `initializer_list` is a library type that **represents an array of values** of the specified type. This type is defined in the  `initializer_list` header. The operations that `initializer_list` provides are listed in Table 6.1.

#### Table 6.1: Operations on initializer_lists

|||
|---|---|
|`initializer_list<T> lst;` |Default initialization; an empty list of elements of type `T`.|
|`initializer_list<T> lst{a,b,c...};` |`lst` has as many elements as there are initializers; elements are copies of the corresponding initializers. Elements in the list are `const`.|
|`lst2(lst)` |Copying or assigning an `initializer_list` does not copy the elements in the list. After the copy, the original and the copy share the elements.|
|`lst2 = lst` |--//--|
|`lst.size()` |Number of elements in the list.|
|`lst.begin()` |Returns a pointer to the first element in `lst`.|
|`lst.end()` |Returns a pointer to the last element in `lst`.|

```cpp
initializer_list<string> ls; // initializer_list of strings
initializer_list<int> li; // initializer_list of ints
```

- elements in an `initializer_list` are always `const` values;

We can write our function to produce error messages from a varying number
of arguments as follows:

```cpp
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " " ;
    cout << endl;
}
```

When we pass a sequence of values to an `initializer_list` parameter, we must enclose the sequence in curly braces:

```cpp
// expected, actual are strings
if (expected != actual)
    error_msg({"functionX", expected, actual});
else
    error_msg({"functionX", "okay"});
```

- A function with an `initializer_list` parameter can have other parameters as well.

```cpp
void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " " ;
        cout << endl;
}
```

```cpp
if (expected != actual)
    error_msg(ErrCode(42), {"functionX", expected, actual});
else
    error_msg(ErrCode(0), {"functionX", "okay"});
```

#### Ellipsis Parameters

- Ellipsis parameters are in C++ to allow programs to interface to C code that uses a C library facility named `varargs`.
- Generally an ellipsis parameter should not be used for other purposes.

An ellipsis parameter may appear only as the ***last element in a parameter list*** and may take either of two forms:

```cpp
void foo(parm_list, ...);
void foo(...);
```

- The first form specifies the type(s) for some of foo's parameters. Arguments that correspond to the specified parameters are type checked as usual.
- No type checking is done for the arguments that correspond to the ellipsis parameter. In this first form, the comma following the parameter declarations is optional.

## 6.3 Return Types and the return Statement

There are two forms of return statements:

```cpp
return;
return expression;
```

### 6.3.1 Functions with No Return Value

- A return with no value may be used only in a function that has a return type of `void`.

- Typically, `void` functions use a return to exit the function at an intermediate point.

```cpp
void swap(int &v1, int &v2)
{
    // if the values are already the same, no need to swap, just return
    if (v1 == v2)
        return;
    // if we're here, there's work to do
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
    // no explicit return necessary
}
```

### 6.3.2 Functions That Return a Value

```cpp
// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2; // ok: == returns bool
    // find the size of the smaller string; conditional operator, see § 4.7 (p. 151)
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return; // error #1: no return value; compiler should detect this error
    }
    // error #2: control might flow off the end of the function without a return
    // the compiler might not detect this error
}
```

> Failing to provide a return after a loop that contains a return is an error. However, many compilers will not detect such errors.

#### How Values Are Returned

Values are returned in exactly the same way as variables and parameters are initialized: The return value is used to initialize a temporary at the call site, and that temporary is the result of the function call.

```cpp
// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word,
const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
```

The return type of this function is `string`, which means the return value is copied to the call site. This function returns a copy of word, or it returns an unnamed temporary string that results from adding word and ending.

As with any other reference, when a function returns a reference, that reference is just another name for the object to which it refers. As an example, consider a function that returns a reference to the shorter of its two string parameters:

```cpp
// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
```

The parameters and return type are **references to `const string`**. The strings are not copied when the function is called or when the result is returned.

#### Never Return a Reference or Pointer to a Local Object

```cpp
// disaster: this function returns a reference to a local object
const string &manip()
{
    string ret;
    // transform ret in some way
    if (!ret.empty())
        return ret; // WRONG: returning a reference to a local object!
    else
        return "Empty"; // WRONG: "Empty" is a local temporary string
}
```

For the same reasons that it is wrong to return a reference to a local object, it is also wrong to return a pointer to a local object. Once the function completes, the local objects are freed. The pointer would point to a nonexistent object.

#### Functions That Return Class Types and the Call Operator

The call operator has the same precedence as the dot and arrow operators and is left associative. As a result, if a function returns a *pointer*, *reference* or *object of class type*, we can use the result of a call to call a member of the resulting object.

```cpp
// call the size member of the string returned by shorterString
auto sz = shorterString(s1, s2).size();
```

#### Reference Returns Are Lvalues

- Calls to functions that return references are lvalues; other return types yield rvalues.

```cpp
char &get_val(string &str, string::size_type ix)
{
    return str[ix]; // get_val assumes the given index is valid
}

int main()
{
    string s("a value");
    cout << s << endl; // prints a value
    
    get_val(s, 0) = 'A'; // changes s[0] to A
    cout << s << endl; // prints A value
    
    return 0;
}
```

- Note that the function call is on the left-hand side of an assignment. However, nothing special is involved. The return value is a reference, so the call is an lvalue. Like any other lvalue, it may appear as the left-hand operand of the assignment operator.

If the return type is a reference to `const`, then (as usual) we may not assign to the result of the call:

```cpp
shorterString("hi", "bye") = "X"; // error: return value is const
```

#### List Initializing the Return Value

Under the new standard, functions can return a braced list of values. As in any other return, the list is used to initialize the temporary that represents the function's return. If the list is empty, that temporary is value initialized. Otherwise, the value of the return depends on the function's return type.

```cpp
vector<string> process()
{
    // . . .
    // expected and actual are strings
    if (expected.empty())
        return {}; // return an empty vector
    else if (expected == actual)
        return {"functionX", "okay"}; // return list-initialized vector
    else
        return {"functionX", expected, actual};
}
```

#### Return from `main`

- If control reaches the end of `main` and there is no return, then the compiler implicitly inserts a return of 0.

- The `cstdlib` header defines two preprocessor variables that we can use to indicate success or failure.

```cpp
int main()
{
    if (some_failure)
        return EXIT_FAILURE; // defined in cstdlib
    else
        return EXIT_SUCCESS; // defined in cstdlib
}
```

- Because these are preprocessor variables, we must not precede them with `std::`, nor may we mention them in `using` declarations.

#### Recursion

- A function that calls itself, either directly or indirectly, is a **recursive function**.

```cpp
// calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}
```

- There must always be a path through a recursive function that does not involve a recursive call; otherwise, the function will recurse "forever," meaning that the function will continue to call itself until the program stack is exhausted.

- **The `main` function may not call itself.**

### 6.3.3 Returning a Pointer to an Array

- Because we cannot copy an array, a function cannot return an array.

```cpp
typedef int arrT[10]; // arrT is a synonym for the type array of ten ints
using arrT = int[10]; // equivalent declaration of arrT; see § 2.5.1 (p. 68)
arrT* func(int i); // func returns a pointer to an array of ten ints
```

#### Declaring a Function That Returns a Pointer to an Array

- recall

```cpp
int arr[10]; // arr is an array of ten ints
int *p1[10]; // p1 is an array of ten pointers
int (*p2)[10] = &arr; // p2 points to an array of ten ints
```

- without using type alias: the form of a function that returns a pointer to an array is:

```cpp
Type (*function(parameter_list))[dimension]
```

A concrete example, the following declares `func` without using a type alias:

```cpp
int (*func(int i))[10];
```

To understand this declaration, it can be helpful to think about it as follows:

- `func(int)` says that we can call `func` with an `int` argument.
- `(*func(int))` says we can dereference the result of that call.
- `(*func(int))[10]` says that dereferencing the result of a call to func
yields an array of size ten.
- `int (*func(int))[10]` says the element type in that array is `int`.

#### Using a Trailing Return Type

- Under the new standard, another way to simplify the declaration of `func` is by using a trailing return type.

Trailing returns can be defined for any function, but are most useful for functions with complicated return types, such as pointers (or references0 to arrays.

- A **trailing return type** follows the *parameter list* and is preceded by `->`. To signal that the return follows the parameter list, *we use `auto`* where the return type ordinarily appears.

```cpp
// fcn takes an int argument and returns a pointer to an array of ten ints
auto func(int i) -> int(*)[10];
```

#### Using `decltype`

```cpp
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even; // returns a pointer to the array
}
```

- we must remember that `decltype` does not automatically convert an array to its corresponding pointer type. The type returned by `decltype` is an array type, to which we must add a `*` to indicate that `arrPtr` returns a pointer.

## 6.4 Overloaded Functions

- These functions perform the same general action but apply to different parameter types.

```cpp
void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);
```

```cpp
int j[2] = {0,1};
print("Hello World"); // calls print(const char*)
print(j, end(j) - begin(j)); // calls print(const int*, size_t)
print(begin(j), end(j)); // calls print(const int*, const int*)
```

#### Defining Overloaded Functions

```cpp
Record lookup(const Account&); // find by Account
Record lookup(const Phone&); // find by Phone
Record lookup(const Name&); // find by Name
Account acct;
Phone phone;
Record r1 = lookup(acct); // call version that takes an Account
Record r2 = lookup(phone); // call version that takes a Phone
```

- It is an error for two functions to differ only in terms of their return types.

#### DeterminingWhether Two Parameter Types Differ

```cpp
// each pair declares the same function
Record lookup(const Account &acct);
Record lookup(const Account&); // parameter names are ignored
typedef Phone Telno;
Record lookup(const Phone&);
Record lookup(const Telno&); // Telno and Phone are the same type
```

#### Overloading and `const` Parameters

- Top-level `const` does not contribute in operator overloading.

```
Record lookup(Phone);
Record lookup(const Phone); // redeclares Record lookup(Phone)
Record lookup(Phone*);
Record lookup(Phone* const); // redeclares Record lookup(Phone*)
```

- But low-level `const` do contribute in operator overloading

```cpp
// functions taking const and nonconst references or pointers have different parameters
// declarations for four independent, overloaded functions
Record lookup(Account&); // function that takes a reference to Account
Record lookup(const Account&); // new function that takes a const reference
Record lookup(Account*); // new function, takes a pointer to Account
Record lookup(const Account*); // new function, takes a pointer to const
```

- The compiler will prefer the non`const` versions when we pass a non`const` object or pointer to non`const`.

#### `const_cast` and Overloading

- `const_casts` are most useful in the context of overloaded functions. 
- Recall `shorterString` function

```cpp
// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
```

This function takes and returns references to `const` string. We can call the function on a pair of non`const` string arguments, but we'll get a reference to a `const` string as the result. 

We might want to have a version of `shorterString` that, when given non`const` arguments, would yield a *plain reference*. We can write this version of our function using a `const_cast`:

```cpp
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&>(s1),     const_cast<const string&>(s2));

    return const_cast<string&>(r);
}
```

This version calls the `const` version of `shorterString` by casting its arguments to references to `const`. That function returns a reference to a `const` string, which we know is bound to one of our original, non`const` arguments. Therefore, we know it is safe to cast that string back to a plain `string&` in the return.

#### Calling an Overloaded Function

- **Function matching** (also known as **overload resolution**) is the process by which a particular function call is associated with a specific function from a set of overloaded functions.

For any given call to an overloaded function, there are three possible outcomes:
- The compiler finds exactly one function that is a best match for the actual arguments and generates code to call that function.
- There is no function with parameters that match the arguments in the call, in which case the compiler issues an error message that there was no match.
- There is more than one function that matches and none of the matches is clearly best. This case is also an error; it is an ambiguous call.

### 6.4.1 Overloading and Scope

- Names do not overload across scopes.

```cpp
string read();
void print(const string &);
void print(double); // overloads the print function

void fooBar(int ival)
{
    bool read = false; // new scope: hides the outer declaration of read
    string s = read(); // error: read is a bool variable, not a function
    // bad practice: usually it's a bad idea to declare functions at local scope
    void print(int); // new scope: hides previous instances of print
    print("Value: "); // error: print(const string &) is hidden
    print(ival); // ok: print(int) is visible
    print(3.14); // ok: calls print(int); print(double) is hidden
}
```


```cpp
void print(const string &);
void print(double); // overloads the print function
void print(int); // another overloaded instance
void fooBar2(int ival)
{
    print("Value: "); // calls print(const string &)
    print(ival); // calls print(int)
    print(3.14); // calls print(double)
}
```

## 6.5 Features for Specialized Uses

- default arguments
- `inline` 
- `constexpr` functions
- some facilities that are often used during debugging.

### 6.5.1 Default Arguments

```cpp
typedef string::size_type sz; // typedef see § 2.5.1 (p. 67)
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
```

- if a parameter has a default argument, all the parameters that follow it must also have default arguments.

#### Calling Functions with Default Arguments

```cpp
string window;
window = screen(); // equivalent to screen(24,80,' ')
window = screen(66);// equivalent to screen(66,80,' ')
window = screen(66, 256); // screen(66,256,' ')
window = screen(66, 256, '#'); // screen(66,256,'#')
```


```cpp
window = screen(, , '?'); // error: can omit only trailing arguments
window = screen('?'); // calls screen('?',80,' ')
```

#### Default Argument Declarations

Although it is normal practice to declare a function once inside a header, it is legal to redeclare a function multiple times. However, each parameter can have its default specified only once in a given scope. Thus, any subsequent declaration can add a default only for a parameter that has not previously had a default specified.

For example, given

```cpp
// no default for the height or width parameters
string screen(sz, sz, char = ' ');
```

we cannot change an already declared default value:

```cpp
string screen(sz, sz, char = '*'); // error: redeclaration
```

but we can add a default argument as follows:

```cpp
string screen(sz = 24, sz = 80, char); // ok: adds default arguments
```

> Default arguments ordinarily should be specified with the function declaration in an appropriate header.

#### Default Argument Initializers

```cpp
// the declarations of wd, def, and ht must appear outside a function
sz wd = 80;
char def = ' ';
sz ht();
string screen(sz = ht(), sz = wd, char = def);
string window = screen(); // calls screen(ht(), 80,' ')
```

```cpp
void f2()
{
    def = '*'; // changes the value of a default argument
    sz wd = 100; // hides the outer definition of wd but does not change the default
    window = screen(); // calls screen(ht(), 80, '*')
}
```

### 6.5.2 Inline and `constexpr` Functions

Calling a function is apt to be slower than evaluating the equivalent expression.

On most machines, a function call does a lot of work: Registers are saved before the call and restored after the `return`; arguments may be copied; and the program branches to a new location.

#### `inline` Functions Avoid Function Call Overhead

A function specified as `inline` (**usually**) is expanded "in line" at each call. If `shorterString` were defined as `inline`, then this call

```cpp
cout << shorterString(s1, s2) << endl;
```

(**probably**) would be expanded during compilation into something like

```cpp
cout << (s1.size() < s2.size() ? s1 : s2) << endl;
```

- The run-time overhead of making shorterString a function is thus removed.

```cpp
// inline version: find the shorter of two strings
inline const string & shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
```

> The `inline` specification is only a request to the compiler. The compiler may choose to ignore this request.

#### `constexpr` Functions

A `constexpr` function is a function that can be used in a constant expression. A `constexpr` function is defined like any other function but must meet certain restrictions: The return type and the type of each parameter must be a literal type, and the function body must contain exactly one `return` statement.

```cpp
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz(); // ok: foo is a constant expression
```

- In order to be able to expand the function immediately, `constexpr` functions are implicitly `inline`.

- A `constexpr` function body may contain other statements so long as those statements generate no actions at run time. For example, a `constexpr` function may contain null statements, type aliases, and `using` declarations.
- A `constexpr` function is permitted to return a value that is not a constant:

```cpp
// scale(arg) is a constant expression if arg is a constant expression
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
```

- The scale function will return a constant expression if its argument is a constant expression but not otherwise:

```cpp
int arr[scale(2)]; // ok: scale(2) is a constant expression
int i = 2; // i is not a constant expression
int a2[scale(i)]; // error: scale(i) is not a constant expression
```

- When we pass a constant expression—such as the literal 2—then the return is a constant expression. In this case, the compiler will replace the call to `scale` with the resulting value.

- If we call `scale` with an expression that is not a constant expression—such as on the int object `i`—then the return is not a constant expression. 
- If we use `scale` in a context that requires a constant expression, the compiler checks that the result is a constant expression. If it is not, the compiler will produce an error message.

> A `constexpr` function is not required to return a constant expression.

#### Put `inline` and `constexpr` Functions in Header Files

Unlike other functions, `inline` and `constexpr` functions may be defined multiple times in the program.

After all, the compiler needs the definition, not just the declaration, in order to expand the code. However, all of the definitions of a given `inline` or `constexpr` must match exactly. As a result, `inline` and `constexpr` functions normally are defined in headers.

### 6.5.3 Aids for Debugging

- two preprocessor facilities: `assert` and `NDEBUG`.

#### The `assert` Preprocessor Macro

- acts somewhat like an inline function.

The assert macro takes a single expression, which it uses as a condition:

```console
assert(expr);
```

evaluates `expr` and if the expression is `false` (i.e., zero), then `assert` writes a message and terminates the program. If the expression is `true` (i.e., is nonzero), then assert does nothing.

- `cassert` header

#### The NDEBUG Preprocessor Variable

- If `NDEBUG` is defined, `assert` does nothing. By default, `NDEBUG` is not defined, so, by default, assert performs a run-time check.

We can "turn off" debugging by two methods
- by writing #define NDEBUG at the beginning of `main.c`.
- by providing a command-line option that lets us define preprocessor variables: `$ CC -D NDEBUG main.C # use /D with the Microsoft compiler`

In addition to using `assert`, we can write our own conditional debugging code using `NDEBUG`. If `NDEBUG` is not defined, the code between the `#ifndef` and the `#endif` is executed. If `NDEBUG` is defined, that code is ignored:

```cpp
void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
    // `__func__` is a local static defined by the compiler that holds the function's name
    cerr << `__func__` << ": array size is " << size << endl;
    #endif
    // . . .
}
```

Here we use a variable named `__func__` to print the name of the function we are debugging. The compiler defines `__func__` in every function. It is a local `static` array of `const char` that holds the name of the function.

In addition to __func__, which the C++ compiler defines, the preprocessor defines four other names that can be useful in debugging:

- `__FILE__` string literal containing the name of the file
- `__LINE__` integer literal containing the current line number
- `__TIME__` string literal containing the time the file was compiled
- `__DATE__` string literal containing the date the file was compiled

We might use these constants to report additional information in error messages:
```cpp
if (word.size() < threshold)
cerr << "Error: " << `__FILE__`
<< " : in function " << __func__
<< " at line " << `__LINE__` << endl
<< " Compiled on " << `__DATE__`
<< " at " << `__TIME__` << endl
<< " Word read was \"" << word
<< "\": Length too short" << endl;
```

If we give this program a string that is shorter than the threshold, then the following error message will be generated:

```console
Error: wdebug.cc : in function main at line 27
    Compiled on Jul 11 2012 at 20:50:03
    Word read was "foo": Length too short
```

## 6.6 Function Matching

```cpp
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
f(5.6); // calls void f(double, double)
```

#### Determining the Candidate and Viable Functions

- In this example, there are four candidate functions named `f`.

- A **candidate function** is a function with the same name as the called function and for which a declaration is visible at the point of the call.

- A **viable function** is a function that must have the same number of parameters as there are arguments in the call, and the type of each argument must match—or be convertible to—the type of its corresponding parameter.

#### Finding the Best Match, If Any

#### Function Matching with Multiple Parameters

- Function matching is more complicated if there are two or more arguments.

> Casts should not be needed to call an overloaded function. The need for a cast suggests that the parameter sets are designed poorly.

If we have a call as shown below, the compiler will reject the call due to its ambiguity. Both 3rd and 4th candidates are equally viable.

```cpp
f(46, 2.56);
```

### 6.6.1 Argument Type Conversions

- The small integral types always promote to `int` or to a larger integral type. Given two functions, one of which takes an `int` and the other a `short`, the `short` version will be called only on values of type `short`.

```cpp
void ff(int);
void ff(short);
ff('a'); // char promotes to int; calls f(int)
```

- **All the arithmetic conversions are treated as equivalent to each other.** 

- The conversion from `int` to `unsigned int`, for example, does not take precedence over the conversion from `int` to `double`. As a concrete example, consider

```cpp
void manip(long);
void manip(float);
manip(3.14); // error: ambiguous call
```

#### Function Matching and `const` Arguments

```cpp
Record lookup(Account&); // function that takes a reference to Account
Record lookup(const Account&); // new function that takes a const reference
const Account a;
Account b;
lookup(a); // calls lookup(const Account&)
lookup(b); // calls lookup(Account&)
```

- The compiler uses the `const`ness of the argument to decide which function to call.

```cpp
Record lookup(Account&); // function that takes a reference to Account
Record lookup(const Account&); // new function that takes a const reference
const Account a;
Account b;
lookup(a); // calls lookup(const Account&)
lookup(b); // calls lookup(Account&). Reason {initializing a reference to from a nonconst object requires const a conversion.}
```

## 6.7 Pointers to Functions

A function's type is determined by its return type and the types of its parameters. The function's name is not part of its type. For example:

```cpp
// compares lengths of two strings
bool lengthCompare(const string &, const string &);
```

has type `bool(const string&, const string&)`.

```cpp
// pf points to a function returning bool that takes two const string references
bool (*pf)(const string &, const string &); // uninitialized
```

> The parentheses around `*pf` are necessary. If we omit the parentheses, then we declare `pf` as a function that returns a pointer to bool:

```cpp
// declares a function named pf that returns a bool*
bool *pf(const string &, const string &);
```

#### Using Function Pointers

- When we use the name of a function as a value, the function is automatically converted to a pointer.

```cpp
pf = lengthCompare; // pf now points to the function named lengthCompare
pf = &lengthCompare; // equivalent assignment: address-of operator is optional
```

Moreover, we can call the function using the pointer. We can do so directly—there is no need to dereference the pointer:

```cpp
bool b1 = pf("hello", "goodbye"); // calls lengthCompare
bool b2 = (*pf)("hello", "goodbye"); // equivalent call
bool b3 = lengthCompare("hello", "goodbye"); // equivalent call
```

There is no conversion between pointers to one function type and pointers to another function type. However, we can assign `nullptr` or a zero-valued integer constant expression.

```cpp
string::size_type sumLength(const string&, const string&);
bool cstringCompare(const char*, const char*);

pf = 0; // ok: pf points to no function
pf = sumLength; // error: return type differs
pf = cstringCompare; // error: parameter types differ
pf = lengthCompare; // ok: function and pointer types match exactly
```

#### Pointers to Overloaded Functions

```cpp
void ff(int*);
void ff(unsigned int);
void (*pf1)(unsigned int) = ff; // pf1 points to ff(unsigned)
```

```cpp
void (*pf2)(int) = ff; // error: no ff with a matching parameter list
double (*pf3)(int*) = ff; // error: return type of ff and pf3 don’t match
```

#### Function Pointer Parameters

```cpp
// third parameter is a function type and is automatically treated as a pointer to function
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));
// equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));
```

```cpp
// automatically converts the function lengthCompare to a pointer to function
useBigger(s1, s2, lengthCompare);
```

```cpp
// Func and Func2 have function type
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2; // equivalent type
// FuncP and FuncP2 have pointer to function type
typedef bool(*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2; // equivalent type
```

- the automatic conversion to pointer is not done.

```cpp
// equivalent declarations of useBigger using type aliases
void useBigger(const string&, const string&, Func);
void useBigger(const string&, const string&, FuncP2);
```

#### Returning a Pointer to Function

- We must write the return type as a pointer type; the compiler will not automatically treat a function return type as the corresponding pointer type.

```cpp
using F = int(int*, int); // F is a function type, not a pointer
using PF = int(*)(int*, int); // PF is a pointer type
```

```cpp
PF f1(int); // ok: PF is a pointer to function; f1 returns a pointer to function
F f1(int); // error: F is a function type; f1 can’t return a function
F *f1(int); // ok: explicitly specify that the return type is a pointer to function
```

```cpp
// declare f1 directly
int (*f1(int))(int*, int);
```

using a trailing return:

```cpp
auto f1(int) -> int (*)(int*, int);
```

#### Using auto or `decltype` for Function Pointer Types

```cpp
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);
// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength
decltype(sumLength) *getFcn(const string &);
```

- We must add a `*` to indicate that we are returning a pointer, not a function.

