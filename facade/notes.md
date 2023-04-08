# Facade Design Pattern

- exposing several components through a single interface
- provides a simple, easy to understand **interface/user interface** over a large and sophisticated body of code


### Motivation

- balancing complexity and presentation/usability
- example of a typical home
	- many subsystems (electrical, sanitation)
	- complex internal structure (floor layers)
	- end user is not exposed to internals
- same with software!
	- many systems working to provide flexibility, but...
	- API consumers want it to 'just work'


### Summary

- build a **facade** to provide a simplified API over a set of classes
- may with to (optionally) expose internals through the **facade**
- may allow users to 'escalate' to use more complex APIs if they need to
