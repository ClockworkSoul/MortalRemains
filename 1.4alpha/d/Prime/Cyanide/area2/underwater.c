#include <mudlib.h>
#include "main.h"
#include <config.h>

inherit ROOM;

int a;

void create()
{
  ::create();
  a=0;
  seteuid( getuid());
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 0);
set ("short", "Underwater");
  set( "long", @EndText
You are below the surface of the lake. It turns out that the lake is
quite shallow and the bottom is only a few feet below you. Considering
the fridged temperature of the water, you should probably not plan
an extended stay. The lake bottom is sandy and a few hearty plants and
algae live there.
EndText
  );
  reset();
  set( "exits", ([
  "up" : MAIN+"/onlake.c"
  ]) );
set ("exit_msg", ([
  "up" : "$N floats upward towards the surface of the lake.\n",
   ]) );
set ("item_desc", ([
"plants" : "They're normal plants in all respects. \n"+"You're breath is getting
quite short.\n",
"algae" : "Just slimy green and brown algae. Yuck!\n"+"You really should be
surfacing soon...\n",
 "water" : "It's REAL cold! In fact, you can't feel your toes anymore...\n",
]) );
set("item_func",(["sand":"ring","bottom":"ring"]) );
}

void reset()
{
object baby;
a=0;
::reset();
seteuid( getuid());
if(present("baby",this_object())) return;
baby=clone_object(MONST+"/baby.c");
baby->move(this_object());
}

int ring() {
  object ring;
  if (a==0) {
    ring = clone_object(OBJ+"/goldring.c");
    ring -> move(this_object());
    a=1;
  write("You see a ring, half buried in the sand!\n");
  return 1;
}
  write ("Functional.\n");
  return 1;
}
