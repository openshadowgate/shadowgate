//      Armor 
//      Thorn@Shadowgate w/ lots of help from Melnmarn
//      1/19/95 
//      Wizard Spells
//      armor.c
//      Modified and updated by Vashkar
#include <spell.h>
#include <daemons.h>
inherit SPELL;

int benchmark,tally,bonus;


void create() 
{
    ::create();
    set_spell_name("spectral hand");
    set_spell_level(([ "mage" : 2 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS spectral hand");
    set_description("A ghostly, invisible to others, glowing hand shaped from your life force materializes and moves as you desire, allowing you to deliver low-level, touch range spells at a distance. The hand is incorporeal and thus can be only abjured.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([ "mage" : ([ "drop of blood" : 1, ]), ]));
    set_helpful_spell(1);
}


void spell_effect(int prof) 
{
    if (caster->query_property("spectral_hand")) 
    {
        tell_object(caster,"The spell is repelled by its own magic.");
        TO->remove();
    }
    spell_successful();

    tell_object(caster,"%^BOLD%^%^CYAN%^Ghostly hand that looks just like yours appears.");

    caster->set_property("spelled", ({TO}) );
    caster->set_property("spectral_hand",1);
    addSpellToCaster();
}



void dest_effect() 
{    
    if(objectp(caster)) 
    {
        caster->remove_property_value("spelled", ({TO}) );
        tell_object(target, "%^CYAN%^The magic shielding around you glows briefly, then fades away.");
        if (caster->query_property("spectral_hand"))
            caster->remove_property("spectral_hand");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() { return "%^CYAN%^"+caster->QCN+" pins his hand and lets a tiny blood drop out."; }

