#include <config.h>
#include <mudlib.h>
#include "sigil.h"
#include  "/d/class/warrior/general/rooms/fighter_guild.c"
inherit ROOM;

void create(){
  ::create();
  seteuid( 0 );
  set( "light", 1 );
set("short","Fighter Proficiency Training Hall.");
  set( "long", @EndText
This is the Great hall of fighters where you can select 
your fighter proficiencies.
Commands are: list , select <prof name>, join fighter
EndText
  );
  set( "exits", ([
"north" : SIGIL+"mainst3.c",
  ]) );
}
