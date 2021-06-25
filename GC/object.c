#include<stdio.h>

#include "object.h"
#include "vm.h"

Object_t* NewObject(Type_t type, void* data) {
    Object_t* newObject = NULL;

    // TODO : Make some types
    switch (type) {
    case FIRST_TYPE:
        newObject = (Object_t*)malloc(sizeof(Object_t));
        break;
    case SECOND_TYPE:
        newObject = (Object_t*)malloc(sizeof(Object_t));
        break;
    default:
        fprintf(stderr, "Incorrect type\n");
        exit(EXIT_FAILURE);
    }

    newObject->type = type;
    newObject->data = data;
    newObject->marked = false;
    newObject->next = NULL;
    newObject->parent = NULL;

    return newObject;
}