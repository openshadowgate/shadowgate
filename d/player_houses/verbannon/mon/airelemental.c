#include <std.h>
#define SAVE_D "/daemon/save_d"
inherit MONSTER;

void create(){
        object ob;
        ::create();
        set_name("air elemental");
        set_short("whirling windstorm of armor and weaponry");
        set_id(({"windstorm","whirling windstorm","elemental","air elemental"}) );
        set_long("Within a mighty wind an assortment of armor and weapons swirl, forming the semblance of an armored warrior "
"clad head to toe in steel. Forming the head is a helmet floating right above a cuirass which forms the body. The legs and feet "
"are a set of greaves, a chain skirt and a pair of steel boots. Spaldings, bracers and gauntlets form the arms and hands. A "
"shield is clasped in the left gauntlet and a bastard sword in the right. This is no enchantment or haunting, before you stands "
"a mighty air elemental! Known for their skill in battle this one is also well armed and armored. Looking within the empty "
"helmet you can almost see its stern battle hardened visage sizing you up, as its features drift in and out of view.\n");
        set_race("elemental");
        set_body_type("human");
        set_overall_ac(-10);
        set_hd(35, 10);
        set_class("fighter");
        set_mlevel("fighter", 35);
        set_wielding_limbs(({"right hand","left hand"}));
        set_gender("neuter");
        set_size(2);
        ob = new("/d/common/obj/weapon/bastard");
                ob->move(TO);
                ob->set_property("enchantment",2);
                command("wield bastard");
        ob = new("/d/common/obj/armour/mshield");
                ob->move(TO);
                ob->set_property("enchantment",2);
                command("wear shield");
        ob = new("/d/common/obj/armour/breastplate");
                ob->move(TO);
                ob->set_property("enchantment",2);
                command("wear breastplate");
                ob->set_short("shining cuirass");
                ob->add_id("cuirass");
        ob = new("/d/common/obj/armour/helm");
                ob->move(TO);
                ob->set_property("enchantment",2);
                command("wear helm");
        ob = new("/d/common/obj/armour/gauntlets");
                ob->move(TO);
                ob->set_property("enchantment",2);
                ob->set_property("monsterweapon",1);
                command("wear gauntlets");
        ob = new("/d/common/obj/armour/greaves");
                ob->move(TO);
                ob->set_property("enchantment",2);
                ob->set_property("monsterweapon",1);
                command("wear greaves");
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
   setenv("MIN", "$N drifts in.");
   setenv("MOUT", "$N drifts $D.");
}

void die(object ob) {
   object myob,*mytargs;
   int weapons,i,j;
   tell_room(ETO,"The elemental shrieks and dissipates into air, leaving the weapons and armor to clatter to the ground.");
   present("bastard",TO)->move(ETO);
   present("shield",TO)->move(ETO);
   present("cuirass",TO)->move(ETO);
   present("helm",TO)->move(ETO);
   TO->move("/d/shadowgate/void");
   TO->remove();
}