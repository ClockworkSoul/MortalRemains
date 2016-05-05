#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    int i;
    object king;

    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "Throne Room(n)");
    set( "long", @EndText
This is the Throne Room of King Jared.
His guards are known far and wide for their prowess in combat,
and their frosty personality.	
EndText
    );

    king=clone_object("/d/Arctic/Shya/monsters/king.c");
    king->move(TO);
    for (i = 1; i <= 6; i++)
        {
        object frostguard;

        frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard1.c");
        frostguard->move(TO);
        }
    set( "exits", ([
           "north" : "/d/Arctic/Shya/rooms/castle/library.c" 
         ]) );
}

void reset()
{         
	int nGuards;

      nGuards = 0;
	if (present("frostguard", TO)) {
		object *inventory;
		int i;

		inventory = all_inventory (TO);
		for (i = 0; i < sizeof(inventory); i++) {
			if (inventory[i]->id("frostguard"))
				nGuards += 1;
		}		
	}
	for (; nGuards < 6; nGuards++) {
		object frostguard;
		frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
		frostguard->move(TO);
	}
}

void init()
{ 
   add_action("block_king", "kill") ;
   add_action("block_king", "steal" ) ;
   add_action("block_king", "backstab");
   add_action("block_king", "cast");
   add_action("block_king", "sneak");
}

int block_king (string str)
{
    if (str == "king")
    {
        if (present("frostguard", TO))
        {
            object *inventory;
            int i;

            write("The guards won't let you do that to their liege.\n") ;
            inventory = all_inventory (TO);
            for (i = 0; i < sizeof(inventory); i++)
            {
                if (inventory[i]->id("frostguard"))
                {
                    write ("A guard turns to attack you!\n");
                    inventory[i]->kill_ob(TP);
			 
                }
            }
            return 1;
	  }
    }
    return 0;
}
