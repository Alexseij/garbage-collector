#include<stdio.h>
#include<stdlib.h>

#include "vm.h"
#include "object.h"

// Cuz i don't have any skills for working with native virtual memory , i will create fake virtual memory
VirtualMemory_t* NewVirtualMemory() {
    VirtualMemory_t* newVirtualMemory = (VirtualMemory_t*)malloc(sizeof(VirtualMemory_t));
    newVirtualMemory->usingMemory = NULL;
    newVirtualMemory->size = 0;
    newVirtualMemory->objects = (Object_t**)malloc(sizeof(Object_t*) * SIZE_OF_VIRTUAL_MEMORY);
    return newVirtualMemory;
}

UsingMemory_t* NewUsingMemory() {
    UsingMemory_t* newUsingMemory = (UsingMemory_t*)malloc(sizeof(UsingMemory_t));
    newUsingMemory->size = 0;
    newUsingMemory->objects = (Object_t*)malloc(sizeof(Object_t) * INIT_SIZE_OF_USING_MEMORY);
    newUsingMemory->capacity = INIT_SIZE_OF_USING_MEMORY;
    return newUsingMemory;
}

void Push(VirtualMemory_t* virtualMemory, Object_t* object) {
    if (virtualMemory == NULL) {
        fprintf(stderr, "NULL pointer to Virtual memory\n");
        exit(EXIT_FAILURE);
    }

    if (object == NULL) {
        return;
    }

    size_t * size = &virtualMemory->size;

    if (*size < SIZE_OF_VIRTUAL_MEMORY) {
        virtualMemory->objects[*size] = object;
        (*size)++;

        if (virtualMemory->objects[*size - 1]->next != NULL
            || virtualMemory->objects[*size - 1]->parent != NULL) {
            if (virtualMemory->usingMemory == NULL) {
                virtualMemory->usingMemory = NewUsingMemory();
                virtualMemory->usingMemory->objects[0] = object;
                virtualMemory->usingMemory->size++;
                return;
            }

            if (virtualMemory->usingMemory->size >= virtualMemory->usingMemory->capacity) {
                virtualMemory->usingMemory->capacity *= 2;
                virtualMemory->usingMemory->objects = (Object_t*)realloc(virtualMemory->usingMemory->objects, virtualMemory->usingMemory->capacity);
            }
            virtualMemory->usingMemory->objects[virtualMemory->usingMemory->size] = object;
            virtualMemory->usingMemory->size++;
        }
    }
    else {
        fprintf(stdout, "Stack Overflow !!1 https://ru.stackoverflow.com/");
        exit(EXIT_FAILURE);
    }
}

Object_t* Pop(VirtualMemory_t* virtualMemory) {
    if (virtualMemory == NULL) {
        fprintf(stderr, "NULL pointer to Virtual memory\n");
        exit(EXIT_FAILURE);
    }

    size_t size = virtualMemory->size;

    if (size >= 0) {
        Object_t* object = virtualMemory->objects[size];
        virtualMemory->size--;

        return object;
    }
    else {
        fprintf(stdout, "Stack is empty !\n");
        return NULL;
    }
}