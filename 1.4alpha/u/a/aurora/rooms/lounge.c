
// This file was created by Aurora
// For Paradox II  Fri Oct 21 11:50:14 1994
// Please do not remove this header file.

#include <std.h>
inherit ROOM;

	string name;


void create()  {
	::create();
	set_property( "indoors", 2 );
	set_property("light",2);
	set_short("Aurora's lounge");
	set("long", @LONGTEXT

This is just a simple lounge with comfy looking chairs and sofas
scattered around the room.  There are also big fluffy pillows 
piled around the room for those who might prefer to sit on the floor.
LONGTEXT
     );
	set_items( ([
		"sofas"  :  "Big comfortable sofas, in many different colors.  Why don't you try one out?",
		"pillows"  :  "They are scattered around the room.",
	]) );
	set_exits( ([
		"east" : "/wizards/aurora/workroom.c",
	"closet" : "/wizards/aurora/rooms/storage.c",
        ]) );
        }         
 
 
void init() 
        {
        ::init();
		name = (string)this_player()->query_name();
switch(name) {
	case "aurora": write("Welcome Home!");break;
	case "abraxas": write("You are welcome in Aurora's lounge, Abraxas.");break;
	case "aurelius": write("You are welcome in Aurora's lounge, Aurelius.");break;
	case "bill": write("Yer always welcome in Aurora's lounge Bill!");break;
       case "beans": write("Heya Beans!");break;
	case "brand": write("You are welcome in Aurora's lounge, Brand.");break;
           case "dakota": write("Heya Dakota.  C'mon in and make yerself at home. ");break;
         case "daymax": write("Heya Daymax, c'mon in!");break;
	case "electa": write("Heya Bernie, i'll code a counter for ya ;>");break;
	case "gideon": write("You are welcome in Aurora's lounge, Gideon.");break;
	case "layertes": write("Heya Sexy!");break;
case "malhavok": write ("Heya Jake, c'mon in and make yerself comfortable =).");break;
case "sindy": write ("Bleh");break;
	case "ouija": write("You are welcome in Aurora's lounge, Ouija.");break;
	case "quark": write("Heya Quark!");break;
         case "robin": write("Come snuggle with me, sexy! *grin*");break;
	case "sage": write("You are welcome in Aurora's lounge, Sage.");break;
	case "sithlord": write("You are welcome in Aurora's lounge, Sithlord.");break;
	case "scooter": write("Heya hon, c'mon in =).");break;
	case "suave": write("Heya Suave, c'mon in, make yerself comfortable.");break;
   case "trip": write("Heya, c'mon in =).");break;
	case "vedder": write("Ok, just please put yer skirt on again? Please?");break;
	case "venger": write("You are welcome in Aurora's lounge, Venger.");break;
	case "malc": write("You are welcome in Aurora's lounge, Malc.");break;
	case "darkness": write("Heya, c'mon in, have a seat, make yerself at home...");break;
	case "winter": write("You are welcome in Aurora's lounge, Duckie ;> ");break;
	case "dalamar": write("Heya sexy, yer always welcome here! ;> ");break;
	case "scoob": write("SCOOBY DOOBIE DOO!!! WHERE ARE YOU??? Oh, yer here *grin* ");break;
	case "nurgle": write("Heya Corum, i'm glad yer back =)");break;
	case "moz": write("Heya Moz, make yerself at home.");break;
	case "steve": write("You are most welcome in Aurora's lounge, Steve.");break;
	default: this_player()->move("/wizards/aurora/workroom.c");
        }
}

