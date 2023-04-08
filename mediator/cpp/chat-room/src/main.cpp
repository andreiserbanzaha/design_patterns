#include "../inc/chatroom.h"
#include "../inc/person.h"

int main()
{
    ChatRoom room;

    Person p1{"John"};
    Person p2{"Jane"};
    Person p3{"drew"};

    room.join(&p1);
    room.join(&p2);
    room.join(&p3);

    p1.say("Hi room");
    p2.say("wassup");
    p3.say("holla");

    return 0;
}
