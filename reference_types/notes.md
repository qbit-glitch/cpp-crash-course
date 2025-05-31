# Chapter 3. Reference Types

## Pointers & Addressing Variables
- The variation in memory address space is  due to `Space Layout Radomization`, which is a security feature that scrambles the base address of important memory regions to hamper exploitation.

<details>
<summary> Address Space Layout Randomization </summary>
“Why does address space layout randomization hamper exploitation? When a hacker finds an exploitable condition in a program, they can sometimes cram a malicious payload into user-provided input. One of the first security features designed to prevent a hacker from getting this malicious payload to execute is to make all data sections non-executable. If the computer attempts to execute data as code, then the theory is that it knows something’s amiss and should terminate the program with an exception.

Some exceedingly clever hackers figured out how to repurpose executable code instructions in totally unforeseen ways by carefully crafting exploits containing so-called return-oriented programs. These exploits could arrange to invoke the relevant system APIs to mark their payload executable, hence defeating the non-executable-memory mitigation.

Address space layout randomization combats return-oriented programming by randomizing memory addresses, making it difficult to repurpose existing code because the attacker doesn’t know where it resides in memory.”

</details>

## Dereferencing Pointers

- “The dereference operator (*) is a unary operator that accesses the object to which a pointer refers. This is the inverse operation of the address-of operator. Given an address, you can obtain the object residing there”

## Member of Pointer Operator

- The member-of-pointer operator or an arrow operator (->) performs two simultaneous operations : 
    - It dereferences a pointer.
    - It accesses a member of the pointed-to object.


## Pointers and Arrays

- “Pointers share several characteristics with arrays. Pointers encode object location. Arrays encode the location and length of contiguous objects.
At the slightest provocation, an array will decay into a pointer. A decayed array loses length information and converts to a pointer to the array’s first element”

### Handling Decay
- We shall pass arrays with 2 arguments:
    - A pointer to the first array element
    - the array's length

### Pointer Arithmetic
- “To obtain the address of the nth element of an array, you have two options. First, you can take the direct approach of obtaining the nth element with square brackets ([]) and then use the address-of (&) operator.”
```cpp
College* third_college_ptr = &oxford[2];
```

- “Pointer arithmetic, the set of rules for addition and subtraction on pointers, provides an alternate approach. When you add or subtract integers to pointers, the compiler figures out the correct byte offset using the size of the pointed-to type.”
```cpp
College* third_college_ptr = oxford + 2;
```

## Pointers are Dangerous

### Buffer Overflows

- “For arrays and pointers, you can access arbitrary array elements with the bracket operator ([]) or with pointer arithmetic. These are very powerful tools for low-level programming because you can interact with memory more or less without abstraction.”
- “By accessing the element past the storage allotted to lower. No bounds checking occurs; this code compiles without warning.”

### *void* Pointers and *std::byte* Pointers

- “Sometimes the pointed-to type is irrelevant. In such situations, you use the void pointer void*. The void pointers have important restrictions, the principal of which is that you cannot dereference a void*. Because the pointed-to type has been erased, dereferencing makes no sense (recall that the set of values for void objects is empty). For similar reasons, C++ forbids void pointer arithmetic.”

- “Other times, you want to interact with raw memory at the byte level. Examples include low-level operations like copying raw data between files and memory, encryption, and compression. You cannot use a void pointer for such purposes because bit-wise and arithmetic operations are disabled. In such situations, you can use a std::byte pointer.”

### *nullptr* and Boolean Expressions:

- “Pointers can have a special literal value, nullptr. Generally, a pointer that equals nullptr doesn’t point to anything. You could use nullptr to indicate, for example, that there’s no more memory left to allocate or that some error occurred.
- Pointers have an implicit conversion to bool. Any value that is not nullptr converts implicitly to true, whereas nullptr converts implicitly to false. This is useful when a function returning a pointer ran successfully. A common idiom is that such a function returns nullptr in the case of failure. The canonical example is memory allocation.”

## References

- “References are safer, more convenient versions of pointers. You declare references with the & declarator appended to the type name. References cannot be assigned to null (easily), and they cannot be reseated (or reassigned). These characteristics eliminate some bugs endemic to pointers.”

- 