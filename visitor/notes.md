# Visitor

- typically a tool for structure traversal rather than anything else
- a pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy
- implemented by propagating a single visit() method throughout the entire hierarchy


### Motivation

- need to define a new operation on an entire class hierarchy
    - e.g. make a document model printable to html/markdown
- do not want to keep modifying every class in the hierarchy
- need access to the non-common aspects of classes in the hierarchy
    - cannot put everything in a single interface
- create an external component to handle rendering
    - but preferably avoid type checks


### Summary

- propagate an **accept(visitor* v)** method throughout the entire hierarchy
- create a visitor with **visit(Foo*)**, **visit(Bar*)** ... for each element in the hierarchy
- each **accept()** simply calls the **visitor.visit(this)**
