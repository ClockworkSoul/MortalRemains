// File: adminp.c
// Added in TMI 1.2.1 to accommodate a reorganization of admin structure
//
// Returns 1 if object has admin privilege; 0 otherwise

#define ELDER "adminaccess"

int adminp( mixed ob_or_str ) {
    if ((stringp(ob_or_str) &&
          (int)master()->query_member_group(ob_or_str, ELDER)) ||
        (objectp(ob_or_str) &&
          (int)master()->query_member_group(geteuid(ob_or_str), ELDER)))
        return 1;
    return 0;
}
