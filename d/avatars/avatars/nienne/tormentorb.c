#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("%^RESET%^%^RED%^glow%^MAGENTA%^i%^RED%^ng orb%^RESET%^");
   set_id(({"orb","sphere","glowing orb","malignant orb","malignant glowing orb"}));
   set_short("%^RESET%^%^RED%^ma%^MAGENTA%^l%^RED%^ign%^BOLD%^%^BLACK%^an%^RESET%^%^RED%^t glow%^BOLD%^i%^RESET%^%^RED%^ng orb%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This, at first, appears to be simply an orb "
"of %^BOLD%^%^BLACK%^dark glass%^RESET%^%^BLUE%^. A closer inspection, "
"though, reveals it to contain countless %^RESET%^writ%^BOLD%^%^BLACK%^hi"
"%^RESET%^ng %^BLUE%^figures, their hands pressed against the glassy "
"inner surface of the sphere as they fight their way forward. Lips move "
"in silent screams of %^RED%^to%^BOLD%^r%^RESET%^%^RED%^ment %^BLUE%^and "
"eyes beseech the viewer for some shred of mercy or pity that might free "
"them from their eternal prison. As you watch, a %^MAGENTA%^ma%^RED%^l"
"%^MAGENTA%^ign%^RED%^a%^MAGENTA%^nt %^BLUE%^glow seems to pulse forth "
"from the orb itself, giving you a desire to simply abandon the sphere "
"and begone from its presence.%^RESET%^");
   set_lore("Tales tell of such talismans as this, in the possession of "
"the very gods themselves. Each contains the power of a domain of "
"influence, and is bound to the deity that controls that domain. The gods "
"guard these jealously, with intense magics to ward them, including "
"protections that would cause any mere mortal who finds them to stop at "
"nothing to be rid of their presence. Generally the only ones who can "
"bear to hold such an item are the gods themselves, or the chosen of the "
"deity who possesses the domain in question. These chosen serve as "
"guardians, who carry and protect the talismans across the realms. It is "
"only with the deaths of these chosen that the protection of these "
"talismans pass to another.\n\n"
"This particular sphere is known as the Orb of Eternal Torment. Possessed "
"of the power over the domain of torment, it has long been the possession "
"of Loviatar, the maiden of Pain. The most recently known guardian of "
"this sphere was a half-drow by the name of Anshara, chosen of Loviatar "
"and a dangerous being even beyond the support of her mistress. While "
"able to walk the planes, she is known to be fond of the prime as her "
"place of birth, and what she believed to be the richest source of her "
"mistress' pleasure.\n");
   set_property("lore difficulty",40);
   set_weight(1);
   set_value(0);
   set_heart_beat(1);
}

void heart_beat(){
   object myplayer;
   if(!userp(ETO)) return;
   if(!interactive(ETO)) return;
   if((string)ETO->query_name() == "anshara") return;

   if((string)ETO->query_name() != "nightfall" && !avatarp(ETO)) {
     myplayer = ETO;
     tell_object(ETO,"%^RED%^Just the horrific feel of the orb is more "
"than you can stand, and you cannot resist dropping the sphere and "
"getting away from it as quickly as you can!%^RESET%^");
     tell_room(EETO,"%^RED%^A look of horror passes across "+ETO->QCN+
"%^RESET%^%^RED%^'s face, and "+ETO->QS+"%^RESET%^%^RED%^ casts aside a "
"dark orb before attempting to flee the area as quickly as "
"possible!%^RESET%^,ETO");
     myplayer->force_me("drop malignant orb");
     myplayer->run_away();
     return;
   }

   switch(random(1001)){
     case 0..996:
     break;
     case 997:
     tell_object(ETO,"%^RED%^A feeling of dread fills you as the orb "
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
     tell_object(ETO,"%^MAGENTA%^The %^RESET%^wails %^MAGENTA%^of "
"countless souls trapped in eternal torment echoes in your ears, sending "
"shivers down your spine despite your best efforts at ignoring "
"them.%^RESET%^");
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

int isMagic(){ return 6; }
