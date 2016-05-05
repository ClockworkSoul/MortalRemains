/*
** File: room6.c
** Author: Ragevortex
** Updated by: Lady Nsd (august 2000)
*/

#include <config.h>
#include <mudlib.h>
#include "mina.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("light",1);
    set("short", "Underground");
    set("author", "ragevortex");
    set("smell", "The air is filled with the stench of dust and rust.\n");
    set( "long", @EndText
The walls here are made of solid rock. They are also cold like
the metal ones. There's dust all around you. No one seems to
clean this place. There's some light coming from the opening
in the ceiling.
EndText
    );
    set( "exits", ([
      "up" : MINA_ROOM+"room2.c",
    ]) );
    set("item_desc", ([
      "dust" : "ACHOOO!!! sniff sniff ... there's a lot of dust.\n",
      "walls" : "Made of hard rock... really hard.\n",
    ]) );
    set ("objects", ([
      "minotaur" : MINA_MON+"warrior.c",
    ]) );
    reset();
}
