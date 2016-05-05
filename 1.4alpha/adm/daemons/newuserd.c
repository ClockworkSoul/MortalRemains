/*
**  File: /adm/daemons/newuserd.c
**  Purpose: New User Daemons v3.0.  A crude attempt at making
**    the new user daemon nice and easy for people to use, as 
**    well as flexible. Allows for rerolls and preferance 
**    resetting. Offers a high level of charater optimizarion. 
**
**  Credits:
**    20 Sep 97  Cyanide began the arduous process of creating 
**               this file. (I hope Ilzarion is happy now.  :P )
**     5 Oct 97  Cyanide added "new_race_stats" func so player 
**               no longer had to reroll all their stats when 
**               they chose a new race.
**    17 Oct 98  Cyanide added support for player registration.
**     5 Feb 00  Cyanide added help files, corrected an error in stat
**               switching, and made a few cosmetic changes.
**
**  More Credits: Much ground work laid by:
**    Buddha@TMI-2    (Original new user daemon)
**    Mobydick@TMI-2  (Races, skills, stats)
**    Leto@TMI-2      (Language mappings (which Cyanide later 
**                    corrupted) )
**
**  IMPORTANT NOTE!
**    To add a new race, you must change these functions:
**      query_race_mins();
**      query_race_maxes();
**      query_race_adj();
**      get_new_race2()
**    as well as update VALID_RACES.
*/

#include <ansi.h>
#include <logs.h>
#include <uid.h>
#include <priv.h>
#include <mudlib.h>
#include <config.h>
#include <login.h>
#include <login_macros.h>
#include <language.h>
#include <daemons.h>

// Definitions and Prototypes

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#define MAX_REROLLS 10
#define FLORAL \
   "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
#define NUM_STATS 6
#define STAT_NAMES ({ "strength", "intelligence", "constitution", \
   "wisdom", "dexterity", "charisma" })
#define STAT_ROLL random(6) + random(6) + random(6) + 3
#define CHARACTERS ({ "a","b","c","d","e","f","g","h","i","j", \
   "k","l","m","n","o","p","q","r","s","t","u","v","w","x", \
   "y","z" })
#define VALID_RACES ({ "dwarf", "drow", "elf", \
    "gnome", "goblin", "half-elf", "half-orc", "half-ogre", \
    "halfling", "human", "kobold", "ogre", "orc" })
#define STAT_ABOVE_MAX -1
#define STAT_BELOW_MIN -2

static varargs void clrscr(object);
void create_new_user(object user, string pass);
static void finish_up (object user, object body);
static void finish_up3(object user, object body);
static void freeze_stats(object);
static void get_new_align(object, object);
static void get_new_gender(object user, object body);
static void get_new_handedness(object, object);
static void get_new_race (object, object);
static void get_stat_switch (object, object);
static void get_help(object, object);
static void get_help2(string, object, object);
static void get_help3(string, object, object);
static void new_pass2 (string, string, object, object, int);
void new_race_stats(object body, string race);
int *query_race_mins(string race);
int *query_race_maxes(string race);
int *query_race_adj(string race);
static varargs mapping roll_stats(object, string);
void show_menu (object user, object body);
string pad(string str, int i);


void create() {
    seteuid(ROOT_UID);
}

int *query_race_mins(string race) {
    int *minarray;

    // "strength", "intelligence", "constitution", 
    // "wisdom", "dexterity", "charisma"

    switch(race) {
    case "aasimar" : minarray = ({ 8,11,5,11,3,13 }); break;
    case "dwarf" : minarray = ({ 8,3,11,3,3,3 }); break;
    case "drow" : minarray = ({ 3,8,7,3,6,8 }); break;   
    case "elf" : minarray = ({ 3,8,7,3,6,8 }); break;
    case "githzarai" : minarray = ({ 3,9,3,3,3,3 }); break;
    case "air genasi" : minarray = ({ 3,5,3,3,9,3 }); break;
    case "earth genasi" : minarray = ({ 9,3,9,3,3,3 }); break;
    case "fire genasi" : minarray = ({ 3,3,3,3,5,3 }); break;
    case "water genasi" : minarray = ({ 5,5,3,3,5,3 }); break;
    case "goblin" : minarray = ({ 5,3,5,3,4,5 }); break;
    case "kender" : minarray = ({ 7,6,10,3,10,3 }); break;
    case "gnome" : minarray = ({ 6,6,8,3,3,3 }); break;
    case "halfling" : minarray = ({ 7,6,10,3,7,3 }); break;
    case "half-elf" : minarray = ({ 3,4,6,3,6,3 }); break;
    case "half-giant" : minarray = ({ 17,3,15,3,3,3 }); break;
    case "half-ogre" : minarray = ({ 14,3,14,3,3,3 }); break;
    case "half-orc" : minarray = ({ 6,3,8,3,3,3 }); break;
    case "human" : minarray = ({ 3,3,3,3,3,3 }); break;
    case "kobold" : minarray = ({ 3,3,3,3,3,3 }); break;
    case "ogre" : minarray = ({ 14,3,12,3,3,4 }); break;
    case "orc" : minarray = ({ 5,3,8,3,3,3 }); break;
    default : minarray = ({ 3,3,3,3,3,3 }); break;
    }
    return minarray;
}

int *query_race_maxes(string race) {
    int *maxarray;

    // "strength", "intelligence", "constitution", 
    // "wisdom", "dexterity", "charisma"

    switch(race) {
    case "aasimar" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "dwarf" : maxarray = ({ 18,18,18,18,17,17 }); break;
    case "drow" : maxarray = ({ 18,18,18,18,18,18 }); break; 
    case "dragon" : maxarray = ({ 20,20,20,20,12,10 }); break;
    case "elf" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "air genasi" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "earth genasi" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "fire genasi" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "water genasi" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "githzerai" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "kender" : maxarray = ({ 17,18,18,17,18,18 }); break;
    case "goblin" : maxarray = ({ 16,18,16,18,17,13 }); break;
    case "gnome" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "half-elf" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "half-giant" : maxarray = ({ 18,13,18,13,15,15 }); break;
    case "half-ogre" : maxarray = ({ 18,12,18,12,12,8 }); break;
    case "half-orc" : maxarray = ({ 18,17,18,14,17,12 }); break;
    case "halfling" : maxarray = ({ 18,18,18,17,18,18 }); break;
    case "human" : maxarray = ({ 18,18,18,18,18,18 }); break;
    case "kobold" : maxarray = ({ 15,17,16,18,18,14 }); break;
    case "ogre" : maxarray = ({ 18,18,18,9,8,10 }); break;
    case "orc" : maxarray = ({ 17,16,18,16,17,14 }); break;
    default : maxarray = ({ 18,18,18,18,18,18 }); break;
    }
    return maxarray;
}

int *query_race_adj(string race) {
    int *adjarray;

    // "strength", "intelligence", "constitution", 
    // "wisdom", "dexterity", "charisma"

    switch(race) {
    case "aasimar" : adjarray = ({ 0,0,-2,1,0,1 }); break;
    case "dwarf" : adjarray = ({ 0,0,1,0,0,-1 }); break;
    case "drow" : adjarray = ({ 0,1,-1,0,1,-1 }); break;
    case "elf" : adjarray = ({ 0,0,-1,0,1,0 }); break;
    case "githzerai" : adjarray = ({ -1,1,0,-1,1,0 }); break;
    case "air genasi" : adjarray = ({ 0,1,0,-1,0,0 }); break;
    case "earth genasi" : adjarray = ({ 1,0,1,-1,0,-1 }); break;
    case "fire genasi" : adjarray = ({ 0,1,0,0,0,-1 }); break;
    case "water genasi" : adjarray = ({ 0,0,1,0,0,-1 }); break;
    case "gnome" : adjarray = ({ 0,1,0,-1,0,0 }); break;
    case "goblin" : adjarray = ({ -1,0,0,0,0,-1 }); break;
    case "kender" : adjarray = ({ -1,0,0,-1,2,0 }); break;
    case "halfling" : adjarray = ({ -1,0,0,0,1,0 }); break;
    case "half-elf" : adjarray = ({ 0,0,0,0,0,0 }); break;
    case "half-giant" : adjarray = ({ 4,-2,2,-2,-2,-2 }); break;
    case "half-ogre" : adjarray = ({ 1,-1,1,0,0,-1 }); break;
    case "half-orc" : adjarray = ({ 1,0,1,0,0,-2 }); break;
    case "human" : adjarray = ({ 0,0,0,0,0,0 }); break;
    case "kobold" : adjarray = ({ -1,0,-1,0,0,0 }); break;
    case "ogre" : adjarray = ({ 2,-2,2,0,0,-2 }); break;
    case "orc" : adjarray = ({ 1,0,0,0,0,-2 }); break;
    default : adjarray = ({ 0,0,0,0,0,0 }); break;
    }
    return adjarray;
}


// query_valid_stat returns the following values:
//   0 : Invalid for an unspecified reason
//  -1 : Stat above maximum for race
//  -2 : Stat below minimum for race 

int query_valid_stat(string race, string stat, int val) {
    int *minarray, *maxarray, i;

    minarray = query_race_mins(race);
    maxarray = query_race_maxes(race);

    i = member_array(stat, STAT_NAMES);

    if (val < minarray[i]) return STAT_BELOW_MIN;
    if (val > maxarray[i]) return STAT_ABOVE_MAX;

    return 1;
}

void create_new_user(object user, string pass) {
    object body;

    if (geteuid(previous_object()) != ROOT_UID) return;
    user->SET_BODY(USER_OB); // Let's assume a standard login
    body = new(USER_OB);

    body->set("name", (string)user->NAME, MASTER_ONLY);
    body->set ("cap_name", capitalize((string)user->NAME), MASTER_ONLY) ;
    body->set("snoopable", 1, MASTER_ONLY);

    // Set default values of the new pod, er... character.
    body->set("gender", "male");
    body->set("race", "human");
    body->set("handedness", 1);
    body->set("rerolls", MAX_REROLLS+1);
    body->set("stat", roll_stats(body));
    body->set("stat_rolled", body->query("stat"));
    body->set_true_align(0,0);

    user->SET_BODY_OB(body);

    cat(NPLAYER_INTRO);

    //  If EMAIL_REGISTRATION is defined in /include/login.h then check to see if
    //  this is a registered name with a predefined password.
#ifdef EMAIL_REGISTRATION
    if (pass && stringp(pass) && pass != "")
    { write("Please enter the password sent to you with your\n" +
	  "registration acceptance: ");
	input_to("get_pass", 3, pass, user, body, 0);
	return; }
#endif  /* EMAIL_REGISTRATION */

    write("\nPlease enter a unique password for your character. Do not use\n"+
      "the password you use on your computer account, and please do not use\n"+
      "any word that appears in the dictionary.\n") ;
    input_to("new_pass", 3, user, body, 0);
}

static void new_pass(string pass, object user, object body, int count) {
    if (strlen(pass) < 5) {
	write("\nI'm sorry, your password must be at least 5 characters.\n");
	if (count > 2) {
	    write("\nYou have taken too many tries.\n");
	    user->remove_user();
	    return;
	}
	write("Please change your password: ");
	input_to("new_pass", 3, user, body, count + 1);
	return;
    }
    write("\nPlease reenter your password to confirm: ");
    input_to("new_pass2", 3, pass, user, body, count);
}

static void new_pass2 (string pass2, string pass, object user, 
  object body, int count) {
    if (pass==pass2) {
	user->SET_PASS(crypt(pass2,0));
	if (REGISTRY_D->query_active()!=1) {
	    write("\nPlease enter your email address (user@host): ");
	    input_to("new_email", user, body, 0);
	} else {
	    user->SET_EMAIL(REGISTRY_D->find_email(body->query("name")));
	    write("\nPlease enter your real name: ");
	    input_to("get_real_name", user, body);
	}
	return;
    }

    write("\nSorry, the passwords have to match.\n");
    if (count>2) {
	write("\nSorry - you have taken too many tries.\n");
	user->remove_user();
	return;
    }

    write("Please enter you character's password: ");
    input_to("new_pass", 3, user, body, count + 1);
}

static void get_pass(string pass, string prev, object user, object body,
  int count) {
    if (crypt(pass, prev) != prev) {
	write("Sorry, that password is incorrect.\n");
	if (count > 2) {
	    write("\nYou have taken too many tries.\n");
	    user->remove_user();
	    return;
	}
	write("Please reenter your password: ");
	input_to("get_pass", 3, prev, user, body, count + 1);
	return;
    }

    user->SET_PASS(prev);
    write("\nPlease enter your email address (user@host): ");
    input_to("new_email", user, body, 0);
}

static void new_email(string e, object user, object body, int count) {
    string id, host;

    if (sscanf(e, "%s@%s", id, host) != 2 || id == "" || host == "") { 
	write("Mail address must be in the form user@host\n");
	if (count > 2) {
	    write("\nYou have taken too many tries.\n");
	    user->remove_user();
	    return;
	}
	write("Please re-enter your email address: ");
	input_to("new_email", user, body, count + 1);
	return; 
    }
    write("\nNow THAT'S original...  oh, well.");
    user->SET_EMAIL(e);
    write("\nPlease enter your real name: ");
    input_to("get_real_name", user, body);
}


static void get_real_name(string rn, object user, object body) {
    if (!rn || rn == "")  rn = "???";
    user->SET_RNAME(rn);

    // That's all we need for now - let's get the menu stuff going.

    clrscr(user);
    show_menu(user, body);
}


// This function clears the screen of the user or the object passed to it.

static varargs void clrscr(object user) {
    if (user)
	tell_object(user, CLR);   // Find this code in ansi.h
    else
	write(CLR);    
    return;
}

static varargs mapping roll_stats(object body, string race, object user) {
    int i, total=0, min=3, max=18, ran=0, ran2=0, *minarray,
    *maxarray;
    mapping stats = allocate_mapping(6);

    // Make sure they have enough rerolls left.

    if (user) {
	if ((int)body->query("rerolls") < 1) {
	    tell_object(user, "Sorry, you have used all your rerolls.\n");
	    return (body->query("stat_rolled"));
	}
    }

    // Figure out the body's min/max for each stat...

    if (!race) {
	minarray = query_race_mins((string)body->query("race"));
	maxarray = query_race_maxes((string)body->query("race"));
    } else {
	minarray = query_race_mins(race);
	maxarray = query_race_maxes(race);
    }

    // The while loop ensures that the stat average won't be too high 
    // or too low and the for loop does all the rolling of the stats. 
    // MUCH less clunky than Mobydick's method, though a bit harder to
    // read.

    total = 0;
    while (total < 66 || total > 90) {
	total = 0;
	for (i=0; i<NUM_STATS; i++) {
	    min = minarray[i];
	    max = maxarray[i];
	    ran=0;                   // Initialization. Ensures we
	    // enter the loop.
	    while (ran<min || ran>max) {
		ran = STAT_ROLL;
		ran2 = STAT_ROLL;
		if (ran2>ran) ran = ran2;
	    }

	    stats[STAT_NAMES[i]] = ran;
	    total+=ran;  
	}
    }

    if (body) {
	body->set("stat", stats);
	body->set("stat_rolled", stats);
	body->set("rerolls", (int)body->query("rerolls") - 1 );
    }

    return stats;
}

string view_stats(object body) {
    int x, y;
    string tmpA, tmpB, str = "", race;

    // This loop will output the current stats, with adjustments if there are any.

    for (x=0; x<NUM_STATS; x+=2) {
	race = body->query("race");

	tmpA = STAT_NAMES[x];
	y = query_race_adj(race)[x];       
	tmpA = capitalize(tmpA)+": "+body->query("stat/"+tmpA);
	if (y<0) tmpA += " (" + y + ")";
	if (y>0) tmpA += " (+" + y + ")";

	tmpB = STAT_NAMES[x+1];
	y = query_race_adj(race)[x+1];
	tmpB = capitalize(tmpB)+": "+body->query("stat/"+tmpB);
	if (y<0) tmpB += " (" + y + ")";
	if (y>0) tmpB += " (+" + y + ")";

	str += sprintf("  %24-s%s\n", tmpA, tmpB);
    }
    return str;
}


void show_menu (object user, object body) {
    string menu = "\n\n"+FLORAL+"\n";
    int x, *mins, *maxes;

    mins = query_race_mins((string)body->query("race"));
    maxes = query_race_maxes((string)body->query("race"));

    menu += "You are "+body->query("cap_name")+", a "+
    body->query("gender")+" "+body->query("race")+".\n";
    menu += "Your alignment is " + body->query_alignment() + ".\n\n";

    menu += view_stats(body);

    menu += "\nYou are ";
    if ((int)body->query("handedness")==1)
	menu+="right-handed";
    else
	menu+="left-handed";

    menu += "\nYou may reroll your stats "+
    body->query("rerolls")+" more times.";

    menu += ("\n"+FLORAL+"\n\n");
    menu = menu + (@END_MENU
You have the following options :
   1 - Reroll your stats          5 - Choose a new race
   2 - Interchange two stats      6 - Choose a new alignment
   3 - Change your handedness     0 - Done
   4 - Choose a new gender        ? - Read the help documents.
END_MENU
    );

    menu+="\nWhat is your choice?: ";
    tell_object(user, menu);
    input_to("menu_choice", 3, user, body);
}


static void menu_choice (string choice, object user, object body) {
    int flag = 1;

    switch (choice) {
    case "1" : roll_stats(body, (string)body->query("race"), user);
	clrscr();
	tell_object(user, "Your stats have been rerolled.");
	show_menu(user, body);
	return;
	break;
    case "2" : get_stat_switch(user, body); break;
    case "3" : get_new_handedness(user, body); break;
    case "4" : get_new_gender(user, body); break;
    case "5" : get_new_race(user, body); break;
    case "6" : get_new_align(user, body); break;
    case "?" : get_help(user, body); break;
    case "0" : finish_up(user, body); break;
	//case "&core42" : SHUTDOWN_D->do_shutdown(1);
    default  : flag = 0;
    }

    if (!flag) {
	clrscr();
	write("You have made an invalid selection.");
	show_menu(user, body);
    }

    return;
}

static void get_help(object user, object body) {
    int i;
    string str, tmp;

    clrscr();

    str = "You can get help in any of the following items: \n\n";

    tmp = "Races: "+capitalize(VALID_RACES[0]);
    for (i = 1; i < sizeof(VALID_RACES)-1; i++) 
	tmp += ", " + capitalize(VALID_RACES[i]);
    str += iwrap(tmp) + "\n\n";;


    tmp = "Stats: "+capitalize(STAT_NAMES[0]);
    for (i = 1; i < sizeof(STAT_NAMES)-1; i++) 
	tmp += ", " + capitalize(STAT_NAMES[i]);
    str += iwrap(tmp) + "\n\nGet help on what topic?: ";

    write(str);
    input_to("get_help2", user, body);
}

static void get_help2(string help, object user, object body) {
    clrscr();

    help = ("/doc/help/"+lower_case(help));
    help = replace_string(help, " ", "_");
    help = replace_string(help, "-", "_");

    write(FLORAL+"\n\n");

    if (file_exists(help))
	cat(help);
    else {
	write("   Sorry, there is no such help document.");
	log_file(BAD_HELP, "[ "+extract(ctime(time()),4,15)+" - "+
	  "*NEW_USER* ]\t\t"+help+"\n");  
    }

    write("\n\n"+FLORAL+"\n\n");

    write("\nHit 'Enter' to continue.");
    input_to("get_help3", user, body);
}

static void get_help3(string s, object user, object body) {
    clrscr();
    show_menu(user, body);
    return;
}

static void get_new_align(object user, object body) {
    clrscr();

    write(@ENDTEXT
You can be any one of the following alignments:
 
 a) Lawful Good      b) Neutral Good     c) Chaotic Good
 d) Lawful Neutral   e) True Neutral     f) Chaotic Neutral
 g) Lawful Evil      h) Neutral Evil     i) Chaotic Evil
ENDTEXT
    );
    write("\nWhat is your choice? (a - i): ");
    input_to("get_new_align2", user, body);
}

static void get_new_align2(string align, object user, object body) {
    mapping mapAlign;

    if (!align) align = "none";
    align = lower_case(align);

    switch (align) {
    case "a" : align = "lg"; break;
    case "b" : align = "ng"; break;
    case "c" : align = "cg"; break;
    case "d" : align = "ln"; break;
    case "e" : align = "nn"; break;
    case "f" : align = "cn"; break;
    case "g" : align = "le"; break;
    case "h" : align = "ne"; break;
    case "i" : align = "ce"; break;
    default :
	clrscr();
	write("That is not a valid choice.");
	show_menu(user, body);
	return;
    }

    body->set_align(align);
    clrscr();
    show_menu(user, body);
    return;
}


static void get_new_handedness(object user, object body) {

    write("\nWould you prefer to be right-handed or left-handed?: ");
    input_to("get_new_handedness2", user, body);
}

static void get_new_handedness2(string h, object user, object body, int count) {
    int handz;

    if (!h || member_array(h, ({"right", "left",
	"r", "l" })) == -1)
    { write("\nYou can only be right or left handed.\n");
	if (count > 2) {
	    clrscr();
	    write("You have taken too many tries.");
	    show_menu(user, body);
	    return; }
	write("Please enter your handedness: ");
	input_to("get_new_handedness2", user, body, count + 1);
	return; }

    switch(h) {
    case "r":
    case "right" : handz = 1;
	break;
    case "l": 
    case "left":  handz = 2;
	break; }
    body->set("handedness", handz, READ_ONLY);
    clrscr();
    show_menu(user, body);
}

static void get_new_gender(object user, object body) {
    if ((string)body->query("race")=="modron") {
	clrscr();
	write("Modrons are sexless, and have no gender.\n"+
	  "If you wish to have a gender, you must change your race first.");
	show_menu(user, body);
	return;
    }

    write("\nWould you prefer to be male of female?: ");
    input_to("get_new_gender2", user, body, 0);
}

static void get_new_gender2(string gender, object user, object body, int count) {
    if (gender) gender = lower_case(gender[0..0]);

    if (!gender || (gender!="m" && gender!="f")) {
	write("\nYou can only be male or female.\n");
	if (count > 2) {
	    clrscr();
	    write("You have taken too many tries.");
	    show_menu(user, body);
	    return;
	}
	write("Please enter your gender: ");
	input_to("get_new_gender2", user, body, count + 1);
	return;
    }

    switch(gender) {
    case "m":  body->set("gender", "male");
	break;
    case "f":  body->set("gender", "female");
	break;
    }

    clrscr();
    show_menu(user, body);
}


static void get_stat_switch (object user, object body) {
    int s;
    string display = "", tmpA, tmpB;

    clrscr();
    display = "\n\nYour stats currently are as follows: \n";

    display += view_stats(body);
    display += "\n\nWhat is the first stat you wish to switch?:\n";
    for (s=0; s<NUM_STATS; s+=2) {
	tmpA = (s+1) + ") " + capitalize(STAT_NAMES[s]);
	tmpB = (s+2) + ") " + capitalize(STAT_NAMES[s+1]);
	display += sprintf("  %-30s%s\n", tmpA, tmpB);
    }
    display+="\nPlease enter a number 1 to 6: ";
    tell_object(user, display);

    input_to("get_stat_switch2", 3, user, body);
}

static void get_stat_switch2 (string choice, object user, object body) {
    int num=0, valid=0;

    valid = sscanf(choice, "%d", num);
    num--;

    if (!valid || !choice || num<0 || num>5) {
	clrscr(user);
	tell_object(user, "Sorry - that is not a valid choice.");
	show_menu(user, body);
    }

    tell_object(user, "\n\nSwitch your "+STAT_NAMES[num]+" with what stat?\n"+
      "Please enter a number 1 to 6: ");
    input_to ("get_stat_switch3", 3, num, user, body);
}

static void get_stat_switch3 (string choice, int statA, object user, object body) {
    int statB=0, val=0, i;
    string statName;

    val = sscanf(choice, "%d", statB);
    statB--;

    if (!val || statB<0 || statB>5) {
	clrscr(user);
	tell_object(user, "Sorry - that is not a valid choice.");
	show_menu(user, body);
    }

    statName = STAT_NAMES[statA];
    val = (int)body->query("stat/"+STAT_NAMES[statB]);

    // query_valid_stat returns the following values:
    //   0 : Invalid for an unspecified reason
    //  -1 : Stat above maximum for race
    //  -2 : Stat bellw minimum for race 

    i = query_valid_stat(body->query("race"), statName, val);
    if (i < 1) {
	clrscr(user);
	switch(i) {
	case STAT_ABOVE_MAX : tell_object(user, val+" is above the maximum value for "+statName+".");
	    break;
	case STAT_BELOW_MIN : tell_object(user, val+" is below the minumum value for "+statName+".");
	    break;
	default : tell_object(user, "That choice is invalid.");
	}
	show_menu(user, body);
	return;
    }

    statName = STAT_NAMES[statB];
    val = (int)body->query("stat/"+STAT_NAMES[statA]);
    i = query_valid_stat((string)body->query("race"), statName, val);
    if (i < 1) {
	clrscr(user);
	switch(i) {
	case STAT_ABOVE_MAX : tell_object(user, val+" is above the maximum value for "+statName+".\n");
	    break;
	case STAT_BELOW_MIN : tell_object(user, val+" is below the minumum value for "+statName+".\n");
	    break;
	default : tell_object(user, "That choice is invalid.\n");
	}
	show_menu(user, body);
	return;
    }

    val = (int)body->query("stat/"+STAT_NAMES[statA]);
    body->set( "stat/"+STAT_NAMES[statA], 
      body->query("stat/"+STAT_NAMES[statB]) );
    body->set("stat/"+STAT_NAMES[statB], val);
    body->set("stat_rolled", body->query("stat"));

    clrscr(user);
    tell_object(user, "Your "+STAT_NAMES[statA]+" and "+STAT_NAMES[statB]+
      " have been juxtaposed.");
    show_menu(user, body);
    return;
}

static void get_new_race(object user, object body) {
    int x, i, num;
    string *races = VALID_RACES, str;

    clrscr(user);
    str = "You may be one of the following races: \n\n ";

    for (i=0; i<sizeof(races); i++) {
	string tmp = CHARACTERS[i] + " - ";
	str += pad(tmp + capitalize(races[i]), 20);

	if (!((i+1)%4) || i==(sizeof(races)-1)) {
	    str += "\n ";
	} 
    }  // End i loop

    write((str));
    write("\nWhich race do you choose? (a - "+
      CHARACTERS[i-1]+"): ");
    input_to("get_new_race2", user, body);
}

static void get_new_race2(string race, object user, object body) {
    int iv = 0, size = 6, i;
    mapping lang = ([ "common" : 100 ]);

    i = member_array(race, CHARACTERS);
    if (i==-1 || i>(sizeof(VALID_RACES)-1)) {
	clrscr();
	write("Invalid race.");
	show_menu(user, body);
	return;
    }

    race = VALID_RACES[i];

    if (body->query("gender")=="neuter")
	body->set("gender", "male");

    switch(race) {
    case "dwarf" : iv = 1;size = 5; lang+=(["dwarven":100]); break;
    case "drow" : iv=1; size=5; lang+=(["drow":100]); break;
    case "elf" : iv=1; size=5; lang+=(["elven":100]); break;
    case "githzerai" : iv=1; lang+=(["githzerai":100]); break;
    case "gnome" : size = 3; lang+=(["gnomish":100]); break;
    case "goblin" : iv = 1; size = 4; lang+=(["goblin":100]); break;
    case "halfling" : size = 3; lang+=(["halfling":100]); break;
    case "kender" : size = 3; lang+=(["halfling":100]); break;
    case "half-elf" : size = 5; iv=1; lang+=(["elven":60]); break;
    case "half-giant" : size = random(3)+10; break;
    case "half-ogre" : size = random(2)+7; iv=1; lang+=(["ogre":60]);
	break;
    case "half-orc" : size = 6; iv=1; lang+=(["orcish":60]); break;
    case "kobold" : size = 3, iv = 2; lang+=(["kobold":100]); break;
    case "modron" : size = 4; body->set("gender", "neuter"); 
	lang += ([ "modron" : 100 ]); break;
    case "ogre" : iv = 1; size = 9; lang+=(["ogre":100]); break;
    case "orcish" : iv = 1; size = 6; lang+=(["orcish":100]); break;
    default : size = 6; iv = 0; break;
    }

    body->set("infravision", iv);
    body->set("size", size);
    body->set("race", race);
    body->set("languages", lang);

    new_race_stats(body, race);
    clrscr();
    write(capitalize(race)+" selected as your race.  Stats rerolled.");
    show_menu(user, body);
}

// This func makes sure that when a player changes his/her race, the
// rolled stats fall within the min/max range for that race.
// If players use it to cheat, we can fix it a bit.  -Cyanide

void new_race_stats(object body, string race) {
    int x, flag = 1, stat;

    body->set("stat", body->query("stat_rolled"));

    for (x=0;x<NUM_STATS;x++) {
	stat = body->query("stat/"+STAT_NAMES[x]);
	flag = query_valid_stat(race, (string)STAT_NAMES[x], stat);
	while (flag<0) {
	    switch (flag) {
	    case -1 : stat--; break;
	    case -2 : stat++; break;
	    default : stat = 10; break;
	    }
	    flag = query_valid_stat(race, (string)STAT_NAMES[x], stat);
	}
	body->set("stat/"+STAT_NAMES[x], stat);
    }

    return;
}


static void finish_up (object user, object body) { 
    write("\nAre you SURE that you wish to end character optimization?: ");
    input_to("finish_up2", 3, user, body);
}

static void finish_up2(string yesno, object user, object body) {
    yesno = lower_case(yesno);

    if (yesno[0..0]=="y") { 
	finish_up3(user, body);
    } else {
	clrscr(user);
	show_menu(user, body);
    }

    return;
}

static void finish_up3(object user, object body) {
    freeze_stats(body);

    seteuid(geteuid(user));
    export_uid(body);
    seteuid(getuid());
    user->connect();

    cat(NPLAYER_NEWS);

    //  If NEW_USER is defined in /include/logs.h then log the creation time.
#ifdef NEW_USER
    log_file(NEW_USER, capitalize((string)user->NAME) + " was created on " +
      extract(ctime(time()), 4, 15) + " from " + query_ip_name() + ".\n");
#endif /* NEW_USER */

    //  If AUTO_WIZHOOD is defined in /include/config.h then any newly created
    //  users will automatically be granted wizard status, and given the PATH
    //  given by the define. This would be handy on places like TMI where
    //  wizard bits are freely given.
#ifdef AUTO_WIZHOOD
    user->set("wizard", 1);
    write("\t[You have been granted automatic wizard status]\n");
#endif /* AUTO_WIZHOOD */

    body->setup();
    body->set("max_hp", 
      (int)body->query("stat/constitution") * 3,
      MASTER_ONLY);
    body->set("hit_points", body->query("max_hp"));
    user->save_data();
    body->save_data();

    //  If EMAIL_REGISTRATION is defined in /include/login.h then check to see if
    //  this is a registered name that now can be removed from the file.
#ifdef EMAIL_REGISTRATION
    (void)BANISH_D->remove_mailreg_name(user->NAME);
#endif /* EMAIL_REGISTRATION */
}


// This func freezes a few settings that need it. Everything else is
// already done!  Cyanide (22 Sep 97)
// 5 Oct 97 - Cyanide remembered to include stat adjustments by race.

static void freeze_stats(object body) {
    int x, *adjs;

    body->delete("stat_rolled");
    adjs = query_race_adj ((string)body->query("race"));

    for (x=0;x<NUM_STATS;x++)
	if (adjs[x])
	    body->add("stat/"+STAT_NAMES[x], adjs[x]);

    body->set("base_stat", body->query("stat"), MASTER_ONLY);
    if (!body->query("languages")) body->set("languages", ([ "common" : 100 ]) );
    if (!body->query("size")) body->set("size", 6);
    body->set("SIZE", body->query("size"), MASTER_ONLY);

    //lets give em some money -ilz
    body->credit(3000);
    return;
}

// This func pads a string str to length i with spaces.
string pad(string str, int i) {
    string tmp = str;
    int loop, strsz = strlen(str);

    if (i <= strsz) return str;
    for (loop = strsz; loop < i; loop++) {
	tmp += " ";
    }
    return tmp;
}

/* EOF */
