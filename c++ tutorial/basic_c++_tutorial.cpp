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
    standards committee. If you don't like something, write a paper and send it in, they are always looking for
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

    Static means that constructs don't change during run time. Dynamic features are explicitly opt-in. Size and location
    of functions and variables are constant. This imposes some restrictions, but enables great optimizations.

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
    * I can see straight to binary. No unapproachable black box. BTW Compiler Explorer is awesome https://godbolt.org/
    
    -- Things I don't like --
    * There are many dark corners. Nearly fifty years of design decision will do that to a language.
    * Package management and build systems are definite weak points.
    * C++ can be slow to compile. The standard's committee is working on it, but its slow progress
    * Tooling is both world class and abysmal at times. 
    * If C is a gun that you can shoot your foot with, C++ is a shotgun to blow your head off
*/

/*
    If you have any suggestions or comments, please dont hesitate to hit me up.

    Also, this guide is a starting point, so if you have questions, google is you best friend. 
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
//  In my opinion, unsigned types are only useful in a handful of scenario's, so it isn't necessary
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

//can overload functions with different signatures (arguments)
void FunctionWithOverloads()
{
}
void FunctionWithOverloads(float different_argument)
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

//  By default, C++ uses pass-by-copy, so arguments are copied when calling functions
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

    int number = ExampleFunction(5); //with 1 integer argument that returns an integer
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
//  that enum's are implicitly treated as integers, which can have suprising results. There is
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

    //    std::cout - default output
    #include <iostream>
    std::cout << "Hello world!\n";

    
    //    std::cin - default input
    #include <iostream> 
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n; //n now holds the inputted number
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
void example_assert()
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
    original C++ file. After macro evaluation, the code is compiled.

    A compilers primary output is an object file, contrary to expectation. An object file contains assembly code
    but lacks the hooking up of functions to their final addresses among a few other things. On Linux, object files
    use the (.o) extension while on windows they use the (.obj) extension.

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
    when the function is called so the requirement is fulfilled then and a class has special syntax to make
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

//  Pointers are like references, save for two main properties. They CAN be null (not point to anything) and CAN
//  be reassigned. This makes it very flexible and likewise very easy to misuse. Before using a pointer, you pretty
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

//  The other property pointers have over references is pointer arithmetic, which is the ability to treat them like numbers
//  This is generally what throws people for a loop, as in C it is pretty much necessary to get anything significant done.
//  In C++, there are enough features that make it mostly unecessary, as such I won't be covering it here.

/////////////////////////
// Classes and Structs //
/////////////////////////

/*  
    Classes and structs are a cornerstone of organizing data and code in C++. They are the most common
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
    Classes inherit from other classes, which is useful to provide a base set of operations to child classes.

    Unlike other Object Oriented Languages, C++ has no default base class. This give developers much more control
    over the behavior of their classes by not mandating a default set of operations. 
*/

class example_inherited_class : example_class
{
    // can access public and protected elements from the base class
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
    -- POD --

    As previously mentioned, the differene between classes and structs is minimal. Therefore, it is mostly a style choice as for 
    which to use.

    My preference is to use structs when you need a bag of data. Like a bunch of settings or data packets.
    Classes are "smart" meaning they have complex setup, usage, and teardown. 
*/

//POD stands for Piece Of Data
struct character_data
{ 
    int x = 0;
    int y = 0;
    float health = 100.0f;
    bool isOnGround = false;
    bool isPoisoned = false;   
    bool isDead = false;
};

/*
    -- Operator Overloading --

    C++ allows classes/structs to define custom operators on themselves. This allows natural syntax in user code. A prime example
    is overloading the == operator and != operator, which allows a custom comparator to be written easily.

    Almost all operators can be overloaded. An obvious use cases is on algebraic types, like complex or vectors. The notable exception
    is the dot operator, which is already defined to be member access (like obj.x). 
*/

class OpOverload {
    int data_member = 0; // for dummy purposes

    //is equal
    bool operator==(OpOverload const& other){
        return data_member == other.data_member;
    }
    
    // is not equal
    bool operator!=(OpOverload const& other){
        return data_member != other.data_member;
    }

    //assign equals
    OpOverload& operator+=(OpOverload const& other){
        data_member += other.data_member;
        return *this; //needed to get a reference to this
    }
    //addition - note that it returns a new object, not a reference.
    OpOverload operator+=(OpOverload const& other){
        OpOverload op; //new object
        data_member += other.data_member;
        return op; //needed to get a reference to this
    }
}

/*
    -- Constructors --

    Construction is the way to establish invariants (read, setup the class). Complex classes 
    will have complex construction but that shouldn't surprise anyone.
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

    /*
        If a constructor runs at the beginning of an objects life, the destructor runs at the end. This is necessary to do things like
        tear down after you are done with an object. Trivial objects will have trivial desctructors, as there is nothing to do. In general,
        if you need a destructor, you will know it. Otherwise it is fine to omit it.
        
    */
    virtual ~ConstructionExample(); // necessary for classes that have inheritance. The details are more complicated than I'd care to explain
    /*
        C++ has the concept of "special member functions" which are functions that can be automatically generated by the compiler.
        These functions all have the property of dealing with construction (and destruction). The most basic case is that if you
        declare a constructor with no parameters and use the = default syntax, the compiler will generate it for you.  
        The next most basic is the automatic generation of a destructor, even if it isn't written in the class. 
    */
    ConstructionExample() = default; //Ask the compiler to generate the function for you. Useful if its trivial

    ConstructionExample() = delete; //Tells the compiler to not generate the function and to disallow user defined constructors
    // Very useful for making sure the compiler doesn't do something silly. Usually its not the constructor/destructor where this is used.

    // explicit marks the constructor so that no conversions will take place for the arguments.
    // It is considered good practice to use explicit on all constructors
    explicit ConstructionExample(int val);

    // Initializer lists are the way to take constructor arguments and assign them to member variables
    ConstructionExample(int a, float b) : a(a), b(b);

    /*  
        C++ has the concept of Copy Construction & its twin, Copy-Assignment Construction. It is used when you are 
        constructing copies of objects. They also are in the "special member functions" and have all of those weird default/delete
        shenanigans.  
        
        A Copy Constructor must have the same name as the class, its return type needs to be a reference to the class, and it takes
        a const reference as an input parameter (and that is the thing which gets copied)  
    */
    //Return type        use same name as class  Take in a parameter that is the other class to copy
    ConstructionExample& ConstructionExample(    ConstructionExample const& other){
       //copy data elements here
    }

    //Return type        operator overload  input argument 
    ConstructionExample& operator=(         ConstructionExample const&) {
       return *this;// creates a reference to "this", which is the object the Copy-Assignment constructor is being called on.
    }
   
};


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

    Const Correctness is the principle of applying const to everything except for things that need to be mutable.
    This has two benefits, performance and bug-catching. Compilers can do some very fancy optimizations if it knows
    something's value doesn't change, and it will also catch cases of bad use of some code, simply because it is
    mutating something in a const context.
*/

///////////////////
// For-Each Loop //
///////////////////

/* 
    A handy construct to know about is the for-each loop. It is a specialized form of the for loop that iterates over 
    an entire collection with an easy to use syntax. 
*/

int example_for_each_loop(){

    std::vector<int> numbers = {1,4,3,7,4,8,9,3};
    int total = 0;
    for(int& num : numbers) {
        total += num;
    }
    return total;
}

/*
    Remember to use the & after the type, as otherwise it makes a copy instead of a reference, possibly costing performance and
    if you are modifying the value inside the for-each loop, the modification will be lost (cause it was a copy!)

    This is my goto method for iterating over a container. Especially when combined with the following item. (auto)
*/

//////////
// Auto //
//////////

/*
    C++ is a statically typed language, but that doesn't mean you have to type out all of the variables all of the time.
    The auto keyword exists to help you work faster without loosing the benefits of strong typing.

    The mechanism that allows this to work is type deduction, which is the ability of the compiler to deduce the type of the
    variable used.
*/
void example_auto(){
    auto varA = 0.0f; //type is deduced to be float
    auto varB = false; //type is bool
    auto varC = fun_call_with_return_type(); //type is whatever the function's return type is.

    std::vector<int> vec_of_stuff;
    for(auto& elem : vec_of_stuff){ //can use auto in for-each loop 
        //makes it super easy to traverse an entire container
    }
}

/*
    Auto is possible to be used in more places (like function return types and function parameters) but for the most part auto
    is most useful to save from typing out huge type declarations multiple times. 

    So I recommend using it for for-each loops and not having to type out variable declarations all the time. Using it too much may
    lead to code that is hard to reason about, as you have to chase down what the exact type is or hope your IDE tells you tye type.
*/


///////////////////////
// Memory Management //
///////////////////////

/*
    Okay kiddos, this is the elephant in the room. C++ is known as being a difficult language to learn and use, and that is 
    50% from memory management. And I'm here to tell you that C++ offers many facilities which automate and make it 
    relatively painless. Is it as easy as using a Garbage Collecttor? No, but in my opinion that is a feature, not a problem.

	The reason that C++ can have any claim 

    Before discussing different strategies, we first have to cover what kinds of memory there are and where it is is located.
    There are 3 main segments of memory in C++. The data/code, the stack, and the heap. The data/code segment is where all
    static data and code sits. Global variables, static strings (stuff inside ""'s) and other fixed sized data. The stack is 
    the call stack, where your program executes. Local variables to functions will reside here. The stack's memory begins right 
    after the end of the data/code segment. It is managed by the language itself, so its all automatically handeld for you.
    Lastly, the heap sits at the other side of the memory space and grows down. All dynamic allocations happens from here, and 
    is managed by you, the programmer. When people talk about "manual memory management", the heap is the area they are referring
    to. 

    -- Global & Static -- */

//  Global variables are declared outside of functions and classes. I advise to use them sparingly, if at all.
int global_var = 15;

//  Static variables in functions and structs/classes act like other languages, with only one instance per running program.
int example_static_counter()
{
    static int counter = 0; //this only is initialized to zero once the first time this function is called.
    return counter++;       //monotonically increasing counter
}
//  The difference between static and globals is when they are initialized and what scope they are available in. Global, like
//  the name implies, is visible to all, while static is only visible in its enclosing scope.

/*
	Static and global variables have their place, but the bread and butter of the language is within what is called local scope.
    That is, scopes inside of a function, class, namespace, or other scope limiting construct. 
*/
void example_local_scope(int paramA, int paramB)
{
    float A;
    A = 5.0f;
	ClassType B(2.0); // B is local to the function, so it exists inside the functions scope
    /* do stuff */
} 
/*
    -- Initialization --

    At C++'s core is the subject of lifetimes and initialization. This works hand in hand with memory management, as such a brief explanation of it
    is required.

    Lifetime is the time in which an object is created and when it is destroyed. A global lifetime means it is created when execution begins
    (before calling main) and ends after the program exits. Local scope is entirely within the enclosing scope. So an variable inside a function
    has its lifetime begin at the time of the function call and end when the function returns.

	For an variable to begin its lifetime, it first needs to be initialized. C++ has probably too many ways to initialize something,
	but for all intents and purposes, initialization is through three mechanisms. A constructor which uses parenthesis, an equal sign,
	or an initializer which uses curly braces.
*/
int init_a(100);
int init_b = 100;
int init_c{100};

/*
	There are lots of names for the different combinations of object types and initialization method, but all use one of the three patterns.
    The thing to realize about initialization is that it is a recursive property. That means that if a class uses another class as a member
    variable (not as a pointer), it has to also know how to initialize that object. Well designed classes will make that easy to do, either by
    using defaults or by needing arguments for a constructor. Note, that if a class has a reference to an object, there must be an already
    existing object in which to reference.

	After an objects constructor is called, it begins their lifetime, and operations can be done as per normal. And when they end their lifetime,
    their destructor is called. On simple objects (including primitives like int and bool), this will be a no-op, as nothing needs to to be done. 

    -- Call Stack --

    Where exactly does a local scope exist in memory? Globals and statics reside in the data segment of the executable, but that can't be expanded.
    We rely on the stack, in which the main function is the first scope pushed onto the stack. Whenever a new function is called, a stack frame is
    pushed onto the stack, and contains enough space for all of its member variables & classes. When the function exits, all those variables and 
    classes are destructed and the memory is freed (from the stack).

    Tying the call stack and lifetime together has the great property of being 100% deterministic. There is no way to leak memory with it, as 
    the only way to get more memory and free it is a function call and exit.

    Unfortunately, that isn't very helpful when needing to do more interesting work. While the stack can have a lot of data on it, the size of 
    each stack frame (read, function & its variables) is set in stone at compile time. That is to say, you couldn't have a dynamically sized
    array local to a function. There is a solution, and it is also the namesake for what is called "manual memory management"

    -- The Heap --

    The heap is the third and final segment of memory. It is managed by the operating system (not by automated language features).

    There are three operations that one can do on the heap: allocation, accessing, and releasing.
*/

//  Allocation is done through the new keyword, and it returns a pointer to an object stored on the heap
ObjectType *obj = new Object(arg1, arg2, ...); 

//  Accessing is done by "dereferencing" a pointer, and has 2 syntaxes, one for fundamental typyes and one for classes

int local_value = *heap_value; //access heap allocated data and store its value in a local_value

int local_value = HeapClass->MemberVariable; //similar as above, but the data is a member of a class

HeapClass->MemberFunction(/*args*/); //call a function on a heap allocated class

//  Releasing is done using the delete keyword
delete obj; //obj must be a pointer type

/* 
    There exists a problem though, how do we remember to call delete for every time heap object? Well, in short, the language has
    no guaranteed for that. If you forget to call delete, and the pointer (which is stored as a local variable) goes out of scope,
    that heap object has now become a memory leak. This is "bad". While it is true that once your program exits, all of its memory
    (data/code, stack, and heap) is freed, for long running programs this is unacceptable.  

    The solution is to attach the lifetime of heap allocated objects to stack allocated objects. Simply put, wrap the new/delete 
    calls into a class that manages the underlying data. Tying the two together means you can't ever forget to call delete because
    you never have to call delete manually in the first place. This is an idiom called RAII, or resource aquisition is initialization.
    It isn't anything new, but is a powerful mechanism for deterministic heap memory allocation.

    Whats even better is that there is a standard library type that does the wrapping for you! Its name is std::unique_ptr.
*/

//Wrapper type for heap allocated objects
#include <memory>
void example_unique_ptr(){

    std::unique_ptr<ObjectType> unique_obj = std::make_unique<ObjectType>(arg1, arg2);

    ObjectType *ptr_to_obj = unique_obj.get(); //returns a raw pointer to object, useful for api's like OpenGL.
}//unique_obj gets destroyed here

/*
    Notice the std::make_unique utility function. 

    Whats even better is that all of the standard library types use idiom. So no need to worry about standard library leaking memory
    left and right. The containers from the standard (including string) are essentially wrappers for a pointer to the heap with special 
    functions to access the data. 

    While RAII is awesome and you should use it, there are some situation where it doesn't quite solve all situations.
    
    std::unique_ptr has a drawback that it can't have multiple owners. Fortunately it has a cousin type std::shared_prt for that
    specific problem. Shadred pointers are reference counted pointers, which keep track of everyone who has access to the data.
    Shared Pointers work by having an external control block that is allocated on the heap. Keep that in mind as unique pointers cost
    the same as a raw pointer, while shared pointers have more overhad.
*/
#include <memory>
void example_shared_ptr() {
    std::shared_prt<ObjectType> shared_obj = std::make_shared<ObjectType>(arg1, arg2);

    external_object.shared_object_member_variable = shared_object; //now the external_object can access the shared_obj
} //shared_obj will be destroyed when all objects referencing it are destroyed.

/*
    shared_ptr has a weakness in that if the chain of ownership (who references who) forms a cycle, the object will never be destroyed
    because it is keeping itself alive. There is a fix, and that is to use std::weak_ptr, which doesn't take ownership (keep things alive).
    Thing to note is that you can't use a weak_ptr directly, you have to promote it to a shared_ptr.

    unique_ptr, shared_ptr, and weak_ptr form what are called "Smart Pointers", and should be used instead of raw pointers directly.

    There is still one type of situation where smart pointers are not a great fit. Data which is highly connected, like a graph. While we
    *can* use share_ptrs to connect objects together, it is more straightforward to seperate who owns the data and the how the data connects
    to eachother.

    A example of this idea put in practice a graph. A manager class handles allocating, accessing, and freeing data (using possible a hash table 
    to store the elements), while each element uses integer id's to refer to elements in the graph it is connected with. This will undoubtedly
    be easier to think about (imagine how you'd double check that there are no cycles in the graph? ) and is more space efficient (as each
    shared_ptr has a control block as well as the heap object). This pattern is sometimes called an arena.

    -- Wrap up --

    If there is one thing to take away from all this is that you should use local variables as much as possible. Being on the stack makes them
    cheap & quick. Next is managed things like standard library containers and unique_ptr. Finally, use managed arena's and shared_ptrs as a last 
    resort.

    Local Variables > containers/unique_ptr > arenas/share_ptr

*/

//////////////////////
// Standard Library //
//////////////////////

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
    This is a very powerful feature, as it decouples the container and algorithms in a modular and extensible fashion.  

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

    //  and a lambda can be used as well - very nice for specialized sorting routines -- see below
    std::sort(s.begin(), s.end(),
              [](int a, int b) {
                  return a > b;
              });
}

/*
    --IOstream--

    The easiest way of handling input and output with the outside world. 
    Both from the consol and from files on the system.

    Contains the std::cout and std::cin previously shown. 
*/

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
        But on that note, its pretty easy to do fork/join threading, so don't be afraid to do that if it works well
        for your use case.

    random - pseudorandom number generators.
        If you need good random numbers, this has what you should use (looking at you C's rand() )
    
    chrono - time and date facilities
        While some hate how cumbersome it is to use, this makes sure you can't muck it up. Time/date is notoriously
        easy to get wrong, so it was designed to be hard to use wrong.
    
    filesystem - C++17 and up - cross platform filesystem handling
    
    optional - C++17 - Wraps a value and boolean flag up together. Helps with expressing intent
    
    variant - C++17 - A typesafe union. Also can be as a replacement for traditional inheritance/polymorphism.

*/

/////////////
// Lambdas //
/////////////

/*
    C++11 adds the very useful feature of lambdas, or anonymous functions. By allowing the creation of functions anywhere and not 
    requiring a name, they are a powerful feature. 

    The technical basis is that a lambda is a "callable", meaning it is an object that can be called as if it was a function. This is
    also known as a function object, and can be used in places of a function. 

    What makes lambdas special is that they can also "capture" is beyond the capabilities of a pure function. It can save a few data
    members and pointers/references to be used for later use.

    A lambda can have any of the following forms:
    [ captures ] ( params ) -> ret_type { body } 	 	
    [ captures ] ( params ) { body } 	 	
    [ captures ] { body } 

    captures is a comma seperated list of objects, with two special possible values, = and &. = means to copy and & means to reference.
    Copy will take whatever values and put it into the capture (which can be costly if the size if large). & will only reference it, which 
    saves space, but you have to be sure the object still exists. They must be put first if used at all, and only one or the other can be use,
    or neither but not both.

    params, ret_type, and body are just the parameters, return type, and body of an equivalent function.

    Lambdas are useful for defining call back functions inplace. Makes so you don't have to define a function that is only ever called
    in one place.
*/
register_command("Turn On Light-bulb", 
    [&light_controller]() {
        light_controller.on();
    }
);

//  They are also very useful for defining specializations to be used in all sorts of places. Sorting, searching, hashing, etc

//  Here, we can sort the elements based in a custom defined manner. Can be extended beyond basic types (ie classes) 
std::sort(s.begin(), s.end(), 
    [](int a, int b) {
        return a > b;   
    }
);

////////////////////
// Move Semantics //
////////////////////

/*
    This is like a copy constructor, but instead "moves" the underlying data. If its all local values, this doesn't mean anything, but if
    a class (like std::vector) owned some heap data, moving this object means transferring ownership. In essence, move semantics implies 
    ownership semantics for resources. A resource could be a heap allocated pointer, a file system handle, a socket, or anything other 
    thing.

    Move semantics is beyond the scope of this tutorial, but a good thing to know about as many "advanced" features of the language make 
    use of them to enable performance optimizations.  
*/
