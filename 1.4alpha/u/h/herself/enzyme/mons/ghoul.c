
#include <mudlib.h>
inherit MONSTER;
#include "area.h";

void create(){
    ::create();
    set("author" , "enzyme");
    set_name("ghoul");
    set("prevent_summon" , 1);
    set("id" , ({"ghoul" , "ghoulish" , "ghoulish figure" , "figure"}) );
    set("short" , "a ghoulish figure");
    set("long" , wrap(
	"You see a misty figure of what appears to be a "+
	"decaying man dressed in a runed hooded robe. "+
	"His form seems to shift in and out of focus "+
	"as he slowly moves toward you. Two small greenish "+
	"flames burn where his eyes once were. You begin to "+
	"wonder if you should let yourself be seen by such a thing! "
      ));
    set("race" , "undead");
    set("undead" , 1);
    set("gender" , "male");
    set("damage" , ({2,5}) );
    set("weapon_name" , "fists");
    set_verbs( ({"hit" , "slam into" , "pound on" , "pummel"}) );
    set_level(random(17)+3);
    wear(PATH+"armour/robes.c");
}
