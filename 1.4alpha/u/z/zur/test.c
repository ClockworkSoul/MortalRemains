#include <config.h>

inherit "/u/c/cyanide/workroom.c";

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "Zur's sanctuary." );
  set( "c_long", @EndText
This is Zur's home. He has become bored with things as
they are, so he has decided to create gods and godesses
to do his work for him. If you stand here, feel fortunate.
Only the truly blessed may enter here.
EndText
  );
set("item_desc", ([ ({ "chair", "book" }) : "Desc.\n", ]));
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
    "cy"    : "/u/c/cyanide/workroom.c",
    "chak"  : "/u/c/chakan/workroom.c",
  ]) );
}

