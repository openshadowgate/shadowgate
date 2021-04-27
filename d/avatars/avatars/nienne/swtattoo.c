//Mark of a Shadow Weave user.  Designed by Shar, coded by Circe 3/29/04
//Moved from circe's realms dir to /d where player items should come from;
// removed reference to shadow weave as it doesn't currently exist in our setting. -N, 8/10
#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("tattoo");
   set_short("%^BOLD%^%^BLACK%^A dark swirling tattoo%^RESET%^");
   set_id(({"tattoo","dark tattoo","swirling tattoo","dark swirling tattoo"}));
   set_long("%^BOLD%^%^BLACK%^Dark bands twist and spiral "+
      "around each other in this vivid tattoo.  The tattoo "+
      "is about four inches tall and two inches wide.  The "+
      "bottom part of the twisting tendrils are a rich thick "+
      "black shade.  As the spirals reach higher up the color "+
      "fades into a dull shadowy gray into a soft dusky purple "+
      "color at the peaks.");
   set_weight(0);
   set_type("ring");
   set_limbs(({"left arm"}));
   set_ac(0);
   set_value(0);
   set_property("no animate",1);
   set_property("death keep",1);
   set_wear((:TO,"wearme":));
}

void init(){
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
        ETO->force_me("wear tattoo");
}

int wearme(){
        if((string)TPQN != owner) {
           tell_object(ETO,"The tattoo refuses your hand!");
           TO->remove();
           return 0;
        }
        tell_object(ETO,"%^BOLD%^%^BLACK%^You can feel the "+
           "seductive, cool caress of the shadows.");
        ETO->add_sight_bonus(5);
        return 1;
}

void unwear() {
   tell_object(query_worn(),"You may not remove the tattoo so easily!");
   return;
}

drop()
{
    tell_object(query_worn(),"You may not remove the tattoo so easily!");
    return 1;
}
