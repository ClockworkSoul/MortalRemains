#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([ "patron" : "/d/Prime/Oerth/ghcity/monster/patron.c", "waitress" : "/d/Prime/Oerth/ghcity/monster/waitress.c" ]) );
reset();
     set ("long",
"This is the common room of the Brass Dragon Inn. \n"+
"There are stairs that lead upstairs and a set \n"+
"of wooden doors that lead to a kitchen of sorts. \n"+
"It is in this room where patrons come to eat and \n"+
"chat with others. \n");
   set("short", "Brass Dragon Inn Commom Room");
     set ("exits", ([
"west" : Oerth+"/rooms/proc2",
"stairs" : Oerth+"/rooms/bdihall1",
"doors" : Oerth+"/rooms/bdikitchen",
     ]) );
}
