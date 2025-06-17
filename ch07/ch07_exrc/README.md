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

