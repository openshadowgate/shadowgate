#include <std.h>
#define SAVE_D "/daemon/save_d"
inherit MONSTER;

void create(){
        object ob;
        ::create();
        set_name("blade golem");
        set_short("mass of chains");
        set_id(({"golem","blade golem","chains","mass of chains"}) );
        set_long("This is a large metal sphere wrapped in chains.  The chains are connected to various objects.  There "
"are barbed blades, serrated blades,  Spiked metal balls, giant scissors, axes and knives it looks like a terrible "
"assortment of objects of war.\n");
        set_race("golem");
        set_body_type("human");
        set_overall_ac(-10);
        set_hd(25, 10);
        set_class("fighter");
        set_mlevel("fighter", 25);
        set_wielding_limbs(({"right hand","left hand"}));
        set_gender("male");
        set_size(3);
        ob = new("/d/common/obj/weapon/claw");
                ob->move(TO);
                ob->set_property("enchantment",2);
                ob->set_property("monsterweapon",1);
                command("wield claw");
        ob = new("/d/common/obj/weapon/whip_dagger");
                ob->move(TO);
                ob->set_property("enchantment",2);
                ob->set_property("monsterweapon",1);
                command("wield whip");
        set_stats("strength",22);
        set_stats("dexterity", 16);
        set_stats("intelligence", 0);
        set_stats("wisdom", 0);
        set_stats("constitution", 20);
        set_stats("charisma", 14);
        set_property("swarm",1);
        set_max_hp(550);
        set_hp(query_max_hp());
        set_mob_magic_resistance("average");
        set_property("magic",1);
        set_exp(1000);
        set_property("full attacks",1);
        set_max_level(25);
        set_funcs(({"slashy"}));
        set_func_chance(25);
   setenv("MIN", "$N rolls in.");
   setenv("MOUT", "$N rolls $D.");
}

void init(){
    string myname;
    ::init();
    add_action("kill_em", "destroy");
    myname = TP->query_name();
    if(member_array(myname,(string *)SAVE_D->query_array("valas_house")) != -1) command("kill " + myname);
}

int kill_em(string str) {
    string mname;
    mname = TP->query_name();
    if(!avatarp(TP) && !(mname == "valas")) return notify_fail("The golem ignores you");
    if(!str)return notify_fail("Who do you want the golem to destroy?");
    if(!present(str, ETO))return notify_fail("Try picking someone in the room!");
    tell_room(ETO,"The statue suddenly comes to life and attacks!");
    command("kill " + str);
    return 0;
}

void slashy(object targ){
    int dex,con,poison,para;
    if(!objectp(targ)) return;
    tell_object(targ,"The blade golem shoots a blade, impaling you!");
    tell_room(ETO,"The blade golem shoots a blade, impaling "+targ->QCN+"!",targ);
    targ->do_damage("torso",40+random(50));
}

void die(object ob) {
   object myob,*mytargs;
   int weapons,i,j;
   tell_room(ETO,"The blade golem shudders and falls apart.");
   weapons = roll_dice(2,4);
   mytargs = TO->query_attackers();
   for(i=0;i<weapons;i++) {
     myob = new("/d/player_houses/valas/mon/weapon");
     myob->move(ETO);
     for(j=0;j<sizeof(mytargs);j++) myob->add_attacker(mytargs[j]);
   }
   TO->move("/d/shadowgate/void");
   TO->remove();
}