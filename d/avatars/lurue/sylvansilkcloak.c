#include <std.h>
inherit ARMOUR;

int OWNED, tracker;
string owner;

void create(){
	::create();
	set_name("silk cloak");
	set_id(({ "cloak", "multihued cloak", "sylvan cloak", "cloak of the sylvan grove" }));
	set_short("%^RESET%^%^GREEN%^s%^YELLOW%^i%^RESET%^%^ORANGE%^l%^GREEN%^k c%^RED%^l%^GREEN%^o%^YELLOW%^a%^RESET%^%^GREEN%^k o%^ORANGE%^f %^GREEN%^t%^RED%^h%^GREEN%^e s%^YELLOW%^y%^RESET%^%^ORANGE%^l%^GREEN%^v%^RED%^a%^GREEN%^n g%^YELLOW%^r%^RESET%^%^GREEN%^o%^RED%^v%^GREEN%^e %^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^a m%^YELLOW%^u%^RESET%^%^ORANGE%^l%^GREEN%^t%^MAGENTA%^i%^RED%^h%^GREEN%^u%^YELLOW%^e%^RESET%^%^GREEN%^d silk cloak%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^A stylized %^ORANGE%^bronze clasp %^GREEN%^in the shape of a pair of intertwining trees fastens this m%^YELLOW%^u%^RESET%^%^ORANGE%^l%^GREEN%^t%^MAGENTA%^i%^RED%^h%^GREEN%^u%^YELLOW%^e%^RESET%^%^GREEN%^d cloak closed.  Made of thousands of pieces of silk, each piece has been delicately edged in %^YELLOW%^golden thread%^RESET%^%^GREEN%^, outlining the many different leaf like patterns upon the garment.  %^YELLOW%^Golds %^RESET%^%^GREEN%^and %^ORANGE%^ambers%^GREEN%^, %^RED%^reds %^GREEN%^and %^MAGENTA%^burgundies%^GREEN%^, greens and %^BOLD%^emeralds%^RESET%^%^GREEN%^ all blend together to create a dynamic display that is at once stunning and at the exact same time demure.  Lined with a pale %^BOLD%^grass-green %^RESET%^%^GREEN%^sheath of silk, the garment is heavy, but fluid in its movements. %^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(5000);
	set_lore(
@AVATAR
This garment was commissioned by the Clothiers of Seneca as a reward for the second prize placement in the first annual Adventurous Summer contest.  The cloak, said to have been fashioned by the fey of Moonstone Valley is rumored to have been enchanted with at least one gift by the creatures that live there.  Though only the true owner of the garment was given the true measure of the cloak's magic. 

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You wrap the silken cloak around your shoulders and feel a soft breeze stir your mind with thoughts of drifting upon it free as can be.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^In your mind, you settle back upon the ground, leaving the gentle breeze behind.%^RESET%^");
      if(present("invisobx999",ETO)) present("invisobx999",ETO)->show_up();
	return 1;
}

void init() {
   ::init();
   add_action("hide_fun","drift");
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED && !avatarp(TP)) {
     owner = TPQN;
     OWNED = 1;
   }
}

int hide_fun(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     notify_fail("You need to be wearing the cloak.\n");
     return 0;
   }
   if(str) {
     notify_fail("Try to <drift>.\n");
     return 0;
   }
   if (ETP->query_property("indoors")) {
     notify_fail("This just wouldn't work indoors.\n");
     return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the power of the cloak today.");
     return 1;
   }
   tracker = time() + 28800;
   new("/d/avatars/lurue/spells/_drift")->use_spell(TP,0,25);
   return 1;
}