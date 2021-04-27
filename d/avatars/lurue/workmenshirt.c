#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cotton shirt");
	set_id(({ "shirt", "white shirt", "workmen's shirt", "workmens shirt" }));
	set_short("%^BOLD%^%^WHITE%^workmen's shirt%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a white cotton shirt%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Made from lightweight, thick-knit cotton, this shirt is designed for wearing by almost %^CYAN%^anyone%^WHITE%^ and features a high collar that can be left open and loose or closed with a pair of nearly %^RESET%^invisible ties%^BOLD%^%^WHITE%^.  Likewise at the wrists of the somewhat puffy sleeves, the cuffs can be tied tight or left open to allow the sleeves to be rolled up.  Though the garment is a simple white color, the material is soft and designed to %^CYAN%^breathe%^WHITE%^, retaining warmth during cold weather and staying cool in warm weather.  A useful, all around, garment that could be %^CYAN%^dyed %^WHITE%^to suit one's particular tastes or needs. 

AVATAR
	);
	set_weight(1);
	set_value(500);
	set_lore(
@AVATAR
These shirts were made popular by sailors and traders who needed a versatile, breathable shirt to get them through the day, regardless of weather conditions.  Designed by weavers throughout the world, most are fairly plain and unadorned, coming in white or a light natural shade.  Though many people have them %^CYAN%^dyed%^RESET%^ to their favorite color.  This became so popular that many of the shirts were enchanted to change with the will of the wearer.  Although these enchanted versions were rare, those who had them coveted their added versatility. 

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You slide the "+query_short()+" %^BOLD%^%^CYAN%^over your head and tug it down into place, admiring the comfort the soft cotton yields.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^With a soft sigh, you take your "+query_short()+" %^BOLD%^%^CYAN%^off.%^RESET%^");
	return 1;
}

