//Coded by Hades//
#include <std.h>
#include <daemons.h>
inherit OBJECT;
int uses;
void create(){
    ::create();
    set_id(({"jar","crystal jar",""}));
    set_name("scry summon jar");
    set_short("A crystal jar");
    set_long(
        "This is a crystal jar.  Magical energy swirls around in it. "+
		"A cork keeps it closed.  \n"
        "A tiny inscription written on it."
    );
    set_weight(5);
    set_value(5000);
    uses = 99;
}
void init(){
    ::init();
    add_action("read","read");
    add_action("pop","pop");

}
void read(string str){
    string tmp;
    if(!str && str != "jar") return notify_fail("Read what?  The jar?\n");
    write("This is a jar of scry summoning.  It has the following function:\n"
        "<pop cork> summons your scrier(1 charges)\n"+
        uses+" charges left"
    );
    return 1;
}
void pop(string str){
    object ob, peeper;
    if(uses < 99) return notify_fail("The jar is out of charges.\n");
    if (ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",TP);
       return 1;
    }
    if(!str) return notify_fail("pop what?  The cork?\n");
    if(!( present("ShadowListener", ETP))) 
	     return notify_fail("Nothing happens.  You put the cork back on.\n");

	//ob->force_me("say testing");
   // if(!ETO->is_class("mage") && !ETO->is_class("bard") &&
   //    !ETO->is_class("thief")) 
   // return notify_fail("Only arcane spellcasters and"+
    //           " rogues can use this.\n");
   // if(ETO->is_class("mage"))
    
	peeper = present("ShadowListener",ETP)->query_mycaster();
	tell_room(EETO,"There is a sucking noise as "+peeper->QCN+ 
	 " is pulled in by the power of the jar.");
	peeper->move_player(EETO);
	tell_object(peeper,"You feel yourself being sucked into your own scrying!");

    uses += 1;
    return 1;
}
