#include <std.h>
#include <daemons.h>
inherit MONSTER;

void create(){
    ::create();
    set_id(({"paladin","black armored paladin"}));
    set_name("banite blackguard");
    set_short("%^BOLD%^%^BLACK%^A black armored paladin%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Before you stands a powerful squadron leader among the Tonovian "
"army.  He is clad in solid black plated armor from head to toe, leaving only "
"a slit in his helm to perceive that a man may actually lie beneath the shell. "
"A %^GREEN%^glowing%^BOLD%^%^BLACK%^ lance is couched at his side, ready for "
"battle. The gauntlet symbol of Bane is emblazoned across his tabard.%^RESET%^");
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_class("paladin");
    set_diety("bane");
    set_mlevel("paladin",35);
    set_guild_level("paladin",35);
    set_hd(35,12);
    set_max_hp(2345);
    set_hp(2345);
    set_mob_magic_resistance("average");
    set_overall_ac(0);
    set_property("no rush",1);
    set_property("no dominate",1);
    set_exp(15000);
    set_stats("strength",18);
    set_stats("constitution",18);
    set_stats("dexterity",17);
    set_stats("charisma",17);
    set_alignment(3);
    add_money("gold",random(500)+150);
    add_money("platinum",random(10)+5);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/laerad/obj/pallyplate")->move(TO);
    present("plate",TO)->set_property("monsterweapon",1);
    command("wear armor");
    new("/d/common/obj/armour/helm")->move(TO);
    command("wear helm");
    new("/d/laerad/obj/dlance")->move(TO);
    command("wield lance");
    set_funcs(({"bolt","bolt"}));
    set_func_chance(50);
    set_property("full attacks",1);
    call_out("do_horse",1);
    set_property("knock unconscious",1);
}

void bolt(object targ){
    tell_room(ETO,"%^BOLD%^%^GREEN%^The blackguard holds his hand out, and crackling black energy forms into a ball between his fingers.");
    tell_object(targ,"%^BOLD%^%^GREEN%^A blast of raw black energy explodes from the paladin's hand, enveloping you!");
    tell_room(ETO,"%^BOLD%^%^GREEN%^A blast of raw black energy explodes from the paladin's hand, enveloping "+targ->QCN+"!",targ);
    set_property("magic",1);
    targ->do_damage(targ->return_target_limb(),(roll_dice(10,10)+100));
    targ->set_paralyzed(15,"You are trying to pick yourself up after being struck by the blast!");
    remove_property("magic");
}

void do_horse(){
	object horse;
	if(!objectp(ETO)) return;
	horse = new("/d/tharis/monsters/sksteed");
	horse->set_owner(TO);
	horse->move(ETO);
	command("mount horse");
}