/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;


void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "House of Mage");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
A blast of intense cold hits your body as you walk in here.
The entire room is covered with ice. Various patterns and
runes are etched into the ice you suppose to preserve the
room from melting. You get the sense that great magics
were used to maintain the beauty that is crafted into this
rooms construction. As your mind and eyes begin to become
more focused on the patterns you notice a story appearing
on each wall. The north which also holds an exit, tells the
story of a mother and her son struggling to survive after
The east tells of a powerful dragon forced to obey an evil
king after slicing the heads off of two of her three babies.
The western wall gives you a look at a peaceful glade with
two lovers, embracing in there first, you watch enthralled
by the passion reflected by the artist.
As you turn around to look at the story behind you, all you
can do is gasp.  the story tells of a great battle, this
battle was fought with blades forged from the souls of the
elder ones.  the battle lasts for many days.mighty blows 
takin on all sides. as you watch your eyes become tired, 
and you never see the end, perhaps there isn't an end...
perhaps it still goes on, or perhaps no mortal would ever
be able to watch the true power of such a battle and live.
EndText
);
    set( "exits", ([
"west" : "room5.c",
"east" : "room6.c",
"south" : "room3.c",
    ]) );
    set( "item_desc", ([

]) );

}


