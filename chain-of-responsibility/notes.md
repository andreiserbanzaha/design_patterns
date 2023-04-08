# Chain of Responsibility

- sequence of handlers processing an event one after another
- a chain of components who all get the chance to process a command or a query, optionally having default processing implementation and an ability to terminate the processing chain


### Motivation

- unethical behavior by an employee - Who takes the blame?
    - employee
    - manager
    - CEO


- you click a graphical element on a form
    - button handles it, stops further processing
    - underlying group box
    - underlying window


- CCG computer game
    - creature has attack and defense values
    - those can be boosted by other cards


### Summary

- can be implemented as:
    - a chain of pointers/references (singly linked lists)
    - centralized list (broker)


- enlist objects in the chain, possibly controling their order
- object removal from chain (e.g. disconnect from a signal)
