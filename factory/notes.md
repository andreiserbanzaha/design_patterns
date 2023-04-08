# Factory Design Pattern

- a component responsible solely for the wholesale (not piece-wise) creation of objects


### Motivation

- object creation logic becomes too convoluted
- constructor is not descriptive
    - name mandated by the containing type
    - cannot overload with same sets of arguments with different names
    - can turn into **optional parameter hell**
- object creation (unlike *builder* - not piece-wise) can be outsourced to:
    - a separate function (**Factory method**)
    - a separate class (**Factory**)
    - a hierarchy of factories with Abstract Factory
