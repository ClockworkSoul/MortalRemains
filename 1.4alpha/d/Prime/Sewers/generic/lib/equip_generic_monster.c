#include <mudlib.h>
#include "../GenericLib.h"
#include EQUIP_GENERIC_MONSTER_HEADER

// inherit ARMOR;


string equip_type;
void equip_generic_monster(object equip, object monster){
    equip->move(monster);
    monster->wear(equip);
}

object create_generic_armour(){
    return clone_object(GArmDir+"generic_armour.c");
}

string random_equip_type(){
    int equip_type_int;
    equip_type_int = random(NUMBER_OF_EQUIP_TYPES);
    switch (equip_type_int){
    case 0:
	equip_type = "Plate";
	break;
    case 1:
	equip_type = "Shield";
	break;
    case 2:
	equip_type = "Helmet";
	break;
    case 3:
	equip_type = "Gloves";
	break;
    case 4:
	equip_type = "Cloak";
	break;
    case 5:
	equip_type = "Amulet";
	break;
    case 6:
	equip_type = "Ring";
	break;
    case 7:
	equip_type = "Boots";
	break;
    }
    return equip_type;
}

string random_equip_material(){
    string equip_material;
    int equip_material_int;
    equip_material_int = random(NUMBER_OF_EQUIP_MATERIALS);
    switch (equip_material_int){
    case 0:
	equip_material = "steel";
	break;
    case 1:
	equip_material = "copper";
	break;
    case 2:
	equip_material = "bronze";
	break;
    case 3:
	equip_material = "iron";
	break;
    }    
    return equip_material;
}

/*

    Plate              4           5               6
    Shield            2           3               4             
    Helmet            1           2               -
    Gloves            1           2               -
    Cloak             1           -               -
    Amulet            1           -               2
    Ring              1           2               3
    Boots             1           1               -

    */


void set_equip_properties(string equip_type, string equip_material){
    int iValue;
    mixed *aValueArray;
    string *aTypeArray;
    iValue = create_equip_value(equip_type, equip_material);
    aValueArray = ({ iValue, "gold"});
    if (equip_type=="Plate")
	aTypeArray = ({ "Plate", "mail", "Plate", "Mail", "Armour" });
    else
	aTypeArray = ({ equip_type, lower_case(equip_type) });
    set("id", aTypeArray);
    set("short", create_equip_short(equip_type, equip_material));
    set("long", create_equip_long(equip_type, equip_material));
    /*
	set("armor", create_equip_ac(equip_type, equip_material));
	set("mass", create_equip_weight(equip_type, equip_material));
	    set("value", aValueArray);
	*/
}

string create_equip_short(string equip_type, string equip_material){
    string article;
    string equip_type_lowercase;
    if (equip_type == "Plate")
	return "a suit of " + equip_material + " mail";
    equip_type_lowercase = lower_case(equip_type);
    if ((equip_type == "Boots")||(equip_type == "Gloves"))
	article = "a pair of ";
    else article = "a ";
    return article + equip_material + " " + equip_type_lowercase;
}

string create_equip_long(string equip_type, string equip_material){
    string article;
    string equip_type_lowercase;
    if (equip_type == "Plate")
	return "A suit of " + equip_material + " mail\n";
    equip_type_lowercase = lower_case(equip_type);
    if ((equip_type == "Boots")||(equip_type == "Gloves"))
	article = "A pair of ";
    else article = "A ";
    return article + equip_material + " " + equip_type_lowercase + "\n";
}

int create_equip_ac(string equip_type, string equip_material){
    if (equip_type == "Plate")
	return 4;
    if (equip_type == "Shield")
	return 2;
    else
	return 1;
}

int create_equip_weight(string equip_type, string equip_material){

    int equip_weight_base;
    int equip_weight_modifier;

    if (equip_type == "Plate")
	equip_weight_base = 5;
    else if (equip_type == "Shield")
	equip_weight_base = 3;
    else if ((equip_type == "Helmet")||(equip_type == "Cloak")||(equip_type == "Boots"))
	equip_weight_base = 2;
    else equip_weight_base = 1;


    if (equip_material == "copper")
	equip_weight_modifier = 0;
    else if (equip_material == "bronze")
	equip_weight_modifier = 1;
    else if (equip_type == "iron")
	equip_weight_modifier = 3;
    else if (equip_type == "steel")
	equip_weight_modifier = 0;

    return equip_weight_base + equip_weight_modifier;
}

int create_equip_value(string equip_type, string equip_material){
    int equip_value_base;
    int equip_value_modifier;

    if (equip_type == "Plate")
	equip_value_base = 3750;
    else if (equip_type == "Shield")
	equip_value_base = 1700;
    else if (equip_type == "Helmet")
	equip_value_base = 1000;
    else equip_value_base = 500;

    if (equip_material == "copper")
	equip_value_modifier = 1;
    else if (equip_material == "bronze")
	equip_value_modifier = 2;
    else if (equip_material == "iron")
	equip_value_modifier = 3;
    else equip_value_modifier = 4;

    return (equip_value_base * 2 - (equip_value_base / equip_value_modifier));
}


