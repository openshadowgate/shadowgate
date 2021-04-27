// Crow captain - LoKi


#include <std.h>
#include <daemons.h>
inherit NPC;
int flag;
object ob;

void create() {
   ::create();
   set_name("captain");
   set_short("%^BLACK%^%^BOLD%^Hitokiri Joseph, Ca%^RESET%^%^MAGENTA%^"+
   "p%^BLACK%^%^BOLD%^t%^RESET%^a%^BLACK%^%^BOLD%^in of the C"+
   "r%^RESET%^%^MAGENTA%^o%^BLACK%^%^BOLD%^w G%^RESET%^u%^BLACK%^%^BOLD%^ard");
   set_id(({"captain","hitokiri","hitokiri Joseph","joseph"}));
   set_long("%^RESET%^%^ORANGE%^Standing at an impressive six feet, "+
   "this barrel chested man looks to have formidable strength. He "+
   "wears %^RESET%^light chain armor%^RESET%^%^ORANGE%^ with "+
   "%^BLACK%^%^BOLD%^large shoulderplates%^RESET%^%^ORANGE%^ "+
   "adorned with reliefs of %^RESET%^feathers%^RESET%^%^ORANGE%^ "+
   "etched in them. Across his back flows a %^RESET%^%^BOLD%^long "+
   "white cloak%^RESET%^%^ORANGE%^ also adored with a "+
   "%^BLACK%^%^BOLD%^black relief%^RESET%^%^ORANGE%^ of a feather. "+
   "His gruff weathered features remind you of a man who has "+
   "worked every day in his life for what he has, and his sun "+
   "blasted face has the look of the fishermen of Torm. "+
   "Striking %^BLUE%^blue eyes%^RESET%^%^ORANGE%^ watch everything "+
   "around him. The two swords in his hands rest casually, yet "+
   "ready.%^RESET%^");
   set_race("human");
   set_stats("intelligence",13);
   set_stats("wisdom",13);
   set_stats("strength",20);
   set_stats("charisma",10);
   set_stats("dexterity",18);
   set_stats("constitution",19);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_guild_level("fighter",35);
   set_alignment(4);
   set_gender("male");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(500);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(5, ({
"%^BLACK%^%^BOLD%^Looking over at some soldiers fighting, Hitokari "+
"grimaces as a blow is dealt%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Several pairs of soldiers spar nearby%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Hitokari commands three soldiers to enage a "+
"single veteran, watching them learn to fight together'%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech intone in a gruff commanding voice");

    ob = new("/d/common/obj/armour/fullplate");
       ob->move(TO);
       ob->set_property("monsterweapon",1);
       ob->set_obvious_short("%^BLACK%^%^BOLD%^etched shoulderplates%^RESET%^");
       command("wear plate");

	ob = new("/d/common/obj/armour/cloak_hooded");
        ob->set_property("enchantment",4);
		ob->set_property("monsterweapon",1);
		ob->set_obvious_short("%^BLACK%^%^BOLD%^rag%^RESET%^"+
		"g%^BLACK%^%^BOLD%^ed b%^RESET%^l%^BLACK%^%^BOLD%^ac"+
		"k cl%^RESET%^o%^BLACK%^%^BOLD%^ak%^RESET%^");
        ob->move(TO);
    command("wear cloak");

    ob = new("/d/token_hunt/obj/low/stormrapier.c");
       ob->move(TO);
       ob->set_property("monsterweapon",1);
       command("wield sword");

    force_me("pose %^BLACK%^%^BOLD%^Watching soldiers spar%^RESET%^");
	
	   add_search_path("/cmds/feats");
   set_monster_feats(({
          "shieldbash",
          "shieldwall",
          "deflection",
          "counter",
          "toughness",
          "improved toughness",
          "damage resistance",
          "knockdown"
          "powerattack",
          "shatter",
          "sunder",
          "rush"
   }));

}

void catch_say(string message){
   if(strsrch(message,"can I train") != -1) {
      call_out("reply_train",1,TP,message);
   }
   if(strsrch(message,"swan") != -1) {
      call_out("reply_swan",1,TP,message);
   }
   if(strsrch(message,"crow") != -1) {
      call_out("reply_crow",1,TP,message);
   }
}

void reply_train(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Hitokiri looks over.\n");
    force_me("say You are welcome to watch the sparring, but "+
	"unless you have someone to fight, then you just watch.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^He returns his attention "+
	"to one specific pair fighting and grimaces.\n%^RESET%^");
    force_me("say Come on! Parry, then back right then attack!");
    return 1;

}

void reply_swan(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Hitokiri glances over.\n");
    force_me("say I joined swan a few years back after Kyla saved my family "+
	"from some nasty business in Torm. I've been fighting all my life, so "+
	"this is the perfect place for me. I hold the rank of captain, and I "+
	"train the regular forces.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^He looks around the courtyard.\n%^RESET%^");
    force_me("say Even when we split into two, crows and swans, I'll stick with Takeda.");
    return 1;

}

void reply_crow(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Hitokiri appraises you.\n");
    force_me("say What happened in the family is our business, we are crows now.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^He looks at his soldiers.\n%^RESET%^");
    force_me("say We're stronger now.");
    return 1;

}

