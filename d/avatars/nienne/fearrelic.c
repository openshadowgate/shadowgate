#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("jet-black rod");
   set_id(({"rod","jet-black rod","black rod","gem-studded rod","gem-studded jet-black rod"}));
   set_short("%^BOLD%^%^BLACK%^g%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^m-st%^BOLD%^%^RED%^u%^BOLD%^%^BLACK%^dd%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^d jet-black rod%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This flawless rod is %^BOLD%^%^BLACK%^jet-black%^RESET%^%^BLUE%^, made perhaps "
"of blackened steel or obsidian. Smooth and reflective, it could be held with ease in one hand. It is narrow "
"at one end and bears a studded head at the other, within which has been set four %^RED%^blood-red "
"%^BLUE%^carnelian stones at equidistant intervals. A closer inspection reveals each gemstone to contain the "
"form of single mortal being, their hands pressed against the gem's inner surface as they %^CYAN%^shriek "
"%^BLUE%^and %^MAGENTA%^scream %^BLUE%^soundlessly for release. As you watch, a %^MAGENTA%^ma%^RED%^l%^MAGENTA%^ign"
"%^RED%^a%^MAGENTA%^nt %^BLUE%^glow seems to pulse forth from the rod itself, giving you a desire to simply "
"abandon the relic and be gone from its presence.%^RESET%^");
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
"This particular sphere is known as the Rod of Binding Fear. Possessed "
"of the power over the domain of Fear, it has long been the dominion "
"of Bane, the Black Tyrant. The most recently known guardian of this "
"sphere was a powerful Erinyes known as Hantu Kopek, chosen of the Black "
"Tyrant and a dangerous being even beyond the support of her master. She "
"was said to have been an unparalleled master of illusion and nightmare, "
"snatching fragments of memory from her victims so as to greater play upon "
"their darkest fears.\n");
   set_property("lore difficulty",40);
   set_weight(1);
   set_value(0);
   set_heart_beat(1);
}

void heart_beat(){
   object myplayer;
   if(!userp(ETO)) return;
   if(!interactive(ETO)) return;
   if((string)ETO->query_name() != "balur" && !avatarp(ETO)) {
     myplayer = ETO;
     tell_object(ETO,"%^RED%^Just the horrific feel of the rod is more "
"than you can stand, and you cannot resist dropping the sphere and "
"getting away from it as quickly as you can!%^RESET%^");
     tell_room(EETO,"%^RED%^A look of horror passes across "+ETO->QCN+
"%^RESET%^%^RED%^'s face, and "+ETO->QS+"%^RESET%^%^RED%^ casts aside a "
"jet-black rod before attempting to flee the area as quickly as "
"possible!%^RESET%^",ETO);
     myplayer->force_me("drop jet-black rod");
     myplayer->run_away();
     return;
   }

   switch(random(1001)){
     case 0..996:
     break;
     case 997:
     tell_object(ETO,"%^RED%^A feeling of fear fills you as the rod "
"pulses with %^MAGENTA%^ma%^RED%^l%^MAGENTA%^ignant %^RED%^energy, and "
"the barely resistable urge runs through you to just drop it and be gone "
"from its presence.%^RESET%^");
     if(!ETO->query_invis()){
       tell_room(EETO,"%^RED%^"+ETO->QCN+" %^RESET%^%^RED%^looks "
"distinctly uneasy for a moment, like "+ETO->QS+" would like nothing "
"better than to run.%^RESET%^",ETO);
     }
     break;
     case 998:
     tell_object(ETO,"%^MAGENTA%^The hisses and whispers of the "
"%^CYAN%^void %^MAGENTA%^echo in your ears, sending shivers down your "
"spine despite your best efforts at ignoring them.%^RESET%^");
     if(!ETO->query_invis()){
       tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" pauses, as if they've "
"heard something, and seems to shiver briefly.%^RESET%^",ETO);
     }
     break;
     case 999:
   tell_object(ETO,"%^BLUE%^The bonechilling %^YELLOW%^scr%^RED%^e"
"%^YELLOW%^am %^RESET%^%^BLUE%^of a soul lost to unnamed torment fills "
"your mind, and the world goes black momentarily.%^RESET%^");
     if(!ETO->query_invis()){
       tell_room(EETO,"%^BLUE%^"+ETO->QCN+" stumbles momentarily, as if "
"disoriented.%^RESET%^",ETO);
     }
     break;
     case 1000:
     tell_room(ETO,"%^BOLD%^%^BLACK%^The feeling of countless desperate "
"hands %^WHITE%^claw%^YELLOW%^i%^WHITE%^ng %^BLACK%^at your skin is "
"enough to force you to glance around, just to ensure you're actually "
"safe.%^RESET%^",ETO);
     if(!ETO->query_invis()){
       tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" glances around, as "
"if suddenly spooked by something.%^RESET%^",ETO);
     }
     break;
   }
   return ;
}

int isMagic(){ return 8; }