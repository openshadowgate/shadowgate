#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("orb of mists");
   set_id(({"orb","orb of mists"}));
   set_short("%^RESET%^%^CYAN%^Orb of %^BOLD%^%^BLACK%^M%^RESET%^i%^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^s%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Set within a base of patterned %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r "
"%^RESET%^%^CYAN%^sits a sphere of glass, its flawless surface showing no scratches or marks. Within its depths swirl %^BLUE%^darkened "
"mists%^CYAN%^, rising and falling independent of the motion of their cage, concealing unknown secrets within.  Around the base have been "
"etched a progression of images that show %^BOLD%^%^BLACK%^ravens %^RESET%^%^CYAN%^in flight, endlessly winging about its perimeter.  As "
"you watch, a faint %^MAGENTA%^aura %^CYAN%^seems to pulse forth from the orb itself, giving you a desire to simply abandon the trophy and "
"begone from its presence.%^RESET%^");
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
"This particular relic is known as the Orb of Mists, and is said to "
"grant power over the domain of mystery.\n");
   set_property("lore difficulty",45);
   set_weight(0);
   set_value(0);
   set_heart_beat(1);
}

void heart_beat(){
   if(!userp(ETO)) return;
   if(!interactive(ETO)) return;

   if((string)ETO->query_name() != "sudelilah" && !avatarp(ETO)) {
     tell_object(ETO,"%^CYAN%^As you take up the orb, its roiling mists "
"draw you inwards, offering a temptation of %^MAGENTA%^secrets "
"%^CYAN%^revealed that could be yours and yours alone. Your mind longs "
"for more, and your thoughts become clouded as you seek deeper and "
"deeper into the foggy miasma that never quite uncovers what you know "
"is only barely out of reach. You struggle to maintain your hold on reality..."
"\n\n%^GREEN%^And then you gasp for air and return to your senses, realising "
"that you have dropped the orb.%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" takes up the orb and seems drawn "
"to peer into its depths, eyes becoming distantly focussed. For long moments "
+ETO->QS+" remains silent, lips moving soundlessly as "+ETO->QP+" features "
"become strained. And then the orb tumbles from "+ETO->QP+" grasp, and "
"suddenly "+ETO->QS+" is normal again!%^RESET%^",ETO);
     ETO->force_me("drop orb of mists");
   }
}

int isMagic(){ return 8; }
