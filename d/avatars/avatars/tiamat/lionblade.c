#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Lionblade");
	set_id(({ "sword", "scimitar", "lionblade" }));
	set_short("%^YELLOW%^Li%^RESET%^%^ORANGE%^o%^YELLOW%^nbl%^RED%^a%^YELLOW%^de%^RESET%^");
	set_obvious_short("%^RESET%^%^YELLOW%^a golden-hilt %^RESET%^scimitar%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This impressive curved blade demonstrates the height of a weaponsmith's skill. Forged from strong steel, the deadly curve of the scimitar is as thick as six inches at its widest, and tapers to a sharp point at the end. The hilt is forged from %^RESET%^%^ORANGE%^copper%^YELLOW%^, and decorated with gold. It curves in an S-shape to protect the wielder's fingers but allows freedom of movement at the wrist. The tang is wound in golden filament to provide a sturdy grip. The pomel of the sword is a highly decorated golden lion head with %^BOLD%^%^RED%^ruby%^YELLOW%^ eyes.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(450);
	set_lore(
@AVATAR
The weapon you are studying is known as a Lionblade. Legend says they were often wielded by Tsarven warrior-priests in a time now lost to history. The artifacts are highly prized among the upper-class in Azha today, who tend to view them as heirlooms from their distant ancestors. They believe the blades have the capacity to drive evil away from their homes.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^YELLOW%^The blade wielded by "+ETOQCN+" sends a mighty %^RED%^ROAR%^YELLOW%^ at "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^Your blade sends a deafening %^RED%^ROAR%^YELLOW%^ at the enemy!");
	tell_object(targ,"%^YELLOW%^You are stunned by a lion's %^RED%^ROAR%^YELLOW%^ emitted from "+ETOQCN+"'s blade!%^RESET%^");
		targ->set_paralyzed(roll_dice(15,0)+0);
return 0;	}
}