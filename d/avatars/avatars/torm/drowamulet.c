#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Amulet of Auras");
	set_id(({ "amulet", "mysterious amulet", "amulet of auras" }));
	set_short("%^CYAN%^Am%^RED%^ul%^YELLOW%^et %^BLUE%^of%^GREEN%^ Au%^RED%^ra%^CYAN%^s%^RESET%^");
	set_obvious_short("a small amulet");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This amulet is strung on %^WHITE%^a strong adamantium chain%^CYAN%^.  The amulet itself is %^BLUE%^a rounded shape%^CYAN%^ and seems to be %^RESET%^%^ORANGE%^mad%^GREEN%^e%^ORANGE%^ of w%^RED%^o%^ORANGE%^od%^BOLD%^%^CYAN%^.  The wooden disc is covered with %^BOLD%^%^BLACK%^numerous small carvings of mystical symbols%^CYAN%^ which have then been painted in a wide variety %^RED%^of b%^MAGENTA%^ri%^BLUE%^gh%^YELLOW%^t c%^GREEN%^ol%^BLUE%^ou%^RED%^rs%^CYAN%^.  The reverse of the amulet bears a short inscription.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Amulet of Auras.  Effects will vanish once amulet is removed.

AVATAR
	);
     set("langage","drow");	set_weight(3);
	set_value(450);
	set_lore(
@AVATAR
%^CYAN%^The Amulet of Auras has been rumoured to exist for well over a century.  The amulet is said to give protection from magical and divine methods of determining the wearer's true nature.  The use of it it has been linked almost exclusively to drow who use it to help put their victims off guard, and is almost certainly of drow origin and manufacture.  Anyone attempting to discover the true nature of the wearer through use of the weave or divine guidance is likely to be left with no strong impressions at all.  It is not known if more than one amulet was ever created sucessfully.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(2);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^CYAN%^You feel disoriented for a moment as you secure the amulet around your neck%^RESET%^");
	ETO->set_property("magic resistance",2);
	return 1;
}

