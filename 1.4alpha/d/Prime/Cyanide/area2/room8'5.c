#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();//<- gets all the information from the original create()
  seteuid( getuid());
  set( "light", 1 );
set ("short", "Palace Entrance");
  set( "long", @EndText
The great iron doors to this grand palace entrance were shattred by
the same powerful magic that cracked the plaza outside. Dust has drifted
through the opening, covering much of the floor in ankle-deep-dust.
  Long ago, Torkath had this grand hall built to greet visiting nobles.
A beautiful mural adorns the walls here. A large throne rests in shambles
at the east end of the chamber, its shattered parts jutting above the
dust.
EndText
  );
set("arena", 1);
  set( "exits", ([
"north" : MAIN+"/phalln1.c",
"south" : MAIN+"/phalls1.c",
"east" : MAIN+"/preproom.c",
"west" : MAIN+"/room6'5.c",
  ]) );
set ("item_desc", ([
 "floor" : "It is covered in dust. The crack extends into this room and ends\n"+
   "just before the east wall.\n",
"murals" : "They depict beautiful crystal grottoes and subterranean
waterfalls.\n",
"doors" : "They have been shattered by the magics which opened the ground
here.\n",
"dust" : "It is quite thick, and is getting rather choking.\n",
"throne" : "It is an ancient stone throne, and is utterly destroyed.\n",
  ]) );
  }
