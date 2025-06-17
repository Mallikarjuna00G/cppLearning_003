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

