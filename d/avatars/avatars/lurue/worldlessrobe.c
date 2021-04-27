#include <std.h>
#include <daemons.h>
inherit PARMOUR;

int tracker;

void create(){
	::create();
	set_name("dark robe");
	set_id(({ "robe", "worldless robe", "heavy robe", "dark robe" }));
	set_short("%^RESET%^%^MAGENTA%^Worldless Robe%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a heavy robe of thick velvet%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^BLACK%^The fabric of this robe is thick and soft, enveloping the wearer in a heavy blanket of %^RESET%^%^MAGENTA%^dark velvet%^BOLD%^%^BLACK%^.  Far more fabric then a robe might normally have, the garment is surprisingly light.  The excellent tailoring has designed it so that the bulk of the fabric is evenly balanced over the wearer's shoulders.  Large volumous sleeves drape the arms and conceal small pockets where a few items could easily be hidden.  Oddly, the edges of the fabric appear frayed and tattered, but upon closer inspection, it can be seen that instead of tattering, the material turns %^RESET%^%^MAGENTA%^misty %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^vanishes%^BOLD%^%^BLACK%^, leaving one to wonder just what sort of fabric this might be. %^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(25000);
	set_lore(
@AVATAR

%^BOLD%^%^BLACK%^When Callista traveled to the "Lich of Attaya's" tower she brought with her the fabled %^RESET%^%^MAGENTA%^Times Cut Dagger%^BOLD%^%^BLACK%^, a relic said to be able to cut the fabric of time and space itself.  This blade she is said to have drawn when she fought the Lich, and yet, not even the famed assassin could wield the weapon properly and as she slashed with it, the weapon came free of her hand.  As it did, it cut a void into the world and fell through, nearly taking her with it.  She recovered, but the loss of the dagger was a harsh blow that sent her scrambling to escape.  After the epic battle, the Lich took the strip of void and blended it with his magic to create a fabric that allowed him to phase through time and space.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_max_internal_encumbrance(30);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      tracker = 0;
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip the robe on and feel like you could just %^RESET%^%^MAGENTA%^step%^BOLD%^%^BLACK%^ into another world.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The heavy fabric slides from your shoulders like water, spilling about your arms in heavy folds.%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("step_fun","step");
}

int step_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the robe.");
     return 1;
   }
   if(str) {
     tell_object(TP,"You should use <step>.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"The robe's power is already spent today.");
     return 1;
   }
   tracker = time() + 28800;
   new("/cmds/wizard/_blink")->use_spell(TP,0,30);
   return 1;
}