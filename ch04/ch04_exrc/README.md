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