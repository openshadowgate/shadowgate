// Web

#include <spell.h>
#include <magic.h>

inherit SPELL;

object oldenv, web, mass;
int waittime, clevel;

void dest_effect();
void waiter(int num);

create() {
    ::create();
    set_spell_name("web");
    set_spell_level(([ "mage" : 2, "assassin" : 2 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS web on TARGET");
    set_description("When a victim is unfortunate enough to be victim of a web spell, he/she might as well get a new "
"hobby.  If the web is successful, the victim will be trapped within a massive web for quite some time.  The time it "
"takes for the victim to escape varies with strength.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "spider web" : 1, ]),
    ]));
    set_property("keywords", ({ "offensive", "targeted", }));
    set_save("reflex");
}

string query_cast_string() {
    return caster->QCN+" steps away from "+target->QCN+" and starts a low chant.";
}

spell_effect(int prof) {
    int save, neededroll, power;
    string strength;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }
    if(!caster->ok_to_kill(target)) {
        dest_effect();
        return 0;
    }
    tell_object(caster,"%^YELLOW%^You jab your finger at "+target->QCN+" and strands of sticky web shoot out towards "+target->QO+"!");
    tell_object(target,"%^YELLOW%^"+caster->QCN+" jabs "+caster->QP+" finger at you, shooting out strands of sticky web!");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" jabs "+caster->QP+" finger at "+target->QCN+", shooting out strands of sticky web!", ({caster, target}) );
    waittime=10;
    power=target->query_stats("strength");
    if (power > 17) {
        waittime=to_int(waittime/2);
    }
    if (power <= 13 && power >= 9) {
        waittime=waittime*2;
    }
    if (power < 9) {
        waittime=waittime*4;
    }
    save = roll_dice(1, 20);
    if ( do_save(target,-2) || target->query_property("no web") || prof < random(100)) {
    //if ( do_saving_throw(target,"spell",-2) || target->query_property("no web") || prof < random(100)) {
        tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" manages to dodge your mass of webs!");
        tell_object(target,"%^BOLD%^%^RED%^You manage to dodge the mass of webs!");
        tell_room(environment(caster),"%^BOLD%^%^RED%^"+target->QCN+" manages to dodge the mass of webs!",({caster, target}) );
        dest_effect();
        return;
    } else {
        strength="furiously wrap around";
        spell_successful();
        tell_object(caster,"%^BOLD%^%^RED%^Your mass of webs "+strength+" "+target->QCN+" trapping "+target->QO+" within!");
        tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+"'s mass of webs "+strength+" you, trapping you within!");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+"'s mass of webs "+strength+" "+target->QCN+" trapping "+target->QO+" within!", ({caster,target}) );
    }
    oldenv=environment(target);
    mass=new("/d/magic/obj/webmass.c");
    mass->set_spell(TO);
    mass->move(oldenv);
    web=new("/d/magic/room/in_web.c");
    target->move(web);
    addSpellToCaster();
    call_out("waiter",ROUND_LENGTH,1);
}

void waiter(int num) {
    object *tempinv;
    if(!target || !objectp(web)){
        dest_effect();
        return;
    }
    if (!present(target,web)) 
    {
        if(objectp(mass)) { mass->remove(); }
        web->move("/d/shadowgate/void.c");
        while ( tempinv=(object *)web->all_inventory() ) {
            tempinv[0]->move(oldenv);
            return;
        }
    }
    if ( (num%2) )
        tell_object(target,"You break through some of the web.");
    if (num < waittime)
        call_out("waiter",ROUND_LENGTH,num+1);
    else
        dest_effect();
    return;
}

void helped() {
    if (target)
        tell_object(target,"You hear someone tearing through the the surface of the web.");
    waittime--;
    return 1;
}

void dest_effect() {
    int i;
    object *tempinv;


    if (objectp(mass))
        mass->remove();
    if (objectp(target) && objectp(web))
        if (present(target,web)) {
            tell_object(target,"%^BOLD%^%^RED%^You manage to break through the mass of webs!");
            tell_room(place,"%^BOLD%^%^RED%^"+target->QCN+" manages to break through the mass of webs!",target );
            target->move(oldenv);
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
        }
    if (objectp(target) && objectp(web)) {
        if (!present(target,web)) {
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
            TO->remove();
        }
    } else if(objectp(web)) {
        tempinv=all_inventory(web);
        for (i=0;i++;i<sizeof(tempinv)) {
            if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
        }
        web->remove();
    } 
    ::dest_effect();
    if(objectp(TO)) TO->remove();

    return;
}
