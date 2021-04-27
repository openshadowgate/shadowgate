#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("bloodied claw");
   set_id(({"claw","beast claw","bloodied claw","bloodied beast claw"}));
   set_short("%^RESET%^%^RED%^bl%^BOLD%^%^RED%^o%^RESET%^%^RED%^odi%^BOLD%^%^RED%^e%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^beast claw%^RESET%^");
   set_long("%^GREEN%^This curved beastclaw is massive, easily longer than a man's hand and too wide to grasp around, leaving you only to "
"wonder at what kind of creature could have possessed it.  Shaped of %^RESET%^dull ivory %^GREEN%^that has %^ORANGE%^yellowed %^GREEN%^with "
"age, it is chipped in some places where either age or combat have taken their toll.  From its fiendishly %^YELLOW%^s%^BOLD%^%^WHITE%^h"
"%^BOLD%^%^BLACK%^a%^YELLOW%^r%^BOLD%^%^RED%^p %^RESET%^%^GREEN%^tip, more than half of the claw is stained with dark %^RED%^blood%^GREEN%^ that "
"does not flake away, but has soaked deep into the claw as if from extensive and repeated exposure.  As you watch, a %^MAGENTA%^ma%^RED%^l"
"%^MAGENTA%^ign %^GREEN%^glow seems to pulse forth from the claw itself, giving you a desire to simply abandon the trophy and begone from "
"its presence.%^RESET%^");
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
"This particular sphere is known as the Huntsmaster's Talon. Possessed "
"of the power over the domain of the hunt, it has long been the possession "
"of Malar, the Beastlord. Never given to a lesser servant, this was the "
"power over which he presided directly, and it has said to have never been "
"taken by mortal hands.\n");
   set_property("lore difficulty",45);
   set_weight(0);
   set_value(0);
   set_heart_beat(1);
}

void heart_beat(){
   if(!userp(ETO)) return;
   if(!interactive(ETO)) return;

   if(!avatarp(ETO)) {
     tell_object(ETO,"%^ORANGE%^As you take up the talon, a %^RED%^fine "
"red mist %^ORANGE%^fills your vision. Blood surges through your veins, "
"and %^BLUE%^howls %^ORANGE%^echo in your ears. Your pulse quickens, "
"adrenaline pushing your senses to their limit! Just when you think your "
"heart is about to %^MAGENTA%^burst%^ORANGE%^, the world around you "
"returns to normal. And you realise you have dropped the claw.%^RESET%^");
     tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" 's eyes grow crazed as the "
"veins in "+ETO->QP+" neck stand up, and every one of "+ETO->QP+" muscles "
"tense. A %^RED%^snarl %^ORANGE%^parts "+ETO->QP+" lips as "+ETO->QS+
" seems to struggle to breathe! Just when you start to wonder if "
+ETO->QS+" is about to lunge at you, the claw tumbles from "+ETO->QP+
"fingers, and suddenly "+ETO->QCN+" is normal again!%^RESET%^,ETO");
     ETO->force_me("drop bloodied beast claw");
   }
}

int isMagic(){ return 8; }
