#include <std.h>
inherit "/std/armour";

int FLAG;

void create()
{
        ::create();
        set_name("bracelets");
        set_short("%^BOLD%^%^BLACK%^Shadow bracelets%^RESET%^");
     set_obvious_short("%^BOLD%^%^BLACK%^Dark black bracelets%^RESET%^");
        set_id(({"bracelets","bracelets of power","Bracelets of Power","shadow bracelets","dark bracelets"}));
        set_long("%^BOLD%^%^BLACK%^These twin bracelets are matching cuffs of pure darkness.  Power seems to shift through the shadows that compose them.  One can only imagine where such a thing would come from.%^RESET%^");

        set_weight(5);
        set_value(2000);
        set_ac(0);
        set_property("enchantment",1);
        set_type("clothing");
        set_limbs(({"right arm"}));
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
   if(!random(3)) FLAG = 1;
   else FLAG = 0;
}

int wearme()
{
int mystat,curstat;
mystat = ETO->query_base_stats("strength");
curstat = ETO->query_stats("strength");

        if(ETO->query_lowest_level() < 20) {
                tell_object(ETO,"You are not experienced enough to use this equipment.");
                return 0;
        }
   if(mystat < curstat){
      tell_object(ETO,"The bracelets refuse to be worn with something already granting you strength!");
      return 0;
   }
   if(FLAG == 1 && ETO->query_base_stats("strength") < 19) {
      ETO->add_stat_bonus("strength",1);
   }
        tell_object(ETO,"You feel the bracelets strengthen your arms as you slip them over your wrists.");


        return 1;
}

int removeme()
{
        tell_object(ETO,"You feel weak once more as you remove the bracelets.");
   if(FLAG == 1 && ETO->query_base_stats("strength") < 19) {
      ETO->add_stat_bonus("strength",-1);
   }

        return 1;
}