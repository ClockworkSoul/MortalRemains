#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());

set("light",1);
set("exits",
(["east" : "/u/s/sydex/workroom.c",
"west" : "/u/s/sydex/Project/area1.c"])
);
set("short","A stone archway.");
set("long",@SydeX
A huge stone Archway rises from the ground here, the top of which
threatens to obscure the entire western half of the sky. The archway
itself seems to be relativly new although there is a well beaten path
leading through the giant archway. The area surronding the archway
seems to be unnaturaly cold. The vegitation surronding the base apears
to be covered with frost......
SydeX
);

}
