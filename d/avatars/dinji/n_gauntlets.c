
#include <std.h>
inherit ARMOUR;
string owner;

void create(){
   ::create();
	set_name("nature's grip");
	set_id(({"gauntlets","nature's grip","nature gauntlets","leather gauntlets"}));
	set_property("enchantment",2);
	set_obvious_short("%^RESET%^%^GREEN%^light green gauntlets%^RESET%^");
	set_short("%^RESET%^%^GREEN%^Nature's Grip%^RESET%^");
	set_long("These gauntlets are made from light leather. They"+
	" have been dyed green for easy blending into natural backgrounds"+
	". Although light, the gauntlets seem to offer a fair bit of"+
	" protection with the extra padding layed over the knuckles and"+
	" back of the hand.");
	set_type("leather");
	set_limbs(({"right hand","left hand"}));
	set_weight(3);
	set_value(10000);
	set_lore("These gauntlets were worn by the legendary Akadian"+
	" ranger, Alveric. Alveric traveled often and to many"+
	" different places. On one of his journies, he met a"+
	" tribe of wild elves locked in a stalemate with a"+
	" large band of ogres. Alveric turned the tide of the"+
	" battle in the elves favor and left these gauntlets"+
	" behind with the elves. Since then they have been"+
	" passed from hand to hand when the need arised.");
	set_property("lore",6);

   set_wear((:TO,"wear":));
   set_remove((:TO,"remove_me":));
}

int wear(){
	if(!ETO->is_class("ranger")) {
	tell_object(ETO,"They simply do not fit.");
	return 0;
	}else{
	tell_object(ETO,"%^RESET%^%^GREEN%^Your hands slip right in%^RESET%^.");
	ETO->add_attack_bonus(1);
	return 1;
	}
}

int remove_me(){
	ETO->add_attack_bonus(-1);
	return 1;
}
