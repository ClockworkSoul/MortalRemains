#include <config.h>
#include <mudlib.h>
#include "../ancients.h"

inherit ROOM;

object maker;

void create()
{
  ::create();
    seteuid(getuid());
  set( "light", 1 );
  set("short", "The Player's Hall");
  set( "long", @EndText
This is the Player's Hall where, in lieu of a town or something,
the players begin...

If you would like to create areas and whatnot for us, please feel
free to post at the board here, and/or use the post office to you
east to mail "admin".   
EndText
  );
  set( "exits", ([
  ]) );
   set ("item_desc", ([
   ]) );
  call_other("d/Ancients/obj/player_board.c", "foo");
reset();
}
