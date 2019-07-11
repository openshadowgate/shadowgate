#include <spell.h>
inherit SPELL;

int newhp;

void create() {
    ::create();
    set_spell_name("virtue");
    set_spell_level(([ "paladin" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS virtue");
    set_description("This spell bestows a small blessing upon the caster, increasing their resilience.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string() 
{
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" lowers "+caster->QP+" head and speaks a prayer.";
}

void spell_effect(int prof) 
{
    object Vob;
    int bonus, diff;
    if (!objectp(caster) || !objectp(environment(caster))) 
    {
        TO->remove();
        return;
    }
    if(objectp(Vob = caster->query_property("VigorOb"))) Vob->dest_effect();
    tell_object(caster,"%^BOLD%^%^BLUE%^The truth and valor of your cause fills you!");
    tell_room(environment(caster),"%^BOLD%^%^BLUE%^"+caster->QCN+"'s skin takes on a glow of health!",caster);
    
    newhp = clevel + 10;
    
    diff = caster->query_max_hp() - caster->query_hp();
    if(diff > 0)
    {
        if(diff >= newhp)
        {
            caster->add_hp(newhp);
            newhp = 0;
            dest_effect();
            return;
        }
        else
        {
            caster->add_hp(newhp);
            newhp -= diff;
        }        
    }
    
    newhp -= caster->query_extra_hp();
    
    if (newhp < 0) newhp = 0;
    caster->add_extra_hp(newhp);
    //caster->set_property("spelled",({TO}));
    //addSpellToCaster();
    caster->set_property("VigorOb",TO);
}

void dest_effect() 
{
    if(objectp(caster)) 
	{
        if((int)caster->query_extra_hp() > 0)
        {
            tell_object(caster, "%^BOLD%^%^BLUE%^The truth and valor of your cause fades away!%^RESET%^");
            tell_room(environment(caster), "%^BOLD%^%^BLUE%^The healthy glow of "+caster->QCN+
            "%^BOLD%^%^BLUE%^'s skin fades away!%^RESET%^", caster);
        }
        caster->add_extra_hp(-1* newhp);
        if ((int)caster->query_extra_hp() < 0) caster->add_extra_hp(-1 * (int)caster->query_extra_hp());
        caster->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}