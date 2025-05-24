# ch03_exmp

## ch03_exmp_3p1_01

```console
$ ./perform.sh 
Compiling 'ch03_exmp_3p1_01.cpp' using g++ with C++11 standard...
g++ -std=c++11 -Wall ch03_exmp_3p1_01.cpp -o a.out
ch03_exmp_3p1_01.cpp: In function ‘int main()’:
ch03_exmp_3p1_01.cpp:8:5: error: ‘cout’ was not declared in this scope; did you mean ‘std::cout’?
    8 |     cout << i;  // error: no using declaration; we must use the full name;
      |     ^~~~
      |     std::cout
In file included from ch03_exmp_3p1_01.cpp:1:
/usr/include/c++/12/iostream:61:18: note: ‘std::cout’ declared here
   61 |   extern ostream cout;          /// Linked to standard output
      |                  ^~~~
Compilation failed.
```