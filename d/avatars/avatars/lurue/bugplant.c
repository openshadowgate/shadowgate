#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("plant");
	set_id(({ "plant", "green plat", "vine", "vines", "bundle", "bundle of vines" }));
	set_short("%^GREEN%^a thick bundle of vines%^RESET%^");
	set_obvious_short("%^GREEN%^a thick bundle of vines%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^Growing out of a small %^ORANGE%^clay pot %^GREEN%^is a sinewy bundle of vines that loops over itself and tangles amongst itself.  Pairs of tiny dark green, nearly black leaves sprout from the thick mass of cords like folded %^BOLD%^%^BLACK%^insect wings%^RESET%^%^GREEN%^.  Here and there, small fleshy %^RESET%^pods %^GREEN%^protrude from under the leaves. The thin, pale skin revealing a darker %^BOLD%^%^BLACK%^seed-core %^RESET%^%^GREEN%^within. Oddly, as you watch these pods swing too and fro, it almost looks like the %^BOLD%^%^BLACK%^dark shapes %^RESET%^%^GREEN%^within are moving about.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(50);
	set_lore(
@AVATAR
Grown by the Hags of Yntala Forest, these plants are rumored to contain a festering type of herb magic that allows the plants to reproduce whatever they are fed.  Creating small things like bugs or snakes from their seeds if tended properly.  Only the Hags know for sure what the true nature of these plants are and it takes a brave and daring soul to reveal their magic.

AVATAR
	);
	set_property("lore difficulty",13);
}