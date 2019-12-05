inherit DAEMON;

/**
 * @file
 * @brief Levelcheck related functions
 */

/**
 * This function returns colored version of levelcheck between players
 *
 * @param first First player
 * @param second Second player
 * @return empty string on error, green K if PK is allowed, yellow A if adventuring only is allowed
 *
 */
public string levelcheck_string(object first, object second)
{
    switch(levelcheck(first,second))
    {
    case 0: return " %^RESET%^%^BOLD%^%^RED%^F%^RESET%^";
    case 1: return " %^RESET%^%^BOLD%^%^GREEN%^K%^RESET%^";
    case 2: return " %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^";
    default: return " %^RESET%^%^BOLD%^%^RED%^F%^RESET%^";
    }
}

/**
 * This function determines whether players are within levelcheck
 *
 * @param first First player
 * @param second Second player
 *
 * @return 1 if players are within levelcheck, 2 if they are allowed
 *         only to adventure together, 0 if they are not within
 *         levelcheck
 *
 */
public int levelcheck(object first, object second)
{
    int lvl, lvl2;
    int diff;
    int range;
    int low;

    if(!objectp(first)) return 0;
    if(!objectp(second)) return 0;

    if(first == second) return 1;

    lvl = (int)first->query_character_level();
    lvl2 = (int)second->query_character_level();

    if(lvl2 > lvl) { low = lvl; }
    else { low = lvl2; }

    diff = lvl - lvl2;
    diff = absolute_value(diff);

    switch(low)
    {
    case 1..40: range = 11; break;
    case 41..50: range = 6; break;
    default: range = 6;
    }

    if(diff > range)
        return 0;

    if(first->query("no pk")) return 2;
    if(second->query("no pk")) return 2;

    if(first->query_death_flag()) return 2;
    if(second->query_death_flag()) return 2;

    if(first->get_pk_death_flag()) return 2;
    if(second->get_pk_death_flag()) return 2;

    return 1;
}
