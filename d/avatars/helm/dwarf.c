#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dwarf");
	set_id(({ "dwarf" }));
	set_short("%^RESET%^%^GREEN%^A sturdy %^ORANGE%^dwarf%^RESET%^%^GREEN%^ with a %^BOLD%^%^BLACK%^black%^RESET%^%^GREEN%^ beard%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A sturdy %^ORANGE%^dwarf%^RESET%^%^GREEN%^ with a %^BOLD%^%^BLACK%^black%^RESET%^%^GREEN%^ beard%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^A sturdy %^ORANGE%^dwarf%^RESET%^%^GREEN%^ with a %^BOLD%^%^BLACK%^black%^RESET%^%^GREEN%^ beard%^RESET%^%^GREEN%^ is dressed in what appears to be a fullplate. His hair is tangled and dirty and reaches to his knees, as does his beard. At his side he wears the largest hammer you've ever seen and he smells funny.

AVATAR
	);
	set("read",
@AVATAR
You read the dwarf like an open book, he appears to think about ale and gold.

AVATAR
	);
     set("langage","dwarvish");	set_weight(300);
	set_value(0);
	set_lore(
@AVATAR
Dwarves are small stocky humanoids that live under ground.

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("bludgeoning");
	set_prof_type("small dwarf");
	set_size(3);
	set_wc(1,13);
	set_large_wc(1,15);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" grabs "+query_short()+" by the foot and is ready to rumble.",ETO);
	tell_object(ETO,"You grab "+query_short()+" by the foot and are ready to rumble.");
	ETO->add_damage_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" lets go of "+query_short()+" and he falls to the ground, exhausted.",ETO);
	tell_object(ETO,"You let go of "+query_short()+" and he falls to the ground, exhausted.");
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),""+query_short()+" scores a hit on "+targ->QCN+" with his large hammer.",({ETO,targ}));
	tell_object(ETO,""+query_short()+" scores a hit on "+targ->QCN+" with his large hammer.");
	tell_object(targ,""+query_short()+" scores a hit on you with his large hammer.");
		targ->set_paralyzed(roll_dice(1,3)+0);
return 0;	}
}