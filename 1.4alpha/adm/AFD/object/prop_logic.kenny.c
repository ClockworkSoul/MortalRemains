// This file is a part of the standard object system devised by Buddha.
// Currently under development. 
 
// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Buddha@TMI, modularized and revised (92-05-01)
// Expanded to use a superior security system by Buddha (92-05-31)
// Temporary flag attribute system added by Watcher (93-02-21)
// Altered by Pallando @ Tabor (93-03-17)

// converted _set and _delete to for-loops and changed _query kenny@xenocide 7jul93
// cleaned up 1sep93 (optimize using while loops)

#define	UNDEFINED	([])[0]
 
nomask
private
static
mixed
_query(mapping map, string *parts) {
	mixed value;
	int i, s;
 	value=map;
	s=sizeof(parts)-1;
	i=-1;
	while(++i<s)
		if(undefinedp(value=value[parts[i]]) || !mapp(value))
			return UNDEFINED;
	return value[parts[i]];
}

nomask
private
static
int
_delete(mapping map, string *parts) {
	mixed value;
	int i, s;
	value=map;
	s=sizeof(parts)-1;
	i=-1;
	while(++i<s)
		if(undefinedp(value=value[parts[i]]) || !mapp(value))
			return 0;
	map_delete(value, parts[i]);
	return 1;
}

nomask
private
static
mixed
_set(mapping map, string *parts, mixed value) {
	mixed tmp, old_val;
	int i, s;
	tmp=map;
	s=sizeof(parts)-1;
	i=-1;
	while(++i<s) {
		if(!mapp(tmp[parts[i]]))
			tmp[parts[i]]=([ ]);
		tmp=tmp[parts[i]];
	}
	old_val=tmp[parts[i]];
	tmp[parts[i]]=value;
	return old_val;
}
