//Updated by ~Circe~ 5/11/08 with rebalancing of domains
//They will no longer drop everything, have a chance to
//unwield/drop weapons, and a chance to cower instead of run.
//changed from Cyric to Bane by Circe 4/14/04
//_fear.c

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("fear");
    set_spell_level(([ "cleric" : 5, "bard" : 3, "mage" : 4, "psion" : 6 ]));
    set_spell_sphere("enchantment_charm");
    set_spell_domain("tyranny");
    set_syntax("cast CLASS fear");
    set_description("Fear sends a wave of horrid thoughts and images out "+
        "toward the foes around the caster, possibly "+
        "terrifying them.  It can make the creature briefly flee in fright, "+
        "or it may make him drop his weapons and cower before "+
        "the caster.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    set_components(([
        "mage" : ([ "white feather" : 1, ]),
    ]));
}

string query_cast_string(){
    return "%^BLUE%^"+caster->QCN+" reaches into your very soul to search out your fears.";
}

void spell_effect(int prof)
{
    object *inven, *newinven, cur;
    int i,j, percent, x, hits,bonus;
    string *ids, MyType;
    object *weapons;

    tell_object(caster,"%^BLUE%^You send a cone of dark images and "+
        "deep-seeded fears forth from your hand.");

    if(!living(caster))
    {
        if(!objectp(target))
        {
            dest_effect();
            return;
        }
        inven = all_living(environment(target));
        inven = filter_array(inven, "is_non_immortal",FILTERS_D);
        if(member_array(caster,inven) != -1) { inven -= ({caster}); }
    }
    else
    {
        inven = caster->query_attackers();
        inven -= ({caster});
        inven = filter_array(inven, "is_non_immortal",FILTERS_D);
    }

    inven = distinct_array(inven);
    inven = target_filter(inven);

    hits = clevel / 5;
    if(hits < 1) hits = 1;
    if(hits > 10) hits = 10;
    newinven = ({});

    if(hits < sizeof(inven))
    {
        while(hits > 0)
        {
            if(!sizeof(inven)) break;
            cur = inven[random(sizeof(inven))];
            inven -= ({cur});
            newinven += ({cur});
            hits--;
        }
        inven = newinven;
    }

    if(!sizeof(inven))
    {
        dest_effect();
        return;
    }

    for (i=0;i<sizeof(inven);i++)
    {
        if (!objectp(inven[i])) continue;
        if (wizardp(inven[i])) continue;

        MyType = (string)TO->query_spell_type();
        switch (MyType)
        {
        case "cleric":  bonus = (int)caster->query_stats("wisdom");         break;
        case "bard":    bonus = (int)caster->query_stats("charisma");       break;
        default:        bonus = (int)caster->query_stats("intelligence");   break;
        }

        bonus = (bonus - 10) / 2;
        if(bonus < 0) bonus = 0;
        bonus = bonus*(-1);

        if(do_save(inven[i],bonus))
        {
            tell_object(inven[i], "%^BLUE%^You fight back some "+
                "horrid images magically placed in your mind.");
            tell_room(place,"%^BLUE%^You see "+inven[i]->QCN+" wince and shudder, "
                "before regaining composure.",inven[i]);
            continue;
        }

        if(race_immunity_check(inven[i], "fear"))
        {
            inven[i]->add_attacker(caster);
            continue;
        }

        if(mind_immunity_damage(inven[i], "default"))
        {
            continue;
        }


        tell_object(inven[i],"%^BLUE%^Images of horror and terror "+
            "flood your mind. You fight them all, but finally they "+
            "grip your mind and you tremble.");

        tell_room(place, "%^BLUE%^Sheer horror contorts "+
            ""+inven[i]->QCN+"'s face. "+inven[i]->QS+" breaks in "+
            "fear and trembles.",inven[i]);

        if(clevel+random(10) > (int)inven[i]->query_highest_level()+random(10))
        {
            tell_object(inven[i],"%^BOLD%^%^BLUE%^Unable to contain "+
                "your terror, you cower before "+caster->QCN+"!%^RESET%^");
            tell_room(environment(inven[i]),"%^BOLD%^%^BLUE%^"+
                ""+inven[i]->QCN+" cowers in terror!%^RESET%^",inven[i]);
            weapons = inven[i]->query_wielded();
            if(sizeof(weapons) && inven[i]->query_property("no disarm"))
            {
                tell_object(inven[i],"%^CYAN%^You lose your grip "+
                    "on your weapons!%^RESET%^");
                tell_room(environment(inven[i]),"%^CYAN%^"+
                    ""+inven[i]->QCN+" drops "+inven[i]->QP+" "+
                    "weapons!%^RESET%^",inven[i]);
            }
            for (x=0;x<sizeof(weapons);x++)
            {
                if(!objectp(weapons[x])) continue;
                ids = weapons[x]->query_id();
                if((int)weapons[x]->query_property("enchantment") < 0) continue;
                inven[i]->force_me("unwield "+ids[0]+"");
                inven[i]->remove_property("disarm time");
                inven[i]->set_property("disarm time", time() + (ROUND_LENGTH * roll_dice(1, 4)));
            }
            inven[i]->set_paralyzed((15+random(20)),"You cannot contain "+
                "your fear to do that!");
            continue;
        }
        else
        {
            tell_object(inven[i],"%^BOLD%^You flee from "+caster->QCN+" "+
                "before controlling yourself!%^RESET%^");
            tell_room(place,"%^BOLD%^"+inven[i]->QCN+" flees in fright!%^RESET%^",inven[i]);
                inven[i]->run_away();
            continue;
        }
    continue;
    }
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
