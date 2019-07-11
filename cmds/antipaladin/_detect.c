#include <std.h>
 
// Detect evil for Anti-Paladins
// By Grazzt@Shadowgate Sept 1996
 
inherit DAEMON;
 
int cmd_detect(string str) {
    object ob;
    object *inv;
    int x,a;
 
    if(!str) {
        notify_fail("Detect what?\n");
        return 0;
    }
    if(!TP->is_class("antipaladin")){
        notify_fail("You are not a Anti-Paladin and cannot do that!\n");
        return 0;
    }
    if(str != "good") {
        notify_fail("You cannot detect that.\n");
        return 0;
    }
    write("%^BLUE%^"
	"You concentrate on the area around you.%^RESET%^");
    say("%^BLUE%^"
        +this_player()->query_cap_name()+
	" concentrates deeply for a moment.%^RESET%^"
    ,this_player());
    inv = all_inventory(environment(this_player()));
    for(x=0;x<sizeof(inv);x++) {
        if(!living(inv[x])) continue;
        else if(wizardp(inv[x])) continue;
        else if(avatarp(inv[x]) && inv[x]->query_invis()) continue;
        a = (int)inv[x]->query_alignment();
        if (a == 1 || a == 4 || a == 7) {
            write("%^RED%^"
	        +(string)inv[x]->query_cap_name()+
	        " gives off the sickening aura of good!%^RESET%^"
	    );
        }
        continue;
    }
    this_player()->set_disable(1,TP);
    return 1;
}
