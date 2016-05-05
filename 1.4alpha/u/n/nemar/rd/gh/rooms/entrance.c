/*
** File /u/n/nemar/rd/city/rooms/entrance.c
** Author: Lord Nemar of the Shadoweirs
*/

#include <config.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "author", "nemar" );
  set( "short", "Shadoweir Guild Entrance" );
  set( "long", @EndText
You have entered the base of the tree.  You notice that the room is MUCH larger
then it looks from the outside.  You see a spiral staircase leading up, with
a strange green skinned lady standing at the base.  You see a sign beside the lady.
EndText
  );
  set( "exits", ([
    "up" : "/u/n/nemar/rd/gh/rooms/1stlvla.c",
    "out" : "/u/n/nemar/rd/city/rooms/square2.c",
  ]) );
  set( "item_desc", ([
    "tree" : "The inside walls is perfectly smooth.\n",
    "oak" : "The inside walls is perfectly smooth.\n",
    "ground" : "The floor is perfectly smooth with no apparent scratches.\n",
    "floor" : "The floor is perfectly smooth with no apparent scratches.\n",
    "woman" : "A strange, short, green, and thin woman.\n",
    "finn" : "She is the guardian that prevents all none guild members from wandering the guild.\n",
    "Finn" : "She is the guardian that prevents all none guild members from wandering the guild.\n",
    "entrance" : "An opening large enough to step through.\n",
    "sign" : "****************************************************\n"
             "*          Welcome to the Shadoweir Guild          *\n"
             "*                                                  *\n"
             "* requirements - To see what is required to join   *\n"
             "* join - To join the guild.                        *\n"
             "* leave - To leave the guild.  Loose xp!!!         *\n"
             "*                                                  *\n"
             "*              GUILD IS NOT OPEN YET!              *\n"
             "****************************************************\n"
             "                       ****                         \n"
             "                       ****                         \n"
             "                       ****                         \n"
             "----------------------------------------------------\n",

  ]) );
  set("objects", ([
    "finn" : "/u/n/nemar/rd/gh/mobs/finn.c",
  ]) );
  set("pre_exit_func", ([
    "up" : "nonguild"
  ]) );
  reset();
}

int nonguild() {
  if(present("finn", this_object())) {
    if (this_player()->query_guild_string() == "shadoweir") return 0;
    } else {
    write("You are not a guild member!  You can NOT go up there!\n");
    return 1;
  }
}
