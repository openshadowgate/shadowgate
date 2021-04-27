#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("bracers");
   set_id(({"bracers","moonstone bracers","etched bracers","etched moonstone bracers","bracers of lunar radiance"}));
   set_short("%^WHITE%^%^BOLD%^Br%^CYAN%^ac%^WHITE%^ers of Lu%^CYAN%^na%^WHITE%^r Ra%^CYAN%^di%^WHITE%^anc%^CYAN%^e%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^et%^RESET%^%^WHITE%^ch%^BOLD%^ed mo%^RESET%^%^WHITE%^on%^BOLD%^s"
"%^RESET%^%^WHITE%^to%^BOLD%^ne br%^RESET%^%^WHITE%^ace%^BOLD%^rs%^RESET%^");
    set_long("%^CYAN%^%^BOLD%^These bracers are a striking piece of craftsmanship, and are made entirely of "
"solid moonstone.  The %^WHITE%^%^BOLD%^mi%^RESET%^%^WHITE%^l%^BOLD%^ky-w%^RESET%^%^WHITE%^h%^BOLD%^ite "
"%^CYAN%^surface has been polished to a flawless shine, and the hinges are so perfectly shaped that when they "
"are clasped beneath the wearer's forearms, the hingeline disappears entirely from view.  Across the surface "
"of the bracers themselves, small etchings form the shapes of various phases of the moon in elven-styled "
"artistry, and are lined with %^WHITE%^%^BOLD%^molten silver%^CYAN%^ to highlight each image.  The bracers are "
"truly stunning to behold.\n%^RESET%^"); 
   set_lore("%^WHITE%^%^BOLD%^Only rare accounts in history ever mention bracers such as these.  They speak "
"of the bracers as being a gift of the MoonMaiden to a faithful follower, imbued with the moon's own brilliant "
"radiance.  Rumours tell that the bracers can guide a truly faithful wearer, granting them the insight "
"and protection of Selune herself.\n");
   set_property("lore difficulty",13);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("magic resistance",1);
   set_item_bonus("athletics",5);
   set_item_bonus("attack bonus",4);
   set_value(2590);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
}

int check() {
   ::check();
   if((int)ETO->query_highest_level() < 30) {
     tell_object(ETO,"You can't seem to fit the bracers around your arms!");
     return 0;
   }
   if((string)ETO->query_diety() != "selune") {
     tell_object(ETO,"You can't seem to fit the bracers around your arms!");
     return 0;
   }
   tell_room(EETO,"%^CYAN%^%^BOLD%^The bracers %^WHITE%^glow softly%^CYAN%^ as "+ETOQCN+" places them around "
+ETO->QP+" arms.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^%^BOLD%^The bracers %^WHITE%^glow softly%^CYAN%^ as you clasp them around your "
"arms, reminding you of the past.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^CYAN%^%^BOLD%^The %^WHITE%^glow %^CYAN%^from "+ETOQCN+"'s bracers fades to nothing."
"%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^%^BOLD%^The %^WHITE%^glow %^CYAN%^from your bracers fades to nothing, leaving you "
"with a distinct feeling of loss.%^RESET%^");
   return 1;
}

/*void init() {
   ::init();
   add_action("whirl_fun","whirl");
}

int whirl_fun() {
   object *weapon,ob;
   if(!TP->is_class("ranger")) return 0;
   if(!random(3)) return 0;

   weapon = TP->query_wielded();
   if((weapon == ({}))) return notify_fail("You should wield your weapons for this!\n");

   if (TP->query_bound() || TP->query_tripped() || TP->query_paralyzed()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!(ob = (object)TP->query_current_attacker())) {
      notify_fail("You are not in battle.\n");
      return 0;
   }
   if(TP->query_property("whirled")) return notify_fail("You can't do that again yet");
   if(!TO->query_worn()) return 0;
   tell_room(ETP,"%^CYAN%^%^BOLD%^A %^WHITE%^gentle glow %^CYAN%^appears around "+TP->QCN+"'s weapons, as "
+TP->QS+" strikes out at "+TP->QP+" foes!%^RESET%^",TP);
   tell_object(TP,"%^CYAN%^%^BOLD%^A %^WHITE%^gentle glow %^CYAN%^appears around your weapons, as you strike "
"out at your foes!%^RESET%^");
   return 0;
}*/
