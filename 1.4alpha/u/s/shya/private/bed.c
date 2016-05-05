//Created by Shya July 2, 2000.//

#include <config.h>
#include <mudlib.h>

inherit OBJECT;
object pillow;
    
 void init() {
 add_action("sit_func", "sit");
 add_action("lay", "lay");
 add_action("pillow_fight", "hit");
 add_action("nibbleinch", "inchnibble");
}

int sit_func ( string str )
{
string dowhat;
string towhat;

if (!str) {
    write("Sit towhat?\n");
    return 1;
}
if (sscanf(str, "%s %s", dowhat, towhat) ==2 ) {
    if (towhat == "bed") {
        if (dowhat == "on")
            write ("You sit on the bed.\n");
        else if (dowhat == "in")
            write ("You climb into the bed.\n");
        return 1;
    }
   return 0;
}
}
int lay(string str)
{
object victim;

if (!str) {
	write ("Do what with who?\n");
   return 1;
}

victim = present(lower_case(str), environment(TP));
    if (!victim) {
	write("That person isn't here with you!\n");
	return 1;
    }
    write(wrap(
	"You lay on the bed in a provocative pose and invite your partner to join you.\n"
	));
    say(TPN+" invites "+victim->query("cap_name")+" to join "+objective(TP->query("gender"))+" in bed.\n");
   
   return 1;
}



int pillow_fight(string str) {
object victim;

if (!str) {
	write ("Have a pillow fight with who?\n");
   return 1;
}
 victim = present(lower_case(str), environment(TP));
    if (!victim) {
	write("That person isn't here with you!\n");
	return 1;
    }    
write(wrap(
	"You start a pillow fight with "+
       victim->query("cap_name")+".\n"));
   say(wrap(
	TPN+" hits "+victim->query("cap_name")+" in the face with a multi-colored pillow.\n"));
    return 1;
}

int nibbleinch(string str) {
object victim;
 
if (!str) {
	write ("Nibble every inch of who?\n");
   return 1;
}

victim = present(lower_case(str), environment(TP));
    if (!victim) {
	write("That person isn't here with you!\n");
	return 1;
}
 write(wrap(
	"You nibble every inch of "+victim->query("cap_name")+"'s body.\n"));
   say(wrap(
	TPN+" nibbles every inch of "+victim->query("cap_name")+"'s body.\n"));
    return 1;
}
void create()
{
    seteuid( getuid() );
    set("light", 1);
    set("author", "shya");
    set ("id", ({"bed"}) );
    set("name", "bed");
    set("short", "Bed" );
    set("long",@EndText 
This four-post kingsize bed takes up the rest of the room
the hottub doesn't. You feel tempted to relax a little 
so go ahead lie down. On top of the bed are multi-colored 
pillows galore.
EndText
    );
    set( "item_desc", ([
	"pillows" :"Light and fluffy and multi-colored, good enough for a pillow fight.\n",
      "pillow" : "Light and fluffy and multi-colored, good enough for a pillow fight.\n"
]));
    pillow=clone_object("/u/s/shya/private/pillow.c");
    pillow->move(this_object());


}

