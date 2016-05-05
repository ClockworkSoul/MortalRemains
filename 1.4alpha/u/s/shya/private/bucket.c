#include <mudlib.h>

inherit CONTAINER ;

void create(){
int i;

    ::create();
    seteuid(getuid());
    set("author", "shya");
    set("id", ({"bucket", "ice bucket", "bucket of ice"}));
    set("short", "Bucket of ice");
    set_open_long (wrap(
     "This silver bucket is full of ice just perfect for chilling something.\n"));
    set ("capacity", 300) ;
    for (i = 1; i <= 10; i++) {
    object ice;
    ice = clone_object("/u/s/shya/private/ice.c");
    ice->move(this_object());
}
}
void init() 
{
    add_action("dump", "dump") ;
    add_action("get_ice", "get");
    add_action("put_in", "put");
}
int dump (string str)  {
    string name;
    object target ;

if (!str) {
     write("Dump bucket over whose head?\n");
return 1;
    }

if (sscanf(str, "%s on %s", str, name) != 2) {
write("Whose head do you want to dump the bucket of ice over?\n");
return 1;
    }
if (str!="bucket") {
return 1;
    }
target = find_player(name);
if (!target) {
write("There's no player named "+target->query("cap_name")+" on the mud!\n");
return 1;
    }
write(wrap(
"You dump a a bucket of ice over "+target->query("cap_name")+"'s head, \n"+
"making "+objective(target->query("gender"))+" gasp.\n"));

tell_object(target, wrap(
TPN+" dumps a bucket of ice over your head, making you gasp.\n"));

say(
    TPN+" dumps a bucket of ice over "+target->query("cap_name")+"'s head.\n",target);
return 1;
}

int get_ice (string str)
{
object ice;
    if (str != "ice") {
        return 0;
    }
ice =clone_object("/u/s/shya/private/ice.c");
ice->move(TP);    
write ("You get some ice.\n");
    return 1;
}

