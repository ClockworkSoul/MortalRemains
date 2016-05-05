#include <config.h>
#include <newbie.h>

inherit ROOM;

void create(){
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("light",1);
    set("short","A sand box.");
    set("long", @End
A five foot by five foot sand box.  The sand is smooth and pretty deep as
to hide things in.  A small pail and shovel lay in the sand.  A mini
castle has already been built here and by the looks of it someone quite
young was the designer.
End
    );
    set("item_desc", ([
      "sand":"Lots of smooth sand fill this sand box.\n",
      "pail":"A small yellow pail to help build castles in the sand.\n",
      "shovel":"A matching yellow shovel for digging in the sand.\n",
      "castle":"A small castle in the sand. Make you want to build one.\n",
    ]));
    set("exits", ([
      "out" : M_ROOM+"playground.c",
    ]));
}
void init () {
    add_action("dig","dig");
    add_action("build","build");
}
int dig (string str) {
    object coins;

    if (str!="in sand") {
	write("Dig in what?\n"); 
	return 1;
    }

    if (str == "in sand") {
	write("You dig in the sand and uncover something.\n");
	say(TPN+" digs in the sand and reveals something.\n");
	coins = clone_object("/std/coins.c");
	coins->set_number(random(100)+10);
	coins->move( this_object() );
    }
    else {
	write ("Dig in what?\n");
    }
    return 1;
}

int build (string str) {

    if (str !="castle") {
	write("Build what?\n");
   return 1;
    }
    if (str == "castle")  {
	write (@End
                         | |__|__|__|__|__|_|                        
    __    __    __       |_|___|___|___|___||       __    __    __   
   |__|  |__|  |__|      |___|___|___|___|__|      |__|  |__|  |__|  
   |__|__|__|__|__|       \________________/       |__|__|__|__|__|  
    \_|__|__|___|/          \____________/          \_|__|__|__|_/   
     \__|____|__/            |___|___|__|            \__|__|__|_/    
      |||_|_|_||             |_|___|__|_|             |_|_|_|_||     
      ||_|_|||_|__    __    _| _  __  _ |_    __    __||_|_|_|_|     
      |_|_|_|_||__|__|__|__|__|__|__|__|__|__|__|__|__|_|_|_|_||     
      ||_|||_|||___|___|___|___|___|___|___|___|___|__||_|_|_|_|     
      |_|||_|_||_|___|___|___|___|___|___|___|___|___||_|_|_|_||     
      ||_|_|_|_|___|_____|___|_8,2/| | | \13,2__|____||_|_|_|_||     
      |_|_|_|_||_|___|_____|__8,2/ | | | |\13,2___|__||_|_|_|_||     
      |_|_|_|_||_|____|___|_|_8,2| | | | ||13,2|__|__||_|_|_|_||     
     /___|___|__\__|____|___|_8,2| | | | ||13,2|____|/_|___|__|_\     
    |_|_|_|_|_|_||_____|___||_8,2| | | | ||13,2|__|___|__|__|__|_|    
    ||_|_|_|_|_|_|_|_|___|__|_8,2|_|_|_|_||13,2|__|__|__|__|__|_||    
                       Wow, You are quite an builder!
End
	);
	say(TPN+"builds ...\n"+ @End

                         | |__|__|__|__|__|_|                        
    __    __    __       |_|___|___|___|___||       __    __    __   
   |__|  |__|  |__|      |___|___|___|___|__|      |__|  |__|  |__|  
   |__|__|__|__|__|       \________________/       |__|__|__|__|__|  
     \__|____|__/            |___|___|__|            \__|__|__|_/    
      |||_|_|_||             |_|___|__|_|             |_|_|_|_||     
      ||_|_|||_|__    __    _| _  __  _ |_    __    __||_|_|_|_|     
      |_|_|_|_||__|__|__|__|__|__|__|__|__|__|__|__|__|_|_|_|_||     
      |_|||_|_||_|___|___|___|___|___|___|___|___|___||_|_|_|_||     
      ||_|_|_|_|___|_____|___|_8,2/| | | \13,2__|____||_|_|_|_||     
      |_|_|_|_||_|___|_____|__8,2/ | | | |\13,2___|__||_|_|_|_||     
     /___|___|__\__|____|___|_8,2| | | | ||13,2|____|/_|___|__|_\     
    |_|_|_|_|_|_||_____|___||_8,2| | | | ||13,2|__|___|__|__|__|_|    
    ||_|_|_|_|_|_|_|_|___|__|_8,2|_|_|_|_||13,2|__|__|__|__|__|_||    
End
	);
   return 1;
    }
    else {
	write ("Build what?\n");
    }
    return 1;
}

