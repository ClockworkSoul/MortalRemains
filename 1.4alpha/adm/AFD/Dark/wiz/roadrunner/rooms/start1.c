#include <mudlib.h>

inherit CHATTING_ROOM;

void create()
{
  ::create() ;
  seteuid(getuid()) ;
  set("light", 1) ;

  set("outdoors", "Dark") ;
  set("short", "Entrance to McKenzie Forest") ;
  set("long", @END
You are standing at the enterance of McKinzie Forest.  The
forest is dark and looks very dense.  There is a path leading
north into the forest.  You see an old sign posted to a tree.
END
  ) ;
  set("item_desc", ([
	"sign" : "This sign is made of oak and nailed to the tree.\n"+
		"Perhaps you should read it.\n",
	"forest" : "This is McKenzie Forest, made of oaks and pines\n",
	"tree" : "I bet if you stood on the sign you could climb it.\n",
	"nail" : "It's a rusty old iron nail, holding the sign to the tree.\n",
	"path" : "This path is leading straight north into the forest.\n"+
		"It is made of dirt and crushed stone.\n",
	]) ) ;
  set("smell", ([
	"default" : "You inhale deeply and smell the strong scent of the "+
		"pine trees.\n",
	]) ) ;
  set("listen", ([
	"default" : "You hear the sounds of a busy forest.\n",
	]) ) ;
  set("exits", ([
	"north" : "/d/Dark/wiz/roadrunner/rooms/trail1.c",
	]) ) ;
}

void init()
{
  add_action("read_sign", "read") ;
}

int read_sign(string str)
{
  if (str && str == "sign")
  {
	write("The sign say's this is McKenzie Forest and\n") ;
	write("if you enter, your going to die.\n") ;
	say(this_player()->query("cap_name") + " reads a sign.\n") ;
	return 1;
  }
 write("Read what?\n") ;
 return 1 ;
}
