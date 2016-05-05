#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "A Rocky Path");
    set("long", @EndText
You have started on a rocky path covered with choking grey ash and
razor-sharp shards of volcanic glass. The path winds down to to the east
from here, turning sharply around a ridge. The heat here is almost
unbearable.
EndText
    );
    set("exits", ([
        "west" : PHLEGETHOS+"out03.c",
        "southeast" : PHLEGETHOS+"out05.c"
    ]) );
    reset();
}