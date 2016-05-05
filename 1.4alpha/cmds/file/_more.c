/*
// The new more command.
// Much more efficient, we hope.
// Apr 30 1997 Zur changed to check for a ".c"
// (04-06-98) Chronos squashed the "no argument error" bug.
//            - Also rewrote the help function.
*/

#include <mudlib.h>

string help() ;

inherit DAEMON ;


int cmd_more(string str) {
   seteuid( geteuid( this_player() ) );
/* Shame on whoever coded this for forgetting this line! - Chronos */
   if (!str) {
     write(help() ) ;
     return 1;
  }
   if(!this_player()->more(str))
   {
   if(extract(str, strlen(str)-2, strlen(str)-1) != ".c") str += ".c";
  return (int)this_player()->more(str);
  }
  //seteuid( getuid() );
  return 1;
}

string help() {
  return @ENDHELP

Usage: more <filename>

The more command prints files to the screen in 20-line chunks.  Between
each 20-line segment, the "More-" prompt appears.  The following commands
can be issued at that prompt:

space 	show the current 20 lines again.	u	backs up 20 lines.
return	shows the next 20 lines.		b	backs up 20 lines.
d 	go down 20 lines.			#	go to absolute line #.
d #	go down # lines.			b #	back up # lines.
q	escape from the file.			?	display the help file.
/str	find next occurance of <str>		e<file>	more <file>.
m#	set a "MARK" at this point.		p#	set the page length.
g# 	return to a previously defined "MARK"	!cmd	execute a cmd
ENDHELP
;
}
