#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int modifier;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("see the unseen");
    set_spell_level(([ "warlock" : 1 ]));
    set_syntax("cast CLASS see the unseen");
    set_description("This invocation allows a warlock to magically augment their vision, "
"allowing vastly improved sight in areas of extreme light or darkness, as well as the "
"ability to perceive hidden items and beings.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->detecting_invis()){
        tell_object(caster, "You are already detecting invisible.");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^GREEN%^You focus your eyes as you voice the syllables of the invocation.%^RESET%^");
    tell_room(place,"%^GREEN%^"+caster->QCN+" voices a few low syllables.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    if(!objectp(caster)) { dest_effect(); return; }
    tell_room(place,"%^GREEN%^An e%^BOLD%^%^GREEN%^e%^BOLD%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^e g%^BOLD%^%^GREEN%^l%^BOLD%^%^CYAN%^o%^RESET%^%^GREEN%^w lights "+caster->QCN+"'s eyes.%^RESET%^",caster);
    tell_object(caster,"%^GREEN%^The world around you snaps into stark clarity, an e%^BOLD%^%^GREEN%^e%^BOLD%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^e g%^BOLD%^%^GREEN%^l%^BOLD%^%^CYAN%^o%^RESET%^%^GREEN%^w outlining each and every detail.%^RESET%^");

    if(member_array((string)caster->query_race(),PLAYER_D->night_races()) != -1) modifier = -10;
    else modifier = 8;
    caster->set_detecting_invis(1);
    caster->add_sight_bonus(modifier);
    caster->set_property("darkvision",1);
    spell_successful();
    addSpellToCaster();
    caster->set_property("spelled", ({TO}) );
    call_out("dest_effect", clevel * ROUND_LENGTH * 5); // darkvision is *20, det invis is no multiplier; we'll go for somewhere in the middle at *5.
}

void dest_effect() {


    if(objectp(caster) && modifier) {
        tell_object(caster,"%^GREEN%^The g%^BOLD%^%^GREEN%^l%^BOLD%^%^CYAN%^o%^RESET%^%^GREEN%^w fades from around you, leaving everything with an oddly dull appearance.%^RESET%^");
        tell_room(environment(caster),"%^GREEN%^The g%^BOLD%^%^GREEN%^l%^BOLD%^%^CYAN%^o%^RESET%^%^GREEN%^w fades from "+caster->QCN+"'s eyes.%^RESET%^",caster);
        caster->set_detecting_invis(0);
        caster->add_sight_bonus(-1*modifier);
        caster->set_property("darkvision",-1);
        caster->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}