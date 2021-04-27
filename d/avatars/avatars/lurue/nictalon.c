#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("wicked looking claws");
	set_id(({ "claw", "claws", "talon", "talons", "devil's trade", "devil's trade talons" }));
	set_short("%^BOLD%^%^BLACK%^D%^RED%^e%^BLACK%^v%^GREEN%^i%^BLACK%^l%^RED%^'%^BLACK%^s Tr%^GREEN%^a%^BLACK%^de T%^RED%^a%^BLACK%^l%^RED%^o%^BLACK%^ns%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^w%^GREEN%^i%^BLACK%^ck%^RED%^e%^BLACK%^d l%^RED%^o%^GREEN%^o%^BLACK%^k%^RED%^i%^BLACK%^ng s%^GREEN%^e%^BLACK%^t of cl%^RED%^a%^BLACK%^ws%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^A leather half glove holds these wicked looking talons in place. %^BOLD%^%^BLACK%^Black leather %^RESET%^%^CYAN%^has been used to make the half glove that fits snuggly around the hand, the fingers of which have been clipped away and neatly hemmed for comfort.  A thin layer of %^BOLD%^%^BLACK%^black cotton padding %^RESET%^%^CYAN%^lines the inside and dark metal rivets hold the metal talons in place.  Four lengths extend several inches beyond the fingertips, while a fifth, shorter, decorative one coils along the curve of the thumb.  Their long, sleek, black lengths curling tightly over the span of the fingers as though they extended from the wrist itself.  Sharp tips glint sickeningly with a %^GREEN%^dull-green color%^CYAN%^, while the edges of each talon are razor sharp and serrated.  A very wicked looking weapon indeed.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(1000);
	set_lore(
@AVATAR
Despite their lofty title, these claws are of mundane origin.  Forged in the work shops of master smiths and enchanted by the maji of the Ruuntan, they are worn as an off-handed weapon by the elite guards of the Ruuntan.  Wielding heavy bastard swords, their fighting style was a mixture of dance and swift blade skill that often resulted in their opponents leaving their belly or side unguarded as their opponent put all effort into blocking the Ruuntan's bladed attack.  Thus making a devil's trade as the sharp claws drove into their exposed flanks.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("talons");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" gives a slight shiver as they secure the "+query_short()+" %^RESET%^%^CYAN%^in place.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The cold metal of the talons curls along the top of your fingers as you slip the "+query_short()+" %^RESET%^%^CYAN%^on.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" peels the tight glove of the "+query_short()+" %^RESET%^%^CYAN%^free from their hand and looks a little lost.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You peel the gloved of the "+query_short()+" %^RESET%^%^CYAN%^free and feel as though something is suddenly missing.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^CYAN%^The tips of "+ETOQCN+"'s "+query_short()+" %^RESET%^%^CYAN%^glint a sickening %^GREEN%^green%^RESET%^%^CYAN%^ as they catch "+targ->QCN+" with their flank exposed.  Turning swiftly "+ETOQCN+" rakes their talons across "+targ->QCN+"'s vulnerable spot! %^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^CYAN%^The tips of the "+query_short()+" %^RESET%^%^CYAN%^glint a sickening %^GREEN%^green%^RESET%^%^CYAN%^ as you catch "+targ->QCN+" with their flank exposed.  Turning swiftly you rake the talons across the vulnerable spot! %^RESET%^");
	tell_object(targ,"%^RESET%^%^CYAN%^The tips of "+ETOQCN+"'s "+query_short()+" %^RESET%^%^CYAN%^glint a sickening %^GREEN%^green%^RESET%^%^CYAN%^ as they catch sight of your exposed flank.  Before you can block, they turn swiftly and rake their talons across your vulnerable spot! %^RESET%^");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}
}