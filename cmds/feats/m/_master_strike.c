#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("MeleeDamage");
    feat_name("master strike");
    feat_syntax("master_strike [TARGET]");
    feat_prereq("Thief L20");
    feat_desc("Ability to surprise your opponent and position yourself properly in combat is represented through the master strike, a deadly technique that allows the thief to deal harm and disruptively paralyze their opponents. Succesful save will allow their victim to endure through half of the damage.");
    set_save("fort");
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((int)ob->query_class_level("thief") < 20) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_master_strike(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    mapping tempmap;
    object* weapons;
    int x;
    ::execute_feat();
    tempmap = caster->query_property("using master strike");
    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to affect.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info", caster);
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (target == caster) {
        tell_object(caster, "There are better ways to kill yourself.");
        dest_effect();
        return;
    }
    if (caster->query_casting()) {
        tell_object(caster, "%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if (!objectp(target)) {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }

    if (!present(target, place)) {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }

    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    caster->set_property("using instant feat", 1);

    tell_object(caster, "%^RESET%^%^ORANGE%^You position yourself and commit to an unexpected strike at " + target->QCN + ".%^RESET%^");
    tell_room(place, "%^RESET%^%^ORANGE%^" + caster->QCN + " through some trickery ends up in " + target->QCN + "'s weak spot.%^RESET%^", caster);
    return;
}

void execute_attack()
{
    int damage, timerz, i;
    int bonusdc;
    object* keyz, shape, * weapons, myweapon, qob;
    mapping tempmap;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    caster->remove_property("using instant feat");
    ::execute_attack();

    if (!objectp(target)) {
        dest_effect();
        return;
    }

    if (caster->query_unconscious()) {
        dest_effect();
        return;
    }

    if (!objectp(target) || !present(target, place)) {
        tell_object(caster, "Your target has eluded you!");
        dest_effect();
        return;
    }

    tempmap = caster->query_property("using master strike");

    if (!mapp(tempmap)) {
        tempmap = ([]);
    }

    if (tempmap[target]) {
        map_delete(tempmap, target);
    }

    keyz = keys(tempmap);

    for (i = 0; i < sizeof(keyz); i++) {
        if (!objectp(keyz[i])) {
            map_delete(tempmap, keyz[i]);
        }
        continue;
    }

    timerz = time() + 300;
    delay_subject_msg(target, 300, "%^BOLD%^%^WHITE%^" + target->QCN + " can be %^CYAN%^master striken again%^WHITE%^ again.%^RESET%^");
    tempmap += ([ target:timerz ]);
    caster->remove_property("using master strike");
    caster->set_property("using master strike", tempmap);

    tell_object(caster, "%^YELLOW%^You strike at " + target->QCN + " with all ferocity!");
    tell_room(place, "%^YELLOW%^" + caster->QCN + " strikes at " + target->QCN + " with all ferocity!", caster);

    bonusdc = clevel;
    bonusdc += BONUS_D->query_stat_bonus(caster, "dexterity");
    spell_kill(target, caster);

    {
        object* weapon = caster->query_wielded();
        string damtype;

        if (sizeof(weapon)) {
            damtype = weapon[0]->query_damage_type();
        }else {
            damtype = "piercing";
        }

        damage = roll_dice(flevel, 6);

        if (do_save(target, -bonusdc)) {
            tell_room(place, "%^BOLD%^%^WHITE%^" + target->QCN + " endures through lethal strike!", target);
            tell_object(target, "%^BOLD%^%^WHITE%^You are are merely slightly shaken, unable to move!");
            target->cause_typed_damage(target, target->return_target_limb(), damage / 2, damtype);
        } else {
            tell_room(place, "%^BOLD%^%^MAGENTA%^Crushing strike hits " + target->QCN + " !", target);
            tell_object(target, "%^BOLD%^%^MAGENTA%^Unberable strike finds a weakness in your defences!\n");
            target->cause_typed_damage(target, target->return_target_limb(), damage, damtype);
            target->set_paralyzed(roll_dice(1, 4) * 2, "%^BOLD%^%^RED%^The impact of the strike has left you unable to move!%^RESET%^");
        }
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
