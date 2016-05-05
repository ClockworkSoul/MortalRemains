#include <mudlib.h>

inherit ROOM;

#define OWNER getuid( this_object() )

static int privacy_level;
static int temp; 
int check_owner();
int receive_object(object ob);
int toss(string str);
string *INVITED = ({  }) ;
string *BANNED = ({  }) ;

void create() 
{
::create();
  seteuid(  getuid( this_object() )  );
//  set(  "owner", getuid( this_object() )  );
  set ("exits", ([
    "south" : "/d/guild/necromancers/rooms/guild.c",
    "down" : "/d/Wizard/rooms/wizhall.c",
    "up" : "/d/Dark/Prime/wiz/boardroom.c",
    "east" : "/d/Start/town/rooms/adv_guild.c",
     ]) );
  set( "light", 1 );
  set("short", "A Blank White Room");
  set( "long",@endtext
A room. Nuff said.
endtext
  );
  set ("show_room_rejection",1);
  set ("remove_msg",
"You hit a solid barrier of darkness, and are stunned.\n"+
capitalize(OWNER)+" tells you: You have not been invited.\n"
  );


}
  
reset();
     
  
int reset() { 
  privacy_level = 2; 
  return 1;
}
    


void init() {
  add_action("shields", "set");
  add_action("help",    "help");
  add_action("shstat", "check");
  add_action("show",    "list");
  add_action("invite",  "invite");
  add_action("uninvite","uninvite");
  add_action("ban",     "ban");
  add_action("unban",   "unban");
  add_action("toss",    "toss");
  
  
}
 
int check_owner() {
  if ( geteuid(this_player()) != OWNER ) {
  return 1;
  }
  return 0;
}


int receive_object(object ob)
{
 // If the privacy_level = 1, throw out losers who are on
 // banned list.
 // If the privacy_level = 2, throw out losers who aren't  
 // on the invite list.
  int on_banned_list=0;
  int on_guest_list=0;
  if (member_array(geteuid(ob), INVITED) != -1) 
    on_guest_list=1;
  if (member_array(geteuid(ob), BANNED) != -1) 
    on_banned_list=1;
  if (privacy_level > 0 			//if privacy is off, skip all this
     && living(ob)				//ignore non-living stuffs
     && geteuid(ob) != OWNER			//don't toss the owner!!
     && ((!on_guest_list && privacy_level==2) || on_banned_list) 
     )
      {
      tell_object(ob, query("remove_msg"));
      if (query("show_room_rejection"))
	say (	"A glistening, golden, shield, springs up around the room.\n" + 
		ob->query("cap_name")+" bounces off of it and is gone.\n" +
		"The shield lowers and the room appears as it was before.\n"
		);
      if (  find_player(OWNER)  )
        tell_object(find_player(OWNER),
          ob->query("cap_name")+" tried to enter your room, \""+query("short")+"\".\n");
      return 0;
      }
  return 1;
}


int shields (string str) {
  if ( !(str=="level 0"||str=="level 1"||str=="level 2")  ) return 0;
  if (check_owner() == 1) return 1;
  
  if (str == "level 0") {
    write("Anyone is allowed into the room.\n");
    privacy_level=0;
    return 1;
  }
  if (str == "level 1") {
    write("People on the \"banned\" list will be tossed from the room.\n");
    privacy_level = 1;
    return 1;
  }
  if (str == "level 2") {
    write("People not on the \"invited\" list will be tossed from the room.\n");
    privacy_level = 2;
    return 1;
  }
  return 0;
}
 
int help(string str) {
  if (str != "here") return 0;
  if (check_owner() == 1) return 1;
  write(@ENDHELP
The available commands for this private room are
  INVITE <person>   to add someone to guest list.
  UNINVITE <person> to remove someone from the guest list.
  TOSS <person>     to throw someone out of the room.
  BAN <person>      to add someone to banned list.
  UNBAN <person>    to remove someone from the banned list.
  SET LEVEL <#>     to set the room's privacy level to 0 1 or 2.
  CHECK             to check to see what the privacy level is.
  LIST              to look at the guest and banned lists.
ENDHELP
  );
  return 1;
}
 
int shstat() {
  if (privacy_level==1) {
    write("People on the \"banned\" list will be tossed from the room.\n");
    return 1;
  }
  if (privacy_level==2) {
    write("People not on the \"invited\" list will be tossed from the room.\n");
    return 1;
  }
  if (privacy_level==0) {
  write("Anyone is allowed into the room.\n");
  return 1;
  }
return 0;
}
 
int invite(string str) {
  int on_guest_list=0;
  if (!str) return 0;
  if (check_owner() == 1) return 1;  
  // Add someone to the invite list.
  if (member_array(str, INVITED) != -1) 
    on_guest_list=1;
  if (on_guest_list)
    {
    write("That person is already invited.\n");
    return 1;
    }
  write("You add "+str+" to the list of invited people.\n");
  say("A new name has been added to the guest list.\n");
  INVITED += ({str});
  return 1;
}
 
int uninvite(string str) {
  int on_guest_list=0;
  if (!str) return 0;
  if (check_owner() == 1) return 1;  
  if (member_array(str, INVITED) != -1) 
    on_guest_list=1;
  if (!on_guest_list)
   {
    write("That person isn't invited.\n");
    return 1;
    }
  write("You remove "+str+" from the list of invited people.\n");
  say("A name has been removed from the guest list.\n");
  INVITED -= ({str});
  toss(str);
  return 1;
}

 
int ban(string str) {
  int on_banned_list=0;
  if (!str) return 0;
  if (check_owner() == 1) return 1;  
  // Add someone to the banned list.
  if (member_array(str, BANNED) != -1) 
    on_banned_list=1;
  if (on_banned_list)
    {
    write("That person is already on the list!\n");
    return 1;
    }
  if(str==OWNER)
    {
    write("WHAT!?!?! You want to ban yourself????\nI don't think so.\n");
    return 1;
    }
  write("You add "+str+" to the list of banned people.\n");
  say("A new name has been added to the banned list.\n");
  BANNED += ({str});
  toss(str);
  return 1;
}
 
int unban(string str) {
  int on_banned_list=0;
  if (!str) return 0;
  if (check_owner() == 1) return 1;  

  if (member_array(str, BANNED) != -1) 
    on_banned_list=1;
  if (!on_banned_list)
    {
    write("That person is not on the list!\n");
    return 1;
    }
  write("You remove "+str+" from the list of banned people.\n");
  say("A name has been removed from the banned list.\n");
  INVITED -= ({str});
  return 1;
}



int toss(string str) {
  object loser,owner;
  if( this_player() != find_player(OWNER) )
    {
    write("You are not the owner.\n");
    return 1;
    }
  if (!str)
    {
    write ("Toss who?\n");
    return 1;
    }
  if (find_player(str)) {
  loser = find_player(str);
  owner = find_player(OWNER);
  if (environment(loser) == environment(owner))
    {
    tell_object(loser, capitalize(OWNER)+" throws you from the room!\n");
    loser->move_player(loser->query("last_location"));
//    say(
//capitalize(OWNER+" throws " + loser->query("cap_name") + " from the room!"
//    );
    return 1;
    }
  }
  return 0;
}
 
int show() {
  if (check_owner() != 1) {  
  write("You examine the guest list and the banned list.\n");
  say(capitalize(OWNER) + " examines the guest list and the banned list.\n");
  write("Guest List\n");
  write("----------\n");
  for (temp = 0;temp<sizeof(INVITED);temp++) write(capitalize(INVITED[temp])+"\n");
  write("\n");
  write("Banned List\n");
  write("-----------\n");
  for (temp = 0;temp<sizeof(BANNED);temp++) write(capitalize(BANNED[temp])+"\n");
  return 1;
  }
  write("You examine the guest list.\n");
  say(this_player()->query("cap_name") + " examines the guest list.\n");
  write("Guest List\n");
  write("----------\n");
  for (temp = 0;temp<sizeof(INVITED);temp++) write(capitalize(INVITED[temp])+"\n");
  return 1;

}
