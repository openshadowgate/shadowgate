#include <std.h>
inherit WEAPONLESS;

object caster;
string castname, fname;

void create(){
    ::create();
    set_name("chest");
    set_id(({"chest","secret chest","floating wooden chest"}));
    set_short("%^RESET%^%^CYAN%^Floating %^ORANGE%^wooden %^BOLD%^c%^RESET%^%^ORANGE%^h%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^t%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is an %^BOLD%^%^ORANGE%^iro%^BLACK%^n%^ORANGE%^-bound%^RESET%^%^ORANGE%^ wooden chest that appears to float. It is quite large and could probably fit a lot of things inside.%^RESET%^");
    set("not living",1);
    set_attacks_num(1);    
    set_exp(1);
    set_gender("neuter");
    set_hp(40);
    set_race("chest");
    set_stats("constitution",16);
    set_stats("dexterity",2);
    set_stats("strength",24);
    set_body_type("humanoid");
    remove_limb("left hand");
    remove_limb("right hand");
    remove_limb("left foot");
    remove_limb("right foot");
    remove_limb("left leg");
    remove_limb("right leg");
    add_limb("chest",0,0,0,0);
    set_attack_limbs(({"chest"}));    
}

void setup_chest(object invoker)
{
    caster = invoker;
    castname = caster->query_name();
    fname = "/d/save/summons/"+castname+"/"+query_name();
    restoreMonster(fname);    
}

void die(object obj)
{
    if(objectp(caster))
        caster->remove_property("has_elemental");
    remove();
}

int remove(){
    save_chest();
    all_inventory(TO)->remove();
    ::remove();
}

void heart_beat()
{
   ::heart_beat();
   if(!objectp(caster))
       TO->remove();
   if(!objectp(TO))
       TO->remove();
}

void save_chest()
{
    /* seteuid(getuid()); */
    if(!objectp(TO))
        return;
    if(!objectp(ETO))
        return;
    mkdir("/d/save/summons/"+castname);
    mkdir("/d/save/summons/"+castname+"/"+query_name());
    saveMonster(fname);
}

