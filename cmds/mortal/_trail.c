#include <std.h>
object who;

int cmd_trail(string str){

    if(member_array("Order of the Metallic Dragon",TP->query_guild()) < 0) return 0;

    if(!str) return notify_fail("Syntax: trail <person>\n");

    if(!(who=present(str, ETP))) return notify_fail("The person has to be in the room before you can follow them.\n");

    if(who == TP) return notify_fail("You can't trail yourself.\n");

    if(!who->add_follower(TP)) return notify_fail("You can't trail someone who is following you.\n");

    tell_object(TP, "You catch "+who->query_cap_name()+"'s trail and start to follow "+who->query_objective()+".");

    if( (int)who->query_stats("wisdom") > random(30) ) {
	tell_object(who, "You have a strange feeling...  it's like you're being...  followed.\n");
    }

    return 1;
}
