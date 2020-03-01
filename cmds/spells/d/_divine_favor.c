#include <priest.h>
#include <daemons.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("divine favor");
    set_spell_level(([ "paladin" : 3, "inquisitor" : 1, "cleric" : 1]));
    set_domains("protection");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS divine favor");
    set_description("Calling upon the strength of their patron, a holy knight can gain a bonus to their attack and damage rolls. This spell does not stack with fighter feats for bonus attack and damage rolls.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_property("blessed")){
     tell_object(caster,"%^ORANGE%^Your caster has already received guidance.");
        return 0;
    }
    if(caster->query_property("blighted")){
     tell_object(caster,"%^ORANGE%^Your caster has already received guidance.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->QCN + " clenches " + caster->QP + " fists and raises " + caster->QP + " eyes to the heavens.";
}

void spell_effect(int prof)
{
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^Heat floods through your body as the power of your god infuses you!");
        tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s body seems to take on a faint radiance!", caster);
    }
    bonus = clevel / 24 + 1;
    caster->add_damage_bonus(bonus);
    caster->add_attack_bonus(bonus);
    spell_successful();
    addSpellToCaster();
    call_out("dest_effect", ((ROUND_LENGTH * 5 + roll_dice(1, 20)) * clevel));
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^The blazing inspiration of your deity fades from you.%^RESET%^");
        caster->add_damage_bonus(-bonus);
        caster->add_attack_bonus(-bonus);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
