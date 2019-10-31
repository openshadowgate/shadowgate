#include <std.h>
#include <spell.h>
inherit SPELL;

object fob,tob;

void create() {
    ::create();
    set_spell_name("siphon magic");
    set_spell_level(([ "mage" : 5, "cleric" : 5 ]));
    set_spell_sphere("abjuration");
    set_syntax(
"cast CLASS siphon magic on OBJECT2 into OBJECT2");
    set_description("With this spell you can transfer enchantment value between objects of the same type.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BOLD%^%^MAGENTA%^"+caster->QCN+" utters a short %^GREEN%^r%^CYAN%^h%^GREEN%^ym%^CYAN%^e %^MAGENTA%^under "+caster->QP+" breath.";
}

int preSpell()
{
    string sfob, stob;
    if(sscanf(arg,"%s into %s",sfob,stob)!=2)
    {
        tell_object(caster, "You must specify both object you take magic from and object you transfer it to.");
        return 0;
    }
    fob = present(sfob,caster);
    if (!objectp(fob))
    {
        tell_object(caster,"The first object is not present.");
        return 0;
    }
    tob = present(stob,caster);
    if (!objectp(tob))
    {
        tell_object(caster,"The Ssecond object is not present.");
        return 0;
    }
    if(!(fob->is_weapon()||fob->is_armor()))
    {
        tell_object(caster,"The first object is neither a weapon nor an armor piece.");
        return 0;
    }
    if(!(tob->is_weapon()||tob->is_armor()))
    {
        tell_object(caster,"The second object is neither a weapon nor an armor piece.");
        return 0;
    }
    if(((fob->is_weapon()&&!tob->is_weapon()) ||
        (!fob->is_weapon()&&tob->is_weapon())) &&
       ((fob->is_armor()&&!tob->is_armor()) ||
        (!fob->is_armo()&&tob->is_weapon())))
    {
        tell_object(caster,"Both objects must be of the same type.");
        return 0;
    }
    if(fob->query_property("enchantment")<1)
    {
        tell_object(caster,"The first object must be enchanted.");
        return 0;
    }
    if(tob->query_property("enchantment")>fob->query_property("enchantment"))
    {
        tell_object(caster,"The second object must not have higher enchantment than the first one.");
        return 0;
    }
    if(tob->query_property("enchantment")<0)
    {
        tell_object(caster,"The second object must not be cursed.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int enchantment;

    if (!objectp(fob)||!objectp(tob))
    {
        tell_object(caster,"That object is no longer present.");
        dest_effect();
        return;
    }

    enchantment = fob->query_property("enchantment");

    fob->remove_property("enchantment");
    tob->remove_property("enchantment");
    tob->set_property("enchantment",enchantment);
    tell_object(caster,"%^BOLD%^%^MAGENTA%^As you spell syllables power on "+fob->query_short()+"%^BOLD%^%^MAGENTA%^ transfers to "+tob->query_short()+"%^BOLD%^%^MAGENTA%^.%^RESET%^");
    tell_room(caster,"%^BOLD%^%^MAGENTA%^You see soft glow flowing from "+fob->query_short()+"%^BOLD%^%^MAGENTA%^ into "+tob->query_short()+"%^BOLD%^%^MAGENTA%^.%^RESET%^",({caster}));
    dest_effect();
}
