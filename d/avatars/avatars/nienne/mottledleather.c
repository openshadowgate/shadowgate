inherit "/d/common/obj/armour/studded";

void create() {
    ::create();
    set_name("mottled studded");
    set_id(({ "armor","leather armor","armour","mottled leather","leather","mottled leather armor" }));
    set_short("%^RESET%^%^ORANGE%^m%^RESET%^o%^ORANGE%^t%^BOLD%^%^BLACK%^tl%^RESET%^%^ORANGE%^ed leather armor%^RESET%^");
    set_long("%^RESET%^This armor is made from leather, but rather than %^RED%^hardened %^RESET%^for protection, it has "
"been reinforced with a series of small, close-set rivets.  Each is made of dull, %^BOLD%^%^BLACK%^non-reflective "
"%^RESET%^metal so as not to catch and reflect any light.  The leather itself is oddly colored in a seemingly-random "
"pattern of %^ORANGE%^d%^RESET%^a%^ORANGE%^r%^BOLD%^%^BLACK%^ke%^RESET%^%^ORANGE%^r %^RESET%^patches, giving it an "
"overall mottled effect.  It would probably serve as effective %^GREEN%^ca%^ORANGE%^mo%^GREEN%^ufl%^ORANGE%^a%^GREEN%^ge "
"%^RESET%^in shadowed or wilderness areas.\n");
    set_value(360);
    set_property("enchantment",2);
}
