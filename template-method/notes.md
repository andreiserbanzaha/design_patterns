# Template method

- a high level blueprint for an algorithm to be completed by inheritors
- allows us to define the *skeleton* of the algorithm, with concrete implementations defined in subclasses

### Motivation

- algorithms can be decomposed into common parts  + spefifics
- strategy pattern does this through composition
    - high-level algorithm uses an interface
    - concrete implementations implement the interface
- template method does the same thing through inheritance
    - overall algorithm makes use of abstract member
    - inheritors override abstract members
    - parent template method invoked


### Summary

- define an algorithm at a high-level
- define constituent parts as abstract methods
- inherit the algorithm class, providing the necessary overrides
