#include <mudlib.h>
inherit ARMOR;
void create ()
{
set("id",({"ring","gold ring"}));
set("short","Shya's ring");
set("long","This ring is made out of gold and has two stones set in it. \n"+
"One of the stones is an Aquamarine and the other is a moonstone. \n"+
"These stones represent the birthmonths of the two most important people \n" +
"in Shya's life: Gregory and Kaelyn. \n");
set("mass",0);
set_armor_type("ring");
set("armor",0);
}

int query_auto_load() {
return 1;
}
