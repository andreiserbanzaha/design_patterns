# Strategy (also known as Policy)

- system behavior partially specified at runtime
- enables the exact behavior of a system to selected either at run-time (dynamic) or at compile-time (static)


### Motivation

- many algorithms can be decomposed into higher and lower level parts
- e.g. making tea can be decomposed into:
    - the process of making a hot beverage (boil water, put into cup)
    - tea-specific things (put teabag into water)
- the high-level algorithm can then be reused for making coffee or hot chocolate
    - supported by beverage specific strategies


### Summary

- define an algorithm at a high level
- define the interface you expect each strategy to follow
- provide for either dynamic or static composition of strategy in the overall algorithm
