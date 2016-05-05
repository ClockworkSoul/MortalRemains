
//coded by Aurora 11/15/94

#include <std.h>
inherit OBJECT;


mixed *query_auto_load(){
	return({"/wizards/aurora/obj/key.c", ({}) });
}

void init() {
   ::init();
   add_action("luv","luv");
	add_action("mote","mote");
   add_action("cho","cho");
}

void create () {
	::create();
	set("id", ({"key", "golden key"}));
	set("short","A golden key");
	set("long","A golden skeleton key with a heart shaped handle "
	"which shines warmly in the light.  This is a very special key "
	"for there is only one lock it can fit, and only one person "
	"who holds this key.  There is something inscribed on the handle.\n");
	set("read","Jeremy, hon, please get in touch with me as soon "
	"as you can, we really need to talk.  I don't hate you, and "
	"i'm sorry you left with us on such bad terms, but there "
	"are a few things we need to talk about very soon and "
	"very seriously.  \n            -Annette "
	);
	}

int luv(string str)
{
	if(!find_player("aurora"))
	{
	write("Though she loves you with all her heart, Annette "
		"isn't here right now to hear you.");
	return 1;
	}
	tell_object(find_living("aurora"), "%^CYAN%^Jeremy tells you: %^MAGENTA%^"+str+" %^RESET%^");
	write("%^CYAN%^You tell Annette: "+str+"%^RESET%^ ");
return 1;
}
int mote(string str)
{
	if(!find_player("aurora"))
	{
	  write("Though she loves you with all her heart, Annette "
		"is not here, but she sends you a giant hug and "
		"a tender kiss, and hopes you'll be on when she "
		"finally does get back.");
	return 1;
	}
	tell_object(find_living("aurora"), "%^CYAN%^Jeremy "+str+" %^RESET%^");
	write("%^CYAN%^You mote to Annette: %^MAGENTA%^Jeremy "+str+" %^RESET%^");
return 1;
}
int cho(string str)
{
	if(!find_player("aurora"))
	{
	write("Though she loves you with all her heart, Annette "
	      "is not here to get yer echo.");
	return 1;
	}
	tell_object(find_living("aurora"), "%^CYAN%^ "+str+" %^RESET%^");
	write("%^CYAN%^You echo to Annette: %^MAGENTA%^ "+str+" %^RESET%^");
	return 1;
}
