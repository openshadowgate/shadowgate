#include <std.h>
inherit "/std/armour";
object owner;
int uses;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TPQN;
    uses = 5;
}
create() {
    ::create();
    set_name("ring");
    set_id(({"ring","gold ring","golden ring","ring of flying"}));
    set_short("%^YELLOW%^Golden ring%^RESET%^");
    set_long(
	"%^YELLOW%^This is small golden ring that is very light in weight. "
	"Traced around the outer band of the ring are small %^MAGENTA%^"
	"purple runes%^YELLOW%^. There is no indication if the ring is "
	"magical in nature or just a decorative piece of jewelry.%^RESET%^"
    );
    set_weight(1);
    set_value(500);
    set_type("clothing");
    set_limbs(({"right hand","left hand"}));
    set_ac(0);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    if((int)TP->query_level() < 21) {    
        notify_fail("The magic of the ring rejects you!");
	TO->remove();
        return 0;
    }
    if(TP != owner) {
	notify_fail("The ring fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    write(
        "%^YELLOW%^A strange energy begins to flow through your body!%^RESET%^"
    );
    say(
	"%^YELLOW%^"+TPQCN+" slips on a golden ring.%^RESET%^"
    ,TP);	
    TP->set_property("demongate flying",1);
    uses = uses - 1;
    return 1;
}
int removeit() {
    if(uses < 1) {
	write("%^YELLOW%^As you remove the golden ring it vanishes!%^RESET%^");
	say("%^YELLOW%^As "+TPQCN+" removes a golden ring, it vanishes!%^RESET%^",TP);   
	TO->remove();
    }
    TP->remove_property("demongate flying",1);
    return 1;
}
