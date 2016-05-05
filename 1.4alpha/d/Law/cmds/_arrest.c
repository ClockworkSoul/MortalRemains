/*
**  _arrest.c
**  The admin arrest command for bad wizards and stuff.
**  Cyanide 12 June 1997
*/

#include <mudlib.h>

#define JAIL "/d/Law/room/jail.c"

int cmd_arrest (string con) {
  object ob;

  if (!con) {
    write ("Arrest who?\n");
    return 1;
  }

  ob = find_player(con);
  if (!ob) {
    write (capitalize(con)+" is not on this mud.\n");
    return 1;
  }

  write(ob->query("cap_name")+" arrested and imprisoned.\n");
  say(TPN+" gestures at "+ob->query("cap_name")+
".\nThe ground beneath "+ob->query("cap_name")+" opens up, and "+
"swallows "+objective(ob->query("gender"))+" alive!\n", ob);
  tell_object(ob, TPN+" gestures at you.\n"+
    "Suddenly, the ground opens and swallows you alive!\n"+
    "You find yourself elsewhere.\n\n");

  ob->move_player(JAIL, "SNEAK");
  return 1;
}
