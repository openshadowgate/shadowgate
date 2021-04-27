#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("axe");
	set_id(({ "axe", "bronze axe", "battleaxe" }));
	set_short("%^RESET%^%^ORANGE%^B%^YELLOW%^r%^BLACK%^o%^RESET%^%^ORANGE%^n%^YELLOW%^z%^RESET%^%^ORANGE%^e A%^GREEN%^x%^ORANGE%^e%^RESET%^");
	set_obvious_short("a %^ORANGE%^w%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^th%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^ed %^RESET%^battleaxe");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Created from thick sheets of %^YELLOW%^bronze%^RESET%^%^ORANGE%^, this weapon seems like it would be heavy and difficult to wield, yet the balance and craftsmanship of this old looking axe makes that far from the truth.  Weathered strips of %^WHITE%^leather %^ORANGE%^wrap the handle, providing a secure grip despite the fraying edges. Dotting the blade and haft, %^GREEN%^greenish %^ORANGE%^and %^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^spots of oxidation can be seen, but the edge is still keenly sharp.  This combined with the comfortable balance of the blade provides a serviceable weapon, despite its age.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100);
	set_lore(
@AVATAR
In the first century of SG, bronze was one of the many metals that was both plentiful and useful in creating armor and weapons.  While this craft has carried forward through the years, steel, mithril and titanium have all replaced the deep ocher bronze as the metal of choice.  Despite this, a few of the pieces from that time still maintain through today.  This axe is a representation of those ancient arts.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("slashing");
	set_prof_type("axe");
	set_weapon_prof("martial");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+" heaves their "+query_short()+" %^YELLOW%^ up and swings it down with a hard blow to "+targ->QCN+"'s side!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^You heave your "+query_short()+" %^YELLOW%^up and swing it down in a telling blow across "+targ->QCN+"'s side!%^RESET%^");
	tell_object(targ,"%^YELLOW%^"+ETOQCN+" heaves their "+query_short()+" %^YELLOW%^ up and swings it down with a hard blow to your side!%^RESET%^");
		return roll_dice(1,4)+0;	}
}