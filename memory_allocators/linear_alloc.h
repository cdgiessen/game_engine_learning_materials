/*
    -- Linear Allocator --

    A linear allocator is one of the simplest kinds of allocators out there. Its simple
    because it only ever allocates, never frees. Starting out with a big bag of memory,
    it keeps incrementing an offset into as calls to Allocate() are made. It has the 
    convinient Reset() function which simply reset the offset to the start, ready for
    new allocations to be made.

    Use case: A scratch space that is short-lived. Don't put persistant data structures 
    here, rather for intermediate computations.

    Disclamer: This isn't a tested (or even compiled) allocator. For illustrative purposes only
   
*/

#pragma once

#include <stdlib.h>

class LinearAlloc {
public:
    LinearAlloc(int total_size) : 
        location(0), //start at the beginning
        total_size(total_size) //set max size
    {
        data = (char*)malloc(total_size);
    }
    ~LinearAlloc(){
        free(data); //free the data after using it
    }

    char* Allocate(int size){
        if(location + size >= total_size)
        {
            return nullptr; //can't allocate anymore! 
        } 
        char* cur = data + location;
        location += size;
        return cur;
    }

    void Free() {
        // Does nothing!
    }

    // Make the current location the start again.
    void Reset(){
        location = 0; 
    }

private:
    char* data;
    int location;
    int total_size;
};