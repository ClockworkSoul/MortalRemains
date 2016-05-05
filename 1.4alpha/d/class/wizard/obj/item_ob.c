/*
** File: item.c  (Level 3 wizard alteration spell)
** Cost: 20 SP
** Credits:
**   09 Feb 98   Cyanide created the spell.
**   24 Mar 98   Cyanide finally fixed the thing.
*/

#include <magic.h>
#include <m_spells.h>
#include <move.h>

#define STORAGE_B MAGES+"std/rooms/storage_rm.c"

inherit OBJECT;
inherit SPELL;

int do_switch(int);

object item;
int active = 0;

void create() {
   seteuid(getuid());
   active = 0;
   set("prevent_sell", 1);
   set("long", "@@query_long");
}


void init() {
   object env;

   add_action("expand", "expand");

   env = environment(TO);
   if (!env) call_out("remove", 1);
   if (!living(env)) call_out("do_switch", 1, 1);
}


void begin_spell ( object caster, object thing, int lvl ) {
   if (!caster || !lvl) remove();
   active = 1;

   item = thing;

   set("schools", ({ "alteration" }) );
   set("enchantment", 1);
   set("caster", caster->query("name"));
   set("level", lvl);
   set("id", item->query("id") );
   add("id", ({ "replica", "cloth" }) );
   set("short", "a cloth replica of "+item->query("short"));

   item->move(STORAGE_B);   // Non-resetting store room.

   return;
}


// Destroying this thing destroys the item, too.

void remove() {
   if (item) item->remove();
   ::remove();
}


int expand(string str) {
   string item_name;

   if (!str) return 0;

   if (id(str) || str=="item") {
      write("You utter the syllable for expansion.\n");
      item_name = query("short");

      if (do_switch(0)) {
         say(TPN+" suddenly has "+item_name+" in "+
          possessive(TP->query("gender"))+" hands.\n");
         write(capitalize(item_name) + 
          " expands to normal size!\n");
      } else
         write("Your item has been lost!\n");

      return 1;
   }

   return 0;
}


int do_switch(int on_floor) {
   int flag;

   if (!item) return 0;

   if (on_floor || (item->move(TP) != MOVE_OK)) {
      if (item->move(environment(TO)) != MOVE_OK) {
         return 0;
      } else {
         tell_room(environment(TO), capitalize(item->query("short"))+
          " suddenly appears on the floor!\n");
      }
   }
   item = 0;
   remove();

   return 1;
}


string query_long() {
   string long;

   long = "A tiny cloth replica of "+lower_case(item->query("short"))+
    ".\nTo get the original item back, just drop it";
   
   if ((string)TP->query("name")==(string)query("caster"))
      long+=" or type \"expand <item>\"";
   
   long+=".";
   long = wrap(long);

   return long;
}

      
/* EOF */
