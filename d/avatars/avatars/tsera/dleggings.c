#include <std.h>
inherit PARMOUR;

void create()
{
   ::create();     
      set_name("%^BOLD%^%^BLACK%^A pair of dark black leather pants%^RESET%^");
      set_short("%^BOLD%^%^BLACK%^A pair of dark black leather pants%^RESET%^");
      set_id(({"leather pants","pants"}));
      set_long("%^BOLD%^%^BLACK%^These tight leather pants have been made with extraordinary craftsmanship."
"  Though they are designed to fit the wearer snugly enough to show off every curve or muscle hidden beneath,"
" the leather is supple enough that they would not hinder any movement.  A small pocket lines the inside of the"
" pants and is made in such a way that its contents would be difficult to detect from the outside.%^RESET%^\n");
      set_weight(3);
      set_value(1000);
      set_ac(0);
      set_property("enchantment",1);
      set_type("clothing");
      set_limbs(({"right leg","left leg"}));
      set_wear((:this_object(),"wearme":));
      set_remove((:this_object(),"unwearme":));
     set_max_internal_encumbrance(25);
}
int wearme(string str){
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" smiles as "+ETO->query_subjective()+" slides into the tight fitting pants.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^BLACK%^Ah yes, you are quite sure that these leggings were made just for you.%^RESET%^");
      ETO->add_stat_bonus("charisma",1);
      return 1;
}
int unwearme(string str){
   ETO->add_stat_bonus("charisma",-1);
   return 1;
}
void init(){
    ::init();
  if(!objectp(TP)) return;
  if (!objectp(ETO)) return;
  if (TP != ETO) return;
  if(interactive(TP) && !avatarp(TP)) {
     set_size(TP->query_size());
  }
}
