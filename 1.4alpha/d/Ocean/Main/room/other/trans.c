/*
* FILE: trans.c
* DESC: This room is used to move a player from the
*       ocean to the city of  R'lyeh
*/
#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

#define CFILE                   O_ROOM+"tocave.txt"
#define DELAY                   3 

int timer = 0;
string *cave_messages;

int enter_scene();

void init() 
{
 // add_action("com_block", "", 1);
  enter_scene();
}

void create()
{
  ::create();
  seteuid( getuid() );
  set("author", "gasman");

  set("short", "Under the Sea");
  set("long", "Under the Sea");
  set("light", 0);

}

int com_block(string arg){
	write("You are powerless to do anything at this time!\n");
	return 1;
}

int enter_scene() 
{
  string txt;
  txt = read_bytes(CFILE, 0, file_size(CFILE));
  cave_messages = explode(txt, "#");  
  tell_object(this_player(), cave_messages[timer]);
  timer++;
  if(timer == 5) 
  {
    remove_call_out("enter_scene");
    this_player()->move_player(O_ROOM+"sea_cave.c", "SNEAK", "down");
    timer = 0;
    return;
  }
  else 
  {
    call_out("enter_scene", 3);
  }
}
