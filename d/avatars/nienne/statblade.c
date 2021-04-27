// updated dex bonus for new system. Nienne, 09/07.
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^silver blade%^RESET%^");
	set_id(({ "longsword", "sword", "long sword", "silver sword", "silver blade", "blade" }));
	set_short("%^BOLD%^%^WHITE%^Wolfsbane%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^silver longsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This eloquent longsword is clearly of %^GREEN%^elven design%^WHITE%^.  The long, sinuous blade is crafted of pure silver and forged through %^MAGENTA%^magical means%^WHITE%^ into a swift and strong weapon.  Ornate %^GREEN%^etchings %^WHITE%^enhance the silver metal's beauty while the narrow groove that runs down its center makes it %^YELLOW%^lighter %^WHITE%^and %^GREEN%^easier %^WHITE%^to wield.  The cross-guard of the blade is also crafted of silver and shaped to look like %^RESET%^%^ORANGE%^branches %^BOLD%^%^WHITE%^sprouting from the %^RESET%^ivory hilt%^BOLD%^%^WHITE%^.  Tinted leaves of %^GREEN%^emerald %^WHITE%^cover the majority of the cross-guard, but at the center where hilt meets blade are two five petal blooms of %^RESET%^%^MAGENTA%^deep amethyst %^BOLD%^%^WHITE%^that curve outward and back toward the weapon themselves, while tiny beads of %^YELLOW%^amber %^WHITE%^rest at the center.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^For those who were lost to us, drink deep.%^RESET%^

AVATAR
	);
     set("langage","elven");	set_weight(7);
	set_value(2500);
	set_lore(
@AVATAR
This blade was forged through elven magic at the behest of Lalaun Silver, an elven noble whose lands and people were destroyed a werebeast of darkest origins.  Sworn to avenge those who were slaughtered, Lalaun gave up his lands and title and set out to seek vengeance upon the creature that took the lives of so many.  Upon learning of the creature's true origin, Lalaun had twin blades forged of the purest silver metal and enchanted strongly with elven magic.  With these in hand, he tracked the beast for over a decade, intent upon bringing justice to those lost. The etchings upon the blade tell all.

AVATAR
	);
	set_property("lore difficulty",14);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
      set("dexbonus",1);
}
int wield_func(){
	tell_room(environment(ETO),"%^BLUE%^%^BOLD%^Determination fills "+ETOQCN+"'s eyes as they take hold of the %^RESET%^"+query_short()+"%^RESET%^%^BOLD%^%^BLUE%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BLUE%^%^BOLD%^As you take hold of the %^RESET%^"+query_short()+"%^RESET%^%^BOLD%^%^BLUE%^, you feel the fire of determination come upon you.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The determination lingers in "+ETOQCN+"'s eyes as they place %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ aside.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The determination remains lingering in your mind as you place %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ aside.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^The %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ strikes deep into "+targ->QCN+"'s defenses!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^The %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ strikes deep into "+targ->QCN+"'s defenses!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ strikes deep into your defenses!%^RESET%^");
		return roll_dice(3,4)+1;	}
}