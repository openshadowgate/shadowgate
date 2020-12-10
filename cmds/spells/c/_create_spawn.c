#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/a/_animate_dead";

void create()
{
    ::create();
    set_spell_name("create spawn");
    set_spell_level(([ "innate" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create spawn");
    set_damage_desc("raises no more than eight vampires.");
    set_description("With this spell a vampire can use the recently deceased to raise a powerful undead vampire spawn to aid them in combat. This power behaves the same way similar spells of creating undead does, but it is unique to vampires." + help_message());
    evil_spell(1);
    set_helpful_spell(1);
    set_arg_needed();
}

string undead_to_raise()
{
    if (caster && caster->is_class("vampire_lord")) {
        return "vampire_knight";
    }
    return "vampire_spawn";
}

int amount_to_raise() {
    return 1;
}

int this_max_hd() {
    return 8;
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^A vampire knight forms itself out of the mist.%^RESET%^";
}

void setup_undead_scaling(object undead)
{
    undead->set_guild_level("fighter", clevel);
    undead->set_mlevel("fighter", clevel);
    if (caster->is_class("vampire_lord")) {
        undead->set_guild_level("mage", clevel);
        undead->set_mlevel("mage", clevel);
        undead->set_weap_enchant(clevel / 10);
        tell_object(caster,"%^BOLD%^%^RED%^Vampire knight speaks to your mind: %^RESET%^%^RED%^I am yours to command, Master.");
    }

    undead->set_skill("perception", clevel);
    undead->set_level(clevel);
    undead->set_hd(clevel, 8);
    undead->set_max_hp(clevel * 12);
    undead->set_attacks_num(clevel / 5 + 1);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(6 - clevel);
}

string err_message_i() {
    return "%^BOLD%^%^BLACK%^A PATHETIC WEAKLING SUCH AS YOURSELF SHALL NOT RAISE MORE!%^RESET%^";
}

void end_message() {
    tell_room(place, "%^BOLD%^%^GREEN%^The corpses %^GREEN%^t%^BLACK%^w%^GREEN%^i%^BLACK%^st%^GREEN%^ and %^BLACK%^c%^GREEN%^h%^BLACK%^an%^GREEN%^g%^BLACK%^e%^GREEN%^s%^GREEN%^ under %^GREEN%^t%^GREEN%^h%^BLACK%^e %^BLACK%^f%^GREEN%^e%^BLACK%^ll %^BLACK%^ma%^GREEN%^g%^BLACK%^i%^GREEN%^c%^BLACK%^,%^GREEN%^ and then finally %^BLACK%^o%^GREEN%^b%^BLACK%^edien%^GREEN%^t%^BLACK%^l%^GREEN%^y%^GREEN%^ stands as %^BLACK%^" + undead_to_raise() + "%^RESET%^", caster);
    //tell_object(caster, "%^BOLD%^%^BLACK%^THE %^WHITE%^" + capitalize(replace_string(undead_to_raise(), "_", " ")) + "%^BLACK%^ RISES%^RESET%^");
    tell_object(caster, "%^BOLD%^%^BLACK%^THE %^WHITE%^" + (caster->is_class("vampire_lord") ? "VAMPIRE KNIGHT" : "VAMPIRE SPAWN") + "%^BLACK%^ RISES%^RESET%^");
}
