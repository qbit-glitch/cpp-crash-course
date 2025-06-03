# 4. The Object Life Cycle

**Outcomes**: “You’ll learn about how the object life cycle dovetails with exceptions to handle error conditions and cleanup in a robust, safe, and elegant way. The chapter closes with a discussion of move and copy semantics that provides you with granular control over an object’s life cycle.”

## An Object's storage duration

- “An object is a region of storage that has a type and a value. When you declare a variable, you create an object. A variable is simply an object that has a name.”

### Allocation, Deallocation and Lifetime

- “each object passes through the following stages:

    - The object’s storage duration begins, and storage is allocated.
    - The object’s constructor is called.
    - The object’s lifetime begins.
    - You can use the object in your program.
    - The object’s lifetime ends.
    - The object’s destructor is called.
    - The object’s storage duration ends, and storage is deallocated.”

### Memory Management

- If you’ve been programming in an application language, chances are you’ve used an automatic memory manager, or a garbage collector. At runtime, programs create objects. Periodically, the garbage collector determines which objects are no longer required by the program and safely deallocates them. This approach frees the programmer from worrying about managing an object’s life cycle, but it incurs several costs, including runtime performance, and requires some powerful programming techniques like deterministic resource management.

- C++ takes a more efficient approach. The trade-off is that C++ programmers must have intimate knowledge of storage durations. It’s our job, not the garbage collector’s, to craft object lifetimes.

### Automatic Storage Duration

- “An automatic object is allocated at the beginning of an enclosing code block, and it’s deallocated at the end. The enclosing block is the automatic object’s scope. Automatic objects are said to have automatic storage duration. Note that function parameters are automatic, even though notationally they appear outside the function body.”

- “Because you cannot access these variables outside of function's scope, automatic variables are also called local variables.”


### Static Storage Duration

- “A static object is declared using the static or extern keyword. You declare static variables at the same level you declare functions—at global scope (or namespace scope). Static objects with global scope have static storage duration and are allocated when the program starts and deallocated when the program stops.”

- “When you use the static keyword, you specify internal linkage. Internal linkage means that a variable is inaccessible to other translation units. You can alternately specify external linkage, which makes a variable accessible to other translation units. For external linkage, you use the extern keyword instead of static”

- “a translation unit is what a preprocessor produces after acting on a single source file.”

- [static_storage_duration.cpp](./static_storage_duration.cpp)

### Local Static Variables

- “A local static variable is a special kind of static variable that is a local—rather than global—variable. Local static variables are declared at function scope, just like automatic variables. But their lifetimes begin upon the first invocation of the enclosing function and end when the program exits.”

- [local_static_variables.cpp](./local_static_variables.cpp)

- “This is an example of a programming pattern called encapsulation, which is the bundling of data with a function that operates on that data. It helps to protect against unintended modification.”


### Static Members

- “Static members are members of a class that aren’t associated with a particular instance of the class. Normal class members have lifetimes nested within the class’s lifetime, but static members have static storage duration.”

- “These members are essentially similar to static variables and functions declared at global scope; however, you must refer to them by the containing class’s name, using the scope resolution operator ::. In fact, you must initialize static members at global scope. You cannot initialize a static member within a containing class definition.”

- “Like other static variables, static members have only a single instance. All instances of a class with static members share the same member, so if you modify a static member, all class instances will observe the modification.”

- [static_members.cpp](./static_members.cpp)

- “You see the scope resolution operator in action where rat_things_power is initialized ➍ and where you invoke the static method power_up_rat_thing ➎.”

## Thread Local Storage Duration

- “One of the fundamental concepts in concurrent programs is the thread. Each program has one or more threads that can perform independent operations. The sequence of instructions that a thread executes is called its thread of execution”

- “Code that multiple threads can execute safely is called thread-safe code. Mutable global variables are the source of many thread safety issues. Sometimes, you can avoid these issues by giving each thread its own copy of a variable. You can do this by specifying that an object has thread storage duration.”

- “You can modify any variable with static storage duration to have thread-local storage duration by adding the thread_local keyword to the static or extern keyword. If only thread_local is specified, static is assumed. The variable’s linkage is unchanged”

- Modify the `local_static_variables.cpp` as : 
    ```cpp
    void power_up_rat_thing(int nuclear_isotopes){
        static thread_local int rat_things_power = 200;
        -- snip --
    }
    ```

## Dynamic Storage Duration

- “Objects with dynamic storage duration are allocated and deallocated on request. You have manual control over when a dynamic object’s life begins and when it ends. Dynamic objects are also called allocated objects for this reason.”

- “The primary way to allocate a dynamic object is with a new expression. A new expression begins with the new keyword followed by the desired type of the dynamic object. New expressions create objects of a given type and then return a pointer to the newly minted object.”

- “After allocating storage for the int, the dynamic object will be initialized as usual. After initialization completes, the dynamic object’s lifetime begins.You deallocate dynamic objects using the delete expression, which is composed of the delete keyword followed by a pointer to the dynamic object. Delete expressions always return void.”

- Initialization and deallocation of Dynamic Objects

    ```cpp
    int *my_int_ptr = new int;
    int *my_int_ptr2 = new int {42};

    delete my_int_ptr;
    ```

- “The value contained in memory where the deleted object resided is undefined, meaning the compiler can produce code that leaves anything there.”

- “You would have to implement a custom destructor to, for example, zero out some sensitive contents.”

NOTE : “Because the compiler doesn’t typically clean up memory after an object is deleted, a subtle and potentially serious type of bug called a use after free can occur. If you delete an object and accidentally reuse it, your program might appear to function correctly because the deallocated memory might still contain reasonable values. In some situations, the problems don’t manifest until the program has been in production for a long time—or until a security researcher finds a way to exploit the bug and discloses it!”

### Dynamic Arrays

- “Dynamic arrays are arrays with dynamic storage duration. You create dynamic arrays with array new expressions.”

- Syntax : 
    ```
    new MyType[n_elements]{ init-list }
    ```

- Example: 
    ```cpp
    int * my_int_array_ptr = new int[100];
    -- Do Something --
    delete[] my_int_array_ptr;
    ```

- “The number of elements ➊ doesn’t need to be constant: the size of the array can be determined at runtime, meaning the value between brackets ➊ could be a variable rather than a literal.”

- “To deallocate a dynamic array, use the array delete expression. Unlike the array new expression, the array delete expression doesn’t require a length”

### Memory Leaks

- “With privilege comes responsibility, so you must make sure that dynamic objects you allocate are also deallocated. Failure to do so causes memory leaks in which memory that is no longer needed by your program isn’t released. When you leak memory, you use up a resource in your environment that you’ll never reclaim. This can cause performance problems or worse.”

NOTE: “In practice, your program’s operating environment might clean up leaked resources for you. For example, if you’ve written user-mode code, modern operating systems will clean up the resources when the program exits. However, if you’ve written kernel code, those operating systems won’t clean up the resources. You’ll only reclaim them when the computer reboots.”

## Tracing the Object's Life Cycle

- [tracing_object_life_cycle.cpp](./tracing_object_life_cycle.cpp)


## Exceptions

- “Exceptions are types that communicate an error condition. When an error condition occurs, you throw an exception. After you throw an exception, it’s in flight. When an exception is in flight, the program stops normal execution and searches for an exception handler that can manage the in-flight exception. Objects that fall out of scope during this process are destroyed.”

- “In situations where there’s no good way to handle an error locally, such as in a constructor, you generally use exceptions. Exceptions play a crucial role in managing object life cycles in such circumstances.”

- “The other option for communicating error conditions is to return an error code as part of a function’s prototype. These two approaches are complementary. In situations where an error occurs that can be dealt with locally or that is expected to occur during the normal course of a program’s execution, you generally return an error code.”

### The *throw* keyword
