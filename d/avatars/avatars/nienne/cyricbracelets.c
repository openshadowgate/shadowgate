#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
   set_name("bracelets");
   set_id(({"bracelets","cyric bracelets","bands of the sworn faithful","bands","silver bracelets","bands of the sworn","silver bands","kelemvor-rebirth-blessing999"}));
   set_short("%^BLACK%^%^BOLD%^Ba%^RESET%^%^WHITE%^nd%^BOLD%^s of t%^RESET%^%^WHITE%^he %^BLACK%^%^BOLD%^Sw%^RESET%^%^WHITE%^or%^BOLD%^n Fait%^RESET%^%^WHITE%^hf%^BLACK%^%^BOLD%^ul%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^si%^RESET%^%^WHITE%^lv%^BOLD%^er brace%^RESET%^%^WHITE%^le%^BLACK%^%^BOLD%^ts%^RESET%^");
   set_long("%^CYAN%^These pair of bracelets are perfectly matched, each a mirror image of thick "
"%^BLACK%^%^BOLD%^s%^RESET%^%^WHITE%^i%^BOLD%^lv%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^r%^RESET%^%^CYAN%^ "
"shaped to rest around the lower arms.  The surface of each is covered in wraithlike etchings of snarling "
"monsters, intertwined with claws and fangs outstretched.  Upon the underside has been rendered an image "
"lined in some %^BLACK%^%^BOLD%^jet-black substance%^RESET%^%^CYAN%^, of a jawless skull upon a backdrop of "
"a %^MAGENTA%^starburst shape%^CYAN%^.  The image would be rendered invisible while the bracelets were worn, but the lines of "
"the etching could be felt against the wearer's skin.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning this jewelry and the clergy of the Dark Sun.  "
"The most common tells that the bracelets are only ever granted to those that uphold the One True Way, as an "
"symbolic reminder of their servitude to the Prince of Lies.");
   set_property("lore difficulty",18);
   set_remove("%^WHITE%^%^BOLD%^You feel the power of the True God recede as you remove the bracelets.");
   set_weight(2);
   set_value(5382);
   set_type("ring");
   set_limbs( ({ "right arm","left arm" }) );
   set_ac(1);
   while((int)query_property("enchantment") != -1) {
     remove_property("enchantment");
     set_property("enchantment",-1);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)ETO->query_diety() != "cyric") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^Mad laughter echoes in your ears, and you can't help but put the bracelets aside!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" shudders and sets the jewelry aside.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^The tight pressure of the bracelets reminds you of the True God's grasp on your soul.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" seems to become more confident as the bracelets clasp into place around "+ETO->QP+" wrists.",ETO);
   ETO->set_property("rebirth",TO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel Cyric's touch fade as you remove the bracelets.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" rubs "+ETO->QP+" wrists as the bracelets come free.",ETO);
   if(ETO->query_property("rebirth")) ETO->remove_property("rebirth");
   return 1;
}

int isMagic(){ return 1; }
int drop(){ return 1;}