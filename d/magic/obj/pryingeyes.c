//pryingeyes.c - for Prying Eyes spell by >> N <<
//Silverwatcher, shadowlistener, and innereye are
//essentially the same file.  If you make a change to
//one, please check to see if the others need it as well.

#include <std.h>
inherit MONSTER;

object caster, follower;
void self_destruct();
void set_scry_power(int x);
void query_scry_power();
void query_mycaster();

int power;

void create(){
    ::create();
    set_name("prying eye");
    set_id(({"eye", "prying eye"}));
    set_long("%^BOLD%^%^WHITE%^It is small and perfectly round %^BOLD%^floati%^BLUE%^ng e%^CYAN%^ye%^RESET%^.");
    set_short("%^BOLD%^floati%^BLUE%^ng e%^CYAN%^ye%^RESET%^");

    set_hd(1,2);
    set_hp(10);
    set_max_hp(10);
    set_new_exp(1, "very low");
    set_race("eye");
    set_body_type("eye");

    add_limb("body","",0,0,0);
}

int move(mixed dest){
    ::move(dest);
}

set_caster(object cas){
    caster = cas;
}

void query_mycaster(){
    return caster;
}

set_target(object ob){
    follower = ob;
}

void die(object ob){
}

void heart_beat(){
    if(!objectp(caster))
        self_destruct();
    if(!objectp(follower))
        self_destruct();
    if(ETO != environment(follower))
        move(environment(follower));
    if(ETO->query_property("no scry")) self_destruct();
    if(present("blockerx111", ETO)) self_destruct();
}

dest_me(){
    remove();
}

catch_tell(string str){
    if(!objectp(caster)){
        dest_me();
        return;
    }
    tell_object(caster,"%^BOLD%^%^WHITE%^You see from afar:%^RESET%^   "+str);
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}
object query_caster() { return caster; }

void set_invis() {
    if (TO->query_invis())
        return;
    else ::set_invis();
    return;
}

void set_scry_power(int x){
    power = x;
}

void query_scry_power(){
    return power;
}

void self_destruct() {
    int i;
    object casterobj,*spells = ({});
    casterobj = find_player(caster);
    if(objectp(casterobj)){
        spells += casterobj->query_property("dispellable spells");
        for(i=0;i<sizeof(spells);i++){
            if(objectp(spells[i])){
                if(!spells[i]->query_target_object()){
                    if((string)spells[i]->query_spell_name() == "prying eyes"){
                        if(!objectp(spells[i])) return notify_fail("Your concentration seems to have been lost.\n");
                        tell_object(casterobj,"Something seems to be blocking your concentration!", TP);
                        spells[i]->removeSpellFromCaster();
                    }
                }
            }
        }
    }
    if(objectp(TO)) dest_me();
    return;
}

int is_priest_scry(){ return 1; }
int is_scry_object(){ return 1; }
