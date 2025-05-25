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
