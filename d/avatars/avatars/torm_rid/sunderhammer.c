#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Hammer of Wood");
	set_id(({ "hammer", "warhammer", "wood hammer" }));
	set_short("%^ORANGE%^Ancient hammer of Wood");
	set_obvious_short("Hammer");
	set_long(
@AVATAR
%^ORANGE%^This ancient warhammer is carved out of a single piece of odd wood.  One could easily mistake it for a training replica.  Runes are carved along the shaft of the hammer, their meaning long forgotten.  The handle of the hammer is wrapped in a patchwork of %^GREEN%^green leaves%^ORANGE%^.  The head of the hammer is carved in a perfect cylinder shape, and a small spike, it also made of wood, on either side of the head, obviously there for damaging your opponent further.  The hammer is incredibly light.  A clear %^GREEN%^green %^BLUE%^aura%^ORANGE%^ surrounds the hammer.

AVATAR
	);
	set("read",
@AVATAR
%^ORANGE%^As you read the runes, they light up in a brilliant %^GREEN%^green %^ORANGE%^light.

%^GREEN%^Take heed to my blessing, protect the forest from all enemies it may have, let the life the forest holds continue to live and let nature thrive.

AVATAR
	);
     set("language","elven");	
        set_weight(10);
	set_value(1500);
	set_type("bludgeoning");
	set_prof_type("medium hammer");
	set_size(2);
	set_wc(2,4);
	set_large_wc(1,10);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
   if(interactive(TP) && (string)TP->query_name() != "sunder"){
      tell_object(TP,"The hammer does not recognize you "+
                     "as its owner and bursts into flames!");
      set_property("magic",1);
      ETO->do_damage("torso",roll_dice(3,6));
      set_property("magic",-1);
      TO->remove();
      return 0;
   }
	tell_room(ETP,"%^ORANGE%^As "+TP->query_cap_name()+" wields the hammer, he seems surprised at how the hammer feels in his hand.",TP);
	tell_object(TP,"%^ORANGE%^As you grasp this hammer you notice how light it is.  You tighten your grip around the handle of the hammer and prepare to defend the forest.");
	return 1;
}

int unwield_func(){
	tell_room(ETP,"%^ORANGE%^ "+TP->query_cap_name()+" Releases his grip on the hammer.",TP);
	tell_object(TP,"%^ORANGE%^You release your grip upon the hammer.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"%^ORANGE%^The head of the hammer seems to grow in weight as you swing towards your target.");
	tell_object(targ,"");
		return roll_dice(3,4)+-1;	}
}