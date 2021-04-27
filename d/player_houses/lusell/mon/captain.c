#include <std.h>
#include <daemons.h>
#include "../lusell.h"
inherit MONSTER;

int FLAG,FLAG2,dlevel,num,num2,timer;
object ob;

create() {
   ::create();
   set_name("captain");
   set_id(({"monster","captain","captain of the guard","officer"}));
   set_short("captain of guard");
 	set_long("This is the commanding officer of the keep garrison.  "+
    	"He is a seasoned fighter and his demeanor shows it.  His "+
   	"gear is immaculate and his composure commanding.");
   set_body_type("human");
   dlevel = random(10) +25;
   set_hd(dlevel,10);
   set_class("fighter");
   set_mlevel("fighter", dlevel);
   set_wielding_limbs(({"right hand","left hand"}));
   set_alignment(5);
   set_race("human");
   set_gender("male");
   set_overall_ac(0);
   set_stats("strength",19);
   set_stats("dexterity",random(3)+16);
   set_stats("intelligence",random(5)+14);
   set_stats("wisdom",random(5)+14);
	set_stats("constitution",random(3)+16);
   set_stats("charisma",random(5)+14);
   set_size(2);
   set_exp(dlevel*50);
   set_max_hp((random(50)+(dlevel*10)));
   set_hp(query_max_hp());
   set_achats(1,({
		"The captain moves under your guard with ease.",
		"The captain slams his shoulder into you attempting to throw you off balance.",
		"The captain parries your blow with ease.",
		"The captain weaves his blades in battle like an artist.",
		"%^BOLD%^%^CYAN%^The captain commands: %^RESET%^TO ME! TO ME! INTRUDERS!!.",
   }),0);
   set_emotes(1,({
   	"The captain surveys the area.",
   	"The captain nods, barely, at you.",
		"The captain smiles and runs his hand over the stonework.",
		"The captain smiles confidently.",
		"The captain seems lost in thought momentarily.",
   }),0);
   add_money("copper",random(500));
   add_money("silver",random(250));
   add_money("gold",random(250));
   add_money("platinum",random(100));
	num = random(100);
    	ob = new("/d/islands/tonerra/obj/Lcloak.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear cloak");
	num = random(100);
    	ob = new("/d/deku/armours/ring_p.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->set_property("enchantment",3);
    		ob->move(TO);
    		command("wear ring");
 	num = random(100);
   	ob = new("/d/dagger/cave2/obj/blacksword.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield serrated");
  	ob = new( CWEAP+"longsword.c" );
   	ob->set_property("monsterweapon", 1);
  	  	ob->move(TO);
   	ob->set_property("enchantment",5);
   	command("wield sword");
	ob = new(CARM+"fullplate.c");
   	ob->set_property("monsterweapon", 1);
   	ob->move(TO);
   	command("wear plate");
   ob = new("/d/common/obj/potion/healing");
   	ob->move(TO);
   	ob->set_uses(random(25)+20);
   command("speak common");
   command("speech bark");
   set_property("full attacks",1);
   add_search_path("/cmds/fighter");
   set_max_level(25);
   set_property("swarm",1);
	FLAG = 0;
	FLAG2 = 0;
	num2 = 0;
   set_speed(35);

	set_funcs(({"summon"}));
	set_func_chance(25);

	set_property("knock unconscious");
}
void init(){
	string mname=TP->query_name();
   ::init();
   if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;

	if(mname == "lusell"){
		force_me("emote salutes the lady of the keep");
		force_me("say well met Lady Lusell!");
		return;
	}
	if(TP->query_unconscious())return;	
	if(TP->query_bound())return;
	if(present("emerald clasp",TP)){
		force_me("nod "+mname);
		return;
	}else{
		force_me("say you are trespassing, penalty is death!");
		force_me("yell INTRUDERS!!!");
		TO->kill_ob(TP);
		if (!random(3))force_me("rush "+TP->query_name());
		return;
	}
}
void summon(object targ){
	string who;

	switch(num2){
		case(0) :
  			command("say TO ME GUARD OF THE WATCH!");
  			tell_room(ETO,"Guards rush to their captain's call.");

			ob = new(LMON+"private_nm");
			ob->move(ETO);
			TO->add_follower(ob);
			ob->command("protect captain");
			ob->kill_ob(targ);

			ob = new(LMON+"sergeant_nm");
			ob->move(ETO);
			TO->add_follower(ob);
			ob->command("protect captain");
			ob->kill_ob(targ);

			if(random(2)){
				ob = new(LMON+"private_nm");
				ob->move(ETO);
				TO->add_follower(ob);
				ob->command("protect captain");
				ob->kill_ob(targ);
			}
			if(random(2)){
				ob = new(LMON+"private_nm");
				ob->move(ETO);
				TO->add_follower(ob);
				ob->command("protect captain");
				ob->kill_ob(targ);
			}
			num2 = 1;
			return;
		case(1) :
			if(objectp(targ) && present(targ,environment(TO))){
				who = targ->query_name();
				TO->force_me("flash "+who);
			}
			return;
	}

}

void heart_beat() {
  	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;

   if(present("kit",TO) && query_hp() < query_max_hp()/3){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("open kit");
		command("quaff kit");
		command("offer bottle");
   }
   if(present("bottle",TO)) command("offer bottle");

	if(FLAG == 0)return;

  	timer++;
   if(timer > 20){
   	timer = 0;
		if(query_attackers() != ({})){
			FLAG = 0;
    		return;
    	}
   }
}
