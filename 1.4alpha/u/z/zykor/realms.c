#include <config.h>
#include <mudlib.h>

inherit ROOM;


void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short", "The mind of Zykor");
  set( "long", @EndText
You are now in the mind of Zykor, here is where he would keep his
toys to play with in his head and also doors to the realms that
exist only in his head, at least for now that is...

You head someone cackling madly from above.
EndText
  );
  set( "exits", ([
 "reality" : "/u/z/zykor/workroom.c",
 "zyrin" : "/u/z/zykor/zyrin/startrm.c",
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
