# ch09_exrc

# ch09_exrc_9p1

Exercise 9.1: Which is the most appropriate—a `vector`, a `deque`, or a `list`—for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.

(a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We'll see in the next chapter that associative containers are better suited to this problem.

(b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front. 

(c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

### (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered.

* **Most Appropriate:** **`std::list`**
* **Rationale:**
    * **`std::vector` (less appropriate):** While a `vector` is efficient for adding elements to the *back* (amortized constant time), inserting elements *into the middle* (to maintain alphabetical order as they are entered) is an **expensive $O(N)$ operation**. Each insertion requires shifting all subsequent elements. For a "fixed number" that might still be large, this becomes very inefficient.
    * **`std::deque` (less appropriate):** Similar to `vector`, inserting into the middle of a `deque` is also an $O(N)$ operation.
    * **`std::list` (most appropriate):** A `list` is designed for **efficient insertion and deletion anywhere in the container ($O(1)$ operation, once the position is found)**. To insert alphabetically, you'd iterate to find the correct spot, and then insertion is fast. This makes `list` much more suitable for dynamically maintaining sorted order with frequent middle insertions.

### (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.

* **Most Appropriate:** **`std::deque`**
* **Rationale:**
    * This scenario perfectly describes a **queue-like behavior** (First-In, First-Out).
    * **`std::vector` (less appropriate):** While `vector` can efficiently `push_back` (amortized constant time), `erase` from the *front* is an expensive $O(N)$ operation as it requires shifting all remaining elements.
    * **`std::list` (also appropriate):** `list` also provides efficient `push_back` and `pop_front` (both $O(1)$).
    * **`std::deque` (most appropriate):** A `deque` (double-ended queue) is specifically optimized for **efficient insertions and deletions at *both* ends ($O(1)$ operations)**. It also offers constant-time random access like `vector` (though not required here), and generally has better cache performance than `list` due to its block-based memory allocation. It's the canonical choice for this kind of "queue" behavior.

### (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

* **Most Appropriate:** **`std::vector`**
* **Rationale:**
    * **`std::vector` (most appropriate):**
        * Efficiently handles an unknown number of elements by dynamically resizing (`push_back` is amortized constant time).
        * Crucially, `std::vector` stores its elements **contiguously in memory**. This is essential for algorithms like `std::sort`, which performs optimally on random-access iterators operating on contiguous memory, leveraging CPU cache efficiently.
    * **`std::deque` (also appropriate):** `deque` also provides random-access iterators and can be sorted efficiently with `std::sort`, though its memory might be split into blocks, which could slightly impact cache performance compared to `vector` for very large sorts.
    * **`std::list` (less appropriate):** `std::sort` *cannot* be used directly on `std::list` because `list` iterators are not random-access. While `list` has its own `sort()` member function, sorting a `list` is generally slower than sorting a `vector` or `deque` for large datasets due to the scattered memory layout and lack of random access.

---

## ch09_exrc_9p2

Exercise 9.2: Define a `list` that holds elements that are `deque`s that hold `int`s.

```cpp
list<deque<int>> ls;
```

## Exercise 9.3: What are the constraints on the iterators that form iterator ranges?

The constraints on the iterators that form a valid range (e.g., for constructors, `insert`, `erase` operations) are:

1.  **They must refer to elements in the same container.** You cannot use iterators from two different containers to define a single range.
2.  **The "end" iterator must not precede the "begin" iterator.** Conceptually, `begin` must be at or before `end`. Specifically, the range is typically defined as `[begin, end)`, meaning it includes elements from `begin` up to, but *not including*, `end`. The `end` iterator can be the `container.end()` sentinel.

Violating these constraints typically leads to **undefined behavior**.

---

## ch09_exrc_9p6

Exercise 9.6: What is wrong with the following program? How might you correct it?

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

The fundamental problem with the `while (iter1 < iter2)` condition for `std::list` iterators is that:

  * **`std::list` iterators are not random-access iterators.** They are **bidirectional iterators**.

**What this means:**

  * **Bidirectional iterators** (like those for `std::list`) only guarantee support for `==`, `!=`, `++`, and `--` operators. They can move forward and backward one step at a time.
  * They **do not support relational operators** like `<`, `>`, `<=`, or `>=`. These operators are only guaranteed for **random-access iterators** (like those for `std::vector` and `std::deque`) because those iterators have a concept of "position" or "distance" that can be compared.

---

## ch09_exrc_9p7

Exercise 9.7: What type should be used as the index into a `vector` of `int`s?

`std::vector<int>::size_type`.

---

## ch09_exrc_9p8

Exercise 9.8: What type should be used to read elements in a list of `string`s? To write them?

- To write elements: `std::list<string>::iterator`
- To read elements: `std::list<string>::const_iterator`

--- 

## ch09_exrc_9p9

Exercise 9.9: What is the difference between the `begin` and `cbegin` functions?

* **`begin()`**: Returns a **`iterator`** (mutable), allowing modification of the element it points to.
* **`cbegin()`**: Returns a **`const_iterator`** (non-mutable), preventing modification of the element it points to, regardless of whether the container itself is `const`. Use for read-only access.

---

## ch09_exrc_9p10

Exercise 9.10: What are the types of the following four objects?

```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

- `it1` is `iterator`.
- `it2` is `const_iterator`.
- `it3` is `const_iterator`.
- `it4` is `const_iterator`.

---

## ch09_exrc_9p11

Exercise 9.11: Show an example of each of the six ways to create and initialize a `vector`. Explain what values each `vector` contains.

Here are examples of the six common ways to create and initialize a `std::vector`, along with an explanation of what each vector will contain:

-----

### 1\. Default Initialization (Empty Vector)

  * **Syntax:** `std::vector<T> v;`
  * **Explanation:** Creates an **empty** `vector`. It has no elements, and its `size()` is 0.

<!-- end list -->

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v1;
    // v1 is empty. v1.size() is 0.
    std::cout << "v1 size: " << v1.size() << std::endl;
    return 0;
}
```

-----

### 2\. Copy Initialization (from another vector)

  * **Syntax:** `std::vector<T> v2(v1);` or `std::vector<T> v2 = v1;`
  * **Explanation:** Creates a new `vector` as a **copy** of an existing `vector`. The new vector will have the same size and contain copies of all the elements from the source vector.

<!-- end list -->

```cpp
#include <vector>
#include <iostream>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    std::vector<std::string> v2(words); // Copy constructor
    // v2 contains {"apple", "banana", "cherry"}
    
    std::vector<std::string> v3 = words; // Copy assignment-like syntax (still copy construction)
    // v3 also contains {"apple", "banana", "cherry"}

    std::cout << "v2 contents:";
    for (const auto& s : v2) { std::cout << " " << s; }
    std::cout << std::endl;
    return 0;
}
```

-----

### 3\. List Initialization (using an initializer list)

  * **Syntax:** `std::vector<T> v = {elem1, elem2, ...};` or `std::vector<T> v{elem1, elem2, ...};`
  * **Explanation:** Creates a `vector` and initializes its elements directly from a braced **initializer list**. The vector will contain exactly the elements specified in the list, in that order.

<!-- end list -->

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<double> v4 = {1.1, 2.2, 3.3, 4.4};
    // v4 contains {1.1, 2.2, 3.3, 4.4}
    
    std::vector<char> v5{'A', 'B', 'C'}; // Direct list initialization
    // v5 contains {'A', 'B', 'C'}

    std::cout << "v4 contents:";
    for (const auto& d : v4) { std::cout << " " << d; }
    std::cout << std::endl;
    return 0;
}
```

-----

### 4\. Constructor with Count and Element Value

  * **Syntax:** `std::vector<T> v(n, val);`
  * **Explanation:** Creates a `vector` with `n` elements, where each element is a **copy of `val`**.

<!-- end list -->

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v6(5, 100);
    // v6 contains five integer elements, each with the value 100: {100, 100, 100, 100, 100}
    std::cout << "v6 contents:";
    for (const auto& i : v6) { std::cout << " " << i; }
    std::cout << std::endl;
    return 0;
}
```

-----

### 5\. Constructor with Count (Value-Initialized Elements)

  * **Syntax:** `std::vector<T> v(n);`
  * **Explanation:** Creates a `vector` with `n` elements.
      * If `T` is a **built-in type** (like `int`, `double`, `char`), the elements are **value-initialized** (typically to 0 for numeric types, `nullptr` for pointers, etc.).
      * If `T` is a **class type**, the elements are **default-constructed**.

<!-- end list -->

```cpp
#include <vector>
#include <iostream>
#include <string>

int main() {
    std::vector<int> v7(3);
    // v7 contains three default-initialized ints (value-initialized to 0): {0, 0, 0}
    std::cout << "v7 contents:";
    for (const auto& i : v7) { std::cout << " " << i; }
    std::cout << std::endl;

    std::vector<std::string> v8(2);
    // v8 contains two default-constructed (empty) strings: {"", ""}
    std::cout << "v8 contents (size of strings): " << v8[0].size() << ", " << v8[1].size() << std::endl;
    return 0;
}
```

-----

### 6\. Constructor with Iterator Range

  * **Syntax:** `std::vector<T> v(begin_iterator, end_iterator);`
  * **Explanation:** Creates a `vector` and initializes its elements by copying elements from the range defined by `begin_iterator` (inclusive) and `end_iterator` (exclusive). This range can come from any container (e.g., another `vector`, a `list`, an array, or even a C-style string).

<!-- end list -->

```cpp
#include <vector>
#include <iostream>
#include <list> // For std::list example

int main() {
    std::list<double> my_list = {10.5, 20.5, 30.5};
    std::vector<double> v9(my_list.begin(), my_list.end());
    // v9 contains {10.5, 20.5, 30.5} (copied from my_list)
    std::cout << "v9 contents:";
    for (const auto& d : v9) { std::cout << " " << d; }
    std::cout << std::endl;

    int arr[] = {1, 2, 3, 4};
    std::vector<int> v10(std::begin(arr), std::end(arr));
    // v10 contains {1, 2, 3, 4} (copied from the array)
    std::cout << "v10 contents:";
    for (const auto& i : v10) { std::cout << " " << i; }
    std::cout << std::endl;
    return 0;
}
```

---

## ch09_exrc_9p12

Exercise 9.12: Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

Here's a brief explanation of the differences between the two `std::vector` constructors:

---

### Constructor 1: Copy from a Container
* **Syntax Example:** `std::vector<int> v2(v1);` or `std::vector<int> v2 = v1;` (where `v1` is another `std::vector`).
* **Source:** Takes an entire `std::vector` (or other compatible container) as the source.
* **Scope:** Copies **all elements** from the source container.
* **Type Requirement:** The source container's element type must be convertible to the new vector's element type. The source container must be an `std::vector` of the exact or convertible type.
* **Flexibility:** Less flexible. You copy the whole container.

---

### Constructor 2: Copy from an Iterator Range
* **Syntax Example:** `std::vector<int> v3(it_begin, it_end);`
* **Source:** Takes a pair of iterators defining a range `[it_begin, it_end)`.
* **Scope:** Copies elements **only within the specified range**. This range can be a partial view of a container, or from a different container type.
* **Type Requirement:** The elements accessible through the iterators must be convertible to the new vector's element type. The iterators can come from *any* container that provides at least Input Iterators (e.g., `std::vector`, `std::list`, `std::array`, even C-style arrays or streams).
* **Flexibility:** More flexible. You can copy a sub-section of data, or data from a different container type (as long as element types are compatible).

---

**In essence:** The **copy constructor** is for copying an **entire vector (or compatible container)**, while the **range constructor** is for copying a **specific sequence of elements** from any source that provides iterators.

---

## ch09_exrc_9p13

Exercise 9.13: How would you initialize a `vector<double>` from a `list<int>`? From a `vector<int>`? Write code to check your answers.

```cpp
list<int> l1 = {10, 23, 4, 45, 67};
vector<double> d1(l1.begin(), l1.end());

vector<int> v1 = {23, 45, 67, 77, 33};
vector<double> d2(v1.begin(), v1.end());
```

[ch09_exrc_9p13](./ch09_exrc_9p13/)

---

## ch09_exrc_9p17

Exercise 9.17: Assuming `c1` and `c2` are containers, what (if any) constraints does the following usage place on the types of `c1` and `c2`?

```cpp
if (c1 < c2)
```

If you use `if (c1 < c2)` with standard C++ containers:

1.  **The container types shall be the same.**
    * You cannot directly compare, for example, a `std::vector<int>` with a `std::list<int>` using `operator<`. The `operator<` is overloaded by each container class to compare instances *of its own type*. There's no built-in `operator<` that knows how to compare a `std::vector` with a `std::list` directly.
    * To compare different container types (as you did with `seqContainerCompare`), you need a custom function or algorithm.

2.  **Along with the above requirement, the types of the elements in the container also shall match (and be comparable).**
    * Even if the container types are the same (e.g., `std::vector<int>` and `std::vector<double>`), the `operator<` for the container will try to compare their elements (`int < double` in this case, which works).
    * More generally, the element types must have a defined `operator<` (or a custom comparison predicate, in more advanced scenarios) for the container's `operator<` to work. If you had `std::vector<MyCustomClass>` and `MyCustomClass` didn't define `operator<`, then `v1 < v2` would fail even if `v1` and `v2` were both `std::vector<MyCustomClass>`.

So, for `if (c1 < c2)` to compile and be valid in the standard library context, `c1` and `c2` must be of the **exact same container type**, and the **elements they store must be comparable using `operator<`**.

---

## ch09_exrc_9p21

Exercise 9.21: Explain how the loop from page 345 that used the return from `insert` to add elements to a `list` would work if we inserted into a `vector` instead.

**Code from page 345:**

```cpp
list<string> lst;
auto iter = lst.begin();
while (cin >> word)
  iter = lst.insert(iter, word); // same as calling push_front
```

The code fragment would work identically in terms of its **functional outcome** (reading words from input and effectively prepending them to the container) if we just change the object type from `std::list` to `std::vector`.

```cpp
vector<string> vec;
auto iter = vec.begin(); // Initially, iter points to vec.begin() (which is also vec.end() if empty)
string word;
while (cin >> word)
  iter = vec.insert(iter, word); // This line is the key
```

Here's why it works, and what the important underlying differences are:

### Why it Works (Functional Correctness)

Both `std::list::insert` and `std::vector::insert` have an overload that takes a position iterator and a value, and importantly, **both return an iterator to the newly inserted element.**

  * **Initial state:** `iter` starts pointing to `vec.begin()` (which is also `vec.end()` if `vec` is empty).
  * **First iteration:** `vec.insert(iter, word)` inserts `word` at the beginning. The `insert` function then returns a valid iterator to this newly inserted `word`. This returned iterator is immediately assigned back to `iter`. So, `iter` now points to the first element (which is the `word` just inserted).
  * **Subsequent iterations:** In each subsequent loop, `iter` will still be pointing to the "current beginning" (the element that was most recently inserted, which is now the first element). `vec.insert(iter, word)` again inserts the new `word` *before* the element that `iter` points to, and `iter` is updated to point to this *new* first element.

This repeated insertion at `iter` (which is always updated to point to the new first element) effectively simulates `push_front()` behavior for both `std::list` and `std::vector`.

### Key Differences (Underlying Mechanics and Efficiency)

While functionally correct, the underlying performance and behavior of `insert` are vastly different:

1.  **Iterator Invalidation:**

      * **`std::list::insert`**: Does **not** invalidate any iterators (except the `end()` iterator if a new element becomes the last). Insertion is done by modifying pointers.
      * **`std::vector::insert`**: This is the crucial difference. When you insert an element into a `vector` anywhere other than the very end, all iterators from the insertion point to the end of the vector (including the one passed as `iter` if it pointed to an element that moved) are **invalidated**. If the `vector` needs to reallocate its memory (which happens when its `capacity` is exceeded), *all* iterators and references to elements become invalidated. The reason our code still works is because the `vec.insert(iter, word)` call **returns a *new, valid* iterator** to the newly inserted element, which you immediately reassign to `iter`. This pattern effectively "revalidates" `iter` in each step.

2.  **Performance:**

      * **`std::list::insert` at `begin()`:** This is an `O(1)` operation (constant time). Very efficient.
      * **`std::vector::insert` at `begin()`:** This is an `O(N)` operation (linear time), where `N` is the number of elements in the vector. Every time you insert at the beginning, all existing elements must be shifted to make room. This makes inserting many elements at the beginning of a vector very inefficient. Additionally, if reallocations occur, the cost is even higher due to copying all elements to a new memory block.

**In summary:** Yes, the loop will work correctly for `std::vector` because `vector::insert` returns a valid iterator. However, this pattern is **highly inefficient** for `std::vector` when inserting at the beginning (or anywhere other than the end), making `std::list` the far more appropriate choice for such an operation. For `vector`, `push_back` is efficient for appending, but there's no efficient `push_front`.

## ch09_exrc_9p22

Exercise 9.22: Assuming `iv` is a vector of `int`s, what is wrong with the following program? How might you correct the problem(s)?

```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
  if (*iter == some_val)
    iv.insert(iter, 2 * some_val);
```

- `iter` and `mid` gets invalidated on first pass condition of `*iter == some_val`, after which behavior of `iter != mid` is undefined.

**Correction:**

```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid) {
  if (*iter == some_val) {
    iter = iv.insert(iter, 2 * some_val);
    mid = iv.begin() + iv.size() / 2;
  }
  iter++;
}
```

---

## ch09_exrc_9p23

Exercise 9.23: In the first program in this section on page 346, what would the values of `val`, `val2`, `val3`, and `val4` be if `c.size()` is 1?

**Given code fragment:** 

```cpp
// check that there are elements before dereferencing an iterator or calling front or back
if (!c.empty()) {
  // val and val2 are copies of the value of the first element in c
  auto val = *c.begin(), val2 = c.front();
  // val3 and val4 are copies of the of the last element in c
  auto last = c.end();
  auto val3 = *(--last); // can’t decrement forward_list iterators
  auto val4 = c.back(); // not supported by forward_list
}
```

- All the objects will have the same value.