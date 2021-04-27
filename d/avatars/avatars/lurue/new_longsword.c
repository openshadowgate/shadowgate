#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("longsword");
	set_id(({ "longsword", "purple longsword", "ornate longsword" }));
	set_short("%^RESET%^%^MAGENTA%^P%^WHITE%^u%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ple L%^WHITE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^gsw%^WHITE%^o%^MAGENTA%^rd%^RESET%^");
	set_obvious_short("%^RESET%^an %^MAGENTA%^o%^BOLD%^%^BLACK%^r%^RESET%^n%^MAGENTA%^ate %^RESET%^looking %^MAGENTA%^l%^BOLD%^%^BLACK%^o%^RESET%^n%^MAGENTA%^gsw%^BOLD%^%^BLACK%^o%^RESET%^r%^MAGENTA%^d%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This long eloquent sword is forged of a dark metal that looks to be a blending of steel and fever iron.  Sharp on each edge, the blade narrows to a dangerous, triangular point that would be good for %^WHITE%^thrusting%^BLACK%^.  The cross guard is plain but two %^RESET%^%^MAGENTA%^amethysts %^BLACK%^%^BOLD%^have been set into either tip as well as a larger one in the pommel.  This, combined with the dyed %^RESET%^%^MAGENTA%^purple leather %^BOLD%^%^BLACK%^that wraps the hilt, is likely what gives the blade its name.%^RESET%^  

AVATAR
	);
	set_weight(7);
	set_value(100);
	set_lore(
@AVATAR
%^RESET%^%^MAGENTA%^The %^WHITE%^Silver Brigade %^MAGENTA%^was a unit of the Tesdrin Empire's army during the first two centuries SG.  Their leaders were known as the Purple Knights for their bright purple cloaks and the etchings placed upon their armor.  Many also carried such fine weapons as this, studded with amethysts or other purple stones to remind people of their station. %^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^MAGENTA%^"+ETOQCN+" quickly parry's "+targ->QCN+"'s attack and strikes them with their "+query_short()+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You quickly parry "+targ->QCN+"'s attack and strike them with your "+query_short()+"%^RESET%^");
	tell_object(targ,"%^RESET%^%^MAGENTA%^"+ETOQCN+" quickly parry's your attack and strikes at you with their "+query_short()+"%^RESET%^");
		return roll_dice(1,4)+0;	}
}