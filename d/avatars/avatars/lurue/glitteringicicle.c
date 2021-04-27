#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("shard of ice");
	set_id(({ "icicle", "shard of ice", "ice shard", "glittering icicle", "shard" }));
	set_short("%^BOLD%^%^CYAN%^G%^WHITE%^l%^BLUE%^i%^CYAN%^tte%^WHITE%^r%^BLUE%^i%^CYAN%^ng I%^WHITE%^c%^BLUE%^i%^CYAN%^cle%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^shard of ice%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This spear is little more then a long, slender length of pure ice crystals formed from the snowmelt and refrozen by the cold air.  About six feet long from one end to the other, the spear is more lance like in shape, having a large base and a dangerously sharp point at the other end.  Rainbows of light %^WHITE%^s%^CYAN%^p%^BLUE%^a%^WHITE%^rk%^CYAN%^l%^WHITE%^e %^CYAN%^within the core, catching the light and sending it dancing about the area with bright flashes and muted colors.  A thin sheaf of leather has been affixed around the middle and ornamented with colorful %^BLUE%^b%^WHITE%^e%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLUE%^d%^WHITE%^s %^CYAN%^along the joint, giving the wielder a bit of protection against the icy cold of the weapon.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(300);
	set_lore(
@AVATAR
Most would claim that these weapons were evil because they are most often found in the hands of Gelugon, or ice devils as they are sometimes called.  Others say they are the work of Auril or Talos, pointing to the often violent depictions of the beads upon the grip.  The truth is less impressive.  The weapons were first created during a storm that had landlocked a group of young adventurers in a large cave high in the northern mountains.  There, they were beset by several yeti who wanted their cave.  The yeti's ability to freeze and then break metal caused a great distress for the young band, until the halfling Tiekin was flung into an icicle and it broke, providing him with a weapon immune to the yeti's attacks.  Since then, many who patrol the north have taken to using such weapons, using the beads to make a space between their hands and the shards of ice. 

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("piercing");
	set_prof_type("spear");
	set_size(3);
	set_wc(2,6);
	set_large_wc(3,4);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You shiver as you take up the frozen weapon!%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^Putting the weapon aside, you begin to feel %^YELLOW%^warmth%^BLUE%^ returning to your fingers.%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+" jabs their weapon forward into "+targ->QCN+" and a spray of ice crystals explodes all around!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You jab the weapon forward into "+targ->QCN+" and a spray of ice crystals explodes all around!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" jabs their weapon forward into you and a spray of ice crystals explodes all around!  The whole world seems to freeze and your body trembles with the cold!%^RESET%^");
		return roll_dice(3,4)+3;	}

}
