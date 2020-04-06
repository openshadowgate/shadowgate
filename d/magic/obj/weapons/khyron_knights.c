//khyron weapon for knights, scimitar
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLACK%^Stormreaver's Scimitar%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^blackened scimitar bathed in %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng%^RESET%^");
    set_id(({ "godweapon", "divine weapon", "scimitar", "lightning scimitar", "stormreavers scimitar", "weapon" }));
    set_long("%^BOLD%^%^BLACK%^This scimitar has been fashioned from blackened adamantium.  The weapon, approximately three feet long, curves inward before coming to a %^RESET%^%^RED%^wicked point%^BOLD%^%^BLACK%^.  The blade itself is %^BOLD%^%^WHITE%^razor sharp%^BOLD%^%^BLACK%^, and is wreathed in living %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctr%^WHITE%^i%^YELLOW%^c%^WHITE%^i%^YELLOW%^ty %^BOLD%^%^BLACK%^that %^BOLD%^%^RED%^pops %^BLACK%^and %^WHITE%^crackles %^BLACK%^its way along the weapon.%^RESET%^");
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
        tell_room(EETO, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from " + ETO->EQN + "'s scimitar shoots forth and scorches " + targ->QCN "!%^RESET%^", ({ ETO, targ }));
        tell_object(ETO, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from your scimitar shoots forth and scorches " + targ->QCN "!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLACK%^A blast of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^ng %^BOLD%^%^BLACK%^from " + ETO->EQN + "'s scimitar shoots forth and scorches you!%^RESET%^");
        targ->do_damage("torso", random(4) + 8);
        return 1;
    }
}
