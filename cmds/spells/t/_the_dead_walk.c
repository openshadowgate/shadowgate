#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

void fail();
int num_mon;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("the dead walk");
    set_spell_level(([ "warlock" : 2 ]));
    set_syntax("cast CLASS the dead walk (on TARGET)");
    set_description("This invocation draws upon the power of the Plane of Shadows, infusing the recently dead with
negative energy to reanimate their bodies as undead. You can raise a total number of hit dice worth of zombies and skeletons up to your casting level. They will follow you and defend you from your enemies. Unlike most common summoning spells, these monsters will not go away unless the caster quits. They are undead, so they can be turned, and so forth, but they cannot be dispelled. Many faiths and cultures condemn this spell and alike powers as it serves caster's selfish, often evil, motives and frequent users of the spell are known to be inherently evil.

To command undead, use <command undead to ACTION>
To dismiss undead, use <dismiss undead>
To command lost undead to follow you, use <command undead to follow>");
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^A %^RESET%^stillness %^CYAN%^falls upon the area as you sway gently, drawing negative energy from your surroundings.%^RESET%^");
    tell_room(place,"%^CYAN%^A %^RESET%^stillness %^CYAN%^falls upon the area as "+caster->QCN+" sways gently.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    object *targs=({}),*temp=({}),*inven=({}),undead,controller;
    int i,j,lvl,flag;

    if (caster->query_property("raised")) {
        if((int)caster->query_property("raised") >= clevel*prof/100) {
            fail();
            return;
        }
    }

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
            fail();
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

    for(i=0;i<sizeof(targs);i++) {
        undead = new("/d/magic/obj/undead"); 
        lvl = targs[i]->make_new_body(undead);

        if(((num_mon + lvl) > clevel)) {
            undead->remove();
            tell_object(caster,"%^CYAN%^You can't gather enough power, and the invocation's energy scatters harmlessly!%^RESET%^");
            tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" seems to struggle briefly.%^RESET%^", caster);
            TO->remove();
            continue;
        }

        spell_successful();
        
        inven = all_inventory(targs[i]);
        for(j=0;j<sizeof(inven);j++) inven[j]->move(undead);

        targs[i]->remove();
        num_mon += lvl;

        undead->set_property("raised",lvl);
        undead->set_property("minion",caster);
        undead->move(environment(caster));
        undead->set_max_hp(undead->query_hp()*5);
        undead->set_hp(undead->query_max_hp());
        undead->serve(caster);
        undead->add_id("summoned monster");
        undead->set_property("spell", TO);
        undead->set_property("spell_creature", TO);
        undead->set_property("minion", caster);
        undead->set_exp((int)undead->query_hd()*50);
        undead->force_me("protect "+caster->query_name()+"");
        controller->add_monster(undead);
        caster->set_property("raised", lvl);
    }
    if(sizeof(targs) > 1) {
      tell_object(caster,"%^BOLD%^%^CYAN%^You release the negative energy into the area in a channeled burst, infusing the bodies with unlife.");
      tell_room(place,"%^BOLD%^%^CYAN%^A dull pulse of energy emanates from "+caster->QCN+", and the lifeless bodies nearby start to move.",caster);
    }
    else {
      tell_object(caster,"%^BOLD%^%^CYAN%^You release the negative energy into the area in a channeled burst, infusing the body with unlife.");
      tell_room(place,"%^BOLD%^%^CYAN%^A dull pulse of energy emanates from "+caster->QCN+", and a lifeless body nearby starts to move.",caster);
    }
    tell_object(caster,"%^RED%^Use 'command undead to <action>' to make your undead minions perform tasks.");
    dest_effect();
}

void fail() {
    tell_object(caster,"%^CYAN%^Your invocation utterly fails!");
    tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" seems disappointed.", caster);
    TO->remove();
    return;
}

void dest_effect() {
    if(objectp(caster)) {
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
