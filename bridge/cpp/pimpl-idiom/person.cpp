#include "person.h"

class Person::PersonImpl
{
public:
	void greet(Person* p);
};

void Person::PersonImpl::greet(Person* p)
{
	// greet impl
}

Person::Person() 
	: impl { new PersonImpl }
{
}

Person::~Person()
{
	delete impl;
}

void Person::greet()
{
	impl->greet(this);
}
