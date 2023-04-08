# Composite Design Pattern

- treating individual and aggregate objects uniformly
- **composite** - a mechanism for treating individual (scalar) objects and compositions of objects in a uniform manner

### Motivation

- objects use other object's fields/properties/members through inheritance and composition
- composition lets us make compound objects
	- e.g.:
		- mathematical expression composed of simple expressions
		- a grouping of shapes that consists of several shapes
- **composite** design pattern is used to treat both single (scalar) and composite objects uniformly
	- Foo and Collection<Foo> have common APIs


### Summary

- objects can use other objects through inheritance/composition
- some composed and singular objects need similar/identical behavior (APIs)
- **composite** design pattern lets us tread both types of objects uniformly
- C++ uses *duck typing*, expecting enumerable types to provide begin()/end()
- a single object can masquerade as a collection
```
Foo* begin() { return this; }
Foo* end() { return this + 1; }
```
