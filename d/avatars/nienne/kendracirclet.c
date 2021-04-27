#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("silvery circlet");
   set_id(({ "circlet","Circlet","coronet","Coronet","silver circlet","silvery circlet","coronet of illumination","Coronet of Illumination" }));
   set_short("%^WHITE%^%^BOLD%^C%^RESET%^%^WHITE%^o%^BLACK%^%^BOLD%^r%^RESET%^%^WHITE%^o%^WHITE%^%^BOLD%^n%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^t %^RESET%^%^WHITE%^o%^WHITE%^%^BOLD%^f %^CYAN%^I%^WHITE%^l%^CYAN%^lu%^WHITE%^m%^CYAN%^in%^WHITE%^a%^CYAN%^ti%^WHITE%^o%^CYAN%^n%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^s%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^l%^RESET%^%^WHITE%^v%^WHITE%^%^BOLD%^e%^RESET%^%^WHITE%^r%^BLACK%^%^BOLD%^y %^RESET%^%^WHITE%^c%^WHITE%^%^BOLD%^i%^RESET%^%^WHITE%^r%^BLACK%^%^BOLD%^c%^RESET%^%^WHITE%^l%^WHITE%^%^BOLD%^e%^RESET%^%^WHITE%^t%^RESET%^");
   set_long("%^MAGENTA%^This circlet is nothing more than a delicate band of %^WHITE%^%^BOLD%^s%^RESET%^"
"%^WHITE%^il%^BOLD%^ve%^RESET%^%^WHITE%^r%^MAGENTA%^, which would rest comfortably atop one's head. The only "
"decoration to the item is near the front, where the band dips forward over the wearer's brow, clasping a "
"single perfect %^WHITE%^%^BOLD%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^%^MAGENTA%^. Despite its plain "
"appearance, it is obviously of very high quality crafting.%^RESET%^\n");
   set_limbs(({"head"}));
   set_weight(0);
   set_value(10);
   set_ac(0);
   set_property("enchantment",3);
   set_item_bonus("magic resistance",20);
   set_item_bonus("spell damage resistance",200);
   set_item_bonus("damage resistance",200);
   set_item_bonus("sight bonus",5);
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_property("no steal",1);
   set_property("no offer",1);
   set_property("no animate",1);
}

void init(){
   ::init();
   add_action("trigger_fun","now");
}

int wear_fun() {
   if(!avatarp(ETO)) return 0;
   tell_room(EETO,"%^WHITE%^%^BOLD%^An almost tangible aura flickers into being around "+ETOQCN+" as "
+ETO->QS+" slips the circlet over "+ETO->QP+" brow.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^An almost tangible aura flickers into being around you, as your "
"vision becomes startlingly clear.%^RESET%^");
   return 1;
}

int remove_fun() {
   tell_room(EETO,"%^WHITE%^%^BOLD%^The near tangible aura fades from around "+ETOQCN+".%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^The near tangible aura seems to fade from around you, as your "
"vision returns abruptly to normal.%^RESET%^");
   return 1;
}

int trigger_fun() {
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(!avatarp(TP)) return 0;
   if(!TO->query_worn()) return 0;

   tell_room(ETP,"%^MAGENTA%^The priestess clenches a fist and then casts it forward, and an invisible wave of force sends everyone to their knees.");
   foreach(object liv in all_living(ETP)) { if(!objectp(liv)) continue; liv->cease_all_attacks(); continue; }
   return 1;
}
