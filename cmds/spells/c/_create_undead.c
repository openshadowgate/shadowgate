#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;
int num_mon;

void fail();

#define UNDEAD ({"ghoul","ghast","mummy","mohrg"})
#define UNDEADDIR "/d/magic/mon/create_undead/"

void create() {
    ::create();
    set_spell_name("create undead");
    set_spell_level(([ "mage" : 6, "cleric" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS create undead [on ghoul|ghast|mummy|mohrg]");
    set_description("Raising dead is pathetic art for the weak. A true necromancer's art is to change what was into something else, more potent and powerful, to serve his fell desires and scheming. This spell uses a fallen corpse to make an undead creature from rotting flesh. Such a creature is more potent than lesser skeletons and zombies, and will serve the necromancer until discorporated. This spell is without a doubt evil, as soul used to fuel new shell is twisted and changed forever.

To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check your undead pool size use %^ORANGE%^<poolsize>%^RESET%^");
    evil_spell(1);
    set_components(([
      "mage" : ([ "drop of blood" : 1, ]),
    ]));
    set_helpful_spell(1);
    set_arg_needed();
}

void spell_effect(int prof) 
{
    object controller, undead, corpse, *inven=({});
    int lvl;

    if(member_array(arg,UNDEAD)==-1)
        arg = UNDEAD[random(sizeof(UNDEAD))];

    if((int)caster->query_property("raised")>clevel)
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^PATHETIC WEAKLING SUCH AS YOURSELF SHALL NOT RAISE MORE%^RESET%^");
        TO->remove();
        return;
    }
    
    inven=all_inventory(place);
    filter_array(inven,(:$1->is_corpse():));
    if(!sizeof(inven))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^%^BLACK%^LIFE'S PUTRID FIRE %^WHITE%^MUS%^BLACK%^T %^WHITE%^BE%^BLACK%^ SNUCK OUT FIRST%^RESET%^%^RESET%^");
        TO->remove();
        return;            
    }

    undead=new(UNDEADDIR+arg);
    if(!(undead))
    {
        tell_object(caster,"Something went wrong.");
        TO->remove();
        return;            
    }
    inven[0]->remove();

    tell_room(place,"%^BOLD%^%^GREEN%^The corpse %^GREEN%^t%^BLACK%^w%^GREEN%^i%^BLACK%^sts%^GREEN%^ and %^BLACK%^c%^GREEN%^h%^BLACK%^an%^GREEN%^g%^BLACK%^e%^GREEN%^s%^GREEN%^ under %^GREEN%^t%^GREEN%^h%^BLACK%^e %^BLACK%^f%^GREEN%^e%^BLACK%^ll %^BLACK%^ma%^GREEN%^g%^BLACK%^i%^GREEN%^c%^BLACK%^,%^GREEN%^ and then finally %^BLACK%^o%^GREEN%^b%^BLACK%^edien%^GREEN%^t%^BLACK%^l%^GREEN%^y%^GREEN%^ stands as a %^BLACK%^"+arg+"%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^%^BLACK%^THE %^WHITE%^"+capitalize(arg)+"%^BLACK%^ RAISES%^RESET%^");    
    
    if(present("undead_controller",caster))
    {
        controller = present("undead_controller",caster);
    }
    else
    {
        controller = new("/d/magic/obj/undead_controller");
        controller->set_caster(caster);
        controller->move(caster);
    }

    undead->set_property("raised",lvl);
    undead->set_property("minion",caster);
    undead->move(environment(caster));
    undead->set_max_hp(undead->query_hp()*2);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(10-clevel);
    undead->add_id("summoned monster");
    undead->set_property("spell", TO);
    undead->set_property("spell_creature", TO);
    undead->set_property("minion", caster);
    undead->control(caster);
    caster->add_follower(undead);
    controller->add_monster(undead);

    lvl = undead->query_level()/2;
    caster->set_property("raised", lvl);

    dest_effect();
    spell_successful();
    return;
}

void dest_effect()
{
    if(objectp(TO)) TO->remove();;
}

string query_cast_string() {
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" steps "+
    "into the shadows, then mixes something in his hands while "+
    "chanting in a deep, dark tone.";
}

