// Changed, Dec 25, 1994 by Aurora, for herself, but original code
// is from Mirabella's workroom, changed by Venger.

#include <std.h>
inherit ROOM;
#define TPCN   this_player()->query_cap_name()
  string name;
  int allow;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("pking",1);
	set("short", "The Bedroom");
    set("long",
"You have entered a cozy looking bedroom.  The floor is covered in "
"a plush mauve carpet, so soft it makes you want to run your bare feet in it.  Off "
"in the corner is a large king size bed covered in a floral comforter and piles of pillows.  "
"The bed is so big it looks like you could almost fit three people in "
"it!  On the walls are various wall hangings, but the main focus of "
"this room is that great big bed."
    );
    set_exits( 
        ({
            "/d/central/field", "/d/school/classrm", 
            "/d/standard/square", "/d/standard/post",
	  "/wizards/aurora/workroom.c"
        }),
        ({
	"central","class","square","post","south"
        })
    );
    set_items ( ([
	"bed" : "A huge king size bed which looks very inviting.",
	"carpet" : "So soft it makes you wanna run your toes in it.",
	"comforter" : "A gorgeous floral comforter.",
	"pillows" : "There are a whole bunch of pillows on the bed.",
	"hangings" : "They compliment the comforter.",
        ]) );
}

init() {
   ::init();
   add_action("cmd_emote", "emote");
   add_action("cmd_emote", "em");
   add_action("cmd_echo", "echo");
   add_action("cmd_echo_to", "to");
  add_action("toggle_allow", "allow");
  name=(string)this_player()->query_cap_name();
   say("Hey, look who's here! It's "+name+".");

  switch (name) {

case "Aurora" :
    break;
 case "Robin" :
   break;
  default : {
            if (allow) {
               write ("Welcome!");
            } else { 
                write("Sorry, you can't come in now.  Maybe try again later.");
		this_player()->move("/wizards/aurora/workroom");
             }
            }
   }
}

int toggle_allow(string str) {
	if((string)this_player()->query_name() == "aurora") {
           allow ^= 1;
           if (allow) {
              write ("The room is opened.");
              say ("The room is able to be entered.");
           } else {
              write ("The room is closed.");
              say ("The room may not be entered by others.");
            }
       }
             return 1;
}

cmd_emote(str) {
   if(!str) {
     write(TPCN+"\n");
     say(TPCN+"\n");
     return 1;
   }
   tell_room(this_object(), TPCN+" "+str+"\n");
   return 1;
}

cmd_echo(str) {
   if(!str) return 0;
   tell_room(this_object(), str+"\n");
   return 1;
}

cmd_echo_to(str) {
string what, what2;
object who;
   if(!str) {
     write("Format:   to <player> <echo>\n");
     return 1;
   }
   if(sscanf(str, "%s %s", what, what2) != 2) return 0;
   who = find_player(what);
   if(!who) {
     write("No such person.\n");
     return 1;
   }
   tell_object(who, what2+"\n");
   write("You echoed to "+capitalize(what)+": "+what2+"\n");
   return 1;
}
