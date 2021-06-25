#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

#include "object.h"
#include "vm.h"

void markAll(VirtualMemory_t* virtualMemory) {
    for (int i = 0; i < virtualMemory->size; i++) {
        for (int j = 0; j < virtualMemory->usingMemory->size; j++) {
            if (virtualMemory->objects[i] != NULL
                && virtualMemory->objects[i] == virtualMemory->usingMemory->objects[j]) {
                virtualMemory->objects[i]->marked = true;
                break;
            }
        }
    }
}

void sweep(VirtualMemory_t* virtualMemory) {
    for (int i = 0; i < virtualMemory->size; i++) {
        if (!virtualMemory->objects[i]->marked) {
            free(virtualMemory->objects[i]);
            virtualMemory->size--;
        }
        else {
            virtualMemory->objects[i]->marked = false;
        }
    }
}

void gc(VirtualMemory_t* virtualMemory) {
    markAll(virtualMemory);
    sweep(virtualMemory);
}

void test1(VirtualMemory_t* virtualMemory) {
    Object_t* firstObject = NewObject(FIRST_TYPE, 10);
    Object_t* secondObject = NewObject(FIRST_TYPE, 20);
    Object_t* thirdObject = NewObject(FIRST_TYPE, 30);

    firstObject->next = secondObject;
    secondObject->parent = firstObject;

    Push(virtualMemory, firstObject);
    Push(virtualMemory, secondObject);
    Push(virtualMemory, thirdObject);
    
    int numOfElements = virtualMemory->size;
    int numOfUsingElements = virtualMemory->usingMemory->size;

    gc(virtualMemory);

    printf("Collected elments : %d  , Using elements now : %d", numOfElements - numOfUsingElements, virtualMemory->size);
}

int main(void) {
    VirtualMemory_t* virtualMemory = NewVirtualMemory();
    test1(virtualMemory);
    return 0;
}


