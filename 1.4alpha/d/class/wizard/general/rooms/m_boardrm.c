/*
** The mage's board room.
** Cy whipped up 27 Noc 97 (Happy Thanksgiving!)
*/

#include <config.h>
#include <mudlib.h>
#include "guildhall.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short", "The Mages' Board Room.") ;
  set( "long", @EndText
You are resting comfortably in the Wizard's Lounge, where much talk of
magic and spell theory has passed in the last hundred or so years since
the University's founding.
Several comfortable couches and armchairs are arranged around the room -
especially around the ornate fireplace.
EndText
  );
  set( "exits", ([
     "south" : RM_MAGES+"m_lobby.c",
  ]) );
  call_other("/d/class/wizard/general/obj/m_board", "dummy"); 
}

void init() {
}

int receive_object(object ob) {
   if (living(ob)) {
      if (wizardp(ob)) return 1;
      if (ob->query_level("wizard")) return 1;
      tell_object(ob, "You hit an invisible wall of force.\n"+
         "A voice tells you: Only mages may enter this place.\n");
      return 0;
   }
   return 1;
}
