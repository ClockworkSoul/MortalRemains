// Damage from cold done by Cyanid by request of Blood.
// 9 Feb 2000

#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "blood");
    set( "short", "House of the Mage");
    set( "long",@EndText
A blast of intense cold hits your body as you walk in here. The entire room
is covered with ice, ornately carved with arcane patterns and runes. As 
your mind and eyes begin to become more focused on the patterns you notice
a story appearing on each wall.
EndText
    );
    set( "exits", ([
      "west" : N_ROOM+"room5.c",
      "east" : N_ROOM+"room6.c",
      "south" : N_ROOM+"room3.c",
      "southwest" : N_ROOM+"room14.c",
    ]) );

    create_door("southwest","northeast","A mahogany door inlaid with silver "+
      "script that glows with the hints of magical protection.", "locked",
      "cheese key", 25);
    set( "item_desc", ([
      "ice" : "Various arcane patterns and runes are etched into the ice.\n",
      "patterns" : wrap("As your mind and eyes begin to become more focused "+
	"on the patterns you notice a story appearing on each wall."),
      "runes" : "Their purpose is a mystery to you.\n",
      "story" : wrap("Which wall do you wish to look at? The east wall, "+
	"west wall, north wall, or south wall?"),
      "north wall" : (@EndNorth
The north which also holds an exit, tells the story of a mother and her
son struggling to survive. It appears to be a continuation of the story on
the east wall.
EndNorth
      ),
      "south wall" : (@EndSouth
As you turn around to look at the story behind you, all you can do is gasp. 
The story tells of a great battle, this battle was fought with blades 
forged from the souls of the Elder Ones. The battle lasts for many days,
with mighty blows taken on all sides. As you watch your eyes become tired,
and you never see the end. Perhaps there isn't an end; perhaps it still 
goes on. Perhaps no mortal would ever be able to watch the true power of
such a battle and live?
EndSouth
      ),
      "east wall" : (@EndEast
The eastern wall tells of a powerful dragon forced to obey an evil king
after he sliced the heads off of two of her three babies.
EndEast
      ),
      "west wall" : (@EndWest
The western wall gives you a look at a peaceful glade with two lovers, 
embracing in there first, you watch enthralled by the passion reflected by
the artist.
EndWest
      ),
    ]) );
}

void init() {
    call_out("do_cold_func", 30, TP);
}

int do_cold_func( object ob ) {
    if (environment(ob) != TO) return 0;
    tell_object(ob, "You feel the cold seep into your bones.\n");

    ob->receive_damage(ob->query_level()*6, "cold");

    call_out("do_cold_func", 30, ob);
    return 1;
}

/* EOF */
