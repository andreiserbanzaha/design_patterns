# Prototype Design Pattern

- **Prototype** - a partially or fully initialized object that you copy (clone) and make use of

### Motivation

- complicated objects aren't designed from scratch
    - they reiterate existing designs
- an existing (partially or fully constructed) design is a **Prototype**
- we make a copy (clone) of the prototype and customize it
    - requires **deep copy** support
- we make the cloning convenient (e.g. via a Factory)
