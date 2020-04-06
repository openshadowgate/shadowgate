//khyron weapon, basically Mjolnir
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLACK%^Stormreaver's Hammer%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^short-handled warhammer bathed in %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng%^RESET%^");
    set_id(({ "godweapon", "divine weapon", "hammer", "lightning hammer", "stormreavers hammer", "weapon" }));
    set_long("%^BOLD%^%^BLACK%^This shorthandled warhammer has been fashioned from blackened adamantium.  The handle, approximately two feet long, has been wrapped in %^RESET%^%^RED%^deep red leather %^BOLD%^%^BLACK%^ending in a looped lanyard.  The hammerhead is reminiscent of a squarish sledgehammer, and is wreathed in living %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctr%^WHITE%^i%^YELLOW%^c%^WHITE%^i%^YELLOW%^ty %^BOLD%^%^BLACK%^that %^BOLD%^%^RED%^pops %^BLACK%^and %^WHITE%^crackles %^BLACK%^its way along the weapon.%^RESET%^");
    set_value(0);
    set_hit((: TO, "hit_func" :));
}

int hit_func(object targ)
{
    targ = ETO->query_current_attacker();
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }
    if (!random(10)) {
        tell_room(EETO, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from " + ETO->EQN + "'s hammer shoots forth and scorches " + targ->QCN "!%^RESET%^", ({ ETO, targ }));
        tell_object(ETO, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from your hammer shoots forth and scorches " + targ->QCN "!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from " + ETO->EQN + "'s hammer shoots forth and scorches you!%^RESET%^");
        targ->do_damage("torso", random(4) + 8);
        return 1;
    }
}
