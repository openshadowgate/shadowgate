#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define CHEST "/d/magic/mon/secret_chest"
inherit SPELL;

object chest;

void create()
{
    ::create();
    set_spell_name("secret chest");
    set_spell_level(([ "mage" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS secret chest");
    set_description("This spell calls to a floating extraplanar chest that will follow the caster everywhere, and even defend him, although poorly. The primary function of this chest is to store caster's equipment and be dispelled. This is a greater summon and won't work with spells of such class, such as gate and conjure elemental.

To command chest, use %^ORANGE%^<command chest to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^.
To command lost chest to follow you once again, use %^ORANGE%^<command chest to follow>%^RESET%^.
To dismiss the chest use %^ORANGE%^<dismiss chest>%^RESET%^.");
	set_helpful_spell(1);
    set_components(([
                        "mage" : ([ "tiny chest":1,
                                    "onyx dust":1]),
                        ]));
}

//Blep


