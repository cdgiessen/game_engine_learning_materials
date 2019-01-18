/*
    -- Pool Allocator --

    A pool allocator works by preallocating a chunks of memory all in the same size, then
    uses a free_list to suballocate out of it. It does not suffer from fragmentation but 
    is limited by the need to have all the objects of the same size. 

    Use Case: There are a lot of the same object with a high rate of creation/destruction. As the 
    memory is already allocated, its cheap to add/remove (no OS calls to get more memory)

    Disclamer: This isn't a tested (or even compiled) allocator. For illustrative purposes only
*/
#pragma once

#include <stdlib.h>

template<typename T>
class PoolAlloc {
public:
    PoolAlloc(int max_objects) : max_objects(max_objects){
        data = (T*)malloc(sizeof(T) * max_objects);
        free_list = (int*)malloc(sizeof(int) * max_objects);

        for(int i = 0; i < max_objects-1;i++){
            free_list[i] = i+1; 
        }
        free_list[max_objects - 1] = 0; //loop it back

    }

    template<typename... Args>
    T* Allocate(Args&&... args){

        int next_free = free_list[current_free_node];

        //fancy way of constructing objects in place
        T* ret = new (&data[current_free_node])T(std::forward<Args>(args)...)
        current_free_node = next_free;
        current_objects_allocated++; //maybe check if its over the max?
        return ret;
    }

    void Free(T* elem){
        //Calculate which index this is: (elem - data)/sizeof(T);
        //This index should be added to the free list
        //in place destroy: elem->~T();

    }

private:
    T* data;
    int* free_list;
    int current_free_node = 0;
    int max_objects;
    int current_objects_allocated = 0;
    
};
