#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("battlehorn");
   set_id(({"horn","dwarven horn","Dwarven Horn","bone horn","horn of bone","sturdy horn","sturdy horn of bone"}));
   set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^ORANGE%^wa%^BOLD%^%^BLACK%^rv%^RESET%^%^ORANGE%^en %^BOLD%^%^BLACK%^Ba%^RESET%^%^ORANGE%^tt%^BOLD%^%^BLACK%^le%^RESET%^%^ORANGE%^ho%^BOLD%^%^BLACK%^rn%^RESET%^");
   set_obvious_short("%^RESET%^A sturdy horn of bone%^RESET%^");
   set_long("%^RED%^This looks like it was once the horn of some massive beast, from its size and substance.  "
"Its outer surface is an %^WHITE%^off-white %^RED%^color remeniscent of %^BOLD%^%^WHITE%^ivory%^RESET%^%^RED%^"
", with a light polished sheen and a natural texture that is lightly pebbled to touch, though slightly %^CYAN%^"
"cold%^RED%^.  It has been hollowed out inside, forming a smooth and precise shape like that of a heraldric "
"horn, leading to a small hole at the tip that would probably serve as a good mouthpiece.  Along its side have "
"been etched several %^ORANGE%^dw%^RED%^ar%^ORANGE%^vi%^RED%^sh %^ORANGE%^ru%^RED%^ne%^ORANGE%^s%^RED%^.  A "
"thick cord of%^ORANGE%^ leather%^RED%^ has been attached to it at either side, probably to allow it to be "
"worn to be carried around.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This great horn was crafted by the dwarf warrior Nalthic StoneAxe, on "
"3 Harvestdays, 668 SG.  It was carved from the horn that was taken by his own hand from the great white "
"dragon Muln, and shaped into its current form by his skills of dwarven craftsmanship.");
   set_property("lore difficulty",11);
   set_weight(2);
   set_value(0);
   set_ac(0);
   set_size(1);
   set_type("ring");
   set_limbs(({"neck"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_language("dwarvish");
   set_read("%^BLUE%^'%^BOLD%^%^RED%^Nalthic StoneAxe - BUGGER OFF!%^RESET%^%^BLUE%^'%^RESET%^");
}

void init() {
   ::init();
   add_action("blow_fun","blow");
}

int wear_fun() {
   tell_object(ETO,"%^ORANGE%^You drape the horn around your neck on its leather strap.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" drapes the leather strap of the horn around "+ETO->QP+" neck.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You remove the strap of the horn from around your neck.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" lifts the strap of the horn from around "+ETO->QP+" neck.",ETO);
   return 1;
}

int blow_fun(string str) {
   object *inven, *my_party;
   int i;
   string thisparty;
   my_party = ({});
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 0;
   }
   if (TP->query_gagged()) {
     return notify_fail(TP->query_gagged_message());
     return 0;
   }
   if (!str) {
     notify_fail("What do you want to blow?");
     return 0;
   }
   if (str != "horn" && str != "battlehorn") {
     notify_fail("You can't blow that.");
     return 0;
   }
   if (!TO->query_worn()) {
     tell_object(TP,"You should probably wear that first to secure it.");
     return 1;
   }
   if ((string)TP->query_race() != "dwarf") {
     tell_object(TP,"You can't seem to make sense of how to sound the battlehorn.");
     return 1;
   }
   if (sizeof(TP->query_attackers()) > 0) {
     tell_object(TP,"You can't do that in the middle of a fight!");
     return 1;
   }
   tell_object(TP,"%^BLUE%^You raise the horn to your lips and blow with all your might!%^RESET%^");
   tell_room(ETP,"%^BLUE%^"+TP->QCN+" raises the horn to "+TP->QP+" lips and blows with all "+TP->QP+" might!"
"%^RESET%^",TP);
   message("info","%^RED%^The sound of a great battlehorn echoes throughout the area!%^RESET%^",nearbyRoom(ETP,3));
   return 1;
}
