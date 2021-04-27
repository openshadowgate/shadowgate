#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^GREEN%^Bracers of Dubious Protection%^RESET%^");
	set_id(({ "bracers" }));
	set_short("%^BOLD%^%^GREEN%^Bracers of Dubious Protection%^RESET%^");
	set_obvious_short("Bronze studded bracers");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This pair of bracers is made out of well treated, finely cured hides of a number of different species.  A few of the strips seem like they used to have scales when their owners were still alive.  Others still retain the texture of an octopus like skin.  There is a number of bronze studs decorating the leather.  They protrude to the inner side of the leather but are polished flush with the surface and do not seem like they would cause the wearer any discomfort.  An image is impressed into the leather, displaying fierce warriors of no race you recognize, a male and a female, locked in deadly combat.  While they seem remotely human, their 'faces' have no features at all.  Both combattants wear what seems to be an exact replica of the bracers you now behold.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(3500);
	set_lore(
@AVATAR
These bracers were dubed %^BOLD%^%^GREEN%^Bracers of Dubious Protection%^RESET%^ by their creator Metikul the Artificer.  They were created from old manuscripts of an unknown origin.  Manuscript's originators are a race long extinct from the realms and no name has survived to recognize them by.  According to Metikul himself, he's not quite sure what properties the process defined in the writings has resulted in.  Though he stated that these artefacts have been employed by some of the fiercest warriors of this long forgotten race.  Still, he vaguely hints at some curse that hangs over these wondrous objects.

AVATAR
	);
	set_type("bracer");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",-5);
	set_ac(13);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,""+ETO->query_cap_name()+"'s movements get almost too fast for your eyes for follow.",TP);
	tell_object(TP,"%^RED%^As you slip "+query_short()+" around your forearms you feel as though the world slows down around you.%^RESET%^");
	ETO->add_stat_bonus("constitution",-3);
	return 1;
}
int remove_func(){
	tell_room(ETP,""+ETO->query_cap_name()+"'s movements return to normal.",TP);
	tell_object(TP,"%^BLUE%^The world around you returns to its normal pace.%^RESET%^");
	ETO->add_stat_bonus("constitution",3);
	return 1;
}
