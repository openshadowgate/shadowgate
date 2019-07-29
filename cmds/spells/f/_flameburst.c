// Flameburst Plants a fire inside of the target, and in a few rounds
// it explodes, doing great damage to the target and anything nearby
#include <std.h>
#include <daemons.h>
#include <party.h>

inherit SPELL;

int party_filter(object obj);

object *party_members;
int timer;


void create()
{
    ::create();
    set_author("ares");
    set_spell_name("flameburst");
    set_spell_level(([ "cleric" : 7 ]));
    set_spell_sphere("elemental fire");
    set_spell_domain("fire");
    set_syntax("cast CLASS flameburst on TARGET");
    set_description("This spell will send a small ball of fire towards the target's chest.  If the spell is successful, "
        "the ball will bury itself inside of the target's flesh and begin to grow.  Over the next several moments, the fire will "
        "consume the target's lungs and heart, and render them unable to move.  If the spell is not dispelled before it has time "
        "to complete, the target's chest will explode dealing great damage to him and anything near him.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}


int preSpell()
{
    if(!target)
    {
        tell_object(caster,"You need a target for this spell.");
        return 0;
    }
    if(target->query_property("flameburst"))
    {
        tell_object(caster,"That target is already consumed by the spell, "
            "another one will not work right now!");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^RED%^%^You begin to chant under your breath, "+
        "the air around you getting warmer by the moment.");
    tell_room(place,"%^RED%^The air around "+caster->QCN+" begins to get"+
        " very warm as "+caster->QS+" chants under "+caster->QP+" breath.",caster);
    return "display";
}


void spell_effect(int prof)
{ 
    string party;
    if(!objectp(caster)) { dest_effect(); return; }    
    party_members = ob_party(caster);

    spell_successful();
    tell_object(caster,"%^RED%^You send forth a tiny ball of fire straight at "+target->QCN+"!");
    tell_object(target,"%^RED%^"+caster->QCN+" sends a tiny ball of fire straight towards you!");
    tell_room(place,"%^RED%^"+caster->QCN+" sends a tiny ball of fire straight at "+target->QCN+"!",({caster,target}));
    
    if(!do_save(target,0)) 
    {
        tell_object(caster,"%^RED%^Your fireball strikes "+target->QCN+" right in the chest and "
            "burrows under the skin!");
        tell_object(target,"%^RED%^"+caster->QCN+"'s tiny ball of fire hits you in the chest and "
            "burrows under your skin!");
        tell_room(place,"%^RED%^"+caster->QCN+"'s ball of fire hits "+target->QCN+" in the chest "
            "and burrows under "+target->QP+" skin!",({caster,target}));
        target->set_property("spelled", ({TO}));
        target->set_property("flameburst",1);
        damage_targ(target,"torso",sdamage/2,"fire");
        spell_kill(target,caster);
        return;
    }
    else
    {
        tell_object(caster,"%^RED%^Your fireball strikes "+target->QCN+" but "
            ""+target->QS+" is able to shrug away at the last instant!");
        tell_object(target,"%^RED%^"+caster->QCN+"'s fireball hits you, but you are "
            "able to shrug away at the last instant!");
        tell_room(place,"%^RED%^"+caster->QCN+"'s fireball hits "+target->QCN+" but "
            ""+target->QS+" is able to shrug away at the last instant!",({target,caster}));
        damage_targ(target,target->return_target_limb(),sdamage,"fire");
        spell_kill(target,caster);
        dest_effect();
        return;
    }
}


int party_filter(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(member_array(obj,party_members) != -1) { return 0; }
    return 1;
}


void execute_attack()
{
    object *living,room;
    int damage,max_hp,i;

    if(!objectp(TO)) { return; }
    ::execute_attack();
    if(!objectp(target)) { dest_effect(); return; }

    room   = environment(target);
    max_hp = (int)target->query_max_hp();
    damage = (max_hp) - roll_dice(3,10); // should almost kill them if they don't dispel it in such a long time
    if(damage > 700) damage = 700;
    
    if(do_save(target,0))
    {
        tell_object(target,"%^YELLOW%^You gasp in relief as the firey burning in your chest subsides!");
        dest_effect();
        return;
    }

    switch(timer)
    {
    case 0:
        tell_object(target,"%^BOLD%^%^RED%^You feel a terrible burning in your chest as the ball "
            "of fire begins to grow!");
        tell_room(room,"%^BOLD%^%^RED%^"+target->QCN+" grimaces in pain and then a look of worry "
            "flashes across "+target->QP+" face!",target);
        damage_targ(target,"torso",roll_dice(1,clevel),"fire");
        timer++;
        break;
    case 1:
        tell_object(target,"%^RED%^You feel the fire in your chest spreading further, making "
            "it almost impossible to breathe!");
        tell_room(room,"%^RED%^"+target->QCN+"'s chest begins to lurch as "+target->QP+" gasps "
            "in shallow breaths!",target);
        damage_targ(target,"torso",roll_dice(1,clevel),"fire");
        timer++;
        break;
    case 2:
        tell_object(target,"%^ORANGE%^The pain is almost unbearable now, and you are no longer "
            "able to breathe.  You can feel your lungs beginning to blister!");
        tell_room(room,"%^ORANGE%^"+target->QCN+" staggers, "+target->QP+" breath caught as "
            ""+target->QS+" is no longer able to breathe!",target);
        damage_targ(target,"torso",roll_dice(1,clevel),"fire");
        timer++;
        break;
    case 3:
        tell_object(target,"%^RED%^You clutch your chest, unable to stand the terrible burning "
            "pain any longer.  The world around you begins to fade to black!");
        tell_room(room,"%^RED%^"+target->QCN+" clutches "+target->QP+" chest and staggers, "
            ""+target->QP+" eyes closing and it looks as if "+target->QS+" is about to "
            "pass out!");
        damage_targ(target,"torso",roll_dice(1,clevel),"fire");
        timer++;
        break;
    case 4:
        tell_object(target,"%^BOLD%^%^RED%^You are barely aware of yourself hitting the floor as your "
            "heart is immolated by the burning flames!");
        tell_room(room,"%^BOLD%^%^RED%^"+target->QCN+" hits the ground with a thud, loosing consciousness!",target);
        timer++;
        damage_targ(target,"torso",roll_dice(1,clevel),"fire");
        target->set_paralyzed(40,"You are unable to move as your life slips away!");
        break;
    case 5:
        tell_object(target,"%^YELLOW%^The fire growing inside of you can no longer be contained.  "
            "You scream in agony as it explodes from inside your chest!");
        tell_room(environment(target),"%^YELLOW%^"+target->QCN+"'s agonized scream is clipped short when "
            ""+target->QP+" chest explodes is a devestating blast of fire!",target);
        living = all_living(environment(target));
        living = filter_array(living,"is_non_immortal",FILTERS_D);
        living = filter_array(living,"party_filter",TO);
        if(FEATS_D->usable_feat(caster,"perfect caster"))
        {
            living = filter_array(living,"perfect_filter",TO);
        }

        if(sizeof(living))
        {
            for(i=0;i<sizeof(living);i++)
            {
                if(!objectp(living[i])) { continue; }
                if(living[i] == target)
                {
                    damage_targ(living[i],"torso",damage,"fire");
                    continue;
                }
                if(!do_save(living[i],0)) 
                {
                    tell_object(living[i],"%^BOLD%^%^RED%^You are hit full force by the firey blast when "
                        ""+target->QCN+"'s chest explodes!");
                    damage_targ(living[i],living[i]->return_target_limb(),damage/2,"fire");
                    damage_targ(living[i],living[i]->return_target_limb(),damage/2,"bludgeoning");
                    continue;
                }
                else
                {
                    tell_object(living[i],"%^BOLD%^%^RED%^You are able to roll to the side at the last "
                        "instant as "+target->QCN+"'s chest explodes, taking only minor damage!");
                    damage_targ(living[i],living[i]->return_target_limb(),(damage/4),"fire");
                    damage_targ(living[i],living[i]->return_target_limb(),damage/4,"bludgeoning");
                    continue;
                }
            }
        }
        dest_effect();
        break;
    default:
        timer++;
        break;
    }
    environment(target)->addObjectToCombatCycle(TO,1);
    return;
}


void dest_effect()
{
    if(objectp(target)) { target->remove_property("flameburst"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
