#include <priest.h>

void create() {
    ::create();
    set_spell_name("shadow_walk");
    set_spell_level(7);
    set_spell_type("priest");
    set_spell_sphere("summoning");
    set_diety("shar");
    set_non_living_ok(0);
    set_somatic_comp();
    set_verbal_comp();
    set_arg_needed();
    set_restricted_to_class(({"cleric"}));
}

string check_error(string file, int prof) { 
    return file;
}

string query_cast_string() {
    return ("%^BOLD%^%^BLACK%^"+caster->query_cap_name()+" whispers a "
"soft phrase under "+caster->query_possessive()+" breath.%^RESET%^");
}

void spell_effect(int prof) {
    string a, tempstr, file, placename;
    mapping tmp;
    object endplace;
    tempstr = ARG;

    if (!tempstr) tempstr = "";
    if (!sscanf(tempstr, "%s", a) ) {
        tell_object(caster,"%^BOLD%^%^BLACK%^You save yourself at the "
"last second from being permanently part of the shadows - you should "
"concentrate on a target location before you step forward.%^RESET%^");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->query_cap_name()+
" seems about to take a step forward, but stops.%^RESET%^",caster);
        TO->remove();
        return;
    }

    if ( member_array(a, caster->query_rem_rooms_sort()) < 0 ) {
        tell_object(caster,"%^BOLD%^%^BLACK%^You save yourself at the "
"last second from being permanently part of the shadows - you can't "
"remember anywhere like "+a+".%^RESET%^");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->query_cap_name()+
" seems about to take a step forward, but stops.%^RESET%^",caster);
        TO->remove();
        return;
    }
    tmp = caster->query_rem_rooms();
    file = tmp[a];

    if (!file || !stringp(file)) {
        tell_object(caster,"%^BOLD%^%^BLACK%^You save yourself at the "
"last second from being permanently part of the shadows - you can't "
"remember anywhere like "+a+".%^RESET%^");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->query_cap_name()+
" seems about to take a step forward, but stops.%^RESET%^",caster);
        TO->remove();
        return;
    }
    file = check_error(file, prof);

    if (file) {
        if (!(endplace = find_object_or_load(file)))
            file = 0;
    }

    if (!file) {
        tell_object(caster,"%^BOLD%^%^BLACK%^You sense something "
"blocking your spellcast, and halt mid-step.%^RESET%^");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->query_cap_name()+
" seems about to take a step forward, but stops.%^RESET%^",caster);
        TO->remove();
        return;
    }

    tell_object(CASTER, "%^BOLD%^%^BLACK%^You step into the nearest "
"shadow, entrusting yourself to Shar's embrace.%^RESET%^");
    tell_room(PLACE, "%^BOLD%^%^BLACK%^"+YOU+" steps into the nearest "
"shadow and disappears.%^RESET%^", ({ CASTER}));

    placename = endplace->query_short();
    tell_object(CASTER, "%^BOLD%^%^BLACK%^You step back out of the "
"shadows at "+placename+"%^RESET%^%^BOLD%^%^BLACK%^.%^RESET%^");
    tell_room(endplace, "%^BOLD%^%^BLACK%^"+YOU+" suddenly steps out of "
"a nearby shadow.%^RESET%^", ({ CASTER}));
    CASTER->move_player(endplace);
    CASTER->set_casting(0);
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    TO->remove();
}

int help() {
    write(
@EndText
Spell  : Shadow Walk
Level  : 7th Level
Sphere : Summoning
Deity  : Shar
Syntax : chant shadow walk to <place>

This spell allows the caster to step from the prime material plane, onto the edge of the plane of shadows. By this means, the caster can move through the shadows to any clearly recalled location on the prime material at near instant speed.

EndText
         );
    return 1;
}
