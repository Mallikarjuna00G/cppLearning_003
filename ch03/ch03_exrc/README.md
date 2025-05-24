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