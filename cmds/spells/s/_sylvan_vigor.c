#include <spell.h>
inherit SPELL;

int newhp;

void create() {
    ::create();
    set_spell_name("sylvan vigor");
    set_spell_level(([ "druid" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS sylvan vigor");
    set_description("This spell bestows a small blessing upon the caster, increasing her health.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^RESET%^%^GREEN%^"+caster->QCN+" holds forth a sprig of mistletoe and whispers an incantation.";
}

void spell_effect(int prof) {
    object Vob;
    int bonus;
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    if(objectp(Vob = caster->query_property("VigorOb"))) Vob->dest_effect();
    tell_object(caster,"%^BOLD%^%^GREEN%^The vigor of nature strengthens you!%^RESET%^");
    tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+"'s skin takes on a glow of health!%^RESET%^",caster);
    newhp = (clevel+10) - (int)caster->query_extra_hp();
    if (newhp < 0) newhp = 0;
    caster->add_extra_hp(newhp);
    caster->set_property("spelled",({TO}));
    caster->set_property("VigorOb",TO);
    addSpellToCaster();
}

void dest_effect() {
    if(objectp(caster)) 
    {
        caster->add_extra_hp(-1* newhp);
        if ((int)caster->query_extra_hp() < 0) caster->add_extra_hp(-1 * (int)caster->query_extra_hp());
        caster->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}