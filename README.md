# Garbage Collector

# How it works

- We have Virtual Machine like JVM or something like that , in code this object called Virtual Memory.
- Virtual Machine can keep objects , in my abstract Virtual Machine they calls Object_t.
- Virtual Machine have Using Memory , objects in using memory can't destroy while Virtual Machine working , in code it's called UsingMemory_t.
- Which objects can be using ? In my abstract programming language , object using <=> when it has parent or it has reference to another object. 
- After creating objects in Virtual Machine , we can call gc , which scanning all object of Virtual Machine and marks using objects (objects in Using Memory). After programm calls sweep function which delete unusing objects. 
