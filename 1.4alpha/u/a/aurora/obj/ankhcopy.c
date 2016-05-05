// some code borrowed from Aurora (ankh2.c)
// check there for further citations.

#include <std.h>
#include <ansi.h>
inherit OBJECT;

mixed *query_auto_load(){
	return({"/wizards/dred/obj/skin", ({}) });
}

void init(){
   ::init();
	add_action("skinup","skinup");
	add_action("skin", "skin");
	this_player()->setenv("start","/wizards/dred/workroom.c");
}

void create(){
   seteuid(getuid());
	set_name("the skin");
	set_id( ({"skin", "the skin"}) );
	set_short("Dred's punk rock skin (worn)");
   set_long(
"%^BOLD%^%^WHITE%^This is Dred's punk-rock leather jacket, or 'skin'.\n"+
"%^BOLD%^%^WHITE%^It was bestowed upon him by Wifebeater, the \n"+
"%^BOLD%^%^WHITE%^rockin-est band in America.\n"+
"%^BOLD%^%^WHITE%^Type 'skin help' for more information."
	   );
   set_weight(100);
   set_value(0);
	}

int skin(string str){
   string command, name, me;
   object who;
   if(!str){
	notify_fail("What did you want the skin to do for you?\n");
      return 0;
   }
   if(sscanf(str, "%s %s", command, name)==2){
      if(find_player(name)) who = find_player(name);
      else {
	 notify_fail("That player isn't logged on.  Sorry.\n");
	 return 0;
      }
   }
   else {
      command = str;
      name = "NIL";
   }
   me = (string)this_player()->query_cap_name();
   if(command=="help"){
      write(
@TEXT

%^RED%^============================%^GREEN%^ Commands %^RED%^============================

%^BOLD%^%^WHITE%^The following commands should be issued in the syntax %^CYAN%^skin <command> <player>

%^BOLD%^%^YELLOW%^     hug    grin    drool    ack      wink    doh
%^BOLD%^%^YELLOW%^     dis    kiss    smack    massage  lick    nibble
%^BOLD%^%^YELLOW%^     bop    bwap    smile    blush    

%^RED%^======================================================================
%^%^BOLD%^%^BLUE%^This Dred's punk rock skin.  If you would like to see more funtions
added, ask Dred most politely, and perhaps he will add them. *grin*

TEXT
	   );
     }
   if(command=="smack"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
	tell_player(who, me+" shows up and pimp-smacks you in the face!\n");
      write("You smack "+who->query_cap_name()+" across the face!  Better run!");
      return 1;
   }
   if(command=="kiss"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
	tell_player(who, me+" wanders over and softly kisses you on the cheek.\n");
      write("You kiss "+who->query_cap_name()+" softly on the cheek from afar.");
      return 1;
   }
   if(command=="grin"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
      tell_player(who, me+" bumps into you and gives you a drunken grin.\n");
      write("You give "+who->query_cap_name()+" a really cheezy grin from afar.");
      return 1;
   }
   if(command=="ack"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
      tell_player(who, me+" acks at you.\n");
      write("You ack at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="blush"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
      tell_player(who, me+" blushs at you uncharacteristically.\n");
      write("You blush at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="smile"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
      tell_player(who, me+" pops his head 'round the corner and smiles at you.\n");
      write("You smile at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="drool"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
	tell_player(who, me+" crashes in, drools all over you, then leaves!\n");
      write("You drool all over "+who->query_cap_name()+"'s hot bod!");
      return 1;
   }
   if(command=="dis"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
      tell_player(who, me+" stares at you coldly, gestures, then blatantly disses you!\n");
      write("You blatantly dis "+who->query_cap_name()+"!  How rude!");
      return 1;
   }
   if(command=="massage"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
	tell_player(who, me+" appears and massages the tension from your shoulders and kisses you softly on the cheek.\n");
      write("You massage the tension from "+who->query_cap_name()+"'s shoulders.");
      return 1;
   }
   if(command=="wink"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
	tell_player(who, me+" winks at you from, uh, wherever he is.\n");
      write("You wink at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="bwap"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
      tell_player(who, me+" appears and slugs you in the shoulder,\n yelling 'Whodat whodat bwap!'\n");
      write( "You whodat-whodat-bwap "+who->query_cap_name()+".");
      return 1;
   }
	if(command=="lick"){
	    if(name=="NIL"){
		notify_fail("You must give a player name with that command.\n");
		return 0;
	    }
	    tell_player(who, me+" comes swinging in and licks you, Monchichi-style.\n");
	    write( "You lick " +who->query_cap_name()+ " all over from afar.");
	    return 1;
	}
	if(command=="nibble"){
	    if(name=="NIL"){
	    notify_fail("You must give a player name with that command.\n");
		return 0;
	    }
	    tell_player(who, me+" appears from the shadows and nibbles gently on your ear.\n");
	    write( "You nibble on " +who->query_cap_name()+ " from a far.\n");
	    return 1;
	}
   if(command=="hug"){
      if(name=="NIL"){
	 notify_fail("You must give a player name with that command.\n");
	 return 0;
      }
      tell_player(who, me+" just sorta shows up and gives you a tender hug.\n");
      write( "You send a tender hug to " +who->query_cap_name()+ ".");
      return 1;
   }
if(command=="doh"){
   if(name=="NIL"){
      notify_fail("You must give a player name with that command.\n");
      return 0;
   }
   tell_player(who, me+" goes DOH! so loud you hear it from far away.\n");
   write( "You bop " +who->query_cap_name()+ " over the head!");
   return 1;
}
if(command=="bop"){
   if(name=="NIL"){
      notify_fail("You must give a player name with that command.\n");
      return 0;
   }
   tell_player(who, me+" rolls his eyes and bops you over the head!\n");
   write( "You bop " +who->query_cap_name()+ " over the head!");
   return 1;
}
   if(command=="update"){
      write("You get the latest copy of the skin.");
	new("/wizards/dred/obj/skin")->move(this_player());
      this_object()->remove();
      return 1;
   }
   notify_fail(
"Sorry...the pun-crock skin doesn't support that command at the moment.\n"+
"Send mail to Dred and maybe he'll add it for you.\n"
	      );
   return 0;
}
 
int drop(){
	write("You can't drop your skin!");
   return 1;
}
 
int give(){
	write("You can't give your skin away!");
   return 1;
}
 
int agive(string str){
   if(!wizardp(this_player())){
      notify_fail("This can only be done by wizards.\n");
      return 0;
   }
   if(!str || !find_living(str)){
	    notify_fail("Who did you want to give a skin to?\n");
      return 0;
   }
	  if(present("skin", find_living(str))){
	    notify_fail("That player already has a skin.\n");
      return 0;
   }
	write("You give "+find_player(str)->query_cap_name()+" their very own skin.");
	say(this_player()->query_cap_name()+ "sends a pun-crock skin to "+find_player(str)->query_cap_name());
	tell_player(find_player(str), "The Gods of Punk Rock bestow upon you your very own skin.");
	new("/wizards/dred/obj/skin")->move(find_player(str));
   return 1;
}
 
