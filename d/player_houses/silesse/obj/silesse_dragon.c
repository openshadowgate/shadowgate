//Guardian for Silesse and Vicdaerrysn's dungeon. Based on Geonslu after 
//discussions with other Imms. ~Circe~ 1/7/13
//Stats, etc., are the same, though I removed the save functions and adjusted
//messages to make this dragon unique.

#include <std.h>
#include "../sil.h"

inherit WEAPONLESS;

void create(){
    ::create();
    set_race("dragon");
    set_name("chaos dragon");
    set_property("no bow",1);
    set_property("no bows",1);
    set_id(({"dragon","chaos dragon","Dragon","chaos","void","Void","silesse dragon"}));
    set_short("%^BOLD%^%^BLACK%^Void, the %^RED%^c%^RESET%^%^MAGENTA%^h"
       "%^GREEN%^a%^ORANGE%^o%^BOLD%^%^WHITE%^s %^BLACK%^dragon%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This majestic creature is over fifty feet "
       "in length including the long, serpentine neck that lifts an "
       "arrow-shaped head dominated by %^YELLOW%^glowing %^RESET%^"
       "%^ORANGE%^go%^YELLOW%^l%^BLACK%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n "
       "%^YELLOW%^eyes%^BLACK%^ and sharp %^RESET%^%^RED%^da%^BOLD%^g%^RESET%^%^RED%^ge%^BOLD%^r"
       "%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^of %^WHITE%^teeth%^BLACK%^.  Standing only "
       "about twelve feet in height, much of his awe-inspiring presence "
       "arises from his sixty-foot wingspan and the manic %^RESET%^u"
       "%^MAGENTA%^n%^GREEN%^p%^ORANGE%^r%^CYAN%^e%^BOLD%^%^BLUE%^d%^RED%^i"
       "%^RESET%^c%^BOLD%^%^MAGENTA%^t%^GREEN%^a%^CYAN%^b%^BLACK%^i"
       "%^RED%^l%^RESET%^%^CYAN%^i%^ORANGE%^t%^YELLOW%^y %^BLACK%^in "
       "his %^YELLOW%^eyes%^BLACK%^.  Each of his powerful limbs "
       "ends in %^RESET%^%^RED%^claws %^BOLD%^%^BLACK%^that are "
       "balanced by his jagged tail, which lashes about like that "
       "of an angry lion.  His scales shift, undulating in color "
       "to create scintillating patterns that make the dragon difficult "
       "to look at.  The dragon is constantly in motion, opening his "
       "jaws to let out ear-piercing shrieks as each of his steps shakes the earth.%^RESET%^");
    set_class("fighter");
    set_class("mage");
    set_hd(44,8);
    set_hp(4000);
    set_guild_level("fighter",44);
    set_guild_level("mage",44);
    set_mlevel("fighter",44);
    set_mlevel("mage",44);
    set_exp(100000);
    set_new_exp(50,"boss");
    set_overall_ac( "/daemon/player_housing"->get_phouse_lock_dc("common")); // -36 with bonuses
    set_body_type("dragon");
    set_attack_limbs(({"right claw","left claw","mouth"}));
    set_attacks_num(3);
    set_damage(2,25);
    set_hit_funcs((["mouth":(:TO,"mouth_attack":),"right claw":(:TO,"claw_attack":),"left claw":(:TO,"claw_attack":)]));
    set_base_damage_type("slashing");
    set_class("fighter");
    set_gender("male");
    set_race("dragon");
    set("aggressive",1);
    set_funcs(({"do_me"}));
    set_func_chance(102);
//    add_money("gold",random(20000));
//    add_money("platinum",random(1000));
    set_alignment(8); //Chaotic neutral for this dragon
    //set_property("no rush",1);
    set_spells(({"confusion","confusion","confusion","dispel magic"}));
    set_spell_chance(30);
    set_mob_magic_resistance("average");
    set_property("no knockdown",1);
    set_property("no death",1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_property("no steal",1);
    set_property("damage resistance",5);
//    set_wimpy(15);
}

int mouth_attack(object targ){
    if(!random(3)){
        return roll_dice(6,25);
    }
    return roll_dice(4,25);
}

int claw_attack(object targ){
    if(!random(3)){
        return roll_dice(3,10);
    }
    return roll_dice(2,10);
}

void do_me(object targ){
    int i,j;
    object *inven;

    inven = all_living(ETO);

    j = sizeof(inven);
    tell_room(ETO,"%^BOLD%^%^BLACK%^The dragon %^RED%^shrieks%^BLACK%^ in rage, lowering his head.");
    for(i=0;i<j;i++){
        if(!objectp(inven[i])) continue;
        if(inven[i] == TO) continue;
        if(avatarp(inven[i])) continue;
        set_property("magic",1);
        tell_object(inven[i],"%^BOLD%^%^RED%^The shriek shakes your bones as a line of %^YELLOW%^energy%^RED%^ streaks toward you!%^RESET%^\n");
        if("/daemon/saving_throw_d"->reflex_save(inven[i],-35)){
            inven[i]->do_damage("torso",roll_dice(24,8)/3);
        }else{
            inven[i]->do_damage("torso",roll_dice(24,8)+12);

            if(!"/daemon/saving_throw_d"->fort_save(inven[i],-14)){
                inven[i]->set_paralyzed(( roll_dice(1,12))*8,"%^BOLD%^Your entire body is still vibrating!%^RESET%^");
            }
        }
        remove_property("magic");
    }
    set_func_chance(50);
}

void heart_beat(){
    int i,j;
    object ob;
    string *tmp, location;

    ::heart_beat();

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tmp = ({});

    if(query_attackers() == ({})){
        set_func_chance(102);
        call_out("home",10);
    }else{ 
       add_hp(55); 
    }
}

void set_paralyzed(int time, string mes){
    if(!PO->is_spell()) return ::set_paralyzed(time,mes);
    return;
}

void set_bound(int xxx, string msg) {return 1;}

void set_tripped(int xxx, string msg) {return 1;}

void init(){
    ::init();

    if(wizardp(TP)) return;
    
    if(TP->query_invis()){
        tell_object(TP,"%^BOLD%^%^BLACK%^Smoke%^RESET%^ spews from the dragon's nostrils as he looks directly at you!\n");
    }
    
    if(TP == TO) return;
}

void home(){
    object home;
    if(!objectp(TO)){ return 1; }
    if(query_attackers() == ({})){
       tell_room(ETO,"%^RESET%^%^ORANGE%^The %^BOLD%^%^BLACK%^dragon "
          "%^RESET%^%^ORANGE%^disappears with a puff of %^BOLD%^"
          "%^BLACK%^smoke%^RESET%^%^ORANGE%^.%^RESET%^");
       "/d/player_houses/silesse/ivorybuilding.c"->redo_constellations();
       TO->move("/d/shadowgate/void");
       TO->remove();
    }
}

void die(object obj){
    int i,j;
    object ob;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(objectp(ETO) && (string)ETO->query_name() == "Inside an ivory building"){
       ETO->set_dead_guardian();
       ETO->set_sil_open();
    }
    ::die(obj);
}

int test_heart() { return 1; }