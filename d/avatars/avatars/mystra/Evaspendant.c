#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("pendant");
	set_id(({ "pendant", "necklace", "chain" }));
	set_short("%^BOLD%^Silv%^RED%^er Hea%^WHITE%^rt of %^BLUE%^Sune%^RESET%^");
	set_obvious_short("%^BOLD%^a heart shaped pendant%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^A very exquisite piece of jewelry, the pendant before you %^YELLOW%^g%^WHITE%^l%^YELLOW%^i%^WHITE%^t%^YELLOW%^t%^WHITE%^e%^YELLOW%^r%^WHITE%^s in the light.  A slender 14" silver chain accented by a stunning diamond and %^RED%^ruby %^WHITE%^pendant.  In the center of the large heart-shaped ruby, a tiny but flawless diamond sits radiantly bathing in the glow of the %^RED%^ruby%^RESET%^.

AVATAR
	);
	set_weight(3);
	set_value(25000);
	set_lore("%^BOLD%^Once upon a time in a kingdom far far away, a poor young mage wished "
        "to find the perfect gift for the woman he loved.  She was the traditional beautiful "
        "daughter of a noble and he was the farmer that her poor nomad her father didn't want "
        "around.  Their love for each other held for as long as they were able to sneak away "
        "together.  The days of summer flittered by on a dream they wished never to awaken "
        "from.  Succumbing to the belief that her father would accept him if he could prove "
        "some manner of wealth, the boy broke into a jewelers shop and found a very beautiful "
        "heart shaped pendant to give her.  Before he did, swelling with pride for the gift "
        "he'd stolen, he enchanted the necklace with a spell of magical resistance just for her.  "
        "She was sort of afraid of magic you know.  He presented his gift to the young woman "
        "in front of her father who immediately became angered beyond belief.  The necklace he "
        "had stolen was one the girls father had made for her upcoming birthday.  Eager and "
        "willing to accept the opportunity to get rid of the young mage for good, the father "
        "called upon the local magistrate who immediately arrested and imprisoned the boy.  "
        "Flattered by what her lover had done, but saddened by his removal, she broke into "
        "the jail and got him out.  They ran away together, pendant around her neck and were "
        "never heard from by her father again.  A beautiful story of love - Shortstory 3, "
        "chapter 4 of The Book of Thieving Bedtime Stories.");

	set_property("lore difficulty",22);
	set("chabonus",1);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" looks stunning wearing her "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You feel your beauty increse when you wear the "+query_short()+"%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" seems less astonishing without her "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You feel an aura about you fade when you remove "+query_short()+"%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}

