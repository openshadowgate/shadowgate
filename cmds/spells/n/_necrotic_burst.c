#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string element;

void create()
{
    ::create();
    set_spell_name("necrotic burst");
    set_spell_level(([ "mage" : 3,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS necrotic burst on TARGET");
    set_description("This spells represents necromancer's ability to channel negative energies. You will open a Small rip in fabric of the reality near your target and it will release burst of pure negative energy, directed at your enemies near it.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(1);
    set_target_required(1);
    set_helpful_spell(1);
    set_save("reflex");
}


string query_cast_string()
{
    tell_object(caster,"%^RED%^You dip silver pin into blood, and throw it into direction of "+target->QCN+", chanting rapidly.%^RESET%^");
    tell_room(place,"%^RED%^"+caster->QCN+" disp silver pin into vial of blood and throws it into direction of "+target->QCN+", chanting rapidly.%^RESET%^",caster);

    return "display";
}


void spell_effect(int prof)
{
    int i;
    object *party_members = ({}),*attackers = ({}),*living = ({}),*targets = ({}), *followers = ({});

    set_helpful_spell(1);
    party_members = ob_party(caster);
    attackers = caster->query_attackers();
    followers = caster->query_followers();
    living = all_living(place);

    if(!objectp(target)) { target = caster; }

    if(target == caster ||
       member_array(target,party_members) != -1 ||
       member_array(target,followers) != -1)
    {
        targets = filter_array(distinct_array(party_members+(followers-attackers))+({caster}),
                               (:!!$1->query_property("negative energy affinity"):));
    }
    else if(member_array(target,attackers) != -1)
    {
        set_helpful_spell(0);
        targets = filter_array(attackers,(:!$1->query_property("negative energy affinity"):));
    }
    else
    {
        /* living = filter_array(living,"is_non_immortal",FILTERS_D); */
        /* living = target_filter(living); */
        targets = ({target});;
    }

    targets = distinct_array(targets);

    tell_room(place,"%^BOLD%^%^BLUE%^The silver pin makes a black rip in the air, and fell energy tendrils furiously rip out of it!");

    if(sizeof(targets))
    {
        for(i=0;i<sizeof(targets);i++)
        {
            int healamnt = calculate_healing();
            if(!objectp(targets[i])) { continue; }
            if(!present(targets[i],place)) { continue; }
            if(!target->query_property("negative energy affinity"))
            {
                tell_room(place,"%^BLUE%^A fell wave moves through"+
                    " "+targets[i]->QCN+" carrying with it the essence of "+
                    "death.",({ targets[i],caster }));
                tell_object(caster,"%^BLUE%^A fell "+
                    "wave moves through "+targets[i]->QCN+", carrying with it the essence of death.");
                tell_object(targets[i],"%^BLUE%^A fell "+
                    "wave moves through you, carrying with it the essence of death.");
                set_helpful_spell(0);
                damage_targ(targets[i],targets[i]->return_target_limb(),healamnt,"negative energy");
            }
            else if(targets[i] == caster)
            {
                tell_object(targets[i],"%^BLUE%^A fell "+
                    "wave moves through you, carrying with it the essence of death.");
                damage_targ(targets[i],targets[i]->return_target_limb(),-healamnt,"negative energy");
            }
            else
            {
                if(do_save(target,0))
                    healamnt/=2;
                tell_room(place,"%^BLUE%^A fell wave moves through"+
                    " "+targets[i]->QCN+" carrying with it the essence of "+
                    "death.",({ targets[i],caster }));
                tell_object(caster,"%^BLUE%^A fell "+
                    "wave moves through "+targets[i]->QCN+", carrying with it the essence of death.");
                tell_object(targets[i],"%^BLUE%^A fell "+
                    "wave moves through you, carrying with it the essence of death.");
                set_helpful_spell(1);
                damage_targ(targets[i],targets[i]->return_target_limb(),healamnt,"negative energy");
            }
        }
    }

    spell_successful();
    dest_effect();
    return;
}

int calculate_healing(object targ)
{
    return sdamage;
}
