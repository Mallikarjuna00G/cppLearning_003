# ch04_exrc

## ch04_exrc_4p2

Exercise 4.2: Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:

(a) `* vec.begin()`: `*(vec.begin())`

(b) `* vec.begin() + 1`: `(*(vec.begin()) + 1)`

## ch04_exrc_4p3

Exercise 4.3: Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

**NOTE: Answer fully obtained from gemini 2.5**

Yes, I consider it an **acceptable trade-off** for C++.

**Why:**

1.  **Performance and Control:** C++'s core philosophy is to provide maximum performance and low-level control. Undefined order of evaluation for most binary operators gives the compiler significant freedom to reorder instructions, leading to highly optimized machine code that runs faster or uses fewer resources. This is crucial for C++'s primary use cases (e.g., operating systems, game engines, high-frequency trading, embedded systems) where every nanosecond or byte matters.

2.  **Programmer Responsibility:** C++ is a language that empowers experienced programmers by giving them sharp tools. The trade-off essentially says: "We'll give you maximum optimization potential, but it's your responsibility to write code that doesn't rely on a specific order of evaluation for expressions with side effects." If the order matters, the programmer *must* explicitly sequence the operations (e.g., by breaking them into separate statements).

While it can lead to subtle bugs if programmers are not careful, it aligns with C++'s design goals and allows it to excel in domains where other languages might fall short due to enforced, rigid evaluation orders.

## ch04_exrc_4p4

Exercise 4.4: Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.

`12 / 3 * 4 + 5 * 15 + 24 % 4 / 2`

`(((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2))`

## ch04_exrc_4p5

Exercise 4.5: Determine the result of the following expressions.

(a) `-30 * 3 + 21 / 5`: -86

(b) `-30 + 3 * 21 / 5`: -18

(c) `30 / 3 * 21 % 5`: 0

(d) `-30 / 3 * 21 % 4`: -2

## ch04_exrc_4p6

Exercise 4.6: Write an expression to determine whether an `int` value is even or odd.

```cpp
// a is some int.
bool even = (a % 2 == 0);
```

## ch04_exrc_4p7

Exercise 4.7: What does overflow mean? Show three expressions that will overflow.

**Overflow** occurs when a calculation produces a result that is too large (or too small, which is technically underflow but often grouped with overflow as a general "exceeding limits" issue) to be stored in the assigned data type.

For signed integers in C++, overflow results in **undefined behavior**. For unsigned integers, it "wraps around" (modulo the maximum value + 1).

**Three expressions that will likely overflow (assuming standard 32-bit `int`):**

1.  `int result = 2000000000 + 1000000000;` (The sum `3,000,000,000` exceeds `INT_MAX` which is approx `2.1 * 10^9`).
2.  `int result = 100000 * 100000;` (The product `10,000,000,000` greatly exceeds `INT_MAX`).
3.  `int result = -2000000000 - 1000000000;` (The sum `-3,000,000,000` is less than `INT_MIN` which is approx `-2.1 * 10^9`).

## ch04_exrc_4p8

**Note: Answer fully taken from gemini 2.5**

* **Logical AND (`&&`)**:
    * The **left operand is evaluated first**.
    * If the left operand is `false`, the **right operand is NOT evaluated** (short-circuit).
    * If the left operand is `true`, the right operand *is* evaluated.

* **Logical OR (`||`)**:
    * The **left operand is evaluated first**.
    * If the left operand is `true`, the **right operand is NOT evaluated** (short-circuit).
    * If the left operand is `false`, the right operand *is* evaluated.

* **Equality (`==`)**:
    * **Both operands are always evaluated.** There is **no short-circuiting**.
    * The order in which the left and right operands are evaluated relative to each other is **unspecified** (meaning the compiler can choose).

## ch04_exrc_4p9

Exercise 4.9: Explain the behavior of the condition in the following `if`:

```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

The `if` block if the code will get executed. Because, `cp` is pointing to a valid string means, it must be pointing to a valid address. Therefore, `cp` is `true` in the AND operation. Then `*cp` is `H` which is not `0`; so that too is `true`.

Here's a breakdown of why:

1.  **`cp` evaluation:**
    * `cp` is a `const char*` pointer. It's initialized to point to the beginning of the string literal "Hello World".
    * In a boolean context (like an `if` condition), a **non-null pointer** evaluates to `true`.
    * Since `cp` points to valid memory (the 'H' of "Hello World"), it is a non-null pointer, so `cp` evaluates to `true`.

2.  **`&&` (Logical AND) short-circuiting:**
    * Because the left operand (`cp`) evaluated to `true`, the logical AND operator proceeds to evaluate its right operand (`*cp`). If `cp` had been `nullptr`, `*cp` would not have been evaluated.

3.  **`*cp` evaluation:**
    * `*cp` dereferences the pointer, giving you the character it points to. In this case, `*cp` is `'H'`.
    * In a boolean context, any **non-zero character** evaluates to `true`. The null character `'\0'` (which has an integer value of 0) evaluates to `false`.
    * Since `'H'` has a non-zero ASCII value, `*cp` evaluates to `true`.

4.  **Final Result:**
    * The condition becomes `true && true`, which evaluates to `true`.
    * Therefore, the code inside the `if` block will indeed be executed.

## ch04_exrc_4p10

Exercise 4.10: Write the condition for a `while` loop that would read `int`s from the standard input and stop when the value read is equal to `42`.

```cpp
int a;
while (cin >> a && a != 42) {
    // do something
}
```

## ch04_exrc_4p11

Exercise 4.11: Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that `a` is greater than `b`, which is greater than `c`, which is greater than `d`.

```cpp
if (a > b && b > c && c > d) {
    // do something
}
```

## ch04_exrc_4p12

Exercise 4.12: Assuming `i`, `j`, and `k` are all `int`s, explain what `i != j < k` means.

1.  **Operator Precedence:**
    The "less than" operator (`<`) has **higher precedence** than the "not equals" operator (`!=`).

2.  **Order of Evaluation:**
    Therefore, `j < k` is evaluated **first**.

3.  **Result of `j < k`:**
    * `j < k` produces a **boolean value** (`true` or `false`).

4.  **Second Comparison:**
    * The expression then effectively becomes `i != (boolean_result_of_j_less_than_k)`.
    * During this comparison, the **boolean value is converted to an `int`**: `true` becomes `1`, and `false` becomes `0`.
    * So, it then compares `i` to either `1` or `0`.

**Therefore, analysis goes like:**

* The evaluation goes like: `i != (j < k)`.
* `j < k` results in a boolean value.
* And that boolean value will then get compared with `i` using the `!=` operator.
* During this second comparison, the boolean value resulted from the first part of the comparison is converted to `int` (either `0` or `1`) and then will get compared to `i`.

## ch04_exrc_4p13

Exercise 4.13: What are the values of i and d after each assignment?

```cpp
int i; double d;
```

(a) `d = i = 3.5;`: `d` will be `3.0` and `i` will be `3`.

(b) `i = d = 3.5;`: `i` will be `3` and `d` will be `3.5`.

## ch04_exrc_4p14

Exercise 4.14: Explain what happens in each of the `if` tests:

`if (42 = i) // ...`: error. Assignment to rvalue is incorrect. Left hand side of the assignment operator must not be an rvalue.

`if (i = 42) // ...`: `i` gets the value `42` and the code in the `if` block gets executed because the condition passes as `i` is non-zero value.

## ch04_exrc_4p15

Exercise 4.15: The following assignment is illegal. Why? How would you correct it?

```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

- Assignment operator has right associativity.
- `pi = 0` is fine.
- but `ival = pi` is error: cannot assign the value of a pointer to an `int`
- The control won't reach till `dval = ival`.

**Correction:**

```cpp
double dval; int ival; int *pi;
dval = ival = 0;
pi = 0;
```

- This is acceptable.
- `ival` is assigned `0`.
- `dval = ival` is also acceptable conversion from `int` to `double`.
- Then separately assigning `pi` with `0`; which is fine.

## ch04_exrc_4p16

Exercise 4.16: Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.

(a) `if (p = getPtr() != 0)`: the intention is to check if `p` has value `0` in it after obtaining from `getPtr()`. Since we are not parenthesizing and `!=` operator has higher precedence than `=` operator, the value obtained from `getPtr()` call will get compared with `0` and the resulting boolean value is assigned to `p` and that is checked for non-zero value to determine the `if`. Which is totally wrong. The correct way is, `if ((p = getptr()) != 0)`. With this, the pointer value is first fetched and then is checked if it is `0` or not.

(b) `if (i = 1024)`: Here, the intention might be to check if `i` is equal to `1024`. If that is the case, the correction is `if (i == 1024)`. What the given statement does is that it will assign `i` with the value `1024` and the `if` condition gets always executed because `i` will always be non-zero.

## ch04_exrc_4p17

Exercise 4.17: Explain the difference between prefix and postfix increment.

* **Prefix Increment (`++variable`)**: Increments the variable, then evaluates to the **new (incremented) value**.
* **Postfix Increment (`variable++`)**: Evaluates to the **original value** of the variable, then increments the variable.

## ch04_exrc_4p18

Exercise 4.18: What would happen if the `while` loop on page 148 that prints the elements from a vector used the prefix increment operator?

```cpp
auto pbeg = v.begin();
// print elements up to the first negative value
while (pbeg != v.end() && *beg >= 0)
    cout << *pbeg++ << endl; // print the current value and advance pbeg
```

- What happens is that the `pbeg` will first advance to the next item and then print the element of that item.
- This results in skipping the first item in the vector from printing.
- And trying dereference the item which is one past the last item from the vector. Which is incorrect (results in undefined behavior).

## ch04_exrc_4p19

Exercise 4.19: Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?

(a) `ptr != 0 && *ptr++`: This is fine. Because we are first checking if the pointer has valid address and then we are dereferencing the pointer to get the value from the adress; which is actually used for AND operation. And then the pointer gets incremented.

(b) `ival++ && ival`: This is fine if the programmer knows what he is doing. But this is definitely confusing at first sight. Assuming `ival` has the value `4`, the expression evaluates like `4 && 5`. By the time `ival` reaches the second operand of the expression, post increment is performed on the variable.

(c) `vec[ival++] <= vec[ival]`: This is not fine. This is confusing. Assuming, `ival` is 4, the expression evaluates as `vec[4] <= vec[5]`.

* **Correction:** To avoid undefined behavior, you must explicitly sequence the operations. For example:
    * `vec[ival] <= vec[ival + 1]; ival++;` (If the intent was to compare the current element with the next, then advance `ival`).
    * Or, if `ival` needs to be incremented first for both: `++ival; vec[ival-1] <= vec[ival];` (though `vec[ival-1]` might be messy).

## ch04_exrc_4p20

Exercise 4.20: Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.

Let's break down each expression, assuming `iter` is a `std::vector<std::string>::iterator`, meaning `*iter` gives you a `std::string` object.

**(a) `*iter++;`**
* **Legal.**
* **Behavior:** This is a common pattern. It first **dereferences** the `std::string` object that `iter` *currently* points to (yielding the string itself). *Then*, `iter` is advanced to the next element in the vector. The overall expression yields the string that was at `iter`'s original position.
* **Brief:** It **does** first dereference the current item and then advance.

**(b) `(*iter)++;`**
* **Illegal.**
* **Reason:** `(*iter)` yields a `std::string` object. The `std::string` class does **not** have a built-in `operator++` (increment operator). You cannot increment a string.

**(c) `*iter.empty()`**
* **Illegal.**
* **Reason:** The dot operator (`.`) has higher precedence than the dereference operator (`*`). So, it attempts `iter.empty()`. However, `iter` (the iterator itself) does not have an `empty()` member function. Even if it did, trying to dereference a `bool` result (`*true` or `*false`) would be an error.

**(d) `iter->empty();`**
* **Legal.**
* **Behavior:** This uses the `->` operator to dereference `iter` and then calls the `empty()` member function on the `std::string` object that `iter` points to. This returns `true` if the string itself is empty, `false` otherwise.

**(e) `++*iter;`**
* **Illegal.**
* **Reason:** `*iter` yields a `std::string` object. Similar to (b), the `std::string` class does **not** have a built-in `operator++`. You cannot increment a string.

**(f) `iter++->empty();`**
* **Legal.**
* **Behavior:** This expression is legal due to operator precedence. `iter++` is evaluated first, which returns a temporary iterator that points to `iter`'s *original* position. *Then*, `->empty()` is called on that temporary iterator to check if the `std::string` it points to is empty. Finally, `iter` itself is advanced to the next element.

## ch04_exrc_4p22

**NOTE: Full taken from gemini 2.5**

The **`if-else if-else` version is generally easier to understand** for this type of conditional logic.

**Why:**

1.  **Clarity of Flow:** The `if-else if-else` structure directly mirrors how humans think about sequential conditions: "If this is true, do X. Otherwise, if *this other thing* is true, do Y. Otherwise, if *yet another thing* is true, do Z. If none of the above, do W."
2.  **Explicit Scoping:** Each condition and its corresponding action are clearly defined in their own block, making it easy to see which grade range corresponds to which result.
3.  **Readability for Nested Logic:** Nested ternary operators, while concise, can become very difficult to read and debug as the nesting deepens. It requires more mental effort to correctly parse which `?` belongs to which `:` and what implied ranges are being covered. The order of evaluation in the ternary is crucial and less obvious at a glance.
4.  **Maintainability:** If you need to add another grade category or adjust a threshold, it's typically much simpler and less error-prone to modify an `if-else if-else` ladder than a deeply nested ternary.

While the ternary version is compact, its conciseness often comes at the cost of immediate clarity for complex, multi-way decisions like this grading scale.

## ch04_exrc_4p23

Exercise 4.23: The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?

```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

**Explanation of Failure:**

The expression fails to compile because the **equality operator (`==`) has higher precedence** than the conditional (ternary) operator (`? :`).

Therefore, the compiler interprets the line as:
`string pl = (s + s[s.size() - 1] == 's') ? "" : "s";`

1.  `s.size() - 1`: Calculates the index of the last character.
2.  `s[s.size() - 1]`: Accesses the last character of `s` (e.g., 'd' for "word").
3.  `s + s[s.size() - 1]`: Concatenates the string `s` with that last character (e.g., "word" + 'd' results in the temporary string `"wordd"`).
4.  `("wordd") == 's'`: This is the **compile-time error**. You cannot directly compare a `std::string` object (like `"wordd"`) with a `char` (like `'s'`) using the `==` operator.

**How to Fix It (assuming typical pluralization intent):**

If the intention is to add "s" to `s` *only if* `s` does not already end in "s", you need to parenthesize the conditional operation to ensure it applies to the plural suffix, not the entire string:

```cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
```

**Explanation of Fix:**

The parentheses `(s[s.size() - 1] == 's' ? "" : "s")` force the conditional logic to be evaluated first. This results in either an empty string `""` or the string `"s"`. This resulting string is then correctly concatenated with `s`.

## ch04_exrc_4p24

Exercise 4.24: Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

The conditional operator (`? :`) takes three parts: `Condition ? Value_if_True : Value_if_False`.

**Original (Right-Associative) Way (How C++ works):**

`C1 ? V1 : C2 ? V2 : V3` is read as `C1 ? V1 : ( C2 ? V2 : V3 )`

1.  C++ evaluates the **innermost** conditional `(C2 ? V2 : V3)` first. This produces either `V2` or `V3`.
2.  Then, it evaluates `C1 ? V1 : (result from step 1)`.

This works because `C1` and `C2` are **conditions** (true/false), and `V1, V2, V3` are **values**.

**If `? :` Were Left-Associative:**

`C1 ? V1 : C2 ? V2 : V3` would be read as `( C1 ? V1 : C2 ) ? V2 : V3`

1.  C++ would first evaluate the **leftmost** conditional: `(C1 ? V1 : C2)`.
2.  This sub-expression would produce either `V1` (if `C1` is true) or `C2` (if `C1` is false).
    * In the code, `V1` is `"high pass"` (a string).
    * `C2` is `(grade > 75)` (a boolean condition).

3.  The problem arises in the next step: The result from step 1 (`V1` or `C2`) would then become the **new `Condition`** for the rest of the expression:
    `(result from step 1) ? V2 : V3`

4.  If `grade` was `95`, `C1` (`grade > 90`) is true, so `(C1 ? V1 : C2)` would evaluate to `"high pass"` (a `std::string`). The expression would then try to do: `"high pass" ? V2 : V3`.

**The confusion and error:** In C++, we **cannot use a `std::string` directly as a boolean condition** (like `if ("high pass")` or `"high pass" ? ...`). Only types like `bool`, integers, or pointers can be implicitly converted to `bool` for conditions.

So, if `? :` were left-associative, our code would cause a **compile-time error** because it would try to use a `std::string` as a condition.

## ch04_exrc_4p25

Exercise 4.25: What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in which `'q'` has the bit pattern `01110001`?

- `'q'` is `01110001` in 8-bits.
- `'q'` is `00000000000000000000000001110001` in 32-bits.
- `~'q'` is `11111111111111111111111110001110` in 32-bits.
- `~'q' << 6` is `11111111111111111110001110000000` in 32-bits.
- The value will be `0xFFFFF8E0`.

## ch04_exrc_4p26

Exercise 4.26: In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?

- As mentioned in the book, `int`s are guaranteed to have 16 bits.
- We cannot use it to track the grades of more than 16 students.
- Even though the promotion from small integer to larger integral type occurs during the bitwise operation, the evaluated value is lost while saving back to the variable `quiz1`.

## ch04_exrc_4p27

Exercise 4.27: What is the result of each of these expressions?

```cpp
unsigned long ul1 = 3, ul2 = 7;
```

(a) `ul1 & ul2`: The final value will be 3.

(b) `ul1 | ul2`: The final value will be 7.

(c) `ul1 && ul2`: The final value will be `true` (boolean)

(d) `ul1 || ul2`: The final value will be `true` (boolean)


## ch04_exrc_4p28

```cpp
$ ./perform.sh 2
Executing './a.out'...
sizeof (bool): 1
sizeof (char): 1
sizeof (wchar_t): 4
sizeof (char16_t): 2
sizeof (char32_t): 4
sizeof (short): 2
sizeof (int): 4
sizeof (long): 8
sizeof (long long): 8
sizeof (float): 4
sizeof (double): 8
sizeof (long double): 16

--------------------------
Last execution status: 0
```

## ch04_exrc_4p10

Exercise 4.29: Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.

```cpp
int x[10]; int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

Compilation: 

```cpp
$ ./perform.sh 
Compiling 'ch04_exrc_4p29.cpp' using g++ with C++11 standard...
g++ -std=c++11 -Wall ch04_exrc_4p29.cpp -o a.out
ch04_exrc_4p29.cpp: In function ‘int main()’:
ch04_exrc_4p29.cpp:9:22: warning: division ‘sizeof (int*) / sizeof (int)’ does not compute the number of array elements [-Wsizeof-pointer-div]
    9 |     cout << sizeof(p)/sizeof(*p) << endl;
      |             ~~~~~~~~~^~~~~~~~~~~
ch04_exrc_4p29.cpp:7:21: note: first ‘sizeof’ operand was declared here
    7 |     int x[10]; int *p = x;
      |                     ^
Compilation successful. Executable created: 'a.out'
```

Execution:
```
$ ./perform.sh 2
Executing './a.out'...
10
2

--------------------------
Last execution status: 0
```

## ch04_exrc_4p30

Exercise 4.30: Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:

(a) `sizeof x + y`: `(sizeof (x)) + y`

(b) `sizeof p->mem[i]`: `sizeof (p->mem[i])`

(c) `sizeof a < b`: `(sizeof (a)) < b`

(d) `sizeof f()`: `sizeof (f())`

## ch04_exrc_4p31

Exercise 4.31: The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

Given code:

```cpp
vector<int>::size_type cnt = ivec.size();
// assign values from size . . . 1 to the elements in ivec
for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;
```

The reason is simple: 
- The prefix version avoids unnecessary work. It increments the value and returns the incremented version. 
- The postfix operator must store the original value so that it can return the unincremented value as its result. If we don’t need the unincremented value, there’s no need for the extra work done by the postfix operator.

Code with postfix operators:

```cpp
vector<int>::size_type cnt = ivec.size();
// assign values from size . . . 1 to the elements in ivec
for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
```

## ch04_exrc_4p32

Exercise 4.32: Explain the following loop.

```cpp
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};

for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr) { 
    /* . . . */ 
}
```

This `for` loop iterates through the `ia` array.

1.  **Initialization:**
    * `ptr` is initialized to point to the first element of `ia` (`ia[0]`).
    * `ix` is initialized to `0`.
2.  **Conditions:** The loop continues as long as *both* `ix` has not reached `size` (i.e., `ix < 5`) **AND** `ptr` has not reached the "one-past-the-end" address of the array (`ia + 5`).
3.  **Increment:** In each iteration, both `ix` (the integer index) and `ptr` (the pointer) are advanced to the next element/index.

Essentially, `ptr` and `ix` iterate in lockstep over the `size` elements of the array. The two conditions (`ix != size` and `ptr != ia + size`) are **redundant** because they will always become false at the same time given how they are initialized and incremented. The loop will execute `size` times.

## ch04_exrc_4p33

Exercise 4.33: Using Table 4.12 (p. 166) explain what the following expression does:

```cpp
someValue ? ++x, ++y : --x, --y
```

1.  **Comma Operator Precedence:** The comma operator (`,`) has **lower precedence** than the conditional operator (`? :`).

2.  **Default Evaluation:** Due to this precedence, the expression `someValue ? ++x, ++y : --x, --y` is parsed by default as:
    ` ( (someValue ? ++x : --x) , ++y ) , --y `

3.  **What actually happens:**
    * First, `x` is either incremented (`++x`) if `someValue` is true, or decremented (`--x`) if `someValue` is false.
    * Then, `y` is **incremented** (`++y`).
    * Finally, `y` is **decremented** (`--y`).
    * The overall effect is that `x` changes based on `someValue`, but `y` ends up with its **original value** (incremented then immediately decremented).