#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "long","tsvarani sword","tsvarani longsword"}));
   set_name("gilded longsword");
   set_short("A%^BLUE%^ Tsvarani hunter's l%^RESET%^o%^BLUE%^ngs%^BOLD%^%^YELLOW%^w%^RESET%^o%^BLUE%^rd");
    set_long(
      "A long, tapered triangular blade, with ancient Tsvarani runes carved along the length. The hilt is"
     +" bound with strips of rayskin, and a small metal charm can be glimpsed beneath the bindings. The"
     +" sword is clearly balanced for one handed use."
    );
    set_weight(7);
    set_size(2);
    set("value", 100);
    set_wc(1,8);
    set_large_wc(1,12);
    set_type("slashing");
    set_property("enchantment",2);
    set_wield((:TO,"extra_wield":));
    set_hit((:TO,"extra_hit":));
}
int extra_wield(){
    if(!ETO) return 0;
  if(!interactive(TP)) return 1;
    if((int)ETO->query_level()<15){
  write("You don't feel you've earned the right to this officer's sword just yet.");
  tell_room(environment(ETO),""+ETO->query_cap_name()+" sighs as "+ETO->query_subjective()+" looks at a fine blade in "+ETO->query_possessive()+" hands.",ETO);
	return 0;
    }
    write("You admire the fine gold work as you wield the sword.");
  tell_room(environment(ETO),ETO->query_cap_name()+" admires the fine gold runes on their longsword for a moment.",ETO);
    return 1;
}
int extra_hit(object ob){
   if(!objectp(ob)) return 1;
    if(!random(3)){
	tell_object(ETO,"%^BLUE%^The hunter's blade cuts deeply into "+ob->query_cap_name()+"!");
	tell_object(ob,"%^BLUE%^"+ETO->query_cap_name()+"s hunter's blade slashes deeply into you!");
   tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+" slashes deeply into "+ob->query_cap_name()+" with a gold gilded sword!",(({ETO,ob})));
	return (random(4)+1);
    }
    return 1;
}
