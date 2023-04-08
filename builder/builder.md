# Builder Design Pattern

- when construction gets a little bit too complicated

### Motivation

- **when piecewise object construction is complicated, provide an API for doing it succintly**
- some objects are simple and can be created in a single constructor call
- other objects require a lot of ceremony to create
- having an object with 10 constructor parameters is not productive
- instead, opt for piecewise construction
- builder provides an API for constructing an object step-by-step
