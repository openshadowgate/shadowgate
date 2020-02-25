#include <priest.h>
#include <daemons.h>
inherit SPELL;

object skin;

void create()
{
    ::create();
    set_spell_name("deathward");
    set_spell_level(([ "paladin" : 4,"druid" : 5,"inquisitor":4, "cleric":4]));
    set_domains(({"knowledge", "law"}));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS deathward");
    set_domains("repose");
    set_description("Those most blessed of the gods can call upon their favor to ward away the very hand of death itself."
        "  This spell protects against death spells, as well as many spell-like effects.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


int preSpell()
{
    if(caster->query_property("no death"))
    {
        tell_object(caster,"You are already under the influence of a similar effect.");
        return 0;
    }
   return 1;
}


string query_cast_string() { return "%^RED%^"+caster->QCN+" invokes "+caster->QP+" patron's favor!"; }


void spell_effect(int prof)
{
    if (!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }
    tell_object(caster, "%^BOLD%^%^WHITE%^The blessings of your god fill you with co%^YELLOW%^n%^WHITE%^fid%^YELLOW%^e%^WHITE%^nce!");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+"'s eyes light with %^YELLOW%^fe%^WHITE%^rv%^YELLOW%^or %^WHITE%^as "
        +caster->QP+" prayer is answered!",caster);
    caster->set_property("no death",1);
    spell_successful();
    addSpellToCaster();
    call_out("dest_effect",(ROUND_LENGTH*10)*clevel);
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You feel the protection of your god fade from you.%^RESET%^");
        caster->set_property("no death",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
