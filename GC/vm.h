#pragma once

#include<stdlib.h>

#include"object.h"

#define SIZE_OF_VIRTUAL_MEMORY 256 
#define INIT_SIZE_OF_USING_MEMORY 8

typedef struct UsingMemory {
    Object_t**  objects;
    size_t      size;
    size_t      capacity;
} UsingMemory_t;

typedef struct VirtualMemory {
    size_t          size;
    Object_t**      objects;
    UsingMemory_t*  usingMemory;
}VirtualMemory_t;

VirtualMemory_t* NewVirtualMemory();
void Push(VirtualMemory_t*, Object_t*);
Object_t* Pop(VirtualMemory_t*);