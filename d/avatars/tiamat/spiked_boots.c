#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("spiked boots");
	set_id(({ "boots", "boot", "shoe", "shoes", "spiked boots" }));
	set_short("%^RESET%^%^ORANGE%^S%^WHITE%^p%^ORANGE%^i%^WHITE%^k%^ORANGE%^e%^WHITE%^d %^ORANGE%^Boots%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^hiking boots%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a pair of rugged hiking boots.  They are made from thick leather
that has been broken in long ago and will fit comfortably.  The laces are
also made of durable leather, and tie up around the ankles.  The bottoms of
the boots are covered in tiny, wicked spikes.  They would make climbing
through rough terrain easier, but could also inflict quite a lot of pain.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1300);
	set_lore(
@AVATAR
Although not particularly attractive, hiking boots like these require some
relatively refined smithing technology to manufacture.  Long ago, when
Druids walked the forests surrounding Shadow, they approached the dwarves
of Echo Mountains and asked them to make superior gear for their Ranger
allies.  A few of these boots remain, the finer examples having been
enchanted long ago.

AVATAR
	);
	set_property("lore difficulty",9);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^ORANGE%^laces up their boots tightly%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You lace up the boots tightly%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^ORANGE%^struggles, then finally removes the hiking boots%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^With a little grunt, you finally remove the boots%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 180){
	tell_room(environment(query_worn()),""+ETOQCN+" %^RESET%^%^ORANGE%^counters the attack with a spiked kick at "+who->QCN+"%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^You counter the attack with a swift, spiked kick!%^RESET%^");
	tell_object(who,""+ETOQCN+" %^RESET%^%^ORANGE%^answers your attack with a swift kick from their spiked boots!%^RESET%^");
		who->do_damage("torso",random(4));
return damage;	}
}