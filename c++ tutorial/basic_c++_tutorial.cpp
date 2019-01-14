/*
-- C++ tutorial --

    My attempt at writing down a bunch of useful things to know about C++ in one place for those 
    needed to learn C++. Meant as a guide/reference for people familiar with programming, though 
    I'll try to make it as approachable as possible.

    Charles Giessen
*/

/*  
    "Within C++, there is a much smaller and cleaner language struggling to get out"
        -Bjarne Stroustrup, Creator of C++ 
*/

//////////////////
// Introduction //
//////////////////

/*
    C++ is a very large language, large enough that even the experts can't claim anywhere near full knowledge.
    Making matters worse, there are currently 4 major versions. C++98, C++11, C++14, and C++17. Fortunately, 
    each version is backwards compatible, so using the lastest version possible is prefereable.

    It is one of the few languages that is standardized by International Organization for Standardization (ISO).
    As such, no one company controls the language. If one wants to change the language, it has to go through the 
    standards commitee. If you don't like something, write a paper and send it in, they are always looking for
    fresh ideas and people who want to better the tools they work in.

    The best way to approach it is in piece-meal. Lots of features are only useful in specific cases, and can
    be ignored in the common case. Many codebases use only a subset of features. My advise is to not try to use 
    features just because they look appealing. Rather try to use them if they solve a problem you are having. 
    Nothing is worse for bugs and maintainability than a solution looking for a problem.

    Beyond this document, I believe there are 3 major sources of learning material. First is books. There are loads
    of excellent published materials for all levels. Second is conference videos, freely available online. Thousands
    of hours of quality presentations and discussions from experts in every domain. Lastly is the body of blogs, 
    articles, and online forums (including stack overflow) that can fill in the gaps from the other two.  
*/

/*
    C++ is a compiled, static, strongly-typed language.

    Compiled is because C++ code turns into executable binary directly. Much of the speed of the language stems from
    that fact. 

    Static means that constructs don't change during run time. Dynamic features are explicitely opt-in. Size and location
    of functions and variables are constant. This imposes some restrictions, but enables great optomizations.

    Strongly-typed is touted as a bug prevention and program correctness guarantee. Turn runtime errors into compile
    errors. If there is one reason people use C++ over C, it is because the type system helps developers write fewer bugs.
*/

/*
    If you ask 100 developers the same question about C++, you will get 100 different answers.

    -- My personal favorite features of C++ -- 
    * Deterministic object life time. You can know when and where things are created and destroyed
    * High performance & High abstraction. Have your cake and eat it too
    * Hugh number of platforms it works on.  
    * Not controlled by the whims of one company.
    * 3 major compilers (gcc, clang, & msvc). No one source of truth, and multiple competing implementations
    * Robust Standard library
    * Language features that make custom types as usable as fundamental types. 
    * I can see straight to binary. No unaproachable black box. BTW Compiler Explorer is awesome https://godbolt.org/
    
    -- Things I don't like --
    * There are many dark corners. Nearly fifty years of design decision will do that to a language.
    * Package management and build systems are definite weak points.
    * C++ can be slow to compile. The standard's committee is working on it, but its slow progress
    * Tooling is both world class and abysmal at times. 
    * If C is a gun that you can shoot your foot with, C++ is a shotgun to blow your head off
    
*/

///////////
// Types //
///////////

/* 
    -- Fundamental Types --   
    There are a small number of built-in types. 
    Boolean, Integers, floating point numbers, characters, and a few odd bits.

    Note, none of these type have a defined default values. Their value is undefined unless specified.

    sizeof(TYPE) can be used to query the size of a type in bytes.

    Since C++ was created before 64 bit was the norm, what the standard mandates as a minimum size
    and what the common sizes are differ a bit.  
*/

//  Boolean
bool isBoolean;

//  Integers
int intA;      //commonly 32 bit
long int intB; //commonly 64 bit

//  Floating points
float floatA;   //commonly 32 bit
double doubleA; //commonly 64 bit

//  Integral types can be declared unsigned.
unsigned int intB;
//  In my opinion, unsigned types are only useful in a handful of scenarioes, so it isn't necessary
//  to be very familiar with them.

//  Character
char character; // essentially an 8 bit integer
//  char* is often used as a handle to a byte array, which means that not all uses of char are for text/strings

// C-Style Arrays
char arr[32]; // a char array of length 32;
/*
    C-Style arrays are their own special bag of syntactic fun. 
    It turns out that they are often pointers in disguise. They look and act like a pointer, but
    don't always have the same semantics.

    They are often superceeded by other features that often are a better fit. As such, I rarely use them.
    std::array is the idiomatic replacement for them. It has a very similar API as to other standard containers, 
    which makes it easier to remember how to use and manipulate.   
*/

/*
    -- Void --
    void, while fundamental, is an incomplete type. An object can't be of type void, nor can you reference
    an void object. But you can use it as a return type and have a pointer to void (void*).
*/

///////////////
// Functions //
///////////////

//  Example
int ExampleFunction(int argument)
{
    /* code goes here */
    return 0;
}

//can overload functions with different signatures (arugments)
void FunctionWithOverloads()
{
}
void FunctionWithOverloads(float different_arugment)
{
}

//  Function declarations contain only the name, arguments and return type. AKA a forward declaration
void FunctionDeclaration();

//  Function definitions have all that plus the curly braces
void FunctionDefinition()
{ /*fancy I know right?*/
}

/*
    The reason this is important is because C++ inherits from C both its single pass nature
    and its ONE-DEFINITION-RULE (ODR).
    
    Single pass means that when compiling, code can't use functions that haven't been
    declared yet. I.E you must declare all functions before using them. This is why main
    appears at the end of code rather than the beginning. 

    ONE-DEFINITION-RULE (ODR) states that there can only ever be one definition for a function
    (or most things actually). A declaration can appear any number of times. But its corresponding
    definition can only happen one time and one only time
*/

//  By default, C++ uses pass-by-copy, so arugments are copied when calling functions
//  changes made to the arguments inside the function are local to the function
//  there is a way to get around this, but that a later topic
void FunctionWithLocalVariables(int argument)
{
    //local variable with default value of 5
    int numberA = 5; 

    //a local variable with no initialization
    int numberB; // its value is undefined! don't do this kids
}

void CallAFunction()
{
    FunctionWithOverloads(); //no args

    int number = ExampleFunction(5); //with 1 integer arugment that returns an integer
}

///////////
// Enums //
///////////

//  a type declaration with a specific range of values. Often used with switch statements
//  They are usually just an int internally, so they can't store complex values

enum COLOR
{
    RED,
    BLUE = 20, //can have a specfic integer value rather than automatic assignment
    GREEN
};

//  an enum can be used like a type (for a variable) or as a value (assign to a variable or a case label).
void enum_example()
{
    COLOR col = RED;
}

//  Enums in C++ come from C, which lacks a lot of type safety. One instance of this behaviour is
//  that enum's are implicitely treated as integers, which can have suprising results. There is
//  a way to avoid this, and that is the enum class.

enum class Color
{
    red,
    blue,
    green
};

//  An enum class requires qualification before youse, ie the double colon.
void enum_class_example()
{
    Color col = Color::red;
    col = Color::green;
}

//////////////////
// Basic Syntax //
//////////////////

void basic_syntax_example()
{
    bool condition = true;

    // basic control flow
    if (condition)
    {
        /* do stuff */
    }
    else if (condition && /*and*/ condition || /*or*/ condition)
    {
        /* do stuff */
    }
    else
    {
        /* do stuff */
    }

    // for loop
    for (int i = 0; i < 100; i++)
    {
        /* do stuff */
    }

    // for-each loop
    std::vector<int> array = {1, 2, 3, 4, 5}; //standard library type for dynamic arrays
    for (int &element : array)
    {
        /* do stuff */
    }
    //  Note: remember to use the ampersand. Without it, the elements are copied, so if you were to change anything,
    //  the values wouldn't be recorded.

    // while loop
    int counter = 0;
    while (counter < 100)
    {
        /* do stuff */
        counter++;
    }

    // Switch statement using an enum
    Color col = Color::red;
    switch (col)
    {
    case (Color::red): /* do stuff */
        break;
    case (Color::blue): /* do stuff */
        break;
    case (Color::green): /* do stuff */
        break;
    default: /* default case */
    }
    //  Note: switch statements fallthrough, so don't forget to add the break;
}

/////////////////////////
// Preprocessor Macros //
/////////////////////////

//  Macros in C++ are textual, meaning they operate on raw text, not contextual language constructs.

//  The following example will replace all instances of the text "NUMBER_OF_EXAMPLES" with the text "25"
#define NUMBER_OF_EXAMPLES 25

//  Macros were developed in a time when the language (C) wasn't nearly as powerful as today's C++. Today,
//  C++ has many features that supercede the cases where heavy macro use made sense. However there are
//  still several key functions that macros excel in.

//  First and foremost, they are the only (current) way to use libraries in C++.
//  EX:
#include <iostream>

//  Nextly, they are great for introducing conditional compilation. Imagine you only want to log something
//  when using a debug build.

void example_debug_mode()
{
    /* do stuff */
#if DEBUG_MODE
    log();
#endif
}

//  This also applies to platform specific functionality. Using platform specific defines, it is very easy
//  to have platform specific function calls.

#if _WIN32
// Windows API calls here
#else
// Linux API calls here
#endif

//  Another very common case is configuration options. These can be defined outside of your code, in a build
//  script or other external variables

#ifndef USE_CONFIG_OPTION_X
// default to enable
#define USE_CONFIG_OPTION_X 1
#endif

//  Asserting stuff still requires macros, though C++20 includes several facilities that reduce the need.
#include <cassert>
void example_asser()
{
    assert(2 + 2 == 4);
}

//  Beyond these use cases, I don't advocate for using macros. There are cases where macros are the right choice,
//  but that is far and few between

//////////////////
// Header Files //
//////////////////

//  Header files are how libraries are included into your code. Header files use the .h or .hpp extension.
//  They almost always come in pairs with a .cpp file.

//EX.
#include <string>    //system libraries
#include "Vector3.h" //your libraries

/*
    These files contain only the declarations of all variables and functions, so they create a "header" that
    describes the interface for the corresponding C++ file. 

    When compiling, header files simply copy and paste the header files contents into the corresponding file that includes them.
    A consequence of this is that every file that includes a header file has to compile their own copy of the code. This is a big
    reason for slow compile times in C++. Try to keep your header files as lean as possible.
*/

//  Header files can also use directory structures which helps organize your code.
#include "src/util/ExampleLibrary.h"

///////////////////////
// Compilation Model //
///////////////////////

/*
    C++ compilation is an involved process which takes several steps. While the minor details of each
    step aren't important to have memorized, a general idea of the process is essential to understanding
    why C++ works in certain ways. Note: this also applies to C code.

    Firstly a compiler works on a per C++ file level. Each of these are called translation units. A translation 
    unit is processed c++ code, which is when all macros are evaluated. The major takeaway here is that all the of the 
    included files are expanded in place, so the resulting translation unit might be much larger than the
    original C++ file. After macro evalutaion, the code is compiled.

    A compilers primary output is an object file, contrary to expectation. An object file contains assembly code
    but lacks the hooking up of functions to their final addresses among a few other things. On Linux, object files
    use the (.o) extenstion while on windows they use the (.obj) extension.

    These object files are the input for the linker, a program that is responsible for creating runnable 
    executables and shared libraries (.so) on linux or dynamic link libraries (.dll) on windows.

    Usually, the compiler and linker are orchestrated together so you don't have to manually call each.
    An example of that is invoking the gcc will automatically call the linker.
*/

////////////////
// References //
////////////////

/*
    The most common way to access data without copying it around is to use a reference.
    References are declared by having a type with an & following it. IE type& name
    They have a few special properties and requirements for use.

    The first property is that they cannot be null, so you can't create a reference to a null
    object. This is achieved by requiring references to always be initialized before use.
    That means you can't create a reference without an object to reference.
    The code int& ref_value; doesn't have an object to reference, so it won't compile. The exception
    to this rule is in function parameters and class definitions. A function parameter will be filled in
    when the function is called so the requirement is fufilled then and a class has special syntax to make
    sure that its references are valid (more in the section on classes, namely constructors)

    The second property is that they cannot be re-assigned. Once an object is referenced, that object and that
    object only are referenced. This may sound like a unecessary restriction, but its actually helps make sure that
    the object you initially referenced doesn't slip out from under you. If you need a reassignable reference,
    then I would advise you to use something different as there is no easy & simple way to achieve that behavior.

    Internally, a reference is just a memory address. Nothing more, nothing less. 32-bit machines use 4 bytes for each
    address and a 64-bit machine uses 8 bytes. Therefore they are cheap to copy and use, compared to the large objects
    they could be referencing. Therefore, if the size of the object is small, <16 bytes, it is rarely cheaper to use
    a reference than the underlying small object.

    References are great, but they do have a glaring issue. What happens if the underlying object that is
    being referenced gets destroyed? Well, now it is a dangling reference. This is a fatal bug,
    as using the reference means using data that no longer represents that object. Main way to avoid this is
    to use references going down (passing into functions) but not going up (return types).
*/

//  Basic example
void example_reference()
{
    int value = 0;
    int &ref_value = value; //ref_value references value
}

void example_reference_in_function(int &value, float &other_value)
{
    int local_value = value; //automatic usage
}

//////////////
// Pointers //
//////////////

//  Ah pointers, the bane of many a cs-students existance. I am here to tell you that in C++, there are many
//  ways to get around them. But I am also the bearer of bad news, namely that you will need to know about them
//  and how to use them.

//  The syntax is to have a type with an ampersand following it.
int *name_one;
//  or
int *name_two;

//  Pointers are like references, save for two main properties. They CAN be null (not point to anything) and CAN
//  be reassinged. This makes it very flexible and likewise very easy to misuse. Before using a pointer, you pretty
//  much always have to makes sure that it's value isn't null, as dereferencing a null pointer will crash your program.

//  There is also a keyword you should use when checking if a pointer is null, which is nullptr.

void example_pointer()
{

    int *ptr_int; //pointer to an int that is null
    if (ptr_int != nullptr)
    { //checks if it is null
        int local_int = *ptr_int;
    }
}

//  The other property pointers have over references is pointer arithmatic, which is the ability to treat them like numbers
//  This is generally what throws people for a loop, as in C it is pretty much necessary to get anything significant done.
//  In C++, there are enough features that make it mostly unecessary, as such I won't be covering it here.

/////////////////////////
// Classes and Structs //
/////////////////////////

/*  
    Classes and structs are a cornerstone of organiziging data and code in C++. They are the most common
    way of creating custom types with specific behavior. 

    Some languages have many different units of composition. Classes, interfaces, abstract classes, structs, etc.
    C++ elects to combine all of the different permutations into just one construct but with many different options. 

    Therefore Classes and Structs are the same underlying thing, but with the only difference being whether things are
    public or private by default. Classes are private by default, while structs are public by default.

    So if you are ever confused which is which, classes are like school classes which keep to themselves, while structs
    are like construction structs that expose everything to the world.  
*/

class example_class
{
    //Everything here will be private by default
    //put all variables & functions here
    void member_funtions();
    int member_variables;
}; //don't forget to close it with a semicolon!

struct example_struct
{
    //Everything here has public access by default
};

/*
    To change the default, we use access modifiers. These are labels that alter all subsequent variables and functions.
    This is in constrast to many languages where the modifier has to be applied to each variable or function
*/

class example_class_accessors
{

  public: //visible to everyone
    int public_variable;
    void public_function();

  private: //only visible to itself
    int private_variable;
    void private_function();

  protected: //visible to classes inheriting from it
    int protected_variable;
};

/*
    Classes inherite from other classes, which is useful to provide a base set of operations to child classes.

    Unlike other Object Oriented Languages, C++ has no default base class. This give developers much more control
    over the behavior of their classes by not mandating a default set of operations. 
*/

class example_inherited_class : example_class
{
    // can access public and proctected elements from the base class
};

/*
    Runtime dynamic behavior is achieved through the use of the virtual modifier. It states that the functions behavior is 
    overridable by child classes' functions.    
*/

class example_base
{
  public:
    virtual void foo(); //can be overriden in a child class
    virtual void bar();
    void baz();
};

class example_child : example_base
{
  public:
    // override tells the compiler that this function overrides a base class
    void bar() override;
    // final states that this function can't be overriden further. Useful to enforce constraints
    virtual void baz() final;
};

/*
    The V-Table is an autogenerated table of function pointers used to facilitate the dynamic dispatch behavior
    of virtual function calls. This is automatically generated by the compiler for you and and generally one table exists
    for every class type (but not each instance of a class). 
    
    It is important to know about as it incurs a performance hit everytime a function call is dispatched. Instead of 
    immediately going to the function, the code first has to figure out which function to call by looking it up in the V-Table.

    Therefore, most people try to reduce the amount of virtual functions used. In my opinion, they are a useful tool for solving
    some dynamic behavior problems, but its best to not use them inside hot loops or other performance sensitive areas.

*/

/*
    As previously mentioned, the differene between classes and structs is minimal. Therefore, it is mostly a style choice as for 
    which to use.

    My preference is to use structs when you need a bag of data. Like a bunch of settings or data packets.
    Classes are "smart" meaning they have complex setup, usage, and teardown.
*/
struct POD
{ //POD stands for Piece Of Data
    int x;
    float y;
};

/*
    Construction is the way to establish invariants (read, setup the class). Complex classes 
    will have complex construction but that shouldn't surprise anyone 
    Descruction is the way to clean up after oneself. This is heavily related to memory management,
    which is discussed later
*/
class ConstructionExample
{
    int a;
    float b;

  public:
    //default constructor. If a class has no constructors in it all, the compiler will
    ConstructionExample();

    //Destructor. Cannot have any arguments
    ~ConstructionExample();

    // explicit marks the constructor so that no conversions will take place for the arguments.
    // It is considered good practice to
    explicit ConstructionExample(int val);

    // Initializer lists are the way to take constructor arguments and assign them to member variables
    ConstructionExample(int a, float b) : a(a), b(b);
};

//////////
// Auto //
//////////

///////////////////////
// Const Correctness //
///////////////////////

/*
    One thing that C++ got wrong is to have things mutable by default. How nice code would be if everything
    was constant by default. But that ship sailed back in the 60's so there's no use crying over it.
    C++ has the modifier const, which as you would expect makes things constant.
*/

//  Can't change the value of val1
const int val1 = 1;

//  modifiers in C++ aren't required to be on a specific side of the variable identifier.
int const val2 = 2;
/*
    The rule is that const applies to the thing to its left, and if there isn't anything, it applies to its right.
    I prefer const being on the right (East Const for life!) but it is just a matter of style.

    More than just variables can be const. Pointers, references, classes, structs, parameters, functions, pretty
    much everything can be made const.

    Const Correctness is the principle of appliying const to everything except for things that need to be mutable.
    This has two benefits, performance and bug-catching. Compilers can do some very fancy optomizations if it knows
    something's value doesn't change, and it will also catch cases of bad use of some code, simply because it is
    mutating something in a const context.
*/

///////////////////////
// Memory Management //
///////////////////////

/*
    Okay kiddos, this is the elephant in the room. C++ is known as being a difficult language to learn and use, and that is 
    50% from memory management. And I'm here to tell you that C++ offers many facilities which automate and make it 
    relatively painless. Is it as easy as using a Garbage Collecttor? No, but in my opinion that is a feature, not a problem.

    Before discussing different strategies, we first have to cover what kinds of memory there are and where it is is located.
    There are 3 maing segments of memory in C++. The data/code, the stack, and the heap. The data/code segment is where all
    static data and code sits. Global variables, static strings (stuff inside ""'s) and other fixed sized data. The stack is 
    the call stack, where your program executes. Local variables to functions will reside here. The stack's memory begins right 
    after the end of the data/code segment. It is managed by the language itself, so its all automatically handeld for you.
    Lastly, the heap sits at the other side of the memory space and grows down. All dynamic allocations happens from here, and 
    is managed by you, the programmer. When people talk about "manual memory management", the heap is the area they are referring
    to.
 */

//  Global variables are declared outside of functions and classes. I advise to use them sparingly, if ever at all.
int global_var = 15;

//  Static variables in functions and structs/classes act like other languages, with only one instance per running program.
int example_static_counter()
{
    static int counter = 0; //this only is initialized to zero once.
    return counter++;       //monotomically increasing counter
}
//  The difference between static and globals is when they are initialized and what scope they are available in. Global, like
//  the name implies, is visiable to all, while static is only visible in its enclosing scope.

//  The use of static outside of functions/classes have different semantics but are still located in the same memory segment.

/*
    The first type of management to talk about is local/stack memory. This is the most simple type and is done automatically
    for you. Every time you enter a function (including main), a section of memory is allocated from the stack. This stack 
    is the call-stack, or the data structure that manages which function is currently being called, which one to return to once
    once the function terminates, parameters, and variables that are local to the function.

    All of the values are allocated on the call stack, and will automatically dissapear when the function returns. You don't
    have to do anything, it is all handled by the compiler and operating system. If possible, prefer using this as much as possible
*/
void function(int paramA, int paramB)
{
    float localA;
    int localB;
    bool localC;
}

//  Not all things can be stored on the stack though. Persistant data structures are a prime example. Fortunately, a standard
//  library container will handle all sorts of situations and can be treated like a local variable. This is thanks in part
//  to a design principle call RAII, or Resource Aquisition Is Initialization

// unique_ptr & containers (vectors & strings are prime examples)

// shared_ptr and other object management scheme
// shared_ptr for multiple owners
//  arena/pool manager which controls objects but lets others access data.


///////////////////////
// Standard Libarary //
///////////////////////

/*
    The C++ Standard Library (sometimes called the STL) is filled with lots of goodies. I suggest you use 
    it to the fullest. The most useful parts for most code will be the Containers and Algorithms.

    Note: It is good practice to preface using the standard library with `std::`
    while its tempting to use 'using namespace std' so you don't have to type std:: all the time,
    name collision is no joke and your compiler errors will be very cryptic
*/

//    --Containers--

//  vector - a dynamically allocated array -
//  https://en.cppreference.com/w/cpp/container/vector
#include <vector>
void example_vector()
{
    std::vector<int> vector_of_ints;
    vector_of_ints.push_back(5); //add a new value to the end
    vector_of_ints.at(0) = 3;    //change an elements value
    vector_of_ints.size();       // is equal to one
}

//  array - statically sized array
//  https://en.cppreference.com/w/cpp/container/array
#include <array>
void example_array()
{
    std::array<int, 3> array_of_ints;
    array_of_ints.at(3) = 21;
    //array's size must be known at compile time, ie can't be a variable
}

//  string - a string. yay
//  https://en.cppreference.com/w/cpp/string/basic_string
#include <string>
void example_string()
{
    std::string example = "Woot woot";
    std::cout << example << " in the boot!\n";
}

//  unordered_map - hash table for all your key-value pair needs
//  faster than std::map (but doesn't store its data in sorted ordered)
//  https://en.cppreference.com/w/cpp/container/unordered_map
#include <unordered_map>
void example_unordered_map()
{
    std::unordered_map<int, std::string> example;
    example[2] = "a value"; //WARNING - this will put a key into the container if none is found
    example.at(5);          // gets the value at a location 5
    example.insert({2, "another value"});
}

//  Other useful containers

//  unordered_set - no duplicate elements -  faster than regular set
//  map - like unordered_map but its elements are always sorted (by key)
//  set - like unordered_set but its elements are always sorted
//  stack - a LIFO data structure
//  queue - a FIFO data structure
//  deque - a double ended queue

/*
    -- Iterators --

    All the standard containers use iterators throughout. An iterator is simply an abstraction on how to traverse
    a container. Iterators have both knowledge of what their are looking at (pointing) and how to advance through
    the container. So an iterator to a linked list would know which node its pointing at, and how to get to the next
    node in the list. 

    Iterators are very powerful when combined with the algorithms library. The algorithms work on any container that 
    satisfy its conditions, so you can write custom containers and have them work with over 100+ algorithms.
    This is a very powerful feature, as it decouples the container and algorithms in a modular and extensible fasion.  

    Iterators can be obtained directly from the container. The std::begin(container) and std::end(container) functions
    return an interator to the respective position in the container. They also are often used as return types from 
    specific functions. Some functions return iterators, as a way to easily traverse the container
*/
void example_iterator_vector_erase_only_even()
{
    std::vector<int> c = {1, 2, 3, 4, 5};
    for (auto it = std::begin(c); it != std::end(c);)
    {
        if (*it % 2 == 0)
            it = c.erase(it);
        else
            ++it;
    }
}

/*
    A very common usage with iterators is defining a range of elements, using a start and end iterator, or a start
    iterator and element count. Vector's erase function has an overload with a start and end iterator argument
    making it easy to erase a contiguous range of elements

    Two things that make iterators not always perfect. 
    Iterator Invalidation is when you modify the underlying container in a way that makes the iterators point to bad 
    addresses. Simplest case is an iterator pointing to the last element of a vector, then you erase the some elements
    of that vector. The iterator now points to elements past the end, which will cause bugs. Best way to avoid this 
    is tightly keeping the container and iterators in sync. Another way would to not store iterators long term.

    The other thing is more preference, but current C++ (C++17 and before) requires the use of c.begin() & c.end() 
    for expressing the entire container. This changes with C++20, which adds the ranges library, a new library that
    is designed to make interacting with algorithms much simpler. Instead of std::sort(container.begin(), container.end()),
    the much prettier syntax of std::sort(container) is viable
*/

/*
    --Algorithms--

    There are lots (over 100+) algorithms available in the standar. Fortunately, you don't need to know all of them to
    make the most of it. Find & sort are bread and butter types, but each has several useful variations.
    A full list can be found here https://en.cppreference.com/w/cpp/algorithm
*/

//  find - I think you can guess what this does

#include <algorithm>
void example_find()
{
    std::vector<int> v{0, 1, 2, 3, 4};
    int n1 = 3;

    auto result1 = std::find(std::begin(v), std::end(v), n1);
    if (result1 != std::end(v))
    {
        std::cout << "v contains: " << n1 << '\n';
    }
    else
    {
        std::cout << "v does not contain: " << n1 << '\n';
    }
}

//  sort - takes a range from a container and sorts it

void example_sort()
{
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    std::sort(s.begin(), s.end());

    //  sort also takes in a custom comparator
    std::sort(s.begin(), s.end(), std::greater<int>());

    //  and a lambda can be used as well - very nice for specialized sorting routines
    std::sort(s.begin(), s.end(),
              [](int a, int b) {
                  return a > b;
              });
    //  Lambdas are anonymous functions
}

/*
    --IOstream--

    The easiest way of handling input and output with the outside world. 
    Both from the consol and from files on the system.
*/

//    std::cout - default output
#include <iostream>
void example_cout()
{
    std::cout << "Hello world!\n";
}

//    std::cin - default input
#include <iostream>
void example_cin()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n; //n now holds the inputted number
}

//    fstream - loading & saving files, binary and text
#include <iostream>
#include <fstream>
#include <string>
void example_fstream()
{
    std::string filename = "test.bin";
    std::fstream s(filename, s.binary | s.trunc | s.in | s.out); //various flags for usage cases
    if (!s.is_open())
    {
        std::cout << "failed to open " << filename << '\n';
    }
    else
    {
        /* read binary data */
    }
} 

/*
    Other useful libraries

    thread - Threads, mutexes, semaphores & other multithreading goodies
        There be dragons. Threads are not childproofed and you can easily do strange things with powerful tools
    
    random - pseudorandom number generators that aren't crap (looking at you C's rand() )
        If you need good random numbers, this has what you need
    
    chrono - time and date facilities
        While some hate how cumbersome it is to use, this makes sure you can't muck it up. Time/date is notoriously
        easy to get wrong, so it was designed to be hard to use wrong.
    
    filesystem - C++17 and up - cross platform filesystem handling
    
    optional - handy type that wraps a value and boolean flag up together.
        helps with expressing intent
    
    variant - a typesafe union. Also can be as a replacement for traditional inheritance.

*/

////////////////////
// Move Semantics //
////////////////////
