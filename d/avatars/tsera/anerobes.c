#include <std.h>
inherit PARMOUR;

string FLAG;
int CHAFLAG;
void create(){
   ::create();
       set_name("%^BOLD%^%^BLACK%^G%^RESET%^%^MAGENTA%^o%^RED%^w%^BOLD%^%^BLACK%^n %^RED%^o%^BLACK%^f M%^MAGENTA%^i%^BLACK%^sf%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^rt%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^n%^RED%^e%^RESET%^");
      set_obvious_short("%^BOLD%^%^BLACK%^Bl%^MAGENTA%^a%^BLACK%^ck v%^RED%^e%^RESET%^%^MAGENTA%^l%^BOLD%^v%^RED%^e%^BLACK%^t dr%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ss%^RESET%^");
set_short("%^BOLD%^%^BLACK%^G%^RESET%^%^MAGENTA%^o%^RED%^w%^BOLD%^%^BLACK%^n %^RED%^o%^BLACK%^f M%^MAGENTA%^i%^BLACK%^sf%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^rt%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^n%^RED%^e%^RESET%^");
      set_id(({"robes","mage robes","magi robes","robe","dress","gown"}));
      set_long("%^BOLD%^%^BLACK%^This stunning dr%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ss is crafted of the finest"
" black velvet, its smooth surface seeming to cascade down the body of the wearer. A provocative"
" %^RED%^V %^BLACK%^cut descends between the breasts, laced together with %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^"
"ms%^RESET%^%^RED%^o%^BOLD%^n %^BLACK%^and %^RESET%^%^MAGENTA%^m%^BOLD%^%^RED%^a%^MAGENTA%^u%^RESET%^%^RED%^v"
"%^MAGENTA%^e %^BOLD%^%^RED%^r%^RESET%^%^MAGENTA%^i%^BOLD%^bb%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^MAGENTA%^s"
"%^BOLD%^%^BLACK%^. Thin straps circle the shoulder and hang to a fabric cross bar in the back which helps"
" support the integrity of the dress. Besides the cross bar, the back of the dress has been completely scooped"
" out, leaving the wearers back bare all the way down to its base. The uneven skirts hang to mid thigh on the"
" right and descend to the knee on the left, a second layer of %^RED%^c%^MAGENTA%^o%^RESET%^%^RED%^l%^MAGENTA%^o"
"%^BOLD%^r%^RED%^f%^RESET%^%^MAGENTA%^u%^BOLD%^l %^RESET%^%^MAGENTA%^t%^BOLD%^%^RED%^a%^RESET%^%^RED%^tt%^BOLD"
"%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^r%^RED%^e%^BOLD%^%^MAGENTA%^d %^BLACK%^s%^MAGENTA%^i%^BLACK%^lk emerging"
" from beneath to sway softly about the legs. The dress seems to adhere and enhance the natural curves of"
" the body while allowing complete freedom of movement.%^RESET%^");
      set_weight(5);
      set_type("clothing");
      set_ac(2);
   set_property("enchantment",3);
      set_limbs(({"torso"}));
      set_max_internal_encumbrance(35);
      set_value(55000);
      set_wear((:TO,"wearme":));
      set_remove((:TO,"removeme":));
      set("chabonus",2);
      set("intbonus",1);
}

int wearme(){
   if((int)ETO->query_highest_level() < 35) {
    tell_object(ETO,"%^RESET%^%^MAGENTA%^This dress simply refuse to conform to your body.");
       return 0;
    tell_object(ETO,"%^BOLD%^%^BLACK%^As you slip on the dress, you are surprised to find it holds %^MAGENTA%^c%^RESET%^%^ORANGE%^h%^MAGENTA%^a%^BOLD%^o%^RED%^t%^RESET%^%^GREEN%^i%^BOLD%^%^RED%^c%^RESET%^, %^CYAN%^dimensional pockets %^BOLD%^%^BLACK%^within.");
   }
   ETO->set_property("magic resistance",20);
   return 1;
   write("You lack the dedication to wear these robes.");
   return 0;
   }
int removeme()
{
   ETO->set_property("magic resistance",-20);
   return 1;
}
void init(){
   ::init();
   add_action("check_put","put");
}
int check_put(string str){
   if(!query_worn()) {
      notify_fail("You must be wearing the robes to place something in their pockets.\n");
      return 0;
   }
   if(query_worn()) return ::put_into();
}


