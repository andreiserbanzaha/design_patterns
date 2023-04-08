#include "../inc/person.h"
#include "../inc/chatroom.h"

Person::Person(std::string const& name)
    : _name{name}
{}

void Person::say(std::string const& message) const
{
    _chatRoom->broadcast(_name, message);
}

void Person::pm(std::string const& who,
                std::string const& message) const
{
    _chatRoom->message(_name, who, message);
}

void Person::receive(std::string const& origin,
                     std::string const& message)
{
    std::string s {origin + ": \"" + message + "\"" };
    std::cout << "[" << _name << "'s chat session]" << s << '\n';
    _chatLog.emplace_back(s);
}

bool Person::operator==(Person const& other)
{
    return _name == other.getName();
}

bool Person::operator!=(Person const& other)
{
    return _name != other.getName();
}

std::string Person::getName() const
{
    return _name;
}

void Person::setRoom(ChatRoom* room)
{
    _chatRoom = room;
}
