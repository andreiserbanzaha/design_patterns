# Singleton Design Pattern

- **singleton** - a component which is instantiated only once


### Motivation

- for some components it only makes sense to have only ONE in the system
    - database repository
    - object factory
- when the constructor call is expensive
    - we do it only once
    - we provide everyone with the same instance
- want to prevent anyone to create additional copies
- need to take care of lazy instantiation and thread safety


### Summary

- making a 'safe' singleton is easy
    - hide or delete the type's c-tor, copy c-tor and copy assignment operator
    - create a static method that returns a reference to a static member
    - guaranteed to be thread-safe since c++11
- types with 'hard' dependencies on singletons are difficult to test
    - cannot decouple the singleton and supply a fake object
- instead of directly using a singleton, consider depending on an abstraction (e.g. interface)
- consider defining a singleton lifetime in DI container
