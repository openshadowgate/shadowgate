#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("plate of ura");
	set_id(({ "armor", "plate", "ura", "plate of ura" }));
	set_short("%^BOLD%^%^RED%^U%^RESET%^%^RED%^r%^BOLD%^%^RED%^a%^WHITE%^, %^YELLOW%^Heavenly Plate %^WHITE%^of the %^RESET%^%^CYAN%^Eternal Citadel%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A set of %^RESET%^%^ORANGE%^masterwork %^BOLD%^%^WHITE%^mithril %^BLACK%^fullplate%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Mithril %^RED%^plates have been carefully shaped and fitted while being connected my a fine, lightweight %^CYAN%^mithril %^RED%^chain mesh. The lightness of the %^CYAN%^mithril %^RED%^chain allows the sections to be linked together while not hindering movement and still protecting as well as %^WHITE%^full plate%^RED%^. It fits tightly across the whole body acting more as a second skin than a suit of armor. It is easily worn and removed by slipping it over the head and pulling a single strap that melds the armor to the wearer's body. No one area is left defenseless for a simple movement allows one of the many interlocked plates to be coupled with a second for additonal protection. This is a feat of armorsmithing only able to be acomplished by a %^BLUE%^master%^RED%^.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Tengri Beovule


%^BOLD%^%^RED%^***There are many intricate Dwarven Runes here.***%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(60);
	set_value(100000);
	set_lore(
@AVATAR
This magnificent armor was made by Tengri Beovule in his 23rd year of life at GiGi's smithy in Torm.  It is said to be one of the finest set of armors ever made by anyone, and is soul bound to him.  It's name is Ura, Heavenly Plate of the Eternal Citadel, and it's likely that this armor will be around long after you are dead.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",8);
	set_ac(7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
   if((string)ETO->query_name()=="tengri"){
	tell_room(environment(ETO),""+ETOQCN+" wears the suit of armor and looks confident enough to tackle a dragon!",ETO);
	tell_object(ETO,"You put on the suit of armor and feel its %^BOLD%^%^RED%^power!%^RESET%^");
	ETO->add_stat_bonus("dexterity",-1);
	ETO->add_stat_bonus("charisma",-1);
	ETO->set_property("magic resistance",5);
	return 1;
   }
   tell_room(environment(ETO),""+ETOQCN+" attempts to slip into the armor and doubles over in pain!",ETO);
   tell_object(ETO,"A sharp pain floods through your body as you realize the armor refuses you!%^RESET%^");
        ETO->do_damage("torso",random(100)+100);
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ETO->remove_attacker(TO);
        TO->remove();
        return 0;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks glum as hey removes the armor.",ETO);
	tell_object(ETO,"You take off the armor and feel like a peasant!");
	ETO->add_stat_bonus("dexterity",1);
	ETO->add_stat_bonus("charisma",1);
	ETO->set_property("magic resistance",-5);
	return 1;
}
