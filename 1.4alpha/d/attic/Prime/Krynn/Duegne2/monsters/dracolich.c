#include <mudlib.h>
inherit OBJECT;

void create(){
  seteuid(getuid());
  set("short", "A very large pile of bones");
  set("id", ({ "bones", "pile", "pile of bones" }));
  set("long", "A large pile pf bones that look like they were once some large animal.\n");
  set("prevent_get",1);
}

void init() {
  add_action("exa_func", "search");
  add_action("exa_func", "exa");
}
int exa_func(string str){
    object mon;
if(str!="bones" && str!="pile" && str!="pile of bones"){
   return 0;
}
mon = clone_object("/d/Prime/Krynn/Duegne2/monsters/skel_dragon.c");

mon->move(environment(TP));
mon->kill_ob(TP);
destruct();
write ("The bones suddenly come alive and attack you!!\n");
  return 1;
}
