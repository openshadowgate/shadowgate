//Dragon Scales coded by Bane//
//Updated to have an enchantment of level / 5 > 4 = 4 - Saide
// had to alter the enchantments to still be wearable with +1/7 levels. Now +1/8 on scale enchants. Nienne, 05/07
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

object scales;
int time, mr;


void create() 
{
    ::create();
    set_spell_name("dragon scales");
    set_spell_level(([ "mage" : 6 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS dragon scales on TARGET");
    set_description("When cast, the spell will enchant the skin of the target to become covered in draconic scales.  The "
        "scales will last for a certain duration depending on the caster's level, and will vanish if the person wearing them quits "
        "out.  The scales provide an innate armor bonus that is dependant upon level, but cannot exceed +4. Some of the innate magic "
        "resistance of the dragon scale will also cover the caster. This will only work on those wearing mage-like armor.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([ "mage" : ([ "dragon scale" : 1, ]), ]));
    set_helpful_spell(1);
}


void spell_effect(int prof) 
{
    int bonus, enc;
    
    if(!objectp(caster) || !objectp(target))
    {
        dest_effect();
        return;
    }

    if (!target->is_ok_armour("mage")) 
    {
        if(!FEATS_D->usable_feat(target,"armored caster"))
        {
            tell_object(caster,"The spell can not offer protection to those wearing armor.");
            TO->dest_effect();
            return;
        }
    }
    
    if(present("xxxscales", target)) 
    {
        tell_object(caster, "The dragon scales already present preclude another set.");
        dest_effect();
        return;
    }
    
    tell_object(caster,"%^BOLD%^YELLOW%^You chant an age old spell while waving your hands over the scale.");
    tell_room(place,"%^BOLD%^YELLOW%^"+caster->QCN+" chants an age old spell while waving "+caster->QP+" hands over a dragon scale.",caster);
    
    time = 500 + (clevel * 50);    
    scales = new("/d/magic/obj/scales");
    enc = clevel / 8;
    mr = enc * 5;
    if(enc > 4)
        enc = 4;
    scales->set_ac(enc);
    scales->set_mr(mr);
    scales->set_owner(target->query_name());
    scales->set_property("spell", TO);
    scales->move(target);
    scales->set_property("spelled", ({TO}) );

    spell_successful();
    addSpellToCaster();
    call_out("test",2);
    call_out("dest_effect",time);
}


void test()
{
    if (!objectp(TO) || !objectp(caster) || !objectp(target))
    {    
        dest_effect();
        return;
    }
    
    if (!target->is_ok_armour("mage")) 
    {
        if(!FEATS_D->usable_feat(target,"armored caster"))
        {
            tell_object(caster,"The spell can not offer protection to those wearing armor.");
            dest_effect();
            return;
        }
    }
    
    if(objectp(scales)) { call_out("test", 2); }
}


void dest_effect() 
{
    if(objectp(scales))
    {
        scales->dest_me();
    }
    remove_call_out("test");
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
    return;
}
