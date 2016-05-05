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
"north" : "l.c",
"east" : "exit.c",
"south" : "l.c",
"west" : "r11.c",
]) );
set("item_desc", ([
"floor" : "A dirty floor made of scuffed wood.",
"dirt" : "You don't get out much, do you?",
"mirror" : "A bit vain, are we?",
"mirrors" : "A bit vain, are we?",
]) );
set("pre_exit_func", ([
"north" : "wizonly",
"south" : "wizonly",
]) );
}
int wizonly() {
if (!wizardp(TP)) {
write("You walk face first into a mirror.\n");
return 1;
}
return 0;
}
