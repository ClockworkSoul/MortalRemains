#include <mudlib.h>
#include "../GenericLib.h"
#include POPULATE_GENERIC_MONSTERS_HEADER

inherit GLibDir+"arm_generic_monster.c";
inherit GLibDir+"equip_generic_monster.c";

/* Populates monsters into a room */
void populate_generic_monsters(object room){
  int i,j;
  object *monster_array;
  monster_array = random_generic_monster();
  i = sizeof(monster_array);
  for(j=0;j<i;j++) monster_array[j]->move(room);
}

/* Returns an array of monsters (eventually to go into a room) */
object *random_generic_monster(){
  int monsters,i;
  object *monster_array;
  object monster;
  monster_array = ({});
  monsters = random(MAX_GENERIC_MONSTERS);
  for(i=0;i<monsters;i++){
    monster = create_generic_monster();
    arm_generic_monster(create_generic_weapon(), monster);
    equip_generic_monster(create_generic_armour(), monster);
    monster_array = monster_array + ({monster,}); 
  }  
  return monster_array;
}

object create_generic_monster(){
  string monster_file_name;
  int monster_type;
  object monster;
  monster_type = random(NUMBER_OF_GENERIC_MONSTER_TYPES);
  monster_file_name = get_generic_monster_file(monster_type);
  monster = clone_object(monster_file_name);
  return monster;
}
/* Returns a monster file, based on the integer argument */
string get_generic_monster_file(int monster_type){
  string monster_file;
  switch(monster_type) {
  case 0:
    monster_file = GMonDir+"human.c";
    break;
  case 1:
    monster_file = GMonDir+"orc.c";
    break;
  case 2:
    monster_file = GMonDir+"kobold.c";
    break;
  case 3:
    monster_file = GMonDir+"skeleton.c";
    break;
  case 4:
    monster_file = GMonDir+"zombie.c";
    break;
  case 5:
    monster_file = GMonDir+"ghoul.c";
    break;
  }
  return monster_file;
}
