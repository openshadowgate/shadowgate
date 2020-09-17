#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ArcaneTrickster");
    feat_name("surprise spells");
    feat_prereq("Arcane Trickster L7");
    feat_desc("An arcane trickster knows when to cast her spells. Spells she casts on prone, paralyzed or incapacitated opponents will always deal half of the damage more. In addition, all cast spells will be silenced. Finally, the Arcane Trickster gets a +4 to DC when rolling against saves against their spells.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("arcane_trickster") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
