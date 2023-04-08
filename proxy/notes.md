# Proxy design pattern

- **Proxy** - an interface for accessing a particular resource
- a class that acts as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality
- proxy example: smart pointers

### Motivation

- you are calling *foo.bar()*
- this assumes that *foo* is in the same process as *bar()*
- what if, later on, you want to put all *foo*-related operations into a separate process
  - can you avoid changing your code?
- **proxy** to the rescue
  - same interface, entirely different behavior
- this is called *communication proxy*
  - other types: logging, virtual, guarding etc..


### Proxy vs Decorator

- **Proxy** provides an identical interface
- **Decorator** provides and enhanced interface
- **Decorator** typically aggregates (or has reference to) what it is decorating, while **proxy** doesn't have to
- **Proxy** might not even be working with a materialized object


### Summary

- a *proxy* has the same interface as the underlying object
- to create a *proxy* simply replicate the existing interface of an object
- add relevant functionality to the redefined member functions
- different proxies: *communication*, *logging*, *caching* etc.
