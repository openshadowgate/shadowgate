#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("gloves");
   set_id(({"gloves","shar gloves","night's caress","nights caress","black gloves","long gloves"}));
   set_short("%^BLACK%^%^BOLD%^N%^RESET%^%^MAGENTA%^i%^BLACK%^%^BOLD%^gh%^RESET%^%^MAGENTA%^t%^BLACK%^%^BOLD%^'s %^RESET%^%^MAGENTA%^C%^BLACK%^%^BOLD%^ar%^RESET%^%^MAGENTA%^e%^BLACK%^%^BOLD%^ss%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^long black gloves%^RESET%^");
   set_long("%^CYAN%^These long gloves are made of the finest leather, dyed so perfect a shade of "
"%^BLACK%^%^BOLD%^ black%^RESET%^%^CYAN%^ that they could almost be made of darkness itself.  They reach just "
"to the wrists, and are impossibly soft to the touch, like a second skin around the hands.  Tiny, darkly-"
"shimmering threads of %^MAGENTA%^violet%^CYAN%^ trace a single line of embroidery around the cuff of each "
"glove, as the only ornamentation upon their perfect black surface.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Many tales speak of such gloves as these.  The more common stories speak of "
"their creation by the most blessed of the Nightmother's followers, gifted only to select members of her "
"church, to further spread Shar's darkness and loss by their very hands.");
   set_property("lore difficulty",12);
   set_weight(2);
   set_value(0);
   set_ac(0);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
   set_type("clothing");
   set_limbs(({"left hand","right hand"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if((string)ETO->query_name() != "tiberius" && !avatarp(ETO)) {
     tell_object(ETO,"%^BLACK%^%^BOLD%^The gloves refuse to let you wear them!");
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" tries to wear the gloves, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel the very touch of darkness held within the gloves.");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" slips the gloves over each hand, like a tangible skin of "
"darkness.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel the protection of darkness recede as you remove the gloves.");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" seems disappointed to remove the dark gloves.",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(random(2)){
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+"'s gloved hand becomes almost insubstancial, like a whisp of "
"pure darkness, and "+who->QCN+"'s attack passes straight through it!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BLACK%^%^BOLD%^Your gloved hand becomes insubstancial, like a whisp of pure darkness, "
"as"+who->QCN+"'s attack passes straight through it!%^RESET%^");
     tell_object(who,"%^BLACK%^%^BOLD%^"+ETOQCN+"'s gloved hand becomes almost insubstancial, like a whisp of pure darkness, and your attack passes straight through it!%^RESET%^");
     return (-1)*damage;
   }
}
