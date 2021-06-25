# Garbage Collector

# How it's work

- We have Virtual Machine like JVM or something like that , in code this object called Virtual Memory.
- Virtual Machine can keep objects , in my abstract Virtual Machine they calls Object_t.
- Virtual Machine have Using Memory , objects in using memory can't destroy while Virtual Machine working , in code it's called UsingMemory_t.
- Which objects can be using ? In my abstract programming language , object using <=> when it has parent or it has reference to another object. 
