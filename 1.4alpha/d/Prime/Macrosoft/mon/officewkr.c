// A poor lowly office worker.

#include "macrosoft.h"

#define TNAME this_object()->query("cap_name")

inherit MONSTER;

string *attribs = ({ "neck-tied", "clean-shaven", "neat", "sleepy", 
"funny-smelling", "odd tie wearing", "balding", "hard-working",
});

string *names = ({ "bob", "jeff", "joe", "john", "greg", "mike", 
"jim", "george", "matt", "pat", "andre", "steve", "bill",
"wess", "cliff", "clyde", "floyd", "ralph", "dave"
});

string *weaps = ({ "pen.c", "book.c", "stapler.c" });

void create() {
    int attrib1, attrib2 = -1;

    attrib1 = random(sizeof(attribs));  
    attrib2 =  random(sizeof(attribs));
    while (attrib2 == attrib1) attrib2 = random(sizeof(attribs));

    ::create();
    set("long", wrap("This poor office worker seems to have devoted "+
	"his entire life to performing menial and mind-numbing tasks "+
	"for almost no money. Pity him."
      ) );
    set_name( names[ random(sizeof(names)) ] );
    set("author", "cyanide");
    set("short", query("cap_name")+" the office worker");
    set("id", ({ lower_case(query("name")), "worker", 
      "office worker" }) );
    set("gender", "male");
    set("attrib1", attribs[attrib1]);
    set("attrib2", attribs[attrib2]);
    set("race", "zombie");
    set("damage", ({ 1, 4 }) );
    set("undead", 1);
    set("weapon_name", "fists");
    credit(15+random(30));

    //Chats and stuff
    set_verbs( ({ "swing at" }) );

    set("chat_chance", 15);
    set("chat_output", ({   
      TNAME+" says [to you] : Please kill me.\n",
      TNAME+" whispsers to you: They won't let me leave.\n",
      TNAME+" says [to you] : We have really shitty 401k.\n",
      TNAME+" says: The boss makes us touch him!\n",
      TNAME+" says: I really need a better job.\n",
      TNAME+" says: Sometimes, when I'm bad, they put me in The Box.\n",
    }));
    set("att_chat_output", ({
      TNAME+" says: My boss is mentally forcing me to fight you!\n",
      TNAME+" screams: Hurry!  Kill me!\n",
      TNAME+" says [to you]: Is that the best you can do?\n",
      TNAME+" says: C'mon slackass, put your heart into it.\n",
      TNAME+" says [to you]: You fight like a little girl!\n"
    }));


    arm(MS_WEAP( weaps[random(sizeof(weaps))] ) );
    set_level(5);
}

/* EOF */
