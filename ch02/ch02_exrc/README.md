# ch02_exrc

## ch02_exrc_2p1

### Integer Types:

`short`: Typically 16 bits.
`int`: Typically 32 bits, range around -2 billion to +2 billion.
`long`: At least as large as `int` (often 32 or 64 bits).
`long long`: At least as large as `long` (at least 64 bits).

### Signed vs. Unsigned:

**Signed**: Can represent both positive and negative numbers.
**Unsigned**: Can only represent non-negative numbers (zero and positive), effectively doubling the positive range for the same number of bits.

### float vs. double:

**float**: Single-precision floating-point number (typically 32 bits), lower precision and smaller range.
**double**: Double-precision floating-point number (typically 64 bits), higher precision and larger range.

## ch02_exrc_2p2

- **Rate**: `double` (or `long double` for higher precision). Mortgage rates are typically fractional and require decimal representation. Precision is important for accurate long-term calculations.
- **Principal**: `double` (or `long double`). The principal can be a large amount and may involve decimal places if there were initial fees or adjustments.
- **Payment**: `double` (or `long double`). The calculated payment will likely be a fractional value representing currency.

## ch02_exrc_2p3

```console
$ ./perform.sh 2
Executing './a.out'...
32
4294967264
32
-32
0
0

--------------------------
Last execution status: 0
```

## ch02_exrc_2p5

Exercise 2.5: Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

a) `'a'`, `L'a'`, `"a"`, `L"a"`

- `'a'`: character literal. 1 byte. Type is `char`.
- `L'a'`: wide character literal, type is `wchar_t`. 32 bit in my machine.
- `"a"`: string literal. Total size will be 2 bytes (including null character).
- `L"a"`: wide character string literal. Because it is `wchar_t` total size will be 8 bytes (4 bytes per character even null character).

b) `10`, `10u`, `10L`, `10uL`, `012`, `0xC`

- `10`: `int`. Size is 4 bytes in my machine.
- `10u`: `unsigned int`. Size is 4 bytes in my machine.
- `10L`: `long`. Size is 8 bytes in my machine.
- `10uL`: `unsigned long`. Size is 8 bytes in my machine.
- `012`: `int`. Size is 4 bytes. The value is equal to 10 in decimal number system. The given value is in octal.
- `0xC`: `int`. The given value is in hexadecimal number system. It is equal to 12 in decimal number system. It takes 4 bytes.

c) `3.14`, `3.14f`, `3.14L`

- `3.14`: `double`. Size is 8 bytes.
- `3.14f`: `float`. Size is 4 bytes.
- `3.14L`: `long double`. Size is 16 bytes.

d) `10`, `10u`, `10.`, `10e-2`

- `10`: `int`. Size = 4 bytes.
- `10u`: `unsigned int`. Size = 4 bytes.
- `10.`: `double`. Size = 8 bytes.
- `10e-2`: `double`. Size = 8 bytes.

## ch02_exrc_2p6

Exercise 2.6: What, if any, are the differences between the following definitions:

```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

For `int month = 9, day = 7;`, `month` variable will have the value `9` and the `day` variable will have the value `7`. No issues.

For `int month = 09, day = 07;`, both the initializations have 0 preceding values which are treated as octal numbers. Dues to this, we will get error for `month = 09` because `9` is not a valid digit as per octal number system. In the case of `day = 07`, `day` variable will have the value `7` (decimal number system).

## ch02_exrc_2p7

Exercise 2.7: What values do these literals represent? What type does each have?

a) `"Who goes with F\145rgus?\012"`

```console
Who goes with Fergus?
```

- `\145` represent character `e`.
- `\012` represent character `\n`-new line character.

b) `3.14e1L`

Type is `long double`. Results to `31.4`. 16 bytes.

c) `1024f`

type is `float`. 4 bytes. Results to `1024.0`.

d) `3.14L`

types is `long double`. 16 bytes. Results to `3.14`.

## ch02_exrc_2p9

Exercise 2.9: Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.

a) `std::cin >> int input_value;`

`std::cin` expects a readily available memory. So the given statement is wrong.

We will get the error:

```console
$ g++ temp.cpp 
temp.cpp: In function ‘int main()’:
temp.cpp:5:17: error: expected primary-expression before ‘int’
    5 |     std::cin >> int input_value;
      |  
```

Correct way is as follows:

```cpp
int input_value;
std::cin >> input_value;
```


b) `int i = { 3.14 };`

We will get the error:

```cpp
$ g++ temp.cpp 
temp.cpp: In function ‘int main()’:
temp.cpp:5:15: error: narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’ to ‘int’ [-Wnarrowing]
    5 |     int i = { 3.14 };
      |    
```

If you still want to assign anyway even if it discards decimal part, write like this: `int i = 3.14;` or `int i = (3.14)` or `int i(3.14)`.

Or if you want the whole value, change the type to `double`.

`double i = { 3.14 }`

c) `double salary = wage = 9999.99;`

We get the error:

```console
$ g++ temp.cpp 
temp.cpp: In function ‘int main()’:
temp.cpp:5:21: error: ‘wage’ was not declared in this scope
    5 |     double salary = wage = 9999.99;
      |
```

We can write like this:

```cpp
double wage = 9999.99, salary = wage;
```

d) `int i = 3.14;`

With this statement, the decimal part of the literal is discarded and `i` will have value `3`. Change the type to `double` if you want the whole value.


## ch02_exrc_2p10

Exercise 2.10: What are the initial values, if any, of each of the following variables?

```cpp
std::string global_str;
int global_int;

int main()
{
    int local_int;
    std::string local_str;
}
```

The value of an object of built-in type that is not explicitly initialized depends on where it is defined. Variables defined outside any function body are initialized to zero. With one exception, which we cover in § 6.1.1 (p. 205), variables of built-in type defined inside a function are uninitialized. The value of an uninitialized variable of built-in type is `undefined` (§ 2.1.2, p. 36). It is an error to copy or otherwise try to access the value of a variable whose value is `undefined`.

- `global_str` will have empty string.
- `global_int` will have value 0.


(through execution we have seen that)
- `local_str` will have empty string.
- `local_int` will have value 0.

## ch02_exrc_2p11

Exercise 2.11: Explain whether each of the following is a declaration or a definition:  
(a) `extern int ix = 1024;`  
(b) `int iy;`  
(c) `extern int iz;`  

**Declaration**: A declaration introduces a name to the program. It tells the compiler about the existence and type of a variable, function, or other entity. It does not allocate storage for the entity. A declaration can occur multiple times for the same entity within a program.

**Definition**: A definition provides the full and complete description of an entity. For variables, this means allocating storage for the variable. For functions, it means providing the function body. An entity can only be defined once in an entire program (One Definition Rule - ODR).

(a) `extern int ix = 1024;`

This is a definition.

The `extern` keyword usually suggests a declaration, indicating that the variable is defined elsewhere. However, the presence of an initializer (`= 1024`) immediately turns a declaration into a definition. When you provide an initial value, you are telling the compiler "allocate storage for this variable right here, and initialize it with this value."

(b) `int iy;`

This is a definition.

When a variable is declared without any storage class specifiers (like `extern`) at global scope, or without `extern` at file scope, and has no initializer, it is considered a definition. It tells the compiler to allocate storage for an `int` variable named `iy` and implicitly initialize it to zero (for global or static variables) or leave it uninitialized (for local variables).

(c) `extern int iz;`

This is a declaration.

The `extern` keyword explicitly states that the variable `iz` is defined elsewhere (in another translation unit or later in the same translation unit). Crucially, there is no initializer present. This means no storage is allocated for `iz` at this point. This statement simply informs the compiler about the type and name of `iz` so that it can be used in the current scope.

## ch02_exrc_2p12

Exercise 2.12: Which, if any, of the following names are invalid?

(a) `int double = 3.14;`: Invalid. `double` is a reserved keyword in C++. You cannot use reserved keywords as variable names.

(b) `int _;`: Valid. In C++, a variable name can start with an underscore (`_`) and consist only of an underscore. While it's valid, using just `_` as a variable name is generally poor practice and can sometimes conflict with compiler-generated names or standard library macros, leading to unexpected behavior.

(c) `int catch-22;`: Invalid. Variable names in C++ cannot contain hyphens (`-`). Hyphens are interpreted as the subtraction operator.

(d) `int 1_or_2 = 1;`: Invalid. Variable names in C++ cannot start with a digit. They must start with a letter (`a-z`, `A-Z`) or an underscore (`_`).

(e) `double Double = 3.14;`: Valid. C++ is case-sensitive. double (lowercase) is a keyword, but Double (uppercase D) is a distinct name and is not a keyword. Therefore, Double is a valid variable name. However, it's generally considered bad practice to use names that differ only by case from keywords, as it can be confusing. And also there is a convention of using first letter in uppercase in classes only.

## ch02_exrc_2p13

Exercise 2.13: What is the value of `j` in the following program?

```cpp
int i = 42;

int main()
{
  int i = 100;
  int j = i;
}
```

Value of `j` will be `100`. Because, local variable `i` is hiding the global variable `i`. So, only local variable `i` is visible inside the function `main`.

## ch02_exrc_2p14

Exercise 2.14: Is the following program legal? If so, what values are printed?

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
  sum += i;
std::cout << i << " " << sum << std::endl;
```

The final output will be `100 45`. The program is legal but can cause confusion due to `i` variable definition inside the for loop; which hides the `i` variable defined before the for loop.

## ch02_exrc_2p15

Exercise 2.15: Which of the following definitions, if any, are invalid? Why?

(a) `int ival = 1.01;`: Invalid. Assigning a `double` value to an integer variable. We will lose the decimal part of the value.


(b) `int &rval1 = 1.01;`: Invalid. Initializer must be an object.

(c) `int &rval2 = ival;`: Valid.

(d) `int &rval3;`: Invalid. A reference must be initialized.

## ch02_exrc_2p16

Exercise 2.16: Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

```cpp
int i = 0, &r1 = i; double d = 0, &r2 = d;
```

(a) `r2 = 3.14159;`: Valid. `d` will have the value `3.14159`.

(b) `r2 = r1;`: Valid. `d` will have the value `0`. Because `r1` is reference to `i` which is an `int` and has value `0`. And that value will get converted to `double` while getting assigned to `d`.

(c) `i = r2;`: Valid. But, `r2` is a reference to `double` object while `i` is an `int`. The statement means `i = d`; so decimal part, if any, gets discarded in `i`.

(d) `r1 = d;`: Valid. It means `i = d`. value of `d` gets copied to `i`; and decimal part of `d` gets ignored while getting copied to `i`.

## ch02_exrc_2p17

Exercise 2.17: What does the following code print?

```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

```console
10 10
```

## ch02_exrc_2p19

Exercise 2.19: Explain the key differences between pointers and references.

Here's a brief explanation of the key differences between pointers and references in C++:

|Feature|Pointers (`*`)|References (`&`)|
|---|---|---|
|Declaration|`int *ptr;` (`*` is part of the type)|`int &ref = var;` (`&` is part of the type)|
|Initialization|Can be declared without initialization. Can be `nullptr`.|MUST be initialized at the point of declaration. Cannot be null.|
|Reassignment|Can be reassigned to point to a different object.|Cannot be reassigned once initialized. It always refers to its initial object.|
|Null Value|Can be `nullptr` (or `NULL`).|Cannot be null. Always refers to a valid object.|
|Dereferencing|Requires explicit dereferencing (*ptr) to access the object it points to.|No explicit dereferencing needed; used directly like the object it refers to.|
|Address-of|Can take the address of an object (`&obj`).|Cannot directly take the address of a reference itself. Taking `&ref` gives the address of the object it refers to.|
|Memory|May occupy memory (typically 4 or 8 bytes) to store an address.|Typically do not occupy storage themselves (compiler optimization), they are just aliases.|
|Arithmetic|Supports pointer arithmetic (`ptr++`, `ptr + 5`, etc.).|Does not support reference arithmetic.|
|Binding|Can point to an object, or nothing (`nullptr`).|Must bind to an existing object.|

## ch02_exrc_2p20

Exercise 2.20: What does the following program do?

```cpp
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

`i` will be `42 * 42 = 1764`.

## ch02_exrc_2p21

Exercise 2.21: Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

```cpp
int i = 0;
```

(a) `double* dp = &i;`: Illegal. double pointer trying to point to an object of type `int`. the pointer should be same type as the object.

(b) `int *ip = i;`: Illegal. We are writing `int *ip = 0;` in other words. It is not wrong to assign 0 to the pointer but it is wrong if the intent is to point to object of `i`.

(c) `int *p = &i;`: Legal.

## ch02_exrc_2p22

Exercise 2.22: Assuming p is a pointer to int, explain the following code:

```cpp
if (p) // ...
if (*p) // ...
```

First `if` condition always passes except when p has the address 0.

Seconf `if` condition always passes except when the object pointed to by `p` has the value 0.

## ch02_exrc_2p23

Exercise 2.23: Given a pointer `p`, can you determine whether `p` points to a valid object? If so, how? If not, why not?

No, you generally cannot reliably determine whether a pointer `p` points to a valid object in C++ just by examining `p` itself.

**Why not?**

Memory is just numbers: A pointer is just a variable holding a memory address (a number). It doesn't inherently carry metadata about whether that address is currently "valid" or "owned" by your program.

## ch02_exrc_2p24

Exercise 2.24: Why is the initialization of `p` legal but that of `lp` illegal?

```cpp
int i = 42; void *p = &i; long *lp = &i;
```

`void *p = &i;` is legal because a `void*` is a generic pointer. It can hold the address of any data type, and a pointer to any object type can be implicitly converted to a `void*`.

`long *lp = &i;` is illegal because `&i` is of type `int*`, and `lp` is of type `long*`. C++ does not allow implicit conversion between pointers to different, unrelated data types like `int*` and `long*`. This is to prevent type-safety violations and potential misinterpretation of memory.

## ch02_exrc_2p25

Exercise 2.25: Determine the types and values of each of the following variables.

(a) `int* ip, i, &r = i;`

- `ip` is a pointer to an `int`.
- `i` is an `int`.
- `r` is a reference to `int` object `i`.

 (b) `int i, *ip = 0;`
 
 - `i` is an `int`.
 - `ip` is a pointer initialized to 0 (`nullptr`).
 
(c) `int* ip, ip2;`

- `ip` is a pointer to an int.
- `ip2` is an `int`.

## ch02_exrc_2p26

Exercise 2.26: Which of the following are legal? For those that are illegal, explainwhy.

(a) `const int buf;`: Illegal. `const` object must always be initialized.

(b) `int cnt = 0;`: Legal.

(c) `const int sz = cnt;`: Legal.

(d) `++cnt; ++sz;`: `++cnt` is fine but `++sz` is not acceptable bacause `sz` is `const` object. We cannot modify it.

## ch02_exrc_2p27

Exercise 2.27: Which of the following initializations are legal? Explain why.

(a) `int i = -1, &r = 0;`: Illegal. References cannot be initialized with literals.

- `int i = -1;` is legal.
- `&r = 0;` is illegal because `r` is a non-`const` reference to an `int`. A non-`const` reference must bind to an lvalue (an object that has an address). A literal like `0` is an rvalue (a temporary value without a persistent address).

(b) `int *const p2 = &i2;`: Legal (assuming `i2` is a non-`const` `int`).

- `p2` is a `const` pointer to a non-`const` `int`. This means `p2` itself cannot be reassigned to point to a different object, but the `int` object it points to (`i2`) can be modified through `*p2`.
- `&i2` gives a pointer to `i2` (type `int*`), which matches the type that `p2` points to.

(c) `const int i = -1, &r = 0;`: Legal.

- `const int i = -1;` is legal.
- `&r = 0;` is legal because `r` is a `const` reference to an `int` (`const int&`). A `const` reference has special rules: it can bind to an rvalue (like the literal `0`) or an object of a different (but convertible) type. When it binds to an rvalue, a temporary `const int` object is created and initialized with `0`, and `r` binds to this temporary object. The lifetime of this temporary is extended to that of the `const` reference `r`.

(d) `const int *const p3 = &i2;`: legal (assuming `i2` is a `const int`).

- `p3` is a `const` pointer to a `const int`. This means neither `p3` itself can be reassigned, nor can the `int` object it points to be modified through `*p3`.
- It is legal to initialize `p3` with the address of a non-`const int` (`&i2`) because you are essentially "adding `const`ness" (making it appear `const` through this pointer). It's also legal to initialize it with the address of an actual `const int`.

(e) `const int *p1 = &i2;`: Legal (assuming `i2` is a `const int`).

- `p1` is a non-`const` pointer to a `const int`. This means `p1` can be reassigned to point to a different `const int` object, but the `int` object it points to cannot be modified through `*p1`.
- It is legal to initialize `p1` with the address of a non-`const int` (`&i2`), as you are making `i2` appear `const` when accessed via `p1`. It's also legal if `i2` is actually a `const int`.

(f) `const int &const r2;`: Illegal. Reference is not initialized.

- The syntax `&const` is actually invalid in C++. A `const` reference is declared as `const type&`.
- Even if the syntax were corrected to `const int& r2;`, it would still be illegal because all references must be initialized at the point of declaration. `r2` is not initialized here.

(g) `const int i2 = i, &r = i;`: Legal.

- `const int i2 = i;` is legal. `i2` is a `const int` initialized with the current value of `i`.
- `&r = i;` is legal. `r` is a non-`const` reference to `int`, and it is correctly initialized to bind to the existing `int` object `i`.

## ch02_exrc_2p28

Exercise 2.28: Explain the following definitions. Identify any that are illegal.

(a) `int i, *const cp;`: Illegal. `const` pointers must be initialized.

- `i` is a legal declaration of an `int` (uninitialized).
- `cp` is declared as a `const` pointer to an `int`. Since `cp` is `const` itself, it must be initialized to point to something at the time of its definition. It is not, hence it's illegal.

(b) `int *p1, *const p2;`: Illegal. `const` pointer `p2` must be initilized.

- `p1` is a legal declaration of a pointer to an `int` (uninitialized).
- `p2` is declared as a `const` pointer to an `int`. Similar to (a), `p2` is `const` and must be initialized. It is not, hence it's illegal.

(c) `const int ic, &r = ic;`: Ilegal.

- `const int ic;` is illegal because `ic` is a `const int` that is not initialized. `const` objects must be initialized at the point of definition.
- Since `ic` is illegal, then `&r = ic;` also becomes problematic because `r` is trying to refer to an illegally declared (uninitialized `const`) object.

(d) `const int *const p3;`: Illegal. `const` pointers must be initialized.

- `p3` is a `const` pointer to a `const int`. Since `p3` itself is `const`, it must be initialized. It is not, hence it's illegal.

(e) `const int *p;`: Legal. Pointer to `const int` object.

- `p` is a non-`const` pointer to a `const int`. This means the value that `p` points to cannot be changed through `p`, but `p` itself can be reassigned to point to a different `const int` (or a non-`const int` that it treats as `const`).
- Pointers (even those pointing to `const` data) do not need to be initialized at definition unless the pointer itself is `const` (which `p` is not in this case). So, its initial value is uninitialized (garbage).

## ch02_exrc_2p29

Exercise 2.29: Uing the variables in the previous exercise, which of the following assignments are legal? Explain why.

(a) `i = ic;`: Ilegal. Because `ic` was not initialized.

- As established in 2.28(c), `const int ic;` is illegal because `const` objects must be initialized.
- Even if `ic` were legally declared (e.g., `const int ic = 5;`), this assignment would still be problematical because `ic` might contain an indeterminate value if it were legally declared but not initialized (e.g., if it were a global/static `const int` it would be `0`, but if it were a local `const int` that was uninitialized, then using its value would be undefined behavior). But the primary reason here is that `ic` itself is an illegal definition.

(b) `p1 = p3;`: Illegal. Because `p3` was not initialized.

- From 2.28(d), `p3` is an illegally defined `const int *const` because it's not initialized. You cannot use an illegally defined variable in an assignment.

(c) `p1 = &ic;`: Illegal. Because, `ic` is `const int` while `p1` is a pointer to just `int`; which is wrong.

- Again, `ic` is an illegally defined `const int` from 2.28(c). So, taking its address is problematic.
- Even if `ic` were a legally defined `const int` (e.g., `const int ic_legal = 5;`), the assignment `p1 = &ic_legal;` would still be illegal.
- `p1` is of type `int*` (a pointer to a non-`const int`).
- `&ic_legal` would be of type `const int*` (a pointer to a `const int`).
- You cannot implicitly convert a `const int*` to an `int*` because it would allow you to modify a `const` object through a non-`const` pointer, which violates `const`-correctness.

(d) `p3 = &ic;`: Ilegal. `p3` is a `const` pointer. We cannot assign new values.

- From 2.28(d), `p3` is an illegally defined `const int *const` (uninitialized `const` pointer). You can't use it.
- Even if `p3` were legally defined (e.g., `const int *const p3_legal = &some_int;`), you still couldn't assign to it later because `p3` itself is a `const` pointer, meaning its target cannot be changed after initialization.

(e) `p2 = p1;`: Illegal. `p2` is a `const` pointer. We cannot assign new values.

- From 2.28(b), `p2` is an illegally defined `int *const` (uninitialized `const` pointer). You can't use it.
- Even if `p2` were legally defined (e.g., `int *const p2_legal = &some_other_int;`), you still couldn't assign to it later because `p2` itself is a `const` pointer, meaning its target cannot be changed after initialization.

(f) `ic = *p3;`: Illegal. `ic` is a `const` integer. We cannot assign new values.

- From 2.28(c), `ic` is an illegally defined `const int`. So, you can't assign to it.
- Even if `ic` were a legally defined `const int` (e.g., `const int ic_legal = 5;`), you still could not assign a new value to it because `ic_legal` is `const`.
- Additionally, `p3` itself is illegally defined from 2.28(d), so dereferencing it (`*p3`) would be undefined behavior.


## ch02_exrc_2p30

Exercise 2.30: For each of the following declarations indicate whether the object being declared has top-level or low-level const.

`const int v2 = 0;`: top-level `const`.

`int v1 = v2;`: no `const` level.

`int *p1 = &v1, &r1 = v1;`: no `const` level.

`const int *p2 = &v2, *const p3 = &i, &r2 = v2;`: `p2` has low-level `const`. `p3` has top-level `const`. `r2` has low-level `const`.

## ch02_exrc_2p31

Exercise 2.31: Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.

`r1 = v2;`: Legal.

- `r1` is a non-`const` reference to `v1`. You can modify the object `r1` refers to (`v1`).
- `v2` is a `const int`.
- The assignment `r1 = v2;` means "assign the value of `v2` (which is `0`) to the object that `r1` refers to (`v1`)".
- This is a legal assignment where the `const` value of `v2` is copied into the non-`const` variable `v1` (via `r1`). The `const` on `v2` is top-level, meaning it's about `v2` itself. When `v2`'s value is used in an expression, its `const`-ness is ignored.

`p1 = p2;`: Illegal. Because `p1` is a pointer to non-`const int` while `p2` is a pointer to `const int`. So the assignment is wrong.

- `p1` is `int*` (pointer to non-`const`).
- `p2` is `const int*` (pointer to `const`).
- You cannot implicitly convert a `const int*` to an `int*`. This would allow you to modify a `const` object through `p1`, which is a violation of `const`-correctness. This is a low-level `const` issue.

`p2 = p1;`: Legal. Because `p1` is `int*` and `p2` is `const int*`. We can convert `int*` to `const int*`. The assignment is correct.

- `p1` is `int*` (pointer to non-`const`).
- `p2` is `const int*` (pointer to `const`).
- You can implicitly convert an `int*` to a `const int*`. This is safe because you're adding `const`ness (promising not to modify the object through `p2` even if `p1` could). This is a low-level `const` conversion.

`p1 = p3;`: Illegal. Because `p1` is `int*` while `p3` is `const int *const`. Mismatch in low-level `const`.



`p2 = p3;`: Legal. There is a match in low-level `const`-ness.