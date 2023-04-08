#pragma once

#include <iostream>
#include <vector>

class Person;

class ChatRoom
{
public:
    ChatRoom();

    void broadcast(std::string const& origin,
                   std::string const& message);

    void join(Person* p);

    void message(std::string const& origin,
                 std::string const& who,
                 std::string const& message);

private:
    std::vector<Person*> _people;
};
