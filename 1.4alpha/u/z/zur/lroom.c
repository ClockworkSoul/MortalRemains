/*
**  FILE:  workroom.c  (private - Version 3.0)
**  PURPOSE:  Privacy and avoiding wizards with no sense of
**	etiquette.
**  AUTHOR:  Cyanide@Nightfall's Keep
**  NOTES:  This is the combination of three different types of
**    	lockable workrooms I've seen, and a few of my own ideas.
**	Unknowing/unwilling contributers:
**		Miranda@Enchanted Rock 	-  Logging
**		Chronos@AtFoD		-  Security levels
**		      ?@Rune		-  Invisibility Screening
**  CHANGES:  
**    18 Mar 1997	Cyanide	    Created the file.
**    30 Apr 1997       Cyanide     Added a few funcs and cool frilly
**                                  stuff on list function.
**    30 Apr        Zur         Made it a save to a file, to hold the global vars.
*/

#include <mudlib.h>

inherit "/adm/daemons/timezone";
inherit ROOM;

#define PL_LOG user_path(getuid())
#define LOG(x) write_file(PL_LOG+"/workroom.log", x+"\t\t"+ctime(query_tzone("EST"))+"\n");
#define OWNER getuid()
#define CHECK_PROT(n) if (check_prot(this_player(), n)==0) return 1;
#define __DEFAULT_BAN ({ "ciao" })
#define __DEFAULT_INVITE ({ "ilzarion", "nightmask", "zur" })
#define SAVE_FILE user_path(getuid())+"/diff"
void guest_add (mixed);
void guest_ban (mixed);
void guest_remove (mixed);
void guest_unban (mixed);
void guest_list();
void guest_help();

mixed banned = ({}) + __DEFAULT_BAN;
mixed invited = ({}) + __DEFAULT_INVITE;
int screen = 1;		//Default screens are on (off = 0)
int shields = 2;	//Default shields on level 2
int lock;
mapping perms;
void create() {
	::create();
	seteuid(getuid());
	restore_object(SAVE_FILE);
	if(!perms) perms = ([ ]);
	set("light", 1);
        set("short", "Cyanide's Office");
        set ("long", "@@query_long");
	set ("exits", ([
       "hall" : "/d/Ancients/rooms/wizrm.c",
	]) );
        set ("c_long", @EndLong
This is Cyanide's working office, tastefully decorated in tans and
light earthtones. An antique desk sits in front of a large bay 
window against the far wall here, and there is a large black file
cabinet in the corner.
EndLong
   );
}

void init() {
	add_action ("guest_func", "guest");
	add_action ("toss_func", "toss");
	add_action ("shield_func", "shields");
	add_action ("screen_func", "screen");
}

int check_prot(object person, string cmd) {
	object owner;
	int i;

	owner = find_player((string)OWNER);

	if (getuid(person) != (string)OWNER) {
		write("You cannot do that here.\n");
		write("Attempt logged.\n");
		if (owner) {
		   write(capitalize(OWNER)+" is present and has been notified.\n");
                   tell_object(owner, "(Workroom) "+person->query("cap_name") +
                      " just tried to \"" + cmd +
                      "\" in your room \"" + query("short")+"\".\n");
	        }
                LOG("(SECURITY)\t" + getuid(person)+"\t"+cmd);
		return 0;
	     } else
	  return 1;
  }

int screen_func (string onoff) {
   CHECK_PROT("screen "+onoff);

   if (!onoff) {
      switch (screen) {
          case 0 : onoff = "off"; break;
          case 1 : onoff = "on"; break;
      }
      tell_object(this_player(), "The invisibility screens are "+
         "currently "+onoff+".\n");
      return 1;
   } else {
      if ((onoff=="on")||(onoff=="off")) {
         switch(onoff) {
            case "on" : screen = 1;
			break;
	    case "off" : screen = 0;
			break;
	    default : write ("Usage: screen [on|off]\n");
			break;
	 }
      write("(Workroom) Invisibility screens have been turned "+onoff+".\n");
      } else {
         write("Usage: screen [on|off]\n");
         return 1;
      }
   }
   save_object(SAVE_FILE);
   return 1;
}  //end screen_func()

int shield_func (int lvl) {
   int stats;
   object ownr;
   string status;

   ownr = find_player((string)OWNER);

  if (!lvl) {
    CHECK_PROT("shields");
    write ("(Workroom)  Shields at level "+shields+".\n");
    return 1;
  }

   CHECK_PROT("shields "+lvl);

   if (shields==(int)lvl) {
      write ("(Workroom)  Shields already set to level "+lvl+".\n");
      return 1;
   }

   switch (lvl) {
      case "0" : shields = 0; break;
      case "1" : shields = 1; break;
      case "2" : shields = 2; break;
   }

      switch (shields) {
         case 0 : status = "Shields off: Anyone may enter the room.";
                break;
         case 1 : status = "Shields level 1: Anyone not banned may enter the room.";
		break;
         case 2 : status = "Shields level 2: Only persons invited may enter the room.";
		break;

	 default : write ("Usage: shields [0|1|2]\n");
		lvl = shields;
		return;
		break;
      }

   if (!lvl) {
      write ("(Workroom): "+status+"\n");
   } else {
      write(wrap("(Workroom) "+status+"\n"));
   }

//Log line here
   save_object(SAVE_FILE);
   return 1;
}

int guest_func (string str) {
   string cmd;

   if (!str) return 0;

   CHECK_PROT("guest "+ str);

   if (sscanf(str, "%s %s", cmd, str)) {
      switch (cmd) {
         case "add" : guest_add(str);
  		return 1;
		break;
	 case "remove" : guest_remove(str);
		return 1;
		break;
	 case "ban" : guest_ban(str);
		return 1;
		break;
	 case "unban" : guest_unban(str);
		return 1;
		break;
      }
   } else {
         switch (str) {
	    case "list" : guest_list();
		return 1;
		break;
	    case "clear" : banned=({}); invited=({});
		write("(Workroom) Guest lists purged.\n");
		return 1;
		break;
            case "reset" : banned = __DEFAULT_BAN;
    	        invited = __DEFAULT_INVITE;
		write("(Workroom) Guests lists reset.\n");
		return 1;
		break;
	    case "help" : guest_help();
		return 1;
		break;
	 }
      }  //end "if"
      save_object(SAVE_FILE);
}

void guest_unban (mixed str) {
   CHECK_PROT("*CHEAT!*");

  if ((member_array(str, banned)) == -1) {
      write("(Workroom) "+capitalize(str)+" is not currently banned.\n");
   } else {
      write("(Workroom) "+capitalize(str)+" has been unbanned.\n");
      LOG("(UNBAN)\t\t"+(string)str);
      banned -= ({ str });
   }
   save_object(SAVE_FILE);
}  //end guest_unban();

void guest_add (mixed str) {
   CHECK_PROT("*CHEAT!*");

   if (member_array(str, invited) == -1) {
     if (member_array(str, banned) != -1 )
         guest_unban(str);
      write("(Workroom) "+capitalize(str)+
        " has been added to the invited list.\n");
      invited += ({ str });
      LOG("(ADD)\t\t"+(string)str);
   } else {
      write("(Workroom) "+capitalize(str)+" is already invited.\n");
   }
   save_object(SAVE_FILE);
}  //end guest_add();

void guest_list() {
  int i;

  CHECK_PROT("*CHEAT!*");

  write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  write("Invited: ");
  for (i=0;i<sizeof(invited);i++) {
    write((string)capitalize(invited[i])+"  ");
    if ((i>0) && ((i%5)==0)) { write("\n\t "); }
  }
  write("\n\nBanned:  ");
  for (i=0;i<sizeof(banned);i++) {
    write((string)capitalize(banned[i])+"  ");
    if ((i>0) && ((i%5)==0)) { write("\n\t "); }
  }
  write("\n");
write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void guest_remove (mixed str) {
  CHECK_PROT("*CHEAT!*");

  if (member_array(str, invited) == -1) {
    write("(Workroom) "+capitalize(str)+" was never invited.\n");
  } else {
    write("(Workroom) "+capitalize(str)+" has been uninvited.\n");
    LOG("(REMOVE)\t"+(string)str);
    invited -= ({ str });
  }
  save_object(SAVE_FILE);
} //end guest_rem()

void guest_ban (mixed str) {
  CHECK_PROT("*CHEAT!*");

  if (member_array(str, banned) == -1) {
      if (member_array(str, invited) != -1 ) {
      guest_remove(str);
    }
    write("(Workroom) "+capitalize(str)+" has been banned from the room.\n");
    banned += ({ str });
    LOG("(BAN)\t\t"+(string)str);
  } else {
    write("(Workroom) "+capitalize(str)+" is already banned.\n");
  }
  save_object(SAVE_FILE);
} //end guest_ban()

int receive_object (object ob) {
  object mine;
  string obname, olprompt;

  if (living(ob)) {
    obname = getuid(ob);
    if ((obname != OWNER) && (!member_group(obname, "admin"))) {
      if ((shields==2) && ((member_array(obname,invited) == -1) ) ||
        ((shields>=0) && ((member_array(obname,banned) != -1)) )) {
        tell_object(ob, "You hit an invisible barrier and are stunned.\n");
        LOG("(NOACCESS)\t"+obname);
        mine = find_player(OWNER);
        if (mine)
          tell_object(mine, ob->query("cap_name")+" tried to enter "+
            "your room \""+ query("short")+"\".\n");
          tell_room(this_object(), ob->query("cap_name")+" just tried"+
            " to enter the room.\n");
        return 0;
      }
      if (screen == 1) {
        if ((ob->query("invisible")) > 0 ) {
          tell_room(this_object(), "There is a great shower of sparks"+
            " and "+ ob->query("cap_name")+" suddenly appears!\n", ob);
          tell_object(ob,"With a great shower of sparks, you suddenly"+
            " find yourself visible!\n");
          ob->remove_env("prompt");
          olprompt = (string)ob->getenv("oldprompt");
          if(olprompt)  ob->setenv("prompt", olprompt);
          ob->remove_env("oldprompt");
          ob->set("invisible", 0);
          ob->do_new();
          LOG("(SCREENED)\t"+getuid(ob));
        }
      }
    }
  }
  return 1;
}

string query_long() {
  string str, desc;

  if (getuid(this_player()) == OWNER) {
    if (shields)
      str = "<[ SHIELDS ON LEVEL "+shields+" ]>\n";
    else
      str = "<[ SHIELDS OFF ]>\n";
    if (screen)
      str += "<[ INVIS FILTER ON ]>\n\n";
    else
      str += "<[ INVIS FILTER OFF ]\n\n";
  } else {
    str = "";
  }

  desc = (string)query("c_long");
  
  str += desc;
  return str;
} //end query_long()

int toss_func (mixed str) {
  object tossee;

  CHECK_PROT("toss "+(string)str);    //Security protection...

  write("(Workroom) Attempting to eject "+capitalize(str)+".\n");

  tossee = present(str, this_object());

  if (tossee) {
    if (tossee->query("last_location") )
      tossee->move(tossee->query("last_location"));
    else
      tossee->move("/std/void.c");
      tell_object(tossee,"A great force tears through you, and you"+
       " find yourself elsewhere!\n");
      tell_room(this_object(),"Space implodes, utter annihilating "+
        tossee->query("cap_name")+"!\n", tossee);
   LOG("(EJECT)\t\t"+(string)str)
      guest_ban(str);
    } else {
      tell_object(this_player(), "Toss who?\n");
    }
    save_object(SAVE_FILE);
  return 1;
}  //end toss_func();

void guest_help() {
  CHECK_PROT("guest help");

write(@EndHelp
	Private Workroom V3.1 - by Cyanide
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
guest add [name]     Invite a person to the room
guest remove [name]  Uninvite a person
guest ban [name]     Utterly ban a person from the room
guest unban [name]   Unbans a person
guest reset          Set the invited/banned lists to defaults
guest list           See the current guest list
guest clear          Totally clear the guest lists

shields [0|1|2]      Set the shields to the given level
screen [on|off]      Turns te invisibility screens on/off
toss [name]          Ejects the person from the room and
                       bans them.
EndHelp
    );
}   //end guest_help()
