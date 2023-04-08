#include <algorithm>

#include "../inc/chatroom.h"
#include "../inc/person.h"

ChatRoom::ChatRoom()
{
}

void ChatRoom::broadcast(std::string const& origin,
                         std::string const& message)
{
    for(auto& p : _people)
    {
        if (p->getName() != origin)
        {
            p->receive(origin, message);
        }
    }
}

void ChatRoom::join(Person* p)
{
    std::string joinMessage = p->getName() + " has joined the chat";
    broadcast("room", joinMessage);
    p->setRoom(this);
    _people.push_back(p);
}

void ChatRoom::message(std::string const& origin,
                       std::string const& who,
                       std::string const& message)
{
    auto target = std::find_if(std::begin(_people),
                               std::end(_people),
                               [&](Person* p){
            return p->getName() == who;
});
    if (target != std::end(_people))
    {
        (*target)->receive(origin, message);
    }
}
