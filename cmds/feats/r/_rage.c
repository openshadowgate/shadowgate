#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

// Flags to determine rage type
string rage_class;
int tireless_rage = 0;
int spirit_warrior = 0;

object* exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Rampage");
    feat_name("rage");
    feat_syntax("rage");
    feat_prereq("Barbarian L1");
    feat_classes("barbarian");
    feat_desc("This feat allows the barbarian to enter a fit of furious rage, boosting their strength, constitution, and will. The ability will last longer, and grow stronger, as the barbarian gains levels. Rage can be turned off by typing rage again. By the end of raging the barbarian will become fatigued. Rage will be interrupted if the barbarran becomes fatigued and exhausted.

%^BOLD%^N.B.%^RESET%^ Being enraged means that you are maddened uncontrollably. This is *not* a state in which you can calmly participate in a normal conversation, undertake delicate tasks, cast offensive spells, solve problems, or pretty much do anything other than shout obscenities and kill things. This power won't work in conjunction with similar magical effects, such as rally, transformation, rage, berserker and fell flight.

%^BOLD%^N.B.%^RESET%^ Rage status can be set using prompt. Please see help prompt for more information.

%^BOLD%^See also:%^RESET%^ rage *spells, satus effects, prompt");
    allow_blind(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("barbarian")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_rage(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);

    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str, "red and black");
}

void execute_feat()
{
    object obj;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "rage")) {
        obj = query_active_feat("rage");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        return;
    }

    if (caster->query_property("using instant feat")) {
        tell_object(caster, "%^BOLD%^You are already in the middle of using a feat.%^RESET%^");
        dest_effect();
        return;
    }
    if (caster->query_casting()) {
        tell_object(caster, "%^BOLD%^You can't rage while you're casting a spell.%^RESET%^");
        dest_effect();
        return;
    }

    if (caster->query_property("effect_exhausted") || caster->query_property("effect_fatigued")) {
        tell_object(caster, "%^BOLD%^You are fatigued or exhausted and cannot rage.%^RESET%^");
        dest_effect();
        return;
    }

    tell_object(caster, cm("You gather strength as you prepare to go into frenzy."));
    caster->set_property("active_feats", ({ TO }));


    if (FEATS_D->usable_feat(caster, "mighty rage")) {
        rage_class = "mighty rage";
    } else if (FEATS_D->usable_feat(caster, "greater rage")) {
        rage_class = "greater rage";
    } else {
        rage_class = "simple rage";
    }

    if (FEATS_D->usable_feat(caster, "tireless rage")) {
        tireless_rage = 1;
    }

    if (FEATS_D->usable_feat(caster, "spirit warrior")) {
        spirit_warrior = 1;
    }

    caster->set_property("raged", 1);
    caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
    caster->set_property("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
    call_out("enable_rage", ROUND_LENGTH);

    ::execute_feat();
    return;
}

void enable_rage()
{
    int duration;

    activate_rage(1);
    tell_object(caster, cm("The world takes on a tinge of red as you are overcome by an insatiable desire to see your enemies rendered into a bloody pulp."));
    tell_room(place, cm(caster->QCN + " growls fiercely as " + caster->QS + " transforms into a homicidal maniac."), caster);

    duration = ROUND_LENGTH * (flevel * 4);

    if (!FEATS_D->usable_feat(caster, "persistent rage")) {
        call_out("dest_effect", duration);
    }
}

void activate_rage(int direction)
{
    switch (rage_class) {
    case "simple rage":
        simple_rage(direction);
        break;

    case "greater rage":
        greater_rage(direction);
        break;

    case "mighty rage":
        mighty_rage(direction);
        break;
    }

    if (spirit_warrior) {
        spirit_warrior(direction);
    }

    if (!tireless_rage) {
        if (direction < 0) {
            "/std/effect/status/fatigued"->apply_effect(target, 36); // 36 rounds - three minutes
        }
    }
}

void simple_rage(int direction)
{
    caster->add_stat_bonus("strength", 4 * direction);
    caster->add_stat_bonus("constitution", 4 * direction);
    caster->add_saving_bonus("will", 2 * direction);
    caster->add_ac_bonus(-2 * direction);
}

void greater_rage(int direction)
{
    caster->add_stat_bonus("strength", 6 * direction);
    caster->add_stat_bonus("constitution", 6 * direction);
    caster->add_saving_bonus("will", 3 * direction);
    caster->add_ac_bonus(-2 * direction);
}

void mighty_rage(int direction)
{
    caster->add_stat_bonus("strength", 8 * direction);
    caster->add_stat_bonus("constitution", 8 * direction);
    caster->add_saving_bonus("will", 4 * direction);
    caster->set_property("fast healing", direction);
    caster->add_ac_bonus(-2 * direction);
}

void spirit_warrior(int direction)
{
    caster->set_missChance(caster->query_missChance() + 33 * direction);
}

void execute_attack()
{
    object* attackers = ({ });
    object* allies = ({ });
    int i;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (caster->query_ghost() || caster->query_unconscious()) {
        dest_effect();
        return;
    }

    if (!caster->query_property("raged")) {
        dest_effect();
        return;
    }

    place = environment(caster);
    attackers = caster->query_attackers();

    if (spirit_warrior) {
        if (sizeof(attackers)) {
            tell_object(caster, cm("Your insatiable bloodlust quickens your reflexes offering you the opportunity to make another attack!"));
            tell_room(place, cm(caster->QCN + "'s attacks become a frenzied blur."), caster);
            caster->execute_attack();
        }
        if (!random(5)) {
            tell_room(place, "%^BOLD%^%^WHITE%^" + caster->QCN + " takes on a ghostly appearance.", caster);
            tell_object(caster, "%^BOLD%^%^WHITE%^You feel insubstantial as your rage continues.");
        }
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    } else {
        dest_effect();
    }
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, cm("You struggle to catch your breath as you try to yank yourself away from your murderous reverie."));
        caster->remove_property_value("active_feats", ({ TO }));
        caster->remove_property("raged");
        caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
        activate_rage(-1);
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
