#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create() {
   ::create();
   set_name("%^BOLD%^%^BLACK%^g%^RESET%^ra%^BOLD%^%^BLACK%^y coat%^RESET%^");
   set_id(({"coat","grey coat","gray coat","coat of shadows","coat of shifting shadows","Coat of Shifting Shadows"}));
   set_short("%^BOLD%^%^BLACK%^Coat of Sh%^RESET%^i%^BOLD%^%^BLACK%^fting Sha%^RESET%^%^MAGENTA%^d%^BOLD%^%^BLACK%^ows%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a soft g%^RESET%^ra%^BOLD%^%^BLACK%^y coat%^RESET%^");
   set_long("This voluminous %^BOLD%^%^BLACK%^g%^RESET%^ra%^BOLD%^%^BLACK%^y "
"%^RESET%^coat would work well to hide much of its wearer's figure from sight, "
"with many %^BLUE%^folds %^RESET%^and %^MAGENTA%^billows %^RESET%^to mislead "
"a viewer. It is made from some kind of supple %^BOLD%^%^BLACK%^s%^RESET%^"
"m%^BOLD%^%^BLACK%^oky %^RESET%^cloth that resembles velvet in its softness, "
"yet it seems far more hardy and resilient to damage than such a%^RED%^ "
"f%^ORANGE%^ra%^RED%^g%^ORANGE%^il%^RED%^e%^RESET%^ material. Long sleeves "
"and a high collar shape the garment, which is secured by way of dull buttons "
"down its length, to nearly reach the floor on a wearer of moderate height. "
"No embroidery or patterning breaks up its %^BOLD%^%^BLACK%^monotone%^RESET%^ "
"color, yet the cloth itself seems to catch light in such a way that the "
"shades of gray constantly %^CYAN%^r%^GREEN%^ip%^CYAN%^pl%^GREEN%^e%^RESET%^ "
"and %^CYAN%^sh%^GREEN%^if%^CYAN%^t%^RESET%^, making it seem that shadows "
"dance across its surface.\n");
   set_lore("This coat matches the description of one crafted for a half-elf "
"rogue known as Thessil, many years ago. Renowned for his skills, yet "
"claiming no alliance save that of the rogues' guilds, he had it specially "
"made to assist his already strong skills in stealth. Many claimed he could "
"walk the shadows themselves with this cloak, though of course these tales "
"have a way of exaggerating themselves over time.");
   set_property("lore difficulty",21);
   set_weight(8);
   set_value(4000);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(2);
   while ((int)TO->query_property("enchantment") != 4) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",4);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
    set_max_internal_encumbrance(21);
}

int wear_fun() {
   if((int)ETO->query_level() < 15) {
     tell_object(ETO,"The coat doesn't fit you.");
     return 0;
   }
   tell_object(ETO,"%^MAGENTA%^You slide into the coat, finding comfort in "
"its voluminous folds.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" draws the coat around "+ETO->QP+
" shoulders, shrouding "+ETO->QP+" figure from view.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You feel revealed and vulnerable without the "
"protection of the coat.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" looks a little uncomfortable after "
"removing the coat.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(random(1000) < 150){
     tell_room(EETO,"%^MAGENTA%^"+who->QCN+" seems to realise too late that "
+who->QP+" blow is offtarget, deceived by the shifting folds of "+ETOQCN+"'s "
"coat!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^MAGENTA%^"+who->QCN+" seems to realise too late that "
+who->QP+" blow is offtarget, deceived by the shifting folds of your coat, "
"and you easily evade the attack!%^RESET%^");
     tell_object(who,"%^MAGENTA%^You realise too late that your blow is "
"offtarget, deceived by the shifting folds of "+ETOQCN+"'s coat!%^RESET%^");
     return(-1)*(damage);
   }
}
