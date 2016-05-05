#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "author", "shya" );
    set( "light", 0 );
    set( "short", "cave entrance (e,w)" );
    set( "exits", ([
      "east" : "/u/s/shya/caverns/rooms/cave2.c",
      "west" : "/u/s/shya/caverns/rooms/forest3.c",
    ]) );
    set("pre_exit_func", ([
        "west" : "worm_check",
        "east" : "roots_check"
    ]) );
    set( "item_desc", ([
            "cave": "The sheer size of it makes you feel insignificant and alone.\n",
            "wall" : "Covered in glowing worms.",
	      "worms" : "Eluminating the room with fluorescent light."
    ]));
}

void init() {
    add_action("get", "get");
}

int get( string str ) {
  object worm;
  if ((str != "worm") && (str != "glow worm")) return 0;
  if (present("worm", TP)) {
    write ("One's enough.\n");
    return 1;
  }
  write("You get a glow worm.\n");
  say(TPN+" plucks a glow worm off the wall.\n");
  worm=clone_object("/u/s/shya/worm.c");
  worm->move(TP);
  worm->do_chat();
  return 1;
}
 
int worm_check()
{
  if (present("worm", TP)) {
    write("The worm dies as you leave the cave.\n");
    present("worm", TP)->remove();
  }
  return 0;
}

int roots_check()
{
  if (present("roots", TO)) {
    write("The roots block your way.\n");
    present("roots", TO)->kill_ob(TP);   
    return 1;
  }
  return 0;
}


void on_roots_die ()
{
    set( "long", @EndText
You are in a huge entrance of a cave. 
The cave continues to the east from here, and exits to the west.  
This seems like a good enough place to hide, except for the wierd
sounds coming from further in the cave.  A hole has been hacked
through the tangled mass of roots allowing you to proceed east.
The cave is lit by millions of glowing worms on the wall.
EndText
    );
}


void reset ()
{
    object roots, worm;

    seteuid( getuid() );
    ::reset();
    if (! present("roots")) {
        set( "long", @EndText
You are in a huge entrance of a cave. 
The cave continues to the east from here, and exits to the west.  
This seems like a good enough place to hide, except for the wierd
sounds coming from further in the cave.  A tangled mass of roots
blocks your progress east.
The cave is lit by millions of glowing worms on the wall.
EndText
        );
        roots = clone_object("/u/s/shya/roots.c");
	  if (roots)
          roots->move(this_object());
    } 
        if (! present("worm")) {
        worm = clone_object("/u/s/shya/worm.c");
        if (worm)
            worm->move(this_object());
    }
}
