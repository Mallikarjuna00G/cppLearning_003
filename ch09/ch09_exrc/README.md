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
  auto val3 = *(--last); // can't decrement forward_list iterators
  auto val4 = c.back(); // not supported by forward_list
}
```

- All the objects will have the same value.

---

## ch09_exrc_9p25

Exercise 9.25: In the program on page 349 that erased a range of elements, what happens 
- if `elem1` and `elem2` are equal? 
- What if `elem2` or both `elem1` and `elem2` are the off-the-end iterator?

**Given code:**

```cpp
// delete the range of elements between two iterators
// returns an iterator to the element just after the last removed element
elem1 = slist.erase(elem1, elem2); // after the call elem1 == elem2
```

Remember, `erase(first, last)` removes elements in the range `[first, last)`, meaning it includes `first` but **does not include `last`**. It returns an iterator to the element immediately following the last removed element.

### Case 1: `elem1` and `elem2` are equal

* **Outcome:** "Erase nothing"
* **Correctness:** **correct.**
    * If `elem1 == elem2`, the range `[elem1, elem2)` is an **empty range**.
    * No elements are erased.
    * The function will simply return `elem2` (which is equal to `elem1`).
    * This is a well-defined and common scenario, often used to indicate "erase nothing."

### Case 2: `elem2` is the off-the-end iterator (e.g., `slist.end()`), and `elem1` is a valid iterator (e.g., `slist.begin()` or somewhere in the middle).

* Passing `slist.end()` as the `last` iterator (`elem2`) is perfectly **valid and common**.
* `slist.erase(slist.begin(), slist.end())` is the standard way to **clear an entire `std::list`**.
* If `elem1` points to an element somewhere in the middle, and `elem2` is `slist.end()`, it will erase all elements from `elem1` up to the end of the list.
* The function will return `slist.end()` (or a valid iterator to the position that *was* `slist.end()`, now representing the new end of the list).
* There is no undefined behavior here.

### Case 3: Both `elem1` and `elem2` are the off-the-end iterator (`slist.end()`).

* If `elem1 == slist.end()` and `elem2 == slist.end()`, the range `[slist.end(), slist.end())` is an **empty range**.
* No elements are erased.
* The function will simply return `slist.end()`.
* This is also well-defined and does not lead to undefined behavior.

### Summary:

* **`elem1 == elem2` (including when both are `end()`):** No elements are erased. The function returns `elem2`. This is **well-defined**.
* **`elem2` is `end()` and `elem1` is not `end()`:** All elements from `elem1` up to the end of the container are erased. The function returns `slist.end()`. This is **well-defined**.

The only time `erase` (or almost any other standard library function) would lead to undefined behavior related to iterators is if you pass it an **invalid** iterator (e.g., one that has already been invalidated by a previous operation, or a default-constructed iterator) or an iterator that is outside the valid range `[begin(), end()]` for the container (except for `end()` itself, which is a valid boundary iterator).

---

## ch09_exrc_9p29

Exercise 9.29: Given that `vec` holds 25 elements, what does `vec.resize(100)` do? What if we next wrote `vec.resize(10)`?

```cpp
// vec.size() is 25.
vec.resize(100);  // vec.size() is 100. All the elements after 25th are value initialized.
vec.resize(10);  // vec.size() is 10. All the remaining elements are discarded.
```

---

## ch09_exrc_9p30

Exercise 9.30: What, if any, restrictions does using the version of `resize` that takes a single argument place on the element type?

For the version of `std::vector::resize` that takes a single argument (`vec.resize(count)`), the primary restriction it places on the element type (`T`) is that `T` must be **Default Constructible**.

**Explanation:**

When you call `vec.resize(count)` and `count` is greater than the current `vec.size()`, the vector needs to create and add `count - vec.size()` new elements. These new elements are **value-initialized**.

* **What "Value-Initialization" Means:**
    * For **built-in types** (like `int`, `double`, `bool`, pointers), value-initialization means they are **zero-initialized** (e.g., `0`, `0.0`, `false`, `nullptr`). This always works.
    * For **class types** (`T` is a class, struct, or union):
        * If `T` has a user-provided or implicitly-declared **default constructor**, that constructor is called to initialize the new elements.
        * If `T` has **no default constructor** (e.g., it only has constructors that take arguments, and you haven't explicitly provided a default one), then `resize(count)` will result in a **compilation error**.

**In summary:**

The element type `T` must have a way for the compiler to create an object of type `T` without any explicit arguments. This is typically achieved by having a public default constructor (either explicitly defined by you, or implicitly generated by the compiler if you don't define any constructors).

---

## ch09_exrc_9p31

Exercise 9.31: The program on page 354 to remove even-valued elements and duplicate odd ones will not work on a `list` or `forward_list`. Why? Revise the program so that it works on these types as well.

**Given code from page 354**

```cpp
// silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
while (iter != vi.end()) {
  if (*iter % 2) {
    iter = vi.insert(iter, *iter); // duplicate the current element
    iter += 2; // advance past this element and the one inserted before it
  } else
    iter = vi.erase(iter); // remove even elements
    // don't advance the iterator; iter denotes the element after the one we erased
}
```

The `std::vector` specific code provided **would not directly work** on `std::list` or `std::forward_list`.

### Reasons Why `std::vector` Code Fails for `std::list` and `std::forward_list`:

The core issue lies in the **iterator categories** and the specific member functions available for each container.

1.  **`iter += 2;` (Random Access Requirement):**
    * **`std::vector`:** Its iterators are **Random Access Iterators**. This means you can directly add or subtract an integer to/from an iterator (e.g., `iter + 2`, `iter - 1`, `iter[i]`). This is efficient because `std::vector` stores elements contiguously in memory, so moving `N` positions is a simple pointer arithmetic operation.
    * **`std::list`:** Its iterators are **Bidirectional Iterators**. They only support `++` (increment) and `--` (decrement). They **do NOT support random access arithmetic** like `iter += 2`. Attempting this will result in a **compilation error**.
    * **`std::forward_list`:** Its iterators are **Forward Iterators**. They only support `++` (increment). They **do NOT support random access arithmetic** like `iter += 2`. Attempting this will result in a **compilation error**.

    *To fix this for `std::list` and `std::forward_list`, you'd need to use `iter++; iter++;` or `std::advance(iter, 2);`.*

2.  **`container.erase(iter);` (Iterator Position for Erasure):**
    * **`std::vector`:** The `vector::erase(iterator pos)` member function removes the element *at* the position pointed to by `pos`. This is standard for `vector` and `list`.
    * **`std::list`:** The `list::erase(iterator pos)` member function also removes the element *at* the position pointed to by `pos`. So, this specific part of the code *would* work for `std::list` in terms of the function call itself.
    * **`std::forward_list`:** This is where it fundamentally breaks for `forward_list`. `std::forward_list` **does NOT have an `erase(iterator pos)` member function**. It only has `erase_after(iterator pos_before_element_to_erase)`. You cannot erase an element directly using an iterator pointing *to* it. You must have an iterator pointing to the element *before* it. Attempting `container.erase(iter)` on a `std::forward_list` will result in a **compilation error**.

    *To fix this for `std::forward_list`, you absolutely need to maintain a `cPrev` (or `iterPrev`) iterator and use `container.erase_after(iterPrev);`.*

3.  **`container.insert(iter, *iter);` (Iterator Position for Insertion):**
    * **`std::vector`:** The `vector::insert(iterator pos, const T& value)` member function inserts `value` *before* the element pointed to by `pos`. This is standard for `vector` and `list`.
    * **`std::list`:** The `list::insert(iterator pos, const T& value)` member function also inserts `value` *before* the element pointed to by `pos`. So, this specific part of the code *would* work for `std::list` in terms of the function call itself.
    * **`std::forward_list`:** Similar to `erase`, `std::forward_list` **does NOT have an `insert(iterator pos, const T& value)` member function**. It only has `insert_after(iterator pos_before_insertion_point, const T& value)`. You cannot insert directly using an iterator pointing *to* the insertion point. You must have an iterator pointing to the element *before* the desired insertion point. Attempting `container.insert(iter, *iter)` on a `std::forward_list` will result in a **compilation error**.

    *To fix this for `std::forward_list`, you absolutely need to maintain a `cPrev` (or `iterPrev`) iterator and use `container.insert_after(iterPrev, *iter);`.*

In essence, the `std::vector` code relies on its iterators being random-access and its `erase`/`insert` functions operating on the element *at* the iterator. `std::list` lacks random-access but has the same `erase`/`insert` semantics. `std::forward_list` lacks both random-access *and* requires operations to be performed using an iterator to the *preceding* element. This is why a separate implementation is needed for each.

---

## ch09_exrc_9p32

Exercise 9.32: In the program on page 354 would it be legal to write the call to `insert` as follows? If not, why not?

```cpp
iter = vi.insert(iter, *iter++);
```

**Given code from page 354**

```cpp
// silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
while (iter != vi.end()) {
  if (*iter % 2) {
    iter = vi.insert(iter, *iter); // duplicate the current element
    iter += 2; // advance past this element and the one inserted before it
  } else
    iter = vi.erase(iter); // remove even elements
    // don't advance the iterator; iter denotes the element after the one we erased
}
```


### Analysis of `iter = vi.insert(iter, *iter++);`

1.  **`*iter++` expression:**
    * The `*` (dereference) operator has lower precedence than `++` (post-increment).
    * So, `iter++` is evaluated first:
        * The **original value** of `iter` (the iterator itself) is used for the dereference.
        * Then, `iter` is **incremented** (moved to the next element).
    * The result of `*iter++` is the **value of the element** that `iter` *originally* pointed to. This value is passed as the second argument to `vi.insert()`.

2.  **`vi.insert(iter, value)` function call:**
    * The first `iter` argument specifies the position where the `value` (from `*iter++`) should be inserted.
    * The `iter` used for the first argument is the `iter` *before* the post-increment from `*iter++` takes effect (conceptually).

### The Problem: Undefined Behavior

The issue is that the `iter` object is **modified** (by `iter++`) and also **read** (as the first argument to `insert`) within the same full expression, without a sequence point in between that guarantees the order of these operations.

According to C++ rules (specifically, the rules regarding unsequenced operations, clarified in C++11 and C++17):
* If an object is modified, and any other access to it (read or write) is unsequenced relative to that modification, the behavior is **Undefined Behavior**.

In `vi.insert(iter, *iter++)`:
* `iter` is read for the first argument of `insert`.
* `iter` is also modified by the post-increment `iter++`.

Since the order of evaluation of function arguments is **unspecified**, the compiler is free to evaluate `iter` (the first argument) and `*iter++` (the second argument, which modifies `iter`) in any order. If `iter++` happens *before* the first `iter` argument is used, or if the side effect of `iter++` happens at an unpredictable time relative to the read of `iter` for the first argument, you have Undefined Behavior.

**Therefore, the call `iter = vi.insert(iter, *iter++);` is NOT legal.**

---

## ch09_exrc_9p33

Exercise 9.33: In the final example in this section what would happen if we did not assign the result of `insert` to `begin`? Write a program that omits this assignment to see if your expectation was correct.

**Given code:**

```cpp
auto begin = v.begin();
// safer: recalculate end on each trip whenever the loop adds/erases elements
while (begin != v.end()) {
  // do some processing
  ++begin; // advance begin because we want to insert after this element
  begin = v.insert(begin, 42); // insert the new value
  ++begin; // advance begin past the element we just added
}
```

* **Issue:** Leads to **Undefined Behavior (UB)**, not just an infinite loop or "unnecessary work."
* **Reason:** `std::vector::insert()` (and `erase()`) can **invalidate iterators** to its elements, especially if the vector reallocates memory (which `insert` often causes).
* **Consequence:** If you don't reassign `begin` with the new, valid iterator returned by `insert()`, `begin` will continue to point to old, potentially deallocated memory. Subsequent uses of this invalidated `begin` (e.g., in the loop condition `begin != v.end()` or `++begin`) result in UB, leading to crashes or unpredictable program behavior.

**Code:** [ch09_exrc_9p33](./ch09_exrc_9p33/)

```console
./a.out
Before insert call: 
0 1 2 3 4 5 6 7 8 9 
After insert call: 
0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
97 0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 97 0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 0 0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 0 0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
After insert call: 
0 0 0 0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
------------------------------------
Before insert call: 
0 0 0 0 0 0 0 97 0 0 42 1 2 3 4 5 6 7 8 9 
free(): invalid pointer
make: *** [Makefile:59: run] Aborted (core dumped)
```

---

## ch09_exrc_9p34

Exercise 9.34: Assuming `vi` is a container of `int`s that includes even and odd values, predict the behavior of the following loop. After you've analyzed this loop, write a program to test whether your expectations were correct.


```cpp
iter = vi.begin();
while (iter != vi.end())
  if (*iter % 2)
    iter = vi.insert(iter, *iter);
  ++iter;
```

- This will eventually lead to segmentation fault through infinite looping. Once an odd number is detected, that element will keep getting duplicated and the `iter` keeps pointing to the same odd element.


Assume,

```cpp
vector<int> v = {0,1,2,3,4,5,6,7,8,9};
```

This will become,

```console
0, 1, 1, 1, 1, 1, 1, 1, .........................
```

**Code:** [ch09_exrc_9p34](./ch09_exrc_9p34/) <br/>*NOTE: This will run indefinitely.*

## ch09_exrc_9p35

Exercise 9.35: Explain the difference between a `vector`’s `capacity` and its `size`.

**`Size`** is the number of elements currently stored in the `vector`. It reflects the logical number of elements you can access or iterate over.

**`Capacity`** is the total number of elements the `vector` can hold before it needs to reallocate memory to accommodate more elements. It represents the physical memory allocated for the `vector`'s storage.

Think of it like a train: the **`size`** is the number of passengers currently on the train, while the **`capacity`** is the total number of seats available. Even if the train has 50 seats (**capacity**), there might only be 20 passengers on it (**size**). If a 21st passenger boards, the **size** increases, but the **capacity** remains the same. If the 51st passenger tries to board, the train must add a new car, increasing its **capacity**.

---

## ch09_exrc_9p36

Exercise 9.36: Can a container have a `capacity` less than its `size`?

A container's `capacity` can **never** be less than its `size`.

The `capacity` represents the total physical memory allocated for the elements, while the `size` is the number of elements currently occupying that space. It's impossible for a container to hold more elements than the memory it has reserved. When a `vector`'s `size` reaches its `capacity`, it must reallocate a larger block of memory before it can add another element.

---

## ch09_exrc_9p37

Exercise 9.37: Why don’t `list` or `array` have a `capacity` member?

Neither `list` nor `array` have a `capacity` member because of how they manage their memory.

* A **`list`** is implemented as a doubly-linked list. Each element is an independent object that contains both the data and pointers to the previous and next elements. New elements are added dynamically and can be placed anywhere in the list without needing a contiguous block of memory. Therefore, there is no concept of a single, reserved block of memory that might need to be reallocated. The size and capacity are effectively the same at all times.

* An **`array`** is a fixed-size, contiguous block of memory. When you define an `array`, its size is set at compile-time and cannot change. The memory for all its elements is allocated upfront. Since its size is fixed, it doesn't need to track a separate `capacity`—its `size` is its `capacity`.

---

## ch09_exrc_9p39

Exercise 9.39: Explain what the following program fragment does:

```cpp
vector<string> svec;
svec.reserve(1024);

string word;
while (cin >> word)
  svec.push_back(word);

svec.resize(svec.size()+svec.size()/2);
```

This program fragment reads words from standard input and stores them in a `vector<string>`. The `reserve` call pre-allocates memory to avoid multiple reallocations, and the `resize` call then increases the size of the vector.

Here's a step-by-step breakdown:

* **`vector<string> svec;`**: A `vector` named `svec` is created to hold `string` objects.
* **`svec.reserve(1024);`**: This line pre-allocates memory for at least 1024 strings. This is a performance optimization that prevents the `vector` from having to reallocate its internal buffer as it grows, which can be an expensive operation. The `size` of the vector remains 0.
* **`while (cin >> word) svec.push_back(word);`**: This loop reads words from standard input (e.g., from the keyboard or a redirected file) one by one and adds them to `svec`. The `size` of the vector grows with each word read.
* **`svec.resize(svec.size() + svec.size()/2);`**: After the loop finishes, this line resizes the vector. The new size is the current size plus half of the current size, effectively increasing the number of elements in the vector by 50%. The new elements are default-initialized (empty strings). If the new size is larger than the current capacity, the vector will reallocate memory to accommodate the change.

[ch09_exrc_9p39](./ch09_exrc_9p39/)

```console
$ make run_app/fast 
Running application ch09_exrc_9p38
On fresh declaration: 
Vector (size : capacity) :: 0 : 0
On reserve(1024): 
Vector (size : capacity) :: 0 : 1024
While feeding: 
their time
Vector (size : capacity) :: 1 : 1024
Vector (size : capacity) :: 2 : 1024
can't go back
Vector (size : capacity) :: 3 : 1024
Vector (size : capacity) :: 4 : 1024
Vector (size : capacity) :: 5 : 1024
they will laugh
Vector (size : capacity) :: 6 : 1024
Vector (size : capacity) :: 7 : 1024
Vector (size : capacity) :: 8 : 1024
once they drown inside my love
Vector (size : capacity) :: 9 : 1024
Vector (size : capacity) :: 10 : 1024
Vector (size : capacity) :: 11 : 1024
Vector (size : capacity) :: 12 : 1024
Vector (size : capacity) :: 13 : 1024
Vector (size : capacity) :: 14 : 1024
After resize 
Vector (size : capacity) :: 21 : 1024
```