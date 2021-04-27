#include <std.h>
#include <daemons.h>
#include "../daelmas.h"
inherit MONSTER;

int xx,FLAG,HFLAG,timer;

create() {
   object ob;
   ::create();
   set_name("Rubin Half-leg");
   set_id(({"rubin","Rubin","human","rubin half-leg","Rubin Half-leg"}));
   set_short("Rubin Half-leg");
   set_long("This human looks to have been through more than one "+
   	"battle and come out the worse for it.  His leftleg is missing "+
   	"below the knee and replaced with an ivory peg-leg.  His face is "+
   	"scarred, but clean shaven and his gray hair is clean, but unkempt.  "+
   	"He has a long scar that starts above his hairline over his right "+
   	"eye and continues downward over the eye and below his mouth.  The "+
   	"right eye is cloudy and apparently without vision.  He is otherwise "+
   	"very clean and wearing clean silk clothes of bright colors."
    );
    set_hd(25,10);
    set_level(25);
    set_class("fighter");
    set_guild_level("fighter",25);
    set_class("thief");
    set_mlevel("thief",25);
    set_body_type("human");
    set_alignment(3);
    set_race("human");
    set_gender("male");
    set_ac(2);
    set_size(2);
    set_stats("strength",18);
    set_stats("dexterity",17);
    set_stats("charisma",12);
    set_stats("constitution",12);
    set_stats("wisdom",12);
    set_stats("intelligence",18);
    set_exp(2500);
    set_max_hp(200);
    set_hp(query_max_hp());
    set_achats(3,({
		"%^BOLD%^%^RED%^Rubin growls: %^RESET%^Ye 'r black 'earted matey!",
		"%^BOLD%^%^RED%^Rubin growls: %^RESET%^Rubie'll cut out yer gizzard!",
		"%^BOLD%^%^RED%^Rubin growls: %^RESET%^Landlubbers!!",
		"%^BOLD%^%^RED%^Rubin growls: %^RESET%^Tha master'll take ye down!",
 		"%^BOLD%^%^RED%^Rubin growls: %^RESET%^Rube'll cut yer 'eart out with a spoon!!",
   	}),0);
    set_emotes(1,({
		"Rubin hums a sailing chanty to himself.",
		"Rubin pulls a rag from his pockets and dusts the furniture half-heartedly.",
		"Rubin cough loudly and harks something up spitting it into his rag.",
		"Rubin produces a rag from his pocket and blows his nose loudly.",
		"%^BOLD%^%^MAGENTA%^Rubin growls: %^RESET%^wipe yer feet. Rube 'as ta live "+
			"on land, doesn't 'ave to sweep it all",
		"%^BOLD%^%^MAGENTA%^Rubin growls: %^RESET%^Wot bizness ye got's in 'ere?",
		"Rubin put a very dirty cleaning rag in his pocket.",
		"%^BOLD%^%^MAGENTA%^Rubin growls: %^RESET%^Mind ye no be messin' the place up.",
		"%^BOLD%^%^CYAN%^Rubin whispers to you: %^RESET%^If'n I were you. "+
			"I'd be scarce afore tha Cap'n got back.",
   }),0);
	new("/d/azha/obj/mr_ring")->move(TO);
    	command("wear ring");
  	new(DOBJ+"marble_key")->move(TO);
  	new("/d/shadow/obj/misc/pouch.c")->move(TO);
  		command("wear pouch");
  		command("put key in pouch");
   ob = new("/d/tharis/obj/wrist_sheath.c");
   	ob->set_property("monsterweapon", 1);
   	ob->move(TO);
   ob = new("/d/attaya/obj/screamer.c");
   	ob->set_property("monsterweapon", 1);
   	ob->move(TO);
   command("wear sheath");
   command("put screamer in sheath");
   add_search_path("/cmds/fighter");
   add_search_path("/cmds/thief");
  	set_property("swarm",1);
  	set_property("full attacks",1);
  	command("speak common");
  	command("speech %^BOLD%^%^MAGENTA%^growl");
   set_scrambling(1);
   set_thief_skill("move silently", 95);
   set_thief_skill("hide in shadows", 95);
   set_speed(35);
   FLAG = 0;
	HFLAG = 0;
}
void init(){
	string mname=TP->query_name();
   ::init();

	add_action("get_em","ask");

   if(avatarp(TP) || TP->query_invis()) return;
	if(mname == "vaser"){
		command("bow vaser awkwardly with a gap-toothed smile");
		command("say welcome 'ome Cap'n!");
		return;
	}else{
		command("say 'ey, were ye think yer goin'?");
		command("emote raises his eyebrow at you.");
		command("say get gone afore I call tha Cap'n!");
		return;
	}
}
int get_em(string str) {
	string mname=TP->query_name();

   if(!str) {
     	notify_fail("%^BOLD%^%^CYAN%^Ask who for what?\n");
     	return 0;
   }
	if(str == "rubin for key" || str == "Rubin for key" || str == "for key"){
		if( mname == "vaser" || mname == "diego"){
			if (FLAG == 0){
				tell_room(ETP,""+TPQCN+" asks Rubin for something.\n");
				command("get key from pouch");
				command("give key to vaser");
				command("give key to diego");
				command("say 'ere ye go Cap'n.");
				FLAG = 1;
				return 1;
			}else{
				tell_room(ETP,""+TPQCN+" asks Rubin for something.\n");
				command("whisper vaser %^BOLD%^uh Cap'n, Rubie ain't got no key right now.");
				command("whisper diego %^BOLD%^uh Cap'n, Rubie ain't got no key right now.");
				return 1;
			}
		}else{
			tell_room(ETP,""+TPQCN+" asks Rubin for something.\n");
			command("emote laughs at you.");
			command("say mate, yer not tha Cap'n so ferget it!!");
  			return 1;
    	}
  	}
}
void heart_beat(){
    	::heart_beat();
    	timer++;
    	if(timer > 100){
      	timer = 0;
      	if(!random(5)){
      		if(HFLAG = 0){
      			command("hide_in_shadows");
      			HFLAG = 1;
      			return 1;
      		}else{
      			command("step");
      			HFLAG = 0;
      			return 1;
      		}
      	}
    	}
}
void reset(){
	::reset();
	if(FLAG == 1){
		FLAG = 0;
	  	new(DOBJ+"marble_key")->move(this_object());
	  	command("put key in pouch");
		return;
	}
}
