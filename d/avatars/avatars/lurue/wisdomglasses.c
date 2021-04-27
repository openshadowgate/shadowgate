#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("glasses");
	set_id(({ "glasses", "peridot glasses", "reynmer shades", "shades" }));
	set_short("%^RESET%^%^GREEN%^Reynmer's %^BOLD%^%^WHITE%^Th%^CYAN%^ou%^GREEN%^gh%^CYAN%^tf%^WHITE%^ul %^RESET%^%^GREEN%^Shades%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^an elaborate set of %^RESET%^%^GREEN%^pe%^BOLD%^ri%^RESET%^%^GREEN%^dot %^BOLD%^%^WHITE%^glasses%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^These glasses appear more of a decorative mask then a functional set of spectacles with their twisted %^YELLOW%^gold %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^silver %^RESET%^%^ORANGE%^wire that loops up in a fan of %^GREEN%^g%^BOLD%^li%^CYAN%^t%^WHITE%^t%^CYAN%^e%^GREEN%^ri%^RESET%^%^GREEN%^ng %^RESET%^%^ORANGE%^beads and arching curls over the brow.   From this display, the wire continues down around a pair of %^GREEN%^pale green peridot lenses%^ORANGE%^, finely polished and so pale they are almost clear.  All before the wire twists back in loops and spirals to hook over the ears and drape a spill of tiny %^GREEN%^cr%^BOLD%^ys%^CYAN%^ta%^WHITE%^l-%^CYAN%^la%^GREEN%^ce%^RESET%^%^GREEN%^d %^ORANGE%^chains that drip down to the base of the jaw.  Fairly light for the amount of metal used to create them, the glasses don't appear to have a function beyond decoration.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1800);
	set_lore(
@AVATAR
Given the curious appearance of these glasses, one can only assume that it was a gnome that created them.  That or someone too caught up in twisting wire and making pretty swirls to pay attention to practicality.  And yet, there are rumors about a set of similar glasses that were worn by King Reynmer of Trevatul, a man said to be as wise as he was kind and who favored a strange set of glasses because "they show me what can be seen with knowledge and foresight". 

AVATAR
	);
	set_property("lore difficulty",15);
	set("wisbonus",1);
	set("dexbonus",-1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^The little beads jingle and you wonder at the wisdom of wearing these strange glasses.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^As you remove your glasses, the whole world seems a little less in focus, though your balance appears restored.%^RESET%^");
	return 1;
}

