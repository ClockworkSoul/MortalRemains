#include <mudlib.h>
#include <sewers.h>

inherit OBJECT;
   void create(){
   seteuid(getuid());
   set("author", "cattt");
   set("id", ({ "big tooth","tooth"}) );
   set("short", "a big ole tooth");
   set("long", @Gem
This tooth is quite large.  From the blood stains on it you would think
that some large monster wasn't eagar on letting it go.
Gem
  );
   set("value", 5);
 }
