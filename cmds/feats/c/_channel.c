#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Presence");
    feat_name("channel");
    feat_prereq("Cleric or Paladin");
    feat_desc("");
    feat_syntax("channel");
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
    if (ob->query_class_level("cleric") < 1 &&
        ob->query_class_level("paladin") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_channel(string str)
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

    if ((int)caster->query_property("using channel") > time() &&
        !FEATS_D->usable_feat(caster, "supreme healer")) {
        tell_object(caster, "It's too soon to use sweeping blow again yet!");
        dest_effect();
        return;
    }

    ::execute_feat();

    tell_object(caster,"%^BOLD%^%^WHITE%^You waver unevenly as you prepare to channel primal energies through yourself.");
    tell_room(place,"%^BOLD%^%^WHITE%^Closes their eyes an look distant for a split second.",caster);

    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack()
{
    object *allies,*attackers;
    object ally, attacker;
    string energy_type;
    string color;
    int dam;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");

    caster->remove_property("using channel");
    caster->set_property("using channel",(time() + 35));

    if (!FEATS_D->usable_feat(caster, "supreme healer")) {
        delay_messid_msg(35, "%^BOLD%^%^WHITE%^You can %^CYAN%^channel%^WHITE%^ again.%^RESET%^");
    }

    ::execute_attack();

    attackers = caster->query_attackers();

    allies = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({ caster });
    allies = distinct_array(allies);
    allies = filter_array(allies, (: environment($1) == $2:), environment(caster));

    dam = roll_dice(clevel, 4);

    if (caster->query_property("negative energy affinity")) {
        energy_type = "negative energy";
        color = "%^BLUE%^";
    } else {
        energy_type = "positive energy";
        color = "%^WHITE%^";
    }

    tell_room(ENV(caster), "%^BOLD%^" + color + "the area is washed with divine energies!");

    foreach(ally in allies)
    {
        if (!objectp(ally)) {
            continue;
        }

        if (energy_type == "negative energy" && !ally->query_property("negative energy affinity")) {
            continue;
        }

        if (energy_type == "positive energy" && ally->query_property("negative energy affinity")) {
            continue;
        }

        ally->cause_typed_damage(ally, ally->query_target_limb(), dam, energy_type);
        tell_object(ally, "%^BOLD%^" + color + "Waves of divine energy was over you, healing your wounds!");
    }

    foreach(attacker in attackers)
    {
        if (!objectp(ally)) {
            continue;
        }

        if (energy_type == "negative energy" && attacker->query_property("negative energy affinity")) {
            continue;
        }

        if (energy_type == "positive energy" && !attacker->query_property("negative energy affinity")) {
            continue;
        }

        ally->cause_typed_damage(ally, ally->query_target_limb(), dam, energy_type);
        tell_object(ally, "%^BOLD%^" + color + "Waves of divine energy was over you, wounding you!");
    }

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
