#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Rage");
    feat_name("renewed vigor");
    feat_classes("barbarian");
    feat_desc("This power allows the barbarian to heal 1d8 plus strength modifier per every four levels.");
    feat_stat_bonus("strength");
    feat_syntax("renewed_vigor");
    set_target_required(0);
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

int cmd_renewed_vigor(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, "");
    return 1;
}

void execute_feat()
{
    object *weapons;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    ::execute_feat();

    tell_object(caster,"%^BOLD%^%^RED%^You waver unevenly as rage rushed through yourself your thoughts.");
    tell_room(place,"%^BOLD%^%^RED%^Closes their eyes an look distant for a split second.",caster);

    caster->set_property("using instant feat",1);
    return;
}

void execute_attack()
{
    int dam;
    int i;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");

    ::execute_attack();

    dam = roll_dice(flevel / 4 + 1 + BONUS_D->query_stat_bonus(caster, "strength"), 8);

    tell_object(caster,"%^BOLD%^%^RED%^Your feel your vitality restored as the rage clouds your pain.");
    caster->cause_typed_damage(caster, caster->return_target_limb(), -dam, "untyped");

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
