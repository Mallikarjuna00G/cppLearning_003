# ch03_exrc

## ch03_exrc_3p3

Exercise 3.3: Explain how whitespace characters are handled in the `string` input operator
and in the `getline` function.

1.  **String Input Operator (`std::string`)**:
    * **Skips leading whitespace:** It reads and discards any leading whitespace characters (spaces, tabs, newlines, etc.) in the input buffer.
    * **Reads non-whitespace:** It then reads non-whitespace characters until it encounters the **next whitespace character** or the end of the input stream.
    * **Leaves trailing whitespace:** The whitespace character that terminates the read operation remains in the input buffer.
    * **Purpose:** Best for reading single "words" or tokens.

    *Example:* If input is `  Hello World\n`, `std::cin >> str;` will put `"Hello"` into `str`, and `" World\n"` remains in the buffer.

2.  **`std::getline`**:
    * **Reads all characters (including whitespace):** It reads characters from the input stream, including whitespace, until it encounters a **delimiter character** (by default, the newline `\n`).
    * **Includes leading/internal whitespace:** All characters read up to (but not including) the delimiter are stored in the string.
    * **Discards delimiter:** The delimiter character itself is read from the input stream but is **discarded** (not stored in the string).
    * **Purpose:** Best for reading entire lines of text.

    *Example:* If input is `  Hello World\n`, `std::getline(std::cin, str);` will put `"  Hello World"` into `str`, and the `\n` is consumed and discarded.

## ch03_exrc_3p8

- range `for` loop is preferred over the other two because we are looping through all the elements of the string.

## ch03_exrc_3p9

Exercise 3.9: What does the following program do? Is it valid? If not, why not?

```cpp
string s;
cout << s[0] << endl;
```

Since `s` is an empty string trying to access through any index number is illegal.

The program is not valid and exhibits **undefined behavior**.

**Here's the explanation**:

1. `std::string s;`: This declares a `std::string` object named `s`. When a `std::string` is default-constructed like this, it is initialized as an empty string. This means it contains no characters, and its `size()` is `0`.

2. 
```cpp
cout << s[0] << endl;:
```

- The operator`[]` for `std::string` provides unchecked access. This means it does not perform bounds checking.
- For a string of size `N`, valid indices are `0` through `N-1`.
- Since `s` is an empty string (`N=0`), there are no valid indices. Accessing `s[0]` is an out-of-bounds access.

3. Undefined Behavior: Accessing a string (or any array/container) out of its valid bounds using operator`[]` results in undefined behavior in C++. This means:

- The program might crash immediately.
- It might print garbage values.
- It might appear to work fine in some cases (e.g., on specific compilers or systems) but crash on others.
- It could lead to security vulnerabilities.

## ch03_exrc_3p11

Exercise 3.11: Is the following range `for` legal? If so, what is the type of `c`?

```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```

- The loop is legal
- The type of `c` is `const char &`.


## ch03_exrc_3p12

Exercise 3.12: Which, if any, of the following `vector` definitions are in error? For
those that are legal, explain what the definition does. For those that are not legal,
explain why they are illegal.

(a) `vector<vector<int>> ivec;`: Legal. `ivec` is a `vector` of `vector` of `int`s (2-dimensional vector of `int`s).

(b) `vector<string> svec = ivec;`: Illegal. `svec` is a `vector` of `string`s and the statement is trying to copy initialize with `ivec` which is a 2-dimensional `vector` of `int`s.

(c) `vector<string> svec(10, "null");`: Legal. `svec` is a `vector` of `string` initialized with 10 elements having the value `"null"`.

## ch03_exrc_3p13

Exercise 3.13: How many elements are there in each of the following vectors? What
are the values of the elements?

(a) `vector<int> v1;`: `v1` is empty.

(b) `vector<int> v2(10);`: `v2` has 10 values and each of them are initialized to 0.

(c) `vector<int> v3(10, 42);`: `v3` has 10 values and each of them are equal to 42.

(d) `vector<int> v4{10};`: `v4` has 1 value and is equal to 10.

(e) `vector<int> v5{10, 42};`: `v5` has 2 values and they are 10 and 42.

(f) `vector<string> v6{10};`: `v6` has 10 values and each of them are initialized with empty strings.

(g) `vector<string> v7{10, "hi"};`: `v7` has 10 values and each of them are initialized with `"hi"`.

## ch03_exrc_3p18

Exercise 3.18: Is the following program legal? If not, how might you fix it?

```cpp
vector<int> ivec;
ivec[0] = 42;
```

- `vector<int> ivec;`: This line default-constructs `ivec`. An `std::vector` created this way is empty, meaning it contains zero elements. Its `size()` is 0.

- `ivec[0] = 42;`:

- - The operator`[]` for `std::vector` provides unchecked access. This means it does not perform any bounds checking.
- - When you try to access `ivec[0]` on an empty vector, you are attempting to access memory outside the bounds of the vector's allocated storage. This leads to undefined behavior.

Undefined Behavior (UB) means:

- The program might crash immediately (often with a segmentation fault or similar error).
- It might appear to work correctly on some systems or compilers but fail unpredictably on others.
- It might corrupt other data in memory, leading to obscure bugs later in the program's execution.
- There are no guarantees about what the program will do.

**How to fix it (to legally put 42 into ivec):**

You need to ensure the vector has space for elements before trying to access them via operator`[]`.

*Using `push_back` (most common and idiomatic for adding elements):*

```cpp
vector<int> ivec;
ivec.push_back(42); // Adds 42 to the end of the vector. ivec now has 1 element.
```

*Initializing directly (if you know the initial elements):*

```cpp
vector<int> ivec = {42}; // ivec is created with one element, 42.
// OR
vector<int> ivec(1, 42); // ivec is created with one element, initialized to 42.
```

## ch03_exrc_3p19

Exercise 3.19: List three ways to define a `vector` and give it ten elements, each with
the value 42. Indicate whether there is a preferred way to do so and why.

1. `vector<int> a(10, 42);`
2. `vector<int> a = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};  // copy-list-initialization`
3. `vector<int> a {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};  // direct-list-initialization`

First one is the preferred way because it is compact.