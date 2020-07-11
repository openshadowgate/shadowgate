#include <std.h>
inherit WEAPONLESS;

object owner;

void create(){
        ::create();

        set_name("fey spirit");
        set_id(({"fee","spirit","fey spirit"}));
        set("short","%^CYAN%^Fey Spirit%^RESET%^");
        set("long","This transparent light appears to be some"+
        " kind of a fey spirit.   It pulses light blue and"+
        " radiates positive energy.  ");
        set_overall_ac(0);
        set_attacks_num(1);
        set_alignment(6);
        set_mob_magic_resistance("high");

        }


void ownerz(object ob){
    owner = ob;
}
void heart_beat(){
    if(!owner) return;
  
    if (member_array(ETO->query_terrain(),({"heavy forest",
    "light forest","jungle","scrub lands","grasslands"})) == -1)
    die();
	
    if(owner->query_hp() < owner->query_max_hp() )
    new(/cmds/spells/c/_cure_moderate_wounds.c)->use_spell(TO,owner,15,100,"cleric");
}

void die(object ob){
	tell_room(ETO,"%^CYAN%^The spirit blinks out of existance.");
    TO->move("/d/shadowgate/void");
    return ::die(ob);
}



int isMagic() {return 3;}
