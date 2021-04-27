//Description by Eiryasha - coded by Circe 6/7/04
//reward for the poetry contest
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("crystal orb");
   set_short("a perfect %^BOLD%^%^CYAN%^orb %^RESET%^of "+
      "%^BOLD%^%^CYAN%^crystal %^RESET%^on a %^BOLD%^%^GREEN%^"+
      "silk ribbon%^RESET%^");
   set_id(({"orb","crystal orb","orb of crystal","perfect orb"}));
   set_long(
@CIRCE
A crystal orb so perfect in roundness and smoothness that captures the gaze in a mesmerizing spell of enchantment. Transparent and clear, when staring deeply into the depths strange and wondrous patterns can be seen spinning and flitting in an amazing dance. A silk ribbon of vibrant green is attached to the crystal orb in a way that suggest the ribbon runs through,
yet the ribbon cannot be seen inside.
CIRCE
   );
   set_lore(
@CIRCE
This statue was presented to the winner of the Spontaneous Poetry Contest held in Torm in the year 663 SG.
CIRCE
   );
   set_property("lore difficulty",5);
   set_weight(5);
   set_type("ring");
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(0);
   set_wear((:TO,"wearme":));
   set_remove("The crystal fades as you remove it.");
}

int wearme(){
   int align;
   align = ETO->query_alignment();
   switch(align){
      case 1:  tell_object(ETO,"The orb begins to %^YELLOW%^glow "+
                  "%^RESET%^with a %^YELLOW%^courageous light%^RESET%^.");
               break;
      case 2:  tell_object(ETO,"The orb %^BOLD%^%^RED%^f%^BLUE%^l"+
                  "%^GREEN%^a%^RED%^s%^BLUE%^h%^GREEN%^e%^RED%^s "+
                  "%^RESET%^through a precise pattern of %^BOLD%^"+
                  "%^BLUE%^c%^GREEN%^o%^RED%^l%^BLUE%^o%^GREEN%^r"+
                  "%^RED%^s%^RESET%^.");
               break;
      case 3:  tell_object(ETO,"The orb %^BOLD%^%^GREEN%^burns "+
                  "%^RESET%^with a %^BOLD%^%^GREEN%^dominating "+
                  "light%^RESET%^.");
               break;
      case 4:  tell_object(ETO,"The orb begins to %^BOLD%^glow "+
                  "%^RESET%^with a %^BOLD%^soft welcoming warmth%^RESET%^.");
               break;
      case 5:  tell_object(ETO,"The orb %^BOLD%^glows %^RESET%^"+
                  "with a %^BOLD%^soft pulse of light%^RESET%^.");
               break;
      case 6:  tell_object(ETO,"The orb %^BLUE%^dims %^RESET%^"+
                  "the room in a %^BLUE%^dark chilling glow%^RESET%^.");
               break;
      case 7:  tell_object(ETO,"The orb begins to %^BOLD%^%^MAGENTA%^"+
                  "glow %^RESET%^with a %^BOLD%^%^MAGENTA%^"+
                  "passionate pulse%^RESET%^.");
               break;
      case 8:  tell_object(ETO,"The orb %^BOLD%^%^RED%^g%^BLUE%^"+
                  "l%^GREEN%^o%^MAGENTA%^w %^RESET%^with a "+
                  "multihued swirl of %^BOLD%^c%^CYAN%^o%^RED%^l"+
                  "%^YELLOW%^o%^GREEN%^r%^RESET%^.");
               break;
      case 9:  tell_object(ETO,"The orb %^RED%^devours %^RESET%^"+
                  "the light about it %^RED%^hungrily%^RESET%^.");
               break;
      default:  break;
   }
   tell_room(EETO,"The orb begins to glow as "+ETOQCN+" wears it.",ETO);
   return 1;
}
