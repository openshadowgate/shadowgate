#include <std.h>
inherit DAEMON;

int cmd_unwield(string str) {
    object ob, myplayer;
    string unwieldf;
    function f;
 
    if(!str) return notify_fail("Unwield what?\n");

    if (TP->query_bound()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(!ob = present(str,TP)) {
          return notify_fail("You don't have that!\n");    
    }

    if(!ob->query_wielded())
      return notify_fail("You are not wielding that!\n");
    if(ob->query_property("enchantment") && (int)ob->query_property("enchantment") < 0){
    	write("The curse on this item prevents you from unwielding it.");
    	return 1;
    }
    ob->__ActuallyUnwield();
    return 1;
}

int help()
{
	write("Usage: <unwield [weapon_name]> \n\n"+
	"This command will remove the given weapon_name "+
	"from whatever limb you are wielding it in.");
	return 1;
}