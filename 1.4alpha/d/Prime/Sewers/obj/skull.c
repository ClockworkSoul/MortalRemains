#include <mudlib.h>
#include <sewers.h>

inherit OBJECT;
   void create(){
   seteuid(getuid());
   set("author", "cattt");
   set("id", ({ "skull" }) );
   set("short", "an old skull");
   set("long", @Gem
Large eye-sockets on this skull make it look alien to these parts.
Gem
  );
   set("value", 10);
 }
