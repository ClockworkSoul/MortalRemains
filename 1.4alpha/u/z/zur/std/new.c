// control.c coded by Zur.
// 3-31-97 wrote the basic file offline, no debugging.
// 4-1-97  changed it to allow for control of existing non-inherited creatures.
//         The real difference is that we use a fake heart_beat to do the same
//         things the heart_beat(); gave us in minion.c. In this system, all
//         The code is within the "remote control", whereas in an inherited mon
//         We can tie right into the heart_beat.
nomask object master;
nomask object fol;
nomask object pro;
nomask int isFollowing;
nomask int Time;
nomask int Lifespan;
nomask int Protect;
object Me; // replacement for this_object()
int failed_command();
int leave();
string Diagnostic();
void check_env();
void die();
inherit OBJECT;
#include <uid.h>
#include <mudlib.h>
void create(){
 Lifespan = 900;
 set("short", "wand of monster control");
 set("id", ({ "wand" }));
 }
void init(){
  //if(Me->id("corpse")) die();
  add_action("restrain_me", "restrain");
  add_action("do_something", "scmd");
  }
//The only thing keeping this piece of shit together.
void fake_heart_beat()
 {
  if(Me){
   if(!living(Me)) die();
   if(Time > Lifespan) leave();
   if(isFollowing) check_env();
   if(Protect && pro)
   {
     object ctk;
     ctk = pro->query_current_attacker();
     if(ctk && environment(pro) == environment(Me))
     {
        if(!ctk == Me->query_current_attacker())
        {
          tell_object(environment(),
              sprintf("%s joins the fray in protection of %s.\n",
                       query("name"), master->query("cap_name")));
          Me->kill_ob(ctk);
        }
     }
   }
  Time++;
  call_out("fake_heart_beat", 1);
 }
 else
 {
   die();
 }
} 
 void set_following(object ob) { fol = ob; }
 void set_master(object ob){  master = ob; }
 void set_protect(object ob) { pro = ob; }
 void set_lifespan(int i){ Lifespan = i; }
 void set_restrained(mixed ob)
  {
      Me = ob;
  }
 void check_env()
 {
   object myenv, masenv;
   myenv = environment(Me);
   masenv = environment(fol);
   if(myenv != masenv)
   {
     Me->move(masenv);
     tell_object(masenv, Me->getenv("MMIN"));
     tell_object(myenv, Me->getenv("MMOUT"));
   }
 }
 int do_something(string str)
 {
  string arg;
  if(!str) return (int) failed_command();
  
  switch(str)
  {
  case "diagnostic":
  case "diag":
  {
    if(!wizardp(this_player()))
      return (int) failed_command();
    else
    write(Diagnostic());
    return 1;
    break;
  } 
  case "leave":
   {
    leave();
    return 1;
    break;
    }
  case "look":
  case "l":
  {
   tell_object(master, "/cmds/std/_look.c"->look_in_room(environment(Me),0)+"\n");
   return 1;
   break;
  }
  case "i":
  case "inventory":
  {
     object *inv;
     int i, size;
     inv = all_inventory(Me);
     size = sizeof(inv);
     if(size)
     {
       write("Your minion has the following:\n");
     }
     else
     {
       write("Your minion is carrying:\n = Nothing = \n");
       return 1;
     }
     for(i= 0; i < size ; i++)
     {
       tell_object(master, sprintf(" = %s =\n", inv[i]->query("short")));
      }
    return 1;
    break;
  }
     //case "coins": dunno money system yet exactly.
     //case "sense": kool for agressives or good aligned/bad aligned chac's
 }
//** Going to non-standard commands.
    sscanf(str, "%s %s", str, arg); 
  
 switch(str){
// Name change.
    case "name":
    {
      if(!arg)
      {
        tell_object(master, "Your minion's name is "+Me->query("cap_name"));
        return 1;
       }
      if(user_exists(arg) || find_living(arg))
      {
        tell_object(master,
             "You are not allowed to name your minion that.\n");
        return 1;
       }
      if(strlen(arg) > 11)
      {
        tell_object(master,
             "Please keep your minion's name to less than eleven characters.\n");
        return 1;
      }
      tell_object(master,
          sprintf("Your minion accepts %s new name of %s",
             possessive(query("gender")), capitalize(arg)));
      //Temporary fix
      Me->set("name", arg);
      Me->set("cap_name", capitalize(arg));
      Me->add("id", arg);
      return 1;
      break;
    }
// Start following
    case "follow":
    {
      object ob;
      if(arg == "me" || !arg) arg = master->query("name");
      ob = present(arg, environment(Me));
     
      if(!ob)
      {
        tell_object(master, "Your minion can't seem to find that to follow.\n");
        return 1;
      }
       if(ob == fol && isFollowing)
      {
        tell_object(master,
          sprintf("Your minion is already following %s.\n",
            (ob == master) ? "you" : ob->query("name")));
        return 1;
       }
      tell_object(master,
          sprintf("Your minion begins to follow %s.\n",
            (ob == master) ? "you" : ob->query("name")));
      set_following(ob);
      isFollowing = 1;
      return 1;
      break;
    }
    
// Start protecting. 
   case "protect" :
   {
     object ob;
     if(arg == "me" || !arg) arg = master->query("name");
     ob = present(arg, environment(Me));
     if(!ob)
     {
       tell_object(master, "Your minion can't protect what is not there.\n");
       return 1;
     }
     tell_object(master,
      sprintf("Your minion begins protecting %s.\n",
       (ob == master) ? "you" : ob->query("name")));
     set_protect(ob);
     Protect = 1;
     return 1;
     break;
   }
     
//** Stop doing shit.
   case "stop":
   {
     if(!arg)
     {
       tell_object(master, "Your minion doesn't know what to stop.\n");
       return 1;
       break;
      }
     switch(arg)
     {
// Stop following
      case "following":
       {
        if(!isFollowing)
        {
          tell_object(master,
             "Your minion isn't following anyone at this time.\n");
          return 1;
         }
         tell_object(master,
             sprintf("Your minion ceases to follow %s.\n",
                (fol == master) ? "you" : fol->query("cap_name")));
         isFollowing = 0;
         return 1;
         break;
       }
// Stop protecting.
      case "protect":
      case "protecting":
      {
        if(!Protect)
        {
          tell_object(master, "Your minion isn't protecting anyone.\n");
          return 1;
        }
        tell_object(master,
          sprintf("Your minion stops protecting %s.\n",
            (pro == master) ? "you" : pro->query("name")
            )
            );
        Protect =  0;
        return 1;
        break;
      }
      default:
      {
        tell_object(master, "Your minion can't stop doing that.\n");
        break;
      }
    }
  }
// The default command for the minion.
// This is where it can do the kool stuff.
    default:
    {
      if(!Me->force_me(sprintf("%s%s", str, arg)))
      {
       return failed_command();
       break;
      }
    }
  
   }
// Something fucked up.
  return (int) notify_fail("*Minion command failed, contact Zur.\n");
 }
void die()
{
   tell_object(master, "You mind explodes in ungodly pain as you companion dies.\n");
   set_restrained(0);
   remove_call_out("fake_heart_beat");
   //Later will add some fuck_you_up code *grin*
 }
void add_exp(int i)
{
  master->add_exp(i);
}
int failed_command()
{
   tell_object(master, "Your minion doesn't understand that command.\n");
   return 1;
 }
int leave()
{  
  tell_object(master,
    "The magics within the wand have faded, causing you to lose control of your minion.\n");
  remove();
  return 1;
 }
string Diagnostic()
 {
    return sprintf(
         "Name:%s\nOwner:%s\nTotal lifespan:%d\nTime remaining:%d\nProtecting:%s\n"+
         "\tWho:%s\nFollowing:%s\n\tWho:%s\nDone.\n",
           Me->query("cap_name"),
           master->query("cap_name"),
           Lifespan,
           Lifespan - Time,
           (Protect) ? "yes" : "no",
           (pro) ? pro->query("cap_name") : "none",
           (isFollowing) ? "yes" : "no",
           (fol) ? fol->query("cap_name") : "none"
           );
 }
 
 //*** Just a temporary measure to test the shit out.
 //    In the "real" version, this will take place in a spell.
 //    Or simmilar command.
 
 int restrain_me(string str)
 {
    object ob;
    if(!str) return (int) notify_fail("Restrain who?\n");
    ob = present(str, environment(this_player()));
    if(!ob) return (int) notify_fail("Can't restrain something that ain't here.\n");
    if(!living(ob)) return (int)
          notify_fail("Tell, me: do you really need to restrain that?\n");
    write("You restrain the soul of "+ob->query("cap_name")+".\n");
    set_restrained(ob);
    set_master(this_player());
    tell_object(ob, "You have been restrained by "+this_player()->query("cap_name")+".\n");
    call_out("fake_heart_beat", 1);
    return 1;
 }
    
 
 
 object query_master(){ return master; }
 object query_following(){ return fol; }
 object query_protected(){ return pro; }
 
 int query_lifespan(){ return Lifespan; }
 int query_time_expired(){ return Time; }
 int query_time_left(){ return (Lifespan - Time); }
 int query_protecting(){ return Protect; }
 int query_isfollowing(){ return isFollowing; }
