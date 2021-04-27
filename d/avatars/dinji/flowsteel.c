#include <std.h>
inherit "/d/common/obj/weapon/double_bladed_sword.c";

void create(){
	::create();
	set_name("flowing steel");
	set_id(({"double bladed sword","double sword","sword","flowing steel"}));
	set_obvious_short("%^BOLD%^%^WHITE%^double bladed sword%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Flowing Steel%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^This is a double bladed sword. The blades themselves"+
	" are double edged and and also curved, but in opposite directions"+
	" from one another, to allow the warrior maximum versatility when"+
	" moving from target to target or simply from swing to swing in"+
	" combat. The blades are joined together by a finely carved oak"+
	" pole. The pole itself is wrapped in a thick, rough leather,"+
	" to allow for a firm grip.");
	set_property("lore",11);
	set_lore("This fine weapon was crafted and used to absolute perfection"+
	" by the half-elven warrior Cerin Ulak. While he was tall, he was not"+
	" very brawny and relied on his speed and agility to weave his way through"+
	" combat. After a successful adventuring career, Cerin settled down and"+
	" and began training other adventurers. He passed this blade down"+
	" to one of his favorite pupils, who lost it to a gambling"+
	" addiction.");
	set_value(2000);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
        set_hit((:TO,"hit_func":));
	set_property("enchantment",3);
}

int wield_func(){
	tell_object(ETO,"%^BOLD%^%^WHITE%^You heft the weapon and admire its perfect balance%^RESET%^.");
	return 1;
}

int unwield_func(){
	tell_object(ETO,"%^BOLD%^%^WHITE%^You release the blade and feel slightly off balance for a second%^RESET%^.");
	return 1;
}

int hit_func(object targ){
        if(!objectp(TO)) return 1;
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;
        if(random(1000) < 300){
      switch(random(3)){         
         case 0:
        tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" finds a weak spot in the enemy's defenses%^RESET%^!",({ETO,targ}));
        tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" finds a weak spot in your defenses%^RESET%^!");
	tell_object(ETO,"%^BOLD%^%^BLACK%^You find a weak spot in your enemy's defenses%^RESET%^!");
	targ->do_damage("torso",roll_dice(3,6));
	break;
	case 1:
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" moves gracefully about the battle, swinging fluidly%^RESET%^!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You gracefully move about the battle, swinging fluidly%^RESET%^!");
        tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" gracefully moves about you, swinging fluidly%^RESET%^!");
	targ->do_damage("torso",roll_dice(3,6));
	break;
	case 2:
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" strikes once, then quickly strikes again as "+ETO->subjective()+" cleaves upwards with the second blade%^RESET%^!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You strike once, then quickly strike again, cleaving upwards with the second blade%^RESET%^!");
       tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" strikes you once, then quickly strikes again, cleaving upwards with the second blade%^RESET%^!");
	targ->do_damage("torso",roll_dice(3,7));
}
}
}
