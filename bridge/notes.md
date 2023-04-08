# Bridge Design Pattern

- connecting components together through abstractions
- **bridge** - a mechanism that decouples an interface (hierarchy) from an implementation (hierarchy)


### Motivation

- prevents a 'Cartesian product' complexity explosion
- example:
	- base class ThreadScheduler
		- preemptive / cooperative
		- windows / linux 
	- end up with a 2x2 scenario: WindowsPTS, UnixPTS, WindowsCTS, UnixCTS
- bridge pattern avoids entity explosion


### Summary

- decouple abstraction from implementation
- both can exist as hierarchies
- a stronger form of encapsulation
