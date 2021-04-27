#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("pants");
	set_id(({ "pants", "comfortable pants", "adjustable pants" }));
	set_short("%^RESET%^%^ORANGE%^a%^BLACK%^%^BOLD%^d%^RESET%^j%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^sta%^RESET%^b%^ORANGE%^le p%^BOLD%^%^BLACK%^a%^RESET%^n%^ORANGE%^ts%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a comfortable pair of pants%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Created from a natural colored cotton and linen blend, these pants have a little give to them, but otherwise remain neatly crisp and perfect for wearing both in day-to-day settings as well as more formal occasions.  Designed to conform to the body wearing it, an inner drawstring allows the garment to be synched around the waist, while a very clever tie system along the pant cuffs allow the legs to be shortened or lengthened a small amount to adjust for height.  The inner cotton lining providing a means by which to hide the lacing that would otherwise be visible.  This inner lining further keeps the garment cool and breathable as well as gentle and soft against the skin.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(500);
	set_lore(
@AVATAR
In the first half of fifth century SG, a gnomish clothier shop opened in Asgard.  More interested in innovation rather then practicality, most of the garments produced by Seventh Stitch were more theatrical or comical then they were practical.  Though they did strike upon a few garments which provided minor success.  Amongst those were a set of expandable pants which featured intricate ties in the pant cuffs and a stretchy waist tie, cutting back on the need for after market tailoring.  While only a minor success, at the time Seventh Stitch felt they were onto something and, in an attempt to market to a greater market, had a few pairs enchanted to be as protective as they were flattering.  From "Clothing of Asgard" by Jullie Nesrolli

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "left leg", "right leg" }));
	set_size(1);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" seems happy with the way their pants fit.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip the set of pants on and are amazed by their comfort and style.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}

