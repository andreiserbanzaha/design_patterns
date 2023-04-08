# Memento

- keep a momento of an object's state to return to that state
- a token/handle representing the system state.
    - lets us to roll back to the state when the token was generated
    - may or may not directly expose state information

### Motivation

- an object or system goes through changes
    - e.g. bank accounts get deposits and withdraws
- there are different ways to navigate those changes
    - record every change (**command**) and teach a command to *undo* itself
    - save a snapshot of the system


### Summary

- mementos are used to roll back states arbitrarily
- a memento is simply a token/handle class with (typically) no functions of its own
- a memento is not required to expose directly the state(s) to which it reverts the system
- can be used to implements undo/redo
