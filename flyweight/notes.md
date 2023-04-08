# Flyweight Design Pattern

- a space optimization technique that lets you use less memory by storing externally the data associated with similar objects
- store common data externally (e.g. static map)
- defined the idea of *ranges* on homogeneous collections -> store data related to those ranges

### Motivation

- avoid redundancy when storing data
- e.g. in an MMORPG:
	- lots of users with identical first/last name
	- no sense in storing same first/last name over and over again
	- store a list of names and pointers to them
- e.g. bold or italic text in the console
	- don't want each character to have a formatting character
	- operate on ranges (e.g. line number, start/end positions)
