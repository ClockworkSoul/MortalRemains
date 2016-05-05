// pub.c
// Written by Mobydick@TMI-2, 11-7-92
// This room is not connected to the rest of Footown.
// It implements a pared-down version of the Lars pub.
// The main differences are: no hangovers, and drunkenness doesn't impair
// ones combat abilities.
// A large majority of people at TMI don't like the current system of
// getting drunk for healing, and there was some debate over whether we
// ought to include a pub in the package at all. In the end we decided that
// we ought to put one in since many people would want it, but we would
// also provide an alternative system of healing. You should find several
// other healing objects in this mudlib: the heal spell, and the bandages
// object and the elixir object in /obj. You can also write a hospital or
// some other room where players can buy healing for gold, but don't have
// the drunkenness associated with it. It is quite possible to create a
// MUD without pubs and still provide adequate healing for players. Think
// about it when you are designing your MUD.

#include <money.h> 
#include <config.h>
#include <mudlib.h>

inherit ROOM ;

void create() {
    ::create();
    set ("light", 1) ;
set("short", "The Talisman Tavern");
    set("long",@Endtext
The Talisman Tavern. This place is where everyone comes to get
drunk and relieve some tension. The place is very crowded with
serving maids running all over the place trying to deliver
fresh mugs so no one gets too excited. There are two huge
bouncers standing by the doors to make sure no trouble starts
in here.
Endtext
    );
    set("exits", ([
      "north" : "/d/Prime/Krynn/Duegne/road5.c",
      "east"  : "/d/Prime/Krynn/Duegne/road4.c",
    ]));
    set ("item_desc", ([ "menu" :
      "You can buy the following drinks: \n"+
      "\tGeneric beer:     5 sp\n"+
      "\tWhite wine:       1 gp\n"+
      "\tSipping whiskey:  5 gp\n" ]) ) ;
    seteuid(getuid()) ;
    reset() ;
}

void init() {
    add_action("buy_drink", "buy") ;
}

int buy_drink (string str) {

    int bonus, rate, drunk, res, mh, cost ;
    string type, word, message ;

    if (!str) {
	notify_fail ("The bartender says: What would you like to drink?\n") ;
	return 0 ;
    }
    switch (str) {
    case "beer" : {
	    bonus = 3 ;
	    rate = 2 ;
	    cost = 5 ;
	    type = "silver" ;
	    message = "You down a generic beer, and immediately wish you hadn't." ;
	    break ;
	}
    case "wine" : {
	    bonus = 5 ;
	    rate = 5 ;
	    cost = 1 ;
	    type = "gold" ;
	    message = "The wine goes down about as well as a Mongolian chardonnay can." ;
	    break ;
	}
    case "whiskey" : {
	    bonus = 10 ;
	    rate = 8 ;
	    cost = 5 ;
	    type = "gold" ;
	    message = "You take a sip of the whiskey and nearly vomit, but you manage to hold it down." ;
	    break ;
	}
    default : {
	    notify_fail ("We don't sell that here!\n") ;
	    return 0 ;
	}
    }
    drunk = this_player()->query("drunk") ;
    if (drunk>24-bonus) {
	write ("The bartender looks at you and says: I think you've had enough.\n") ;
	return 1 ;
    }
    res = this_player()->query("wealth/"+type) ;
    if (res<cost) {
	if (cost==1) word = "coin" ; else word = "coins" ;
	notify_fail ("That costs "+cost+" "+type+" "+word+", which you don't have.\n") ;
	return 0 ;
    }
    this_player()->set("wealth/"+type,res-cost) ;
    res = this_player()->query("capacity") ;
    this_player()->set("capacity", res+cost) ;
    res = this_player()->query("hit_points") ;
    res = res + bonus ;
    mh = this_player()->query("max_hp") ;
    if (res>mh) res=mh ;
    this_player()->set("hit_points",res) ;
    this_player()->set("drunk",drunk+rate) ;
    write(message+"\n") ;
    return 1 ;
}
