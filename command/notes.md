# Command

- ordinary c++ statements are perishable
    - cannot undo a field/property assignment
    - cannot directly serialize a sequence of actions(calls)

- want an object that represents an operation
    - X should change its field Y to value Z
    - X should do w()

- uses: GUI commands, multi-level undo/redo, macro recordings and more

- **Command**
    - an object which represents an instruction to perform a particular action
    - contains all the information necessary for the action to be taken

- **Command Query Separation**
    - command - asking for an action or change (no return value)
    - query - asking for an information
    - CQS - having separate means of sending commands and queries


### Summary

- encapsulate all details of an operation in a separate object
- define instruction for applying the command(either in the command itself or elsewhere)
- optionally define instructions for undoing the command
- can create composite commands (aka macros) 
