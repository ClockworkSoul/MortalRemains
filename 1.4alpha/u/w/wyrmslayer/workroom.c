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
set("short","Wyrmy's Lab");
set("long",@End
     This is the lab and home of the greatest flappywiz of all
time, Wyrmslayer the flappy.  It is here that he crashes the mud
and breaks code, and it is here that players sometimes meet
their death when accidents occur.  Be wise to be careful
and tread carefully while here.

An altar sits here.
End);
  set( "exits", ([
    "start" : START,
    "cyan":"/u/c/cyanide/workroom.c",
  ]) );
    set("item_desc",(["altar":"The altar says to kneel for a blessing.\n"]));
}
void init()
{
    add_action("do_kneel","kneel");
}
int do_kneel(string arg)
{
   if(!arg) return notify_fail("You must kneel before wyrmslayer.\n");
   if(arg != "before wyrmslayer")
      return notify_fail("kneel before wyrmslayer!\n");
    message("say","You kneel before the mighty Wyrmslayer and "
      "he blesses you with kindness.\n",this_player());
    message("say",this_player()->query("cap_name")+" kneels before "
      "Wyrmslayer and gains his kindness.\n",environment(this_player()),({this_player()}));
    return 1;
}
