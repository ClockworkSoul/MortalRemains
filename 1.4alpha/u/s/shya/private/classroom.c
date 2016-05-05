//This was created by Shya as a surprise for a teacher July 15, 2000//

inherit ROOM;

object blackboard;

void create() {
 
    seteuid(getuid());
    ::create() ;
    set("author", "shya");
    set("light", 1);
    set("short", "Mr. Shallar's Classroom.");
    set("long", @ENDTEXT
You walk in to the room and notice the classroom is in chaos, 
students throwing paper airplanes and playing loud music. 
There are two big black boards at the front of the room,
with writing on them. Maybe you should 'read' them.
Along the wall behind the desk are bookshelves covered in books.
There is a roll-away map on one side of the room.
ENDTEXT
);
    blackboard = clone_object("/u/s/shya/private/bboard.c") ;
      blackboard->move(TO) ;
  set("listen" , "You hear loud music coming from the back of the room.\n");
    set("smell", "You catch a wiff of chalk dust.\n");
    set("item_desc", ([
      "room" : "An ordinary classroom.\n",
      "classroom" : "An ordinary room with two black boards.\n",
      "students" : "Twenty or so kids waiting to learn.\n",
      "paper" : "A thin, flexible material in sheets.\n",
      "airplanes" : "Paper folded into aerodynamic flying machines.\n",
      "music" : "Loud noise which some people call music.\n",
      "globe" : "A model map of the earth.\n",
      "map" : "A picture representation of the United States of America.\n",
      "desk" : "A solid oak desk covered with papers and a globe on the corner.\n",
      "bookshelves" : "Covered with encyclopedias and books dealing with U.S. History.\n",
      "books" : "Recorded events in U.S. History.\n",
      "encyclopedias" : "A set of books with alphabetically arranged articles of U.S. History.\n",
      "chair" : "Solid oak to match the desk and bookshelves.\n",
      "papers" : "Looks like some graded reports done by the students.\n" 
    ]) );
}

void init() 
{
 add_action("read_func", "read");
 add_action("sit_func", "sit");
}

int read_func( string str ) {
    string name;

    if (!str) {
 write("Read what?\n");
	return 1;
    }
if (str!="book") {
	return 0;
    }
write("You read a book about U.S History.\n");
return 1;
}
int sit_func ( string str )
{
string dowhat;
string towhat;

if (!str) {
    write("Sit towhat?\n");
    return 1;
}
if (sscanf(str, "%s %s", dowhat, towhat) ==2 ) {
    if (towhat == "chair") {
        if (dowhat == "in")
            write ("You sit in the chair.\n");
        return 1;
 } 
       else if (dowhat == "at")
            write ("You pull up a chair and take a seat at the desk.\n");
        return 1;
    }
return 0;
}