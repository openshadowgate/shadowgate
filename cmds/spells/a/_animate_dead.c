// Animate Dead - Coded by Vashkar@shadowgate
// Updated to allow control of undead -Ares
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;
int num_mon;

#define UNDEADDIR "/d/magic/mon/create_undead/"

void fail();

void create() {
    ::create();
    set_spell_name("animate dead");
    set_spell_level(([ "mage" : 4, "cleric" : 3, "paladin" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS animate dead [on TARGET]");
    set_description("%^RESET%^With this spell, the caster uses remnants of negative energy released upon recent death to bend souls of the deceased to the will of the caster and puts them into their former vessels. Such souls are incapable of understanding what has been done to them, forced to serve and protect the caster. Many faiths and cultures condemn this spell and alike powers as it serves caster's selfish, often evil, motives and frequent users of the spell are known to be inherently evil.

To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check your undead pool size use %^ORANGE%^<poolsize>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    evil_spell(1);
    set_components(([
      "mage" : ([ "drop of blood" : 1, "bit of bone" : 1, ]),
    ]));
    set_helpful_spell(1);
}

void spell_effect(int prof)
{
    object *targs=({}),*temp=({}),*inven=({}),undead,controller;
    int i,j,lvl,flag;

    if(target && !target->is_room()) {
        if(!target->is_corpse()) {
            fail();
            return;
        }
        targs = ({target});
    }
    else {
        targs = all_inventory(environment(caster));

        for(i=0;i<sizeof(targs);i++) {
            if(!targs[i]->is_corpse()) continue;
                temp += ({ targs[i]});
        }
        targs = temp;

        if(!sizeof(targs)) {
            tell_object(caster,"%^RESET%^%^BOLD%^%^BLACK%^LIFE'S PUTRID FIRE %^WHITE%^MUS%^BLACK%^T %^WHITE%^BE%^BLACK%^ SNUCK OUT FIRST%^RESET%^%^RESET%^");
            TO->remove();
            return;
        }
    }

    if(present("undead_controller",caster)) {
        controller = present("undead_controller",caster);
    }
    else {
        controller = new("/d/magic/obj/undead_controller");
        controller->set_caster(caster);
        controller->move(caster);
    }

    num_mon = (int)caster->query_property("raised");
    if(!intp(num_mon)) num_mon = 0;
    if(num_mon > clevel) {
        tell_object(caster,"%^RESET%^%^BOLD%^%^BLACK%^YOU ARE %^WHITE%^NOT %^WHITE%^WORTHY%^BLACK%^ TO RAISE MORE%^RESET%^%^RESET%^");
        tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" seems to strain doing something.%^RESET%^", caster);
        TO->remove();
        return;
    }

    spell_successful();

    for(i=0;i<sizeof(targs);i++) {
        undead=new(UNDEADDIR+"skeleton");
        lvl = clevel/6;

        if(((num_mon + lvl) > clevel)) {
            undead->remove();
            tell_object(caster,"%^RESET%^%^BOLD%^%^BLACK%^RAISING MORE IS %^WHITE%^BEYOND%^BLACK%^ YOUR PATHETIC %^BLACK%^M%^WHITE%^ISERY%^RESET%^%^RESET%^");
            tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" seems to strain doing something.%^RESET%^", caster);
            TO->remove();
            continue;
        }

        inven = all_inventory(targs[i]);
        inven->move(undead);

        targs[i]->remove();
        num_mon += lvl;

        undead->set_property("raised",clevel);
        undead->set_property("minion",caster);
        undead->move(environment(caster));

        undead->set_guild_level("fighter",clevel);
        undead->set_weap_enchant(clevel/12);
        undead->set_skill("perception",clevel);
        undead->set_level(clevel);
        undead->set_hd(clevel,6);

        undead->set_max_hp(clevel*10);
        undead->set_hp(undead->query_max_hp());
        undead->set_overall_ac(5-clevel);
        undead->control(caster);
        caster->add_follower(undead);

        undead->add_id("summoned monster");
        undead->set_property("spell", TO);
        undead->set_property("spell_creature", TO);
        undead->set_property("minion", caster);
        controller->add_monster(undead);
        caster->set_property("raised", lvl);
    }
    tell_object(caster,"%^BLUE%^You let your arms drop limply after completing the spell.");
    tell_room(place,"%^BOLD%^"+caster->QCN+" lets "+caster->QP+" arms drop limply.",caster);
    dest_effect();
    spell_successful();
    return;
}

void fail() {
    tell_object(caster,"%^RESET%^%^BOLD%^%^BLACK%^YOU FAIL, %^WHITE%^PA%^BLACK%^T%^WHITE%^HETIC %^WHITE%^WEAKLING%^RESET%^%^RESET%^");
    tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" seems disappointed.", caster);
    TO->remove();
    return;
}

void reverse_spell() {
    spell_effect(200);
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
