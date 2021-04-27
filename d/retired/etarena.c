//Updated with feats - Octothorpe 6/21/10

#include <std.h>
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_id(({"etarena","Etarena","human"}));
    set_name("etarena");
    set_short("%^BOLD%^%^BLACK%^Etarena Telkaror, Lady of %^RED%^"
"F%^RESET%^%^RED%^ur%^BOLD%^y%^RESET%^");
    set_long("%^RESET%^Etarena has a %^BOLD%^lissome%^RESET%^ build enhanced "
"by extraordinary %^BOLD%^grace%^RESET%^ and fluency of movement. Her body is "
"in excellent physical condition with her muscles kept lean and toned, and "
"she appears to be in her mid or late twenties. Her lightly %^ORANGE%^"
"tanned%^RESET%^ skin is often marred by hints of battle. Despite this, the "
"statuesque angles of her face hold a natural %^BOLD%^allure%^RESET%^ with "
"her raised cheek bones, plump lips and sapphire eyes encircled with long, "
"thick lashes. Her straight %^BOLD%^%^BLACK%^ebony %^RESET%^hair falls below "
"her shoulders and its care does not appear to be a high priority of this "
"woman. A few %^BOLD%^%^BLACK%^b%^RESET%^e%^ORANGE%^a%^BOLD%^%^BLACK%^d"
"%^RESET%^e%^ORANGE%^d %^RESET%^dreadlocks are evident within the scraggly "
"strands. Her %^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^%^CYAN%^r%^BLACK%^k "
"%^RESET%^s%^BOLD%^%^CYAN%^a%^BLACK%^p%^RESET%^p%^BOLD%^%^CYAN%^h%^BLACK%^i"
"%^RESET%^r%^BOLD%^%^CYAN%^e %^BLACK%^e%^RESET%^y%^BOLD%^%^CYAN%^e%^BLACK%^s "
"%^RESET%^watch the world with a cold detachment, and found deep within their "
"depths are hints of %^MAGENTA%^violet %^RESET%^and %^CYAN%^azure%^RESET%^. "
"Spiraling around her upper arm is a %^BOLD%^%^BLACK%^dark %^RESET%^tattoo.");
    set_race("human");
    set_body_type("human");
    set_gender("female");
    set_alignment(6);
    set_diety("talos");
    set_class("ranger");
    set_hd(39,8);
    set_guild_level("ranger",39);
    set_mlevel("ranger",39);
    set_nogo(({"/d/player_houses/kiervalan/rooms/path","/d/player_houses/kiervalan/rooms/bathroom"}));
    set_max_hp(3000);
    set_hp(3000);
    set_exp(28000);
	add_attack_bonus(8);
	add_damage_bonus(8);
    set_overall_ac(-4);
    set("aggressive",0);
    set_stats("dexterity",18);
    set_stats("strength",18);
    set_property("full attacks",1);
    set_wielding_limbs(({"left hand","right hand"}));
    command("message in enters quietly.");
    command("message out leaves $D with soft footsteps.");
    command("speech say %^BOLD%^%^BLACK%^impassively%^RESET%^");
    set_emotes(1, ({"%^BOLD%^%^BLACK%^Etarena's lips curl into an %^RESET%^"
"%^MAGENTA%^amused smirk%^BOLD%^%^BLACK%^ as she slowly lowers her gaze down "
"the length of your body.%^RESET%^","%^RESET%^%^MAGENTA%^Etarena says "
"%^BOLD%^%^BLACK%^impassively: %^RESET%^Nature, in all its grand "
"destructiveness, will be the ruin of all men and their cities. None escape "
"the wrath of Talos!","%^BOLD%^%^BLACK%^A shock of dark %^YELLOW%^"
"lightning%^BOLD%^%^BLACK%^ crackles along the edge of Etarena's "
"sword.%^RESET%^","%^BOLD%^%^BLACK%^Etarena turns her cold, %^BOLD%^%^BLACK%^s"
"%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^p%^BOLD%^%^BLACK%^ph%^RESET%^%^BLUE%^i"
"%^BOLD%^%^BLUE%^r%^BOLD%^%^BLACK%^e e%^BOLD%^%^BLUE%^y%^RESET%^%^BLUE%^e"
"%^BOLD%^%^BLACK%^s on you and sneers.%^RESET%^" }), 0);
    add_money("gold", random(100)+400);
    add_money("platinum", random(30)+200);
    add_money("electrum", random(100)+500);
    ob = new("/d/retired/obj/talosblade");
    ob->move(TO);
    command("wield scimitar");
    ob = new("/d/attaya/obj/scimitar");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield scimitar");
    ob = new("/d/retired/obj/demonbracers");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear bracers");
    ob = new("/d/antioch/ruins/obj/demon_boots");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear boots");
    ob = new("/d/attaya/obj/callistaarmor");
    ob->move(TO);
    ob->set_obvious_short("%^BOLD%^%^BLACK%^Bodice of the %^RED%^Hu%^RESET%^"
"%^RED%^r%^BOLD%^%^BLACK%^r%^RESET%^ic%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^n"
"%^BOLD%^es%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear mesh");
    ob = new("/d/attaya/obj/pants");
    ob->move(TO);
    ob->set_obvious_short("%^BOLD%^%^BLACK%^Black leather pants%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear pants");
    ob = new("/d/attaya/obj/silkdrape");
    ob->move(TO);
    ob->set_obvious_short("%^BOLD%^%^BLACK%^A black silk top%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear drape");
    ob = new("/d/players/kiervalan/etagauntlets");
    ob->move(TO);
    ob->set_short("%^BOLD%^%^RED%^C%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^"
"aw%^RESET%^%^RED%^e%^BOLD%^d %^BLACK%^leather gauntlets%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear gauntlets");
    ob = new("/d/common/obj/rand/rand_leath_head");
    ob->move(TO);
    ob->add_id("cowl");
    ob->set_obvious_short("%^BOLD%^%^BLACK%^tattered black cowl%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear cowl");
	set_monster_feats(({
	   "ambidexterity",
	   "two weapon fighting",
	   "improved two weapon fighting",
	   "whirl",
	   "unassailable parry",
	   "toughness",
	   "improved toughness",
	   "damage resistance",
	   "regeneration",
	   "powerattack",
	   "shatter",
	   "sunder",
	   "rush",
	   "expertise",
	   "knockdown"	   
    }));
    set_funcs(({
	    "punch_me",
		"punch_me",
		"kdit",
		"rushit",
		"rushit",
		"rushit",
		"sunderit",
		"shatterit",
		"whirlit",
		"whirlit"
    }));
    set_func_chance(90);
    set_property("add kits",50);
    set_property("no steal",1);
}

void punch_me(object targ) {
    if(!objectp(TO) || !objectp(targ)) return;
    if(!present(targ->query_name(),ETO)) return;
    tell_room(ETO,"%^BOLD%^%^BLACK%^Etarena growls and grabs a fistful of "
+targ->QCN+"'s hair, pulling "+targ->QO+" closer and punching "+targ->QO+
" across the face with her %^RED%^c%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^aw"
"%^RESET%^%^RED%^e%^BOLD%^d %^BLACK%^gauntlets!%^RESET%^",targ);
    tell_object(targ,"%^BOLD%^%^BLACK%^Etarena growls and grabs a fistful of "
"your hair, pulling you closer and punching you across the face with her "
"%^RED%^c%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^aw%^RESET%^%^RED%^e%^BOLD%^d "
"%^BLACK%^gauntlets!%^RESET%^");
    targ->do_damage(targ->return_target_limb(),roll_dice(20,20));
    targ->set_paralyzed(12,"You're still dazed from the punch to the face!");
}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

void sunderit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sunder "+targ->query_name());
}

void shatterit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shatter "+targ->query_name());
}

void whirlit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("whirl "+targ->query_name());
}

void init(){
   ::init();
   if(!TP->query_invis() && (string)TP->query_gender() == "female"){
     tell_room(ETO,"%^BOLD%^%^BLACK%^Etarena speaks in a %^RESET%^low%^RED%^, "
"%^BOLD%^%^BLACK%^inf%^BOLD%^%^RED%^u%^RESET%^%^RED%^ri%^BOLD%^%^RED%^a"
"%^BOLD%^%^BLACK%^ted hiss:%^RESET%^ Leave now, whore!");
     kill_ob(TP,1);
   }
   return;
}
