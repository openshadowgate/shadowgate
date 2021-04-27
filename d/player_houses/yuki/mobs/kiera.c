// Crow captain - LoKi


#include <std.h>
#include <daemons.h>
inherit NPC;
int flag;
object ob;

void create() {
   ::create();
   set_name("captain");
   set_short("%^BLACK%^%^BOLD%^Takeda Kiera, B%^RESET%^l%^BLACK%^%^BOLD%^ack "+
   "Sw%^RESET%^a%^BLACK%^%^BOLD%^n%^RESET%^");
   set_id(({"captain","kiera","takeda kiera","black swan"}));
   set_long("%^BLACK%^%^BOLD%^Her lithe form covered in the black wrappings "+
   "of a close fitting suit, this woman reminds you instantly of a hunting "+
   "cat. Her motions are fluid and silent as she watches over similarly clad"+
   " soldiers going through motions. Her skin is %^RESET%^%^BOLD%^pure "+
   "alabaster%^BLACK%^%^BOLD%^, and long black hair is draped over her "+
   "shoulder in a long ponytail. Along the sleeves of her suit are "+
   "intricate %^RESET%^%^RED%^red feathers%^BLACK%^%^BOLD%^ denoting "+
   "her membership as a crow.  ");
   set_race("human");
   set_stats("intelligence",18);
   set_stats("wisdom",13);
   set_stats("strength",18);
   set_stats("charisma",16);
   set_stats("dexterity",20);
   set_stats("constitution",17);
   set_class("thief");
   set_mlevel("thief",35);
   set_guild_level("thief",35);
   set_alignment(4);
   set_gender("female");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(500);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(5, ({
"%^BLACK%^%^BOLD%^Kiera looks over, observing you quietly%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Two black clad warriors spar in complete silence as Kiera watches%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^kiera corrects a black clad warrior's stance and returns to watching'%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech purr in a soft voice");

    force_me("pose %^BLACK%^%^BOLD%^Standing before a group of soldiers%^RESET%^");
	
	ob = new("/d/common/obj/armour/cloak_hooded");
        ob->set_property("enchantment",4);
		ob->set_property("monsterweapon",1);
		ob->set_obvious_short("%^BLACK%^%^BOLD%^rag%^RESET%^"+
		"g%^BLACK%^%^BOLD%^ed b%^RESET%^l%^BLACK%^%^BOLD%^ac"+
		"k cl%^RESET%^o%^BLACK%^%^BOLD%^ak%^RESET%^");
        ob->move(TO);
    command("wear cloak");
    ob = new("/d/token_hunt/obj/low/maskdagger.c");
        ob->set_property("monsterweapon",1);
        ob->move(TO);
    command("wield dagger");
    ob = new("/d/token_hunt/obj/low/maskdagger.c");
        ob->set_property("monsterweapon",1);
        ob->move(TO);
    command("wield dagger");
	
	   set_monster_feats(({
        "ambidexterity",
      "two weapon fighting",
          "improved two weapon fighting",
          "greater two weapon fighting",
          "two weapon defense",
          "hardenedminions",
          "knockdown",
          "blindfight",
          "powerattack",
          "shatter",
          "sunder",
          "rush",
          "combat reflexes",
          "expertise",
          "disarm",
          "dodge",
          "mobility",
          "evasion",
          "scramble"
          }));
}

void catch_say(string message){
   if(strsrch(message,"crow") != -1) {
      call_out("reply_crow",1,TP,message);
   }
   if(strsrch(message,"swan") != -1) {
      call_out("reply_swan",1,TP,message);
   }
}

void reply_swan(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Keira waves to her students and they sit silently.\n");
    force_me("say I am Takeda Kiera. I followed my cousin here once I learned that "+
	"Bwana had been rebuilt.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^She smiles for a moment.\n%^RESET%^");
    force_me("say I am a Black Swan, and although Swan is done and gone, I follow my "+
	"cousin for he knows this realm better then any of us. We are stronger now then we ever were.");
    return 1;

}

void reply_crow(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Keira chuckles softly.\n");
    force_me("say We are the same force as Swan was, but with the cowards and idiots removed.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^She considers.\n%^RESET%^");
    force_me("say You will find things have changed for the better around here.");
    return 1;

}

