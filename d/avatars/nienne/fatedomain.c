#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("woven tapestry");
   set_id(({"tapestry","woven tapestry","tapestry of fate","tapestry of stars"}));
   set_short("%^RESET%^%^BLUE%^Tapestry of %^YELLOW%^S%^BOLD%^%^WHITE%^t%^YELLOW%^a%^BOLD%^%^WHITE%^r%^YELLOW%^s%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This small, beautiful work of art is only a little wider than a handspan. Set upon a light %^ORANGE%^timber %^CYAN%^frame, "
"lines of soft thread weave back and forth across its surface to shape a %^BLUE%^velvety backdrop %^CYAN%^of night spotted with %^RESET%^pale stars"
"%^CYAN%^. Metallic traces have been incorporated to lend faint %^BOLD%^%^WHITE%^s%^RESET%^p%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^k%^RESET%^l"
"%^BOLD%^%^BLACK%^e%^RESET%^s %^CYAN%^to each of the stars in turn, gleaming brightly with any motion.  As you watch, a faint %^BOLD%^%^CYAN%^aura "
"%^RESET%^%^CYAN%^seems to pulse forth from the tapestry itself, giving you a desire to simply abandon the trophy and begone from its presence.%^RESET%^");
   set_lore("Tales tell of such talismans as this, in the possession of "
"the very gods themselves. Each contains the power of a domain of "
"influence, and is bound to the deity that controls that domain. The gods "
"guard these jealously, with intense magics to ward them, including "
"protections that would cause any mere mortal who finds them to stop at "
"nothing to be rid of their presence. Generally the only ones who can "
"bear to hold such an item are the gods themselves, or the chosen of the "
"deity who possesses the domain in question. But, for some rare few mortals "
"whose hearts are in true attunement, they may also take up such relics "
"and in doing so, become something more than mortal themselves.\n\n"
"This particular relic is known as the Tapestry of Stars, and is said to "
"grant power over the domain of fate and destiny.\n");
   set_property("lore difficulty",45);
   set_weight(0);
   set_value(0);
   set_heart_beat(1);
}

void heart_beat(){
   if(!userp(ETO)) return;
   if(!interactive(ETO)) return;

   if((string)ETO->query_name() != "sadhara" && !avatarp(ETO)) {
     tell_object(ETO,"%^CYAN%^As you take up the tapestry, a vision of "
"%^BLUE%^velvet darkness %^CYAN%^fills your senses and obscures the world "
"around you. %^RESET%^Stars %^CYAN%^are born upon the blanket of night, as "
"dust collects around them and forms rock, water and air, and your mind "
"whirls to try and comprehend the countless formations. %^GREEN%^Life "
"%^CYAN%^blossoms across the constellations, its myriad forms taking shape "
"and it is all you can do to retain consciousness as the immensity of it all "
"threatens to overwhelm you.\n\n%^GREEN%^And then quite suddenly the world "
"around you reasserts itself, and you realise you have dropped the tapestry.%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s eyes grow glazed as "
+ETO->QP+" breathing grows shallow, and "+ETO->QP+" pupils dart sightlessly "
"to and fro. "+capitalize(ETO->QP)+" lips part, hands twitching until "
"the tapestry falls from "+ETO->QP+" fingers, and suddenly "+ETO->QS+
" is normal again!%^RESET%^",ETO);
     ETO->force_me("drop tapestry of fate");
   }
}

int isMagic(){ return 8; }
