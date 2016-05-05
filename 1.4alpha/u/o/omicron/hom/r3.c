#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
set("light", 1);
set("short", "House of Mirrors");
set("long", @EndText
This is a relatively small room. There are dirty mirrors on all sides
and the floor is wooden.
EndText
);
set("exits", ([
"south" : "l.c",
"west" : "l.c",
"east" : "ent.c",
"north" : "r9.c",
]) );
set("item_desc", ([
"floor" : "A dirty floor made of scuffed wood.",
"dirt" : "You don't get out much, do you?",
"mirror" : "A bit vain, are we?",
"mirrors" : "A bit vain, are we?",
]) );
set("pre_exit_func", ([
"south" : "wizonly",
"west" : "wizonly",
]) );
}
int wizonly() {
if (!wizardp(TP)) {
write("You walk face first into a mirror.\n");
return 1;
}
return 0;
}
