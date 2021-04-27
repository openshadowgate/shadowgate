#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "house ring" }));
	set_short("%^BOLD%^%^WHITE%^g%^BOLD%^%^RED%^l%^RESET%^%^WHITE%^o%^BOLD%^%^YELLOW%^w%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^g si%^YELLOW%^l%^BOLD%^%^RED%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^r r%^RESET%^%^WHITE%^i%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^g%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^g%^BOLD%^%^RED%^l%^RESET%^%^WHITE%^o%^BOLD%^%^YELLOW%^w%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^g si%^YELLOW%^l%^BOLD%^%^RED%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^r r%^RESET%^%^WHITE%^i%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^g%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Strange, seemingly mo%^BOLD%^%^RED%^l%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^en s%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^v%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^r forms this horribly twisted ring.  Constant swirling %^BOLD%^%^YELLOW%^ye%^RESET%^%^WHITE%^l%^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^w%^BOLD%^%^YELLOW%^s %^BOLD%^%^WHITE%^and si%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^vers toy at the edges of mercury colored silver as if attempting to betray an angry red glow within the ring.  One thing remains constant however, the outline of a %^BOLD%^%^BLACK%^spider%^BOLD%^%^WHITE%^, the purest black, with a wicked %^BOLD%^%^RED%^glowing dagger %^BOLD%^%^WHITE%^overlaying it's back.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^This ring is mentioned in few legends, but to the trained scholar, one word seems to linger on the edge of recollection: Kartah.  A house of vicious assassins and cunning mages, they are a small, discreet house of drow.  Unlike most drow of the underdark, these are content to remain for the most part quiet.  As such, not much is known of them, except that to mention them openly is to ask for an early grave.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",25);
	set_type("ring");
	set_limbs(({ "left hand", "right hand" }));
	set_size(2);
	set_property("enchantment",1);
}


