#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

static string rage_class;

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
        break;
    }
    if (caster->query_property("using instant feat")) {
        tell_object(caster, "%^BOLD%^You are already in the middle of using a feat.%^RESET%^");
        dest_effect();
        break;
    }
    if (caster->query_casting()) {
        tell_object(caster, "%^BOLD%^You can't rage while you're casting a spell.%^RESET%^");
        dest_effect();
        break;
    }

    tell_object(caster, cm("The world takes on a tinge of red as you are overcome by an insatiable desire to see your enemies rendered into a bloody pulp."));
    tell_room(place, "%^RED%^" + caster->QCN + " growls fiercely as " + caster->QS + " transforms into a homicidal maniac.%^RESET%^", caster);

    caster->set_property("active_feats",({TO}));

    caster->set_property("using instant feat",1);

    call_out("enable_rage",ROUND_LENGTH);

    ::execute_feat();
    return;
}

void enable_rage()
{
    caster->remove_property_value("added short",({"%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^"}));
    caster->set_property("added short",({"%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^"}));
    caster->set_property("raged",1);
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

    place = environment(caster);
    attackers = caster->query_attackers();

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    } else {
        dest_effect();
    }
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,cm("Your rage ends and you."));
        caster->remove_property_value("active_feats",({TO}));
        caster->remove_property_value("added short",({"%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^"}));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
