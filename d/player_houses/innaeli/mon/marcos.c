#include <std.h> 
#include "../defs.h" 
inherit WEAPONLESS; 

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void create() { 
	object obj; 
	::create(); 
	set_name("Marcos the Cook"); 
	set_id(({"marcos","cook","marcos the cook","Marcos","sailor"})); 
	set_short("%^BOLD%^%^WHITE%^Marcos the Cook%^RESET%^"); 

	set_long("%^RESET%^Marcos is a retired sailor with the mouth "+
	"to prove it. His %^BOLD%^massive%^RESET%^ arms and chest are "+
	"covered in %^BOLD%^%^BLACK%^t%^BOLD%^%^GREEN%^a%^RESET%^"+
	"%^GREEN%^t%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^"+
	"o%^BOLD%^%^BLACK%^s%^RESET%^, and hes a bit thick around the "+
	"middle. This man has obviously seen his share of battles back "+
	"in his glory days, and the %^BOLD%^%^WHITE%^massive sword"+
	"%^RESET%^ at his side certainly makes you think twice about "+
	"challenging him. He is dripping in %^YELLOW%^gaudy jewelry"+
	"%^RESET%^, including a %^BOLD%^%^WHITE%^flawless %^RESET%^"+
	"%^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^b%^BOLD%^%^RED%^y "+
	"b%^RESET%^%^RED%^a%^BOLD%^%^RED%^n%^RESET%^%^RED%^d%^RESET%^. "+
	"He isnt much to look at, being big, bald, and missing an eye "+
	"as well as more than a couple teeth, but he knows how to cook "+
	"a fine meal.%^RESET%^"); 

	set_race("human"); 
	set_body_type("human"); 
	set_alignment(5); 
	set_class("fighter"); 
	set_mlevel("fighter",25); 
	set_gender("male"); 
	set_size(2); 
	set_hd(10,25); 
	add_money("gold",random(200)+15); 
	
	set_stats("strength",16); 
	set_stats("dexterity",15); 
	set_stats("constitution",18); 
	set_stats("intelligence",10); 
	set_stats("wisdom",10); 
	set_stats("charisma",10); 

	set_overall_ac(-5); 
	set_exp(3000); 
	set_max_hp((random(50)+350)); 
	set_hp(query_max_hp()); 
	set("aggressive",9); 
	set_damage(1,4); 
	set_attack_limbs(({"right hand","left hand"})); 
	set_attacks_num(2); 
	set_max_level(25); 
	set_property("swarm",1); 
	
	set_emotes(3,({"%^BOLD%^%^WHITE%^Marcos chases a %^BOLD%^"+
	"%^BLACK%^fly%^BOLD%^%^WHITE%^ around the kitchen, swatting at "+
	"it with a spatula.%^RESET%^","%^BOLD%^%^WHITE%^Muttering and "+
	"cursing, Marcos chops down some %^BOLD%^%^GREEN%^v%^RESET%^"+
	"%^GREEN%^e%^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^e%^BOLD%^"+
	"%^GREEN%^t%^RESET%^%^GREEN%^a%^YELLOW%^b%^RESET%^%^ORANGE%^l"+
	"%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s%^BOLD%^%^WHITE%^ as if "+
	"they just insulted his mother.%^RESET%^","%^BOLD%^%^WHITE%^"+
	"Marcos yanks a %^BOLD%^%^BLACK%^pot%^BOLD%^%^WHITE%^ off the "+
	"stove and throws it at a %^BOLD%^%^BLACK%^rat%^BOLD%^%^WHITE%^ "+
	"scurrying across the floor. The rat vanishes into the pantry!"+
	"%^RESET%^"}),0); 
	
	set_funcs(({"hack"}));
      set_func_chance(30);
} 

void init() {
   ::init();
   add_action("request_fun","request");
}

void hack(object targ) {
	tell_room(ETO,"%^BOLD%^%^RED%^Marcos grabs up one of the "+
	"kitchen knives and stabs it into "+targ->query_cap_name()+
	" with brutal force!%^RESET%^");
	tell_object(targ, "%^BOLD%^%^RED%^Marcos grabs up one of the "+
	"kitchen knives and stabs you with brutal force!%^RESET%^");
	targ->do_damage(targ->return_target_limb(),roll_dice(10,10));
	return 1;
}
	
void die(object obj) {
    tell_room(EETO,"%^RED%^Marcos gasps, staggers and falls face "+
	"first into the compost pile!%^RESET%^");
    new(OBJ"bsbrubyring")->move(TO);
    ::die(obj);
}

int request_fun(string str) {
   if(!str) return notify_fail("Marcos just ignores you.\n");
   if(str != "ring") return notify_fail("Marcos just ignores you.\n");
   if((string)TP->query_name() != "innaeli" && (string)TP->query_name() != "anson" && !avatarp(TP))
     return notify_fail("Marcos just ignores you.\n");
   tell_object(TP,"Marcos pauses long enough in his work to pass you a ring from his pocket.");
   tell_room(ETO,"Marcos pauses from his work to pass something to "+TP->QCN+".");
   new(OBJ"bsbrubyring")->move(TO);
   force_me("give ring to "+TP->query_name()+"");
   return 1;
}