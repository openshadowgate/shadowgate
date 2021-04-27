#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dragoncall");
	set_id(({ "axe", "dragons call" }));
	set_short("%^BOLD%^%^RED%^Re%^BOLD%^%^BLUE%^vkl%^BOLD%^%^YELLOW%^a's %^BOLD%^%^BLUE%^Ca%^BOLD%^%^RED%^ll%^RESET%^");
	set_obvious_short("A Battle Axe");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This medium axe is finely crafted, it's head made out of pure %^BOLD%^%^WHITE%^adamantine%^BOLD%^%^RED%^. The edges have been sharped to a %^BOLD%^%^YELLOW%^keen edge and lines of what looks like trails of blood trails off onto the axe. The handle is made out of %^RESET%^%^ORANGE%^oak %^BOLD%^%^RED%^that has been hardened and covered with %^BOLD%^%^YELLOW%^runes%^BOLD%^%^RED%^. On the end of the handle sits half of a dragons %^BOLD%^%^CYAN%^eye %^BOLD%^%^RED%^that watches everything that moves warily. An inscription flows up the side.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Chaos in heart, chaos forever.

AVATAR
	);
     set("langage","str");	set_weight(15);
	set_value(3000);
	set_lore(
@AVATAR
The axe was crafted by a man by the name of Felrin Van Hak, who was drafted by a powerful and wealthy adventurer to make a weapon out of the dragon. This is the accomplishment of the smith's work. This legendary axe has slew almost all beasts imaginable, and those who have it are always feel lucky and never let it leave their side.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium axe");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",4);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" wields the axe and smiles slightly.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^A voice in your mind says: %^BOLD%^%^CYAN%^Hello, Servant, Let us play.");
	ETO->add_stat_bonus("strength",1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" smirks as he unwields the weapon.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^A voice in your mind says: %^BOLD%^%^CYAN%^What, no more fun?");
	ETO->add_stat_bonus("strength",-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^YELLOW%^A wail emits from the axe striking "+targ->query_cap_name()+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^YELLOW%^A wail emits from the axe striking your target!");
	tell_object(targ,"%^BOLD%^%^YELLOW%^A wail emits from the axe striking you!");
		return roll_dice(3,4)+0;	}
}