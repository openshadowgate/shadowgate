#include <std.h>
inherit "/std/weapon";
create() {
    ::create();
    set_name("longsword");
    set_id(({"longsword","black longsword","long sword","black sword","sword"}));
    set_short("%^BLUE%^Black longsword%^RESET%^");
    set_long(
	"This is one of the standard %^BOLD%^%^BLACK%^black "
	"longswords%^RESET%^ used by the lower ranks of the Drow "
	"Regime. However it still is an amazingly crafted weapon and "
	"emanates magical properties."
    );
    set_weight(5);
    set_size(2);
    set_value(50);
    set_wc(1,8);
    set_large_wc(1,12);
    set_type("slashing");
    set_property("enchantment",1);
    set_wield((: TO,"drow" :));
}
int drow() {
    if(TP->query_highest_level() < 5) {
        write(
	    "This weapon is to complex for one of your level to wield!"
	);
	return 1;
    }	
   if((string)TP->query_race() != "Drow" && (string)TP->query_race() != "drow"){
        write(
            "You feel a %^BOLD%^%^YELLOW%^shock%^RESET%^ run through your "
	    "body as you wield the sword!"
        );
        TP->do_damage("torso",roll_dice(2,6));
      TP->add_attacker(TO);
      TP->continue_attack();
      TP->remove_attacker(TO);
        return 1;
    }
    return 1;
}
