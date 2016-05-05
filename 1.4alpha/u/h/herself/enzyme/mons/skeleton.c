
#include <mudlib.h>;
#include "area.h";
inherit MONSTER;

void create(){
    ::create();
    set("author" , "enzyme");
    set("prevent_summon" , 1);
    set_name("skeleton");
    set("id" , ({"fighter" , "skeleton" , "skeleton fighter"}) );
    set("short" , "a skeleton fighter");
    set("long" , wrap(
	"This is the skeleton of a long dead fighter that has "+
	"been animated by some dark magics. Tiny greenish "+
	"flames burn where his eyes once were. There seems "+
	"to be hatred and evil eminating from it's entire being. "+
	"It moves with unearthly speed and agility. "
      ));
    set("race" , "undead");
    set("gender" , "neuter");
    set("undead" , 1);
    set("wealth" , 100);
    set("damage" , ({1,3}) );
    set("weapon_name" , "boney fists");
    set_verbs( ({"hit" , "pound on" , "beat on" , "pummel"}) );
    wear(PATH+"armour/rags.c");
    arm(PATH+"weapons/haxe.c");
    set_level(13);
}
