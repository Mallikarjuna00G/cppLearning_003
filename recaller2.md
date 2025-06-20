# Revisit Notes

**NOTE: This is just a notes captured during my revision and does not have consistency but just my understandings and the points I thought of capturing.**

# CH03: Strings, vectors and Arrays

- A `string` is a variable-length sequence of characters.
- A `vector` holds a variable-length sequence of objects of a given type. - Built-in array type. Like other built-in types, arrays represent facilities of the hardware.

- the scope operator (`::`)
- which says that the compiler should look in the scope of the left-hand operand for the name of the right-hand operand.
- Thus, `std::cin` says that we want to use the name `cin` from the namespace `std`.

#### Headers Should Not Include `using` Declarations
- Code inside headers ordinarily should not use `using` declarations.
- The reason is that the contents of a header are copied into the including program's text. If a header has a `using` declaration, then every program that includes that header gets that same `using` declaration. As a result, a program that didn't intend to use the specified library name might encounter unexpected name conflicts.

## 3.2 Library `string` Type

- A `string` is a variable-length sequence of characters.
- Header: `header`
- `using std::string`

### 3.2.1 Defining and Initializing strings

- Common ways to initialize strings.

```cpp
string s1; // default initialization; s1 is the empty string
string s2 = s1; // s2 is a copy of s1. copy initialization.
string s3 = "hiya"; // s3 is a copy of the string literal. copy initialization. Trailing null character not copied to s3 in case of copy initialization using literal.
string s4(10, 'c'); // s4 is cccccccccc. Direct initialization
```


#### Direct and Copy Forms of Initialization

- When we have a single initializer, we can use either the direct or copy form of initialization.
- When we initialize a variable from more than one value, such as in the initialization of `s4` above, we must use the direct form of initialization.

```cpp
string s5 = "hiya"; // copy initialization
string s6("hiya"); // direct initialization
string s7(10, 'c'); // direct initialization; s7 is cccccccccc
```

```cpp
string s8 = string(10, 'c'); // copy initialization; s8 is cccccccccc
```

is same as 

```cpp
string temp(10, 'c'); // temp is cccccccccc
string s8 = temp; // copy temp into s8
```

#### Table 3.1: Ways to Initialize a string
|||
|---|---|
|`string s1` |***Default initialization***; `s1` is the empty string.|
|`string s2(s1)` |`s2` is a copy of `s1`. ***Direct initialization***.|
|`string s2 = s1` |Equivalent to `s2(s1)`, `s2` is a copy of `s1`. ***Copy initialization***.|
|`string s3("value")` |`s3` is a copy of the string literal, not including the **null**. ***Direct initialization***.|
|`string s3 = "value"` |Equivalent to `s3("value")`, `s3` is a copy of the string literal. ***Copy initialization***. No null character at the end in `s3`.|
|`string s4(n, 'c')` |Initialize s4 with `n` copies of the character `'c'`. ***Direct initialization***.|

### 3.2.2 Operations on `string`s

```cpp
// Note: #include and using declarations must be added to compile this code
int main()
{
    string s; // empty string
    cin >> s; // read a whitespace-separated string into s
    cout << s << endl; // write s to the output
    return 0;
}
```

#### Table 3.2: `string` Operations

|||
|---|---|
|`os << s` |Writes `s` onto output stream `os`. Returns `os`.|
|`is >> s` |Reads whitespace-separated string from `is` into `s`. Returns `is`.|
|`getline(is, s)` |Reads a line of input from `is` into `s`. Returns `is`.|
|`s.empty()` |Returns `true` if `s` is empty; otherwise returns `false`.|
|`s.size()` |Returns the number of characters in `s`.|
|`s[n]` |*Returns a reference* to the `char` at position `n` in `s`; positions start at `0`.|
|`s1 + s2` |Returns a `string` that is the concatenation of `s1` and `s2`.|
|`s1 = s2` |Replaces characters in `s1` with a copy of `s2`.|
|`s1 == s2`|The strings `s1` and `s2` are equal if they contain the same characters.|
|`s1 != s2`|Equality is case-sensitive.|
|`<`, `<=`, `>`, `>=` |Comparisons are case-sensitive and use dictionary ordering.|

```cpp
string s1, s2;
cin >> s1 >> s2; // read first input into s1, second into s2. Chaining.
cout << s1 << s2 << endl; // write both strings. Chaining.
```

#### Using `getline` to Read an Entire Line

- Sometimes we do not want to ignore the whitespace in our input.
- Use the `getline` function instead of the `>>` operator.

- The function `getline` takes an input stream and a string. This function reads the given stream up to and including the first newline and stores what it read—not including the newline—in its string argument.

- `getline` returns its `istream` argument. We can use `getline` as a condition.

```cpp
int main()
{
    string line;
    // read input a line at a time until end-of-file
    while (getline(cin, line))
    cout << line << endl;
    return 0;
}
```

- Reminder. we use `endl` to end the current line and flush the buffer.

#### The `string` `empty` and `size` Operations

#### The `string::size_type` Type

- `size` returns a `string::size_type` value

- The `string` class—and most other library types—defines several companion types. These companion types make it possible to use the library types in a machine-independent manner. The type size_type is one of these companion types.

- Although we don't know the precise type of `string::size_type`, we do know that **it is an `unsigned type`** big enough to hold the size of any string.

- Any variable used to store the result from the string size operation
should be of type `string::size_type`.

#### Adding Literals and strings

```cpp
string s1 = "hello", s2 = "world"; // no punctuation in s1 or s2
string s3 = s1 + ", " + s2 + '\n';
```

- When we mix strings and `string` or character literals, at least one operand to each `+` operator must be of `string` type.

```cpp
string s4 = s1 + ", "; // ok: adding a string and a literal
string s5 = "hello" + ", "; // error: no string operand
string s6 = s1 + ", " + "world"; // ok: each + has a string operand
string s7 = "hello" + ", " + s2; // error: can't add string literals
```

- For historical reasons, and for compatibility with C, string literals are **not** standard library strings. It is important to remember that these types differ when you use string literals and library strings.

### 3.2.3 Dealing with the Characters in a `string`

- Header: `cctype`
- Use `std::` for the functions

#### Table 3.3: cctype Functions

|||
|---|---|
|`isalnum(c)` |`true` if `c` is a letter or a digit.|
|`isalpha(c)` |`true` if `c` is a letter.|
|`iscntrl(c)` |`true` if `c` is a control character.|
|`isdigit(c)` |`true` if `c` is a digit.|
|`isgraph(c)` |`true` if `c` is not a space but is printable.|
|`islower(c)` |`true` if `c` is a lowercase letter.|
|`isprint(c)` |`true` if `c` is a printable character (i.e., a space or a character that has a visible representation).|
|`ispunct(c)` |`true` if `c` is a punctuation character (i.e., a character that is not a control character, a digit, a letter, or a printable whitespace).|
|`isspace(c)` |`true` if `c` is whitespace (i.e., a space, tab, vertical tab, return, newline, or formfeed).|
|`isupper(c)` |`true` if `c` is an uppercase letter.|
|`isxdigit(c)` |`true` if `c` is a hexadecimal digit.|
|`tolower(c)` |If `c` is an uppercase letter, returns its lowercase equivalent; otherwise returns `c` unchanged.|
|`toupper(c)` |If `c` is a lowercase letter, returns its uppercase equivalent; otherwise returns `c` unchanged.|

- If our index has a signed type, its value will be converted to the `unsigned` type that `string::size_type` represents.

## 3.3 Library `vector` Type

- A `vector` is a collection of objects, all of which have the same type.
- Referred to as a container because it "contains" other objects.

- Include these.
```cpp
#include <vector>
using std::vector;
```

- Reminder. Never put `using` statements in header files.
 
- A `vector` is a class template. C++ has both class and function templates.

```cpp
vector<int> ivec; // ivec holds objects of type int
vector<Sales_item> Sales_vec; // holds Sales_items
vector<vector<string>> file; // vector whose elements are vectors
```

- `vector` is a template, not a type. Types generated from `vector` must include the element type, for example, `vector<int>`.
- We can define vectors to hold objects ofmost any type. Because references are not objects, we cannot have a vector of references.

### 3.3.1 Defining and Initializing `vector`s

```cpp
vector<string> svec; // default initialization; svec has no elements
```

- we can (efficiently) add elements to a `vector` at run time.

```cpp
vector<int> ivec; // initially empty
// give ivec some values
vector<int> ivec2(ivec); // copy elements of ivec into ivec2
vector<int> ivec3 = ivec; // copy elements of ivec into ivec3
vector<string> svec(ivec2); // error: svec holds strings, not ints. two vectors must be the same type
```

#### List Initializing a `vector`

```cpp
vector<string> articles = {"a", "an", "the"};
```

> As we've seen, C++ provides several forms of initialization. In many, but not all, cases we can use these forms of initialization interchangably. So far, we have seen two examples where the form of initialization matters: 
> - when we use the *copy initialization* form (i.e., when we use `=`), we can supply only a single initializer;
> - and when we supply an *in-class initializer*, we must either use *copy initialization* or *use curly braces*. 
> - A third restriction is that we can supply a list of element values only by using *list initialization* in which the initializers are enclosed in curly braces. *We cannot supply a list of initializers using parentheses*.

```cpp
vector<string> v1{"a", "an", "the"}; // list initialization
vector<string> v2("a", "an", "the"); // error
```

#### Creating a Specified Number of Elements

```cpp
vector<int> ivec(10, -1); // ten int elements, each initialized to -1
vector<string> svec(10, "hi!"); // ten strings; each element is "hi!"
```

#### Value Initialization

```cpp
vector<int> ivec(10); // ten elements, each initialized to 0
vector<string> svec(10); // ten elements, each an empty string
```

- There are two restrictions on this (*value initialization*) form of initialization.
- The first restriction is that some classes require that we always supply an explicit initializer. If our vector holds objects of a type that we cannot default initialize, then we must supply an initial element value; it is not possible to create vectors of such types by supplying only a size.
- The second restriction is that when we supply an element count without also supplying an initial value, we must use the direct form of initialization

```cpp
vector<int> vi = 10; // error: must use direct initialization to supply a size
```

#### Table 3.4: Ways to Initialize a vector

|||
|---|---|
|`vector<T> v1` |`vector` that holds objects of type `T`. Default initialization; `v1` is empty.|
|`vector<T> v2(v1)` |`v2` has a copy of each element in `v1`.|
|`vector<T> v2 = v1` |Equivalent to `v2(v1)`, `v2` is a copy of the elements in `v1`.|
|`vector<T> v3(n, val)` |`v3` has `n` elements with value `val`.|
|`vector<T> `v4(n)` |`v4` has `n` copies of a *value-initialized* object.|
|`vector<T> v5{a,b,c . . .}` |`v5` has as many elements as there are initializers; elements are initialized by corresponding initializers.|
|`vector<T> v5 = {a,b,c . . . }` |Equivalent to `v5{a,b,c . . . }`.|

#### List Initializer or Element Count?

- We specify which meaning we intend by whether we use curly braces or parentheses:

```cpp
vector<int> v1(10); // v1 has ten elements with value 0
vector<int> v2{10}; // v2 has one element with value 10
vector<int> v3(10, 1); // v3 has ten elements with value 1
vector<int> v4{10, 1}; // v4 has two elements with values 10 and 1
```

- If we use braces and there is no way to use the initializers to list initialize the object, then those values will be used to construct the object

```cpp
vector<string> v5{"hi"}; // list initialization: v5 has one element
vector<string> v6("hi"); // error: can't construct a vector from a string literal
vector<string> v7{10}; // v7 has ten default-initialized elements
vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"
```

- The body of a range for must not change the size of the sequence over which it is iterating.

- To use `size_type`, we must name the type in which it is defined. A `vector` type always includes its element type:

```cpp
vector<int>::size_type // ok
vector::size_type // error
```

#### Table 3.5: `vector` Operations

|||
|---|---|
|`v.empty()` |Returns `true` if `v` is empty; otherwise returns `false`.|
|`v.size()` |Returns the number of elements in `v`.|
|`v.push_back(t)` |Adds an element with value `t` to end of `v`.|
|`v[n]` |Returns a reference to the element at position `n` in `v`.|
|`v1 = v2` |Replaces the elements in `v1` with a copy of the elements in `v2`.|
|`v1 = {a,b,c . . . }` |Replaces the elements in `v1` with a copy of the elements in the comma-separated list.|
|`v1 == v2` |`v1` and `v2` are equal if they have the same number of elements and each element in `v1` is equal to the corresponding element in `v2`.|
|`v1 != v2` |`v1` and `v2` are equal if they have the same number of elements and each element in `v1` is equal to the corresponding element in `v2`.|
|`<`, `<=`, `>`, `>=` |Have their normal meanings using dictionary ordering.|

#### Subscripting Does Not Add Elements

```cpp
vector<int> ivec; // empty vector
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    ivec[ix] = ix; // disaster: ivec has no elements
```

```cpp
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    ivec.push_back(ix); // ok: adds a new element with value ix
```

## 3.4 Introducing Iterators

- All of the library containers have iterators, but only a few of them support the subscript operator.
- Technically speaking, a `string` is *not a container* type, but string supports many of the container operations. As we've seen `string`, like `vector` has a subscript operator. Like `vector`s, `string`s also have iterators.
- iterators have operations to move from one element to another.
- A valid iterator either denotes an element or denotes a position one past the last element in a container.
- All other iterator values are invalid.

### 3.4.1 Using Iterators

- We do not use the address-of operator to obtain an iterator. Types that have iterators have members that return iterators.

```cpp
// the compiler determines the type of b and e; see § 2.5.2 (p. 68)
// b denotes the first element and e denotes one past the last element in v
auto b = v.begin(), e = v.end(); // b and e have the same type
```

- The iterator returned by end is often referred to as the ***off-the end**
iterator* or abbreviated as "**the end iterator**."

#### Iterator Operations

```cpp
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
    auto it = s.begin(); // it denotes the first character in s
    *it = toupper(*it); // make that character uppercase. Dereferencing iterator
}
```

#### Table 3.6: Standard Container Iterator Operations

|||
|---|---|
|`*iter` |Returns a reference to the element denoted by the iterator `iter`.|
|`iter->mem` |Dereferences `iter` and fetches the member named `mem` from the underlying element. Equivalent to `(*iter).mem`.|
|`++iter` |Increments `iter` to refer to the next element in the container.|
|`--iter` |Decrements `iter` to refer to the previous element in the container.|
|`iter1 == iter2`<br/><br/> `iter1 != iter2` |Compares two iterators for equality (inequality). Two iterators are equal if they denote the same element or if they are the off-the-end iterator for the same container.|

#### Moving Iterators from One Element to Another

```cpp
// process characters in s until we run out of characters or we hit a whitespace
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    *it = toupper(*it); // capitalize the current character
```

- Because the iterator returned from `end` does not denote an element, it may not be incremented or dereferenced.

> KEY CONCEPT: GENERIC PROGRAMMING  
> Programmers coming to C++ from C or Java might be surprised that we used `!=` rather than `<` in our `for` loops.  
> As we've seen, only a few library types, `vector` and `string` being among them, have the subscript operator. Similarly, all of the library containers have iterators that define the `==` and `!=` operators. **Most of those iterators do not have the `<` operator**.

#### Iterator Types

- Iterators define types named `iterator` and `const_iterator` that represent actual iterator types:

```cpp
vector<int>::iterator it; // it can read and write vector<int> elements
string::iterator it2; // it2 can read and write characters in a string
vector<int>::const_iterator it3; // it3 can read but not write elements
string::const_iterator it4; // it4 can read but not write characters
```

- If a `vector` or `string` is `const`, we may use only its `const_iterator` type.
- With a non`const` `vector` or `string`, we can use either `iterator` or `const_iterator`.

#### The `begin` and `end` Operations

```cpp
vector<int> v;
const vector<int> cv;
auto it1 = v.begin(); // it1 has type vector<int>::iterator
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
```

```cpp
auto it3 = v.cbegin(); // it3 has type vector<int>::const_iterator
```

#### Combining Dereference and Member Access

`(*it).empty()` same as `it->empty()`

```cpp
// print each line in text up to the first blank line
for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
    cout << *it << endl;
```

- Because the loop **reads but does not write** to the elements in text, we use `cbegin` and `cend` to control the iteration.

- It is important to realize that loops that use iterators should not add elements to the container to which the iterators refer.

### 3.4.2 Iterator Arithmetic

#### Table 3.7: Operations Supported by vector and string Iterators

|||
|---|---|
|`iter + n`<br/><br/>`iter - n` |Adding (subtracting) an integral value `n` to (from) an iterator yields an iterator that many elements forward (backward) within the container. The resulting iterator must denote elements in, or one past the end of, the same container.|
|`iter1 += n`<br/><br/>`iter1 -= n` |Compound-assignment for iterator addition and subtraction. Assigns to `iter1` the value of adding `n` to, or subtracting `n` from, `iter1`. |
|`iter1 - iter2` |Subtracting two iterators yields the number that when added to the right-hand iterator yields the left-hand iterator. The iterators must denote elements in, or one past the end of, the same container.|
|`>`, `>=`, `<`, `<=` |Relational operators on iterators. One iterator is less than another if it refers to an element that appears in the container before the one referred to by the other iterator. The iterators must denote elements in, or one past the end of, the same container.|

#### Arithmetic Operations on Iterators

```cpp
iter1 - iter2
```

The result type is a signed integral type named `difference_type`. Both `vector` and `string` define `difference_type`. This type is signed, because subtraction might have a negative result.

#### Using Iterator Arithmetic

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

**Question:**

Why `mid` is calculated that way in the above code?

**Answer:**

This is a crucial and common pattern in C++ when dealing with iterators for algorithms like binary search! The calculation `text.begin() + (end - beg) / 2` for `mid` is done this way to ensure **correctness and robustness**, especially for `std::vector` and other random-access iterators.

Let's break down why:

1.  **Iterators as Positions, Not Indices:**
    * Unlike array indices (e.g., `arr[0]`, `arr[5]`), iterators (`text.begin()`, `end`) are not simple integer offsets from the start. They represent *positions* within the container.
    * You can't directly do `(text.begin() + text.end()) / 2` because iterators don't support addition with other iterators, nor division.

2.  **`end - beg` (Iterator Difference):**
    * For **random-access iterators** (like those for `std::vector`, `std::string`, or raw pointers), subtracting two iterators (`end - beg`) gives you the **distance** or **number of elements** between `beg` and `end`. This result is of type `std::ptrdiff_t` (**a signed integer type**).
    * So, `(end - beg)` gives you the *length* of the current search range.

3.  **`/ 2` (Finding the Offset):**
    * Dividing this length by `2` (`(end - beg) / 2`) calculates the **offset** from the beginning of the current range to find its midpoint.

4.  **`text.begin() + offset` (Moving to the Midpoint):**
    * You can add an integer offset to a random-access iterator (`text.begin() + offset`). This operation moves the iterator `offset` positions forward from `text.begin()`.
    * So, `text.begin() + (end - beg) / 2` effectively says: "Start at the beginning of the current range (`text.begin()`) and move forward by half the distance of the current range." This lands `mid` exactly in the middle of the current search window.

**Why this specific calculation is robust:**

* **Handles Different Container Types:** This pattern works perfectly for any container that provides random-access iterators (like `std::vector`, `std::deque`, `std::array`, or even raw C-style arrays). It doesn't rely on `text.begin()` being numerically `0` or anything specific about the underlying memory layout beyond random access.
* **Avoids Overflow (for very large containers):** If you tried to calculate `(beg_index + end_index) / 2` with raw indices and the container was extremely large (e.g., `size_t` could theoretically exceed `long long` max for a single index on some architectures, though less common now), adding `beg_index + end_index` might overflow before dividing by 2. `ptrdiff_t` is guaranteed to be large enough to hold the difference between any two pointers/iterators in a valid object. (Though, more importantly, `end - beg` itself might be very large, but the overflow concern is mostly with summing two large indices).
* **Semantic Clarity:** It clearly expresses "find the length of the current segment, halve it, and move that many steps from the segment's start."

This pattern is the standard, idiomatic way to calculate midpoints in binary search (and similar algorithms) when using iterators in C++ for containers that support random access.

**END: Answer**

## 3.5 Arrays

- An array is a data structure that is similar to the library vector type but offers a different trade-off between performance and flexibility.
- Unlike a `vector`, arrays have fixed size; we cannot add elements to an array. Because arrays have fixed size, they sometimes offer better run-time performance for specialized applications. However, that run-time advantage comes at the cost of lost flexibility.

### 3.5.1 Defining and Initializing Built-in Arrays

- Arrays are a *compound type*. An array declarator has the form `a[d]`, where `a` is the name being defined and `d` is the dimension of the array.
- The dimension must be known at compile time, which means that the dimension must be a constant expression.

```cpp
unsigned cnt = 42; // not a constant expression
constexpr unsigned sz = 42; // constant expression
// constexpr see § 2.4.4 (p. 66)
int arr[10]; // array of ten ints
int *parr[sz]; // array of 42 pointers to int
string bad[cnt]; // error: cnt is not a constant expression
string strs[get_size()]; // ok if get_size is constexpr, error otherwise
```

- By default, the elements in an array are *default initialized*.
- When we define an array, we must specify a type for the array. We cannot use `auto` to deduce the type from a list of initializers.
- There are no arrays of references.

#### Explicitly Initializing Array Elements

```cpp
// list initializations

const unsigned sz = 3;
int ia1[sz] = {0,1,2}; // array of three ints with values 0, 1, 2
int a2[] = {0, 1, 2}; // an array of dimension 3
int a3[5] = {0, 1, 2}; // equivalent to a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"hi", "bye"}; // same as a4[] = {"hi", "bye", ""}
int a5[2] = {0,1,2}; // error: too many initializers
```

#### Character Arrays Are Special

```cpp
char a1[] = {'C', '+', '+'}; // list initialization, no null
char a2[] = {'C', '+', '+', '\0'}; // list initialization, explicit null
char a3[] = "C++"; // null terminator added automatically
const char a4[6] = "Daniel"; // error: no space for the null!
const char a4[7] = "Daniel"; // ok. null terminator added to the remaining locations
const char a4[10] = "Daniel"; // ok. null terminator added to the remaining locations
const char a4[3] = ""; // ok. All items are null terminators. Size is 3 (0 to 2).
```

#### No Copy or Assignment

We cannot initialize an array as a copy of another array, nor is it legal to assign one array to another:

```cpp
int a[] = {0, 1, 2}; // array of three ints
int a2[] = a; // error: cannot initialize one array with another
a2 = a; // error: cannot assign one array to another
```

#### Understanding Complicated Array Declarations

```cpp
int *ptrs[10]; // ptrs is an array of ten pointers to int
int &refs[10] = /* ? */; // error: no arrays of references
int (*Parray)[10] = &arr; // Parray points to an array of ten ints
int (&arrRef)[10] = arr; // arrRef refers to an array of ten ints
```

```cpp
int *(&arry)[10] = ptrs; // arry is a reference to an array of ten pointers
```

It can be easier to understand array declarations by starting with the array's name and reading them from the inside out (first to the right and then to the left).

### 3.5.2 Accessing the Elements of an Array

- When we use a variable to subscript an array, we normally should define that variable to have type `size_t`. `size_t` is a **machine-specific** `unsigned` type that is guaranteed to be large enough to hold the size of any object in memory. The `size_t` type is defined in the `cstddef` header, which is the C++ version of the `stddef.h` header from the C library.

- The most common source of security problems are **buffer overflow bugs**. Such bugs occur when a program fails to check a subscript and mistakenly uses memory outside the range of an array or similar data structure.

### 3.5.3 Pointers and Arrays

```cpp
string nums[] = {"one", "two", "three"}; // array of strings
string *p = &nums[0]; // p points to the first element in nums
string *p2 = nums; // equivalent to p2 = &nums[0]
```

- When we use an array as an initializer for a variable defined using `auto`, the *deduced type is a pointer*, not an array:

```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
auto ia2(ia); // ia2 is an int* that points to the first element in ia
ia2 = 42; // error: ia2 is a pointer, and we can't assign an int to a pointer
```

```cpp
auto ia2(&ia[0]); // now it's clear that ia2 has type int*
```

- Conversion does not happen when we use `decltype`. The type returned by `decltype(ia)` is array of ten ints:

```cpp
// ia3 is an array of ten ints
decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};
ia3 = p; // error: can't assign an int* to an array
ia3[4] = i; // ok: assigns the value of i to an element in ia3
```

#### Pointers Are Iterators

```cpp
int arr[] = {0,1,2,3,4,5,6,7,8,9};
int *p = arr; // p points to the first element in arr
++p; // p points to arr[1]
int *e = &arr[10]; // pointer just past the last element in arr
for (int *b = arr; b != e; ++b)
    cout << *b << endl; // print the elements in arr
```

#### The Library `begin` and `end` Functions

- `iterator` header have two functions named `begin` and `end`.
- These functions are not member functions like those we saw for containers (`vector`, `string`).
- Arrays are not class types.

```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
int *beg = begin(ia); // pointer to the first element in ia
int *last = end(ia); // pointer one past the last element in ia
```

```cpp
// pbeg points to the first and pend points just past the last element in arr
int *pbeg = begin(arr), *pend = end(arr);
// find the first negative element, stopping if we've seen all the elements
while (pbeg != pend && *pbeg >= 0)
    ++pbeg;
```

#### Pointer Arithmetic

```cpp
constexpr size_t sz = 5;
int arr[sz] = {1,2,3,4,5};
int *ip = arr; // equivalent to int *ip = &arr[0]
int *ip2 = ip + 4; // ip2 points to arr[4], the last element in arr

// ok: arr is converted to a pointer to its first element; p points one past the end of arr
int *p = arr + sz; // use caution -- do not dereference!
int *p2 = arr + 10; // error: arr has only 5 elements; p2 has undefined value
```

```cpp
auto n = end(arr) - begin(arr); // n is 5, the number of elements in arr
```

The result of subtracting two pointers is a library type named `ptrdiff_t`. Like `size_t`, the `ptrdiff_t` type is a **machine-specific type** and is defined in the `cstddef` header. Because subtraction might yield a negative distance, `ptrdiff_t` is a **signed integral type**.

#### Interaction between Dereference and Pointer Arithmetic

```cpp
int ia[] = {0,2,4,6,8}; // array with 5 elements of type int
int last = *(ia + 4); // ok: initializes last to 8, the value of ia[4]
```

```cpp
last = *ia + 4; // ok: last = 4, equivalent to ia[0] + 4
```

#### Subscripts and Pointers

```cpp
int ia[] = {0,2,4,6,8}; // array with 5 elements of type int

int i = ia[2]; // ia is converted to a pointer to the first element in ia
// ia[2] fetches the element to which (ia + 2) points

int *p = ia; // p points to the first element in ia
i = *(p + 2); // equivalent to i = ia[2]

int *p = &ia[2]; // p points to the element indexed by 2
int j = p[1]; // p[1] is equivalent to *(p + 1),
// p[1] is the same element as ia[3]
int k = p[-2]; // p[-2] is the same element as ia[0]
```

The library types (`vctor`, `string`) force the index used with a subscript to be an `unsigned` value. The built-in subscript operator does not. The index used with the built-in subscript operator can be a negative value.

***Unlike subscripts for vector and string, the index of the built-in subscript operator is not an unsigned type.***

### 3.5.4 C-Style Character Strings

Although C++ supports C-style strings, they should not be used by C++ programs. C-style strings are a surprisingly *rich source of bugs and are the root cause of many security problems*. They're also harder to use!

C-style strings are not a type. Instead, they are a convention for how to represent and use character strings. Strings that follow this convention are stored in character arrays and are null terminated.

#### C Library String Functions

- Header: `cstring` (C++ version of the C header `string.h`.)

- The pointer(s) passed to these routines must point to null-terminated array(s)

```cpp
char ca[] = {'C', '+', '+'}; // not null terminated
cout << strlen(ca) << endl; // disaster: ca isn't null terminated
```

- The result is undefined. The most likely effect of this call is that `strlen` will keep looking through the memory that follows `ca` until it encounters a null character.

#### Table 3.8: C-Style Character String Functions

**The functions in Table 3.8 do not verify their string parameters.**

|||
|---|---|
|`strlen(p)` | Returns the length of `p`, not counting the null.|
|`strcmp(p1, p2)` |Compares `p1` and `p2` for equality. Returns `0` if `p1 == p2`, *a positive* value if `p1 > p2`, *a negative* value if `p1 < p2`.|
|`strcat(p1, p2)` |Appends `p2` to `p1`. Returns `p1`.|
|`strcpy(p1, p2)` |Copies `p2` into `p1`. Returns `p1`.|

#### Comparing Strings

```cpp
string s1 = "A string example";
string s2 = "A different string";
if (s1 < s2) // false: s2 is less than s1
```

```cpp
const char ca1[] = "A string example";
const char ca2[] = "A different string";
if (ca1 < ca2) // undefined: compares two unrelated addresses
```

```cpp
if (strcmp(ca1, ca2) < 0) // same effect as string comparison s1 < s2
```

#### Caller Is Responsible for Size of a Destination String

```cpp
// initialize largeStr as a concatenation of s1, a space, and s2
string largeStr = s1 + " " + s2;
```

```cpp
// disastrous if we miscalculated the size of largeStr
strcpy(largeStr, ca1); // copies ca1 into largeStr
strcat(largeStr, " "); // adds a space at the end of largeStr
strcat(largeStr, ca2); // concatenates ca2 onto largeStr
```

- i.e., the destination C-style string size must be sufficient enough to provide space for more characters.

### 3.5.5 Interfacing to Older Code

Modern C++ programs often interface with older C++ or C code, requiring management of built-in arrays and C-style strings. The C++ library provides tools to simplify this interaction.

#### Mixing Library strings and C-Style Strings

Mixing `std::string` and C-style strings offers flexibility in C++. An `std::string` can be initialized or assigned from a null-terminated character array, and such arrays can serve as one operand in string addition or compound assignment:

```cpp
std::string s("Hello World"); // s holds "Hello World"
// string s2 = "another C-style string"; // valid assignment
// s += " literal"; // valid compound assignment
```

However, direct conversion from `std::string` to a C-style `char*` is not supported:

```cpp
char *str = s; // error: can't initialize a char* from a string
```

To obtain a C-style string from an `std::string`, use the `c_str()` member function. It returns a `const char*` to the string's null-terminated data, preventing modification:

```cpp
const char *str = s.c_str(); // ok
```

Crucially, the pointer returned by `c_str()` is only valid as long as the original `std::string` (`s` in this example) remains unchanged. Any subsequent modification to `s` can invalidate `str`. If persistent access to the C-style data is required, it must be explicitly copied.

#### Using an Array to Initialize a vector

```cpp
int int_arr[] = {0, 1, 2, 3, 4, 5};
// ivec has six elements; each is a copy of the corresponding element in int_arr
vector<int> ivec(begin(int_arr), end(int_arr));

// copies three elements: int_arr[1], int_arr[2], int_arr[3]
vector<int> subVec(int_arr + 1, int_arr + 4);
```

## 3.6 Multidimensional Arrays

- Strictly speaking, there are no multidimensional arrays in C++. What are commonly referred to as multidimensional arrays are actually arrays of arrays.

```cpp
int ia[3][4]; // array of size 3; each element is an array of ints of size 4
// array of size 10; each element is a 20-element array whose elements are arrays of 30 ints
int arr[10][20][30] = {0}; // initialize all elements to 0
```

#### Initializing the Elements of aMultidimensional Array

```cpp
int ia[3][4] = { // three elements; each element is an array of size 4
    {0, 1, 2, 3}, // initializers for the row indexed by 0
    {4, 5, 6, 7}, // initializers for the row indexed by 1
    {8, 9, 10, 11} // initializers for the row indexed by 2
};
```

```cpp
// equivalent initialization without the optional nested braces for each row
int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
```

```cpp
// explicitly initialize only element 0 in each row
int ia[3][4] = {{ 0 }, { 4 }, { 8 }};  // remaining elements are value initialized
```

```cpp
// explicitly initialize row 0; the remaining elements are value initialized
int ix[3][4] = {0, 3, 6, 9};
```

#### Subscripting a Multidimensional Array

```cpp
// assigns the first element of arr to the last element in the last row of ia
ia[2][3] = arr[0][0][0];
int (&row)[4] = ia[1]; // binds row to the second four-element array in ia
// row is a reference to "array of 4 ints" not array of 4 references to ints.
```

```cpp
constexpr size_t rowCnt = 3, colCnt = 4;
int ia[rowCnt][colCnt]; // 12 uninitialized elements
// for each row
for (size_t i = 0; i != rowCnt; ++i) {
    // for each column within the row
    for (size_t j = 0; j != colCnt; ++j) {
        // assign the element's positional index as its value
        ia[i][j] = i * colCnt + j;
    }
}
```

#### Using a Range for with Multidimensional Arrays

```cpp
size_t cnt = 0;
for (auto &row : ia) // for every element in the outer array
    for (auto &col : row) { // for every element in the inner array
        col = cnt; // give this element the next value
        ++cnt; // increment cnt
    }
```

- **To use a multidimensional array in a range for, the loop control variable for all but the innermost array must be references.**

That means, we can write like below:

```cpp
for (const auto &row : ia) // for every element in the outer array
    for (auto col : row) // for every element in the inner array
        cout << col << endl;
```

But if we write like,

```cpp
for (auto row : ia)
    for (auto col : row)
```

our program would not compiile.

Let's break it down:

```cpp
int ia[3][4] = { // ia is an array of 3 arrays, each of size 4
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
};

for (auto row : ia) // Problematic line 1
    for (auto col : row) // Problematic line 2
```

### Explanation of the Error

1.  **Outer `for` loop: `for (auto row : ia)`**
    * `ia` is an `int[3][4]`, which is an array of 3 elements.
    * Each of these 3 elements is itself an `int[4]` (an array of 4 integers).
    * When you use a range-based `for` loop, `auto` for `row` will deduce the type of each element in `ia`. So, `row` will be deduced as an `int[4]`.
    * Crucially, when an array is passed by value (which `auto` by default attempts to do in a range-for loop if you don't specify `&` or `const &`), it **decays to a pointer to its first element**. So, `row` effectively becomes an `int*` (a pointer to the first `int` of that row).

2.  **Inner `for` loop: `for (auto col : row)`**
    * Now, in the inner loop, you're trying to iterate over `row`.
    * As established, `row` has decayed to an `int*`.
    * **The core problem:** A raw pointer (`int*`) does *not* provide the necessary "range" information (`begin()` and `end()` iterators, or `std::begin()` and `std::end()` from `<iterator>`) that a range-based `for` loop requires. The compiler cannot determine the size of the array pointed to by `row` from just the pointer itself. It needs to know where the "end" of the range is.

**In summary:**

The `for (auto row : ia)` loop correctly extracts each row as an `int[4]` array. However, `for (auto col : row)` then tries to iterate over that `int[4]` array, but `row` in this context (due to array-to-pointer decay) is treated as a plain `int*` (a pointer to the first element of the row). A plain pointer doesn't carry size information, so the range-based for loop cannot determine its bounds, leading to a compilation error.

### How to Fix It (and make it compile)

To make this code compile with range-based for loops, you must prevent the array-to-pointer decay in the outer loop by using a **reference** for `row`:

```cpp
int ia[3][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
};

for (const auto& row : ia) { // Corrected: row is a reference to an int[4]
    for (auto col : row) {   // Now 'row' is an int[4], which is a valid range
        // ... do something with col
        std::cout << col << " ";
    }
    std::cout << std::endl;
}
```

By making `row` a `const auto&` (or `int (&)[4]`), it becomes a **reference to an actual array**, not a pointer. An array reference *does* retain its size information, allowing the inner range-based for loop to correctly determine the `begin()` and `end()` of that row.

#### Pointers and Multidimensional Arrays

```cpp
int ia[3][4]; // array of size 3; each element is an array of ints of size 4. ia is pointing to first of its elements
int (*p)[4] = ia; // p points to an array of four ints
p = &ia[2]; // p now points to the last element in ia
```

The parentheses in this declaration are essential:

```cpp
int *ip[4]; // array of pointers to int. So totally 4 pointers.
int (*ip)[4]; // pointer to an array of four ints
```

```cpp
// print the value of each element in ia, with each inner array on its own line
// p points to an array of four ints
for (auto p = ia; p != ia + 3; ++p) {
    // q points to the first element of an array of four ints; that is, q points to an int
    for (auto q = *p; q != *p + 4; ++q)
        cout << *q << ' ';
    cout << endl;
}
```

```cpp
// p points to the first array in ia
for (auto p = begin(ia); p != end(ia); ++p) {
// q points to the first element in an inner array
    for (auto q = begin(*p); q != end(*p); ++q)
        cout << *q << ' '; // prints the int value to which q points
    cout << endl;
}
```

#### Type Aliases Simplify Pointers to Multidimensional Arrays

```cpp
using int_array = int[4]; // new style type alias declaration; see § 2.5.1 (p. 68)
// typedef int int_array[4]; // equivalent typedef declaration; § 2.5.1 (p. 67)
// print the value of each element in ia, with each inner array on its own line
for (int_array *p = ia; p != ia + 3; ++p) {
    for (int *q = *p; q != *p + 4; ++q)
        cout << *q << ' ';
    cout << endl;
}
```

## REVISE AGAIN: `auto` and `decltype` deduction rules.

You're asking about two fundamental type deduction mechanisms in C++ that, while related, operate with distinct rules: `auto` and `decltype`.

---

### `auto` Type Deduction Rules

`auto` deduction largely follows the rules of **template type deduction**. Imagine `auto` as the `T` in a function template `template<typename T> void func(T param);` where `param` is the initializer you're assigning to the `auto` variable.

Here are the key rules for `auto` variables:

1.  **`auto` (by value):**
    * **Strips `const` and `volatile`:** If the initializer is a `const` or `volatile` type, those qualifiers are dropped.
    * **Strips references:** If the initializer is a reference, the reference part is dropped.
    * **Array to pointer decay:** If the initializer is an array, it decays to a pointer to its first element.
    * **Function to function pointer decay:** If the initializer is a function name, it decays to a function pointer.

    ```cpp
    const int x = 10;
    auto a = x;         // a is int (const stripped)

    int& y = x;
    auto b = y;         // b is int (reference stripped)

    int arr[] = {1, 2, 3};
    auto c = arr;       // c is int* (array decays to pointer)

    void foo() {}
    auto d = foo;       // d is void(*)() (function decays to function pointer)
    ```

2.  **`auto&` (by lvalue reference):**
    * **Preserves `const` and `volatile`:** If the initializer is `const` or `volatile`, these qualifiers are retained.
    * **Binds to lvalues:** Can only bind to lvalues.

    ```cpp
    const int x = 10;
    auto& a = x;        // a is const int& (const preserved)

    int y = 20;
    auto& b = y;        // b is int&
    // auto& c = 30;    // Error: Cannot bind lvalue reference to rvalue
    ```

3.  **`const auto&` (by const lvalue reference):**
    * **Preserves `const` and `volatile`:** Always results in a `const` reference, preserving any existing `const` or `volatile`.
    * **Binds to both lvalues and rvalues:** Can bind to both. This is common in range-based for loops.

    ```cpp
    const int x = 10;
    const auto& a = x;  // a is const int&

    int y = 20;
    const auto& b = y;  // b is const int&

    const auto& c = 30; // c is const int& (binds to rvalue)
    ```

4.  **`auto&&` (universal reference / forwarding reference):**
    * **Preserves `const` and `volatile`:** Retains these qualifiers.
    * **Preserves value category:**
        * If initialized with an **lvalue**, it deduces to an **lvalue reference** (`T&`).
        * If initialized with an **rvalue**, it deduces to an **rvalue reference** (`T&&`).
    * This is the basis for perfect forwarding.

    ```cpp
    int x = 10;
    auto&& a = x;          // a is int& (lvalue reference)

    auto&& b = 20;         // b is int&& (rvalue reference)

    const int cx = 30;
    auto&& c = cx;         // c is const int&
    ```

---

### `decltype` Type Deduction Rules

`decltype` works quite differently from `auto`. Instead of deducing a "stripped" or "transformed" type, `decltype(expression)` returns the **exact type** of the expression, including references and `const`/`volatile` qualifiers.

Here are the key rules for `decltype`:

1.  **`decltype(variable_name)`:**
    * Returns the declared type of the variable.

    ```cpp
    const int x = 10;
    decltype(x) a;       // a is const int (declared type of x)

    int& y = x;
    decltype(y) b = y;   // b is int& (declared type of y)
    ```

2.  **`decltype(function_call)`:**
    * Returns the exact return type of the function call.

    ```cpp
    int foo();
    const double& bar();
    decltype(foo()) a;   // a is int (return type of foo)
    decltype(bar()) b = bar(); // b is const double& (return type of bar)
    ```

3.  **`decltype(lvalue_expression)`:**
    * If the expression is an **lvalue** (something that has an identity and can be assigned to), `decltype` produces a **reference type** (`T&`).

    ```cpp
    int i = 0;
    decltype(i) x;        // x is int (from rule #1 for variable name)
    decltype((i)) y = i;  // y is int& (because (i) is an lvalue expression)

    decltype(i + 0) z;    // z is int (i + 0 is an rvalue expression)
    ```
    * The crucial point here is that a variable name `i` is an lvalue, but `decltype(i)` gives you `int`. However, if you put parentheses around it `(i)`, it's then treated as an lvalue *expression*, and `decltype((i))` gives you `int&`.

4.  **`decltype(rvalue_expression)`:**
    * If the expression is an **rvalue** (a temporary value that doesn't persist beyond its use), `decltype` produces the **plain type** (`T`).

    ```cpp
    decltype(10) a;        // a is int (10 is an rvalue literal)
    decltype(i + j) b;     // b is int (i + j produces a temporary rvalue)
    ```

---

### `decltype(auto)`

This special form combines `auto`'s syntactic convenience with `decltype`'s precise deduction rules. It's most commonly used for function return types.

* When used as a return type, `decltype(auto)` deduces the exact type of the `return` expression using `decltype`'s rules (including references and `const`/`volatile` qualifiers).

    ```cpp
    int& get_int_ref(int& val) {
        return val;
    }

    decltype(auto) get_int_ref_decltype_auto(int& val) {
        return val; // deduces to int& because 'val' is an lvalue expression
    }

    int main() {
        int x = 10;
        int& r1 = get_int_ref(x); // r1 is int&
        int& r2 = get_int_ref_decltype_auto(x); // r2 is int&
    }
    ```

These rules cover the most common scenarios for `auto` and `decltype` in C++. Understanding the distinction between "type of a variable" and "type of an expression" is key for `decltype`, and the "template deduction" analogy is powerful for `auto`.



# CH04: Expressions

#### Operand Conversions

- Small integral type operands (e.g., `bool`, `char`, `short`, etc.) are generally promoted to a larger integral type, typically `int`.

#### Lvalues and Rvalues

- In C++, an lvalue expression yields an object or a function. However, some lvalues, such as `const` objects, may not be the left-hand operand of an assignment.

- We can use an lvalue when an rvalue is required, but we cannot use an rvalue when an lvalue (i.e., a location) is required. When we use an lvalue in place of an rvalue, the object's contents (its value) are used.

- Assignment requires a (non`const`) lvalue as its left-hand operand and yields its left-hand operand as an lvalue.
- The *address-of* operator requires an lvalue operand and returns a pointer to its operand as an rvalue.
- The built-in dereference and subscript operators and the iterator dereference and `string` and `vector` subscript operators all yield lvalues.
- The built-in and iterator increment and decrement operators require lvalue operands and the prefix versions also yield lvalues.

When we apply `decltype` to an **expression** (other than a variable), the result is a *reference type* if the expression yields an lvalue. 

- As an example, assume `p` is an `int*`. Because dereference yields an lvalue, `decltype(*p)` is `int&`. On the other hand, because the address-of operator yields an rvalue, `decltype(&p)` is `int**`, that is, a pointer to a pointer to type `int`.

### 4.1.2 Precedence and Associativity

- An expression with two or more operators is a **compound expression**.

### 4.1.3 Order of Evaluation

* **Precedence:**
    * Determines how operands are **grouped** with operators.
    * Example: In `A + B * C`, `B * C` is grouped first due to `*`'s higher precedence.
* **Evaluation Order:**
    * Determines the sequence in which **operands are computed**.
    * **Generally Unspecified:** For most operators, the order in which operands are evaluated is *not guaranteed*.
* **Example:**
    ```cpp
    int i = f1() * f2();
    ```
    * We know `f1()` and `f2()` must be called *before* multiplication.
    * However, the C++ standard **does not specify** whether `f1()` is called before `f2()`, or `f2()` before `f1()`.

- ***For operators that do not specify evaluation order, it is an error for an expression to *refer to and change* the same object.***

Consider this example,

```cpp
int i = 0;
cout << i << " " << ++i << endl; // undefined
```

The compiler might evaluate `++i` before evaluating `i`, in which case the output will be `1 1`. Or the compiler might evaluate `i` first, in which case the output will be `0 1`.

There are four operators that do guarantee the order in which operands are evaluated.
- logical AND (`&&`) operator guarantees that its left-hand operand is evaluated first. Moreover, we are also guaranteed that the right-hand operand is evaluated only if the left-hand operand is `true`. 
- the logical OR (`||`) operator. Left-hand operator is evaluated first. Right-hand operator is evaluated only if left-hand operand is evaluated to `false`.
- the conditional (`? :`) operator 
- the comma (`,`) operator

#### Order of Evaluation, Precedence, and Associativity

Order of operand evaluation is independent of precedence and associativity. In an expression such as `f() + g() * h() + j()`:
- Precedence guarantees that the results of `g()` and `h()` are multiplied.
- Associativity guarantees that the result of `f()` is added to the product of `g()` and `h()` and that the result of that addition is added to the value of `j()`.
- There are no guarantees as to the order in which these functions are called.


- If `f`, `g`, `h`, and `j` are independent functions that do not affect the state of the same objects or perform IO, then the order in which the functions are called is irrelevant. If any of these functions do affect the same object, then the expression is in error and has undefined behavior.

## 4.2 Arithmetic Operators
- For most operators, operands of type bool are promoted to `int`.

```cpp
int ival = 42;
double dval = 3.14;
ival % 12; // ok: result is 6
ival % dval; // error: floating-point operand
```

In a division, a nonzero quotient is positive if the operands have the same sign and negative otherwise. Earlier versions of the language permitted a negative quotient to be rounded up or down; the new standard requires the *quotient to be rounded toward zero* (i.e., truncated).

The modulus operator is defined so that if `m` and `n` are integers and `n` is nonzero, then `(m/n)*n + m%n` is equal to `m`. By implication, if `m%n` is nonzero, it has the same sign as `m`. Earlier versions of the language permitted `m%n` to have the same sign as `n` on implementations in which negative `m/n` was rounded away from zero, but such implementations are now prohibited. Moreover, except for the obscure case where `-m` overflows, `(-m)/n` and `m/(-n)` are always equal to `-(m/n)`, `m%(-n)` is equal to `m%n`, and `(-m)%n` is equal to `-(m%n)`. 

More concretely:

- `21 % 6; /* result is 3 */`
- `21 / 6; /* result is 3 */`
- `21 % 7; /* result is 0 */`
- `21 / 7; /* result is 3 */`
- `-21 % -8; /* result is -5 */`
- `-21 / -8; /* result is 2 */`
- `21 % -5; /* result is 1 */`
- `21 / -5; /* result is -4 */`

## 4.3 Logical and Relational Operators

#### Equality Tests and the bool Literals

It is usually a bad idea to use the boolean literals `true` and `false` as operands in a comparison. These literals should be used only to compare to an object of type `bool`.

- If `val` is not a `bool`, then `true` is converted to the type of `val` before the `==` operator is applied.

```cpp
if (val == true) { /* . . . */ } // true only if val is equal to 1!
```

```cpp
if (val == 1) { /* . . . */ }
```

## 4.4 Assignment Operators

- The left-hand operand of an assignment operator must be a modifiable lvalue.

```cpp
int i = 0, j = 0, k = 0; // initializations, not assignment
const int ci = i; // initialization, not assignment
```

```cpp
1024 = k; // error: literals are rvalues
i + j = k; // error: arithmetic expressions are rvalues
ci = k; // error: ci is a const (nonmodifiable) lvalue
```

```cpp
k = 0; // result: type int, value 0
k = 3.14159; // result: type int, value 3
```

```cpp
k = {3.14}; // error: narrowing conversion. initializer list.
vector<int> vi; // initially empty
vi = {0,1,2,3,4,5,6,7,8,9}; // vi now has ten elements, values 0 through 9
```

Regardless of the type of the left-hand operand, the *initializer list* may be empty. In this case, the compiler generates a *value-initialized* temporary and assigns that value to the left-hand operand.

#### Assignment Is Right Associative

```cpp
int ival, jval;
ival = jval = 0; // ok: each assigned 0
```

```cpp
int ival, *pval; // ival is an int; pval is a pointer to int
ival = pval = 0; // error: cannot assign the value of a pointer to an int
string s1, s2;
s1 = s2 = "OK"; // string literal "OK" converted to string
```

#### Assignment Has Low Precedence

```cpp
// a verbose and therefore more error-prone way to write this loop
int i = get_value(); // get the first value
while (i != 42) {
    // do something . . .
    i = get_value(); // get remaining values
}
```

```cpp
int i;
// a better way to write our loop---what the condition does is now clearer
while ((i = get_value()) != 42) {
    // do something . . .
}
```

#### Compound Assignment Operators

```cpp
+= -= *= /= %= //arithmetic operators
<<= >>= &= ^= |= // bitwise operators; see § 4.8 (p. 152)
```

Each compound operator is essentially equivalent to `a = a op b;` with the exception that, when we use the compound assignment, the left-hand operand is **evaluated only once**. If we use an ordinary assignment, that operand is **evaluated twice**: once in the expression on the right-hand side and again as the operand on the left hand. In many, perhaps most, contexts this difference is immaterial aside from **possible performance consequences**.

## 4.5 Increment and Decrement Operators

> ADVICE: USE POSTFIX OPERATORS ONLY WHEN NECESSARY<br/>  
> Readers from a C background might be surprised that we use the prefix increment in the programs we've written. The reason is simple: The prefix version avoids unnecessary work. It increments the value and returns the incremented version. The postfix operator must store the original value so that it can return the unincremented value as its result. If we don't need the unincremented value, there's no need for the extra work done by the postfix operator.<br/>  
> For `int`s and pointers, the compiler can optimize away this extra work. For more complicated iterator types, this extra work potentially might be more costly. By habitually using the prefix versions, we do not have to worry about whether the performance difference matters. Moreover—and perhaps more importantly—we can express the intent of our programs more directly.

## 4.6 The Member Access Operators

```cpp
string s1 = "a string", *p = &s1;
auto n = s1.size(); // run the size member of the string s1
n = (*p).size(); // run size on the object to which p points
n = p->size(); // equivalent to (*p).size()
```

```cpp
// run the size member of p, then dereference the result!
*p.size(); // error: p is a pointer and has no member named size
```

## 4.7 The Conditional Operator

```cpp
cond ? expr1 : expr2;
```

#### Using a Conditional Operator in an Output Expression

```cpp
cout << ((grade < 60) ? "fail" : "pass"); // prints pass or fail
cout << (grade < 60) ? "fail" : "pass"; // prints 1 or 0!
cout << grade < 60 ? "fail" : "pass"; // error: compares cout to 60
```

The second expression is equivalent to

```cpp
cout << (grade < 60); // prints 1 or 0
cout ? "fail" : "pass"; // test cout and then yield one of the two literals
// depending on whether cout is true or false
```

The last expression is an error because it is equivalent to

```cpp
cout << grade; // less-than has lower precedence than shift, so print grade first
cout < 60 ? "fail" : "pass"; // then compare cout to 60!
```

## 4.8 The Bitwise Operators

- The bitwise operators take operands of integral type that they use as a collection of bits.
- If an operand is a "small integer," its value is first promoted to a larger integral type
- The operand(s) can be either `signed` or `unsigned`.

## 4.9 The `sizeof` Operator

- The `sizeof` operator returns the size, in bytes, of an expression or a type name.

```cpp
sizeof (type)
sizeof expr
```

- The `sizeof` operator is unusual in that it does not evaluate its operand

```cpp
Sales_data data, *p;
sizeof(Sales_data); // size required to hold an object of type Sales_data
sizeof data; // size of data's type, i.e., sizeof(Sales_data)
sizeof p; // size of a pointer
sizeof *p; // size of the type to which p points, i.e., sizeof(Sales_data). dereferenced.
sizeof data.revenue; // size of the type of Sales_data's revenue member
sizeof Sales_data::revenue; // alternative way to get the size of revenue
```

Because `sizeof` does not evaluate its operand, it doesn't matter that is an `p` invalid (i.e., uninitialized) pointer. Dereferencing an invalid pointer as the operand to `sizeof` is safe because the pointer is not actually used.

- `sizeof` an array is the size of the entire array. It is equivalent to taking the `sizeof` the element type times the number of elements in the array. Note that `sizeof` does not convert the array to a pointer.

## 4.10 Comma Operator

- The comma operator takes two operands, which it evaluates from left to right.
- Guarantees the order in which its operands are evaluated.

## 4.11 Type Conversions

#### When Implicit Conversions Occur

The compiler automatically converts operands in the following circumstances:
- In most expressions, values of integral types smaller than `int` are first promoted to an appropriate larger integral type.
- In conditions, non-`bool` expressions are converted to `bool`.
- In initializations, the initializer is converted to the type of the variable; in assignments, the right-hand operand is converted to the type of the left-hand.
- In arithmetic and relational expressions with operands of mixed types, the types are converted to a common type.
- As we'll see in Chapter 6, conversions also happen during function calls.

### 4.11.1 The Arithmetic Conversions

#### Integral Promotions

The integral promotions convert the small integral types to a larger integral type. The types `bool`, `char`, `signed char`, `unsigned char`, `short`, and `unsigned short` are promoted to `int` if all possible values of that type fit in an `int`. Otherwise, the value is promoted to `unsigned int`.

The larger `char` types (`wchar_t`, `char16_t`, and `char32_t`) are promoted to the smallest type of `int`, `unsigned int`, `long`, `unsigned long`, `long long`, or `unsigned long long` in which all possible values of that character type fit.

#### Operands of Unsigned Type

- Given an `unsigned int` and an `int` in an expression, the `int` is converted to `unsigned int`.

When the `signed` operand has a larger type than the `unsigned` operand, the result is machine dependent. If all values in the `unsigned` type fit in the larger type, then the `unsigned` operand is converted to the `signed` type. If the values don't fit, then the `signed` operand is converted to the `unsigned` type. For example, if the operands are `long` and `unsigned int`, and `int` and `long` have the same size, the `long` will be converted to `unsigned int`. If the `long` type has more bits, then the `unsigned int` will be converted to `long`.

#### Understanding the Arithmetic Conversions

```cpp
bool flag; char cval;
short sval; unsigned short usval;
int ival; unsigned int uival;
long lval; unsigned long ulval;
float fval; double dval;
3.14159L + 'a'; // 'a' promoted to int, then that int converted to long double
dval + ival; // ival converted to double
dval + fval; // fval converted to double
ival = dval; // dval converted (by truncation) to int
flag = dval; // if dval is 0, then flag is false, otherwise true
cval + fval; // cval promoted to int, then that int converted to float
sval + cval; // sval and cval promoted to int
cval + lval; // cval converted to long
ival + ulval; // ival converted to unsigned long
usval + ival; // promotion depends on the size of unsigned short and int
uival + lval; // conversion depends on the size of unsigned int and long
```

### 4.11.2 Other Implicit Conversions

**Array to Pointer Conversions:**

```cpp
int ia[10]; // array of ten ints
int* ip = ia; // convert ia to a pointer to the first element
```

**Pointer Conversions:**

- A constant integral value of `0` and the literal `nullptr` can be converted to any pointer type;
- a pointer to any non-`const` type can be converted to `void*`.
- a pointer to any type can be converted to a `const void*`.

**Conversions to bool:** 

```cpp
char *cp = get_string();
if (cp) /* . . . */ //true if the pointer cp is not zero
while (*cp) /* . . . */ // true if *cp is not the null character
```

**Conversion to const:** 

```cpp
int i;
const int &j = i; // convert a nonconst to a reference to const int
const int *p = &i; // convert address of a nonconst to the address of a const
int &r = j, *q = p; // error: conversion from const to nonconst not allowed
```

*Conversions Defined by Class Types:* 

- Class types can define conversions that the compiler will apply automatically.

```cpp
string s, t = "a value"; // character string literal converted to type string
while (cin >> s) // while condition converts cin to bool
```

### 4.11.3 Explicit Conversions

- Although necessary at times, casts are inherently dangerous constructs.

#### Named Casts

A named cast has the following form:

```cpp
cast-name<type>(expression);
```

**cast-name** may be one of
- `static_cast` 
- `dynamic_cast` (supports run-time type identification)
- `const_cast`
- `reinterpret_cast`


#### `static_cast`

- Any well-defined type conversion, other than those involving low-level `const`, can be requested using a `static_cast`.

```cpp
// cast used to force floating-point division
double slope = static_cast<double>(j) / i;
```

- Compilers often generate a warning for assignments of a larger arithmetic type to a smaller type. When we do an explicit cast, the warning message is turned off.

- we can use a `static_cast` to retrieve a pointer value that was stored in a `void*` pointer.

```cpp
void* p = &d; // ok: address of any nonconst object can be stored in a void*
// ok: converts void* back to the original pointer type
double *dp = static_cast<double*>(p);
```

#### `const_cast`

- A `const_cast` changes only a low-level `const` in its operand.

```cpp
const char *pc;
char *p = const_cast<char*>(pc); // ok: but writing through p is undefined
```

Conventionally we say that a cast that converts a `const` object to a non-`const` type "**casts away the const**." Once we have cast away the `const` of an object, the compiler will no longer prevent us from writing to that object.

```cpp
const char *cp;
// error: static_cast can't cast away const
char *q = static_cast<char*>(cp);
static_cast<string>(cp); // ok: converts string literal to string
const_cast<string>(cp); // error: const_cast only changes constness
```

#### `reinterpret_cast`

* **`reinterpret_cast`:** Performs a low-level, bit-pattern reinterpretation of an operand.
* **Danger:** Changes type without compiler warnings/errors, leading to undefined runtime behavior if assumptions about the reinterpreted type are incorrect.
* **Example:**
    ```cpp
    int *ip;
    char *pc = reinterpret_cast<char*>(ip); // ok
    string str(pc); // Dangerous! Likely bizarre runtime behavior
    ```
* **Key Issue:** The compiler trusts your explicit cast and doesn't know the pointer `pc` actually points to an `int`, not a `char`. Debugging such issues, especially across separate files, is extremely difficult.

#### Old-Style Casts

```cpp
type (expr); // function-style cast notation
(type) expr; // C-language-style cast notation
```



> ADVICE: AVOID CASTS<br/>  
> Casts interfere with normal type checking. As a result, we strongly
recommend that programmers **avoid casts**. This advice is particularly applicable to `reinterpret_casts`. Such casts are always hazardous. A `const_cast` can be useful in the context of overloaded functions, which we'll cover in § 6.4 (p. 232). Other uses of `const_cast` often indicate a design flaw. The other casts, `static_cast` and `dynamic_cast`, should be needed infrequently. Every time you write a cast, you should think hard about whether you can achieve the same result in a different way. If the cast is unavoidable, errors can be mitigated by limiting the scope in which the cast value is used and by documenting all assumptions about the types involved.

```cpp
char *pc = (char*) ip; // ip is a pointer to int
```

- Old-style casts are less visible than are named casts. Because they are
easily overlooked, it is more difficult to track down a rogue cast.

## 4.12 Operator Precedence Table

|===|===|===|===|
|Associativity|Operator|Function|Use|
|---|---|---|---|
|L| `::` |global scope |`::name`|
|L| `::` |class scope |`class::name`|
|L| `::` |namespace scope |`namespace::name`|
|===|===|===|===|
|L| `.` |member selectors |`object.member`|
|L| `->` |member selectors |`pointer->member`|
|L| `[]` |subscript |`expr[ expr ]`|
|L| `()` |function call |`name(expr_list)`|
|L| `()` |type construction |`type(expr_list)`|
|===|===|===|===|
|R| `++` |postfix increment |`lvalue++`|
|R| `--` |postfix decrement |`lvalue--`|
|R| `typeid` |type ID |`typeid(type)`|
|R| `typeid` |run-time type |`ID typeid(expr)`|
|R| explicit cast |type conversion |`cast_name<type>(expr)`|
|===|===|===|===|
|R| `++` |prefix increment |`++lvalue`|
|R| `--` |prefix decrement |`--lvalue`|
|R| `~` |bitwise NOT |`~expr`|
|R| `!` |logical NOT |`!expr`|
|R| `-` |unary minus |`-expr`|
|R| `+` |unary plus |`+expr`|
|R| `*` |dereference |`*expr`|
|R| `&` |address-of |`&lvalue`|
|R| `()` |type conversion |`(type) expr`|
|R| `sizeof` |size of object |`sizeof expr`|
|R| `sizeof` |size of type |`sizeof( type )`|
|R| `sizeof...` |size of parameter pack |`sizeof...( name )`|
|R| `new` |allocate object |`new type`|
|R| `new[]` |allocate array |`new type[size]`|
|R| `delete` |deallocate object |`delete expr`|
|R| `delete[]` |deallocate array |`delete[] expr`|
|R| `noexcept` |can expr throw |`noexcept ( expr )`|
|===|===|===|===|
|L| `->*` |ptr to member select |`ptr->*ptr_to_member`|
|L| `.*` |ptr to member select |`obj.*ptr_to_member`|
|===|===|===|===|
|L| `*` |multiply |`expr * expr`|
|L| `/` |divide |`expr / expr`|
|L| `%` |modulo (remainder) |`expr % expr`|
|===|===|===|===|
|L| `+` |add |`expr + expr`|
|L| `-` |subtract |`expr - expr`|
|===|===|===|===|
|L| `<<` |bitwise shift left |`expr << expr`|
|L| `>>` |bitwise shift right |`expr >> expr`|
|L| `<` |less than |`expr < expr`|
|L| `<=` |less than or equal |`expr <= expr`|
|L| `>` |greater than |`expr > expr`|
|L| `>=` |greater than or equal |`expr >= expr`|
|===|===|===|===|
|L| `==` |equality |`expr == expr`|
|L| `!=` |inequality |`expr != expr`|
|===|===|===|===|
|L| `&` |bitwise AND |`expr & expr`|
|===|===|===|===|
|L| `^` |bitwise XOR |`expr ^ expr`|
|===|===|===|===|
|L| `\|` |bitwise OR |`expr \| expr`|
|===|===|===|===|
|L| `&&` |logical AND |`expr && expr`|
|===|===|===|===|
|L| `\|\|` |logical OR |`expr \|\| expr`|
|===|===|===|===|
|R| `?:` |conditional |`expr ? expr : expr`|
|R| `=` |assignment |`lvalue = expr`|
|R| `*=`, `/=`, `%=`, |compound assign `lvalue += expr`, etc.|
|R| `+=`, `-=`|--//--|
|R| `<<=`, `>>=`|--//--|
|R| `&=`,`\|=`, `^=`|--//--|
|===|===|===|===|
|R| `throw` |throw exception |`throw expr`|
|===|===|===|===|
|L| `,` |comma |`expr , expr`|