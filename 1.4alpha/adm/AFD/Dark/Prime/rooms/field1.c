#include <config.h>
#include <mudlib.h>
#include "field.c"
#include "../defs.h"
inherit ROOM;
object rat1;
int poked, num, rnum;

void create(){
  stuff();
  ::create();
    seteuid(getuid());
	set("exits",([
	"south":"field7.c",
	"west":"field2.c",
  	]) );
	rnum=2;
::reset();
}
int reset(){
poked=0;
if(!present(rat1)){
rat1=clone_object(MON(rat.c));
rat1->move(TO);
}
}

