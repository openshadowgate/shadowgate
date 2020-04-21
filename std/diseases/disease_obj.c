#include <std.h>
#include <daemons.h>

#pragma strict_types
#pragma strong_types
#pragma save_types

inherit OBJECT;

int clevel;
int stage;

string description;
string incubation_desc;
string damage_desc;
string infection_desc;

// Diseases persist across logins by moving into player's inventory.

void create()
{
    ::create();
    set_name("disease_obj");
}

void set_description(string arg)
{
    description = arg;
}

void set_incubation(string arg)
{
    incubation_desc = arg;
}

void set_damage_desc(string arg)
{
    damage_desc = arg;
}

void set_infection(string arg)
{
    infection_desc = arg;
}

int is_disease()
{
    return 1;
}

void init_disease(int dc)
{
    clevel = dc;
    return;
}

void advance_disease()
{
    return;
}

int cure_disease(int power)
{
    if (power < clevel) {
        return 0;
    }
    if (objectp(TO)) {
        TO->remove();
        return 1;
    }
}

object infect(object victim, int dc)
{
    object tmp;
    object * diseases;

    if (is_immune(victim)) {
        return 0;
    }

    if (member_array(query_name(),
                     filter_array(all_inventory(victim),
                                  (:$1->is_disease():))->query_name()) != -1) {
        return 0;
    }

    tmp = new(file_name(TO));
    tmp->move(victim);
    tmp->init_disease(dc);
    return tmp;
}

int is_immune(object victim)
{
    if (victim->is_undead()) {
        return 1;
    }
    if (FEATS_D->usable_feat(victim, "purity of body") ||
        FEATS_D->usable_feat(victim, "divine health")) {
        return 1;
    }
    return 0;
}

void help()
{
    write("%^GREEN%^%^BOLD%^Name: %^RESET%^" + query_name());
    write("%^GREEN%^%^BOLD%^Infection: %^RESET%^" + infection_desc);
    write("%^GREEN%^%^BOLD%^Incubation: %^RESET%^" + incubation_desc);
    write("%^GREEN%^%^BOLD%^Damage: %^RESET%^" + damage_desc);
    write("%^GREEN%^%^BOLD%^Description: %^RESET%^" + description);
}
