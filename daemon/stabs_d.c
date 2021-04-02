#include <std.h>
#include <daemons.h>

varargs int get_stab_damage(object player, object target, object weapon)
{
    int thac0, ret, roll, level, size, damage, i;
    object* head;

    if (!objectp(player)) {
        return 0;
    }
    if (!objectp(target)) {
        return 0;
    }

    if (!target->query_limbs()) {
        return 0;
    }

    ret = BONUS_D->query_dex_bonus(target);
    ret -= BONUS_D->query_stance_bonus(target);
    roll = random(20) + 1;

    if (player->is_class("thief")) {
        if (userp(player)) {
            level = player->query_guild_level("thief");
            if (FEATS_D->usable_feat(player, "invisible thief")) {
                level += 5;
            }
        }else {
            level = player->query_class_level("thief");
        }
        level = (level / 2) + 1;
    }

    // Other stab sources than thief class go here.

    // Number of stabs is defined in living.c

    if (!objectp(target)) {
        return 0;
    }

    size = target->query_size();

    if (objectp(weapon)) {
        damage = weapon->query_damage();
    } else {
        damage = roll_dice(1, 4);
    }

    if (FEATS_D->usable_feat(player, "weapon finesse")) {
        damage += "/daemon/bonus_d"->damage_bonus(player->query_stats("dexterity"));
    }else {
        damage += "/daemon/bonus_d"->damage_bonus(player->query_stats("strength"));
    }

    if (player->query_property("strong stab")) {
        roll = 8;
    }else {
        roll = 6;
    }

    // 1d8 per level for "strong stab" creatures, 1d6 for normal/players
    damage += roll_dice(level, roll);


    // Ghosts and incorporeals can be stabbed only with magic weapons

    if (objectp(target)) {
        if (target->query_property("weapon resistance")) {

            int enchantment, resistance;
            enchantment = 0;
            resistance = target->query_property("weapon resistance");
            if (!objectp(weapon)) {
                enchantment = COMBAT_D->unarmed_enchantment(TP);
            }else if (objectp(weapon)) {
                enchantment = weapon->query_property("enchantment");
            }
            if (enchantment < resistance) {
                damage = 0;
            }
        }
    }

    return damage;
}

int combat_backstab(object stabber, object victim)
{
    int penalty, damage, level, roll, magic, damtype;
    object* weapon;
    int nostab = 0;

    weapon = stabber->query_wielded();

    if (!objectp(victim)) {
        victim = stabber->query_current_attacker();
    }

    if (!roll_stab_dcs(stabber, victim)) {
        return 0;
    }
    switch (random(3)) {
    case 0:
        tell_object(stabber, "%^BOLD%^%^YELLOW%^You move quickly into position and execute three quick slices at l%^RESET%^i%^YELLOW%^g%^RESET%^h%^BOLD%^%^YELLOW%^t%^RESET%^n%^BOLD%^%^YELLOW%^i%^RESET%^n%^BOLD%^%^YELLOW%^g speed!");
        tell_object(victim, "%^BOLD%^%^BLUE%^" + stabber->query_cap_name() + " quickly moves into position and executes three l%^RESET%^i%^BLUE%^g%^RESET%^h%^BOLD%^%^BLUE%^t%^RESET%^n%^BOLD%^%^BLUE%^i%^RESET%^n%^BOLD%^%^BLUE%^g quick slices!");
        tell_room(environment(stabber), "%^BOLD%^%^YELLOW%^" + stabber->query_cap_name() + " quickly moves into position on " + victim->query_cap_name() + " and executes three attacks at l%^RESET%^i%^BOLD%^%^YELLOW%^g%^RESET%^h%^BOLD%^%^YELLOW%^t%^RESET%^n%^BOLD%^%^YELLOW%^i%^RESET%^n%^BOLD%^%^YELLOW%^g speed!", ({ victim, stabber }));
        break;
    case 1:
        tell_object(stabber, "%^BOLD%^%^GREEN%^You drop a hidden %^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^gg%^RESET%^GREEN%^e%^BOLD%^%^GREEN%^r from the folds of your apparel and kick it from the %^BOLD%^%^YELLOW%^hilt%^BOLD%^%^GREEN%^, sending it flying at " + victim->query_cap_name() + "!");
        tell_object(victim, "%^BOLD%^%^BLUE%^" + stabber->query_cap_name() + " drops a hidden dagger from the folds of  " + stabber->query_possessive() + " apparel and kicks it from the hilt, sending it flying at you!");
        tell_room(environment(stabber), "%^BOLD%^%^GREEN%^" + stabber->query_cap_name() + " drops a hidden %^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^gg%^RESET%^%^GREEN%^er %^BOLD%^%^GREEN%^from " + stabber->query_possessive() + " apparel and kicks it from the %^BOLD%^%^YELLOW%^hilt%^BOLD%^%^GREEN%^, sending it flying at " + victim->query_cap_name() + "!", ({ victim, stabber }));
        break;
    case 2:
        tell_object(stabber, "%^BOLD%^%^RED%^You reach into your pocket and slap a rune covered %^RESET%^%^RED%^note%^BOLD%^%^RED%^ on " + victim->query_cap_name() + "! You roll backwards as it *pause* E%^BOLD%^%^BLACK%^X%^BOLD%^%^RED%^P%^BOLD%^%^BLACK%^L%^BOLD%^%^RED%^O%^BOLD%^%^BLACK%^D%^BOLD%^%^RED%^E%^BOLD%^%^BLACK%^S%^BOLD%^%^RED%^ seconds later!");
        tell_object(victim, "%^BOLD%^%^RED%^" + stabber->query_cap_name() + " reaches into " + stabber->query_possessive() + " pocket and slaps an rune covered note on you before rolling away! Seconds later it EXPLODES!");
        tell_room(environment(stabber), "%^BOLD%^%^RED%^" + stabber->query_cap_name() + " reaches into " + stabber->query_possessive() + " pocket and slaps a rune covered %^RESET%^%^RED%^note%^BOLD%^%^RED%^ on " + victim->query_cap_name() + "! Seconds later *pause* it E%^BOLD%^%^BLACK%^X%^BOLD%^%^RED%^P%^BOLD%^%^BLACK%^L%^BOLD%^%^RED%^O%^BOLD%^%^BLACK%^D%^BOLD%^%^RED%^E%^BOLD%^%^BLACK%^S%^BOLD%^%^RED%^!", ({ victim, stabber }));
        break;
    }

    if (sizeof(weapon) && objectp(weapon[0]) && weapon[0]->query_property("magic")) {
        magic = 1;
        stabber->set_property("magic", 1);
    }

    if (sizeof(weapon)) {
        damtype = weapon[0]->query_damage_type();
    }else {
        damtype = "piercing";
    }


    damage = get_stab_damage(stabber, victim, weapon);

    stabber->cause_typed_damage(victim, "torso", damage, damtype);

    if (sizeof(weapon) && objectp(weapon[0])) {
        stabber->cause_typed_damage(victim, "torso", stabber->get_damage(weapon[0]), damtype);
    }

    if (magic) {
        stabber->set_property("magic", -1);
        magic = 0;
    }

    stabber->clean_up_attackers();

    if (objectp(victim)) {
        victim->continue_attack();
    }

    return 0;
}


int roll_stab_dcs(object stabber, object vic)
{
    object* weapon, * head, * armor;
    int percent, damage, level, thac0, AC, vic_size, magic;
    int i, j;
    int dex, ret;
    weapon = ({});

    if ((!objectp(stabber)) || (!objectp(vic))) {
        return 0;
    }

    if ((stabber->query_skill("stealth") + roll_dice(1, 20)) >
        (vic->query_skill("perception") + roll_dice(1, 20))) {
        vic->add_attacker(stabber);
    } else {
        stabber->kill_ob(vic, 1);
    }

    i = 10;

    if (vic->query_in_vehicle()) {
        i += 2;
    }

    if (vic->query_watched()) {
        i += vic->query_level() / 10;
    }

    vic->add_attacker(stabber);
    stabber->add_attacker(vic);

    if ((stabber->query_skill("stealth") + roll_dice(1, 20)) <
        (vic->query_skill("perception") + i) || !random(20)) {
        tell_object(stabber, "%^BOLD%^" + vic->QCN + " %^BOLD%^was obviously watching and catches you!");
        tell_object(vic, "%^BOLD%^You catch " + stabber->QCN + " %^BOLD%^trying to stab you.");
        tell_room(environment(stabber), "%^BOLD%^" + vic->QCN + " catches " + stabber->QCN + " %^BOLD%^trying to stab " + vic->QO + "!", ({ stabber, vic }));
        return 0;
    }

    return 1;
}
