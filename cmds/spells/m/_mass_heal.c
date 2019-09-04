// mass heal
// cures party members if not given a target, if no party it just cures the caster.
// if aimed at an attacker, it hits all attackers, healing living targets and hurting
// undead targets.  If cast at a neutral, it hits all things in the room, healing
// living things, and hurting undead.
// Don't know wtf I was thinking when I originally made this, I've simplified the
// code, hopefully getting rid of some of the bugs. -Ares

#include <std.h>
#include <magic.h>
#include <party.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("ares");
    set_spell_name("mass heal");
    set_spell_level(([ "cleric" : 9 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS mass heal on TARGET");
    set_description("This is a stronger version of the priest spell, heal.  When cast without a target or on the caster "
        "or any party member, it will heal the caster and any party members of the caster who are present in the area.  When cast "
        "on a hostile, it will hit all hostiles in the immediate area, healing those that are living, and hurting those that are "
        "undead.  When cast on a neutral creature that is neither in the caster's party or hostile to the caster, it will hit all "
        "creatures in the area, healing those that are living and hurting those that are undead.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}


int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"You must specify a target for this spell.");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^CYAN%^Your voice rings out as you begin to "+
        "chant a powerful prayer, gathering your divine energy into your hands.");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s voice rings out as they"+
        " begin to chant a powerful prayer.  Cupping "+caster->QP+" hands, "+
        ""+caster->QS+" starts to gather divine energy.",caster);
    return "display";
}


void spell_effect(int prof)
{
    int i;
    object *party_members = ({}),*attackers = ({}),*living = ({}),*targets = ({}), *followers = ({});

    party_members = ob_party(caster);
    attackers = caster->query_attackers();
    followers = caster->query_followers();
    living = all_living(place);

    if(!objectp(target)) { target = caster; }

    if(target == caster ||
       member_array(target,party_members) != -1 ||
       member_array(target,followers) != -1)
    {
        targets = filter_array(distinct_array(party_members+(followers-attackers)+({caster})),
                               (:!$1->is_undead():));
    }
    else if(member_array(target,attackers) != -1)
    {
        targets = filter_array(attackers,(:$1->is_undead():));
    }
    else
    {
        living = filter_array(living,"is_non_immortal",FILTERS_D);
        targets = living;
    }

    targets = distinct_array(targets);

    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" opens "+
        ""+caster->QP+" hands, releasing a brilliant wave of"+
        " energy as "+caster->QS+" shouts out the final words "+
        "of the prayer.",caster);

    if(sizeof(targets))
    {
        int healamnt = calculate_healing();
        for(i=0;i<sizeof(targets);i++)
        {
            if(!objectp(targets[i])) { continue; }
            if(!present(targets[i],place)) { continue; }
            if(!!target->is_undead())
            {
                tell_room(place,"%^BOLD%^%^CYAN%^A brillaint wave moves through"+
                    " "+targets[i]->QCN+" carrying with it the essence of "+
                    "life, as "+caster->QCN+" voice rings out.",({ targets[i],caster }));
                tell_object(caster,"%^BOLD%^%^CYAN%^A brilliant "+
                    "wave moves through "+targets[i]->QCN+", carrying with it the essence of life.");
                tell_object(targets[i],"%^BOLD%^%^CYAN%^A brilliant "+
                    "wave moves through you, carrying with it the essence of life.");
                set_helpful_spell(0);
                damage_targ(targets[i],targets[i]->return_target_limb(),healamnt,"positive energy");
            }
            else if(targets[i] == caster)
            {
                tell_object(targets[i],"%^BOLD%^%^CYAN%^A brilliant "+
                    "wave moves through you, carrying with it the essence of life.");
                damage_targ(targets[i],targets[i]->return_target_limb(),-healamnt,"positive energy");
            }
            else
            {
                tell_room(place,"%^BOLD%^%^CYAN%^A brillaint wave moves through"+
                    " "+targets[i]->QCN+" carrying with it the essence of "+
                    "life, as "+caster->QCN+" voice rings out.",({ targets[i],caster }));
                tell_object(caster,"%^BOLD%^%^CYAN%^A brilliant "+
                    "wave moves through "+targets[i]->QCN+", carrying with it the essence of life.");
                tell_object(targets[i],"%^BOLD%^%^CYAN%^A brilliant "+
                    "wave moves through you, carrying with it the essence of life.");
                set_helpful_spell(1);
                damage_targ(targets[i],targets[i]->return_target_limb(),-healamnt,"positive energy");
            }
        }
    }

    spell_successful();
    dest_effect();
    return;
}

int calculate_healing(object targ)
{
    define_base_damage(-3);
    return sdamage;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
