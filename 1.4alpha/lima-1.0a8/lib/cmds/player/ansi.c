/* Do not remove the headers from this file! see /USAGE for more info. */

//  Yaynu@Lima Bean
#include <mudlib.h>
inherit CMD;
inherit M_ANSI;

private void main(string arg)
{
    if ( !arg )
    {
	string ansistate;
	if ( i_use_ansi() )
	    ansistate = ansi( "on");
	else
	    ansistate = "off";

	out ("Ansi is " + ansistate + ".\n");
	return;
    }

    if ( arg == "on" )
    {
	this_user()->query_shell_ob()->set_variable("ansi", 1);
	out("Turning ansi on.\n");
    }
else if (arg == "off")
    {
	this_user()->query_shell_ob()->unset_variable("ansi");
	out("Turning ansi off.\n");
    }
    else
    {
	out("Usage: ansi <on/off>.\n");
	return;
    }
    this_user()->update_translations();
}                                    

void player_menu_entry(string str)
{
    bare_init();
    main(str);
    done_outputing();
}
