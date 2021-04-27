#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("snowfall circlet");
	set_id(({ "circlet" }));
	set_short("%^RESET%^%^BOLD%^%^CYAN%^Sn%^WHITE%^ow%^CYAN%^fall %^WHITE%^Cir%^CYAN%^cl%^WHITE%^et%^RESET%^");
	set_obvious_short("A white circlet");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^THis circlet is made out of ice!  A thick covering of frost cakes teh ice circlet.  The ice crystals have been pressed together, making the circlet rather thick.  The circlet is simple in design, an ice band that travels around one's head.  In the middle of the circlet the ice has been carved into a diamond shape.  Deep within the diamond ice is one large %^WHITE%^snowflake%^CYAN%^ that has been perfectly preserved.  Somthing seems to keep the ice from melting.

AVATAR
	);
	set_weight(4);
	set_value(1000);
	set_lore(
@AVATAR
The Snowfall Circlet is gifted only to those that the Frostmaiden favor.  It is said that any unworthy soul who tries to wear it is found the next day dead, frozen through.  

AVATAR
	);
	set_type("chain");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" slips on a white circlet.  %^WHITE%^Frost%^CYAN%^ cakes their hair!",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You slip on the circlet and feel the cold comforting feeling of the ice against your skin.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" removes a white circlet and begins to shiver fiercly as the frost melts from their hair.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You slip off the circlet and feel a blast of warm air, oddly enough chilling you to the bone!");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^A ray of frost strikes "+who->QCN+"",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^A ray of frost is emited from the circlet and strikes "+who->QCN+"");
	tell_object(who,"%^BOLD%^%^CYAN%^Brrrrr You are hit with a ray of frost!");
		who->do_damage("torso",random(10));
return damage;	}
}