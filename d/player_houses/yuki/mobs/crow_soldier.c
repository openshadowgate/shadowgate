
//Crow soldier

#include <std.h>

inherit MONSTER;

void make_me();

void create(){
        ::create();
        set_name("soldier of the Crows");
        set_id(({"soldier","crow","soldier of the guild crow","militia","guard"}));
set_short("soldier");
        set_long("%^BLACK%^%^BOLD%^This rough looking soldier has the look of a "+
		"person who's been through %^RESET%^%^RED%^cou%^RESET%^n%^RED%^tless enc"+
		"oun%^RESET%^t%^RED%^ers%^BLACK%^%^BOLD%^ on both sides of conflict. The"+
		"ir features are marked with countless %^RESET%^%^ORANGE%^s%^RESET%^"+
		"c%^ORANGE%^ars%^BLACK%^%^BOLD%^ and the %^RESET%^hardn%^BOLD%^e%^RESET%^s"+
		"s%^BLACK%^%^BOLD%^ in their eyes belies the fact that they are marked b"+
		"y %^RESET%^%^RED%^combat%^BLACK%^%^BOLD%^. Their %^RESET%^armo"+
		"r%^BLACK%^%^BOLD%^ and %^RESET%^weapons%^BLACK%^%^BOLD%^ are of perf"+
		"ect quality and obviously well cared for. The only item that seems wors"+
		"e for wear is the b%^RESET%^l%^BLACK%^%^BOLD%^a%^RESET%^c%^BLACK%^%^BOLD%^k"+
        " clo%^RESET%^a%^BLACK%^%^BOLD%^k they wear, with a %^RESET%^%^RED%^blo%^BOLD%^"+
        "o%^RESET%^%^RED%^d red %^BLACK%^%^BOLD%^ornate feather insignia on it.%^RESET%^");
        set_hd(8,1);
        set_exp(1400);
        set_stats("strength",18);
        set_alignment(3);
        set_size(2);
        set_body_type("human");
        add_limb("neck","neck",0,0,0);
        set_wielding_limbs(({"right hand","left hand"}));
        set_gender("male");
        set("aggressive",6);
        set_property("swarm",0);
        set_mob_magic_resistance("average");
        set_max_level(15);
        make_me();
        add_money("gold",10+random(5));
        add_money("silver",10+random(5));
        add_money("electrum",10+random(5));

}

void make_me(){
        object ob;
        int i,j,k;
        string myclass,race;
        i = random(5);
        switch(i){
        case 0: race = "half-drow";
                break;
        case 1: race = "human";
                break;
        case 2: race = "half orc";
                break;
        case 3: race = "half-elf";
                break;
        case 4: race = "human";
                break;
        }

        set_race(race);
    set_short("%^BLACK%^%^BOLD%^A " +query_race()+ " s%^RESET%^%^RED%^o"+
	"%^BLACK%^%^BOLD%^ldi%^RESET%^e%^BLACK%^%^BOLD%^r of the "+
	"Cro%^RESET%^%^RED%^w%^BLACK%^%^BOLD%^s%^RESET%^");
        i = random(4);
        switch(i){
        case 0:
        case 1: myclass = "fighter";
                break;
        case 2: myclass = "cleric";
                break;
        case 3: myclass = "mage";
        }
        set_class(myclass);
       set_guild_level(myclass,20);
       set_mlevel(myclass,20);

        switch(myclass){
        case "fighter":
                set_hp(250);
				ob = new("/d/common/obj/armour/cloak_hooded");
                    ob->set_property("enchantment",4);
					ob->set_property("monsterweapon",1);
					ob->set_obvious_short("%^BLACK%^%^BOLD%^rag%^RESET%^"+
					"g%^BLACK%^%^BOLD%^ed b%^RESET%^l%^BLACK%^%^BOLD%^ac"+
					"k cl%^RESET%^o%^BLACK%^%^BOLD%^ak%^RESET%^");
                    ob->move(TO);
				command("wear cloak");
                ob = new("/d/common/obj/weapon/longsword");
                    ob->set_property("enchantment",4);
                    ob->set_property("monsterweapon",1);
                    ob->move(TO);
                command("wield sword in right hand");
                ob = new("/d/common/obj/armour/chain");
                    ob->set_property("enchantment",4);
					ob->set_property("monsterweapon",1);
                    ob->move(TO);
                command("wear armor");
                break;
        case "cleric":
                set_hp(250);
				ob = new("/d/common/obj/armour/cloak_hooded");
                    ob->set_property("enchantment",4);
					ob->set_property("monsterweapon",1);
					ob->set_obvious_short("%^BLACK%^%^BOLD%^rag%^RESET%^"+
					"g%^BLACK%^%^BOLD%^ed b%^RESET%^l%^BLACK%^%^BOLD%^ac"+
					"k cl%^RESET%^o%^BLACK%^%^BOLD%^ak%^RESET%^");
                    ob->move(TO);
				command("wear cloak");
                ob = new("/d/common/obj/weapon/mace");
                    ob->set_property("enchantment",4);
                    ob->set_property("monsterweapon",1);
                    ob->move(TO);
                command("wield mace in right hand");
                ob = new("/d/common/obj/armour/chain");
                    ob->set_property("enchantment",4);
					ob->set_property("monsterweapon",1);
                    ob->move(TO);
                command("wear armor");
                set_spells(({ "cause moderate wounds","call lightning",
"dispel magic", "hold person"}));
                set_spell_chance(60);
                break;
        case "mage":
                set_hp(250);
				ob = new("/d/common/obj/armour/cloak_hooded");
                    ob->set_property("enchantment",4);
					ob->set_property("monsterweapon",1);
					ob->set_obvious_short("%^BLACK%^%^BOLD%^rag%^RESET%^"+
					"g%^BLACK%^%^BOLD%^ed b%^RESET%^l%^BLACK%^%^BOLD%^ac"+
					"k cl%^RESET%^o%^BLACK%^%^BOLD%^ak%^RESET%^");
                    ob->move(TO);
				command("wear cloak");
                ob = new("/d/common/obj/armour/bracers");
                    ob->set_property("enchantment",4);
					ob->set_property("monsterweapon",1);
                    ob->move(TO);
				command("wear bracers");
                ob = new("/d/common/obj/weapon/dagger");
                    ob->set_property("enchantment",1);
                    ob->set_property("monsterweapon",1);
                    ob->move(TO);
                command("wield dagger in right hand");
                set_spells(({"magic missile",
                                "lightning bolt",
                                "magic missile",
                                "dispel magic"}));
                set_spell_chance(90);
                break;
        }
}
