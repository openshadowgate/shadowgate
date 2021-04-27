#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("ebony hairpin");
   set_short("%^BLACK%^%^BOLD%^Black Talon%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^ebony hairpin%^RESET%^");
   set_id(({"hairpin","pin","Hairpin","Pin","ebony hairpin","black talon","black talon hairpin","talon"}));
   set_long("%^MAGENTA%^This elegant hairpin is crafted from a single piece of "
"%^BLACK%^%^BOLD%^flawless ebony%^RESET%^%^MAGENTA%^.  The handle is shaped to fit "
"comfortably within one's hand, and is carved in an ornate fashion, set with tiny "
"chips of %^BOLD%^%^MAGENTA%^am%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^th%^WHITE%^y%^MAGENTA%^st%^RESET%^%^MAGENTA%^ "
"and %^BOLD%^%^WHITE%^di%^CYAN%^a%^WHITE%^mond%^RESET%^%^MAGENTA%^, that glitter darkly in any reflected "
"light.  A smooth, slender point extends from this handle, to be placed through the hair, "
"though this hairpin seems uncharacteristically sharp - it would be best to be careful "
"when trying to wear it.%^RESET%^\n");
   set_weight(4);
   set_value(1025);
   set_ac(0);
   set_type("ring");
   set_limbs(({"head"}));
   set_lore("%^WHITE%^%^BOLD%^A particularly distinct accessory created by crafters hired "
"by the temple of the Black Hand, and gifted to the reknowned assassin Tatsu'ei, as a "
"reward for her service in the temple's name.  Some rumours tell it to be more than simply "
"a pretty hairpiece, but quite dangerous in her hands also.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_property("enchantment",1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
    add_action("wield_fun","wield");
}

int wear_fun() {
   if(!avatarp(ETO)) return 0;
   tell_object(ETO,"%^MAGENTA%^You twist your hair into place and secure it with the hairpin, careful "
"not to harm yourself on its sharp tip.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" twists "+ETO->QP+" hair into place and secures it carefully "
"with the hairpin.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You slide the hairpin free, letting your hair fall loose again.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" slides the hairpin free, letting "+ETO->QP+" hair fall "
"loose.%^RESET%^",ETO);
   return 1;
}

int wield_fun(string str) {
   object ob,*names;
   int i;
   if (!str) {
     notify_fail("Wield what?");
     return 0;
   }
   if (member_array(str,TO->query_id()) == -1) {
     notify_fail("You can't wield that.\n");
     return 0;
   }
   if(ETO->query_highest_level() < 15) {
     notify_fail("You can't make sense of how to wield that.");
     return 0;
   }
   ob = new("/d/avatars/nienne/hairpin2.c");
   ob->move(ETO);
   if ((int)TO->query_property("enchantment") < 0) {
     ob->remove_property("enchantment");
     ob->set_property("enchantment",(int)TO->query_property("enchantment"));
   }
   else {
     while((int)ob->query_property("enchantment") != 3) {
       ob->remove_property("enchantment");
       ob->set_property("enchantment",3);
     }
   }
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       ob->add_identified(names[i]);
     }
   }
   ETO->force_me("wield black talon dagger");
   TO->remove();
   return 1;
}
