// Cyanide's library.
// He likes it here.
// Cyanide coded it, January 10th, 2000

#include "main.h"

inherit MAIN+"/palacestd.c";

int aquarium_broke = 0;
object aquarium;

void create() {
    ::create();
    set("short", "Cyanide's Personal Library");
    set("long", "@@query_long");
    set("exits", ([
      "west" : MAIN+"/spire1.c"
    ]) );
    set("smell", "It smells a bit like chlorine.\n");
    set("item_desc", ([
      "library" : "You're standing within it.\n",
      "floor" : "Black marble polished to a mirror-like shine.\n",
      "shapes" : "With few exceptions, they are rectangular.\n",
      "sizes" : "From very small, to table-sized.\n",
      "ceiling" : "It is nothing special.\n",
      "something else" : "You may wat to look at the aquarium.\n",
      "books" : wrap("They contain titles such as \"Evil Geniuses For "+
	"Dummies\", and a whole section of books by a publisher "+
	"called \"O'Reilly\"."),
      "glass" : "@@query_glass_desc",
      "water" : "@@query_glass_desc",
      "aquarium" : "@@query_aquarium_desc",
      "serpent" : "@@query_serpent_desc",
      "sea serpent" : "@@query_serpent_desc",
"fish" : "Very relaxing to watch them.\n",
    ]) );
    set("pre_exit_func", ([
      "east" : "aquarium_enter",
    ]) );
}

void init() {
    add_action("break_cmd", "break");
    add_action("throw_cmd", "throw");
}

int break_cmd( string arg ) {
    if (!arg || arg=="") {
	write("Break what?\n");
	return 1;
    }

    if (arg=="aquarium" || arg=="glass") {
	write(wrap("You have no effect. You would probably have to "+
	    "throw something at the glass to actually break it."));
	say(TPN+" tries to break the glass, but has no effect.\n");
    } else {
	write("You can't break that.\n");
    }

    return 1;
}

int throw_cmd(string arg) {
    string arg2;
    object ob;
    int flag;

    if (!arg || arg=="" ||
      sscanf(arg, "%s at %s", arg, arg2)!=2) {
	write("Throw what at what?\n");
	return 1;
    }

    ob = present(arg, TP);

    if (!ob) {
	write("You have no \""+arg+"\" to throw!\n");
	return 1;
    } else {
	if (ob->query("prevent_drop") || 
	  ob->query_auto_load()) {
	    write("You wouldn't want to part with that.\n");
	    return 1;
	}
    }

    if (arg2!="aquarium" && arg2!="glass" && arg2!="tank") {
	write("You can't throw anything at that.\n");
	return 1;
    }

    if (aquarium_broke) {
	write("It's already been shattered!\n");
	return 1;
    }

    if (!aquarium)
	aquarium = find_object_or_load(MAIN+"/aquarium.c");

    if ((int)ob->query("mass") < 2 ||
      !aquarium) {
	write(wrap("You hurl the "+arg+" with all your might, "+
	    "but it simply bounces off the glass."));
	say(wrap(TPN+" throws "+article(arg)+" "+arg+" at the "+
	    "aquarium glass, but it just bounces off.") );
	ob->move(TO);
    } else {
	write(wrap("You hurl the "+arg+" with all your might, "+
	    "shattering the glass instantly and freeing the "+
	    "sea serpent!"));
	say(wrap(TPN+" throws "+article(arg)+" "+arg+" at the "+
	    "aquarium glass, shattering it instantly and freeing "+
	    "the sea serpent!"));

	ob->move(aquarium);
	ob = clone_object(MONST+"/baby.c");
	ob->set("chat_output", ({
	  "The baby serpent gasps for breath.\n",
	  "The serpent flounders around on the library floor.\n"
	}) );
	ob->move(TO);
	add("exits", ([ "east" : MAIN+"/aquarium.c" ]) );
	aquarium_broke = 1;
    }
    return 1;
}

string query_long() {
    string str = "You have entered Cyanide's personal library. Hundreds of "+
    "books in all manners of shapes and sizes line almost every "+
    "wall from black marble floor to the thirty foot ceiling. Inset "+
    "into the far east wall is a very large aquarium";

    if (aquarium_broke)
	str += ", which appears to have been shattered by some unknown "+
	"vandal. Broken glass and water is lying everywhere.";
    else
	str += ", which seem to contain something else very large.";

    return wrap(str);         
}

string query_aquarium_desc() {
    string str;

    if (aquarium_broke)
	str = "It is shattered, and broken glass is lying everywhere.";
    else
	str = "It is huge - several thousand gallons. It contains "+
	"many species of tropical fish, and one very large "+
	"sea serpent.";

    return wrap(str);
}

string query_glass_desc() {
    if (aquarium_broke) 
	return wrap("It appears that somebody has smashed "+
	  "the giant fishtank that was inset into the east wall, "
	  "leaving a large gap.");
}

string query_serpent_desc() {
    if (!aquarium_broke)
	return "It doesn't look very friendly.\n";
}

int aquarium_enter() {
    if (!aquarium)
	aquarium = find_object_or_load(MAIN+"/aquarium.c");

    if (aquarium_broke && aquarium) {
	return 0;
    } else {
	tell_object(TP, "Enter the aquarium?  You must be mad!\n");
	return 1;
    }
}

/* EOF */
