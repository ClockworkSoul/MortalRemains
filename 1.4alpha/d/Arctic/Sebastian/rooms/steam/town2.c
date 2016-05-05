#include <mudlib.h>
#include <steamtown.h>

inherit ROOM;
void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("light", 1);
	set("short", CITY_NAME+" , Ventnor Ave.\n");
	set("long", @Foo
	Ah, Ventnor Avenue.  Truly the pinnacle of Steam driven
technology.  High rise apartment complexes completely occupy this
corner of Steam Town proper.  People rush past you, wearing elegant
clothing, and expensive accessories.  There is very little dirt or
filth to be seen in this corner of Steam Town, truly a masterpiece
of community living!
Foo
);
	set("item_desc",([
	"avenue":"A high-income, high rent area of Steam Town.\n",
	"apartment":"Places like the 'Frump Tower' and such fill the sky.\n",
	"complexes":"A veritable cornucopia of living spaces.\n",
	"corner":"Ventnor Ave. is the upper class corner of Steam Town.\n",
	"people":"If it weren't for the guards, this place would be"+
	"a thief's dream.\n",
	"clothing":"Names like 'Gucci', 'Tommy Orcfinger' and DKMR flood"+
	"your vision.\n",
	"accessories":"Rodex watches, dragonskin boots, and snow"+
	"leopard skin purses are all around you.\n",
	"dirt":"Not a speck can be seen, anywhere.\n",
	"filth":"No scum, no rust, no decrepid buildings, anywhere.\n"
	]));
	set("safe", 1);
	set("exits",([
	"south":M_ROOM+"town3.c",
	"east":M_ROOM+"town1.c"
	]));
}
