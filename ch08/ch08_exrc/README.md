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

## ch08_exrc_8p12

Exercise 8.12: Why didn't we use in-class initializers in `PersonInfo`?

In-class initializers weren't necessary because `std::string` and `std::vector` (the types of `name` and `phones`) automatically default-initialize to an empty string and an empty vector, respectively. Explicitly initializing them to empty would be redundant.

## ch08_exrc_8p14

Exercise 8.14: Why did we declare `entry` and `nums` as `const auto &`?

```cpp
// members are public by default; see § 7.2 (p. 268)
struct PersonInfo {
    string name;
    vector<string> phones;
};
vector<PersonInfo> people; // will hold all the records from the input

for (const auto &entry : people) { // for each entry in people
    ostringstream formatted, badNums; // objects created on each loop
    for (const auto &nums : entry.phones) { // for each number
        if (!valid(nums)) {
        badNums << " " << nums; // string in badNums
        } else
        // ''writes'' to formatted's string
        formatted << " " << format(nums);
    }

    if (badNums.str().empty()) // there were no bad numbers
        os << entry.name << " " << formatted.str() << endl; // and reformatted numbers
    else // otherwise, print the name and bad numbers
        cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
}
```

* **`const`**: To prevent accidental modification of `entry` (a `PersonInfo` object) or `nums` (a phone number string) within the loop, as they are only being read.
* **`auto`**: To let the compiler deduce the type, making the code more concise and adaptable if the underlying types change.
* **`&` (Reference)**: To avoid copying the `PersonInfo` objects and `string`s in each iteration, which improves performance, especially for large vectors or strings.