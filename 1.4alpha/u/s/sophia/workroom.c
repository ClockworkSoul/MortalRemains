#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set("objects", ([
      "campfire" : "/u/s/sophia/campfire.c",
      "key" : "u/s/sophia/mkey.c"
    ]) );
    reset();
    set( "short", "Sophia's secret place" );
    set( "long", @EndText
You have entered what appears to be a clearing
in the midst of ancient trees and realize as 
you look carefully around that this 
is really Sophia's workroom.
EndText );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
"up" : "/u/s/sophia/home/bedroom2.c",
"south" : "/u/s/sophia/home/playground.c",
    ]) );
    set("item_desc", ([
"hammock" : "A hand woven hammock just big enough to cuddle in.\n",
      "stream" : "A clear small stream tumbles over mossy rocks. A small
bit of metal in the stream glints in the sun. You could follow the
stream south.\n",
"trees" : "Ancient mahogany trees that are at least hundreds 
if not thousands of years old. There are also maple and ironwood 
trees and lilac bushes here and you wonder how these species all grow
in this place together. You can just glimpse the end of what seems to be a hammock.\n",
]) );
}
void init() {
::init();
add_action("toss", "toss",);
}
int toss (string str) {
object mkey;
string str;
if(!str || sscanf(str, "%s in %s",str,str2)!=2){
write("Toss what in where?|n");
return 1;
}
if (str2 != "fire") {
write("You don't see "+article(str2)+" "str2+" here.\n");
return 1;
}

mkey = present(str, TP);
if (!mkey) {
write("You don't have "+article(str)+" "str+"!\n");
return 1;
}

if (!torch->(id("torch")) {
write("There is a three cookie fine for that!\n");
return 1;
}
say(TPN+" watches the fire in fascination\n");
write(
"Suddenly the fire grows and the flames dance until they "+
"form a living scene. Sophia can watch whatever she likes "+
"from here and you wonder if maybe she can read the future here too.\n");
return 1;
mkey->remove();
return 1;
}
