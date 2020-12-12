#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/a/_animate_dead";

void create()
{
    ::create();
    set_spell_name("create undead");
    set_spell_level(([ "mage" : 6, "cleric" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create undead");
    set_damage_desc("raises no more than three graveknights.");
    set_description("Animating dead is a pathetic craft for the weak. A true necromancer's art is to change what was into something more potent and powerful that can serve his fell desires and schemes. This spell uses a fallen corpse to make an undead creature from rotting flesh. Such a creature is more potent than lesser skeletons and zombies, and will serve the necromancer until discorporated. This spell is without a doubt evil, as the soul used to fuel the new shell is twisted and changed forever (of a maximum 3)." + help_message());
    evil_spell(1);
    set_components(([
      "mage" : ([ "drop of blood" : 1, ]),
    ]));
    set_helpful_spell(1);
    set_arg_needed();
}

string undead_to_raise() {
    return "graveknight";
}

int amount_to_raise() {
    return 1;
}

int this_max_hd() {
    return 3;
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^GREEN%^You cut your %^BOLD%^%^GREEN%^wrists and %^GREEN%^s%^BLACK%^i%^GREEN%^n%^GREEN%^g%^GREEN%^ low in %^GREEN%^f%^BLACK%^ell%^GREEN%^ tongues.%^RESET%^");
    return "%^BOLD%^%^GREEN%^" + caster->QCN + " cuts " + caster->QP + "%^BOLD%^%^GREEN%^wrists and %^GREEN%^s%^BLACK%^i%^GREEN%^n%^GREEN%^g%^BLACK%^s%^GREEN%^ low in %^GREEN%^f%^BLACK%^ell%^GREEN%^ tongues.%^RESET%^";
}

void setup_undead_scaling(object undead)
{
    undead->set_guild_level("fighter", clevel);
    undead->set_weap_enchant(clevel / 10);
    undead->set_skill("athletics", clevel);
    undead->set_skill("perception", clevel - 10);
    undead->set_level(clevel);
    undead->set_hd(clevel, 6);
    undead->set_max_hp(clevel * 14 + 100);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(10 - clevel);
}

string err_message_i() {
    return "%^BOLD%^%^BLACK%^A PATHETIC WEAKLING SUCH AS YOURSELF SHALL NOT RAISE MORE!%^RESET%^";
}

void end_message() {
    tell_room(place, "%^BOLD%^%^GREEN%^The corpses %^GREEN%^t%^BLACK%^w%^GREEN%^i%^BLACK%^st%^GREEN%^ and %^BLACK%^c%^GREEN%^h%^BLACK%^an%^GREEN%^g%^BLACK%^e%^GREEN%^s%^GREEN%^ under %^GREEN%^t%^GREEN%^h%^BLACK%^e %^BLACK%^f%^GREEN%^e%^BLACK%^ll %^BLACK%^ma%^GREEN%^g%^BLACK%^i%^GREEN%^c%^BLACK%^,%^GREEN%^ and then finally %^BLACK%^o%^GREEN%^b%^BLACK%^edien%^GREEN%^t%^BLACK%^l%^GREEN%^y%^GREEN%^ stands as %^BLACK%^" + undead_to_raise() + "%^RESET%^", caster);
    tell_object(caster, "%^BOLD%^%^BLACK%^THE %^WHITE%^" + upper_case(replace_string(undead_to_raise(), "_", " ")) + "%^BLACK%^ RISES%^RESET%^");
}
