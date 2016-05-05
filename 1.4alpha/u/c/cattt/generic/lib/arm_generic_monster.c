#include <mudlib.h>
#include "../GenericLib.h"
#include ARM_GENERIC_MONSTER_HEADER

// inherit WEAPON;

void arm_generic_monster(object weapon, object monster){
  //  move_object(weapon, monster);
  weapon->move(monster);
  //  monster->init_command("wield "+ weapon->query_name());
  monster->command("wield "+weapon->query("name"));
}

object create_generic_weapon(){
  return clone_object(GWepDir+"generic_weapon.c");
}

string random_weapon_type(){
  string weapon_type;
  int weapon_type_int;
  weapon_type_int = random(NUMBER_OF_WEAPON_TYPES);
  switch (weapon_type_int){
  case 0:
    weapon_type = "Thrust";
    break;
  case 1:
    weapon_type = "Crush";
    break;
  case 2:
    weapon_type = "Slash";
    break;
  case 3:
    weapon_type = "Cleave";
    break;
  }    
  return weapon_type;
}

string random_weapon_material(){
  string weapon_material;
  int weapon_material_int;
  weapon_material_int = random(NUMBER_OF_WEAPON_MATERIALS);
  switch (weapon_material_int){
  case 0:
    weapon_material = "steel";
    break;
  case 1:
    weapon_material = "silver";
    break;
  case 2:
    weapon_material = "bronze";
    break;
  case 3:
    weapon_material = "iron";
    break;
  }    
  return weapon_material;
}

void set_weapon_properties(string weapon_type, string weapon_material){
  string name;
  name = create_weapon_name(weapon_type);
  set("author", "grull");
  set("name", name);
  set_weapon_type(create_weapon_alias(weapon_type));
  set_material_type("metal/" + weapon_material);
  set("short", create_weapon_short(weapon_type, weapon_material));
  set("long", create_weapon_long(weapon_type, weapon_material));
  set("id", ({ name, }) );
  //set_length(create_weapon_length(weapon_type));
  //set_wc(create_weapon_class(weapon_type, weapon_material));
  //set_weight(create_weapon_weight(weapon_type, weapon_material));
  //set_value(create_weapon_value(weapon_type, weapon_material));

  // I decided to be cute on this one. This relies on boolean
  // truth evaluating to '1'.
  set("nosecond", (weapon_type == "Thrust") );

}

string create_weapon_short(string weapon_type, string weapon_material){
  if (weapon_type == "Thrust")
    return "a " + weapon_material + " spear";
  else if (weapon_type == "Crush")
    return "a " + weapon_material + " mace";
  else if (weapon_type == "Slash")
    return "a " + weapon_material + " sword";
  else if (weapon_type == "Cleave")
    return "a " + weapon_material + " axe";
}

string create_weapon_long(string weapon_type, string weapon_material){
  if (weapon_type == "Thrust")
    return "A " + weapon_material + " spear.\n";
  else if (weapon_type == "Crush")
    return "A " + weapon_material + " mace.\n";
  else if (weapon_type == "Slash")
    return "A " + weapon_material + " sword.\n";
  else if (weapon_type == "Cleave")
    return "A " + weapon_material + " axe.\n";
}

int create_weapon_length(string weapon_type){
  if (weapon_type == "Thrust")
    return 60;
  else if (weapon_type == "Crush")
    return 24;
  else if (weapon_type == "Slash")
    return 36;
  else if (weapon_type == "Cleave")
    return 40;
}

string create_weapon_name(string weapon_type){
  if (weapon_type == "Thrust")
    return "spear";
  else if (weapon_type == "Crush")
    return "mace";
  else if (weapon_type == "Slash")
    return "sword";
  else if (weapon_type == "Cleave")
    return "axe";
}

string create_weapon_alias(string weapon_type){
  if (weapon_type == "Thrust")
    return "spear";
  else if (weapon_type == "Crush")
    return "mace";
  else if (weapon_type == "Slash")
    return "sword/short";
  else if (weapon_type == "Cleave")
    return "axe/hand";
}

int create_weapon_class(string weapon_type, string weapon_material){

  int weapon_class_base;
  int weapon_class_modifier;

  if (weapon_type == "Thrust")
    weapon_class_base = 3;
  else if (weapon_type == "Crush")
    weapon_class_base = 5;
  else if (weapon_type == "Slash")
    weapon_class_base = 4;
  else if (weapon_type == "Cleave")
    weapon_class_base = 6;


  if (weapon_material == "silver")
    weapon_class_modifier = 0;
  else if (weapon_material == "bronze")
    weapon_class_modifier = 1;
  else if (weapon_type == "iron")
    weapon_class_modifier = 2;
  else if (weapon_type == "steel")
    weapon_class_modifier = 4;

  return weapon_class_base + weapon_class_modifier;
}

int create_weapon_weight(string weapon_type, string weapon_material){

  int weapon_weight_base;
  int weapon_weight_modifier;

  if (weapon_type == "Thrust")
    weapon_weight_base = 12;
  else if (weapon_type == "Crush")
    weapon_weight_base = 8;
  else if (weapon_type == "Slash")
    weapon_weight_base = 4;
  else if (weapon_type == "Cleave")
    weapon_weight_base = 6;


  if (weapon_material == "silver")
    weapon_weight_modifier = 0;
  else if (weapon_material == "bronze")
    weapon_weight_modifier = 1;
  else if (weapon_type == "iron")
    weapon_weight_modifier = 2;
  else if (weapon_type == "steel")
    weapon_weight_modifier = 4;

  return weapon_weight_base + weapon_weight_modifier;
}
  
int create_weapon_value(string weapon_type, string weapon_material){
  return create_weapon_class(weapon_type, weapon_material)*15;
}




