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

## ch03_exrc_3p26

Exercise 3.26: In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) /2;`?

```cpp
// text must be sorted
// beg and end will denote the range we're searching
auto beg = text.begin(), end = text.end();
auto mid = text.begin() + (end - beg)/2; // original midpoint
// while there are still elements to look at and we haven't yet found sought
while (mid != end && *mid != sought) {
    if (sought < *mid) // is the element we want in the first half?
        end = mid; // if so, adjust the range to ignore the second half
    else // the element we want is in the second half
        beg = mid + 1; // start looking with the element just after mid
    mid = beg + (end - beg)/2; // new midpoint
}
```

**NOTE: Full answer received from gemini 2.5**

The statement `mid = beg + (end - beg) / 2;` is used instead of `mid = (beg + end) / 2;` for two primary reasons related to C++'s iterator design and safety:

1.  **Iterator Arithmetic Limitations:**
    * In C++, iterators generally **do not support addition with other iterators**. Operations like `beg + end` are not defined for most iterator categories (e.g., iterators for `std::list`, `std::set`, or `std::map`).
    * Only **random-access iterators** (like those for `std::vector`, `std::deque`, `std::string`, or raw pointers) allow arithmetic operations such as adding an integer to an iterator (`iterator + N`) or subtracting one iterator from another (`iterator - iterator`).
    * `end - beg` calculates the **distance** (number of elements) between two iterators, which is a valid operation for random-access iterators. Dividing this distance by 2 gives an offset. Adding this offset to `beg` (`beg + offset`) moves `beg` forward by that many steps, correctly pointing to the midpoint.

2.  **Prevention of Integer/Pointer Overflow:**
    * Even if `beg + end` were somehow defined or implicitly cast to numerical types (which they aren't directly), summing two memory addresses (`beg` and `end`) could potentially lead to **integer overflow** if their numerical values are very large and exceed the capacity of the underlying integer type (e.g., `size_t` or `ptrdiff_t`). While less common with 64-bit systems, `(low + high) / 2` is a known potential pitfall for large indices in general programming contexts.
    * `beg + (end - beg) / 2` avoids this by first calculating the *difference* (which is typically smaller than the absolute addresses) and then adding that difference as an offset to the starting iterator.

In summary, `mid = beg + (end - beg) / 2;` is the correct and robust way to calculate a midpoint using iterators because:
* It adheres to the defined operations for iterators (subtracting iterators to get a distance, and adding an integral offset to an iterator).
* It avoids potential overflow issues that could arise from directly summing two large memory addresses.

## ch03_exrc_3p27

Exercise 3.27: Assuming txt_size is a function that takes no arguments and returns
an int value, which of the following definitions are illegal? Explain why.

```cpp
unsigned buf_size = 1024;
(a) int ia[buf_size]; (b) int ia[4 * 7 - 14];
(c) int ia[txt_size()]; (d) char st[11] = "fundamental";
```

(a) `int ia[buf_size];`: Illegal. In C++11 (and earlier C++ standards), the size of a built-in array declared on the stack or globally must be a constant expression. While `buf_size` is initialized with a constant literal, `buf_size` itself is a variable, not a `const` or `constexpr` variable. Its value is not guaranteed to be known at compile time in a way that makes it a constant expression for array sizing. This would be a Variable Length Array (VLA), which is a feature from C99 that some C++ compilers support as a non-standard extension, but it's not part of standard C++11.

(b) `int ia[4 * 7 - 14];`: Legal. It deduces to `int ia[14];`.

(c) `int ia[txt_size()];`: Legal only if `txt_size()` is `constexpr` otherwise error. A function call generally results in a run-time value. For the result of a function call to be used as a compile-time constant for an array size, the function itself must be declared `constexpr` (and all arguments to it, if any, must also be constant expressions). If `txt_size()` is just a regular function, its return value is not a compile-time constant, making the array definition illegal.

(d) `char st[11] = "fundamental";`: Illegal. error: no space for the null! String literals in C++ are null-terminated. The string `"fundamental"` contains 11 characters `(f, u, n, d, a, m, e, n, t, a, l)`. To store this string including its null terminator, you would need an array of size 12. Declaring `char st[11]` means there is only space for 11 characters, leaving no room for the mandatory null terminator, which leads to an error (or potentially a warning and truncation in some older compilers, but typically an error).

## ch03_exrc_3p28

Exercise 3.28: What are the values in the following arrays?

```cpp
string sa[10];
int ia[10];

int main() {
    string sa2[10];
    int ia2[10];
}
```

- `sa` will have 10 empty strings because the array has global scope.
- `ia` will have 10 elements (each 0) because the array has global scope.
- `sa2` will have 10 elements and each of them are default initialized to empty string.
- `ia2` will have 10 elements and each of them are *undefined* because the array has local scope.

## ch03_exrc_3p29

Exercise 3.29: List some of the drawbacks of using an array instead of a vector.

Here are some of the drawbacks of using a raw C-style array instead of an `std::vector`:

* **Fixed Size:** Arrays have a fixed size determined at compile time. Once declared, their size cannot be changed at runtime. If you need more or less space, you must create a new array and copy elements, which is cumbersome and error-prone.
* **No Dynamic Resizing:** Unlike `std::vector`, arrays cannot dynamically grow or shrink to accommodate varying amounts of data. This often leads to either allocating too much memory (wasting space) or too little (leading to overflow or undefined behavior).
* **No Bounds Checking (with `operator[]`):** When accessing array elements using the `[]` operator, there is no automatic runtime check to ensure the index is within the valid bounds of the array. Accessing an out-of-bounds index leads to **undefined behavior**, which can result in crashes, corrupted data, or security vulnerabilities. `std::vector` offers the `at()` method for bounds-checked access.
* **No Integrated Size Information:** Raw arrays do not store their own size. If you pass an array to a function, it "decays" to a pointer to its first element, losing information about its total size. You must typically pass the size as a separate argument, making code more error-prone. `std::vector` stores and provides its size (via `size()`) and capacity (via `capacity()`).
* **Difficult to Copy and Assign:** Raw arrays cannot be directly copied or assigned using the `=` operator (e.g., `array1 = array2;` is illegal for arrays). You must manually copy elements using a loop, `std::copy`, or `memcpy`. `std::vector` provides well-defined copy constructors and assignment operators for easy and safe deep copying.
* **Manual Memory Management (for dynamic arrays):** If you allocate an array dynamically using `new[]` (e.g., `int* arr = new int[10];`), you are solely responsible for deallocating that memory using `delete[]` when it's no longer needed. Failure to do so leads to **memory leaks**. `std::vector` handles all its memory management automatically using RAII, ensuring memory is properly allocated and deallocated.
* **Limited Functionality:** Raw arrays offer only basic access. `std::vector` provides a rich set of member functions for common operations like adding/removing elements (`push_back`, `pop_back`, `insert`, `erase`), clearing (`clear`), resizing (`resize`), and integrating seamlessly with standard library algorithms.

## ch03_exrc_3p30

Exercise 3.30: Identify the indexing errors in the following code:

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
    ia[ix] = ix;
```

**Correction:**

```cpp
for (size_t ix = 0; ix < array_size; ++ix)
    ia[ix] = ix;
```

## ch03_exrc_3p33

Exercise 3.33: What would happen if we did not initialize the scores array in the
program on page 116?

```cpp
// count the number of grades by clusters of ten: 0--9, 10--19, . . . 90--99, 100
unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
unsigned grade;

while (cin >> grade) {
    if (grade <= 100)
    ++scores[grade/10]; // increment the counter for the current cluster
}
```

If you did not initialize the `scores` array with `{}` in the program on page 116, changing it to:

```cpp
unsigned scores[11]; // No initializer
unsigned grade;

while (cin >> grade) {
    if (grade <= 100)
    ++scores[grade/10]; // increment the counter for the current cluster
}
```

This would lead to **undefined behavior**. Here's why:

1.  **Uninitialized Local Array:** The `scores` array is declared inside a function (likely `main`), giving it **automatic storage duration**. When a built-in type array with automatic storage duration is declared without an initializer (like `unsigned scores[11];`), its elements are **default-initialized**. For built-in types, default-initialization means the elements are **uninitialized**; they contain indeterminate ("garbage") values.

2.  **Reading Indeterminate Values:** The core of the loop is `++scores[grade/10];`. This operation first involves:
    * Reading the current value of `scores[grade/10]`.
    * Incrementing that value.
    * Writing the new value back to `scores[grade/10]`.

3.  **Undefined Behavior:** Since `scores[grade/10]` holds an indeterminate value, attempting to **read** that indeterminate value (in the first step of the increment operation) results in **undefined behavior**.

**Consequences of Undefined Behavior:**

* **Incorrect Counts:** The most immediate and likely consequence is that your grade counts will be completely wrong. Instead of starting from `0` and incrementing, you'd be adding `1` to some random, arbitrary number already in memory.
* **Program Crash:** The program might crash (e.g., with a segmentation fault) due to attempting to read from or write to memory in an invalid way, especially if the garbage value leads to an invalid memory address being calculated or accessed.
* **Unpredictable Behavior:** The program's behavior could be unpredictable. It might appear to work correctly sometimes, or it might produce different incorrect outputs on different runs or different systems. This makes debugging extremely difficult.

This is precisely why `unsigned scores[11] = {};` is crucial. It ensures that all elements of the `scores` array are **value-initialized to `0`**, providing a correct starting point for counting grades.

## ch03_exrc_3p34

Exercise 3.34: Given that `p1` and `p2` point to elements in the same array, what does the following code do? Are there values of `p1` or `p2` that make this code illegal?

```cpp
p1 += p2 - p1;
```

Considering the point that both `p1` and `p2` point to elements in the same array, any valid address from `p2` will the statement legal and if the `p2` is not valid then the statement will be illegal.

The given statement gets deduce as, `p1 = p1 + (p2 - p1);` which is same as `p1 = p1 + p2 - p1;` and again that is same as `p1 = p2;`. So the statements validity is completely dependent on `p2`.

## ch03_exrc_3p37

Exercise 3.37: What does the following program do?

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;

while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

The while loop may or may not stop looping after all the elements of the array are attended and will only stop if it encounters null character anywhere in the memory after the array.

## ch03_exrc_3p38

Exercise 3.38: In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

In this section we see that 

```cpp
const char ca1[] = "A string example";
const char ca2[] = "A different string";
```

With the intention of concatenating two character arrays (like we do in strings) if we write `ca1 + ca2`, it will not work. Because, here `ca1` and `ca2` are like pointers pointing to the first elements of their array. So, it will become a pointer arithmetic, in otherwords addition of two addresses.