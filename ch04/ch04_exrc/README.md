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