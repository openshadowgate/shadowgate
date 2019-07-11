// Hints Daemon
// Gives hints out on apropos subjects.
// Thorn@ShadowGate
// 20 September 2001
// /daemon/hint_d.c

#include <std.h>
#include <security.h>

// DEBUG mode enabled on 1, 0 is off.  Make sure and set DEBUGGER
// to yourself if you are testing this.
#define DEBUG 0
#define DEBUGGER "thorn"

// #define SAVE_FILE "/daemon/save/hints"

// 
#define HDIR "/doc/hints"
#define HPROP "hints"

inherit DAEMON;

void initialize_daemon();

string *files;
mapping hints;

void create() {
    ::create();

  initialize_daemon();
}

void initialize_daemon() {
	string *list;
	string temp;
	string data;
	string *lines;
	mixed *info;
	int x;
	
	hints = ([ ]);
	files = ({ });
	list = stat(HDIR+"/");
	for(x=0;x<sizeof(list);x++) {
		temp = list[x];
		info = stat(HDIR+"/"+temp, -1);
		if((int)info[1] == -2) continue;
		files += ({ temp });
		if(DEBUG)
        tell_object(find_player(DEBUGGER), temp);
		data = read_file(HDIR+"/"+temp);
		lines = explode(data, "\n");
		hints[temp] = lines;
	}
	if(DEBUG)
		tell_object(find_player(DEBUGGER), 
			"\nInitialization complete.\n");
	return;
}

mapping dump() {
	return hints;
}

string get_hint(string *apropos) {
	int num, x;
	string *hnts, *list, err;
	
	list = ({ });
	if(apropos) {
		for(x=0;x<sizeof(apropos);x++) {
			if(member_array(apropos[x], keys(hints)) == -1)
				continue;
			list = list + ({ apropos[x] });
		}
	} 
	else {
		list = keys(hints);
	}
	if(!list)
		return "*ERR: No such hint file.";
	num = sizeof(list);
	hnts = hints[list[random(num)]];
	num = sizeof(hnts);
	return hnts[random(num)];
}

int hint(object user, string topics) {
	string hint, retval;
	string *tlist;
	
	if(!user->getenv("HINTS")) return 0;
	if(topics) {
		tlist = explode(topics, " ");
		hint = get_hint(tlist);
	}
	else hint = get_hint(0);
	message("hint", "%^BOLD%^GREEN%^<hint>%^RESET%^ "+hint+"\n", user);
	return 1;
}
