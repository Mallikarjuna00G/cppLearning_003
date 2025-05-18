# ch01_exrc

## ch01_exrc_1p1

```console
$ ./perform.sh 1
Compiling 'ch01_exrc_1p1.cpp' using g++ with C++11 standard...
Compilation successful. Executable created: 'a.out'

$ ./perform.sh 2
Executing './a.out'...

--------------------------
Last execution status: 0


```

##  ch01_exrc_1p2

```console
$ ./perform.sh 1
Compiling 'ch01_exrc_1p2.cpp' using g++ with C++11 standard...
Compilation successful. Executable created: 'a.out'

$ ./perform.sh 2
Executing './a.out'...

--------------------------
Last execution status: 255
```

## ch01_exrc_1p6

The given code fragment

```cpp
std::cout << "The sum of " << v1;
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;
```

is illegal. The second and third lines need to be preceeded with `std::cout` because each line is terminated with semicolon. Otherwise, the semicolons from the first and secons lines need to be removed. Therefore, either of the following code fragments are correct.

```cpp
std::cout << "The sum of " << v1;
std::cout << " and " << v2;
std::cout << " is " << v1 + v2 << std::endl;
```

```cpp
std::cout << "The sum of " << v1
    << " and " << v2
    << " is " << v1 + v2 << std::endl;
```

Assuming v1 is 3 and v2 is 7, the output will be of the form

```console
The sum of 3 and 7 is 10
```