// Cyanide 17 May 98

int cmd_unwear ( string str ) {
    seteuid(getuid());

    return
    "/cmds/std/_unequip.c"->cmd_unequip(str);
}
