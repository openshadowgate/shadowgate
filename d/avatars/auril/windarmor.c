#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dervishes motion");
        set_id(({"studded","studded armor","armor","motion","dervish's motion"}));
        set_short("%^BOLD%^%^GREEN%^Dervish's %^BOLD%^%^YELLOW%^Mo%^BOLD%^%^WHITE%^ti%^BOLD%^%^YELLOW%^on%^RESET%^");
	set_obvious_short("A lavish suit of studded armor");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This suit of studded has been adorned with small %^BOLD%^%^BLUE%^st%^BOLD%^%^YELLOW%^rea%^BOLD%^%^BLUE%^ks %^BOLD%^%^CYAN%^of magically enchanted thread which glimmer in the light and seem to %^BOLD%^%^BLACK%^deepen %^BOLD%^%^CYAN%^in the darkness. This suit of armor would be hard pressed to find an equal, and the holy symbol of %^BOLD%^%^YELLOW%^Akadi %^BOLD%^%^CYAN%^etched as a centerpiece on the chest shows well it's wearers intentions.%^RESET%^

AVATAR
	);
        set_weight(25);
	set_value(10000);
	set_lore(
@AVATAR
This was a suit of armor that was once worn by the ranger Ezekial. It was formed by the mage Jandd in an attempt to make peace with the ranger because of a misstep the wizard made in the rangers forest. No one knows what happened to the ranger, but rumors were told that he fell to a powerful dragon.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
        set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel at ease when you wear the armor.");
	ETO->add_stat_bonus("dexterity",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel a little weaker after you remove the armor%^RESET%^");
	ETO->add_stat_bonus("dexterity",-2);
	return 1;
}
