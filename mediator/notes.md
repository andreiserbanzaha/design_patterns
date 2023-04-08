# Mediator

- a component that facilitates communication between other components without them necessary being aware of each other or having direct (reference) access to each other

### Motivation

- components may go in and out of the system at any time
    - e.g. chat room participants, players in MMORPG etc
- it makes no sense to have direct references to one another
    - those references may go dead
- solution:
    - have them all refer to some central component that facilitates communication

### Summary

- create the mediator and have each object in the system refer to it
    - e.g. in a field
- mediator engages in bidirectional communication with its connected components
- mediator has functions the components can call
- components have functions the mediator can call
- event processing libraries make communication easier to implement
