#include <std.h>

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

void init_disease(int stg, int dc)
{
    clevel = dc;
    stage = stg;
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
    }
    return 1;
}

int infect(object victim, int stg, int dc)
{
    object tmp;

    if (is_immune(victim)) {
        return 0;
    }
    tmp = new(file_name(TO));
    tmp->move(victim);
    tmp->init_disease(stg, dc);
    return 1;
}

int is_immune(object victim)
{
    if (victim->is_undead()) {
        return 1;
    }
    if (FEATS_D->usable_feat(victim, "purity of body") || FEATS_D->usable_feat(victim, "divine health")) {
        return 1;
    }
    return 0;
}

void help()
{
    write("%^BOLD%^%^ORANGE%^Name: " + query_name());
    write("%^BOLD%^%^ORANGE%^Infection: " + infection_desc);
    write("%^BOLD%^%^ORANGE%^Incubation: " + incubation_desc);
    write("%^BOLD%^%^ORANGE%^Damage: " + damage_desc);
    write("%^BOLD%^%^ORANGE%^Description: \n" + description);
}
