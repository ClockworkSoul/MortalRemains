inherit "/std/monster.c";

void create(){
  ::create();
  seteuid(getuid());
  set_name("mirror");
  set("short", "Mirror");
  set("long", "A reflective Mirror");
}

void recieve_message(string str){
string a;
if(sscanf("%s", a)){
  say("Mirror: "+str+"\n");
}
}
