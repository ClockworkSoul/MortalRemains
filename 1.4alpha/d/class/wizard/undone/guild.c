/*
** Mage's Guild
** Begun by Cyanide, 10 Aug 97
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

// This is a temporary array of mage SP's until I feel like making
// the real mage SP list...
#define MAGE_SP ({ 0,10,20,30,40,50,60,70,80,90,100,110,120,130,\
  140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,\
  290,300 })

#include <daemons.h>
#include <mudlib.h>
#include <c_wizards.h>

inherit GUILD;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "The Guild of Wizardry");
  set ("long", "An unfinished guildhall.\n");
  set("light", 1);
  set("class", "mage");
  set("group", "wizard");
  set("experience", WIZARD_XP);
}

void init() {
  ::init();
}

string titles (object ob) {
  string str;
  int lvl;

  lvl = ob->query_level("mage");
  if ((string)ob->query("gender")=="female") {
    str = ({
      "$N the Peasant ($A)",
      "$N the Scribe ($A)",
      "$N the New Apprentice ($A)",
      "$N the Beginning Apprentice ($A)",
      "$N the Apprentice ($A)",
      "$N the Advancing Apprentice ($A)",
      "$N the Skilled Apprentice ($A)",
      "$N the Senior Apprentice ($A)",
      "$N the Graduate Mage ($A)",
      "$N the Beginning Mage ($A)",
      "$N the Advancing Mage ($A)",
      "$N the Mage ($A)",
      "$N the Academician ($A)",
      "$N the Learned Mage ($A)",
      "$N the Skilled Mage ($A)",
      "$N the Adepta Minor ($A)",
      "$N the Adept Mage ($A)",
      "$N the Adepta Major ($A)",
      "$N the Archmagess ($A)",
      "$N the Mistress of the First Circle ($A)",
      "$N the Mistress of the Second Circle ($A)",
      "$N the Mistress of the Third Circle ($A)",
      "$N the Mistress of the Fourth Circle ($A)",
      "$N the Mistress of the Fifth Circle ($A)",
      "$N the Mistress of the Sixth Circle ($A)",
      "$N the Mistress of the Seventh Circle ($A)",
      "$N the Mistress of the Eighth Circle ($A)",
      "$N the Mistress of the Ninth Circle ($A)",
      "$N the Arcanamach ($A)",
      "$N the Mistress of Sorcery ($A)",
      "$N the Sorceress Queen ($A)",
      "$N the Arcaness ($A)" 
    })[lvl];
  } else {
    str = ({
      "$N the Peasant ($A)",
      "$N the Scribe ($A)",
      "$N the New Apprentice ($A)",
      "$N the Beginning Apprentice ($A)",
      "$N the Apprentice ($A)",
      "$N the Advancing Apprentice ($A)",
      "$N the Skilled Apprentice ($A)",
      "$N the Senior Apprentice ($A)",
      "$N the Graduate Mage ($A)",
      "$N the Beginning Mage ($A)",
      "$N the Advancing Mage ($A)",
      "$N the Mage ($A)",
      "$N the Academician ($A)",
      "$N the Learned Mage ($A)",
      "$N the Skilled Mage ($A)",
      "$N the Adeptus Minor ($A)",
      "$N the Adept Mage ($A)",
      "$N the Adeptus Major ($A)",
      "$N the Archmage ($A)",
      "$N the Master of the First Circle ($A)",
      "$N the Master of the Second Circle ($A)",
      "$N the Master of the Third Circle ($A)",
      "$N the Master of the Fourth Circle ($A)",
      "$N the Master of the Fifth Circle ($A)",
      "$N the Master of the Sixth Circle ($A)",
      "$N the Master of the Seventh Circle ($A)",
      "$N the Master of the Eighth Circle ($A)",
      "$N the Master of the Ninth Circle ($A)",
      "$N the Arcanamach ($A)",
      "$N the Master of Sorcery ($A)",
      "$N the Sorcerer King ($A)",
      "$N the Arcanist ($A)" })[lvl];
    }
  return str;
}                


int join() {
  object book;

  if (TP->query("base_stat/intelligence") < 9) {
    write("You are not intelligent enough to be a wizard!\n");
    return 0;
  }

  write("A voice says, \"Welcome child...\"\n");
  write("The air shimmers, and a book appears in your hands.\n");
  write("A voice says, \"Take care of this gift, child, and it"+
    " will serve you well.\"\n");

  book = clone_object(MAGE+"obj/book.c");
  if (!book) {
    write("\nA voice says, \"Forgive us child. You cannot join us"+
      " now.\"\nPlease notify Cyanide.\n");
    return 1;
  }
  book->move(this_player());
  return 1;
}

int advance() {
  int level, hp;

  level = TP->query_level("mage");
  write("YOu advance to level "+level+".\n");

  if(level%3==0) TP->add("nwp", 1);
  if(level%6==0) TP->add("wp", 1);

  set_sp(TP, MAGE_SP[level]);

  hp = WIZ_HP_ROLL;
  hp += PROPERTY_D->query_con_hp_bonus(TP);
  add_hp(TP, hp);
  return 1;
}
