#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("bracers");
   set_id(({"bracers","silver bracers","shining bracers","shining silver bracers","bands","bands of fortune","bands of fortunes favor","bands of favor","bands of fortune's favor"}));
   set_short("%^WHITE%^%^BOLD%^Ba%^RESET%^%^WHITE%^nd%^BOLD%^s o%^RESET%^%^WHITE%^f F%^BOLD%^or%^RESET%^%^WHITE%^tu%^BOLD%^ne%^RESET%^%^WHITE%^'s %^BOLD%^Fa%^RESET%^%^WHITE%^vo%^BOLD%^r%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^s%^RESET%^%^WHITE%^hi%^BOLD%^ni%^RESET%^%^WHITE%^ng %^BOLD%^si%^RESET%^%^WHITE%^lv%^BOLD%^er %^RESET%^%^WHITE%^br%^BOLD%^ac%^RESET%^%^WHITE%^er%^BOLD%^s%^RESET%^");
    set_long("%^CYAN%^%^BOLD%^These bracers are beatifully crafted of %^WHITE%^s%^RESET%^%^WHITE%^il%^BOLD%^ve"
"%^RESET%^%^WHITE%^r m%^BOLD%^et%^RESET%^%^WHITE%^al%^BOLD%^%^CYAN%^, polished to a brilliant sheen.  They are "
"fairly long as bracers go, designed to protect almost the entire forearm, although how strong a protection "
"silver metal could offer is questionable.  The clasps are fitted upon the underside of each bracer, designed "
"to be invisible when clasped shut around the forearms.  Across the surface of each are etched ornate "
"patterns, so elaborate as to probably be of %^RESET%^%^GREEN%^elven crafting%^BOLD%^%^CYAN%^.  They depict a "
"myriad of magical creatures, from %^WHITE%^unicorns %^CYAN%^to %^RESET%^%^CYAN%^faerie dragons%^BOLD%^, all "
"further enhanced by the fine sprinkling of %^BLUE%^sap%^RESET%^%^BLUE%^p%^BOLD%^hire dust %^CYAN%^that "
"outlines each engraved image.\n%^RESET%^"); 
   set_lore("%^WHITE%^%^BOLD%^Only one tale mentions bracers that resemble these.  They were once the "
"possession of the elven rogue Dalarianeth, a nomadic traveller with an uncanny reputation for good luck.  "
"Throughout his adventures the recounts tell of his many brushes with death, from shipwreck to his encounter "
"with a great black dragon.  At some point his luck must have failed him, however, as he obviously no longer "
"carries these stunning bracers with him.%^RESET%^\n");
   set_property("lore difficulty",13);
   set_type("bracer");
   set_limbs(({"torso"}));
   set_weight(10);
   set_ac(1);
   set_size(2);
   set_property("enchantment",4);
   set_value(4500);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
}

int check() {
   ::check();
   if((string)ETO->query_diety() != "tymora" && !avatarp(ETO)) {
     tell_object(ETO,"You can't seem to fit the bracers around your arms!");
     return 0;
   }
   tell_room(EETO,"%^BLUE%^%^BOLD%^The silver metal %^WHITE%^glitters%^BLUE%^ as "+ETOQCN+" places the bracers "
"around "+ETO->QP+" arms.%^RESET%^",ETO);
   tell_object(ETO,"%^BLUE%^%^BOLD%^The silver metal %^WHITE%^glitters%^BLUE%^ as you clasp them around your "
"arms.%^RESET%^");
   ETO->set_property("magic resistance",5);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" looks almost disappointed to remove the bracers.%^RESET%^",ETO);
   tell_object(ETO,"%^BLUE%^%^BOLD%^The bracers' %^WHITE%^shine %^BLUE%^from your bracers seems to dull as you "
"remove them.%^RESET%^");
   ETO->set_property("magic resistance",-5);
   return 1;
}

void init() {
   ::init();
   add_action("stab_fun","stab");
}

int stab_fun(string str) {
   if(!TP->is_class("thief")) return 0;
   if(!str) return 0;
   if(!TO->query_worn()) return 0;
   if(sizeof(TP->query_attackers()) > 0) return 0;
   if (TP->query_bound() || TP->query_tripped()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!random(3)) return 0;

   if (present(str,EETO) && sizeof(TP->query_wielded())) {
     tell_room(ETP,"%^BLUE%^%^BOLD%^"+TP->QCN+"'s weapons sparkle with a %^WHITE%^silver sheen %^BLUE%^as "
+TP->QS+" strikes!%^RESET%^",TP);
     tell_object(TP,"%^BLUE%^%^BOLD%^Your weapons sparkle with a %^WHITE%^silver sheen %^BLUE%^as you strike!"
"%^RESET%^");
   }
   return 0;
}
