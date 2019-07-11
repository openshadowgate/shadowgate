#include <std.h>
inherit DAEMON;


int cmd_unwear(string str) {
	return "/cmds/mortal/_remove"->cmd_remove(str);
}
