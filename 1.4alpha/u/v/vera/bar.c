#define JUKEBOX "/u/v/vera/jukebox.c"
#define BLADDER "/u/v/vera/bladder.c"
#define BARMAN "/u/v/vera/barman.c"
#define BAR "/u/v/vera/bar.c"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create() {
    object ob;
  ::create();
  seteuid( getuid() );
  set ("light", 1);

set ( "short", "Inside an old, cosy and very comfortable bar");
    
set ( "long", @EndText

You are in an old, cosy and very comfortable pub.
An open fire flickers brightly giving the whole room a very pleasent,
homely feeling. At one end of the room is a varnished wood bar.  
The stone walls hold black and white photographs of  the town as it 
used to be. You feel very relaxed here. The rest-rooms are to the west. 
To the north is a passage leading to a workroom
Out will take you back the way you came.
You can 'order <name of drink>' if you want.
EndText
     );

set( "exits", ([
        "out" : START,
        "north" : "/u/v/vera/workroom.c",
        "west" : "/u/v/vera/toilet.c", ])   
       );

      if (!present ("jukebox")) {
      ob=clone_object(JUKEBOX);
      ob->move(this_object());
	}
      if (!present ("barman")) {
      ob=clone_object(BARMAN);
      ob->move(this_object());
     	}
      if (!present ("bladder", this_player())) {   
      ob=clone_object(BLADDER);
      ob->move(this_player());
                 }
}
