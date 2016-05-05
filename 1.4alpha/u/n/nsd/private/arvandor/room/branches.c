/*
** File: branches.c
** Author: Lady Nsd
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

int butterfly_flag;

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Top of the tower");
    set( "long", @EndText
This is the top of the tower. There's nothing more to see,
except for the multiple branches of the oak tree you're in.
You can see some innoffensive caterpillars devouring the
few leaves that remain in the branches. Looking closer, you
notice there are chrysalises hanging from the branches.
EndText
    );
    set( "exits", ([
      "down" : ARV_ROOM+"seelietower4.c",
      "jump" : ARV_ROOM+"seeliecourt3.c",
    ]) );
    set("item_desc", ([
      "branches" : "Broad branches with few leaves. Some caterpillars are\n"+
      "stepping on them. There are chrysalises hanging from them.\n",
      "caterpillars" : "Plump caterpillars that devour the remaining leaves.\n",
      "chrysalises" : "Dark and translucent chrysalises. They have small\n"+
      "vessels. One of them is moving. 'Check' the 'moving' one.\n",
    ]) );
    butterfly_flag = 1;
}
void init() {
    add_action("check_moving_chrysalis", "check");
}
int check_moving_chrysalis (string str) {
    object butterfly;
    butterfly = clone_object(ARV_MON+"butterfly2.c");
    if (butterfly && butterfly_flag) {
	write("The chrysalis cracks and a butterfly attacks you!\n");
	say("The chrysalis cracks and a butterfly attacks "+TPN+"!\n");
	butterfly->move(this_object() );
	butterfly->kill_ob(this_player() );
	butterfly_flag = 0;
    }else
	write("That chrysalis is empty!\n");
    return 1;
}
void fix_flag() { butterfly_flag = 1; }
/* EOF */
