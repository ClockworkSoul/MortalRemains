// Cyanide made this some time in 1996 for AFD.  Here now.  ;)

#include <mudlib.h>
#include "main.h"

inherit ROOM;

#define GO(x) TP->move("x")

int toggle = 0, dial = 1, clock = 1;
string tog_st = "off", dial_st = "A", teleport = "offA1";

void strs();
string query_long();

void create() {
    ::create();
    seteuid(getuid());
    set ("light", 1);
    set ("author", "cyanide");
    set ("short", "Cyanide's Laboratory");
    set ("long", "@@query_long");
    set("exits", ([
      "west" : MAIN+"/southshore.c",
    ]) );
    toggle = random(2);
    dial = random(3)+1;
    clock = random(12)+1;
    strs();

}

void init() {
    add_action("switch_func", "set");
    add_action("switch_func", "switch");
    add_action("teleport_func", "press");
}

void strs() {
    switch(toggle) {
    case 0 : tog_st = "off"; break;
    case 1 : tog_st = "on"; break;
    default : tog_st = "ERROR"; break;
    }

    switch(dial) {
    case 1 : dial_st = "A"; break;
    case 2 : dial_st = "B"; break;
    case 3 : dial_st = "C"; break;
    default : dial_st = "ERROR"; break;
    }

    set ("item_desc", ([
      "dial" : "It is currently set to \""+dial_st+"\".\n",
      "switch" : "It is currently set to \""+tog_st+"\".\n", 
      "toggle" : "It is currently set to \""+tog_st+"\".\n",
      "clock" : "It is currently set to \""+clock+"\".\n",
      "button" : "It is labelled \"DO NOT PRESS!\".\n",
    ]) );
}

string query_long() {
    string str;
    str= "You have entered Cyanide's Laboratory, which is filled with a"+
    " great variety of technological wonders and horrors, all of which"+
    " are buzzing and crackling with electricity - but a panel on the"+
    " wall especially catches your attention.\n"+
    "The panel has 3 switches which stand out prominantly: an on/off "+
    "toggle switch (set to \""+tog_st+"\"), a triangle dial (set to \""+
    dial_st+"\"), and a clock (set to \""+clock+"\"). You could "+
    "possibly \"switch\" them...\n"+
    "There is also a big red button just below the three switches.";

    return wrap(str);
}

int teleport_func() {
    string path;

    teleport = tog_st+dial_st+(string)clock;

    switch(teleport) { 
    case "onA1" : path="/d/Prime/Cyanide/area1/a1forest08.c"; break;
    case "onA3" : path="/d/Planar/Baator/phlegethos/city22.c"; break;
    case "onA6" : path="/d/Prime/Cyanide/area2/LOS05.c"; break;
    case "onA7" : path="/d/Prime/Park/room/statue1.c"; break;
    case "onA10" : path="/d/Prime/Macrosoft/3/office1w.c"; break;
    case "onB3" : path = "/d/Planar/Baator/stygia/styx3.c"; break;
    case "onB8" : path="/d/Planar/Baator/maldomini/mal6.c"; break;
    case "onB10" : path="/d/Planar/Baator/minauros/bog4.c"; break;
    case "onC1" : path = "/d/Prime/Macrosoft/2/cube02n.c"; break;
    case "onC5" : path="/d/Prime/Macrosoft/1/l_stall.c"; break;
    case "onC6" : path="/d/Planar/Baator/dis/dplain23.c"; break;
    case "offA1" : path="/d/Prime/Cyanide/area2/lair.c"; break;
    case "offA2" : path="/d/Planar/Baator/malbolge/mal23b.c"; break;
    case "offA3" : path="/d/Prime/Cyanide/area3/maze5.c"; break;
    case "offA9" : path = "/d/Prime/Macrosoft/4/e3.c"; break;
    case "offA11" : path = "/d/Planar/Baator/avernus/fortbel17.c"; break;
    case "offB12" : path="/d/Prime/Sewers/room/sewer52.c"; break;
    case "offC4" : path="/d/Prime/Cyanide/anthill/ants2.c"; break;
    case "offC9" : path = "/d/class/wizard/general/rooms/mage_guild.c"; break;
    default : 
	write ("You hear a crackling sound and catch a whiff "+
	  "of ozone.\nNothing happens.\n");
	say ("You hear a crackling sound and catch a whiff of "+
	  "ozone.\n");
	return 1; 
	break;
    }

    say("There is a brilliant burst of white light!\n"+
      "When your vision clears, "+TPN+" is gone!\n");

    write("There is a brilliant burst of white light!\n"+
      "Suddenly, you find yourself in...\n\n");

    TP->move_player(path, "SNEAK");

    say(TPN+" suddenly appears in a flash of bright light!\n");

    return 1;
}

int switch_func(string str) {
    string str2, name;

    if (!str) {
	write("Syntax: 'switch [clock|dial|toggle] to [setting]'\n");
	return 1;
    }
    sscanf (str, "%s to %s", str, str2);

    // Silly, lazy hack.
    if (str=="switch") str = "toggle";

    if (str!="clock"&&str!="toggle"&&str!="dial") {
	write ("Switch what to what?\n"); 
	return 1; 
    }

    switch (str) {
    case "toggle" :
	name = "toggle switch"; 
	switch(str2) {
	case "on" : toggle = 1; break;
	case "off" : toggle = 0; break;
	default : write("Switch toggle to [on|off].\n");
	    return 1; 
	    break;
	}
	break;
    case "dial" :
	str2 = capitalize(str2);
	name = "triangular dial";
	switch(str2) {
	case "A" : dial = 1; break;
	case "B" : dial = 2; break;
	case "C" : dial = 3; break;
	default : write ("switch dial to [A|B|C].\n");
	    return 1; break;
	}
	break;
    case "clock" :
	switch(str2) {
	case "1" : clock = 1; break;
	case "2" : clock = 2; break;
	case "3" : clock = 3; break;
	case "4" : clock = 4; break;
	case "5" : clock = 5; break;
	case "6" : clock = 6; break;
	case "7" : clock = 7; break;
	case "8" : clock = 8; break;
	case "9" : clock = 9; break;
	case "10" : clock = 10; break;
	case "11" : clock = 11; break;
	case "12" : clock = 12; break;
	default : write ("Switch clock to [1..12].\n");
	    return 1; 
	    break;
	}
	name = "clock"; 
	break;
    default :
	write ("Switch [toggle|dial|clock] to [value].\n");
	return 1;
	break;
    }

    write ("You set the "+name+" to "+str2+".\n");
    say (TPN+" plays with the "+name+" on the control panel.\n");
    strs();
    return 1;
}

/* EOF */
