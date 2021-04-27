// Static field - wall of fire variant. Nienne, 07/07.
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i, hpcount;
string tempstr;
object caster, place, endplace, outside, wall, wall2;

string *dir_listing(string tempfil);

void create() {
    ::create();
    set_spell_name("static field");
    set_spell_level(4);
    set_spell_type("wizard");
    set_spell_sphere("invocation_evocation");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components( ([
                     "amber rod":1
                     ]) );
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->query_cap_name()+" motions before "
+caster->query_possessive()+" in an arc with a pale rod of %^RED%^amber"
"%^ORANGE%^, which suddenly disappears in a %^YELLOW%^bright "
"flash%^RESET%^%^ORANGE%^!%^RESET%^";
}

void spell_effect(int prof) {
    string *outs, *ins, *limbs, arg;
    object *exits, *inexits, *burned;
    int i, j;
    ::spell_effect();
    caster=CASTER;
    hpcount=caster->query_hp();
    place=PLACE;
    if (ARG)
        arg=lower_case(ARG);
    if (member_array(arg,place->query_exits()) < 0) {
        tell_object(caster,"%^ORANGE%^The air around you seems to come to "
"life, and arcs of %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c"
"%^YELLOW%^ity %^RESET%^%^ORANGE%^crackle around you!%^RESET%^");
        tell_room(place,"%^ORANGE%^The air around you seems to come to "
"life, and arcs of %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c"
"%^YELLOW%^ity %^RESET%^%^ORANGE%^crackle around "
+caster->query_cap_name()+"!%^RESET%^", caster);
        wall=new("/d/magic/obj/staticfield.c");
        wall->set_property("spell",TO);
        wall->set_property("spelled", ({TO}) );
        wall->move(place);
        wall->surround(caster);
        return;
    }
    wall=new("/d/magic/obj/staticfield.c");
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    wall->block(caster,arg);
    if (objectp(wall))
        wall->move(place);
    else
        return;
    tell_room(place,"%^ORANGE%^The air around you seems to come to "
"life, and arcs of %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c"
"%^YELLOW%^ity %^RESET%^%^ORANGE%^crackle before the "+ arg+".%^RESET%^");
    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();
    for (i=0;i<sizeof(ins);i++) {
        if ( base_name(place) == (string)outside->query_exit(ins[i]) ||
          base_name(place)+".c" == (string)outside->query_exit(ins[i]) ||
          base_name(place) == (string)outside->query_exit(ins[i])+".c") {
            wall2=new("/d/magic/obj/staticfield.c");
            wall2->set_property("spell",TO);
            wall2->block(caster,ins[i]);
            wall2->move(outside);
            tell_room(outside,"%^ORANGE%^A crackling field of %^YELLOW%^"
"el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c%^YELLOW%^ity %^RESET%^%^ORANGE%^"
"appears in the air before the "+ arg+".%^RESET%^");
            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++) {
                if ( living(burned[j]) ) {
                    if ( burned[j]->query_property("strength") &&
                         strsrch(burned[j]->query_property("strength"),
                                 "electricity") != -1 ) {
                        tell_room(outside,"%^YELLOW%^"+
                                  burned[j]->query_cap_name()+" seems "+
                                  "unaffected by the charged "
                                  "field.%^RESET%^",
                                  burned[j]);
                        tell_object(burned[j],"%^YELLOW%^The "
                                    "charged field doesn't bother you at "
                                    "all.%^RESET%^");
                    } else {
                        tell_room(outside,"%^YELLOW%^"+
                                  burned[j]->query_cap_name()+" recoils "+
                                  "from the crackling air!%^RESET%^",
                                  burned[j]);
                        tell_object(burned[j],"%^YELLOW%^The charged air "+
                                    "crackles across your skin!%^RESET%^");
                        limbs = burned[j]->query_limbs();
                        damage_targ(burned[j],
                                    limbs[random(sizeof(limbs))],
                                    (2+random(7)) );
                    }
                }
            }
            break;
        }
    }
    call_out("concentration",4);
    return;
}

void concentration() {
    int flag = 0;
    if ( caster->query_paralyzed() ||
         !objectp(wall) ||
         !objectp(wall2))
        flag = 1;
    if ((int)caster->query_hp() != hpcount) {
        if ((int)caster->query_hp() < hpcount - 30 ) {
            tell_room(environment(caster),"%^YELLOW%^"+
                     caster->query_cap_name()+" looks as though "+
                     caster->query_subjective()+" just lost "+
                     caster->query_possessive()+" concentration!%^RESET%^",
                     caster);
            tell_object(caster,"%^YELLOW%^You lose your concentration on "
                       "maintaining the static field you "
                       "invoked!%^RESET%^");
            flag = 1;
        } else
            hpcount = caster->query_hp();
    }
    if (flag)
        call_out("dest_effect",clevel*3);
    else
        call_out("concentration",4);
    return;
}

void dest_effect() {
    ::dest_effect();
    if (objectp(wall))
        wall->remove_wall();
    if (objectp(wall2))
        wall2->remove_wall();
    remove();
    return;
}

int help() {
    write(
@EndText
Spell  : Static field
Level  : 4th Level
Sphere : Invocation/Evocation
Syntax : cast static field [on <exit>]

By means of this spell, the caster invokes a charged field 
of static either protectively around himself, or imposed 
before an exit to harm any that pass through. To cast the 
field around him/herself, the mage simply types:
cast static field
Otherwise, the mage might type:
cast static field on north
Be warned however, the mage who casts this spell must
keep concentration on the field to maintain its existence.
The mage may type <remove field> to disperse the field.

Material component required:

One amber rod

EndText
);
    return 1;
}
