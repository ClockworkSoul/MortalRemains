
void stuff() {
  ::create();
    seteuid(getuid());
  set( "light", 1 );
  set("short","Castle Fields");
  set( "long", @EndText
You are standing amidst a huge corn fields that seems to be the bulk of the castles
stapple crops. Rows of fresh corn grow for miles and you hear a lot of squeeking
going on in the field. A large flag waves at the entrance to the fields.
EndText
  );
 set ("item_desc", ([
"squeeking" : "You fail to hear see any squeeking but you seem to hear it fine.\n",
"corn" : "Fresh corn on every stalk.\n",
"rows" : "Rows of corn as far as the eye can see.\n",
"stalks" : "The stalks support the corn as it grows.\n",
"eyes" : "You cant make out what they belong to, maybe you should poke the hole.\n",
"hole" : "You look in the hole and you see a pair of beedy eyes!\n",
]) ) ;
rnum=3;
::reset();
}
void reset(){poked=0;}
void init(){
add_action("hole","poke");
}
int hole(string str){
if(!str){ write("Poke what");return 1;}
if(str="hole"){
  object rat1;
rat1 = present("rat", TO);
if(rat1){ //rat is still here
write("You try to poke your hand into the hole but the rat wont let you near it!\n");
rat1->kill_ob(TP);
rat1->set("agressive", 1);
return 1;
}
if(poked==rnum){  //there are no more rats in hole.
write("You poke your hand into the hole but pull it back out covered in dirt.\n");
return 1;
}
if(!rat1){
write("You poke your hand in the hole and hear a squeek!\nA large rat enters.\n");
rat1=clone_object(MON(rat.c));
rat1->move(TO);
num=poked+1;
poked = num;
if(poked==rnum){add("items_desc/hole", "You look into the hole and see dirt.\n");return 1;}
}
}
}
