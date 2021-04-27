#include <std.h>
inherit"/std/armour";

void create(){
   ::create();
   set_name("wizard's hat");
   set_id(({"hat","wizard's hat","wizard hat","suede hat"}));
   set_short("%^RESET%^%^CYAN%^A %^BLUE%^midnight blue %^CYAN%^suede wizard's hat%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This %^BLUE%^midnight blue %^CYAN%^hat is "
"modelled after the classical wizard's hat.  The tall conical hat is made out "
"of %^BLUE%^midnight blue %^CYAN%^suede.  The body of the hat itself is rather "
"soft, allowing it to drape in soft folds, though the point at the top still "
"remains very stiff and straight.  A wide brim helps to shield the wearer from "
"the elements and bright lighting.  A matching %^BLUE%^midnight blue "
"%^CYAN%^velvet band with a decorative %^YELLOW%^brass %^RESET%^%^CYAN%^buckle "
"is set in the center of the hat, where the crown meets the brim.%^RESET%^\n");
   set_property("lore difficulty",13);
   set_type("clothing"); 
   set_limbs(({"head"}));
   set_ac(0);
   set_property("enchantment",2);
   set_weight(3);
   set_size(2);
   set_value(1500);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   set_heart_beat(1);
}

int wearme(){
   object *armor;
   int i,FLAG;
   FLAG = 0;
   if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"The hat rejects one as weak as you!");
      return 0;
   }
   if(!living(ETO)) return 1;
   armor = ETO->query_armour("head");
   if(armor != ({})){
     for(i=0;i<sizeof(armor);i++){
       if(((string)armor[i]->query_type() != "ring") && ((string)armor[i]->query_type() != "bracer")) FLAG ++;
     }
     if(FLAG != 0){
       tell_object(ETO,"You may not wear the hat with other headgear!");
       return 0;
     }
   }
   if((ETO->is_class("mage")) && (!ETO->is_class("cleric")) &&
(!ETO->is_class("fighter")) && (!ETO->is_class("thief"))){
     tell_object(ETO,"%^CYAN%^You place the %^BLUE%^midnight blue %^CYAN%^suede "
"hat on your head, topping off your wizard's apparel.%^RESET%^");
     return 1;
   }
   tell_object(ETO,"The wizard hat refuses to sit right upon your head!");
   return 0;
}

int unwearme(){
   tell_object(ETO,"%^CYAN%^You remove the %^BLUE%^midnight blue %^CYAN%^suede "
"hat, and feel less like a wizard.%^RESET%^");
   return 1;
}

void heart_beat(){
   object *armor;
   string *myids;
   int i;
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!living(ETO)) return;
   armor = ({});
   armor += ETO->query_armour("head");
   if(TO->query_worn()){
     for(i=0;i<sizeof(armor);i++) {
       if(((string)armor[i]->query_type() != "clothing") && ((string)armor[i]->query_type() != "ring") && ((string)armor[i]->query_type() != "bracer")){
         if( !armor[i]->query_property("no remove") ) {
           tell_object(ETO,"The hat rejects the "+armor[i]->query_name()+
" you were wearing!");
           myids = armor[i]->query_id();
           ETO->force_me("unwear "+myids[0]+"");
         }
       }
     }
   }
}
