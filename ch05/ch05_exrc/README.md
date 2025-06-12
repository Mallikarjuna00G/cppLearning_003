# ch05_exrc

## ch05_exrc_5p1

Exercise 5.1: What is a null statement? When might you use a null statement?

A **null statement** is a single semicolon `;`. It's a statement that does nothing.

You might use a null statement:
1.  **When the loop body is empty but required:** For `for` or `while` loops where all the work is done in the condition or update parts.
    *Example:* `while (std::cin >> s);` (reads input until EOF or invalid input)
2.  **As a placeholder:** In code development when a statement is syntactically required but the actual logic isn't yet implemented.
3.  **To provide an empty case in a `switch` statement:** Though often clearer to let cases fall through.

## ch05_exrc_5p2

Exercise 5.2: What is a block? When might you might use a block?

A **block** (or compound statement) is a sequence of zero or more statements enclosed in curly braces `{}`. It acts as a single statement.

You might use a block:
1.  **For control flow statements:** The body of `if`, `else`, `for`, `while`, `do-while` loops, and `switch` statements must be a single statement. A block allows you to group multiple statements.
2.  **To define a new scope:** Variables declared inside a block are local to that block and are destroyed when the block ends. This is useful for limiting variable lifetime and avoiding name collisions.

## ch05_exrc_5p3

Exercise 5.3: Use the comma operator (§ 4.10, p. 157) to rewrite the `while` loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

**Before:**

```cpp
#include <iostream>

int main()
{
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    
    while (val <= 10) {
        sum += val;
        ++val;
    }

    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
```

**After:**

[ch05_exrc_5p3.cpp](./ch05_exrc_5p3.cpp)

When we use comma operator, the result of a comma expression is the value of its right-hand (/-most) expression. The left-hand expression is evaluated and its result is discarded. Here the `while` condition is a comma expression.

In my opinion, it diminishes the readability of the code.

## ch05_exrc_5p4

Exercise 5.4: Explain each of the following examples, and correct any problems you detect.

(a) 

```cpp
while (string::iterator iter != s.end()) { /* . . . */ }`:
```

- The given statement is wrong.
- Mistake 1: The iterator is just being declared and not even initialized.
- Mistake 2: The uninitialized iterator is being compared to end of a vector.
- Even if the iterator gets initialized in the control statement, the while loop will most likely loop infinitely because the iterator gets created and initialized on each iteration. It will not matter if the iterator is being incremented inside the block.
- The correction would be to declare and initialize the iterator before the `while` loop and advance it inside the body of the loop. And the control statement shall just contain the comparision.

```cpp
string::iterator iter = s.begin();
while (iter != s.end()) {
    /* . . . */ 
    ++iter;
}
```

(b) 

```cpp
while (bool status = find(word)) { /* . . . */ }
if (!status) { /* . . . */ }
```

- This is incorrect.
- The `status` variable is being declared in the control statement of the `while` loop and it is not visible outside the `while` loop.
- Assuming there is no other `status` variable before the given code snippet, we will get compilation error (`undefined 'status'`).

- The correction involves declaring the `status` variable before the `while` loop.
- The loop loops until the word is found (assuming `word` is being updated inside the loop).
- Loops ends once the word is not found. And then goes to execute the if block. Infact, the `if` check is not even needed as the `while` control statement failed means it passes this `if` control statement and the `if` block gets executed. So, the content of the `if` block can be placed outside the `if` block without any `if` condition checks.

## ch05_exrc_5p7

Exercise 5.7: Correct the errors in each of the following code fragments:

(a) 

```cpp
if (ival1 != ival2)
    ival1 = ival2
else ival1 = ival2 = 0;
```

**Correction:**

```cpp
if (ival1 != ival2)
    ival1 = ival2;
else ival1 = ival2 = 0;
```

(b) 

```cpp
if (ival < minval)
    minval = ival;
    occurs = 1;
```

**Correction:**

```cpp
if (ival < minval) {
    minval = ival;
    occurs = 1;
}
```


(c) 

```cpp
if (int ival = get_value())
cout << "ival = " << ival << endl;
if (!ival)
cout << "ival = 0\n";
```

**Correction:**

```cpp
int ival;
if (ival = get_value()) {
    cout << "ival = " << ival << endl;
}
if (!ival) {
    cout << "ival = 0\n";
}
```

(d) 

```cpp
if (ival = 0)
    ival = get_value();
```

**Correction:**

```cpp
if (ival == 0)
    ival = get_value();
```

## ch05_exrc_5p8

Exercise 5.8: What is a "dangling else”? How are else clauses resolved in C++?

A **"dangling else"** occurs when an `else` clause doesn't have an unambiguous `if` statement to pair with, usually in nested `if` statements without braces.

In C++, `else` clauses are resolved by pairing with the **closest preceding unpaired `if` statement**.

## ch05_exrc_5p13

Exercise 5.13: Each of the programs in the highlighted text on page 184 (below) contains a common programming error. Identify and correct each error.

(a) 

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;
    case 'e': eCnt++;
    default: iouCnt++;
}
```

**Correction:**

```cpp
unsigned int aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++; break;
    case 'e': eCnt++; break;
    default: iouCnt++; break;
}
```

(b) 

```cpp
unsigned index = some_value();

switch (index) {
    case 1:
        int ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
}
```

**Correction:**

corr1: 

```cpp
unsigned int index = some_value();

switch (index) {
    case 1: {
            int ix = get_value();
            ivec[ ix ] = index;
        }
        break;
    default: {
            ix = ivec.size()-1;
            ivec[ ix ] = index;
        }
        break;
}
```

corr2: 

```cpp
unsigned int index = some_value();

switch (index) {
    case 1:
        int ix;
        ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
}
```

(c) 

```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
```

**Correction:**

```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1: case 3: case 5: case 7: case 9:
        oddcnt++;
        break;
    case 2: case 4: case 6: case 8: case 10:
        evencnt++;
        break;
}
```

(d) 

```cpp
unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();

switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

**Correction:**

```cpp
const unsigned int ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();

switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```