#include "../cave.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light",1);
    set("short","an indescript room");
    set("long",@EndText
An indescript room, just waiting to be filled with many nouns, adjectives, and verbs.
EndText
    );
    set("items",([
    ]) );
    set("exits",([
        "north":CRM+"14",
        "west":CRM+"25",
        "south":CRM+"27",
    ]) );
}
