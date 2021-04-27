#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
	set_name("silent steps");
        set_id(({"boots","silent steps","gray boots","dark gray boots"}));
	set_obvious_short("%^BOLD%^%^BLACK%^dark gray boots%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^Silent Steps%^RESET%^");
	set_long("These boots are made from cured leather and"+
	" have been dyed a dark shade of gray. The bottom of"+
	" the boots are padded with layers of silk"+
	" the same color as the boots. The boots have no"+
	" no laces and posses a thin black fur trim around"+
	" the top.");
	set_type("leather");
        set_limbs(({"right foot","left foot"}));
	set_property("enchantment",2);
	set_property("lore",7);
	set_lore("These boots were worn by a human adventurer named Alvin Kyaes."+
	" Alvin was a member of one the more renowned adventuring groups"+
	" known as the company of the moon. It is unlcear what Alvin's role was"+
	" in the party, as he was only known as mediocre swordsman,"+
	" terrible spellcaster, and even worse singer. However,"+
	" somehow he always ended up coming out ahead...");
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}

int wear_func(){
	if(!ETO->is_class("thief")){
	tell_object(ETO,"%^BOLD%^%^BLACK%^The boots don't seem to fit%^RESET%^.");
	return 0;
}
	if(ETO->is_class("thief")) {
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your feet fit snugly into the boots%^RESET%^.");
	ETO->set_thief_skill_bonus("move silently",5);
	ETO->set_thief_skill_bonus("hide in shadows",5);
}
return 1;
}

int remove_func(){
	ETO->set_thief_skill_bonus("move silently",-5);
	ETO->set_thief_skill_bonus("hide in shadows",-5);
return 1;
}
