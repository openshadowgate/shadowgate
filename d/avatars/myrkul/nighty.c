#include <std.h>
inherit "/d/common/obj/clothing/robe";

void create(){
	::create();
	set_name("nighty");
	set_id(({ "nighty", "robe" }));
	set_short("%^BOLD%^%^BLACK%^N%^MAGENTA%^a%^BLACK%^ugh%^MAGENTA%^t%^BLACK%^y N%^MAGENTA%^i%^BLACK%^ghty%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^N%^MAGENTA%^a%^BLACK%^ugh%^MAGENTA%^t%^BLACK%^y N%^MAGENTA%^i%^BLACK%^ghty%^RESET%^");
	set_long("%^BOLD%^%^MAGENTA%^This silken shift leaves %^BLACK%^little%^MAGENTA%^ to the imagination. It is possible that it might cover a woman's ass. But not by much. And even if it did manage to cover her bre"
	"asts, you could probably just see straight through the %^BLUE%^sheer%^MAGENTA%^ silk. Not for the faint of heart, this could barely be worn indoors behind closed doors. It would take %^WHITE%^supreme "
	"confidence%^MAGENTA%^ to wear this outfit!%^RESET%^
"
	);
	set_value(10000);
	set_lore("It is legend that succubus once made a bet with Sune over who looked the best. It is rumored that the succubus wore this Naughty Nightie and won. Of course Sune slew her on the spot and hung what demo"
	"nic remains of soul were left in pocket dimension filled with dung for a thousand years. Who knows if it were true or not, but wearing this thing, maybe a succubus might have a shot at Sune!
"
	);
    set_property("lore difficulty",20);
	set_size(2);
	set_property("enchantment",1);
}



