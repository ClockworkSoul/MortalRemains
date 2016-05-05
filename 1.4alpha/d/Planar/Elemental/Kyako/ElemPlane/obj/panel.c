#include <mudlib.h>
#include "plane.h"

inherit OBJECT;

int *Anspl = ({ 0,0,0,0,0,0,0,0 }) ;
int *Ansact = ({1, 12, 6, 70, 2, 9 , 0 , 12 }) ;
int var;

void create() {
  seteuid(getuid());
  set("short", "a panel");
  set("long", @Panel
This is a panel. It appears to be made out of water,
but it remains substantial.
You see 8 displays with numbers in them.
To see what they read, type list.
Good luck!

Commands are: list, choose <letter>, push button, help panel
Panel
  );
  set("name", "panel");
  set("author", "kyako");
  set("id", ({ "panel", "stone panel" }) );
  set("prevent_get", 1) ;
}

void init() {
  add_action("choose", "choose");
  add_action("push", "push");
  add_action("list", "list");
  add_action("help_panel", "help");
}

int set_var(int i){
  int valuenum;
  sscanf(i, "%d", valuenum);
  Anspl[var] = valuenum;
  return 1;
}

int choose(string str) {
  if (str == "A") {
    write("Enter the value for spot A.\n");
    write("Your value is: ");
    var = 0;
    input_to("set_var");
    return 1;
  }
  if (str == "B") {
    write("Enter the value for spot B.\n");
    write("Your value is: ");
    var = 1;
    input_to("set_var");
    return 1;
  }
  if (str == "C") {
    write("Enter the value for spot C.\n");
    write("Your value is: ");
    var = 2;
    input_to("set_var");
    return 1;
  }
  if (str == "D") {
    write("Enter the value for spot D.\n");
    write("Your value is: ");
    var = 3;
    input_to("set_var");
    return 1;
  }
  if (str == "E") {
    write("Enter the value for spot E.\n");
    write("Your value is: ");
    var = 4;
    input_to("set_var");
    return 1;
  }
  if (str == "F") {
    write("Enter the value for spot F.\n");
    write("Your value is: ");
    var = 5;
    input_to("set_var");
    return 1;
  }
  if (str == "G") {
    write("Enter the value for spot G.\n");
    write("Your value is: ");
    var = 6;
    input_to("set_var");
    return 1;
  }
  if (str == "H") {
    write("Enter the value for spot H.\n");
    write("Your value is: ");
    var = 7;
    input_to("set_var");
    return 1;
  }
  return 0;
}

int list() {
  write("Current selections are:\n\n");
  write("| A   | B   | C   | D   | E   | F   | G   | H   |\n");
  printf("| %-3d | %-3d | %-3d | %-3d | %-3d | %-3d | %-3d | %-3d |\n",
  Anspl[0], Anspl[1], Anspl[2], Anspl[3], Anspl[4], Anspl[5], Anspl[6], Anspl[7]);
  return 1;
}

int push(string str) {
  if (str == "button") {
    if (Anspl[0] == Ansact[0] && Anspl[1] == Ansact[1] && Anspl[2] == Ansact[2] && Anspl[3] == Ansact[3] && Anspl[4] == Ansact[4] && Anspl[5] == Ansact[5] && Anspl[6] == Ansact[6] && Anspl[7] == Ansact[7]) {
      write("You have all the correct answers!\n");
      write("You're very smart!\n");
      TP -> move_player(PLANE+"stuffroom.c");
      Anspl = ({ 0,0,0,0,0,0,0,0 });
      return 1;
    } else {
      write("Your answers aren't all right!\n");
      write("Try again!\n");
      return 1;
    }
    return 1;
  }
  return 1;
}

int help_panel(string str) {
  if (!str || str != "panel") return 0 ;
  write(@ENDHELP
Place your answers using the command
choose <letter>
Your letter must be capitalized or it will not work!
Use the "list" command to see your current choices.
When you think you have the correct answer, type
push button
Type "help panel" to see this message.
ENDHELP
 );
 return 1;
}
