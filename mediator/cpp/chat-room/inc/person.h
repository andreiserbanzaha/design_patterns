#pragma once

#include <iostream>
#include <string>
#include <vector>

class ChatRoom;

class Person
{
public:
    Person(std::string const& name);

    void say(std::string const& message) const;

    void pm(std::string const& who,
            std::string const& message) const;

    void receive(std::string const& origin,
                 std::string const& message);

    bool operator==(Person const& other);

    bool operator!=(Person const& other);

    std::string getName() const;

    void setRoom(ChatRoom* room);

private:
    std::string _name;
    std::vector<std::string> _chatLog;
    ChatRoom* _chatRoom{nullptr};
};
