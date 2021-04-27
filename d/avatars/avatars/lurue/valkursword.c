#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("gleaming cutlass");
	set_id(({ "cutlass", "captain's cutlass", "gleaming cutlass", "sword", "gleaming sword" }));
	set_short("%^BOLD%^%^BLUE%^C%^CYAN%^a%^RESET%^%^BLUE%^p%^BOLD%^t%^RESET%^a%^CYAN%^i%^BOLD%^%^BLUE%^n%^CYAN%^'%^BLUE%^s C%^BLACK%^u%^CYAN%^t%^RESET%^%^BLUE%^l%^CYAN%^a%^BOLD%^%^BLUE%^ss%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLUE%^g%^WHITE%^l%^CYAN%^e%^RESET%^%^CYAN%^a%^BLUE%^m%^BOLD%^i%^BLACK%^n%^BLUE%^g %^RESET%^%^CYAN%^sword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This gleaming sword is made out of what appears, at first, to be pure water.  The long curved blade constantly shifting and swirling with all the %^BLUE%^s%^CYAN%^h%^RESET%^%^CYAN%^a%^BLUE%^d%^WHITE%^e%^BOLD%^%^CYAN%^s %^BLUE%^o%^RESET%^%^CYAN%^f %^BLACK%^%^BOLD%^b%^BLUE%^l%^CYAN%^u%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^.  For the hilt a pale piece of living %^MAGENTA%^c%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^r%^MAGENTA%^al%^WHITE%^ forms the grip and guard, wrapping the hand in its protective embrace, while polished pieces of %^BLACK%^a%^BLUE%^b%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^lo%^RESET%^%^GREEN%^n%^BLACK%^%^BOLD%^e %^WHITE%^offer a smooth hold for one's hand.  On the pommel a large, cloudy pearl can be seen, its glossy l%^CYAN%^u%^WHITE%^mi%^BLACK%^n%^WHITE%^es%^MAGENTA%^c%^CYAN%^e%^WHITE%^nce glittering with %^RESET%^%^MAGENTA%^m%^CYAN%^y%^WHITE%^s%^MAGENTA%^ti%^BLUE%^c%^MAGENTA%^al %^WHITE%^%^BOLD%^power.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(10000);
	set_lore(
@AVATAR
This swirling blade of water is known as the Captain's Cutlass and was plucked from the deepest waters of the Saakrune, down where the deepest of secrets can be found.  Formed by magic, the edge of the blade is so thin that the water can cut and tear through most anything.  The coral comes from the Dagger Sea and continues to grow and replenish itself through the magic that imbues the water.  While the pearl that adorns the pommel seems to have been formed from where the waters of the world reflected the sky.  Its gray-blue aura swirling constantly as though reflecting a vision of the realm.  This sword was created with care and love and given to Valkur in celebration for his reaching full Avatar status.  Congrats!

AVATAR
	);
	set_property("lore difficulty",40);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",10);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^Is that the ocean you smell?%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The sound of the ocean fades away.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^A howling %^BLACK%^v%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^t%^BLACK%^e%^BLUE%^x of water engulfs "+targ->QCN+", dragging them down into the abyss of Davey Jones' Locker!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The roar of the tide.. %^WHITE%^The howl of the wind.. %^BLUE%^The strike of the sword!  %^RESET%^%^CYAN%^Water explodes in a drowning vortex around "+targ->QCN+" as you strike them for daring to attack.  %^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^As "+ETOQCN+" strikes you with their "+query_short()+"%^BOLD%^%^BLUE%^, a howling %^BLACK%^v%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^t%^BLACK%^e%^BLUE%^x of water springs up around you, dragging you down into Davey Jones' Locker!%^RESET%^");
		return roll_dice(2,10)+1;	}

}
