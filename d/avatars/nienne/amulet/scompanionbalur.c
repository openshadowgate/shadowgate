#include <std.h>
inherit "/d/magic/obj/scompanion";

void init(){
   ::init();

   if(!objectp(ETO)) { 
       TO->remove();
       return;
   }
   if(!userp(ETO)) {
       TO->remove();
       return;
   }
   caster = ETO;
   if((string)caster->query_name() != "balur") {
     tell_object(caster,"%^RESET%^%^ORANGE%^The spell fizzles and dies - you just don't have the knowledge to maintain such a complex ritual.%^RESET%^");
     tell_room(environment(caster),"%^RESET%^%^ORANGE%^"+caster->QCN+" can't seem to maintain the spell, which fizzles harmlessly and dies.%^RESET%^",caster);
     TO->move("/d/shadowgate/void");
     TO->remove();
     return;
   }

   lvl = caster->query_guild_level("warlock");
   tell_object(caster,"%^ORANGE%^You draw forth a handful of charcoal and a stick of incense.  Lighting the "
"incense, you begin the chant to call forth a creature companion.%^RESET%^\n\n");
   tell_object(caster,"%^RESET%^%^GREEN%^What gender do you wish your summoned creature to be?  Choices: "
"%^YELLOW%^male%^RESET%^%^GREEN%^ or %^YELLOW%^female%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ "
"to abort the spell.%^RESET%^\n");
   input_to("step1");
}