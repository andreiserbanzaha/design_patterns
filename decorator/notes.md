# Decorator design pattern

- adding behavior without altering the class itself
- **Decorator** - facilitates the addition of behaviors to individual objects


### Motivation

- want to augment an object with additional functionality
- do not want to rewrite or alter existing code (OCP)
- want to keep new functionality separate (SRP)
- need to be able to interact with existing structures
- 2 options:
	- aggregate the decorated object
	- inherit from the decorated object


### Summary

- a **dynamic** decorator keeps the reference to the decorated object(s)
	- ColoredShape{Square{}}
- a **static** decorator uses mixin inheritance 
	- ColoredShape<Square>
- both approaches allow limitless composition
	- TransparentShape<ColoredShape<Circle>>

