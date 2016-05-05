// hall2.c
// This room is where players come to be promoted to wizard. The function
// wizqual in this room is the one that determines what it takes to become
// a wizard. You probably want to alter it: we've set the standards rather
// low for our own purposes. More detail on it in the header.

#define NUM_QUESTS 1
#define MIN_SKILL 50
#define TOT_SKILL 500

#include <mudlib.h>
#include <daemons.h>
#include <path.h>

inherit ROOM ;

void create() {
  ::create();
// This room needs EUID so it can load the promotion daemon.
  seteuid(getuid()) ;
  set("light", 1) ;
  set ("short", "The wizzing room") ;
  set ("long", @Endtext
A round platform stands in the center of the room.  Computer lights
blink and strobe continously on the walls.  A small camera is making
a gentle humming sound on the ceiling corner.  A pair of automatic
sliding doors lead to the south, into the questing room.
Endtext
  ) ;
  set ("item_desc", ([
    "platform" : "It is some kind of hologram projector.\n",
    "lights" : "The light patterns are rather repetitive and dizzying.\n",
    "walls" : "It seems like you're inside a giant computer terminal.\n",
    "camera" : "It is looking directly at you.\n",
    "doors" : "They are hooked up to a motion sensor.\n",
  ]) ) ;
  set("objects", ([
    "jessica" : MOBS+ "jessica",
  ]) );
  set ("exits", ([
    "south" : ROOMS+ "hall",
  ]) ) ;
  set("exit_msg", ([
    "south" : "$N leaves south through the sliding doors.",
  ]) );
  set("pre_exit_func", ([ "south" : "slide_open" ]) );
  reset();
}

void init() {
  add_action ("advance", "advance") ;
  add_action ("inquire", "inquire") ;
}

// This is the wizqual function which determines what it takes to get
// promoted to wizard. It comes with the following standards:
//   1. All quests completed.
//   2. No skill below 50.
//   3. Total skills above 500.
// If the player has met the requirements it returns 1, otherwise it
// returns 0.

int wizqual (object ob) {

  mapping solved, skills ;
  string *names ;
  int i, j, sum ;

  solved = ob->query("quest") ;
  if (!solved) return 0 ;
  j = sizeof(solved) ;
  if (j != NUM_QUESTS) return 0 ;
  skills = ob->query_skills() ;
  names = keys(skills) ;
  for (i=0;i<sizeof(skills);i++) {
    j = skills[names[i]] ;
    if (j<MIN_SKILL) return 0 ;
    sum = sum + j ;
  }
  if (sum<TOT_SKILL) return 0 ;
  return 1 ;
}

// This function checks whether a player has met the criteria. If so, it
// gives him the wizard command path, sets his wizard property, and calls
// enable_wizard() on him. Notably, it does NOT give him a directory. If
// you want that done, you'll have to add it.

int advance() {
  string str ;
  int res ;

  if (wizardp(TP))
    return notify_fail("Jessica says: You are already a wizard!\n");
  if (wizqual(this_player())==1) {
    res = PROMOTION_D->promote_wiz(this_player()) ;
    if (res==0) {
      write ("Jessica says: I am unable to promote you.  Speak to an admin.\n") ;
      return 1 ;
    }
    write (
"Jessica looks sweetly at you and says:\n"+
"    Congratulations! You have attained wizard status on this MUD. If you\n"+
"have never been a wizard before, the first thing you should do is type\n"+
"\"help new_wiz\" and read through the document. It will give you some\n"+
"idea of the abilities of a wizard, and what responsibilities wizards must\n"+
"carry in order to keep the MUD running smoothly.  When you have finished\n"+
"that, talk to one of the administrators of the MUD and ask them what you\n"+
"should do in order to become a full-fledged wizard.\n") ;
    shout (TPCN+" has attained immortality!\n") ;
    str = this_player()->query("cap_name")+" "+ctime(time()) ;
    log_file ("NEW_WIZARDS", str) ;
    return 1 ;
  } else {
    write("Jessica says: I'm sorry, you don't meet the qualifications yet.\n");
    return 1 ;
  }
}

int inquire() {
  write (
"Jessica looks at you and says:\n"+
"  To make wizard on this MUD you must meet three qualifications.  First,\n"+
"you must complete all the quests.  The 'Quest Listings' to the south\n"+
"will describe them, and you can type \"quests\" to see how many you have\n"+
"left to do.  Second, all of your skills must above 50.  Third, the total\n"+
"of all your skills must be at least 500.\n"
  );
  return 1 ;
}

void slide_open() {
  write("The doors slide open as you leave south.\n");
  return 0;
}
