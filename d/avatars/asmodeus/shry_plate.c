// reward plate for shry
#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";
#define WAIT_TIME 43200

int used_time;



void create(){
        ::create();
        set_name("Tears of the Moon");
        set_id(({ "plate", "heavy titanium plate", "fullplate", "tears", "tears of the moon", "armor"}));
        set_short("%^RESET%^%^BOLD%^Te%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^rs "+
		"of t%^RESET%^h%^RESET%^%^CYAN%^e %^RESET%^%^BOLD%^Mo%^RESET%^o"+
		"%^BOLD%^n%^RESET%^");
        set_obvious_short("%^RESET%^%^BOLD%^he%^RESET%^a%^RESET%^%^BOLD%^"+
		"vy ti%^RESET%^t%^RESET%^%^BOLD%^anium pla%^RESET%^t%^RESET%^%^BOLD%^"+
		"e%^RESET%^");
        set_long("%^RESET%^%^BOLD%^Crafted from interwoven %^RESET%^he%^RESET%^%^BOLD%^a%^RESET%^v"+
		"y %^BLACK%^%^BOLD%^ti%^RESET%^t%^BLACK%^%^BOLD%^ani%^RESET%^u%^BLACK%^%^BOLD%^m pla%^RESET%^"+
		"t%^BLACK%^%^BOLD%^es%^RESET%^%^BOLD%^, this set of full plate should be too heavy to wear, "+
		"though as you look at it, you can sense that it thrums with %^RESET%^%^CYAN%^power%^RESET%^%^BOLD%^"+
		". All along the plates are %^RESET%^engravings%^BOLD%^ of stars, and moons. Underneath the plate is "+
		"a layer of silver chain. What is odd about the plate is that it seems to be constantly %^CYAN%^wet"+
		"%^WHITE%^ with a layer of m%^RESET%^i%^RESET%^%^BOLD%^lky white d%^RESET%^e%^RESET%^%^BOLD%^w that"+
		" runs down the plates.%^RESET%^");
        set_property("enchantment",5);
		set_value(10000);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        set_struck((:TO,"strike_func":));
		set_property("lore difficulty",15);
        set_lore("%^RESET%^%^BOLD%^The Tears of the Moon was created for a lycan general of Selune's faith to aid her in "+
		"her many conquests against Shar's forces. The group she led was known for journying deep into "+
		"Shar's territories to fight, and would be far from the temples of Selune for months on end.%^RESET%^ ");
}

void init(){
   ::init();
   set_size(TP->query_size());
   if((int)TO->query_property("enchantment") < 5){
      TO->remove_property("enchantment");
          TO->set_property("enchantment",5);
   }
   if(living(ETO)){
      add_action("tears_fun","gather");
   }
}

int tears_fun(){
   if(!objectp(ETO)) return 0;
   if(!(query_worn())){
      tell_object(ETO,"%^RESET%^%^CYAN%^You need to wear the plate to "+
	  "be able to gather the water%^RESET%^.");
      return 1;
   }
   if(WAIT_TIME > (time() - used_time)){
      tell_object(ETO,"%^RESET%^%^CYAN%^You cant seem to gather enough "+
	  "water right now.%^RESET%^");
      return 1;
   }
   tell_room(EETO,"%^RESET%^%^CYAN%^As "+ETOQCN+" %^RESET%^%^CYAN%^runs "+
   "their hands across the armor, they slowly chant!%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^CYAN%^You run your hands along the "+
   "plate and gather the %^RESET%^dewy liquid%^RESET%^%^CYAN%^ in your "+
   "hands. You feel the blessings of %^BOLD%^Selune%^RESET%^%^CYAN%^ "+
   "fill your heart as the water drips on the ground!");
   ETP->set_property("blessed","selune");
   used_time = time();
      return 1;
}



int wear_func(){
        tell_room(EETO,"%^RESET%^"+ETOQCN+" slowly dons the "+query_short()+".",ETO);
        tell_object(ETO,"You slowly don the "+query_short()+" and feel the water flow "+
		"on the armor. You realize you could '%^CYAN%^gather%^RESET%^' the water");
        return 1;
}
int remove_func(){
        tell_room(EETO,"As "+ETOQCN+" pulls off the "+query_short()+".",ETO);
        tell_object(ETO,"You remove the "+query_short()+".");
        return 1;
}
int strike_func(int damage, object what, object who){
        if(random(1000) < 100){
        tell_room(EETO,"%^BLACK%^%^BOLD%^As "+who->QCN+" %^BLACK%^%^BOLD%^strikes"+
"		"+ETOQCN+"%^BLACK%^%^BOLD%^, their blow glances off the wet "+
"plates.%^RESET%^",({ETO,who}));
        tell_object(ETO,"%^BLACK%^%^BOLD%^As "+who->QCN+"%^BLACK%^%^BOLD%^'s"+
"		blow strikes you, it glances off the wet plate.%^RESET%^");
        tell_object(who,"%^BLACK%^%^BOLD%^As you strike "+ETOQCN+"%^BLACK%^%^BOLD%^ "+
		"the blow is deflected off by the wet plate.%^RESET%^");
return(-1)*(damage);
}
}
