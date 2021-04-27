#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
	::create();
	set_name("bangles");
	set_id(({ "bands", "bangles", "bands of turquoise", "cor'thial'de na", "bracers", "bracer" }));
	set_short("%^BOLD%^%^CYAN%^C%^WHITE%^o%^BLUE%^r%^CYAN%^'thi%^WHITE%^a%^BLUE%^l%^CYAN%^'de N%^WHITE%^a%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^bands of %^CYAN%^turquoise%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^These bangles are the most curious of things.  Formed of incredibly old %^CYAN%^turquoise%^BLUE%^ they fit around the wrist comfortably "
"and are loose enough to slide just a little.  The pale blue stone is veined with %^WHITE%^white %^BLUE%^and %^BLACK%^black %^BLUE%^crystal bands but shows no sign of "
"special design.  What is odd about them is that they give off a pale %^CYAN%^glimmer of light %^BLUE%^that shines up the length of the wearer's arm, bathing the arm "
"from wrist to elbow in their %^CYAN%^pale light%^BLUE%^.  Where the light emanates from, however, is impossible to tell.%^RESET%^");
	set_value(4000);
	set_lore("The Cor'thial'de Na is an ancient proverb from a culture long since vanished.  That this one phrase has endured the centuries speaks to how powerful the "
"meaning behind it is: %^BOLD%^%^CYAN%^The Self Is All.  %^RESET%^It is said that the society from which these words of inspiration were derived from found that turquoise "
"radiated with the most wholesome of light when a person understood and believed this truth.  Tricksters and hucksters in later times used this lore and light magic to "
"sell turquoise trinkets to gullible patrons, calling those items Cor'thial'de Na, but most faded within a day, shortly after the charlatans vanished.  Despite this a few "
"items are said to have been real and still circulate to this day.  Inspiring.");
	set_property("lore difficulty",35);
	set_item_bonus("wisdom",1);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^The Self Is All.  Rely upon it and its place upon the world, and you shall be free of the constraints that shadow you.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^Never forget the wisdom gained in the simplest of things: The knowledge of self.%^RESET%^");
	return 1;
}

