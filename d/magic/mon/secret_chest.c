#include "summoned_monster.h"
inherit WEAPONLESS;

object caster;
string castname, fname;

void create(){
    ::create();
    set_name("secret chest");
    set_id(({"secret chest","chest"}));
    set_short("%^RESET%^%^CYAN%^Floating %^ORANGE%^wooden %^BOLD%^c%^RESET%^%^ORANGE%^h%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^t%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is an %^BOLD%^%^ORANGE%^iro%^BLACK%^n%^ORANGE%^-bound%^RESET%^%^ORANGE%^ wooden chest that appears to float. It is quite large and could probably fit a lot of things inside.%^RESET%^");
    set_hp(40);
    set_exp(1);
    set_stats("strength",24);
    set_stats("constitution",20);
    set_stats("dexterity",2);
    set_race("chest");
    set_gender("neuter");
}

void setup_chest(object invoker)
{
    caster = invoker;
    castname = caster->query_name();
    fname = "/d/save/summons/"+castname+"/"+query_name();    
}

void die(object obj)
{
    remove();
}

int remove(){
    reset_all_status_effects();
    save_chest();
    all_inventory(TO)->remove();
    if(objectp(caster))
        caster->remove_property("has_elemental");
    ::remove();
}

void heart_beat()
{
   ::heart_beat();
   if(!objectp(caster))
       remove();
   if(!objectp(TO))
       remove();
}

void save_chest()
{
    seteuid(getuid());
    if(!objectp(TO))
        return;
    if(!objectp(ETO))
        return;
    mkdir("/d/save/summons/"+castname);
    mkdir("/d/save/summons/"+castname+"/"+query_name());
    saveMonster(fname);
}

