# Iterators

- how traversal of data structures  happens and who makes it happen


- **Iterator** - an object that facilitates the traversal of a data structure

### Motivation

- iteration (traversal) is a core functionality of various data structures
- an **iterator** is a class that facilitates the traversal
    - keeps a reference to the current element
    - knows how to move to a different element
- can be used implicitly
    - range-based for loop
    - coroutines


### Summary

- an object can be iterated(traversed) if it defines *begin()/end()* pair
- an iterator specified how you can traverse an object
- typically required operators **!=** and **++**
- **++** is called sporadically, so cannot be recursive, but...
    - coroutines allow recursion through generator-yielding functions
