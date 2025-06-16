# ch07_exrc :: Classes

## ch07_exrc_7p5

Exercise 7.5: Provide operations in your `Person` class to return the `name` and `address`. Should these functions be `const`? Explain your choice.

- In my opinion, both of these member functions shall be `const` since they are just to provide existing data without any modifications.

## ch07_exrc_7p8

Exercise 7.8: Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

```cpp
    istream &read(istream &is, Sales_data &item);
    ostream &print(ostream &os, const Sales_data &item) const;
```

- Because in the `read` function we are actually feeding the `Sales_data` object members via `istream`; therefore it cannot be `const`.
- In `print` we are not modifying anything in the `Sales_data` object received but will only print it. Therefore, we do not have any statements modifying the members of the object. To avoid unintentional modifications in the object we are adding `const`ness.

## ch07_exrc_7p10

Exercise 7.10: What does the condition in the following `if` statement do?

```cpp
if (read(read(cin, data1), data2))
```

- Assuming `istream& read(istream& is, Person &p);`

- First, `read(cin, data1)` is executed. If the read is successfull, in that place we will have a `istream` reference waiting for outer `read` (`read(cin, data2)`). If this `read` also succeeds, then the `if` condition passes.
- If any of the reads fail then the `if` condition will also fail.

