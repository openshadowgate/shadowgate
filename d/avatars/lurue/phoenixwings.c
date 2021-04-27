#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker;

void create(){
	::create();
	set_name("winged bracers");
	set_id(({ "bracers", "bracer", "phoenix wings", "phoenix wings", "phoenix wing bracers", "phoenixwings" }));
	set_short("%^BOLD%^%^RED%^Ph%^YELLOW%^o%^RESET%^%^ORANGE%^e%^YELLOW%^n%^RED%^ix W%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^g%^RED%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^w%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^g%^RED%^ed br%^YELLOW%^a%^RESET%^%^ORANGE%^c%^YELLOW%^e%^RED%^rs%^RESET%^");
	set_long("%^RED%^Forged of %^ORANGE%^leather%^RED%^, %^CYAN%^steal %^RED%^and %^YELLOW%^spun-gold thread%^RESET%^%^RED%^, these magnificent bracers are the clear work of ages long past. Shaped as a set fiery wings, each bracer extends upward along the arm. The %^YELLOW%^yellow%^RED%^, red, %^RESET%^%^RED%^and %^ORANGE%^orange %^RED%^leathers are veined with %^YELLOW%^golden stitches%^RESET%^%^RED%^, while a sheet of %^CYAN%^shaped "
"steel %^RED%^is affixed to their backs, making the feathers, and thus the bracers, sturdy enough for even the most vicious of battles. Looking close you see that every feather is %^WHITE%^unique%^RED%^, just as they might be in nature.  The stylized, wing motif extends from wrist toward the elbow in an arching sweep that carries the final feather's tip half way up the biceps before it gives way.  In motion, these bracers are nothing short of %^YELLOW%^magnificent %^RESET%^%^RED%^to watch as they appear to swoop, dive and pivot in an aerial display.%^RESET%^");
	set("read",
@AVATAR


%^RED%^%^BOLD%^I%^YELLOW%^n%^RESET%^%^ORANGE%^v%^YELLOW%^o%^RED%^ke%^RED%^ the fires within
%^BOLD%^%^RED%^and you shall be re%^YELLOW%^n%^RESET%^%^ORANGE%^e%^YELLOW%^w%^RED%^ed%^RESET%^



AVATAR
	);
     set("langage","firbolg");	set_weight(10);
	set_value(3500);
	set_lore("The ancient craft that was put into the creation of these bracers has been lost in time.  All that is left is the tale of one firbolg warrior named Aedanke who wore a full suit of such craft.  A woodsman of the Morninglord he was said to have possessed the gift of flight as well as the blessing of bringing life to those places where there was none.  Though a mammoth of a man in height and strength, Aedanke was reserved "
"about harming anyone, preferring to find peaceful solutions to the problems that were presented to him in his travels.  But when pressed, the flames of his rage were said to encompass his enemy without remorse.  What happened to Aedanke is unknown, but one tale says he was slain by a band of ice giants in offering to Auril.  When the last of his life ran out, Aedanke burst into flames and the last fire was so intense that it consumed his enemy and the temple of frost wherein he had been slain.");
	set_property("lore difficulty",23);
	set_type("bracer");
	set_limbs(({ "left arm", "right arm" }));
	set_size(2);
      set_ac(1);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

void init() {
   ::init();
   add_action("healz","invoke");
}

int wear_func(){
   if((string)ETO->query_diety() != "lathander") {
     tell_object(ETO,"The bracers just don't fit you.");
     return 0;
   }
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" slips a set of %^RESET%^"+query_short()+" %^YELLOW%^onto their arms.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You slip the %^RESET%^"+query_short()+" %^YELLOW%^on and your arms feel light as air!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" sighs as they slip the %^RESET%^"+query_short()+"%^YELLOW%^ from their arms.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^Your arms feel heavier now as you slip the %^RESET%^"+query_short()+"%^YELLOW%^ from your arms.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^YELLOW%^The wings of "+ETOQCN+"'s %^RESET%^"+query_short()+"%^YELLOW%^ flare outward creating a shield against "+who->QCN+"'s attack!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^Suddenly the wings of the %^RESET%^"+query_short()+"%^YELLOW%^ unfurl and move your arm quickly to block "+who->QCN+"'s attack!%^RESET%^");
	tell_object(who,"%^YELLOW%^The wings of "+ETOQCN+"'s %^RESET%^"+query_short()+"%^YELLOW%^ flare outward creating a shield against your attack!%^RESET%^");
return (damage*0)/100;	}
}

int healz(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     notify_fail("You need to be wearing the bracers.");
     return 0;
   }
   if(!str) {
     notify_fail("Try to <invoke bracers>.");
     return 0;
   }
   if(str != "bracers") {
     notify_fail("Try to <invoke bracers>.");
     return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the power of the bracers today.");
     return 1;
   }
   tracker = time() + 28800;
   new("/cmds/priest/_heal")->use_spell(TP,TP,25);
   return 1;
}
