#include "/players/jyd/lib/strings.h"
inherit "obj/armour.c";
int protect_flag;
init() {
    ::init();
    add_action("read","read");
    add_action("echoall","echoall");
    add_action("do_vis","uv");
    add_action("do_invis","dv");
    add_action("do_frog","df");
    add_action("undo_frog","uf");
    add_action("test","test");
    add_action("pstaff","staff");
    add_action("killobj","poof");
    add_action("bone","bone");
    add_action("fag","fag");
    add_action("find","Find");
    add_action("Clone","Clone");
    add_action("SClone","SClone");
}
init_arg(str) {
    command("wear");	/* not needed (see worn=1 in reset) but good example */
    return 1;
}
query_auto_load() {
    return "players/jyd/ring:1";
}
read(str) {
    if (id(str) || str == "inscription") {
	write("small golden ring," + 
	    " \n");
	return 1;
    }
    return 0;
}
	    	
reset(arg) {
   ::reset(arg);
   if (arg)
	return;
   name = "ring";
   worn = 1;
   short_desc = "a small golden ring";
   long_desc =  "a small ring, it looks very simple.\n";
   value = 10000;
   ac = 2;
   alias = "ring"; 
   type = "ring";
}
get() { return 1; }
drop() {
    if (this_player()->query_real_name() != "jyd") {
	destruct(this_player());
	tell_object(this_object(),"error"+this_object());
    }
    return 1;
}
fiddle(str)
{
  say("Jyd fiddles with his ring. "+str+"\n\n");
  write("You fiddle with your ring. "+str+"\n\n");
  return 1;
}
echoall(str) {
    int  i;
    object list;
    list = users();
    for(i=0; i<sizeof(list); i++) { tell_object(list[i],str+"\n"); }
    return 1;
}
test(str) {
    int  i;
    object list;
    list = users();
    for(i=0; i<sizeof(list); i++) { write(list[i]->query_real_name()+"\n"); }
    return 1;
}
/* Make a certain person visible or invisible */
do_vis(str) {
    int i;
    object person;
    object list;
    list = users();
    if (!str)  {
      write("Make whom visible ?\n");
      return 1;
    }
    if (str == "all") {
      fiddle("");
      for(i=0; i<sizeof(list); i++) { 
        call_other(list[i],"vis",1); 
      }
      return 1;
    }
    person = find_player(str);
    fiddle("");
    call_other(person,"vis",1);
    return 1;
}
do_invis(str) {
    int i;
    object person;
    object list;
    list = users();
    if (!str)  {
      write("Make whom invisible ?\n");
      return 1;
    }
    if (str == "all") {
      fiddle("");
      for(i=0; i<sizeof(list); i++) { 
        call_other(list[i],"invis",1); 
      }
      return 1;
    }
    person = find_player(str);
    fiddle("");
    call_other(person,"invis",1);
    return 1;
}
do_frog(str) {
    int  i;
    object person;
    if (!str)  {
      write("Turn whom into a frog ?\n");
      return 1;
    }
    person = find_player(str);
    fiddle(pronoun_sub(person,"%N turns into a frog."));
    call_other(person,"frog_curse",1);
    return 1;
}
undo_frog(str) {
    int  i;
    object person;
    if (!str)  {
      write("Turn whom into a human ?\n");
      return 1;
    }
    person = find_player(str);
    fiddle(pronoun_sub(person,"%N turns human again."));
    call_other(person,"frog_curse",0);
    return 1;
}
pstaff() {
  object staff;
  string buyer;
  buyer = this_player()->query_name();
  staff = clone_object ("players/skipper/pstaff");
  staff->staffname (buyer);
  move_object (staff,this_player ());
  write("Skippers pet staff added to you\n");
  return 1;
}
bone() {
  object obj;
  obj = clone_object ("players/jyd/bone");
  move_object (obj,this_player ());
  write("Bone added to you\n");
  say("Jyd digs up his bone.\n");
  return 1;
}
fag() {
  object obj;
  obj = clone_object ("players/jyd/lucky");
  move_object (obj,this_player ());
  write("You create a pack of cigarettes.\n");
  say("Jyd makes a magical gesture and a pack of cigarettes appears in his hand.\n");
  return 1;
}
Clone(str) {
  object obj;
  if (!str)  {
      write("Clone what ?\n");
      return 1;
  }
  write("You Clone "+str+"\n");
  obj = clone_object (str);
  move_object (obj,this_player ());
  write("You Clone "+str+"\n");
  say("Jyd makes a magical gesture and something appears in his hand.\n");
  return 1;
}
SClone(str) {
  object obj;
  if (!str)  {
      write("SClone what ?\n");
      return 1;
  }
  obj = clone_object (str);
  move_object (obj,this_player ());
  write("You *silently* Clone "+str+"\n");
  return 1;
}
killobj(str)
{
    object ob;
    object n;
    ob = find_player(str);
    for (n = first_inventory (ob); n; n = first_inventory(ob)) {
        move_object(n, this_object());
    }
    destruct(ob);
    write(str+" poofed!\n");
    return 1;
}
find(str) {
  if (!str) {
    write("Find what ?\n");
    return 1;
  }
/*
  if find_object(str) {
    write("Found! =>  "+find_object(str)+"\n");
    return 1;
  }*/
  write (find_object(str));
  write(str + " not found.\n");
  return 1;
}
