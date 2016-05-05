#include <mudlib.h>

inherit ROOM;

void create()
{
seteuid(geteuid());
set( "light", 1);
set( "short", "Ancient ruins");
set( "long", @Endtext
As you enter the room you feel the ancient power that still
resides within these walls. The civilization that built and
once inhabited this structure was a powerful one, making you
fear even more the force that destroyed them. The walls are a 
dark obsidian, reflecting some light but causing many shadows to
form, some of which seem very unnatural and life like. To your
north is a corridor leading further into the ruins. To your south
is the forest that surrounds this structure.
Endtext
);
set( "item_desc", ([
"walls" : "The walls are made of a dark obsidian that is cold to the touch. They reflect what little light there is creating shadows to play with your mind.\n",
"shadows" : "Shadows caused by the light reflecting off the smooth walls. Are they alive or is it just an over active imagination playing games with you??\n",
"floor" : "The floor is worn with age yet remarkably clean for the amount of time that this place has gone uninhabited.\n",
"ceiling" : "The high ceiling is cracked in many places allowing some light to filter in and dance along the walls.\n",
]));
set( "search_desc", ([
"shadows" : "You try and search the shadows but they seem to dance and dodge your feeble attempts.\n",
"walls" : "You search the walls and after a awhile you find........nothing but wall.\n",
"floor" : "After kneeling down to inspect the floor you realize it was all for naught since there is nothing here but a stone floor.\n",
"ceiling" : "You think about inspecting the ceiling but realize that there is not enough of left to risk breaking your neck over.\n",
]));
set( "exits", ([
"up"  :  "/d/Prime/Krynn/Duegne2/Ruin/house2.c",
"north"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin2.c",
]) );
::create();
}
