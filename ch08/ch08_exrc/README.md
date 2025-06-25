# ch08_exrc

## ch08_exrc_8p1

- See code from `ch08_exrc_8p2`

## ch08_exrc_8p3

Exercise 8.3: What causes the following `while` to terminate?

```cpp
while (cin >> i) /* ... */
```

The `while (cin >> i)` loop will terminate due to two primary reasons related to stream state:

1.  **End-of-file (EOF):** If the input stream reaches its end (e.g., when reading from a file and all content has been consumed, or when a user signals EOF manually, like Ctrl+Z on Windows or Ctrl+D on Unix-like systems), the `eofbit` will be set, causing the expression `cin >> i` to evaluate to a falsy value (the stream is no longer in a "good" state).

2.  **Incorrect Input (Type Mismatch/Format Error):** If the input read from `cin` cannot be successfully converted to the type of `i` (e.g., trying to read the string "abc" into an `int i`), the `failbit` will be set. This also causes the expression `cin >> i` to evaluate to a falsy value, terminating the loop.

