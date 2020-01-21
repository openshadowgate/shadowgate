#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

// Flags to determine rage type
static string rage_class;
static int tireless_rage;
static int spirit_warrior;

object *exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Rapage");
    feat_name("ragenextgen");
    feat_syntax("rage");
    feat_prereq("Barbarian L1");
    feat_desc("");
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->query_name()!="ornulf")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_lifeless_shroud(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str,"red and black");
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
        tell_object(caster, cm("You struggle to catch your breath as you try to yank yourself away from your murderous reverie."));
        obj->dest_effect();
        dest_effect();
        return;
    }

    if (caster->query_property("raged")) {
        tell_object(caster, "%^RED%^You are already raging.%^RESET%^");
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

    tell_object(caster, cm("The world takes on a tinge of red as you are overcome by an insatiable desire to see your enemies rendered into a bloody pulp."));
    tell_room(place, "%^RED%^" + caster->QCN + " growls fiercely as " + caster->QS + " transforms into a homicidal maniac.%^RESET%^", caster);

    caster->set_property("active_feats",({TO}));

    caster->set_property("using instant feat",1);

    if (FEATS_D->usable_feat(caster, "mighty rage")) {
        rage_class = "mighty rage";
    } else if (FEATS_D->usable_feat(caster, "greater rage")) {
        rage_class = "greater rage";
    } else {
        rage_class = "simple rage";
    }

    if (FEATS_D->usable_feat(caster, "tireless rage"))
        spirit_warrior = 1;

    if (FEATS_D->usable_feat(caster, "spirit warrior"))
        spirit_warrior = 1;

    call_out("enable_rage", ROUND_LENGTH);

    ::execute_feat();
    return;
}

void enable_rage()
{
    caster->remove_property_value("added short",({"%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^"}));
    caster->set_property("added short",({"%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^"}));
    caster->set_property("raged",1);
    caster->remove_property("using instant feat");
    activate_rage(1);

    if (!FEATS_D->usable_feat(caster, "persistent rage"))
        call_out("dest_effect", ROUND_LENGTH * (caster->query_guild_level("barbarian") * 5));
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

    if (spirit_warrior)
        spirit_warrior(direction);

    if(!tireless_rage)
        if(direction < 0)
        {
            "/std/effect/status/exhausted"->apply_effect(target, 36); // 36 rounds - three minutes
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
    caster->add_stat_bonus("strength", 6 * direction);
    caster->add_stat_bonus("constitution", 6 * direction);
    caster->add_saving_bonus("will", 4 * direction);
    caster->add_ac_bonus(-2 * direction);
}

void spirit_warrior(int direction)
{
    caster->set_missChance(caster->query_missChance() + 50 * direction);
}

void execute_attack()
{
    object *attackers = ({ });
    object *allies = ({ });
    int i;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (caster->query_ghost() || caster->query_unconscious()) {
        dest_effect();
        return;
    }

    if (!caster->query_property("raged"))
    {
        dest_effect();
        return;
    }

    if (caster->query_property("effect_exhausted")) {
        dest_effect();
        return;
    }

    place = environment(caster);
    attackers = caster->query_attackers();

    if(sizeof(attackers))
    {
        tell_object(caster, cm("Your insatiable bloodlust quickens your reflexes offering you the opportunity to make another attack!"));
        tell_room(place, cm(caster->QCN + "'s attacks become a frenzied blur."), caster);
        caster->execute_attack();
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
        caster->remove_property_value(" active_feats ",({TO}));
        caster->remove_property_value(" added short ",({" % ^RESET % ^%^BOLD % ^%^RED % ^(%^RESET % ^%^RED % ^enraged % ^BOLD % ^) % ^RESET % ^"}));
        activate_rage(-1);
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
