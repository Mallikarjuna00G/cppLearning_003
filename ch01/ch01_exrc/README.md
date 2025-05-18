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

## ch01_exrc_1p7

```console
$ ./perform.sh 1
Compiling 'ch01_exrc_1p7.cpp' using g++ with C++11 standard...
g++ -std=c++11 -Wall ch01_exrc_1p7.cpp -o a.out
ch01_exrc_1p7.cpp:2:18: warning: "/*" within comment [-Wcomment]
    2 |  * comment pairs /*    */ cannot nest.
      |                   
ch01_exrc_1p7.cpp:2:27: error: ‘cannot’ does not name a type
    2 |  * comment pairs /*    */ cannot nest.
      |                           ^~~~~~
Compilation failed.
```

## ch01_exrc_1p8

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

Errors start from line 3.

compilation result without corrections:

```console
$ ./perform.sh 1
Compiling 'ch01_exrc_1p8.cpp' using g++ with C++11 standard...
g++ -std=c++11 -Wall ch01_exrc_1p8.cpp -o a.out
ch01_exrc_1p8.cpp:5:24: warning: missing terminating " character
    5 |     std::cout << /* "*/" */;
      |                        ^
ch01_exrc_1p8.cpp:5:24: error: missing terminating " character
    5 |     std::cout << /* "*/" */;
      |                        ^~~~~
ch01_exrc_1p8.cpp: In function ‘int main()’:
ch01_exrc_1p8.cpp:5:15: error: no match for ‘operator<<’ (operand types are ‘std::ostream’ {aka ‘std::basic_ostream<char>’} and ‘std::ostream’ {aka ‘std::basic_ostream<char>’})
    5 |     std::cout << /* "*/" */;
      |     ~~~~~~~~~ ^~
      |          |
      |          basic_ostream<[...]>
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~~~~~  
      |          |
      |          basic_ostream<[...]>
ch01_exrc_1p8.cpp:5:15: note: candidate: ‘operator<<(int, int)’ (built-in)
    5 |     std::cout << /* "*/" */;
      |     ~~~~~~~~~~^~~~~~~~~~~~~~
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~~~~~  
ch01_exrc_1p8.cpp:5:15: note:   no known conversion for argument 2 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘int’
In file included from /usr/include/c++/12/iostream:39,
                 from ch01_exrc_1p8.cpp:1:
/usr/include/c++/12/ostream:108:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(__ostream_type& (*)(__ostream_type&)) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  108 |       operator<<(__ostream_type& (*__pf)(__ostream_type&))
      |       ^~~~~~~~
/usr/include/c++/12/ostream:108:36: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘std::basic_ostream<char>::__ostream_type& (*)(std::basic_ostream<char>::__ostream_type&)’ {aka ‘std::basic_ostream<char>& (*)(std::basic_ostream<char>&)’}
  108 |       operator<<(__ostream_type& (*__pf)(__ostream_type&))
      |                  ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/12/ostream:117:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(__ios_type& (*)(__ios_type&)) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>; __ios_type = std::basic_ios<char>]’
  117 |       operator<<(__ios_type& (*__pf)(__ios_type&))
      |       ^~~~~~~~
/usr/include/c++/12/ostream:117:32: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘std::basic_ostream<char>::__ios_type& (*)(std::basic_ostream<char>::__ios_type&)’ {aka ‘std::basic_ios<char>& (*)(std::basic_ios<char>&)’}
  117 |       operator<<(__ios_type& (*__pf)(__ios_type&))
      |                  ~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~
/usr/include/c++/12/ostream:127:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(std::ios_base& (*)(std::ios_base&)) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  127 |       operator<<(ios_base& (*__pf) (ios_base&))
      |       ^~~~~~~~
/usr/include/c++/12/ostream:127:30: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘std::ios_base& (*)(std::ios_base&)’
  127 |       operator<<(ios_base& (*__pf) (ios_base&))
      |                  ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~
/usr/include/c++/12/ostream:166:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long int) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  166 |       operator<<(long __n)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:166:23: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘long int’
  166 |       operator<<(long __n)
      |                  ~~~~~^~~
/usr/include/c++/12/ostream:170:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  170 |       operator<<(unsigned long __n)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:170:32: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘long unsigned int’
  170 |       operator<<(unsigned long __n)
      |                  ~~~~~~~~~~~~~~^~~
/usr/include/c++/12/ostream:174:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(bool) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  174 |       operator<<(bool __n)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:174:23: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘bool’
  174 |       operator<<(bool __n)
      |                  ~~~~~^~~
In file included from /usr/include/c++/12/ostream:833:
/usr/include/c++/12/bits/ostream.tcc:91:5: note: candidate: ‘std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(short int) [with _CharT = char; _Traits = std::char_traits<char>]’
   91 |     basic_ostream<_CharT, _Traits>::
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/12/bits/ostream.tcc:92:22: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘short int’
   92 |     operator<<(short __n)
      |                ~~~~~~^~~
/usr/include/c++/12/ostream:181:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(short unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  181 |       operator<<(unsigned short __n)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:181:33: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘short unsigned int’
  181 |       operator<<(unsigned short __n)
      |                  ~~~~~~~~~~~~~~~^~~
/usr/include/c++/12/bits/ostream.tcc:105:5: note: candidate: ‘std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(int) [with _CharT = char; _Traits = std::char_traits<char>]’
  105 |     basic_ostream<_CharT, _Traits>::
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/12/bits/ostream.tcc:106:20: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘int’
  106 |     operator<<(int __n)
      |                ~~~~^~~
/usr/include/c++/12/ostream:192:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  192 |       operator<<(unsigned int __n)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:192:31: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘unsigned int’
  192 |       operator<<(unsigned int __n)
      |                  ~~~~~~~~~~~~~^~~
/usr/include/c++/12/ostream:201:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long long int) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  201 |       operator<<(long long __n)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:201:28: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘long long int’
  201 |       operator<<(long long __n)
      |                  ~~~~~~~~~~^~~
/usr/include/c++/12/ostream:205:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long long unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  205 |       operator<<(unsigned long long __n)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:205:37: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘long long unsigned int’
  205 |       operator<<(unsigned long long __n)
      |                  ~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/12/ostream:220:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(double) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  220 |       operator<<(double __f)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:220:25: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘double’
  220 |       operator<<(double __f)
      |                  ~~~~~~~^~~
/usr/include/c++/12/ostream:224:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(float) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  224 |       operator<<(float __f)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:224:24: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘float’
  224 |       operator<<(float __f)
      |                  ~~~~~~^~~
/usr/include/c++/12/ostream:232:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long double) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  232 |       operator<<(long double __f)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:232:30: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘long double’
  232 |       operator<<(long double __f)
      |                  ~~~~~~~~~~~~^~~
/usr/include/c++/12/ostream:245:7: note: candidate: ‘std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(const void*) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]’
  245 |       operator<<(const void* __p)
      |       ^~~~~~~~
/usr/include/c++/12/ostream:245:30: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘const void*’
  245 |       operator<<(const void* __p)
      |                  ~~~~~~~~~~~~^~~
/usr/include/c++/12/bits/ostream.tcc:119:5: note: candidate: ‘std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(__streambuf_type*) [with _CharT = char; _Traits = std::char_traits<char>; __streambuf_type = std::basic_streambuf<char>]’
  119 |     basic_ostream<_CharT, _Traits>::
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/12/bits/ostream.tcc:120:34: note:   no known conversion for argument 1 from ‘std::ostream’ {aka ‘std::basic_ostream<char>’} to ‘std::basic_ostream<char>::__streambuf_type*’ {aka ‘std::basic_streambuf<char>*’}
  120 |     operator<<(__streambuf_type* __sbin)
      |                ~~~~~~~~~~~~~~~~~~^~~~~~
In file included from /usr/include/c++/12/string:53,
                 from /usr/include/c++/12/bits/locale_classes.h:40,
                 from /usr/include/c++/12/bits/ios_base.h:41,
                 from /usr/include/c++/12/ios:42,
                 from /usr/include/c++/12/ostream:38:
/usr/include/c++/12/bits/basic_string.h:3883:5: note: candidate: ‘template<class _CharT, class _Traits, class _Alloc> std::basic_ostream<_CharT, _Traits>& std::operator<<(basic_ostream<_CharT, _Traits>&, const __cxx11::basic_string<_CharT, _Traits, _Alloc>&)’
 3883 |     operator<<(basic_ostream<_CharT, _Traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/12/bits/basic_string.h:3883:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   ‘std::ostream’ {aka ‘std::basic_ostream<char>’} is not derived from ‘const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>’
    6 |     std::cout << /* "*/" /* "/*" */;
      |          ^~~~
In file included from /usr/include/c++/12/bits/ios_base.h:46:
/usr/include/c++/12/system_error:279:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(basic_ostream<_CharT, _Traits>&, const error_code&)’
  279 |     operator<<(basic_ostream<_CharT, _Traits>& __os, const error_code& __e)
      |     ^~~~~~~~
/usr/include/c++/12/system_error:279:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘const std::error_code&’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:507:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(basic_ostream<_CharT, _Traits>&, _CharT)’
  507 |     operator<<(basic_ostream<_CharT, _Traits>& __out, _CharT __c)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:507:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   deduced conflicting types for parameter ‘_CharT’ (‘char’ and ‘std::basic_ostream<char>’)
    6 |     std::cout << /* "*/" /* "/*" */;
      |          ^~~~
/usr/include/c++/12/ostream:517:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(basic_ostream<_CharT, _Traits>&, char)’
  517 |     operator<<(basic_ostream<_CharT, _Traits>& __out, char __c)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:517:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘char’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:523:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(basic_ostream<char, _Traits>&, char)’
  523 |     operator<<(basic_ostream<char, _Traits>& __out, char __c)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:523:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘char’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:534:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(basic_ostream<char, _Traits>&, signed char)’
  534 |     operator<<(basic_ostream<char, _Traits>& __out, signed char __c)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:534:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘signed char’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:539:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(basic_ostream<char, _Traits>&, unsigned char)’
  539 |     operator<<(basic_ostream<char, _Traits>& __out, unsigned char __c)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:539:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘unsigned char’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:598:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(basic_ostream<_CharT, _Traits>&, const _CharT*)’
  598 |     operator<<(basic_ostream<_CharT, _Traits>& __out, const _CharT* __s)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:598:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   mismatched types ‘const _CharT*’ and ‘std::basic_ostream<char>’
    6 |     std::cout << /* "*/" /* "/*" */;
      |          ^~~~
/usr/include/c++/12/bits/ostream.tcc:302:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(basic_ostream<_CharT, _Traits>&, const char*)’
  302 |     operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s)
      |     ^~~~~~~~
/usr/include/c++/12/bits/ostream.tcc:302:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘const char*’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:615:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(basic_ostream<char, _Traits>&, const char*)’
  615 |     operator<<(basic_ostream<char, _Traits>& __out, const char* __s)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:615:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘const char*’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:628:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(basic_ostream<char, _Traits>&, const signed char*)’
  628 |     operator<<(basic_ostream<char, _Traits>& __out, const signed char* __s)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:628:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘const signed char*’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:633:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(basic_ostream<char, _Traits>&, const unsigned char*)’
  633 |     operator<<(basic_ostream<char, _Traits>& __out, const unsigned char* __s)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:633:5: note:   template argument deduction/substitution failed:
ch01_exrc_1p8.cpp:6:10: note:   cannot convert ‘std::cout’ (type ‘std::ostream’ {aka ‘std::basic_ostream<char>’}) to type ‘const unsigned char*’
    6 |     std::cout << /* "*/" /* "/*" */;
      |     ~~~~~^~~~
/usr/include/c++/12/ostream:754:5: note: candidate: ‘template<class _Ostream, class _Tp> _Ostream&& std::operator<<(_Ostream&&, const _Tp&)’
  754 |     operator<<(_Ostream&& __os, const _Tp& __x)
      |     ^~~~~~~~
/usr/include/c++/12/ostream:754:5: note:   template argument deduction/substitution failed:
/usr/include/c++/12/ostream: In substitution of ‘template<class _Ostream, class _Tp> _Ostream&& std::operator<<(_Ostream&&, const _Tp&) [with _Ostream = std::basic_ostream<char>&; _Tp = std::basic_ostream<char>]’:
ch01_exrc_1p8.cpp:6:10:   required from here
/usr/include/c++/12/ostream:754:5: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
Compilation failed.
```

## ch01_exrc_1p14

`while` loop: when we do not know how many iterations we need to go through.

`for` loop: when we precisely know how many iterations we need to go through.

## ch01_exrc_1p15_01

```console
$ ./perform.sh 1
Compiling 'ch01_exrc_1p15_01.cpp' using g++ with C++11 standard...
g++ -std=c++11 -Wall ch01_exrc_1p15_01.cpp -o a.out
ch01_exrc_1p15_01.cpp:4:5: error: cannot declare ‘::main’ to be a global variable
    4 | int main ( {
      |     ^~~~
ch01_exrc_1p15_01.cpp:6:48: error: found ‘:’ in nested-name-specifier, expected ‘::’
    6 |     std::cout << "Read each file." << std::endl:
      |                                                ^
      |                                                ::
ch01_exrc_1p15_01.cpp:6:44: error: ‘std::endl’ is not a class, namespace, or enumeration
    6 |     std::cout << "Read each file." << std::endl:
      |                                            ^~~~
ch01_exrc_1p15_01.cpp:8:18: error: ‘Update’ was not declared in this scope
    8 |     std::cout << Update master. << std::endl;
      |                  ^~~~~~
ch01_exrc_1p15_01.cpp:8:25: error: expected ‘}’ before ‘master’
    8 |     std::cout << Update master. << std::endl;
      |                         ^~~~~~
ch01_exrc_1p15_01.cpp:4:12: note: to match this ‘{’
    4 | int main ( {
      |            ^
ch01_exrc_1p15_01.cpp:8:24: error: expected ‘)’ before ‘master’
    8 |     std::cout << Update master. << std::endl;
      |                        ^~~~~~~
      |                        )
ch01_exrc_1p15_01.cpp:4:10: note: to match this ‘(’
    4 | int main ( {
      |          ^
ch01_exrc_1p15_01.cpp:10:10: error: ‘cout’ in namespace ‘std’ does not name a type
   10 |     std::cout << "Write new master." std::endl;
      |          ^~~~
In file included from ch01_exrc_1p15_01.cpp:1:
/usr/include/c++/12/iostream:61:18: note: ‘std::cout’ declared here
   61 |   extern ostream cout;          /// Linked to standard output
      |                  ^~~~
ch01_exrc_1p15_01.cpp:12:5: error: expected unqualified-id before ‘return’
   12 |     return 0
      |     ^~~~~~
ch01_exrc_1p15_01.cpp:13:1: error: expected declaration before ‘}’ token
   13 | }
      | ^
Compilation failed.
```

## ch01_exrc_1p15_02

```console
$ ./perform.sh 1
Compiling 'ch01_exrc_1p15_02.cpp' using g++ with C++11 standard...
g++ -std=c++11 -Wall ch01_exrc_1p15_02.cpp -o a.out
ch01_exrc_1p15_02.cpp: In function ‘int main()’:
ch01_exrc_1p15_02.cpp:6:17: error: ‘v’ was not declared in this scope; did you mean ‘v2’?
    6 |     std::cin >> v >> v2; // error: uses "v" not "v1"
      |                 ^
      |                 v2
ch01_exrc_1p15_02.cpp:8:5: error: ‘cout’ was not declared in this scope; did you mean ‘std::cout’?
    8 |     cout << v1 + v2 << std::endl;
      |     ^~~~
      |     std::cout
In file included from ch01_exrc_1p15_02.cpp:1:
/usr/include/c++/12/iostream:61:18: note: ‘std::cout’ declared here
   61 |   extern ostream cout;          /// Linked to standard output
      |                  ^~~~
Compilation failed.
```

## ch01_exrc_1p17

The program will continue to receive the inputs forever and will show the count when end-of-line character is entered.

## ch01_exrc_1p18

ran ch01_exmp_1p4p4_01

- The program will continue to receive the inputs forever and will show the count when end-of-line character is entered.

```console
Executing './a.out'...
42
42
42
42
42
42
42
42
42
42 occurs 9 times

--------------------------
Last execution status: 0
```

- We get print saying the number occured once, for every number we enter.

```console
Executing './a.out'...
1
2
1 occurs 1 times
3
2 occurs 1 times
4 
3 occurs 1 times
5
4 occurs 1 times
6
5 occurs 1 times
7
6 occurs 1 times
89
7 occurs 1 times
9
89 occurs 1 times
9 occurs 1 times

--------------------------
Last execution status: 0
```