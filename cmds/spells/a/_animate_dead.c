#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;
int num_mon, num_this_undead, is_mount;
object controller, undead, * targs = ({}), * temp = ({}), * inven = ({});

#define UNDEADDIR "/d/magic/mon/create_undead/"

void fail();

void create()
{
    ::create();
    set_spell_name("animate dead");
    set_spell_level(([ "mage" : 4, "cleric" : 3, "paladin" : 3, "inquisitor" : 3, "oracle" : 3 ]));
    //mystery is set in line 30
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS animate dead [on TARGET | mount]");
    set_damage_desc("raises no more than six skeletal champions.");
    set_description("%^RESET%^With this spell, the caster uses remnants of the negative energy released upon a recent death in order to bend the deceased to the will of the caster. Many faiths and cultures condemn this spell and similar powers as it serves the caster's selfish, often evil, motives. Frequent users of this spell are known to be inherently evil. Each skeleton will use 1 pool level (of a maximum 6).

You can control up to 4 + clevel/9 humanoids and 5 beasts.
To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check how many undead you have use %^ORANGE%^<poolsize>%^RESET%^");

    if (undead_to_raise() == "skeleton") {
        set_mystery("bones");
        set_verbal_comp();
        set_somatic_comp();
    };
    set_non_living_ok(1);
    evil_spell(1);
    set_components(([
                        "mage" : ([ "drop of blood" : 1, "bit of bone" : 1, ]),
                        ]));
    set_helpful_spell(1);
    set_arg_needed();
}

string undead_to_raise() {
    if (is_mount == 1) {
        return "skelehorse";
    }
    return "skeleton";
}

int amount_to_raise() {
    return 4;
}

int total_max_hd() {
    int max_hd = clevel;
    if (is_mount == 1) {
        return 20; //skelehorses dont use hd
    }
    max_hd = 4 + max_hd / 9;
    return max_hd;
}

int this_max_hd() {
    if (is_mount == 1) {
        return 5; //can only have 5 skelehorses at a time, intended for self and all graveknights max
    }
    return 6;
}

string query_cast_string() {
    return "%^BOLD%^%^BLUE%^" + caster->QCN + " steps into the shadows, then mixes something in his hands while chanting in a deep, dark tone.";
}

void setup_undead_scaling(object undead)
{
    undead->set_guild_level("fighter", clevel);
    undead->set_weap_enchant(clevel / 12);
    undead->set_skill("athletics", clevel);
    undead->set_skill("perception", clevel);
    undead->set_level(clevel);
    undead->set_hd(clevel, 4);
    undead->set_max_hp(clevel * 10);
    undead->set_hp(undead->query_max_hp());
    undead->set_overall_ac(5 - clevel);
}

string err_message_i() {
    return "%^RESET%^%^BOLD%^%^BLACK%^YOU ARE %^WHITE%^NOT %^WHITE%^WORTHY%^BLACK%^ TO RAISE MORE!%^RESET%^";
}

void end_message() {
    tell_object(caster, "%^BLUE%^You let your arms drop limply after completing the spell.");
    tell_room(place, "%^BOLD%^" + caster->QCN + " lets " + caster->QP + " arms drop limply.", caster);
}

int preSpell()
{
    int i;

    if (arg && strsrch(arg, "mount") != -1) {
        is_mount = 1;
        arg = replace_string(arg, " mount", "");
    }
    if (arg) {
        target = present(arg, environment(caster));
    }

    if (target && !target->is_room()) {
        if (!target->is_corpse()) {
            fail();
            return 0;
        }
        targs = ({ target });
    }
    else {
        targs = all_inventory(environment(caster));

        for (i = 0; i < sizeof(targs); i++) {
            if (!targs[i]->is_corpse()) {
                continue;
            }
            temp += ({ targs[i] });
        }
        targs = temp;

        if (!sizeof(targs)) {
            tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^LIFE'S PUTRID FIRE %^WHITE%^MUS%^BLACK%^T %^WHITE%^BE%^BLACK%^ SNUFFED OUT FIRST!%^RESET%^");
            TO->remove();
            return 0;
        }
    }

    if (present("undead_controller", caster)) {
        controller = present("undead_controller", caster);
    }else {
        controller = new("/d/magic/obj/undead_controller");
        controller->set_caster(caster);
        controller->move(caster);
    }
    
    if (!validate_poolsize(undead_to_raise(), total_max_hd(), this_max_hd())) {
        tell_object(caster, err_message_i());
        tell_room(environment(caster), "%^CYAN%^" + caster->QCN + " seems to strain doing something.%^RESET%^", caster);
        TO->remove();
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int i;

    for (i = 0; i < sizeof(targs) && i < amount_to_raise(); i++) {
        undead = new(UNDEADDIR + undead_to_raise());
        if (!validate_poolsize(undead_to_raise(), total_max_hd(), this_max_hd())) {
            undead->remove();
            tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^RAISING MORE IS %^WHITE%^BEYOND%^BLACK%^ YOUR PATHETIC %^BLACK%^M%^WHITE%^ASTERY!%^RESET%^");
            tell_room(environment(caster), "%^CYAN%^" + caster->QCN + " seems to strain doing something.%^RESET%^", caster);
            TO->remove();
            return;
        }

        inven = all_inventory(targs[i]);
        inven->move(undead);

        targs[i]->remove();

        undead->set_property("raised " + undead_to_raise(), 1);
        undead->set_property("minion", caster);
        undead->move(environment(caster));
        if (undead_to_raise() != "skelehorse") {
            undead->set_property("raised", 1);
            caster->set_property("raised", 1);
            setup_undead_scaling(undead);
        }
        undead->control(caster);
        caster->add_follower(undead);
        undead->add_id("summoned monster");
        undead->set_property("spell", TO);
        undead->set_property("spell_creature", TO);
        undead->set_property("minion", caster);
        controller->add_monster(undead);
        caster->set_property("raised " + undead_to_raise(), 1);
    }
    end_message();
    dest_effect();
    spell_successful();
    return;
}

void fail()
{
    tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^YOU FAIL, %^WHITE%^PA%^BLACK%^T%^WHITE%^HETIC %^WHITE%^WEAKLING!%^RESET%^");
    tell_room(environment(caster), "%^CYAN%^" + caster->QCN + " seems disappointed.", caster);
    TO->remove();
    return;
}

void reverse_spell()
{
    spell_effect(200);
}

void dest_effect()
{
    if (objectp(TO)) {
        TO->remove();
    }
}

int validate_poolsize(string undead_type, int max_hd, int this_hd) {
    num_this_undead = (int)caster->query_property("raised " + undead_type);
    num_mon = (int)caster->query_property("raised");
    if (!intp(num_mon)) {
        num_mon = 0;
    }
    if (!intp(num_this_undead)) {
        num_this_undead = 0;
    }
    if (num_mon >= max_hd || num_this_undead >= this_hd) {
        return 0;
    }
    return 1;
}