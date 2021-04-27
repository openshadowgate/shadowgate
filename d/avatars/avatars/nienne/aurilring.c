#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("crystalline ring");
   set_id(({"ring of protection","band","ring","crystal ring","crystalline ring","circle","circle of frost","crystal ring","Circle of Frost"}));
   set_short("%^BOLD%^%^CYAN%^Ci%^WHITE%^r%^CYAN%^cle of Fr%^WHITE%^o%^CYAN%^st%^RESET%^");
   set_obvious_short("%^BOLD%^%^CYAN%^a cr%^WHITE%^y%^CYAN%^stal%^WHITE%^l%^CYAN%^ine ring%^RESET%^");
   set_long("%^GREEN%^This small, delicate ring appears to be made of fine, semi-transparent %^BOLD%^%^CYAN%^"
"cr%^WHITE%^y%^CYAN%^stal%^RESET%^%^GREEN%^.  It looks as though it would break with the slightest touch, though its "
"appearance is deceiving - it is solid as %^BOLD%^%^BLACK%^stone%^RESET%^%^GREEN%^.  There seems to be no order to its "
"crafting, with sharp edges of crystal protruding out at random places.  They catch and refract the %^YELLOW%^light "
"%^RESET%^%^GREEN%^like slivers of %^BOLD%^%^WHITE%^ice%^RESET%^%^GREEN%^, giving it a stark sort of beauty to behold.  "
"Despite this, it seems oddly %^BOLD%^%^CYAN%^cold %^RESET%^%^GREEN%^to the touch, no matter how much you try to warm "
"it.\n%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^It was said that a set of these rings were once crafted by a wizard of great power.  He "
"had a fondness for spells that harnessed and unleashed the elements, and spent decades researching spells to control "
"them.  One of his greatest achievements lay in a set of four rings, each said to hold the power of one particular "
"element - fire, ice, earth and air - though at his death they were never found, and some claim their existance only to "
"be a myth.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_weight(2);
   set_size(2);
   set_ac(0);
   set_property("enchantment",4);
   set_item_bonus("constitution",2);
   set_value(2500);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   object *stuff;
   int i,j, flag;

   stuff = TP->all_armour();
   j = sizeof(stuff);
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
   tell_object(ETO,"%^BOLD%^%^CYAN%^A %^WHITE%^sh%^CYAN%^i%^WHITE%^ver%^CYAN%^ runs down your spine as you slide the ring "
"on your finger.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^CYAN%^The %^WHITE%^chi%^CYAN%^l%^WHITE%^l%^CYAN%^ leaves your body as you slip the ring "
"off.%^RESET%^");
   return 1;
}
