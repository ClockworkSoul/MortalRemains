inherit ROOM;

string *MEMBERS = ({ "raistlin", "waxer", "cyanide", "highlander",
    "mirage", "chronos", "gendor", "roadrunner", "norton" }) ;

int locked;

void create() {
  seteuid(getuid());
  locked = 1;
  set( "light", 0 );
  set("short", "The Inner Sanctum");
  set("item_func", ([
     "thrones" : "throne_func",
  ]) );
  set( "long", @EndText
You stand on a rock platform, surrounded by blue flames.  The sky above you is
dark red.  In a circle on the edge of the platform there are thrones, each
named for their owner.

You have come to the far reaches of existance.  This is a place where
reality and the Netherplane unite.  Only those of immense power
may enter here, those who have given their souls to the Dark, and
succumbed to the powers of that domain.

Few are allowed here, only wizards of The dark domain may enter here.
This is a locked room, so as to make it safe for those who wish to code
in peace. 
EndText
  );
  ::create();
}

void init() {
  add_action("do_lock", "lock");
  add_action("sit", "sit");
  add_action("transport", "transport");
  if(locked && member_array(TPn, MEMBERS) == -1) {
    write("You are not allowed in the Inner Sanctum, Be Gone!\n");
    say(TPN+ " attempted to violate the sanctity of this place.\n");
    TP->move((string)this_player()->query("last_location"), "SNEAK");
  }
}

int do_lock(string junk) {       
  if(member_array(TPn, MEMBERS) == -1) {
    write("You are not allowed to do that.\n");
    return 1;
  }
  if(locked) {       
    say("This room is now unlocked.\n");
    write("This room is now unlocked.\n");
    locked = 0;
  } else {  
    write("This room is now locked.\n");
    say("This room is now locked.\n");
    locked = 1;
  }
  return 1;
}

int sit(string str) {
  if (!str) {
    write("Sit where?\n");
    return 1;
  }
  if (str != "on throne" && str != "on my throne") {
    write("Sit where?\n"); 
    return 1;
  }
  if(member_array(TPn, MEMBERS) == -1) {
    write("You are not a member of the Council.\n");
    return 1;
  }
  say(TPN + " sits in "+possessive(TP->query("gender"))+" throne.\n");
  write("You take your position in the Council.\n");
  return 1;
}

int transport(string str) {
  if (!str) return 0;
  if(member_array(str, MEMBERS) == -1) {
    write("That is not a member of the Council.\n");
    return 1;
  }
  write("You leap into the flames of eternity and fall into "+
    capitalize(str)+"'s workroom!\n");
  say(TPN + " leaps into the flames of eternity.\n");
  TP->move_player(user_path(str) + "workroom.c", "SNEAK");
  return 1;
} 



int throne_func() {
  int i, x;
  string work;
  x = sizeof(MEMBERS);
  work = "You see "+x+" thrones, ";
  x--;
  for(i=0;i<sizeof(MEMBERS);i++) {
    if (i == x) work += "and one for "+capitalize(MEMBERS[i])+".\n";
    else work += "one for "+capitalize(MEMBERS[i])+", ";
  }
  write(wrap(work));
  say(TPN+ " looks carefully at each of the thrones.\n");
  return 1;
}
