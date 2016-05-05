// This is the daemon that handles all the ranking and opponent
// requests from the thunderdome.. :)
// (06-20-00) Written from scratch by Chronos.
#include <mudlib.h>
#include <td.h>


inherit DAEMON ;

int Round ; // 0= Nobody is in there..
  string *ranking_s;
void save_rankings() ;
int *ranking_p;

void create() {
  seteuid(getuid()) ;
    restore_object(SAVE_FILE) ;
  if (!ranking_p)
  ranking_p = ({ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }) ;
  if (!ranking_s) 
  ranking_s = ({ "Nobody","Nobody", "Nobody", "Nobody", "Nobody", "Nobody", 
  "Nobody", "Nobody", "Nobody", "Nobody", "Nobody", "Nobody", 
  "Nobody", "Nobody", "Nobody", "Nobody", "Nobody", "Nobody","Nobody",
"Nobody", "Nobody",  }) ;
  call_out("save_rankings", 60) ;
}

void save_rankings() {
    save_object(SAVE_FILE) ;
  call_out("save_rankings", 60) ;
}

string list_rankings() {
   string str ;
  int i ;
  str = " Rank Player                         Points\n";
  str +="------------------------------------------------------\n";
  for(i=0;i<20;i++) {
  if (i<9)
   str += sprintf(" [ %d] %-30s %d\n", i+1,
 ranking_s[i], ranking_p[i]) ;
else
      str += sprintf(" [%d] %-30s %d\n",i+1,
   ranking_s[i], ranking_p[i]) ;
  }
   return str ;
}
int get_rank(object player, int points) {
  int i,x ;
 if (!player || !points) return - 1 ;
  if (ranking_p[19]>points)  return 0 ;

  x= -1 ; // reset the x var to -1.  You will never get rank 1 if you use 0 for a counter!

  // Figure out what rank they got. 
  for(i=0;i<19;i++)  if (ranking_p[i]<points && x==-1) x = i ;  // X is the rank you got.
  
  // Time to adjust the ranking data variables.
  for(i=20;i>x;i--) {
    ranking_p[i] = ranking_p[i-1] ;
    ranking_s[i] = ranking_s[i-1] ;
  }
  ranking_p[x] = points ;
  ranking_s[x] = player->query("cap_name") ;
  return x+1;  //Adjust for counting from 0.
}

// This function gets a random monster from the round opponent files and
// returns the filename.

string get_opponent(int round) {
  string *mon_file ;
  int i ;
  if (!round) return "#ERROR#" ;
  mon_file =  explode( read_file(TD_DATA_DIR+"ROUND_"+round), "\n") ;
  if (!mon_file) return "#ERROR#" ;
  return mon_file[random(sizeof(mon_file))];
}

void death(object who, object killer, int xpv) {
  if (!who) return 1;  // Can't do anything anyway.
  tell_object(who, @ENDLONG
*** You have been defeated in the ThunderDome Arena!
     Luckily, we don't really punish people for that sort of thing.
ENDLONG
  ) ;
  tell_object(killer, "*** Congratulations - You have gained "+xpv+" points!\n"+
           "     You may advance to the next Round.\n");
  if (userp(who)) {
    who->move(RECOVERY_ROOM) ;
    Round = 0 ;
    message("thunderdome", 
 "[ ThunderDome Notification ]\n"+who->query("cap_name")+
   " was defeated by the ruthless "+killer->query("cap_name") + "!\n",
         OB_ROOM) ;    
    message("thunderdome", 
 "[ ThunderDome Notification ]\n"+who->query("cap_name")+
   " was defeated by the ruthless "+killer->query("cap_name") + "!\n",
         TD_START)  ;
    killer->remove() ;
  }
  else who->remove() ;
  if (!random(10)) {
    tell_object(killer, "Fortune smiles upon thee, you have been Healed.\n") ;
    killer->set("hit_points", (int)killer->query("max_hp")) ;
  }
  Round++ ;
  call_out("begin_next_round", 15) ;
  return 1; 
}
