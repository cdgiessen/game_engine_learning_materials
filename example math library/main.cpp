

#include <iostream>

#include "Vector3.h"

/*
Example usage of our Vector class

*/


void example_function_call(int count, float* pointer){ /* do fancy stuff*/}

    

int main(){

    math::Vector3 a = math::Vector3(2,3,2);

    using namespace math;
    Vector3 b = a + Vector3(0,-2,1);

    //why operator overloads are so nice (for math types)
    Vector3 c = a * b - a / b;

    a.Normalize(); //change a
    c = b.Normal(); // b gets the normal version of a, but doesn't change a

    float* data_array;
    data_array = c.data_ptr(); //data_array now points to the location of Vector3 c
    
    //forward declaration of a function
    void example_api_call(int count, float* pointer);

    //sample usage for data_ptr(). Very handy for C api's (like OpenGL)
    example_function_call(3, c.data_ptr());
    
    //output to standard output, or for use in custom printer
    std::cout << a << " " << b << " " << c;
    std::string out = a.to_string();

    return 0; 
}
