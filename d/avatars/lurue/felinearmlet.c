#include <std.h>
inherit ARMOUR;
int tracker;

void create(){
	::create();
	set_name("armlet");
	set_id(({ "armlet", "silver armlet", "armlet of the feline", "feline armlet", "arm let", "armband", "arm band" }));
	set_short("%^BOLD%^%^WHITE%^Armlet of the %^BLACK%^F%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^li%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^WHITE%^armband%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Designed to be worn on the upper arm around the biceps, the %^BLACK%^s%^RESET%^i%^BOLD%^"
"%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^WHITE%^wire has been pounded into a thin wide strip and then looped around "
"itself several times in a tight upward spiraling coil.  At the top of this coil the metal has been folded back and "
"around on itself, forming a loop through which a shard of smoothed %^RESET%^%^GREEN%^peridot %^BOLD%^%^WHITE%^has been "
"inserted.  The end of the coil terminates in an inner looping spiral.  Able to be adjusted to fit the wearer's arm the "
"metal seems to expand or shorten on its own so that the %^BLACK%^<%^RESET%^%^GREEN%^9%^BOLD%^%^BLACK%^> %^WHITE%^hoops "
"are preserved.%^RESET%^");
	set_weight(3);
	set_value(1500);
	set_lore("Legends tell of a wizard whose fondness for her feline companion caused her to create several items which "
"were directly influenced by her familiar.  This armband is said to be one of those many items.  Fashioned after one of "
"the best known traits, the coils symbolize the nine lives of a cat and the item itself is said to hold a property that "
"aids the lives of those who wear it.");
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
      tracker = 9;
}

int wear_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^If you %^RESET%^%^GREEN%^meow%^BOLD%^%^BLACK%^ like a cat, then you might have the %^RESET%^%^GREEN%^lives%^BOLD%^%^BLACK%^ of a cat.%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("meow_fun","meow");
}

int meow_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You must be wearing the armlet to activate it.");
     return 1;
   }
   if(str) {
     tell_object(TP,"Just %^GREEN%^meow%^RESET%^ like a cat!");
     return 1;
   }
   if(!tracker) {
     tell_object(TP,"There are no hoops left on the armlet, its power is spent.");
     return 1;
   }
   tracker--;
	set_long("%^BOLD%^%^WHITE%^Designed to be worn on the upper arm around the biceps, the %^BLACK%^s%^RESET%^i%^BOLD%^"
"%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^WHITE%^wire has been pounded into a thin wide strip and then looped around "
"itself several times in a tight upward spiraling coil.  At the top of this coil the metal has been folded back and "
"around on itself, forming a loop through which a shard of smoothed %^RESET%^%^GREEN%^peridot %^BOLD%^%^WHITE%^has been "
"inserted.  The end of the coil terminates in an inner looping spiral.  Able to be adjusted to fit the wearer's arm the "
"metal seems to expand or shorten on its own so that the %^BLACK%^<%^RESET%^%^GREEN%^"+tracker+"%^BOLD%^%^BLACK%^> "
"%^WHITE%^hoops are preserved.%^RESET%^");
   TP->force_me("emote meows like a cat!");
   new("/cmds/priest/_heal")->use_spell(TP,TP,30);
   return 1;
}