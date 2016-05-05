/*
** FIle:  mortuary.c
** The secret entrance to Cyanide;s necromancers guild.
** Idea credit:  Megaweapon
** Credits:
**    26 Jun 98   Cyanide created the file.
*/

#include <mudlib.h>
#include <move.h>
#include "sigil.h"

#define NECRO_GUILD "/d/class/wizard/necromancer/rooms/necro_guild"

inherit ROOM ;

int open = 0;

void create() {
    ::create();
    seteuid(getuid());
    set ("objects", ([ "qaida" : "/d/Outer/Sigil/monsters/qaida" ]) );
    reset();
    set ("light", 1) ;
    set ("long", "@@query_long");
    set ("short", "Mortuary") ;
    set ("exits", ([
      "down"	: SIGIL+"mortuary1.c",
      "north" : SIGIL+"mainst13.c" 
    ]) ) ;
    set("item_desc", ([
      "coffin" : "@@query_coffin",
      "candles" : "They have been burning for quite some time.\n",
      "room" : "It is bare, except for the coffin.\n"
    ]) );
    set("smell", "It reeks of dust in here.\n");
}

void init() {
    add_action("search", "search");
    add_action("open", "open");
    add_action("close", "close");
    add_action("close", "shut");
    add_action("enter", "enter");
}

string query_long() {
    string str = "You are in a dimly lit stone room that "+
    "apparantly serves the purpose of a mortuary. There are "+
    "a few candles lit here and there, and there is an ornate "+
    "coffin lying on a table in the back of the room, "+
    (open ? "wide open." : "closed.");

    return wrap(str);
}

int search (string str) {
    if (str=="coffin" || str=="casket") {
	if (open)
	    write("You could easily \"enter\" it.\n");
	else
	    write("It is simply a closed coffin.\n");
	return 1;
    }
    return 0;
}

string query_coffin() {
    string str = "An ornate coffin of ebony and silver.";
    if (!open)
	str += " It is closed.";
    else {
	str += " It is wide open.";
	if (TP->query_skill("Portal Feel"))
	    str += "\nYou sense a portal within the coffin.";
    }

    return wrap(str);
}

int open_func() {
    if (!open) {
	open = 1;
	return 1;
    }
    return 0;
}

int close_func() {
    if (open) {
	open = 0;
	call_out("movve", 1);
	return 1;
    }
    return 0;
}

void movve() {
    object *obs, coffin;
    int i;

    coffin = children(SIGIL+"coffin.c")[0];  
    obs = all_inventory(coffin);

    for (i=sizeof(obs)-1; i>=0; i--) {
	if (living(obs[i]))
	    obs[i]->move_player(NECRO_GUILD);
	else {
	    if (obs[i]->move(NECRO_GUILD)==MOVE_OK)
		tell_room(NECRO_GUILD, wrap(capitalize(obs[i]->
		      query("short"))+" appears and falls to "+
		    "the ground."));
	}
    }
    return;
}

int close(string str) {
    if (str!="coffin" && str!="casket") return 0;

    if (close_func()) {
	write("You close the coffin.\n");
	say(TPN+" slams the coffin closed.\n");
    } else {
	write("The coffin is already shut.\n");
    }
    return 1;
}

int open(string str) {
    if (str!="coffin" && str!="casket") return 0;

    if (open_func()) {
	write("You open the coffin.\n");
	say(TPN+" opens the coffin.\n");
    } else {
	write("The coffin is already open.\n");
    }
    return 1;
}

int enter(string str) {
    object coffin, *obs;
    int i, flag = 0;

    if (str!="coffin" && str!="casket") return 0;

    if (!open) {
	write("You cannot enter a closed coffin...\n");
	return 1;
    }

     find_object_or_load(SIGIL+"coffin.c");
    if (sizeof(children(SIGIL+"coffin.c")))
	coffin = children(SIGIL+"coffin.c")[0];

    if (!coffin) {
	write("Error. Notify Cyanide.\n");
	return 1;
    }

    obs = all_inventory(coffin);
    for (i=0; i<sizeof(obs); i++)
	if (living(obs[i])) flag = i+1;

    if (flag) {
	write(obs[i-1]->query("cap_name")+
	  " is already lying in the coffin.\n");
	return 1;
    }

    write("You climb into the coffin and lie down.\n");
    say(TPN+" climbs into the coffin and lies down.\n");
    TP->move_player(coffin, "SNEAK");

    return 1;
}

int query_open() { return open; }

/* EOF */
