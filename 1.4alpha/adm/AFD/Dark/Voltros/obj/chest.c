inherit CONTAINER;
void create()
{
   seteuid(getuid());
    ::create();
    set("id", ({"chest" }));
    set("short", "a plain wooden chest");
    set("long", "This is a plain, wooden chest.\n");
    clone_object("/d/Dark/Keldros/rithik/obj/sbook.c")->move(TO);
    set("bulk", 30);
    set ("mass", 15) ;
    set("armor", 0);
    set ("capacity", 700) ;
    set ("volume", 180) ;
set_value(401);
}