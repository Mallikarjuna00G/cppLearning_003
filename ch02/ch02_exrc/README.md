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