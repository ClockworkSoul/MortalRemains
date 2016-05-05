/*
** FILE: A room in /d/Prime/Cyanide
** PURPOSE: I high-level area with all sorts of surprises.
**    Quite deadly - methinks.
** CHANGES:
**   Mar-10-95  Cyanide@ERock   Created the file.
**   Oct-15-96  Cyanide@AtFoD   Carried in the tradition.
**   Apr-03-98  Cyanide@NKeep   Cyanide kept - yet again.
*/

#include <mudlib.h>
#include <move.h>

#include "main.h"

inherit MAIN+"/gardenstd.c";

int num_berries = 2;

void create()
{
    ::create();
    seteuid( getuid());
    set ("author", "cyanide");
    set ("light", 1);
    set ("short", "Topiary");
    set( "long", wrap("This is the southern end of a formal "+
	"garden. Hedges hide the palace walls. "+
	"Fantastically shaped hedges and bushes "+
	"are arrayed with geometric precision. They have not recently "+
	"been clipped, but you can discern creatures in the shapes "+
	"of the bushes: there is a dragon, a vampire, a great "+
	"serpent, and a huge misshapen dog. Among the bushes are "+
	"several statues of human figures. On the east side of the "+
	"garden the path leads through a rose arbor into a tunnel"+
	" formed by creeping vines. A garden path leads west."
      ));
    set( "exits", ([
      "north" : MAIN+"/cgarden.c",
      "west" : MAIN+"/garden03.c",
      "east" : MAIN+"/gfountain.c",
    ]) );
    set ("item_desc", ([
      "cyanide" : "There seems to be an odd vine covering the "+
      "statue.\n",
      "statue of cyanide" : "There seems to be an odd vine "+
      "covering the statue.\n",
      "gothmog" : "It looks an awful lot like Ilzarion...\n",
      "statue of gothmog" : "It looks an awful lot like "+
      "Ilzarion...\n",
      "statue" : "Which one?\n",
      "vine" : "@@query_vine",
      "vines" : "They seem to grow as you watch.\n",
      "berry" : "They are bright, bright red.\n",
      "berries" : "They are bright, bright red.\n",
      "garden" : "A very unlikely garden...\n",
      "statues" : wrap("There are seven statues of various "+
	"wizards. The statues of Cyanide and Gothmog seem "+
	"prominant."),
      "bushes" : wrap("There seems to be something odd about them."),
      "bush" : "Which one?\n",
      "hedges" : wrap("There seems to be something odd about them."),
      "vampire" : "It's just a bush clipped into the shape of a vampire.\n",
      "dragon" : "It's just a bush clipped into the shape of a dragon.\n",
      "serpent" : "It's just a bush clipped into the shape of a sea serpent.\n",
      "dog" : "It's just a bush clipped into the shape of a three headed dog.\n",
    ]) );
    set("search_func", ([
      "vine" : "vine",
    ]) );
}

void init() {
    add_action ("killkill","search");
    add_action ("killkill","touch");
    add_action ("pick", "take");
    add_action ("pick", "get");
}

int vine() {
    write("It is covered in berries.\n"+
      "You might want to take one.\n");
    return 1;
}

int pick ( string str ) {
    object berry;

    if (str=="berry" || str=="berries") {
	if (num_berries > 0) {
	    berry = clone_object(OBJ+"/berries.c");
	    if (berry && (berry->move(TP) == MOVE_OK )) {
		num_berries--;
		write("You pick a handfull of red berries.\n");
	    } else {
		write("Error: Notify Cyanide!\n");
	    }
	} else {
	    write("It would seem all the berries have "+
	      "already been plucked from the vine.\n");
	}
    }

    return 1;
}

string query_vine() {
    string str;

    str = "It has dark, shady leaves";

    if (num_berries)
	str += " and bright red berries.";
    else
	str += ". There don't seem to be any berries on "+
	"the vine, however.";

    if (TP->query_skill("Herbalism"))
	str += "\nIt is obviously nightshade. Very poisonous.";

    return wrap(str);
}

int killkill(string str) {
    object plant;
    if (str!="bushes" && str!="shrubs" && str!="toparies") {
	return 0;
    }
    write ("The topiary suddenly comes to life and attacks you!\n");
    plant=clone_object(MONST+"/topiarymon.c");
    plant->move(this_object());
    plant->kill_ob(TP);
    return 1;
}

/* EOF */
