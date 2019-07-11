// please note - all MR spells & items (plat band, power resistance, prot from spells, drow MR) are now all balanced to MR and do not stack.
// this is to counteract innate caster SR so that feats/items/etc are what chooses a player's capacity to bypass. N, 5/15.
#include <std.h>
inherit SPELL;

int lower;

void create() {
    ::create();
    set_spell_name("protection from spells");
    set_spell_level(([ "mage" : 8 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS protection from spells on TARGET");
    set_description("Using this power will allow a mage or sorcerer to temporarily raise the target's "
"resistance to spells of all kinds.  This is only a temporary state, however, and will fade after a "
"short while.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
    set_components(([
      "mage" : ([ "small diamond" : 1, ]),
    ]));
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" holds up a tiny d%^BOLD%^%^WHITE%^ia%^BOLD%^%^CYAN%^m"
"%^BOLD%^%^WHITE%^on%^BOLD%^%^CYAN%^d, light glinting from its facets.";
}

void spell_effect(int prof) {
    if (!objectp(caster)) return;
    if(!objectp(target))
    {
        tell_object(caster,"You don't see that target here!");
        return;
    }
    tell_room(place,"%^BOLD%^%^CYAN%^The diamond held in "
        +caster->QCN+"'s fingertips g%^BOLD%^%^WHITE%^li"
        "%^BOLD%^%^CYAN%^tt%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s "
        "brightly, the sparks spreading across "+target->QCN+
        " in a brilliant wave!",({caster,target}));
    if(target == caster){
        tell_object(caster,"%^BOLD%^%^CYAN%^The diamond held between "
        "your fingertips g%^BOLD%^%^WHITE%^li%^BOLD%^%^CYAN%^tt"
        "%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s brightly, the "
        "sparks spreading across you in a brilliant wave!");
    }
    else{
        tell_object(caster,"%^BOLD%^%^CYAN%^The diamond held between "
        "your fingertips g%^BOLD%^%^WHITE%^li"
        "%^BOLD%^%^CYAN%^tt%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s "
        "brightly, the sparks spreading across "+target->QCN+
        " in a brilliant wave!");
        tell_object(target,"%^BOLD%^%^CYAN%^The diamond held between "
        +caster->QCN+"'s fingertips g%^BOLD%^%^WHITE%^li%^BOLD%^%^CYAN%^tt"
        "%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s brightly, the "
        "sparks spreading across you in a brilliant wave!");
    }
    if(target->query_property("raised resistance")){
        tell_object(caster,"%^BOLD%^The power is repelled forcibly.");
        tell_object(target,"%^BOLD%^The power is repelled forcibly.");
        dest_effect();
        return;
    }
    lower = clevel/3;
    target->set_property("spell damage resistance",lower);
    addSpellToCaster();
    call_out("dest_effect",80 + clevel*8,lower);
}

void dest_effect(){

    if(objectp(target)) 
    {
        target->set_property("spell damage resistance",(-1*lower));
        tell_room(environment(target),"%^RESET%^%^CYAN%^The air suddenly seems to grow dull as "
        "a wave of energy dissipates from the air around "+target->QCN+".%^RESET%^",target);
        tell_object(target,"%^RESET%^%^CYAN%^The air suddenly seems to grow dull as "
        "a wave of energy dissipates from the air around you!%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

