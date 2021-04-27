#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
	::create();
	set_name("shadow glove");
	set_id(({ "glove" }));
	set_short("%^BOLD%^%^BLACK%^Stealthwhisper%^RESET%^");
	set_obvious_short("A black, weighted glove");
	set_long("%^RESET%^This is a %^BOLD%^%^BLACK%^dark leather%^RESET%^, heavily weighted glove."+
    " Completely black, the weapon shows almost no distinctive features."+
    " The only distinguishable feature is a %^BOLD%^%^CYAN%^quartz"+
    " %^BOLD%^%^BLACK%^rested int he palm of the glove. Within the quartz, a %^BOLD%^%^WHITE%^smoky"+
    " %^BOLD%^%^BLACK%^substance whisps around.);
	set_weight(2);
	set_value(1000);
	set_lore("Rumored to be a special gift to Maskarrans who have completed a special mission for their deity.");
	set_type("piercing");
	set_prof_type("stealthwhisper");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" wields the dagger and a dark shadow bursts forth from the dagger crawling up their arm. "+ETO->query_cap_name()+"'s eyes %^BOLD%^%^CYAN%^glow %^BOLD%^%^BLACK%^for a moment before returning to normal.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Shadows burst forth from the glove and crawl up your arms. A strange feeling passes through your body.");
	ETO->add_stat_bonus("dexterity",1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The sensation leaves you.");
	ETO->add_stat_bonus("dexterity",-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"%^BOLD%^%^BLACK%^Long tentacles of shadows burst forth from the glove, enveloping you!");
		targ->set_paralyzed(roll_dice(3,6)+0);
return 0;	}
}
