#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("chainmail");
	set_id(({ "chainmail", "chain mail", "mail" }));
	set_short("%^BOLD%^%^BLACK%^Ob%^WHITE%^sc%^RESET%^u%^BOLD%^%^WHITE%^ri%^BLACK%^ng C%^WHITE%^h%^RESET%^a%^BOLD%^%^WHITE%^i%^BLACK%^n%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a suit of %^BOLD%^%^WHITE%^mithril %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^steel %^RESET%^%^CYAN%^chainmail%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Created from multiple sized links, this suit of chainmail is designed to drape over the upper body of the smaller, stouter figure of a gnome, halfling or other similar sized person.  The larger links, done in a shade of %^BOLD%^%^BLACK%^darkened steel%^RESET%^%^CYAN%^, cover the chest and vital points, and are layered with a finer %^WHITE%^%^BOLD%^mithril mesh %^RESET%^%^CYAN%^between their links.  These contrasting colors give the armor a %^BOLD%^%^BLACK%^sh%^WHITE%^im%^RESET%^me%^BOLD%^%^WHITE%^ri%^BLACK%^ng %^RESET%^%^CYAN%^effect that distracts the eyes, especially during times when the wearer is moving quickly, such as in battle.  A thin layer of %^RESET%^padding %^CYAN%^and straps of %^ORANGE%^leather%^CYAN%^, secured with steel buckles, allow the armor to be tightened or loosened to fit the wearer better, making the suit versatile as well as comfortable.%^RESET%^

AVATAR
	);
	set_weight(30);
	set_value(4000);
	set_lore(
@AVATAR
Kismeret the Flamboyant was said to have been the man of a thousand skills.  His flamboyant flare of telling grandiose stories was well known back in early fourth century, but beyond recounting his tales to large numbers of drunken tavern patrons, there are very few actual accountings of his doing even one of these outlandish stories.  Still, despite most writing him off as a tall tale teller, there is some evidence that Kismeret had at least done a few things he claimed.  The tale of defeating the five dwarven guardians of Holruon, for instance, and bringing back the mithril chain of obscuring, appears to be at least somewhat true as many recounting and drawings done of Kismeret during his life showed a set of the fine chainmail  indicated.  Taken from "The Flamboyant", by Hart Poulton

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("chain");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",4);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" adjusts a few buckles on their chainmail.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^After sliding on the chainmail, you adjust the straps until everything is comfortable.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" undoes a few buckles and slides their suit of chainmail off.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Unbuckling a few straps, you slip your chainmail off.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 50){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^The different hues of "+ETOQCN+"'s chainmail cause "+who->QCN+" to become momentarily distracted!  Their attack goes wide and "+ETOQCN+" takes only a small glancing blow instead of a direct hit! %^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The different hues of your chainmail cause "+who->QCN+" to become momentarily distracted!  Their attack goes wide and you take only a small glancing blow instead of a direct hit!%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^The different hues of "+ETOQCN+"'s chainmail cause you to become momentarily distracted!  Your attack goes wide and they take only a small glancing blow instead of a direct hit!  Better pay attention next time! %^RESET%^");
return (damage*-80)/100;	}

}
