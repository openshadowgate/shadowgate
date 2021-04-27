#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("tainted blade");
	set_id(({ "sword", "two handed sword", "tainted", "two-handed sword" }));
	set_short("%^BOLD%^%^BLACK%^Shadow taint%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A massive black bladed sword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a huge sword, requireing two hands to wield. The long straight blade is about five and a half feet in length with a blood grove running almost the whole length. Twisted runes are inscribed in the grove the metal around them is warped as if the inscription has somehow been changed. The lines of stressed metal from this warping process only add to the intimidating nature of the weapon. The base of the blade is wraped in %^RESET%^%^ORANGE%^le%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ther%^BOLD%^%^BLACK%^ allowing a hand to be placed there for more leverage in combat, a pair of spikes just above this give the hand some protection against a weapon sliding down onto the hand. The grip is also %^RESET%^%^ORANGE%^le%^BOLD%^%^BLACK%^ather which at places is beginning to come away revealing the dark bare metal beneath. The pommel shows the most warping, the simple round steel counterwieght, common on weapons of this kind, is now a gaping %^BOLD%^%^WHITE%^sk%^RESET%^%^WHITE%^u%^BOLD%^%^WHITE%^ll%^BOLD%^%^BLACK%^ with dark %^RESET%^%^RED%^red%^BOLD%^%^BLACK%^ eyes.  

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Remember your %^RESET%^%^WHITE%^oath%^BOLD%^%^RED%^, your %^BOLD%^%^GREEN%^betrayal %^BOLD%^%^RED%^and know you can never go back %^RESET%^%^RED%^slave%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(20000);
	set_lore(
@AVATAR
This is the ancient sword of the noble D'Velik family. After he accepted the taint in return for immortality Harrold D'Velik watched his weapon change with each of his old freind and soldiers slain by it. He moved throughout his own camp, killing the men under his command who refused to join him in darkness. Is is rumoured to be a very powerful weapon, capable of throwing opponents to the ground with ease.

AVATAR
	);
	set_property("lore difficulty",19);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(large);
	set_wc(4,6);
	set_large_wc(4,6);
	set_property("enchantment",5);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 280){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^ "+ETOQCN+" uses the flat of thier "+query_short()+" to smash "+targ->QCN+" across the chest, throwing them to the ground.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Gripping the sword by the leather above the crosspiece you slam the flat of the blade against your foe throwing them to the ground.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^ "+ETOQCN+" smashes you in the chest with the flat of thier "+query_short()+" throwing you to the ground!%^RESET%^");
		targ->set_paralyzed(roll_dice(8,0)+0);
return 0;	}

}
