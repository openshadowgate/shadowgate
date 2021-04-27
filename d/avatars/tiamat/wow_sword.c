#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^YELLOW%^sword of awesome%^RESET%^");
	set_id(({ "sword", "medium blade", "sword of awesome", "awesome sword" }));
	set_short("%^BOLD%^%^YELLOW%^A Stunning Sword of Awesome%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^strange yellow longsword%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This is a strange looking sword.  It doesn't appear to be made of any kind of metal, but rather as though a cartoon sword became real.  It is mostly yellow, but also has %^MAGENTA%^s%^WHITE%^p%^RED%^a%^GREEN%^r%^BLUE%^k%^YELLOW%^l%^ORANGE%^y%^RESET%^ %^YELLOW%^gems running all along the hilt.  There is something stamped on the bottom of the pommel.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^ORANGE%^ Made In China%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(4);
	set_value(2000);
	set_lore(
@AVATAR
Holy cow, what you have there is a sword of AWESOME.  It was invented by Tiamat as a sick little practice session but themed in honor of her teacher, Lurue.  You'll see how when it specials.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(6,8);
	set_large_wc(6,12);
	set_property("enchantment",5);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^YELLOW%^ looks silly wielding "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel silly wielding "+query_short()+"%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^YELLOW%^ looks more natural, now rid of "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel more serious, now rid of "+query_short()+"%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+" 's "+query_short()+"%^RESET%^    %^YELLOW%^ shoots r%^MAGENTA%^a%^RED%^i%^YELLOW%^n%^GREEN%^b%^CYAN%^o%^BLUE%^ws%^RESET%^%^YELLOW%^! at "+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^The "+query_short()+" %^RESET%^%^YELLOW%^ shoots r%^MAGENTA%^a%^RED%^i%^YELLOW%^n%^GREEN%^b%^CYAN%^o%^BLUE%^ws%^RESET%^%^YELLOW%^! at "+targ->QCN+"%^RESET%^");
	tell_object(targ,"%^YELLOW%^You are blasted with r%^MAGENTA%^a%^RED%^i%^YELLOW%^n%^GREEN%^b%^CYAN%^o%^BLUE%^ws%^RESET%^%^YELLOW%^!%^RESET%^");
		targ->set_paralyzed(roll_dice(3,0)+0);
return 0;	}
}