#pragma once

#include <string>

class Person
{
public:
	Person();
	~Person();

	void greet();

private:
	class PersonImpl;
	PersonImpl* impl;

	std::string name;
};
