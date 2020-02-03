// Sleep
// skip newbies from room effect added by Styx 10/17/02

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

int x,time;
int max_hd, counter;
object this_target,*party,*prospective,*targets;
void dest_effect();
int check();



create()
{
    ::create();
    set_spell_name("sleep uriel");
    set_spell_level(([ "mage" : 1, "bard" : 1, "psion" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast <classname> sleep on <target>");
    set_description("This spell will force your target or everyone in the room, excluding your party, to fall asleep. Attacks on the sleepers will awaken them; normal noise won't, however. Successful save will negate the effect. Immunity to mental attacks will cause damage instead. This is an agressive spell and victims will respond violently.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
    set_components(([
        "bard" : ([ "lullaby" : 1, ]),
    ]));
}



spell_effect(int prof)
{
    int success, rounds;
    string myrace;

    success = 0;

    rounds =  (prof/100) * (roll_dice(1,6) + (clevel/10));
    if (rounds < 1) rounds = 1;
    if (rounds > 15) rounds = 15;
    time = rounds * ROUND_LENGTH;

    //d20 SRD set Sleep as having max 4 HD. That's pretty small for SG so
    //setting it to 8 to be useful at lower levels. However, this is a 
    //L1 spell and it really shouldn't have impact on PK at upper levels. 
    //Solution I am setting here is 1/2 Clevel -- Uriel Feb 2020 
    max_hd = clevel/2;
    if (max_hd < 8) max_hd = 8;


    //validate target specified by caster
    if(!objectp(target) ||
       !caster->ok_to_kill(target) ||
       !living(target) )
    {
       tell_object(caster, target->QCN+"%^BOLD%^%^RED%^ is not a valid target.%^RESET%^");
        dest_effect();
        return;
    }
    //validate additional targets in the room
    prospective = target_filter(all_living(prospective));

    counter = 0;
    targets = ({target});



    for (x=0;x < sizeof(prospective);x++)
    {
        if (counter >= max_hd) break;
        if(!caster->ok_to_kill(prospective[x])) {
             tell_object(caster, prospective[x]->QCN+"is not a valid target.");
             continue;
        }
        this_target = prospective[x];
        counter += this_target->query_level();

        if(do_save(this_target,0)   ||
           race_immunity_check(this_target, "sleep") ||
           mind_immunity_check(this_target, "default"))
        {
           tell_room(environment(this_target),
               "%^YELLOW%^Outraged at "+caster->QCN+" for "+caster->QP+" mind control, "+
               target->QCN+" attacks "+caster->QO+"!", ({target, caster}) );
           tell_object(this_target,
               "%^YELLOW%^Outraged at "+caster->QCN+" for "+caster->QP+
               " mind control, you attack "+caster->QO+"!");
           tell_object(caster,"%^YELLOW%^"+target->QCN+" attacks you,"+
               " outraged at you for your attempted mind control!" );
           spell_kill(this_target,caster);
           continue;
        }

        tell_room(environment(this_target),
           "%^CYAN%^%^BOLD%^"+this_target->QCN+
           " wavers for a bit, then falls to the ground in a deep slumber.", this_target);
        tell_object(this_target,"%^BOLD%^%^CYAN%^"+caster->QCN+" tries to control "+
           "your mind!\nYou try to fight "+caster->QO+" off, but "+caster->QP+" "
           "will is too strong for you!\nYou suddenly become drowsy and fall asleep.");
        tell_object(caster,"%^GREEN%^You break into "+this_target->QCN+"'s mind and "
           "overcome "+target->QP+" willpower!");
        this_target->set_asleep(time, "You are asleep!");
        this_target->set_property("spelled", ({TO}) );
        targets += ({this_target});
        spell_successful();
        success = 1; // this indicates whether the spell works on anything
    }
    if(!success)
    {
        tell_object(caster, "%^CYAN%^%^BOLD%^Your sleep attempt fails to affect anything.%^RESET%^");
        dest_effect();
        return;
    }
    call_out("dest_effect",time);
    return;
}



void dest_effect()
{
    object *spells_on, *newtargs;
    newtargs = ({});
    for (x=0;x<sizeof(targets);x++)
    {
        if (targets[x])
        {
            this_target = targets[x];
            if (spells_on=this_target->query_property("spelled"))
            {
                this_target->remove_property_value("spelled", ({TO}) );
                spell_kill(this_target,caster);
            }
            if (present(caster, environment(this_target))) {
               tell_room(environment(this_target),
                   "%^YELLOW%^Outraged at "+caster->QCN+" for "+caster->QP+
                   " mind control, "+this_target->QCN+" attacks "+caster->QO+"!",
                   ({this_target, caster}) );
               tell_object(this_target,"%^YELLOW%^Outraged at "+caster->QCN+
                   " for "+caster->QP+" mind control, you attack "+caster->QO+"!");
               tell_object(caster,"%^YELLOW%^"+
                   this_target->QCN+" attacks you, outraged at you for your"+
                   " mind control!" );
               spell_kill(this_target, caster);

            }

        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


string query_cast_string() { return caster->QCN+" throws some rose petals in the air!"; }

