// Sonic shield - wall of fire variant. Nienne, 07/07.
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
    set_spell_name("sonic shield");
    set_spell_level(4);
    set_spell_type("wizard");
    set_spell_sphere("invocation_evocation");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components( ([
                     "tiny bell":4
                     ]) );
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^A gentle %^YELLOW%^chim%^RESET%^%^ORANGE%^i"
"%^YELLOW%^ng %^CYAN%^rings forth as "+caster->query_cap_name()+
" releases several %^WHITE%^tiny bells %^CYAN%^into the air, which "
"glint brightly before %^RESET%^%^GREEN%^van%^CYAN%^i%^GREEN%^shi%^CYAN%^"
"n%^GREEN%^g%^BOLD%^%^CYAN%^.%^RESET%^";
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
        tell_object(caster,"%^CYAN%^The chiming in the air around you "
"fades to a low static %^RED%^h%^MAGENTA%^u%^RED%^m%^CYAN%^.%^RESET%^");
        tell_room(place,"%^CYAN%^The chiming fades to a low static "
"%^RED%^h%^MAGENTA%^u%^RED%^m%^CYAN%^ in the air around "
+caster->query_cap_name()+".%^RESET%^", caster);
        wall=new("/d/magic/obj/sonicshield.c");
        wall->set_property("spell",TO);
        wall->set_property("spelled", ({TO}) );
        wall->move(place);
        wall->surround(caster);
        return;
    }
    wall=new("/d/magic/obj/sonicshield.c");
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    wall->block(caster,arg);
    if (objectp(wall))
        wall->move(place);
    else
        return;
    tell_room(place,"%^CYAN%^The chiming in the air fades to a low static "
"%^RED%^h%^MAGENTA%^u%^RED%^m%^CYAN%^ before the "+ arg+".%^RESET%^");
    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();
    for (i=0;i<sizeof(ins);i++) {
        if ( base_name(place) == (string)outside->query_exit(ins[i]) ||
          base_name(place)+".c" == (string)outside->query_exit(ins[i]) ||
          base_name(place) == (string)outside->query_exit(ins[i])+".c") {
            wall2=new("/d/magic/obj/sonicshield.c");
            wall2->set_property("spell",TO);
            wall2->block(caster,ins[i]);
            wall2->move(outside);
            tell_room(outside,"%^CYAN%^A low static %^RED%^h%^MAGENTA%^u"
"%^RED%^m%^CYAN%^ becomes apparent in the air before the "
+ arg+".%^RESET%^");
            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++) {
                if ( living(burned[j]) ) {
                    if ( burned[j]->query_property("strength") &&
                         strsrch(burned[j]->query_property("strength"),
                                 "sonic") != -1 ) {
                        tell_room(outside,"%^BOLD%^%^CYAN%^"+
                                  burned[j]->query_cap_name()+" seems "+
                                  "unaffected by the sound.%^RESET%^",
                                  burned[j]);
                        tell_object(burned[j],"%^BOLD%^%^CYAN%^The sound "+
                                    "doesn't bother you at all.%^RESET%^");
                    } else {
                        tell_room(outside,"%^BOLD%^%^CYAN%^"+
                                  burned[j]->query_cap_name()+" recoils "+
                                  "from the sonic vibrations!%^RESET%^",
                                  burned[j]);
                        tell_object(burned[j],"%^BOLD%^%^CYAN%^The sonic "+
                                    "vibrations scream in your "
                                    "ears!%^RESET%^");
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
            tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+
                     caster->query_cap_name()+" looks as though "+
                     caster->query_subjective()+" just lost "+
                     caster->query_possessive()+" concentration!%^RESET%^",
                     caster);
            tell_object(caster,"%^BOLD%^%^CYAN%^You lose your "+
                       "concentration on maintaining the sonic shield "+
                       "you invoked!%^RESET%^");
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
Spell  : Sonic shield
Level  : 4th Level
Sphere : Invocation/Evocation
Syntax : cast sonic shield [on <exit>]

By means of this spell, the caster invokes a vibrating 
sonic barrier either protectively around himself, or imposed 
before an exit to harm any that pass through. To cast the 
shield around him/herself, the mage simply types:
cast sonic shield
Otherwise, the mage might type:
cast sonic shield on north
Be warned however, the mage who casts this spell must
keep concentration on the shield to maintain its existence.
The mage may type <remove shield> to silence the shield.

Material component required:

Four tiny bell

EndText
);
    return 1;
}
