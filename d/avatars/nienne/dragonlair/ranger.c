#include <std.h>
inherit MONSTER;

object ob;

void create() {
    ::create();
    set_name("Elven ranger");
    set_id( ({"elf","ranger","elven ranger"}) );
    set_short("Elven ranger");
    set_long("This elven warrior is clad head to toe in darkly colored leathers, granting protection both from sight and blows. Dark hair is pulled back servicably from its face, revealing angular features characteristic of elfkind. A blade is held easily in each hand, the steady grip suggesting the wielder is quite competent in their use.");
    set_race("elf");
    set_body_type("human");
    if(random(2)) set_gender("male");
    else set_gender("female");
    set_wielding_limbs(({"right hand", "left hand"}) );
    set_size(2);
    set_class("fighter");    
    set_mlevel("fighter", 15);
    set_hd(15,10);
    set_new_exp(15,"normal");
    set_max_hp(150+random(200));
    set_hp(query_max_hp());
    set_overall_ac(-10);
    set_property("swarm",1);
    set_property("full attacks", 1);
    set_stats("strength", 17);
    set_mob_magic_resistance("average");
    set_alignment(7);
    add_money("gold", random(500));
    add_money("silver", random(2500));
    set_funcs(({"kick", "smash"}));
    set_func_chance(30);
    ob = new("/d/avatars/nienne/statblade");
    ob->move(TO);
    if(random(9)) ob->set_property("monsterweapon",1);
    command("wield sword");
    ob = new("/d/token_hunt/obj/mid/forestsgleam");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield sword");
    set_property("knock unconscious",1);
}

void init() {
    ::init();
    if(avatarp(TP)) return;
    if(TP->query_invis()) return;
    if((string)TP->query_race() != "elf") call_out("kill_ob", 5, TP, 1);
}

void kick(object targ) {
    tell_room(ETO, "%^GREEN%^The elf drops and kicks out a foot, sending "+targ->QCN+" sprawling!%^RESET%^",targ);
    tell_object(targ, "%^GREEN%^The elf drops and kicks out a foot, sending you sprawling!%^RESET%^");
    targ->set_tripped(1,"You are trying to get up!");
}

void smash(object targ) {
    tell_room(ETO, "%^RED%^The elf lunges at "+targ->QCN+" with blade leading, cracking it hard across "+targ->QP+" skull!%^RESET%^", targ);
    tell_object(targ, "%^RED%^The elf lunges at you with blade leading, cracking it so hard across your skull that you see stars!%^RESET%^");
    targ->set_paralyzed(random(20)+5, "You're still blinking away spots from your vision!");
    targ->do_damage(targ->return_target_limb(),roll_dice(6,10));
}