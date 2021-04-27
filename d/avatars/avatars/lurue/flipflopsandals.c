#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("sandals");
	set_id(({ "sandals", "flower sandals", "beaded sandals" }));
	set_short("%^RESET%^%^RED%^p%^ORANGE%^l%^YELLOW%^a%^RESET%^%^GREEN%^y%^RED%^f%^ORANGE%^u%^YELLOW%^l %^RESET%^%^ORANGE%^s%^GREEN%^a%^RED%^n%^YELLOW%^d%^RESET%^%^ORANGE%^a%^RED%^l%^GREEN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a set of %^RED%^s%^YELLOW%^l%^RESET%^%^ORANGE%^i%^RED%^p%^ORANGE%^-%^YELLOW%^o%^RESET%^%^GREEN%^n%^ORANGE%^ sandals%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Simple in their design, these sandals slip onto the feet with a thin thong running between the first and second toe.  The thong stretches up to meet a beaded band covered in %^RED%^red%^ORANGE%^, %^GREEN%^green %^ORANGE%^and %^YELLOW%^yellow %^RESET%^%^ORANGE%^beads, which reaches over the top of the foot.  At the juncture, a %^RESET%^silver medallion %^ORANGE%^has been set.  Slightly tarnished, the medallion has the image of a delicate looking flower, much like that of a %^YELLOW%^daisy%^RESET%^%^ORANGE%^.  With no support on the heel, the flat of leather sole slaps slightly against the wearer's heal making a fun little click-clack sound.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(300);
	set_lore(
@AVATAR
Made for lounging about the home, these slippers are popular mostly with women, though a few men have taken to wearing them as well, simply due to their ease of wear and the comfortable fit. Said to have started appearing in several seaside towns, via various little trinket carts, these slippers can also be seen worn around the beach as they allow the wearer to shed them quickly in order to enter the water, and are easily replaced, even with sandy feet. 

AVATAR
	);
	set_property("lore difficulty",8);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You wiggle your toes as you slide these comfortable slip-ons on.%^RESET%^");
	return 1;
}


