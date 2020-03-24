//heart of metal, 3/24/2020, Odin

#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;
#define MYTYPES ({ "silver", "cold iron" })

object mywpn;
string mypname, pname, origtype, weaponarg, typearg;

void create()
{
    ::create();
    set_spell_name("heart of metal");
    set_spell_level(([ "mage" : 3, "cleric" : 3, "inquisitor" : 3 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS heart of metal <weapon> with <type>");
    set_description("Using this spell, you temporarily lend the powers of either silver or cold iron to the target weapon.  This will change its base damage type for the duration of the spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_target_required();
    set_helpful_spell(1);
}

int preSpell()
{
    origtype = mywpn->query_base_damage_type();
    if (!arg) {
        tell_object(caster, "You must specify a target weapon for this power!");
        dest_effect();
        return 0;
    }
    if (!mywpn = present(arg, caster)) {
        tell_object(caster, "You don't have any " + arg + " in your inventory!");
        dest_effect();
        return 0;
    }
    if (!mywpn->is_weapon()) {
        tell_object(caster, "That " + arg + " is not a weapon!");
        return 0;
    }
    if (sscanf(arg, "%s with %s", weaponarg, typearg) != 2) {
        tell_object(CASTER, "You need to specify both your weapon and the type of metal.");
        dest_effect();
        return 0;
    }
    if (member_array(typearg, MYTYPES) == -1) {
        tell_object(caster, "That is not a valid type of metal!");
        dest_effect();
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int mylevel;
    switch (typearg) {
    case "silver":
        mywpn->set_damage_type("silver");
        mywpn->remove_property("added short string");
        mywpn->set_property("added short string", ({ " %^BOLD%^%^WHITE%^{{s%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^lv%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE^&ry%^BOLD%^%^WHITE%^}}%^RESET%^" }));
        mywpn->set_property("added short", mywpn->query_property("added short string"));
        if (interactive(caster)) {
            tell_object(caster, "%^BOLD%^%^WHITE%^You gather the very essence of silver about you infuse your " + arg + " with its mystical powers.%^RESET%^");
        }
        tell_room(place, "%^BOLD%^%^WHITE%^As " + caster->QCN + " concentrates on " + caster->QP + " "
                  "" + arg + ", the weapon itself turns to pure silver!.%^RESET%^", caster);
        caster->remove_paralyzed();
        spell_successful();
        mylevel = clevel;
        call_out("dest_effect", (((mylevel / 10) + 1) * ROUND_LENGTH));
        break;

    case "cold iron":
        origtype = mywpn->query_base_damage_type();
        mywpn->set_damage_type("cold iron");
        mywpn->remove_property("added short string");
        mywpn->set_property("added short string", ({ " %^RESET%^%^RED%^{{cold iron}}%^RESET%^" }));
        mywpn->set_property("added short", mywpn->query_property("added short string"));
        if (interactive(caster)) {
            tell_object(caster, "%^RESET%^%^RED%^You gather the very essence of cold iron about you infuse your " + arg + " with its mystical powers.%^RESET%^");
        }
        tell_room(place, "%^RESET%^%^RED%^As " + caster->QCN + " concentrates on " + caster->QP + " "
                  "" + arg + ", the weapon itself turns to pure cold iron!.%^RESET%^", caster);
        caster->remove_paralyzed();
        spell_successful();
        mylevel = clevel;
        call_out("dest_effect", (((mylevel / 10) + 1) * ROUND_LENGTH));
        break;
    }
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^RESET%^%^CYAN%^Your weapon reverts to its normal material.%^RESET%^");
    }
    if (objectp(mywpn)) {
        mywpn->remove_property_value("added short", (string)mywpn->query_property("added short string"));
        mywpn->set_damage_type(origtype);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
