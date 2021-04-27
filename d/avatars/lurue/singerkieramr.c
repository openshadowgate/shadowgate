#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leather armor");
	set_id(({ "leather", "armor", "studded", "shimmering night" }));
	set_short("%^BOLD%^%^WHITE%^Sh%^RESET%^i%^BOLD%^%^WHITE%^mme%^BLACK%^r%^WHITE%^ing N%^RESET%^i%^BOLD%^%^WHITE%^g%^BLACK%^h%^WHITE%^t%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^fine leather%^BOLD%^%^BLACK%^ studded leather armor%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Crafted from the softest, %^ORANGE%^highest quality leather %^CYAN%^you have ever seen, this studded is light, yet provides an amazing amount of protection. It has been cut oddly, with longer sleeves that flare out slightly, almost as if it was more ceremonial. The entire surface of the armor has been studded with polished %^WHITE%^%^BOLD%^moonstones %^RESET%^%^CYAN%^and %^BOLD%^opa%^WHITE%^ls%^RESET%^%^CYAN%^, giving the effect of a %^BOLD%^%^WHITE%^shi%^RESET%^m%^BOLD%^%^WHITE%^me%^BLACK%^r%^WHITE%^ing %^BLACK%^night %^RESET%^%^CYAN%^skyscape when the light hits it. Over the heart there is a design engraved into the leather that has been filled with %^BOLD%^%^WHITE%^molten silver %^RESET%^%^CYAN%^of %^BOLD%^two female eyes surrounded by seven stars%^RESET%^%^CYAN%^. Overall the studded seems to glow in the light.%^RESET%^

AVATAR
	);
	set_weight(16);
	set_value(32);
	set_lore(
@AVATAR

%^BOLD%^%^CYAN%^Moonstones and leather, opals and silver, all were gathered by Kiervalan Telkaror and Singer Moonsong to forge this stylish armor.  Through several quests and exploits, the two found each of the items that would be made into the final suit of leather armor. When all the pieces were gathered and the armor was forged, the pair stood together before the altar of %^BOLD%^%^WHITE%^Selune%^CYAN%^ and asked her blessing.  Moonlight flooded the temple and filled the armor with her radiance. Some time later, long after the forging of the leather, Singer entrusted the armor to the dwarven priests to add the favor of the earth and enchant it with protective magics.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(6);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^Sparkles of %^WHITE%^Moo%^RESET%^n%^BOLD%^%^WHITE%^li%^BLACK%^g%^WHITE%^ht%^CYAN%^ float around "+ETOQCN+"!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^Sparkles of %^WHITE%^Moo%^RESET%^n%^BOLD%^%^WHITE%^li%^BLACK%^g%^WHITE%^ht%^CYAN%^ float around you!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The %^WHITE%^Moo%^RESET%^n%^BOLD%^%^WHITE%^li%^BLACK%^g%^WHITE%^ht%^CYAN%^ fades back into "+ETOQCN+"'s "+query_short()+"%^BOLD%^%^CYAN%^!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The %^WHITE%^Moo%^RESET%^n%^BOLD%^%^WHITE%^li%^BLACK%^g%^WHITE%^ht%^CYAN%^ fades back into the "+query_short()+"%^BOLD%^%^CYAN%^!%^RESET%^");
	return 1;
}

