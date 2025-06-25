# Revisit Notes

**NOTE: This is just a notes captured during my revision and does not have consistency but just my understandings and the points I thought of capturing.**

# ch07: Classes

- Data abstraction is a programming (and design) technique that relies on the separation of `interface` and `implementation`.

## 7.1 Defining Abstract Data Types

- Functions defined in the class are implicitly inline.

#### Introducing `this`

- Member functions access the object on which they were called through an extra, implicit parameter named `this`.
- `this` is initialized with the address of the object on which the function was invoked.
- `this` is a `const` pointer.

#### Introducing `const` Member Functions

- By default, the type of `this` is a `const` pointer to the non`const` version of the class type.
- Although `this` is implicit, it follows the normal initialization rules, which means that (by default) we cannot bind `this` to a `const` object.
- This fact, in turn, means that we cannot call an *ordinary member function* on a `const` object. (Because ordinary member function usually changes the data in the object).
- `this` is implicit (does not appear in the parameter list of any member functions) and does not appear in the parameter list. And there is no place to indicate that this should be a pointer to `const`.
- The language resolves this problem by letting us put `const` after the parameter list of a member function. A `const` following the parameter list indicates that this is a pointer to `const`. Member functions that use `const` in this way are **`const` member functions**.


<br>
<br>


- The fact that `this` is a *pointer to `const`* means that `const` member functions cannot change the object on which they are called. That means `const` member functions may read but not write to the data members of the objects on which it is called.

> Objects that are `const`, and references or pointers to `const` objects, may call only `const` member functions.

#### Class Scope and Member Functions

- The compiler processes classes in two steps—the member declarations are compiled first, after which the member function bodies, if any, are processed. Thus, member function bodies may use other members of their class regardless of where in the class those members appear.

#### Defining a Member Function outside the Class

- If the member was declared as a `const` member function, then the definition must also specify `const` after the parameter list.


#### Defining a Function to Return "This" Object

```cpp
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue; // the members of ‘‘this'' object
    return *this; // return the object on which the function was called
}
```

```cpp
total.combine(trans); // update the running total
```

- Note that we are returning the reference to the object. This avoids creation of temporary objects. And the other advatage is we can use it on left hand side of many of the operators like assignment, IO stream operators. This also helps in chaining.

- Here the return statement <u>***dereferences***</u> `this` to obtain the object on which the function is executing. That is, for the call above, we return a reference to `total`.

### 7.1.3 Defining Nonmember Class-Related Functions

- *auxiliary functions*: conceptually part of the interface of the class, they are not part of the class itself.

> Ordinarily, nonmember functions that are part of the interface of a class should be declared in the same header as the class itself.

#### Defining the read and print Functions

- The IO classes are types that cannot be copied, so we may only pass them by reference.
- Moreover, reading or writing to a stream changes that stream, so functions take ordinary references, not references to `const`.

```cpp
// input transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}
```

### 7.1.4 Constructors

- Classes control object initialization by defining one or more special member functions known as **constructors**.
- Unlike other member functions, constructors may not be declared as `const`.
- When we create a `const` object of a class type, the object does not assume its "`const`ness" until after the constructor completes the object's initialization.

#### The Synthesized Default Constructor

- Classes control *default initialization* by defining a special constructor, known as the **default constructor**. The default constructor is one that takes no arguments.

- If our class does not explicitly define any constructors, the compiler will implicitly define the default constructor for us.
- The compiler-generated constructor is known as the **synthesized default constructor**.

For most classes, this synthesized constructor initializes each data member of the class as follows:
- If there is an *in-class initializer*, use it to initialize the member.
- Otherwise, *default-initialize* the member.

#### Some Classes Cannot Rely on the Synthesized Default Constructor

- Objects of built-in or compound type (such as arrays and pointers) that are defined inside a block have undefined value when they are default initialized.
- Therefore, classes that have members of built-in or compound type should ordinarily either initialize those members inside the class or define their own version of the default constructor.

> Classes that have members of built-in or compound type usually should rely on the synthesized default constructor only if all such members have in-class initializers.

- Another reason that some classes must define their own default constructor is that sometimes the compiler is unable to synthesize one. For example, if a class has a member that has a class type, and that class doesn't have a default constructor, then the compiler can't initialize that member.

#### Defining the Sales_data Constructors

```cpp
struct Sales_data {
    // constructors added
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);

    // other members as before
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

#### What `= default` Means

`Sales_data() = default;`: 

- Default contructor. We want this constructor to do exactly the same work as the synthesized version we had been using.

- Like any other function, if the `= default` appears inside the class body, the default constructor will be inlined; if it appears on the definition outside the class, the member will not be inlined by default.

#### Constructor Initializer List

```cpp
Sales_data(const std::string &s): bookNo(s) { }
Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
```

- The new parts in these definitions are the colon and the code between it and the curly braces that define the (empty) function bodies. This new part is a **constructor initializer list**, which specifies initial values for one or more data members of the object being created.

- If your compiler does not yet support in-class initializers, then every constructor should explicitly initialize every member of built-in type.

> Constructors should not override in-class initializers except to use a different initial value. If you can't use in-class initializers, each constructor should explicitly initialize every member of built-in type.

#### Defining a Constructor outside the Class Body

```cpp
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this); // read will read a transaction from is into this object
}
```

- Even though the constructor initializer list is empty, the members of this object are still initialized before the constructor body is executed.

- Members that do not appear in the constructor initializer list are initialized by the corresponding in-class initializer (if there is one) or are default initialized.

### 7.1.5 Copy, Assignment, and Destruction

#### Some Classes Cannot Rely on the Synthesized Versions

- Cannot always rely on synthesized versions of the copy, assignment, and destruction operations.

- In particular, the synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves (For example, in the cases of managing dynamic memory allocation).

## 7.2 Access Control and Encapsulation

In C++ we use access specifiers to enforce encapsulation:
- Members defined after a `public` specifier are accessible to all parts of the program. The public members define the interface to the class.
- Members defined after a `private` specifier are accessible to the member functions of the class but are not accessible to code that uses the class. The `private` sections encapsulate (i.e., hide) the implementation.

```cpp
class Sales_data {
    public: // access specifier added
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(std::istream&);

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);

    private: // access specifier added
    double avg_price() const
    { return units_sold ? revenue/units_sold : 0; }
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

- A class may contain zero or more access specifiers, and there are no restrictions on how often an access specifier may appear.

#### Using the `class` or `struct` Keyword

- We can define a class type using either (`class` or `struct`) keyword. - The only difference between `struct` and `class` is the default access level.
- If we use the `struct` keyword, the members defined before the first access specifier are public; if we use `class`, then the members are private.

### 7.2.1 Friends

- A class can allow another class or function to access its nonpublic members by making that class or function a `friend`.
- A class makes a function its friend by including a declaration for that function preceded by the keyword `friend`.

```cpp
class Sales_data {
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    // other members and access specifiers as before
    
    public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(std::istream&);

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);
    
    private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// declarations for nonmember parts of the Sales_data interface
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
```

Friend declarations may appear only inside a class definition; they may appear anywhere in the class. Friends are not members of the class and are not affected by the access control of the section in which they are declared.

#### Declarations for Friends

- A friend declaration only specifies access. It is not a general declaration of the function.

- If we want users of the class to be able to call a friend function, then we must also declare the function separately from the friend declaration.
- To make a friend visible to users of the class, we usually declare each friend (outside the class) in the same header as the class itself.

## 7.3 Additional Class Features

### 7.3.1 Class Members Revisited

#### Defining a Type Member

```cpp
class Screen {
    public:
    typedef std::string::size_type pos;
    
    private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
```

```cpp
class Screen {
    public:
    // alternative way to declare a type member using a type alias
    using pos = std::string::size_type;
    // other members as before
};
```

- unlike ordinary members, members that define types must appear before they are used.

#### Member Functions of class Screen

```cpp
class Screen {
    public:
    typedef std::string::size_type pos;
    
    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    char get() const // get the character at the cursor
    { return contents[cursor]; } // implicitly inline
    
    inline char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c); // can be made inline later
    
    private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
```

- we use `= default` to ask the compiler to synthesize the default constructor'''s definition for us.

#### Making Members inline

- member functions defined inside the class are automatically `inline`.

```cpp
inline // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c; // move cursor to the column within that row
    return *this; // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width; // compute row location
    return contents[row + c]; // return character at the given column
}
```

- `inline` member functions better/should be defined in the same header as the corresponding class definition.

#### Overloading Member Functions

```cpp
Screen myscreen;
char ch = myscreen.get();// calls Screen::get()
ch = myscreen.get(0,0); // calls Screen::get(pos, pos)
```

#### mutable Data Members

- It sometimes (but not very often) happens that a class has a data member that we want to be able to modify, even inside a `const` member function.

- A mutable data member is never `const`, even when it is a member of a `const` object.

```cpp
class Screen {
    public:
    void some_member() const;
    
    private:
    mutable size_t access_ctr; // may change even in a const object
    // other members as before
};

void Screen::some_member() const
{
    ++access_ctr; // keep a count of the calls to any member function
    // whatever other work this member needs to do
}
```

#### Initializers for Data Members of Class Type

```cpp
class Window_mgr {
    private:
    // Screens this Window_mgr is tracking
    // by default, a Window_mgr has one standard sized blank Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};
```

> When we provide an in-class initializer, we must do so following an `=` sign or inside braces.

### 7.3.2 Functions That Return `*this`

```cpp
class Screen {
    public:
    Screen &set(char);
    Screen &set(pos, pos, char);
    // other members as before
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this; // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch; // set specified location to given value
    return *this; // return this object as an lvalue
}
```

```cpp
// move the cursor to a given position, and set that character
myScreen.move(4,0).set('#');
```

equivalent to 

```cpp
myScreen.move(4,0);
myScreen.set('#');
```

#### Returning `*this` from a `const` Member Function

```cpp
Screen myScreen;
// if display returns a const reference, the call to set is an error
myScreen.display(cout).set('*');
```

> A `const` member function that returns `*this` as a reference should have a return type that is a reference to `const`.

#### Overloading Based on `const`

```cpp
class Screen {
    public:
    // display overloaded on whether the object is const or not
    Screen &display(std::ostream &os)
    { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
    { do_display(os); return *this; }
    
    private:
    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const {os << contents;}
    // other members as before
};
```

```cpp
Screen myScreen(5,3);
const Screen blank(5, 3);
myScreen.set('#').display(cout); // calls nonconst version
blank.display(cout); // calls const version
```

> ADVICE: USE PRIVATE UTILITY FUNCTIONS FOR COMMON CODE  
> 
> Some readers might be surprised that we bothered to define a separate `do_display` operation. After all, the calls to `do_display` aren't much simpler than the action done inside `do_display`. Why bother? We do so for several reasons:
> - A general desire to avoid writing the same code in more than one place.
> - We expect that the display operation will become more complicated as our class evolves. As the actions involved become more complicated, it makes more obvious sense to write those actions in one place, not two.
> - It is likely that we might want to add debugging information to `do_display` during development that would be eliminated in the final product version of the code. It will be easier to do so if only one definition of `do_display` needs to be changed to add or remove the debugging code.
> - There needn't be any overhead involved in this extra function call. We defined `do_display` inside the class body, so it is implicitly `inline`. Thus, there likely be no run-time overhead associating with calling `do_display`.
>
> In practice, well-designed C++ programs tend to have lots of small functions such as `do_display` that are called to do the "real" work of some other set of functions.

### 7.3.3 Class Types

- Two different classes define two different types even if they define the same members.

```cpp
struct First {
    int memi;
    int getMem();
};

struct Second {
    int memi;
    int getMem();
};

First obj1;
Second obj2 = obj1; // error: obj1 and obj2 have different types
```

#### Class Declarations

- we can also declare a class without defining it, which is called as **forward declaration**:

```cpp
class Screen; // declaration of the Screen class
```

- introduces the name `Screen` into the program and indicates that `Screen` refers to a class type.

- After a declaration and before a definition is seen, the type `Screen` is an **incomplete type**.

- We can use an incomplete type in only limited ways: We can define pointers or references to such types, and we can declare (but not define) functions that use an incomplete type as a parameter or return type.

With one exception that we'll describe in § 7.6 (p. 300), data members can be specified to be of a class type only if the class has been defined. The type must be complete because the compiler needs to know how much storage the data member requires. Because a class is not defined until its class body is complete, a class cannot have data members of its own type. 

- However, a class is considered declared (but not yet defined) as soon as its class name has been seen. Therefore, a class can have data members that are pointers or references to its own type:

```cpp
class Link_screen {
    Screen window;
    Link_screen *next;
    Link_screen *prev;
};
```

### 7.3.4 Friendship Revisited

- A class can also make another class its friend or it can declare specific member functions of another (previously defined) class as friends.
- In addition, a friend function can be defined inside the class body. Such functions are implicitly `inline`.

#### Friendship between Classes

```cpp
class Screen {
    // Window_mgr members can access the private parts of class Screen
    friend class Window_mgr;
    // . . . rest of the Screen class
};
```

The member functions of a friend class can access all the members, including the nonpublic members, of the class granting friendship. 

```cpp
class Window_mgr {
    public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);
    
    private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = string(s.height * s.width, ' ');
}
```

- It is important to understand that friendship is not transitive. That is, if class `Window_mgr` has its own friends, those friends have no special access to Screen.

> Each class controls which classes or functions are its friends.

#### Making AMember Function a Friend

```cpp
class Screen {
    // Window_mgr::clear must have been declared before class Screen
    friend void Window_mgr::clear(ScreenIndex);
    // . . . rest of the Screen class
};
```

Making a member function a friend requires careful structuring of our programs to accommodate interdependencies among the declarations and definitions.

In this example, we must order our program as follows:
- First, define the `Window_mgr` class, which declares, but cannot define, `clear`. `Screen` must be declared before `clear` can use the members of `Screen`.
- Next, define class `Screen`, including a friend declaration for `clear`.
- Finally, define `clear`, which can now refer to the members in `Screen`.

#### Overloaded Functions and Friendship

```cpp
// overloaded storeOn functions
extern std::ostream& storeOn(std::ostream &, Screen &);
extern BitMap& storeOn(BitMap &, Screen &);

class Screen {
    // ostream version of storeOn may access the private parts of Screen objects
    friend std::ostream& storeOn(std::ostream &, Screen &);
    // . . .
};
```

#### Friend Declarations and Scope

- Classes and nonmember functions need not have been declared before they are used in a friend declaration.
- Even if we define the function inside the class, we must still provide a declaration outside of the class itself to make that function visible.
- A declaration must exist even if we only call the friend from members of the friendship granting class.

```cpp
struct X {
    friend void f() { /* friend function can be defined in the class body */ }
    X() { f(); } // error: no declaration for f
    void g();
    void h();
};

void X::g() { return f(); } // error: f hasn't been declared
void f(); // declares the function defined inside X
void X::h() { return f(); } // ok: declaration for f is now in scope
```

## 7.4 Class Scope

```cpp
Screen::pos ht = 24, wd = 80; // use the pos type defined by Screen
Screen scr(ht, wd, ' ');
Screen *p = &scr;
char c = scr.get(); // fetches the get member from the object scr
c = p->get(); // fetches the get member from the object to which p points
```

#### Scope and Members Defined outside the Class

```cpp
void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}
```

- `ScreenIndex` is visible.

```cpp
class Window_mgr {
    public:
    // add a Screen to the window and returns its index
    ScreenIndex addScreen(const Screen&);
    // other members as before
};

// return type is seen before we're in the scope of Window_mgr
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}
```

- Above we needed to mention `Window_mgr` for the return type.

### 7.4.1 Name Lookup and Class Scope

#### Name Lookup for Class Member Declarations

- Names used in declarations, including names used for the return type and types in the parameter list, must be seen before they are used.

```cpp
typedef double Money;
string bal;

class Account {
    public:
    Money balance() { return bal; }
    
    private:
    Money bal;
    // . . .
};
```

#### Type Names Are Special

- If a member uses a name from an outer scope and that name is a type, then the class may not subsequently redefine that name.

```cpp
typedef double Money;
class Account {
    public:
    Money balance() { return bal; } // uses Money from the outer scope
    
    private:
    typedef double Money; // error: cannot redefine Money
    Money bal;
    // . . .
};
```

> Definitions of type names usually should appear at the beginning of a class. That way any member that uses that type will be seen after the type name has already been defined.

#### Normal Block-Scope Name Lookup inside Member Definitions

```cpp
// note: this code is for illustration purposes only and reflects bad practice
// it is generally a bad idea to use the same name for a parameter and a member
int height; // defines a name subsequently used inside Screen
class Screen {
    public:
    typedef std::string::size_type pos;
    void dummy_fcn(pos height) {
        cursor = width * height; // which height? the parameter
    }
    
    private:
    pos cursor = 0;
    pos height = 0, width = 0;
};
```

```cpp
// bad practice: names local to member functions shouldn't hide member names
void Screen::dummy_fcn(pos height) {
    cursor = width * this->height; // member height
    // alternative way to indicate the member
    cursor = width * Screen::height; // member height
}
```

```cpp
// good practice: don't use a member name for a parameter or other local variable
void Screen::dummy_fcn(pos ht) {
    cursor = width * height; // member height
}
```

#### After Class Scope, Look in the Surrounding Scope

- If we want the name from the outer scope, we can ask for it explicitly using the scope operator

```cpp
// bad practice: don't hide names that are needed from surrounding scopes
void Screen::dummy_fcn(pos height) {
    cursor = width * ::height;// which height? the global one
}
```

#### Names Are Resolved Where They Appear within a File

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

## 7.5 Constructors Revisited

### 7.5.1 Constructor Initializer List

```cpp
string foo = "Hello World!"; // define and initialize
string bar; // default initialized to the empty string
bar = "Hello World!"; // assign a new value to bar
```

If we do not explicitly initialize a member in the constructor initializer list, that member is default initialized before the constructor body starts executing. For example:

```cpp
// legal but sloppier way to write the Sales_data constructor: no constructor initializers
Sales_data::Sales_data(const string &s, unsigned cnt, double price)
{
    bookNo = s;
    units_sold = cnt;
    revenue = cnt * price;
}
```

#### Constructor Initializers Are Sometimes Required

- Members that are const or references must be initialized.
- Members that are of a class type that does not define a default constructor also must be initialized.

```cpp
class ConstRef {
    public:
    ConstRef(int ii);
    
    private:
    int i;
    const int ci;
    int &ri;
};
```

```cpp
// error: ci and ri must be initialized
ConstRef::ConstRef(int ii)
{ // assignments:
    i = ii; // ok
    ci = ii; // error: cannot assign to a const
    ri = i; // error: ri was never initialized
}
```

- By the time the body of the constructor begins executing, initialization is complete.

```cpp
// ok: explicitly initialize reference and const members
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }
```

> We must use the constructor initializer list to provide values for members that are `const`, reference, or of a class type that does not have a default constructor.

> ADVICE: USE CONSTRUCTOR INITIALIZERS
>
> In many classes, the distinction between initialization and assignment is strictly a matter of low-level efficiency: A data member is initialized and then assigned when it could have been initialized directly.
> More important than the efficiency issue is the fact that some data members must be initialized. By routinely using constructor initializers, you can avoid being surprised by compile-time errors when you have a class with a member that requires a constructor initializer.

#### Order of Member Initialization

- constructor initializer list specifies only the values used to initialize the members, not the order in which those initializations are performed.
- Members are initialized in the order in which they appear in the class definition: The first member is initialized first, then the next, and so on.
- if one member is initialized in terms of another, then the order in which members are initialized is crucially important.

```cpp
class X {
int i;
int j;
    public:
    // undefined: i is initialized before j
    X(int val): j(val), i(j) { }
};
```

> It is a good idea to write constructor initializers in the same order as the members are declared. Moreover, when possible, avoid using members to initialize other members.

- better to write

```cpp
X(int val): i(val), j(val) { }
```

#### Default Arguments and Constructors

> A constructor that supplies default arguments for all its parameters also defines the default constructor.

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

### 7.5.2 Delegating Constructors

- A delegating constructor uses another constructor from its own class to perform its initialization.

```cpp
class Sales_data {
    public:
    // non delegating constructor initializes members from corresponding arguments
    Sales_data(std::string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt*price) { }
    // remaining constructors all delegate to another constructor
    Sales_data(): Sales_data("", 0, 0) {}
    Sales_data(std::string s): Sales_data(s, 0,0) {}
    Sales_data(std::istream &is): Sales_data()
    { read(is, *this); }
    // other members as before
};
```

- Body of the "delegated-to constructor" is executed and then the body of "delegating constructor" is executed.

### 7.5.3 The Role of the Default Constructor

The default constructor is used automatically whenever an object is *default* or *value initialized*. 

**Default initialization happens**
- When we define non`static` variables or arrays at block scope without initializers.
- When a class that itself has members of class type uses the synthesized default constructor
- When members of class type are not explicitly initialized in a constructor initializer list

**Value initialization happens**
- During array initialization when we provide fewer initializers than the size of the array
- When we define a local `static` object without an initializer
- When we explicitly request value initialization by writing an expressions of the form `T()` where `T` is the name of a type (The vector constructor that takes a single argument to specify the vector's size uses an argument of this kind to value initialize its element initializer.)

```cpp
class NoDefault {
    public:
    NoDefault(const std::string&);
    // additional members follow, but no other constructors
};

struct A { // my_mem is public by default; see § 7.2 (p. 268)
    NoDefault my_mem;
};

A a; // error: cannot synthesize a constructor for A

struct B {
    B() {} // error: no initializer for b_member
    NoDefault b_member;
};
```

> In practice, it is almost always right to provide a default constructor if other constructors are being defined.

#### Using the Default Constructor

- The following declaration of `obj` compiles without complaint.

```cpp
Sales_data obj(); // ok: but defines a function, not an object
if (obj.isbn() == Primer_5th_ed.isbn()) // error: obj is a function
```

- Intended to declare a default-initialized object, but `obj` actually declares a function taking no parameters and returning an object of type `Sales_data`.

```cpp
// ok: obj is a default-initialized object
Sales_data obj;
```

> It is a common mistake among programmers new to C++ to try to declare an object initialized with the default constructor as follows:

```cpp
Sales_data obj(); // oops! declares a function, not an object
Sales_data obj2; // ok: obj2 is an object, not a function
```

### 7.5.4 Implicit Class-Type Conversions

Every constructor that can be called with a single argument defines an implicit conversion to a class type. Such constructors are sometimes referred to as **converting constructors**.

```cpp
string null_book = "9-999-99999-9";
// constructs a temporary Sales_data object
// with units_sold and revenue equal to 0 and bookNo equal to null_book
item.combine(null_book);
```

#### Only One Class-Type Conversion Is Allowed

```cpp
// error: requires two user-defined conversions:
// (1) convert "9-999-99999-9" to string
// (2) convert that (temporary) string to Sales_data
item.combine("9-999-99999-9");
```

```cpp
// ok: explicit conversion to string, implicit conversion to Sales_data
item.combine(string("9-999-99999-9"));
// ok: implicit conversion to string, explicit conversion to Sales_data
item.combine(Sales_data("9-999-99999-9"));
```

#### Class-Type Conversions Are Not Always Useful

```cpp
// uses the istream constructor to build an object to pass to combine
item.combine(cin);
```

- we have constructed an object that is discarded after we add its value into `item`.

#### Suppressing Implicit Conversions Defined by Constructors

We can prevent the use of a constructor in a context that requires an implicit conversion by declaring the constructor as **explicit**:

```cpp
class Sales_data {
    public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    explicit Sales_data(const std::string &s): bookNo(s) { }
    explicit Sales_data(std::istream&);
    // remaining members as before
};
```

Now, neither constructor can be used to implicitly create a `Sales_data` object. Neither of our previous uses will compile:

```cpp
item.combine(null_book); // error: string constructor is explicit
item.combine(cin); // error: istream constructor is explicit
```

- The `explicit` keyword is meaningful only on constructors that can be called with a single argument. Constructors that require more arguments are not used to perform an implicit conversion, so there is no need to designate such constructors as `explicit`. 
- The `explicit` keyword is used only on the constructor declaration inside the class. It is not repeated on a definition made outside the class body:

```cpp
// error: explicit allowed only on a constructor declaration in a class header
explicit Sales_data::Sales_data(istream& is)
{
    read(is, *this);
}
```

#### `explicit` Constructors Can Be Used Only for Direct Initialization

```cpp
Sales_data item1(null_book); // ok: direct initialization
// error: cannot use the copy form of initialization with an explicit constructor
Sales_data item2 = null_book;
```

#### Explicitly Using Constructors for Conversions

```cpp
// ok: the argument is an explicitly constructed Sales_data object
item.combine(Sales_data(null_book));
// ok: static_cast can use an explicit constructor
item.combine(static_cast<Sales_data>(cin));
```

#### Library Classes with explicit Constructors

Some of the library classes that we've used have single-parameter constructors:
- The `string` constructor that takes a single parameter of type `const char*` is not `explicit`.
- The `vector` constructor that takes a size is `explicit`.

### 7.5.5 Aggregate Classes

An aggregate class gives users direct access to its members and has special initialization syntax. A class is an aggregate if
- All of its data members are public
- It does not define any constructors
- It has no in-class initializers
- It has no base classes or virtual functions

For example, the following class is an aggregate:

```cpp
struct Data {
    int ival;
    string s;
};
```

We can initialize the data members of an aggregate class by providing a braced list of member initializers:

```cpp
// val1.ival = 0; val1.s = string("Anna")
Data val1 = { 0, "Anna" };
```

- The initializers must appear in declaration order of the data members.

```cpp
// error: can't use "Anna" to initialize ival, or 1024 to initialize s
Data val2 = { "Anna" , 1024 };
```

### 7.5.6 Literal Classes

- Classes can also be literal types.
- Unlike other classes, classes that are literal types may have function members that are `constexpr`. Such members must meet all the requirements of a `constexpr` function. These member functions are implicitly `const`.

#### `constexpr` Constructors

- a literal class must provide at least one `constexpr` constructor.
- a `constexpr` constructor must meet the requirements of a constructor—meaning it can have no return statement—and of a `constexpr` function—meaning the only executable statement it can have is a return statement.

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

- A `constexpr` constructor must initialize every data member. The initializers must either use a `constexpr` constructor or be a constant expression.

A `constexpr` constructor is used to generate objects that are `constexpr` and for parameters or return types in `constexpr` functions:

```cpp
constexpr Debug io_sub(false, true, false); // debugging IO
if (io_sub.any()) // equivalent to if(true)
    cerr << "print appropriate error messages" << endl;

constexpr Debug prod(false); // no debugging during production
if (prod.any()) // equivalent to if(false)
    cerr << "print an error message" << endl;
```

## 7.6 `static` Class Members

### Declaring `static` Members

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
```

- Static member functions are not bound to any object; they do not have a `this` pointer. As a result, static member functions may not be declared as `const`, and we may not refer to `this` in the body of a static member.

#### Using a Class `static` Member

We can access a static member directly through the scope operator:

```cpp
double r;
r = Account::rate(); // access a static member using the scope operator
```

```cpp
Account ac1;
Account *ac2 = &ac1;
// equivalent ways to call the static member rate function
r = ac1.rate(); // through an Account object or reference
r = ac2->rate(); // through a pointer to an Account object
```

```cpp
class Account {
    public:
    // can be used without scope operator
    void calculate() { amount += amount * interestRate; }
    
    private:
    static double interestRate;
    // remaining members as before
};
```

#### Defining `static` Members

- When we define a `static` member outside the class, we do not repeat the `static` keyword.

```cpp
void Account::rate(double newRate)
{
    interestRate = newRate;
}
```

- are not initialized by the class' constructors.
- we must define and initialize each `static` data member outside the class body.

```cpp
// define and initialize a static class member
double Account::interestRate = initRate();
```

> The best way to ensure that the object is defined exactly once is to put the definition of `static` data members in the same file that contains the definitions of the class non`inline` member functions.

#### In-Class Initialization of `static` Data Members

```cpp
class Account {
    public:
    static double rate() { return interestRate; }
    static void rate(double);
    
    private:
    static constexpr int period = 30;// period is a constant expression
    double daily_tbl[period];
};
```

```cpp
// definition of a static member with no initializer
constexpr int Account::period; // initializer provided in the class definition
```

> Even if a const static data member is initialized in the class body, that member ordinarily should be defined outside the class definition.

#### `static` Members Can Be Used in Ways Ordinary Members Can't

- a `static` data member can have incomplete type.

```cpp
class Bar {
    public:
    // . . .
    private:
    static Bar mem1; // ok: static member can have incomplete type
    Bar *mem2; // ok: pointer member can have incomplete type
    Bar mem3; // error: data members must have complete type
};
```

- we can use a `static` member as a default argument.

```cpp
class Screen {
    public:
    // bkground refers to the static member
    // declared later in the class definition
    Screen& clear(char = bkground);
    
    private:
    static const char bkground;
};
```

