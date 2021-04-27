#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("vest");
	set_id(({ "vest", "kenders pride" }));
	set_short("%^RESET%^%^GREEN%^K%^ORANGE%^e%^GREEN%^nd%^ORANGE%^e%^GREEN%^rs %^BOLD%^%^YELLOW%^Pr%^WHITE%^i%^YELLOW%^de%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^many %^ORANGE%^pocketed %^BOLD%^%^WHITE%^f%^BLACK%^u%^RESET%^%^ORANGE%^r %^GREEN%^vest%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This stylish (for a kender at least)%^RESET%^%^GREEN%^ vest%^BOLD%^%^CYAN%^ is formed out of %^RESET%^%^ORANGE%^sq%^BOLD%^%^WHITE%^u%^BLACK%^i%^WHITE%^r%^RESET%^%^ORANGE%^rel%^BOLD%^%^CYAN%^ and %^WHITE%^bunny%^CYAN%^ pelts. The %^RESET%^%^GREEN%^vest%^BOLD%^%^CYAN%^ fits loosely around the wearer's body to accommodate the numerous %^RESET%^%^BLUE%^pockets%^BOLD%^%^CYAN%^, both inside and out. Fastened to the front of the vest is a motley assortment of %^RESET%^%^ORANGE%^buttons%^BOLD%^%^CYAN%^, %^YELLOW%^toggles%^CYAN%^, and %^BLACK%^laces%^CYAN%^ of all shapes and sizes, to fasten it up. Most of the pockets are %^RED%^overstuffed%^CYAN%^ with %^YELLOW%^tr%^MAGENTA%^i%^YELLOW%^nk%^MAGENTA%^e%^YELLOW%^ts%^CYAN%^ and %^GREEN%^gew-gaws%^CYAN%^. It's a wonder that this vest doesn't weigh more than it's wearer!%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^>%^RESET%^%^CYAN%^Oh! I'm sorry, you must've dropped this back there!%^BOLD%^<%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(0);
	set_lore(
@AVATAR
%^RESET%^%^GREEN%^Kenders%^BOLD%^%^WHITE%^ of the%^RESET%^%^BLUE%^ Worlds%^BOLD%^%^WHITE%^ would travel and "find" items all of their lives and wouldn't even know that they possessed this famed%^RESET%^%^RED%^ Artifact%^BOLD%^%^WHITE%^. %^RESET%^%^GREEN%^K%^ORANGE%^e%^GREEN%^nd%^ORANGE%^e%^GREEN%^rs%^BOLD%^%^YELLOW%^ Pr%^WHITE%^i%^YELLOW%^de%^WHITE%^ has actually passed through more tiny hands than a gnome has last names. Each kender who owned the vest added another pocket as the vest just seemed to pick up more and more objects. Nobody truly knows if they own the TRUE vest or not, as there have, of course, been replicas, but none as historical as this specific vest.%^RESET%^
%^BOLD%^%^WHITE%^-= "An Unfinished Chronicle of Kender History", Penning Ferievermein%^RESET%^

AVATAR
	);
	set_property("lore difficulty",18);
	set("dexbonus",2);
	set("chabonus",2);
	set_max_internal_encumbrance(100);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",5);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^BOLD%^%^MAGENTA%^snickers%^YELLOW%^ and%^GREEN%^ giggles%^YELLOW%^ as they pull on the%^RESET%^%^BLUE%^ many%^ORANGE%^ pocketed%^BOLD%^%^WHITE%^ f%^BLACK%^u%^ORANGE%^r%^GREEN%^ vest%^BOLD%^%^YELLOW%^.%^RESET%^  ",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^The%^WHITE%^ f%^BLACK%^u%^RESET%^%^ORANGE%^r%^BOLD%^ from the%^RESET%^%^GREEN%^ vest%^BOLD%^%^MAGENTA%^ t%^CYAN%^i%^MAGENTA%^c%^CYAN%^k%^MAGENTA%^l%^CYAN%^e%^MAGENTA%^s%^YELLOW%^ as you%^GREEN%^ w%^WHITE%^r%^GREEN%^i%^WHITE%^g%^GREEN%^g%^WHITE%^l%^GREEN%^e%^YELLOW%^ into it.%^RESET%^  ");
	ETO->set_property("magic resistance",75);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^BOLD%^%^YELLOW%^writhes on the ground, kicking and giggling, as they %^GREEN%^w%^WHITE%^r%^GREEN%^i%^WHITE%^g%^GREEN%^g%^WHITE%^l%^GREEN%^e%^YELLOW%^ out of their %^RESET%^%^GREEN%^vest%^BOLD%^%^YELLOW%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^The %^RESET%^%^BLUE%^many%^ORANGE%^ pocketed%^BOLD%^%^WHITE%^ f%^BLACK%^u%^RESET%^%^ORANGE%^r%^GREEN%^ vest%^BOLD%^%^YELLOW%^ causes you to roll on the floor, kicking and giggling, as you remove it!%^RESET%^");
	ETO->set_property("magic resistance",-75);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 350){
	tell_room(environment(query_worn()),"%^BOLD%^%^YELLOW%^You hear a loud%^RED%^ THWACK!%^YELLOW%^ as "+who->QCN+" hits "+ETOQCN+"'s %^RESET%^%^BLUE%^many %^ORANGE%^pocketed %^BOLD%^%^WHITE%^f%^BLACK%^u%^RESET%^%^ORANGE%^r%^RESET%^%^GREEN%^ vest%^BOLD%^%^YELLOW%^......ouch....hope that wasn't yours......%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel a soft%^RESET%^%^CYAN%^ THWUMP!%^BOLD%^%^YELLOW%^ and hear a loud%^RED%^ THWACK!%^YELLOW%^ as "+who->QCN+" hits your %^RESET%^%^GREEN%^vest%^BOLD%^%^YELLOW%^.%^RESET%^");
	tell_object(who,"%^BOLD%^%^YELLOW%^You hear a loud %^RED%^THWACK!%^YELLOW%^ and feel something %^WHITE%^cr%^RESET%^a%^BOLD%^ck%^YELLOW%^ in "+ETOQCN+"'s %^RESET%^%^BLUE%^many %^ORANGE%^pocketed %^BOLD%^%^WHITE%^f%^BLACK%^u%^RESET%^%^ORANGE%^r%^GREEN%^ vest%^BOLD%^%^YELLOW%^...*grumble*...could've used that....");
return (damage*-75)/100;	}

}
