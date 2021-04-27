//Coded by Bane//
//made the same fixes as to the other dragons so if functions are reduced 
//enough to have weaponless combat kick in it won't bug.  *Styx*  4/30/02
//Switched out helm of brillance for white dragon plate because after discussion with Tsera, Circe and T it was moved to a //new area -Cythera 03/28/05
#include <std.h>
#include "../sorrowsong.h"
#include <daemons.h>
inherit WEAPONLESS;

int done, storm, heal, weapon, i;
object *others;


void create(){
    ::create();
    set_id(({"dragon","white","white dragon","wyrm","great wyrm","muln","goddess"}));
    set_name("muln");
    set_short("%^BOLD%^%^WHITE%^Muln - D%^CYAN%^r%^WHITE%^ag%^CYAN%^o%^WHITE%^n Go%^CYAN%^dd%^WHITE%^ess of So%^CYAN%^rr%^WHITE%^ow's S%^CYAN%^o%^WHITE%^ng");
    set_long("%^BOLD%^%^WHITE%^This dragon is no wyrmling by any stretch of the imagination. She stretches at least seventy-five feet"
	" in length and easily weighs twenty-five tons or more. Her scales g%^CYAN%^l%^WHITE%^isten like mirrors, reflecting all"
	" light away from her, except in a few patches where the mirrored scales have lost their sheen and turned a "
	"%^RESET%^%^CYAN%^pale %^BLUE%^blue%^BOLD%^%^WHITE%^ or light %^RESET%^gray%^BOLD%^%^WHITE%^. %^CYAN%^I%^WHITE%^c%^CYAN%^y blue%^WHITE%^"
	" eyes glare out with %^BOLD%^%^BLACK%^m%^GREEN%^a%^BLACK%^li%^GREEN%^c%^BLACK%^e%^WHITE%^ from above a beaked nose and"
	" %^RESET%^%^ORANGE%^spiny dewlaps%^BOLD%^%^WHITE%^. She is a truly %^RED%^terrifying%^WHITE%^ creature to behold, her countenance leaves you frozen in place."
	" fr%^CYAN%^o%^WHITE%^zen%^WHITE%^ in place. A chemical odor from her tickles your nose.");
    set_race("dragon");
    set_body_type("dragon");
    set_gender("female");
    set_alignment(9);
    set_size(3);
	add_money("gold",random(75000));
    set_class("mage");
    set_class("cleric");
    set_hd(35+(random(11)),4);
    set_mlevel("mage",query_hd());
    set_mlevel("cleric",query_hd());
    set_hp((query_hd() * 50) + random(query_hd()));
    set_guild_level("mage",query_hd());
    set_guild_level("cleric",query_hd());
    set_attack_bonus(10);
    set("aggressive",30);
	set_property("weapon resistance", 3);
	set_property("spell penetration",50);
	set_property("cold resistance",200);
	set_property("fire resistance",-200);
    set_mob_magic_resistance("average");
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("swarm",1);
	set_property("no paralyze", 1);
    set_property("no tripped",1);
    set_property("no bows",1);
    set_property("no steal",1);
    set_stats("strength",25);
    set_stats("dexterity",10);
	set_stats("intelligence",18);
	set_stats("wisdom",19);
	set_stats("charisma",18);
	set_stats("constitution",25);
    set_new_exp(28,"boss");
    set_overall_ac(-25);
    set_spells(({
	"magic missile",
	"cone of cold",
	"lightning bolt",
	"chill touch",
	"greater dispel magic",
	"chain lightning",
	"chill metal",
	"dispel law",
	"dispel good",
	"hypothermia",
	"ice shield",
	"lower resistance",
	"airbolt",
	"windstorm",
	"frost breath",
	"greater dispel magic",
	}));
		set_monster_feats(({
		"spell focus",
		"spell penetration"
		"perfect caster"
    }));
	
    add_limb("mouth", "head", 0, 0, 0);
    set_attack_limbs(({"right foreclaw","left foreclaw","tail","mouth"}));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(2,8);
    set_funcs(({"breath"}));
    set_func_chance(102);
    set_spell_chance(70);
    weapon = 0;
    }



int kill_ob(object victim, int which){
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold){
	if(storm < 1){
	new("/cmds/spells/i/_ice_storm")->use_spell(TO,0,query_hd(),100,"mage");
	storm = 1;
	}
    }
}


void breath(object targ){
    others = all_living(ETO);
    weapon++;
    for(i=0;i<sizeof(others);i++){
	others[i]->remove_property("hit");
    }
    if(weapon < 10){
	set_func_chance(60);
	} else {
	set_func_chance(0);
    }
    tell_room(ETO,"%^BOLD%^%^CYAN%^The dragon breathes a cone of frost everywhere!%^RESET%^");
    if (targ->reflex_save(29)){
	tell_object(targ,"%^BOLD%^%^CYAN%^The frost %^BOLD%^%^BLACK%^burns%^BOLD%^%^CYAN%^ into you like %^RED%^fire!%^RESET%^");
	tell_room(ETO,"%^BOLD%^%^CYAN%^The frost engulfs "+targ->query_cap_name()+" completely!%^RESET%^",targ);
	set_property("magic",1);
	targ->cause_typed_damage(targ, 0, roll_dice(24,10) ,"cold");
	remove_property("magic");
	targ->set_property("hit",1);
	return 1;
    }
    tell_object(targ,"%^BOLD%^%^CYAN%^You dive out of the way and only get slightly frozen!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^CYAN%^"+targ->query_cap_name()+" dives out of the way and only gets slightly frozen!%^RESET%^",targ);
    set_property("magic",1);
    targ->cause_typed_damage(targ,0,roll_dice(24,10)/2,"cold");
    remove_property("magic");
    targ->set_property("hit",1);
    return 1;
}

void heart_beat(){
    if (!objectp(TO)) return;
    if(TO->query_hp() < 250){
	if(!heal){
	    new("/cmds/spells/h/_heal")->use_spell(TO,TO,query_level(),100,"cleric");
	    heal = 1;
	}
    }
    if(TO->query_hp() < TO->query_max_hp()){
	TO->add_hp(1);
    }
    if(!sizeof(TO->query_attackers())) {
	set_func_chance(102);
	storm = 0;
	weapon = 0;
	heal = 0;
    }
}
void check_me()
{
    done = 0;
}
void reset()
{
    ::reset();
    set_func_chance(102);
    heal = 0;
    weapon = 0;
    storm = 0;
}
void die(object ob) 
{
    int i;
    object who;
   tell_room(ETO,"%^BOLD%^%^BLACK%^An ear %^WHITE%^sha%^CYAN%^tt%^WHITE%^ering%^BLACK%^ roar echoes through the room as %^WHITE%^Muln%^BLACK%^ collaspes "
"into the altar, breathing her last breath. %^YELLOW%^Coins %^BLACK%^and %^MAGENTA%^precious items%^BLACK%^ scatter across the cave.%^RESET%^");
   switch(random(3)){
      case 0: new(OBJ"foesgift")->move(ETO);
              break;
      case 1: new(OBJ"whdragonplate")->move(ETO);
              break;
      case 2: new(OBJ"iolitemail")->move(ETO);
              break;
   }
   switch(random(3)){
      case 0: new(OBJ"frostreaver")->move(ETO);
              break;
      case 1: new(OBJ"conjwand")->move(ETO);
              break;
      case 2: new(OBJ"staffvital")->move(ETO);
              break;
   }
   switch(random(3)){
      case 0: new(OBJ"andavenseye")->move(ETO);
              break;
      case 1: new(OBJ"linenpants")->move(ETO);
              break;
      case 2: new(OBJ"talsanklet")->move(ETO);
              break;
   }
   ::die(ob);
}