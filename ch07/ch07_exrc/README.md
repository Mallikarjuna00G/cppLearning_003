# ch07_exrc :: Classes

## ch07_exrc_7p5

Exercise 7.5: Provide operations in your `Person` class to return the `name` and `address`. Should these functions be `const`? Explain your choice.

- In my opinion, both of these member functions shall be `const` since they are just to provide existing data without any modifications.

## ch07_exrc_7p8

Exercise 7.8: Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

```cpp
    istream &read(istream &is, Sales_data &item);
    ostream &print(ostream &os, const Sales_data &item) const;
```

- Because in the `read` function we are actually feeding the `Sales_data` object members via `istream`; therefore it cannot be `const`.
- In `print` we are not modifying anything in the `Sales_data` object received but will only print it. Therefore, we do not have any statements modifying the members of the object. To avoid unintentional modifications in the object we are adding `const`ness.

## ch07_exrc_7p10

Exercise 7.10: What does the condition in the following `if` statement do?

```cpp
if (read(read(cin, data1), data2))
```

- Assuming `istream& read(istream& is, Person &p);`

- First, `read(cin, data1)` is executed. If the read is successfull, in that place we will have a `istream` reference waiting for outer `read` (`read(cin, data2)`). If this `read` also succeeds, then the `if` condition passes.
- If any of the reads fail then the `if` condition will also fail.

## ch07_exrc_7p16

Exercise 7.16: What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a `public` specifier? What kinds should be `private`?

- A class may contain zero or more access specifiers, and there are no restrictions on how often an access specifier may appear. Each access specifier specifies the access level of the succeeding members. The specified access level remains in effect until the next access specifier or the end of the class body.
- The constructors and member functions that are part of the interface follow the `public` specifier; the data members and the functions that are part of the implementation follow the `private` specifier.

## ch07_exrc_7p17

Exercise 7.17: What, if any, are the differences between using `class` or `struct`?

- The only difference between using `class` and using `struct` to define a class is the default access level.
- When we define a class intending for all of its members to be `public`, we use `struct`. If we intend to have `private` members, then we use `class`.
- A class may define members before the first access specifier. Access to such members depends on how the class is defined. If we use the `struct` keyword, the members defined before the first access specifier are `public`; if we use class, then the members are `private`.

## ch07_exrc_7p18

Exercise 7.18: What is encapsulation? Why is it useful?

**Encapsulation** is the process of bundling data (member variables) and the methods (member functions) that operate on that data into a single unit (a class), and **restricting direct access** to some of the component parts.

**Why it's useful:**

* **Data Hiding:** Protects data from unintended external modification, ensuring data integrity.
* **Modularity:** Makes code easier to manage, understand, and debug by logically grouping related elements.
* **Flexibility/Maintainability:** Allows internal implementation details to be changed without affecting external code that uses the class's public interface.

## ch07_exrc_7p19

Exercise 7.19: Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

Currently the `Person` class is as,

```cpp
struct Person {
    // START: constructors
    Person() = default;
    Person(const string &name): name(name) {}
    Person(const string &name, const string &address): name(name), address(address) {}
    Person(istream &is) {
        read(is, *this);
    }
    // END: constructors

    std::string name = "";
    std::string address = "";

    inline string getName() const {return name;}
    inline string getAddress() const {return address;}

};
```

After encapsulation:

```cpp
class Person {
    public:
    // START: constructors
    Person() = default;
    Person(const string &name): name(name) {}
    Person(const string &name, const string &address): name(name), address(address) {}
    Person(istream &is) {
        read(is, *this);
    }
    // END: constructors


    inline string getName() const {return name;}
    inline string getAddress() const {return address;}

    private:
    std::string name = "";
    std::string address = "";
};
```

- Most likey I will make all the member variables `private`.
- All the constructors will go under `public`.
- Most of the member functions will go under `public`. Only few will go under `private` based on requirements.

## ch07_exrc_7p20

Exercise 7.20: When are friends useful? Discuss the pros and cons of using friends.

**Friends are useful** when a non-member function or another class needs to access the `private` or `protected` members of a class, but cannot or should not be a regular member function (e.g., I/O operators like `operator<<` or `operator>>`).

**Pros:**
* **Convenience for I/O and other non-member operations:** Allows non-member functions to operate naturally on private data, especially for overloaded operators that require the left-hand operand to be a non-class type (like `ostream` for `operator<<`).
* **Tight coupling where necessary:** Enables efficient, direct access to internals for closely related classes or functions when high performance or complex interaction justifies breaking strict encapsulation.

**Cons:**
* **Breaks Encapsulation:** Directly violates the principle of data hiding, as friends have special access to private members.
* **Reduced Maintainability:** Tightly couples classes/functions, making it harder to modify internal implementation details without affecting friends.
* **Increased Complexity:** Can make the class's interface less clear by implicitly extending it beyond explicitly public members.
* **Potential for Abuse:** If overused, can lead to spaghetti code and undermine the benefits of object-oriented design.

## ch07_exrc_7p25

Exercise 7.25: Can `Screen` safely rely on the default versions of copy and assignment? If so, why? If not, why not?

Yes, `Screen` **can safely rely on the default versions of copy and assignment.**

**Reason:**

The `Screen` class's members (`pos cursor`, `pos height`, `pos width`, `std::string contents`) are all of types that **handle their own copying and assignment correctly** (either built-in types or `std::string`, which has well-defined copy/assignment semantics). There are no raw pointers managing dynamically allocated memory that `Screen` itself is responsible for, thus no "deep copy" issues.

## ch07_exrc_7p28

Exercise 7.28: What would happen in the previous exercise if the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&`?

If the return type was `Screen` (by value) instead of `Screen&` (by reference):

1.  **Breaks Chaining:** Method chaining (e.g., `myScreen.move().set().display()`) would operate on temporary copies, not the original `myScreen` object. Each call would modify a copy, and the next call would operate on a *new* copy of that modified copy, and so on, leaving the original object unchanged.
2.  **Performance Overhead:** Each call would involve creating and destroying a full copy of the `Screen` object, potentially causing significant performance degradation for frequent operations.

## ch07_exrc_7p29

Exercise 7.29: Revise your `Screen` class so that `move`, `set`, and `display` functions return `Screen` and check your prediction from the previous exercise.

```console
./a.out
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

## ch07_exrc_7p30

Exercise 7.30: It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

**Pros of explicitly using `this->`:**

* **Clarity:** Makes it immediately obvious that you're accessing a member of the current object, especially when local variables or parameters have the same name as members.
* **Consistency:** Some coding styles prefer it for uniformity in member access.

**Cons of explicitly using `this->`:**

* **Redundancy/Verbosity:** Adds unnecessary characters for typical member access where there's no ambiguity.
* **Visual Clutter:** Can make code harder to read by adding noise where it's not needed.
* **No Functional Difference:** The compiler implicitly adds `this->` anyway, so there's no performance or functional gain.

## ch07_exrc_7p33

Exercise 7.33: What would happen if we gave `Screen` a `size` member defined as follows? Fix any problems you identify.

```cpp
pos Screen::size() const
{
    return height * width;
}
```

- It is clear that the `size` member is being definied outside the class.
- `pos` is declared inside the class. Therefore, we need to mention the scope of `pos` as well.

**Corrected version:**

```cpp
Screen::pos Screen::size() const
{
    return height * width;
}
```

## ch07_exrc_7p34

Exercise 7.34: What would happen if we put the `typedef` of `pos` in the `Screen` class on page 285 as the last line in the class?

```cpp
int height; // defines a name subsequently used inside Screen
class Screen {
    public:
    typedef std::string::size_type pos;
    void setHeight(pos);
    pos height = 0; // hides the declaration of height in the outer scope
};

Screen::pos verify(Screen::pos);

void Screen::setHeight(pos var) {
    // var: refers to the parameter
    // height: refers to the class member
    // verify: refers to the global function
    height = verify(var);
}
```

If write like the following, we will get compilation error saying the `pos` is undefined while parsing first statement haiving `pos` in the class. i.e., `void setHeight(pos);`

```cpp
int height; // defines a name subsequently used inside Screen
class Screen {
    public:
    void setHeight(pos);
    pos height = 0; // hides the declaration of height in the outer scope
    typedef std::string::size_type pos;
};

Screen::pos verify(Screen::pos);

void Screen::setHeight(pos var) {
    // var: refers to the parameter
    // height: refers to the class member
    // verify: refers to the global function
    height = verify(var);
}
```

## ch07_exrc_7p35

Exercise 7.35: Explain the following code, indicating which definition of `Type` or `initVal` is used for each use of those names. Say how you would fix any errors.

```cpp
typedef string Type;
Type initVal();

class Exercise {
    public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
    
    private:
    int val;
};

Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

Evaluation:

```cpp
typedef string Type;  // place p1;
Type initVal();  // place p2;

class Exercise {
    public:
    typedef double Type;  // place p3;
    Type setVal(Type);  // here both `Type`s are used from palce p3.
    Type initVal();  // place p4; `Type` is used from place p3. 
    
    private:
    int val;
};

// here both `Type` used are from place p1.
Type Exercise::setVal(Type parm) {
    val = parm + initVal();  // `initVal` is from place p4. Results in type mismatch finally resulting in compilation error. Attempt for string + double.
    return val;
}  // results in compilation error because, the mismatch in the return type of the Exercise::setval function. From declaration it is double but is string in the definition.
```

**How I would fix the errors:**

```cpp
typedef string Type;
Type initVal();

class Exercise {
    public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
    
    private:
    int val;
};

Exercise::Type Exercise::setVal(Exercise::Type parm) {
    val = parm + initVal();  // value truncated during assignment
    return val;  // During conversion from int to double
}
```

## ch07_exrc_7p36

Exercise 7.36: The following initializer is in error. Identify and fix the problem.

```cpp
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
```

```cpp
struct X {
    X (int i, int j): base(i), rem(i % j) { }
    int rem, base;
};
```

## ch07_exrc_7p37

Exercise 7.37: Using the version of `Sales_data` from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:

```cpp
Sales_data first_item(cin);

int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
}
```

Given `Sales_data` version from this section is as follows:

```cpp
class Sales_data {
    public:
    // defines the default constructor as well as one that takes a string argument
    Sales_data(std::string s = ""): bookNo(s) { }
    // remaining constructors unchanged
    Sales_data(std::string s, unsigned cnt, double rev): bookNo(s), units_sold(cnt), revenue(rev*cnt) { }
    Sales_data(std::istream &is) { read(is, *this); }
    // remaining members as before
};
```

Evaluation: 

```cpp
Sales_data first_item(cin);  // version 3 of the constructor is used.
  // The values will be based on the user input.

int main() {
    Sales_data next;  // version 1 of the constructor is used.
      // bookNo is assigned with empty string. other members are initialised with in-class initializers.
    Sales_data last("9-999-99999-9");  // version 1 of the constructor is used.
      // bookNo is assigned with the value "9-999-99999-9" and other members are initialised with in-class initializers.
}
```

## ch07_exrc_7p38

Exercise 7.38: We might want to supply `cin` as a default argument to the constructor that takes an `istream&`. Write the constructor declaration that uses `cin` as a default argument.

```cpp
class Sales_data {
    public:
    // defines the default constructor as well as one that takes a string argument
    Sales_data(std::string s, unsigned cnt, double rev): bookNo(s), units_sold(cnt), revenue(rev*cnt) { }
    Sales_data(std::istream &is = cin) { read(is, *this); }
    // remaining members as before
};
```

- Note: We have to remove other default constructors. Otherwise it will result in ambiguity.

## ch07_exrc_7p39

Exercise 7.39: Would it be legal for both the constructor that takes a `string` and the one that takes an `istream&` to have default arguments? If not, why not?

- No, it would be illegal. If both constructors had default arguments, they would both be callable with no arguments, creating an **ambiguous default constructor** and causing a compilation error. A class can only have one default constructor.

## ch07_exrc_7p40

Exercise 7.40: Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.

(a) `Book` (b) `Date` (c) `Employee` (d) `Vehicle` (e) `Object` (f) `Tree`

Choosing **(b) `Date`**.

**Data:**
* `unsigned short year;`
* `unsigned char month;`
* `unsigned char day;`

**Constructors:**
1.  `Date() = default;` (Default: Represents an invalid or uninitialized date, or a "null" date).
2.  `Date(unsigned short y, unsigned char m, unsigned char d);` (Parameterized: For creating a specific valid date).
3.  `Date(std::istream& is);` (From Stream: For reading date components from an input stream).

**Decisions:**
* Data types chosen for minimal memory and logical range.
* Default constructor for flexibility when date isn't immediately known.
* Parameterized constructor for direct, complete initialization.
* Stream constructor for convenient input from files or console. (Validation would be handled inside these constructors or helper functions).

## ch07_exrc_7p42

Exercise 7.42: For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating `constructor(s)` for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

Yes, the `Date` class from Exercise 7.40 **could use delegation**.

**Delegating Constructors for `Date`:**

```cpp
class Date {
public:
    unsigned short year;
    unsigned char month;
    unsigned char day;

    // Delegating constructor: calls the (y,m,d) constructor
    Date() : Date(1970, 1, 1) {} // Default to Epoch start (or other sensible default)

    // Primary constructor: initializes all members
    Date(unsigned short y, unsigned char m, unsigned char d)
        : year(y), month(m), day(d) {
        // Potentially add validation here
    }

    // From stream constructor: Reads and then potentially delegates to primary
    Date(std::istream& is) : Date() { // Delegate to default or primary, then read
        is >> year >> month >> day;
        // Add validation for read values
    }
};
```
**Explanation:** The default constructor `Date()` now delegates to the three-parameter constructor `Date(1970, 1, 1)`, providing a sensible default date without repeating initialization logic. The stream constructor also delegates to the default `Date()` to ensure members are initialized, then proceeds to read from the stream.

## ch07_exrc_7p43

Exercise 7.43: Assume we have a class named `NoDefault` that has a constructor that takes an `int`, but has no default constructor. Define a class `C` that has a member of type `NoDefault`. Define the default constructor for `C`.

```cpp
class NoDefault {
    public:
    NoDefault(int a): val(a){}

    private:
    int val;
};

class C {
    public:
    C(): mem(NoDefault(0)){}

    NoDefault mem;
}
```

If I just write `C() {}` as the default constructor for class `C`:

```cpp
class C {
public:
    C() {} // User-defined default constructor with an empty body
    NoDefault mem;
};
```

This will result in a **compilation error**.

**Reason:**

When the compiler generates the code for your explicitly defined (even if empty) constructor `C() {}`, it needs to ensure all of `C`'s members are initialized. Since `NoDefault mem;` is not initialized in `C`'s member initializer list, the compiler tries to **default-initialize** `mem`.

However, as we established, `NoDefault` **does not have a default constructor**. Therefore, the compiler cannot find a way to default-initialize `mem`, leading to an error like:

* "no matching constructor for initialization of 'mem'"
* "no default constructor exists for class 'NoDefault'"
* "member 'mem' has no default constructor"

So, simply writing `C() {}` is insufficient if `C` has a member whose type lacks a default constructor. You **must** explicitly initialize such members in the initializer list of `C`'s constructors.

## ch07_exrc_7p44

Exercise 7.44: Is the following declaration legal? If not, why not?

```cpp
vector<NoDefault> vec(10);
```

- No. Because, there is no default constructor in `NoDefault`.

## ch07_exrc_7p45

Exercise 7.45: What if we defined the `vector` in the previous execercise to hold objects of type `C`?

- Even then it will result in error unless we handle in initialization of `NoDefault` type member of `C` because `NoDefault` does not have default constructor.

## ch07_exrc_7p46

Exercise 7.46: Which, if any, of the following statements are untrue? Why?

**(a) A class must provide at least one constructor.**

* **Correctness:** **Untrue.** C++ does not mandate a user-declared constructor. If no constructors are declared, the compiler will synthesize one (a default constructor) if it's implicitly needed. Your reasoning about better practice is also valid.

**(b) A default constructor is a constructor with an empty parameter list.**

* **Correctness:** **Mostly true, but it's more precise to say "a constructor that can be called without arguments."** This includes constructors with an empty parameter list *and* constructors where all parameters have default arguments.
    * `MyClass();` (empty parameter list) - is a default constructor.
    * `MyClass(int x = 0, std::string s = "");` - is also a default constructor because it can be called without arguments (`MyClass mc;`).
    So, it's not *just* an empty parameter list.

**(c) If there are no meaningful default values for a class, the class should not provide a default constructor.**

* **Correctness:** **True.** If an object cannot be put into a valid or meaningful state without explicit arguments, providing a default constructor would create invalid objects, leading to logical errors or undefined behavior later. The class should force users to provide the necessary information through other constructors.

**(d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.**

* **Correctness:** **UNTRUE.** This is a common misconception.
    * The compiler **does generate** a default constructor (if no user-defined constructors are present and one is needed).
    * However, this synthesized default constructor **does NOT initialize built-in types (like `int`, `double`, pointers) that don't have in-class initializers**. These built-in members will have **indeterminate (garbage) values** if the object is default-initialized.
    * It *does* call the default constructors of class-type members (if they have one) and uses in-class initializers.
    * The rule for zero-initialization (setting to zero) applies only in specific contexts (static/global variables, arrays value-initialized, explicit value initialization with `{}`). Default initialization of local built-in variables does not zero them.

## ch07_exrc_7p47

Exercise 7.47: Explain whether the `Sales_data` constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?

Yes, the `Sales_data` constructor `Sales_data(std::string s)` **should be explicit**.

**Benefits of `explicit`:**

* **Prevents Implicit Conversions:** Stops the compiler from automatically converting a `std::string` into a `Sales_data` object in contexts like function calls or assignments where such a conversion might be unintentional or misleading.
* **Avoids Subtle Bugs:** Reduces the chance of subtle logical errors where a string is accidentally interpreted as a `Sales_data` object.
* **Clarity:** Forces users to be explicit about their intent to create a `Sales_data` object from a string (e.g., `Sales_data item("0-201-78345-X");` or `Sales_data item = Sales_data("0-201-78345-X");`).

**Drawbacks of `explicit`:**

* **Less Convenient:** Requires explicit casting or direct construction syntax (`Sales_data item("isbn");` or `static_cast<Sales_data>("isbn")`) even when the conversion might be desired.
* **No Implicit Initializations:** Disallows direct initialization using an `=` sign (e.g., `Sales_data item = "0-201-78345-X";` becomes illegal).

## ch07_exrc_7p48

Exercise 7.48: Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions

```cpp
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

What happens if the `Sales_data` constructors are explicit?

**If `Sales_data` constructors are NOT `explicit`:**

* `Sales_data item1(null_isbn);`: **Direct initialization.** Calls `Sales_data(const std::string&)` constructor, directly using `null_isbn`.
* `Sales_data item2("9-999-99999-9");`: **Direct initialization.** Calls `Sales_data(const std::string&)` constructor, using the string literal "9-999-99999-9".

**If `Sales_data` constructors ARE `explicit`:**

* `Sales_data item1(null_isbn);`: **Still Legal (Direct Initialization).** Explicit constructors can always be used for direct initialization.
* `Sales_data item2("9-999-99999-9");`: **Still Legal (Direct Initialization).** Same as above, direct initialization is allowed.

The question likely intended to include an example like `Sales_data item3 = "9-999-99999-9";`. In that case:

* **If NOT `explicit`:** Legal. Uses **copy initialization**, implicitly converting "9-999-99999-9" to a `Sales_data` object using `Sales_data(const std::string&)` constructor.
* **If `explicit`:** **Illegal.** `explicit` prevents implicit conversions required by copy initialization.

## ch07_exrc_7p49

Exercise 7.49: For each of the three following declarations of combine, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:

(a) `Sales_data &combine(Sales_data);`
(b) `Sales_data &combine(Sales_data&);`
(c) `Sales_data &combine(const Sales_data&) const;`

Assuming `Sales_data` constructors are **not `explicit`** (as is typical for this type of problem unless stated otherwise, allowing implicit conversions from `string` to `Sales_data`).

**`Sales_data i;` and `std::string s;`**

**(a) `Sales_data &combine(Sales_data);`**
* **What happens:**
    1.  The `std::string s` is **implicitly converted** to a temporary `Sales_data` object using the `Sales_data(const std::string&)` constructor.
    2.  This temporary `Sales_data` object is then **copied** (due to pass-by-value) into the `combine` function's parameter.
    3.  The `combine` function executes.
    4.  The return type is `Sales_data&`, which implies returning a reference to `*this`. This is fine.
* **Result:** The call is legal. The original `Sales_data i` is modified, but there's an unnecessary temporary object creation and copy due to pass-by-value.

**(b) `Sales_data &combine(Sales_data&);`**
* **What happens:**
    1.  The `combine` function expects a **non-const lvalue reference** (`Sales_data&`).
    2.  The `std::string s` can be implicitly converted to a `Sales_data` temporary.
    3.  **Problem:** A non-const lvalue reference **cannot bind to a temporary object**.
* **Result:** **Illegal.** Compilation error.

**(c) `Sales_data &combine(const Sales_data&) const;`**
* **What happens:**
    1.  The `std::string s` is **implicitly converted** to a temporary `Sales_data` object using the `Sales_data(const std::string&)` constructor.
    2.  The `combine` function expects a **const lvalue reference** (`const Sales_data&`). A `const` lvalue reference **can bind to a temporary object**.
    3.  The `combine` function is declared `const` (`const;` at the end), meaning it promises not to modify `*this`. Its return type is `Sales_data&`, which would allow modification of the calling object.
* **Result:** **Illegal.** While the implicit conversion and binding to a temporary are fine, the `const` qualifier on the member function (`const` after parameters) indicates that `combine` cannot modify the `Sales_data` object it's called on (`i` in `i.combine(s)`). However, `combine`'s signature returns `Sales_data&`, which *implies* it might modify `i`. This is a contradiction, as you cannot return a non-const reference to a `const` object (`*this`). The compiler will typically issue an error about returning a non-const reference from a const member function.

## ch07_exrc_7p50

Exercise 7.50: Determine whether any of your `Person` class constructors should be explicit.

Let's consider the `Person` class and its constructors:

```cpp
class Person {
public:
    // Person() = default; // (a) Default constructor
    // Person(const string &name) : name(name) {} // (b) Takes name (implicitly convertible from string)
    // Person(const string &name, const string &address) : name(name), address(address) {} // (c) Takes name, address
    // Person(istream &is) { read(is, *this); } // (d) Takes istream&
    // ...
private:
    std::string name = "";
    std::string address = "";
    // ...
};
```

**Which constructors should be `explicit`?**

1.  **`Person(const string &name)` (Constructor (b)):**
    * **Should be `explicit`.**
    * **Reason:** It's unlikely that an implicit conversion from a `std::string` to a `Person` object is ever desired. For instance, if you had a function `void processPerson(Person p);`, you wouldn't want to accidentally call `processPerson("John Doe");` and have it silently create a `Person` object. `explicit` forces users to write `processPerson(Person("John Doe"));` making their intent clear.
    * **Benefit:** Prevents unintended conversions and potential bugs.
    * **Drawback:** Requires explicit construction syntax.

2.  **`Person(istream &is)` (Constructor (d)):**
    * **Should be `explicit`.**
    * **Reason:** Implicit conversion from an `istream` to a `Person` object is almost never what you'd want. An `istream` typically represents a source of data, not a direct value that "is" a `Person`. If this constructor were not `explicit`, something like `void func(Person p);` and then calling `func(std::cin);` would try to create a `Person` from `std::cin`, which is highly improbable intended behavior.
    * **Benefit:** Prevents unexpected and probably incorrect implicit conversions.
    * **Drawback:** Requires explicit construction syntax (e.g., `Person p(std::cin);`).

**Constructors that generally should NOT be `explicit` (or cannot be):**

* **`Person() = default;` (Constructor (a)):** Default constructors cannot be `explicit`. An `explicit` default constructor makes no sense as it defeats the purpose of being "default."
* **`Person(const string &name, const string &address)` (Constructor (c)):** This constructor takes two arguments. Constructors with more than one required argument are not considered for implicit conversions (only single-argument constructors are), so `explicit` is unnecessary and would have no effect here.

**In summary:** The single-parameter constructors, `Person(const std::string&)` and `Person(std::istream&)`, are prime candidates for being `explicit` to prevent undesired implicit type conversions.

## ch07_exrc_7p51

Exercise 7.51: Why do you think `vector` defines its single-argument constructor as `explicit`, but `string` does not?

The choice to make a single-argument constructor `explicit` boils down to whether the conversion it performs is considered **natural and intuitive (implicit)** or **potentially surprising and error-prone (explicit)**.

**`std::vector`'s single-argument constructor is `explicit`:**

* `std::vector<T>::vector(size_type count);` (e.g., `std::vector<int> v(10);`)
* **Reason for `explicit`:** An `int` (representing a count) is fundamentally **not** the same "thing" as a `std::vector` (a dynamic array). If this constructor were not explicit, you could write:
    * `void func(std::vector<int> v);`
    * `func(10);` // This would implicitly create a vector of 10 zeros.
* This implicit conversion is often **undesirable and non-obvious**. An integer count doesn't "is-a" vector. Making it `explicit` forces you to write `func(std::vector<int>(10));`, which clearly states your intent to create a vector from that count. This prevents accidental conversions that could lead to bugs.

**`std::string`'s single-argument constructor is NOT `explicit`:**

* `std::string::string(const char* s);` (e.g., `std::string str = "hello";`)
* **Reason for NOT `explicit`:** A C-style string literal (`const char*`) is widely considered to be **conceptually equivalent** to a `std::string`. The conversion from `const char*` to `std::string` is so common and natural that the convenience of implicit conversion outweighs the risk of accidental use.
    * `void func(std::string s);`
    * `func("world");` // This is very idiomatic C++ and generally desired.
* Making this `explicit` would make `std::string` much less convenient to use with string literals and C-style strings, which are a cornerstone of C++ text handling.

**In essence:**

* `vector<T>(count)`: A count is **not** a vector. The conversion is not natural. -> **`explicit`**
* `string(const char*)`: A C-style string **is conceptually** a string. The conversion is very natural and commonly desired. -> **Not `explicit`**

## ch07_exrc_7p52

Exercise 7.52: Using our first version of `Sales_data` from § 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.

```cpp
Sales_data item = {"978-0590353403", 25, 15.99};
```

Our first version of `Sales_data` from § 2.6.1 (p. 72):

```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

- No problems.
- `bookNo` will have the value `"978-0590353403"`.
- `units_sold` will have the value `25`.
- `revenue` will have the value `15.99`.

## ch07_exrc_7p53

Exercise 7.53: Define your own version of `Debug`.

```cpp
class Debug {
    public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) { }
    
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }
    
    private:
    bool hw; // hardware errors other than IO errors
    bool io; // IO errors
    bool other; // other errors
};
```

## ch07_exrc_7p54

Exercise 7.54: Should the members of `Debug` that begin with `set_` be declared as `constexpr`? If not, why not?

No, the members of `Debug` that begin with `set_` (**`set_io`, `set_hw`, `set_other`**) **should NOT be declared as `constexpr`**.

**Reason:**

A `constexpr` function implies that it can be evaluated at compile time. However, a crucial rule for `constexpr` functions is that they **cannot modify the state of an object** unless that object is `mutable` and the modification is part of a `constexpr` context that ensures the object is destroyed before end of compilation (which is rare for member setters). More generally, a `constexpr` member function must be `const` and not modify its `this` object.

The `set_` functions explicitly **modify data members** (`io`, `hw`, `other`). Therefore, they are inherently non-`const` operations and cannot be `constexpr`. They change the object's state, which is generally disallowed for `constexpr` member functions (which are implicitly `const` unless they are constructors).

## ch07_exrc_7p55

Exercise 7.55: Is the `Data` class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.

```cpp
struct Data {
    int ival;
    string s;
};
```

No, the `Data` class from § 7.5.5 (p. 298) is **NOT a literal class**.

**Reason:**

For a class to be a literal type, **all of its data members must also be literal types**.

In the `Data` struct:

* `int ival;` is a literal type (it's a built-in type).
* `std::string s;` is **not a literal type**. `std::string` has a user-defined destructor, copy constructor, and assignment operator, which disqualifies it from being a literal type.

Because `std::string` is not a literal type, `Data` cannot be a literal type, even though `int` is.

## ch07_exrc_7p56

Exercise 7.56: What is a `static` class member? What are the advantages of `static` members? How do they differ from ordinary members?

**What is a `static` class member?**

A `static` class member (data member or member function) is a member that **belongs to the class itself**, rather than to individual objects (instances) of the class. There is only **one copy** of a `static` data member, shared by all objects of that class. `static` member functions can be called without an object.

**Advantages of `static` members:**

* **Shared Data:** Provides a way for all objects of a class to share the same data, ensuring consistency (e.g., a counter for created objects).
* **Utility Functions:** Enables defining utility functions that are logically associated with a class but don't operate on specific object instances (e.g., a factory method, a comparison function).
* **Namespace Scoping:** They provide better organization than global functions/variables by being scoped within the class's name.
* **Access without Object:** `static` members can be accessed directly using the class name (`ClassName::staticMember`) without needing an object instance.

**How do they differ from ordinary members?**

* **Ownership:**
    * **Ordinary:** Belongs to each individual object. Each object has its own copy of the data.
    * **Static:** Belongs to the class itself. There is only one copy, shared by all objects.
* **Storage:**
    * **Ordinary Data:** Stored as part of each object's memory footprint.
    * **Static Data:** Stored separately, outside of any object.
* **Access:**
    * **Ordinary:** Accessed via an object instance (`object.member`) and implicitly via `this` pointer in non-static member functions.
    * **Static:** Accessed via the class name (`ClassName::staticMember`) or, less commonly, via an object instance (`object.staticMember`). `static` member functions do *not* have a `this` pointer and can only access other `static` members or global data.
* **Initialization (Data Members):**
    * **Ordinary Data:** Initialized when an object is constructed.
    * **Static Data:** Must be defined and often initialized outside the class definition, typically in a single `.cpp` file.

## ch07_exrc_7p57

Exercise 7.57: Write your own version of the `Account` class.

```cpp
class Account {
    public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

    private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

void Account::rate(double newRate) {
    interestRate = newRate;
}

// define and initialize a static class member
double Account::interestRate = initRate();

double Account::initRate() {
    return double(8.5);
}
```

## ch07_exrc_7p58

Exercise 7.58: Which, if any, of the following `static` data member declarations and definitions are errors? Explain why.

```cpp
// example.h
class Example {
    public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};

// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```

Let's analyze each part of the `static` data member declarations and definitions:

**Inside `example.h` (Declarations):**

1.  **`static double rate = 6.5;`**
    * **Error:** Yes, this is an error.
    * **Explanation:** Non-`const` `static` data members **cannot be initialized inside the class definition** (in the header file). Their definition and initialization must occur outside the class, typically in a single `.cpp` file. Only `static const` integral types (and `static constexpr` in C++11 and later for any literal type) can be initialized directly in the class definition.

2.  **`static const int vecSize = 20;`**
    * **Error:** No, this is **legal**.
    * **Explanation:** `static const int` members (which are integral types) *can* be initialized directly inside the class definition (in the header). This is a special rule for such members, allowing them to be used as compile-time constants (e.g., for array sizes).

3.  **`static vector<double> vec(vecSize);`**
    * **Error:** Yes, this is an error.
    * **Explanation:**
        * Like `rate`, `static` members that are **not integral constants** (or `constexpr` literal types) cannot be initialized inside the class definition. `std::vector` is a class type, not an integral type.
        * Even if it were an integral type, `vec(vecSize)` uses **parenthesized initialization**, which is generally not allowed for in-class initializers for `static` members (only brace or equals initializer are).
        * Furthermore, even if the syntax were allowed, it still violates the rule that non-integral-constant `static` members must be *defined* (and possibly initialized) outside the class.

**Inside `example.C` (Definitions):**

1.  **`double Example::rate;`**
    * **Error:** No, this is **legal (and necessary)**.
    * **Explanation:** This provides the definition for the `static double rate` declared in the header. If it needed an initial value, it would be `double Example::rate = 6.5;` here. Since it was given `6.5` in the declaration, this definition is just providing the storage. If you had removed the `= 6.5` from the header, then `double Example::rate = 6.5;` would be needed here. Given the error in the header, you would indeed need `double Example::rate = 6.5;` here.

2.  **`vector<double> Example::vec;`**
    * **Error:** No, this is **legal (and necessary)**.
    * **Explanation:** This provides the definition for the `static vector<double> vec` declared in the header. You would typically initialize it here as well, e.g., `std::vector<double> Example::vec(vecSize);` (note `std::vector` qualification and using `vecSize` which is now a valid static const member).

---

**Corrected `example.h` and `example.C`:**

**`example.h`:**

```cpp
// example.h
#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <vector> // Need to include <vector> for std::vector
// using std::vector; // Optional, can use std::vector explicitly

class Example {
public:
    // static double rate = 6.5; // ILLEGAL: Remove initialization here
    static double rate; // Just the declaration

    static const int vecSize = 20; // LEGAL: static const integral type can be initialized in-class

    // static vector<double> vec(vecSize); // ILLEGAL: Remove initialization here, and use std::vector
    static std::vector<double> vec; // Just the declaration (must use std::vector)
};

#endif // EXAMPLE_H
```

**`example.C`:**

```cpp
// example.C
#include "example.h"
#include <vector> // Best practice to include headers needed for definitions here too

// Definition and initialization for static double rate
double Example::rate = 6.5; // Initialize here

// Definition and initialization for static vector<double> vec
// Note: vecSize is accessible here as it's a static const member.
std::vector<double> Example::vec(Example::vecSize); // Initialize here
```