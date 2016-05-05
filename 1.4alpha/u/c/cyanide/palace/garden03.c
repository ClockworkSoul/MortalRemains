#include "main.h"

inherit MAIN+"/gardenstd.c";

void create()
{
    ::create();
    set("short", "A Beautiful Garden");
    set( "long", @EndText
About you in this area, bushes and shrubs blooming with the 
disembodied hands and ears of young girls surround you - seemingly
reaching out to you, begging for some kind of mercy. Ladies' lips on
long climbing vines begin making hungry sucking noises at your
approach, as if expecting you to feed them. Judging from the vivid
red of their blooms, live blood apparently flows through their
petals.
EndText
    );
set("item_desc", ([
"bushes" : "Grotesque, aren't they?\n",
"shrubs" : "Especially grotesque.\n",
"hands" : "They grab at your clothing as you walk near.\n",
"ears" : "Small, like those of a young girl.\n",
"lips" : "They appear to be stained with the blood of "+
"their prey.\n",
"vines" : "They have grown over much of this part of "+
"the garden.\n",
"blooms" : "They are a vivid blood red.\n", 
]) );
    set( "exits", ([
      "north" : MAIN+"/gpathw.c",
      "east" : MAIN+"/topiary.c",
    ]) );
}
