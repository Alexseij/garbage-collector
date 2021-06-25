#pragma once

#include <stdbool.h>

#define FIRST_TYPE_SIZE 4
#define SECOND_TYPE_SIZE 8

typedef enum Type {
    //Have no idea for name of my types :)
    FIRST_TYPE,
    SECOND_TYPE
}Type_t;

typedef struct Object {
    void* data;
    Type_t          type;
    bool            marked;
    struct Object* next;
    struct Object* parent;
} Object_t;

Object_t* NewObject(Type_t, void*);