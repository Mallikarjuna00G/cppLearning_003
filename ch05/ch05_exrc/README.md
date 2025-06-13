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

## ch05_exrc_5p15

Exercise 5.15: Explain each of the following loops. Correct any problems you detect.

(a) 

```cpp
for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
if (ix != sz)
// . . .
```

- First issue is we do not know what `sz` is.
- Second, `ix` is not visible to `if` condition.
- Even if `ix` is declared before the `for` loop, the `if` condition check always fails and its body is never executed. Because the control stays in the loop as long as `ix != sz` and the loop stops only when `ix` is same as `sz`. And again the code is checking if `ix != sz` which is impossible.

```cpp
for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
// if statement is removed as it is redundant
```

(b) 

```cpp
int ix;
for (ix != sz; ++ix) { /* . . . */ }
```

- Wrong. No initialization statement.

**Correction:**
```cpp
int ix;
for (;ix != sz; ++ix) { /* . . . */ }
```

(c) 

```cpp
for (int ix = 0; ix != sz; ++ix, ++sz) { /* . . . */ }
```

- The loop will be a infinite loop unless `sz` is already having the value `0` just before the `for` loop.
- Correction cannot be provided unless the requirements are clear.

## ch05_exrc_5p16

Exercise 5.16: The `while` loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The `for` loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

**1. Idiomatic `while` loop:**
Reads integers from input until end-of-file.
```cpp
#include <iostream>
int val, sum = 0;
while (std::cin >> val) { // Condition: input success
    sum += val;
}
// std::cout << "Sum: " << sum << std::endl;
```
**`while` loop rewritten as a `for` loop:**
```cpp
#include <iostream>
int val, sum = 0;
for (; std::cin >> val; ) { // Initialization and update parts are empty
    sum += val;
}
// std::cout << "Sum: " << sum << std::endl;
```

**2. Idiomatic `for` loop:**
Iterates through elements of a `std::vector` using an index.
```cpp
#include <vector>
#include <iostream>
std::vector<int> nums = {1, 2, 3, 4, 5};
for (size_t i = 0; i < nums.size(); ++i) { // Initialization, condition, update all in one line
    std::cout << nums[i] << " ";
}
// std::cout << std::endl;
```
**`for` loop rewritten as a `while` loop:**
```cpp
#include <vector>
#include <iostream>
std::vector<int> nums = {1, 2, 3, 4, 5};
size_t i = 0; // Initialization outside
while (i < nums.size()) { // Condition
    std::cout << nums[i] << " ";
    ++i; // Update inside the loop body
}
// std::cout << std::endl;
```

**Which loop would you choose? Why?**

If I could use only one loop, I would choose the **`while` loop**.

**Reason:** Any `for` loop can be mechanically rewritten as a `while` loop (as shown above), making `while` more fundamental and universally applicable. The `while` loop's simpler structure (just a condition) makes it more flexible for scenarios where iteration doesn't neatly fit the "initialize, test, update" pattern, such as reading from input streams or iterating based on external events.


## ch05_exrc_5p18

Exercise 5.18: Explain each of the following loops. Correct any problems you detect.

(a) 

```cpp
do
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
while (cin);
```

- Since there are multiple statements meant to execute for `do-while` loop, the braces need to be written.
- The intention is to get two integers, find the sum of them and print to console. This process shall repeat as long as the provided inputs are valid.

**Correction:**

```cpp
do {
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
} while (cin);
```


(b) 

```cpp
do {
    // . . .
} while (int ival = get_response());
```

- Having a variable declaration in `do-while` condition results in compilation error.
- Declare any variable that will be used in the condition of `do-while` before the `do-while` statement.

**Correction:**

```cpp
int ival;
do {
    // . . .
} while (ival = get_response());
```


(c) 

```cpp
do {
    int ival = get_response();
}
```

- This is an invalid syntax.
- This is supposed to be a `do-while` statement.
- The variable which is supposed to be used in the `do-while` condition shall be declared before the `do-while` statement.

**Correction:**

```cpp
int ival;
do {
    // do something
} while (ival = get_response());
```

## ch05_exrc_5p22

Exercise 5.22: The last example in this section that jumped back to `begin` could be better written using a loop. Rewrite the code to eliminate the `goto`.

**Given code:**

```cpp
// backward jump over an initialized variable definition is okay
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
```

**Rewritten code:**

```cpp
// backward jump over an initialized variable definition is okay
while (true) {
    int sz = get_size();
    if (sz <= 0) {
        continue;
    }
    break;
}
```

OR

```cpp
// backward jump over an initialized variable definition is okay
int sz;
while ((sz = get_size()) <= 0) {
    
}
```

## ch05_exrc_5p24

With 

```cpp
throw exception();
```

```console
$ ./perform.sh 3
Executing './a.out'... <ifile.txt
Enter two integers to perform divsion operation: 
terminate called after throwing an instance of 'std::exception'
  what():  std::exception
./perform.sh: line 55:  4177 Aborted                 (core dumped) ./"$EXECUTABLE_NAME" < ifile.txt

--------------------------
Last execution status: 134
```

With 

```cpp
throw runtime_error("Division by zero.!!");
```

```console
$ ./perform.sh 3
Executing './a.out'... <ifile.txt
Enter two integers to perform divsion operation: 
terminate called after throwing an instance of 'std::runtime_error'
  what():  Division by zero.!!
./perform.sh: line 55:  4302 Aborted                 (core dumped) ./"$EXECUTABLE_NAME" < ifile.txt

--------------------------
Last execution status: 134
```