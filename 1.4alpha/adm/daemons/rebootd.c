/*
**  Reboot daemon written for Nightfall's Keep by Cyanide
**  12 June 1997.
*/

#include <mudlib.h>
#include <uid.h>
#include <config.h>
#include <logs.h>
#include <daemons.h>

int count_down = 28800;     //Default = 8 hours.

inherit TIME_D;
inherit DAEMON;

// Prototypes...
void doomsday();
int find_time_left();

// Don't want this cleaning up with callouts pending.
int clean_up() {
    if (find_call_out("doomsday")>-1) {
	return 1 ;
    }
    ::clean_up() ;
}


void create() {
    seteuid(ROOT_UID);

    // Determine the time left to next reboot in seconds.
    count_down = find_time_left();

    // Begin count down to Armageddon...
    call_out("doomsday", count_down);

}

static void doomsday() {
    PURGE_D->process_users(-1,0,0,0);

    SHUTDOWN_D-> start_shutdown(0, 60, "TIMED REBOOT", 1);
#ifdef SHUTDOWN_LOG
    log_file(SHUTDOWN_LOG, wrap("Reboot daemon initiated scheduled"+
	" shutdown ["+extract(ctime(time()),4,15) + "]"));
#endif
}

int find_time_left() {
    int sec, min, hour, *reboot_time, i;
    mixed *time;

    reboot_time = REBOOT_TIMES;

    time = localtime(query_tzone("EST"));
    sec = time[0];
    min = time[1];
    hour = time[2];

    // Convert the current time to seconds after midnight.
    sec = (hour*3600) + (min*60) + sec;

    count_down = 0;
    for (i=((sizeof(reboot_time))-1); i>=0; i--)
	if (sec < reboot_time[i])
	    count_down = (reboot_time[i] - sec);

	// If the current time is later than the last listed reboot time,
	// then figure out how long until the FIRST reboot of the day...
    if (count_down == 0)
	count_down = reboot_time[0] + (86400 - sec);

    return count_down;     //Return time to next reboot.
    //Redundant, but useful.
}
