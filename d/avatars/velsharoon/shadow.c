#include <std.h>
inherit "/d/common/obj/weapon/mace";

void create(){
	::create();
	set_name("Shadow of the Void");
	set_id(({ "mace", "shadow", "void", "ice", "shadow mace", "void mace", "ice mace", "shadow of the void", "Shadow of the Void", "Mace" }));
	set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^a%^BOLD%^%^BLACK%^dow %^CYAN%^of the %^RESET%^%^BLUE%^Vo%^BOLD%^%^WHITE%^i%^RESET%^%^BLUE%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^ice%^RESET%^-%^BLUE%^encrusted %^CYAN%^mace%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^Aching cold of a dire winter emanate from this deadly weapon. The very thought of grabbing hold of the haft of this mace makes one's veins practically freeze. The whole of the weapon i"
	"tself is a masterwork to behold, and nearly impossible to describe. A clear sphere serves as the head of this weapon, churning %^BOLD%^%^BLACK%^b%^CYAN%^l%^BLACK%^i%^CYAN%^g%^BLACK%^h%^CYAN%^t%^BLACK%"
	"^f%^CYAN%^i%^BLACK%^r%^CYAN%^e%^BLUE%^ trapped within it's depths. The haft is a single solid shard of %^CYAN%^i%^WHITE%^c%^CYAN%^e%^BLUE%^ depending from the sphere. The weapon itself looks very frag"
	"ile and one must be very brave indeed to even pick it up.%^RESET%^
"
	);
	set_value(67000);
	set_lore("%^RESET%^%^BLUE%^......and so I am condemned in the afterlife to an eternity of frosty conflagration. As my body was consumed, so shall yours be; embraced in these frigid arms, sealed away in your own"
	" tomb of ice. You shall not escape, but you will serve me well. My slave, my minion, my wrath made manifest.......%^RESET%^
"
	);
    set_property("lore difficulty",35);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+"%^BOLD%^%^BLUE%^ grabs ahold of the "+query_short()+" %^BOLD%^%^BLUE%^ with a shaky hand. %^CYAN%^I%^WHITE%^c%^CYAN%^e%^BLUE%^ encases "+ETOQCN+"%^BOLD%^%^BLUE%^ hand up to the wrist.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You grasp the "+query_short()+" %^BOLD%^%^BLUE%^ with trepedition, your hand freezing instantly to the %^CYAN%^i%^WHITE%^c%^CYAN%^e%^BLUE%^ but feeling no pain as more %^CYAN%^i%^WHITE%^c%^CYAN%^e%^BLUE%^ encases your hand up to the wrist.%^RESET%^");
	ETO->add_damage_bonus(4);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^I%^WHITE%^c%^CYAN%^e%^BLUE%^ shatters from "+ETOQCN+"'s%^BOLD%^%^BLUE%^ hand as they release the "+query_short()+"%^BOLD%^%^BLUE%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^I%^WHITE%^c%^CYAN%^e%^BLUE%^ shatters from your hand as you release the "+query_short()+"%^BOLD%^%^BLUE%^.%^RESET%^");
	ETO->add_damage_bonus(-4);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 45){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^B%^CYAN%^l%^BLACK%^i%^CYAN%^g%^BLACK%^h%^CYAN%^t%^BLACK%^f%^CYAN%^i%^BLACK%^r%^CYAN%^e %^YELLOW%^FLARES%^WHITE%^ into existence from "+ETOQCN+"'s "+query_short()+"%^BOLD%^%^WHITE%^ and rushes forward to encase "+targ->QCN+"%^BOLD%^%^WHITE%^ in it's %^RESET%^%^BLUE%^hoary%^BOLD%^%^WHITE%^ embrace!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^B%^CYAN%^l%^BLACK%^i%^CYAN%^g%^BLACK%^h%^CYAN%^t%^BLACK%^f%^CYAN%^i%^BLACK%^r%^CYAN%^e %^YELLOW%^FLARES%^WHITE%^ into existence from the head of the "+query_short()+"%^BOLD%^%^WHITE%^ and rushes forward to encase "+targ->QCN+"%^BOLD%^%^WHITE%^ in it's %^RESET%^%^BLUE%^hoary%^BOLD%^%^WHITE%^ embrace!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^B%^CYAN%^l%^BLACK%^i%^CYAN%^g%^BLACK%^h%^CYAN%^t%^BLACK%^f%^CYAN%^i%^BLACK%^r%^CYAN%^e %^YELLOW%^FLARES%^WHITE%^ into existence from "+ETOQCN+"'s "+query_short()+"%^BOLD%^%^WHITE%^ and rushes forward to encase you in it's %^RESET%^%^BLUE%^hoary%^BOLD%^%^WHITE%^ embrace! Frigid cold unlike you have ever felt tears through you and your soul!%^RESET%^");
		return roll_dice(2,12)+0;	}

}
