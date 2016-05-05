/*
* File: beach.c
* Desc: The first file in the Ocean Domain
* File originally created by gasman, edited by Herself
*/
#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

int monster_flag;
int found = 0;

void init() 
{
    add_action("swim", "swim");
    add_action("dig", "dig");
}

void create()
{
    ::create();
    seteuid( getuid() );
    set("author" , "herself");
    set("forbidden" , 1);
    set("short" , "The Beach");
    set("long" , wrap(
	"You stand on a vast sandy beach. The ocean "+
	"stretches out in front of you. To the "+
	"east and west, the beach seems to go for miles. "+
	"The sand squishes between your toes, and the hot "+
	"sun beats down on your head. "
      ) );

    set("light", 1);
    monster_flag = 1;

    set("item_desc", ([
      "sand" : wrap("It is white like snow, and sparkles "+
	"with tiny flecks of broken seashells. It reminds "+
	"you of your childhood when you used to dig in "+
	"the sand on the beach. "),
      "sea#ocean" : "It stretches out to the horizon.\n",
      "beach" : "You are standing on it. \n",
      "west#east" : "Try looking in the direction.\n",
      "horizon" : "It seems so far away. \n",
      "toes" : "Your toes are half burried in the sand. \n",
      "head" : "You can't see your head silly!\n",
    ]) );

    set("objects", ([
      "noise" : O_MON+"ocean_sounds.c",
      "crab" : O_MON+"crab.c",
      "starfish" : O_MON+"starfish.c",
    ]) );
    reset();
    set( "exits", ([
      "east" : O_ROOM+"beach1.c",
      "west" : O_ROOM+"beach8.c",
      "swim" :  O_ROOM+"sea",
    ]));

    set ("pre_exit_func", ([ "swim" : "swim_off" ]) ) ;

}

//ACTIONS

int swim_off(string arg) 
{
    say(P_NAME +" dives into the ocean and swims off.\n");
    write("You dive into the sea.\n\n\n\n");
    //this_player()->move_player(O_ROOM+"sea", "SNEAK", "swim");
    return 0;
}

int dig(string arg) 
{
    if(!arg) 
    {
	write("dig what?\n");
	return 1;
    }
    if(arg == "sand") 
    {
	object smon;
	smon = clone_object(O_MON+"sand.c");
	if(smon && monster_flag){
	    say(TPN+" digs in the sand... \n A sand monster appears!\n");
	    write("You dig in the sand... \n A sand monster appears!\n");
	    smon->move( environment(this_player() ) );
	    smon->kill_ob( this_player() );
	    monster_flag = 0;
	}else
	    write("You dig in the sand and get all dirty.\n");
	return 1;
    }
}
void fix_flag() { monster_flag = 1; }
