#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "author", "shya" );
    set( "light", 0 );
    set( "short", "a cave (e,w)" );
    set( "exits", ([
      "east" : "/u/s/shya/cavern/rooms/tunnel2.c"
    ]) );
    set("pre_exit_func", ([
        "east" : "roots_check"
    ]) );
    set( "item_desc", ([
            "cave": "The sheer size of it makes you feel insignificant and alone.\n",
            "sounds" : "Low rumbling noises."        
    ]));
}
int roots_check()
{
  if (present("roots", TO)) {
    write("The roots block your way.\n");
    return 1;
  }
  return 0;
}


void on_roots_die ()
{
    set( "long", @EndText
You are in a cave. 
The cave continues to the east further into the darkness.  
A hole has been hacked through the tangled mass of roots allowing
you to proceed east.
EndText
    );
}


void reset ()
{
    object bat, roots;

    seteuid( getuid() );
    ::reset();
    if (! present("roots")) {
        set( "long", @EndText
You are in a cave. 
The cave continues to the east further into the darkness.  
A tangled mass of roots blocks your progress east.
EndText
        );
        roots = clone_object("/u/s/shya/private/roots.c");
	  if (roots)
          roots->move(this_object());
    }

    if (! present("bat")) {
        bat = clone_object("/u/s/shya/private/bat.c");
	  if (bat)
            bat->move(this_object());
    }

}
