//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
      object ob;
	::create();
	set_name("giant spider");
	set_id(({"spider","monster","giant spider"}));
	set_short("A giant spider");
	set_long(
	"The spider is incredibly large, at least ten feet in height."+
	" She has naturally hard body armor that gives her some"+
	" protection as she stands guard over her nest. Her coloring"+
	" is black and brown, blending in well with the forest. Her"+
	" pincers clack together slowly, sending little chills down"+
	" your spine. Her mandibles move together hungrily, she is"+
	" obviously hoping to make a meal out of you. To get caught"+
	" by that bite would almost assuredly mean your death. Her"+
	" other weapon seems to be the numerous strands of sticky"+
	" webbing in the area. This is definitely not a good place"+
	" to be."
	);
	set_race("spider");
	set_gender("female");
	set_body_type("arachnid");
	set_hd(20,3);
        set_max_level(20);
	set_overall_ac(4);
	set_alignment(9);
	set_size(3);
	set_max_hp(random(40)+100);
	set_hp(query_max_hp());
//        set_exp(7000);
	set_new_exp(15,"normal");
	add_limb("mouth","head",0,0,0);
	set_attack_limbs(({"right pincer","left pincer","mouth"}));
	set_attacks_num(1);
	set_nat_weapon_type("pierce");
	set_damage(1,8);
	set("aggressive",25);
	set_property("swarm",1);
	set_level(15);
	set_hit_funcs((["mouth":(:TO,"bite":)]));
	set_class("fighter");
	set_mlevel("fighter",15);
	set_funcs(({"web"}));
	set_func_chance(10);
	add_money("silver",random(500));
	set_emotes(8,({
	"The giant spider clacks her pincers together.",
	"Venom drips out of the spider's mouth and singes the ground.",
	"The giant spider circles around you.",
	}),1);
    if(!random(6)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("spiderweb");
      ob->move(TO);
    }
}

int bite(object targ)
{
        if(!"/daemon/saving_throw_d.c"->fort_save(targ,-11)){
		tell_object(targ,"%^RED%^You feel the venom in the spider's"+
		" bite burn through your veins.");
		tell_room(ETO,"%^RED%^"+targ->query_cap_name()+""+
		" moans and looks a little pale.",targ);
		targ->add_poisoning(30);
		return 1;
	}
	else {
		tell_object(targ,"You clench your teeth and ignore the"+
		" spider's poison.");
		return 1;
	}
}

void web(object targ)
{
	int dex, roll, strn, TIME;

	dex = targ->query_stats("dexterity");
	roll = random(20);
	strn = targ->query_stats("strength");
	TIME = 19 - strn;

	if(roll > dex) {
		tell_object(targ,"%^BOLD%^%^BLACK%^The spider pushes you"+
		" into her web!");
		tell_room(ETO,"%^BOLD%^%^BLACK%^The spider"+
		" pushes "+targ->query_cap_name()+" into her web!",targ);
		switch(TIME) {
			case 1:
				targ->set_paralyzed(25,"You are stuck in the web!");
				break;
			case 2:
				targ->set_paralyzed(40,"You are stuck in the web!");
				break;
			case 3:
				targ->set_paralyzed(65,"You are stuck in the web!");
				break;
			case 4:
				targ->set_paralyzed(80,"You are stuck in the web!");
				break;
			case 5:
				targ->set_paralyzed(100,"You are stuck in the web!");
				break;
			case 6:
				targ->set_paralyzed(125,"You are stuck in the web!");
				break;
			case 7:
				targ->set_paralyzed(140,"You are stuck in the web!");
				break;
			case 8:
				targ->set_paralyzed(165,"You are stuck in the web!");
				break;
			case 9:
				targ->set_paralyzed(180,"You are stuck in the web!");
				break;
			case 10:
				targ->set_paralyzed(200,"You are stuck in the web!");
				break;
			case 11:
				targ->set_paralyzed(225,"You are stuck in the web!");
				break;
			case 12:
				targ->set_paralyzed(240,"You are stuck in the web!");
				break;
			case 13:
				targ->set_paralyzed(265,"You are stuck in the web!");
				break;
			case 14:
				targ->set_paralyzed(280,"You are stuck in the web!");
				break;
			case 15:
				targ->set_paralyzed(300,"You are stuck in the web!");
				break;
			case 16:
				targ->set_paralyzed(325,"You are stuck in the web!");
				break;
			case 17:
				targ->set_paralyzed(340,"You are stuck in the web!");
				break;
			case 18:
				targ->set_paralyzed(365,"You are stuck in the web!");
				break;
			default:
				targ->set_paralyzed(25,"You are stuck in the web!");
				break;

			return 1;
		}
	}
	else {
		tell_object(targ,"%^BOLD%^You avoid the spider's attempts"+
		" to stick you in her web.");
		tell_room(ETO,""+targ->query_cap_name()+""+
		" avoids the spider's attempts to stick "+targ->query_objective()+""+
		" in her web.",targ);
		return 1;
	}
}

void reset()
{
	::reset();
	if(!present("gem")) {
		if(!random(4)) {
			switch(random(400)) {
					case 0..300:
					new(OBJ+"gem")->move(TO);
					break;
				case 301..350:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
				case 351..375:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
				case 376..400:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
			}
		}
	}
	if(!present("jewelry")) {
		if(!random(5)) {
			switch(random(200)) {
				case 0..100:
					new(OBJ+"jewelry")->move(TO);
					break;
				case 101..175:
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					break;
				case 176..200:
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					break;
			}
		}
	}
}
