#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("golden hoop");
   set_id(({"hoop","golden hoop"}));
   set_short("%^BOLD%^%^YELLOW%^gol%^RESET%^%^ORANGE%^d%^BOLD%^%^YELLOW%^en h%^RESET%^%^ORANGE%^oo%^BOLD%^%^YELLOW%^p%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This simple piece of jewelry has been crafted of pure %^YELLOW%^g%^RESET%^"
"%^ORANGE%^ol%^BOLD%^%^YELLOW%^d%^BOLD%^%^WHITE%^, polished so that it gleams brightly under light.  A "
"tiny notch has been marked at an angle to run the length of the hoop, adding simple %^RESET%^%^CYAN%^"
"orn%^GREEN%^am%^CYAN%^enta%^GREEN%^t%^CYAN%^ion %^BOLD%^%^WHITE%^to the otherwise unremarkable piece.  "
"It is fairly small, perhaps designed for piercings other than the ears.  Despite its relatively "
"%^BOLD%^%^BLACK%^plain %^BOLD%^%^WHITE%^appearance, the usually soft metal bears no damage, scratches "
"or dents, leading you to wonder that it might somehow have been hardened or enhanced.%^RESET%^\n"); 
   set_type("clothing");
   set_limbs(({"head"}));
   set_weight(2);
   set_size(-1);
   set_ac(0);
   set_property("enchantment",2);
   set_item_bonus("charisma",1);
   set_item_bonus("spell penetration",10);
   set_value(2500);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^The hoop %^YELLOW%^gleams%^BOLD%^%WHITE%^ as it slips through your "
"lip.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s hoop %^YELLOW%^gleams%^BOLD%^%WHITE%^ as it slips "
"through "+ETO->QP+" lip.%^RESET%^",ETO);
   return 1;
}
