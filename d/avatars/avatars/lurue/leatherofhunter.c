#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("leathers");
	set_id(({ "leathers", "leathers of the traveling hunter", "hunter leathers" }));
	set_short("%^BOLD%^%^BLACK%^Leathers %^RESET%^%^MAGENTA%^of the %^BOLD%^%^BLACK%^Traveling Hunter%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a leather jumpsuit%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^Created from thin crisscrossing pieces of %^BOLD%^%^BLACK%^dark leather%^RESET%^%^MAGENTA%^, this jumpsuit is form fitting but supple enough to move within as the wide pieces slide back and forth allowing easy movement.  The natural strength of the %^BOLD%^%^BLACK%^leather %^RESET%^%^MAGENTA%^provides extra protection as well, making the outfit suitable for those unwilling or unable to wear the heavier armors.  Laces tie up the front from waist to neck where a band of soft, %^BOLD%^%^BLACK%^black bear fur %^RESET%^%^MAGENTA%^creates a wide collar just under the jaw.  The sleeves are long, covering the full length of the arm with tight crisscrossing panels and terminating at the wrist with a matching cuff of %^BOLD%^%^BLACK%^bear's fur%^RESET%^%^MAGENTA%^.  Like the shirt portion, the leggings also feature leather-laces from knee to ankle and are edged with a thin strip of the %^BOLD%^%^BLACK%^bear fur%^RESET%^%^MAGENTA%^ on either side that terminates just above the foot.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(1400);
	set_lore(
@AVATAR
Created by the Hunters of Malar, these leather crafted items are made from the training hunts that their Beastlord's clergy use to enhance their skills.  While the meat of the beast is often consumed or used to lure larger prey, the pelts themselves are transformed via a lengthy tanning and crafting process into exceptional clothing or armor.  These pieces are often used by the Hunters as rewards for those outside the faith who have proven themselves either in the hunt or by helping the Hunters directly.  Though they are never given to someone who doesn't actively engage in hunting in one manner or another.  Often referred to by the Beastlord's followers to be "traveling hunters" as they are those who are not of the faith but understand the ways of the hunt, these items have come to be known by a similar name. 

AVATAR
	);
	set_property("lore difficulty",15);
	set_max_internal_encumbrance(7);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^"+ETOQCN+" slides their body into the "+query_short()+" %^RESET%^%^MAGENTA%^and quickly ties up all the laces%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You slide your body into the "+query_short()+" %^RESET%^%^MAGENTA%^and quickly tie up all the laces%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^After undoing all the laces on the "+query_short()+"%^RESET%^%^MAGENTA%^, "+ETOQCN+" slithers out of the garment with a soft sigh.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^After undoing all the laces on the "+query_short()+"%^RESET%^%^MAGENTA%^, you slither out of the garment with a soft sigh.%^RESET%^");
	return 1;
}
