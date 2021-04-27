#include <std.h>
inherit ARMOUR;

int FLAG;

void create(){
	::create();
	FLAG = 0;
	set_name("mask");
	set_id(({ "mask", "cat mask" }));
	set_short("%^BOLD%^%^BLACK%^Cat Mask%^RESET%^");
	set_obvious_short("black mask");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A half-mask that has been fashioned out of a very light metal.  The mask is in the image of the upper face of a cat. Long points come up on each side of the upper part of the mask to resemble the ears of a cat.  The lower ends of the mask tapper down to a fine point, offering protection for your ears.  The metal has been coated with a black enamle, giving it a depth of color.  The feline eyes of the mask are slanted and covered with a thin layer of crystal, to protect your eyes.  It seems the mask can either sit ontop of your head, or you can pull it down to cover your eyes.%^RESET%^
AVATAR
	);
	set_weight(3);
	set_value(125);
	set_lore(
@AVATAR
The Cat Mask was gifted to a human female who gained the attention of the Lord of Felines for sometime.  Sadly there is no record of who the female was or what happened to her.
AVATAR
	);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
void init() {
    	::init();
    	add_action("say_func","say");
}
int wear_func(){
	if((int)ETO->query_level() < 10) {
   	notify_fail("You are not skilled enough to know how to use this item!");
    	return 0;
   }
	FLAG = 1;
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" "+
		"slips on the mask "+
		"and releases a purr from their lips.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip on the mask "+
		"and get the urge to purr.");
   ETO->add_sight_bonus(4);
	return 1;
}
int remove_func(){
	FLAG = 0;
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" "+
		"slips off the mask and frowns",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip off the "+
		"mask and feel rather dull.");
   ETO->add_sight_bonus(-4);
	return 1;
}
int query_size(){
    if(!objectp(ETO) || !living(ETO)) return 2;
    return ETO->query_size();
}
int say_func(string str) {
	string msg;
   msg = str;
   if(ETO->query_gagged() || ETO->query_paralyzed()) return 0;
   if(!query_worn()) return 0;
   if(FLAG == 0) {
   	return 0;
   }else {
   	if (!str) {
      	tell_object(ETO,"%^BOLD%^%^GREEN%^You meow.%^RESET%^");
         tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" smiles "+
         	"enigmatically and then meows for no apparent reason.",ETO);
          	return 1;
    	}else {
    		if((string)ETO->query_name() != "diego") {
   			msg = "daemon/language_d"->translate(msg,ETO->query_spoken(),ETO);
    		}
         message("say","%^RESET%^%^ORANGE%^Y%^YELLOW%^o%^RESET%^%^ORANGE%^u p%^YELLOW%^u%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^: %^CYAN%^"+msg,ETO);
      	message("say","%^RESET%^%^ORANGE%^"+ETOQCN+" p%^YELLOW%^u%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^s%^YELLOW%^:%^RESET%^ %^CYAN%^"+msg,environment(ETO),ETO);
         return 1;
     	}
  	}
}
