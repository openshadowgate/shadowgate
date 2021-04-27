#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("body armor");
   set_id(({ "body armor", "armor", "leather", "mesh" }));
   set_short("%^RESET%^%^ORANGE%^Cothens light armor%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^Suit of light armor%^RESET%^");
   set_long("%^RESET%^This set of %^ORANGE%^armor %^RESET%^is made from %^ORANGE%^leather %^RESET%^that has"
" been designed to give decent protection without hindering movement.  The front of the armor looks to be "
"reinforced somehow and bears the %^MAGENTA%^emblem %^RESET%^of a"
" %^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^si%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^g %^RESET%^%^GREEN%^tree"
" %^RESET%^against the setting %^YELLOW%^s%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^n %^RESET%^upon its breast.  The"
" image of the %^GREEN%^tree %^RESET%^is leafless though far from lifeless, and seems to %^MAGENTA%^radiate"
" %^RESET%^an %^CYAN%^aura %^RESET%^of %^MAGENTA%^power %^RESET%^from within it... almost as though it were"
" %^MAGENTA%^p%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^ls%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ng"
" %^RESET%^with its own inner %^BOLD%^%^GREEN%^lifeforce%^RESET%^.  The %^ORANGE%^armor %^RESET%^tucks into the waist"
" line before draping down past the hips in seperate %^ORANGE%^flaps %^RESET%^of thick %^RESET%^%^ORANGE%^leather"
" %^RESET%^for added protection.  Besides the %^GREEN%^image %^RESET%^of the %^GREEN%^tree, %^RESET%^the rest of"
" the %^ORANGE%^armor %^RESET%^has been kept a very %^ORANGE%^natural color %^RESET%^so that the wearer may more"
" easily %^ORANGE%^bl%^GREEN%^e%^ORANGE%^nd %^RESET%^in with the surrounding areas.%^RESET%^\n");
   set_weight(15);
   set_value(15000);
   set_type("leather");
   set_limbs(({"torso"}));
   set_size(2);
   set_property("enchantment",3);
   set_ac(3);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}
int wear_func(){
   tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The %^GREEN%^tree %^ORANGE%^on the front of the armor takes on its"
" own life and begins to %^GREEN%^gl%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^w %^ORANGE%^against the image of the"
" setting %^YELLOW%^s%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^n %^RESET%^%^ORANGE%^as "+ETO->query_cap_name()+" slips the"
" armor on.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^ORANGE%^The %^GREEN%^tree %^ORANGE%^on the front of the armor takes on its own"
" life and begins to %^GREEN%^gl%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^w %^ORANGE%^against the image of the setting"
" %^YELLOW%^s%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^n %^RESET%^%^ORANGE%^as you wear the armor.%^RESET%^");
   ETO->add_stat_bonus("dexterity",2);
   return 1;
}
int remove_func(){
   tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The image of the %^GREEN%^tree %^ORANGE%^fades in color as "+ETO->query_cap_name()+" takes the armor off.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^ORANGE%^The image of the %^GREEN%^tree %^ORANGE%^as you take the armor off.%^RESET%^");
   ETO->add_stat_bonus("dexterity",-2);
   return 1;
}