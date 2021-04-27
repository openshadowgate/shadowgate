#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Scales of Chromatic Dragon");
	set_id(({ "scales", "robe", "gown", "scale" }));
	set_short("%^BOLD%^%^RED%^Scales of C%^GREEN%^hr%^BLUE%^om%^WHITE%^at%^BLACK%^ic %^RED%^Dragon%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Scales of C%^GREEN%^hr%^BLUE%^om%^WHITE%^at%^BLACK%^ic %^RED%^Dragon%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^Scales of C%^GREEN%^hr%^BLUE%^om%^WHITE%^at%^BLACK%^ic%^RED%^ dragon%^RESET%^%^BOLD%^%^RED%^ are an artifact bound to the immortal Tiamat.  In her draconic form, she wears the scales around her body, taking on the colors of white, blue, red, black and green dragons along each of her five heads.  In humanoid form, the scales become a multihued gown of draconic scales, shifting in color with her movements.  If this item should somehow fall into the hands of a mortal, please <offer> the item or ask for an immortal to take them away.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(5000);
	set_lore(
@AVATAR
Tiamat (pronounced TEE-a-maht), also known as the Nemesis of the Gods, is the queen of evil dragons and a member of the Untheric pantheon. Like most other draconic deities, she is the offspring of the dragon creator deity Io. Tiamat is also the eternal rival of her brother Bahamut, ruler of the good metallic dragons.

AVATAR
	);
	set_property("lore difficulty",10);
	set_max_internal_encumbrance(200);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",5);
	set_ac(35);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 900){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^Tiamat blasts her enemy with a quintet of %^GREEN%^b%^BLUE%^r%^BLACK%^e%^WHITE%^at%^RED%^h weapons!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^You blast your enemy with a quintet of %^GREEN%^b%^BLUE%^r%^BLACK%^e%^WHITE%^at%^RED%^h weapons!");
	tell_object(who,"%^BOLD%^%^RED%^You are overwhelmed by a quintet of %^GREEN%^b%^BLUE%^r%^BLACK%^e%^WHITE%^at%^RED%^h weapons!");
		who->do_damage("torso",roll_dice(20,12));
return damage;	}

}
