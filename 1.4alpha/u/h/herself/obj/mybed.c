
#include <mudlib.h>


inherit OBJECT ;

void create() {
    seteuid( getuid() );
    set("author" , "Herself");
    set("id" , ({"bed" , "canopy bed" , "white canopy bed"}) );
    set("short" , "a white canopy bed");
    set("long" , wrap(
	"It is a white brass canopy bed. King sized. "+
	"The canopy is white lace, and flutters slightly "+
	"in the breeze from the open windows here. The "+
	"bedspread is white as well, a silky looking "+
	"material. At the head of the bed are many "+
	"fluffy pillows, you may try to get one. "+
	"The bed looks so comfortable... you just might "+
	"lay down. "
      ));
    set("mass" , 1000);
    set("prevent_get", 1);
}
void init() {
    add_action ("lay_down" , "lay");
    add_action ("get_pillow" , "get");
    add_action ("jump_bed" , "jump");
    add_action ("cuddle_someone" , "cuddle");
}
int lay_down (string str) {
    if(!str) {
	write ("Lay where?\n");
	return 1;
    }
    write(wrap(
	"You lay down on the bed..... It's so comfortable\n"+
	"that you never want to get up.\n") );
    say(wrap(
	TPN+" lays down on the bed... It \n")+
      "looks so comfortable, you want to do the same. \n");
    return 1;
}
int get_pillow (string str) {
    object pillow;
    if(!str) {
	return 0;
    }
    pillow = clone_object("/u/h/herself/obj/pillow.c");
    say(wrap(
	"With an evil giggle, "+TPN+" grabs a pillow off of the bed.\n") );
    write(@EndText
You grab a fluffy white pillow off of the bed.
EndText);
    pillow->move(this_player());
    return 1;
}
int cuddle_someone (string str) {
    object ob;
    if(!str) {
	return 0;
    }
    ob = present(str, environment(TP));
    if (!ob) {
	write ("Cuddle with who? \n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That person isn't here! \n");
	return 0;
    }
    write(wrap(
	"You invite "+ob->query("cap_name")+" into the bed with you. "+
	"The two of you snuggle up together for hours... \n"));
    say(
      TPN+" pulls "+ob->query("cap_name")+" into the bed with "+
      objective(TP->query("gender"))+" and the two of them snuggle "+
      "together under the blanket. \n", ({ob}) );
    tell_object(ob, wrap(
	TPN+" pulls you into the bed with "+objective(TP->query("gender"))+
	", "+subjective(TP->query("gender"))+" snuggles up next to you "+
	"under the blanket. \n"));
    return 1;
}
int jump_bed(string str) {
    if(!str) {
	write ("Jump on what?\n");
	return 1;
    }
    write(
      "You leap up onto the bed and jump around like a little kid!\n");
    say(wrap(
	TPN+" leaps up onto the bed, and jumps around "+
	"just like a little kid! \n"+"Doesn't that look like fun? \n"));
    return 1;
}
