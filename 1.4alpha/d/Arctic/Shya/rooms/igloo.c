#include <config.h>
#include <mudlib.h>
inherit ROOM;

object snowman, icegolem, snowcat;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "a igloo");
    set( "long", @EndText
This igloo is warm and cozy compaired to outside on the pond.
A small fire burning keeps it warm. 
EndText
    );
    set( "exits", ([
         "south" : "/d/Arctic/Shya/rooms/icehouse2.c",
    ]) );
    set("item_desc", ([
        "fire" : "This fire is burning nice and hot. Surprising for inside an igloo.\n"
]));
    snowman=clone_object("/d/Arctic/Shya/monsters/snowman.c");
    snowman->move(TO);
    snowcat=clone_object("/d/Arctic/Shya/monsters/snowcat.c");
    snowcat->move(TO);
    icegolem=clone_object("/d/Arctic/Shya/monsters/icegolem.c");
    icegolem->move(TO);
}