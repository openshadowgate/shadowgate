#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("golden ring");
   set_id(({"ring of protection","ring","gold ring","golden ring","band","black band","black band of the chosen","band of the chosen"}));
   set_short("%^BOLD%^%^BLACK%^Bla%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^k Band of the C%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^osen%^RESET%^");
   set_obvious_short("%^BOLD%^%^YELLOW%^a %^BLACK%^gemm%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^d %^YELLOW%^golden ring%^RESET%^");
   set_long("%^GREEN%^This piece of jewelry consists primarily of a simple band of %^YELLOW%^gold%^RESET%^%^GREEN%^, slender and elegant in its shaping.  "
"Narrow for the most part, the base broadens slightly to support a single oval cabochon-cut %^BOLD%^%^BLACK%^black opal%^RESET%^%^GREEN%^, that carries "
"hints and veins of every hue imaginable in its %^BOLD%^%^BLACK%^d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rk dep%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^hs"
"%^RESET%^%^GREEN%^.  Oddly though, instead of reflecting the %^WHITE%^light %^GREEN%^around it, the gemstone seems to draw it inward - perhaps an odd "
"trick of its crafting. %^YELLOW%^Tiny golden claws %^RESET%^%^GREEN%^support the gemstone, resulting in a ring that is perhaps more delicate than "
"practical, but definitely an artfully worked item.\n%^RESET%^"); 
   set_lore("%^WHITE%^%^BOLD%^Rings such as this are rarely seen, and guarded jealously by the few that own them.  Deceptively simple, save for the rare "
"and precious black opal encased in each piece, the more learned recognize such an item to be the mark of a faithful follower of the Black Hand - "
"telltale by the gemstone's affinity for consuming light, rather than reflecting it like a normal jewel.  Rumors abound of how the enchanted items are "
"crafted, but none carry any basis in proven fact, leaving many to wonder if they are obtained by more supernatural means, or possibly granted by Bane "
"himself.%^RESET%^\n");
   set_property("lore difficulty",13);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_weight(1);
   set_size(2);
   set_ac(0);
   set_property("enchantment",1);
   set_item_bonus("magic resistance",1);
   set_value(2500);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   object *stuff;
   int i,j, flag;

   stuff = TP->all_armour();
   j = sizeof(stuff);
   if((string)ETO->query_diety() != "bane" && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   for(i=0;i<j;i++) {
     if(!objectp(stuff[i])) continue;
     if((string)stuff[i]->query_type() == "ring") {
       if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
         flag = 1;
         break;
       }
     }
   }
   if(flag) {
     write("The magic of the ring already worn prevents you from wearing this one!");
     return 0;
   }
   tell_room(ETO,"%^BOLD%^%^BLACK%^A %^RESET%^%^GREEN%^subtle %^BOLD%^%^BLACK%^confidence fills you as you slide the ring on.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(ETO,"%^BOLD%^%^BLACK%^The feeling of confidence fades as you slip the ring off.%^RESET%^");
   return 1;
}
