#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
    ::create();//<- gets all the information from the original create()
    seteuid( getuid());
    set ("light", 0);
    set("short", "Stagnant Pool");
    set( "long", @EndText
You are floating on the surface of a black, evil smelling pool.
Bodies and other debris float atop the water as well as
below the surface. Building stones and other debris have tumbled
this way and can be seen jutting from the murky, black pool.
EndText
    );
    set( "exits", ([
      "northwest" : MAIN+"/room7'4.c",
      "dive" : MAIN+"/room3'9",
    ]) );
    set ("exit_suppress", ({"dive"}) );
    set ("exit_msg", ([
      "dive" : "$N takes a risk and dives into the black pool.\n",
    ]) );
    set ("item_desc", ([
      "bodies" : "They seem ancient, and dissolve at your touch.\n",
      "debris" : "Mostly chunks of wood and dead vermin.\n",
      "stones" : "They are covered with a thick layer of black sludge.\n",
      "pool" : "Yuck...\n",
    ]) );
}

void init () {
    add_action ("dive_func", "enter");
    add_action ("go_func", "go");
    add_action ("nw_func", "northwest");
    add_action ("no_torch", "dive");
}

int dive_func (string str) {
    if (str!="pool" && str!="water") {
	notify_fail("Enter what?\n");
	return 0;
    }
    write (
      "If you want to dive in, just say so.\n");
    return 1;
}

int nw_func () {
    object wet;
    write ("You climb out of the black, smelly waters.\n");
    wet = present("wet_obj", TP);
    if (!wet) {
	wet = clone_object (OBJ+"/wetness.c");
	wet->move(this_player());
    }
    return 0;
}

int go_func (string dir) {
    if (dir!="northwest" && dir!="nw") {
	return 0;
    }
    return nw_func();
}

int no_torch(string str) {
    object torch, stick;
    torch=present("torch",this_player());
    if (!torch) {return 0;}
    torch->remove();
    write ("Your torch goes out!\n");
    stick=clone_object(OBJ+"/wetstick.c");
    stick->move(this_player());
    return 0;
}
