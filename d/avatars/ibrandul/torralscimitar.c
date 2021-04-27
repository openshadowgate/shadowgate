#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^T%^RESET%^%^CYAN%^w%^RESET%^%^BOLD%^is%^CYAN%^t%^RESET%^%^BOLD%^ of %^GREEN%^F%^RESET%^%^BOLD%^a%^GREEN%^t%^RESET%^%^BOLD%^e%^RESET%^");
	set_id(({ "sword", "scimitar", "dragon fang", "twist of fate" }));
	set_short("%^RESET%^%^BOLD%^T%^RESET%^%^CYAN%^w%^RESET%^%^BOLD%^is%^CYAN%^t%^RESET%^%^BOLD%^ of %^GREEN%^F%^RESET%^%^BOLD%^a%^GREEN%^t%^RESET%^%^BOLD%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^dr%^RESET%^a%^BOLD%^gon %^BLACK%^f%^RESET%^%^BOLD%^an%^RESET%^g %^BLACK%^%^BOLD%^%^scimitar%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Crafted out of dragon fangs, this%^RESET%^%^CYAN%^ scimitar %^BOLD%^%^WHITE%^is a true masterpiece. The hilt is haped in the form of a %^YELLOW%^dragon%^WHITE%^. It holds the blade of the sword in its mighty %^RED%^jaws %^WHITE%^and its outspread %^BLACK%^wings %^WHITE%^form the cross piece. Engraved into the curved blade is picture of a %^MAGENTA%^knave's %^WHITE%^face. On the left side of the knave is a %^GREEN%^deck of cards %^WHITE%^and on the right is a %^BLUE%^pair of dice%^WHITE%^. The edge is jaggedly serrated, making the blade look like a %^RED%^f%^YELLOW%^l%^RED%^a%^YELLOW%^m%^RED%^e%^WHITE%^. A sparkling %^BLUE%^sapphire %^WHITE%^has been set as pommel, held in the claws of the %^YELLOW%^dragon%^WHITE%^.

AVATAR
	);
	set_weight(4);
	set_value(75000);
	set_lore(
@AVATAR
crafted by a legendary weaponsmith with a thousand names, this blade is said to be formed from fangs he ripped from a black dragon's jaw himself

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,4);
	set_large_wc(2,4);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ grips the "+query_short()+"%^BLACK%^%^BOLD%^ grimly%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You grip the "+query_short()+"%^BLACK%^%^BOLD%^ grimly%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ lets go of the "+query_short()+"%^BLACK%^%^BOLD%^ slowly%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You let go of the "+query_short()+"%^BLACK%^%^BOLD%^ slowly%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BLACK%^%^BOLD%^AS "+ETOQCN+"%^BLACK%^%^BOLD%^ slices deeply into "+targ->QCN+"%^BLACK%^%^BOLD%^, the "+query_short()+"%^BLACK%^%^BOLD%^ suddenly covers with b%^RESET%^l%^BLACK%^%^BOLD%^ack ac%^GREEN%^i%^BLACK%^%^BOLD%^d%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BLACK%^%^BOLD%^As you rip the "+query_short()+"%^BLACK%^%^BOLD%^ across "+targ->QCN+"%^BLACK%^%^BOLD%^'s body, b%^RESET%^l%^BLACK%^%^BOLD%^ack ac%^GREEN%^i%^BLACK%^%^BOLD%^d covers the blade, soaking "+targ->QCN+"%^RESET%^");
	tell_object(targ,"%^BLACK%^%^BOLD%^As "+ETOQCN+"%^BLACK%^%^BOLD%^ slices into you, your body burns from b%^RESET%^l%^BLACK%^%^BOLD%^ack ac%^GREEN%^i%^BLACK%^%^BOLD%^d from the "+query_short()+"%^RESET%^");
		return roll_dice(2,4)+-1;	}
}