#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create() {
   ::create();
   set_name("mithril platemail");
   set_id(({"plate","platemail","elven plate","elven platemail","mithril platemail","mithril plate","suit of plate","suit","ornate suit","suit of platemail","suit of mithril platemail"}));
   set_short("%^RESET%^%^GREEN%^E%^BOLD%^lv%^RESET%^%^GREEN%^en Pl%^CYAN%^at%^GREEN%^ema%^BOLD%^i%^RESET%^%^GREEN%^l%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^an %^GREEN%^o%^BOLD%^rn%^RESET%^%^GREEN%^ate %^CYAN%^suit of %^BOLD%^%^WHITE%^mith%^YELLOW%^r%^WHITE%^il %^RESET%^%^CYAN%^platemail%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This breathtaking suit of plate is crafted of %^BOLD%^%^WHITE%^mith%^YELLOW%^r"
"%^WHITE%^il%^RESET%^%^CYAN%^, treated and polished to give a %^BOLD%^%^WHITE%^br%^RESET%^il%^BOLD%^%^WHITE%^"
"liant whi%^YELLOW%^t%^WHITE%^e shine %^RESET%^%^CYAN%^that reflects its surroundings like a mirror.  It seems "
"precisely cut to fit a %^MAGENTA%^sl%^RED%^e%^MAGENTA%^nder %^CYAN%^frame, and would certainly not be tall "
"enough to fit a normal human.  A delicately fitted suit of %^RESET%^chainmail %^CYAN%^and %^ORANGE%^padding "
"%^CYAN%^resides underneath the armor itself, to protect the wearer from discomfort.  The articulated metal "
"plates of the suit form only a %^BOLD%^%^BLUE%^thin shell%^RESET%^%^CYAN%^, that despite its light weight "
"seems nearly impractical to protect against forceful blows, though it is stronger than steel to the touch.  "
"Delicate and graceful in shape, it seems more a piece of %^RESET%^%^ORANGE%^artw%^YELLOW%^o%^RESET%^%^ORANGE%^"
"rk%^CYAN%^ than armor, with fluted shoulders and ornate raised embossing.  Central parts of the armor have "
"been left undecorated, further enhancing the elaborate pattern that traces across the left breast and down "
"the side of the plates.  It depicts a swirling image of %^GREEN%^vin%^BOLD%^e%^RESET%^%^GREEN%^s%^CYAN%^, "
"amongst which dance the splayed wings of a myriad of %^BOLD%^birds%^RESET%^%^CYAN%^, flitting amongst the "
"%^MAGENTA%^bl%^BOLD%^o%^RESET%^%^MAGENTA%^ss%^BOLD%^o%^RESET%^%^MAGENTA%^ms %^CYAN%^that spread their petals "
"across the plates of armor.  The suit could certainly be called nothing short of %^BOLD%^ma%^BLUE%^g%^CYAN%^"
"nifi%^GREEN%^c%^CYAN%^ent%^RESET%^%^CYAN%^, and undoubtably both magic and a mastery of smithwork both had a "
"hand in its creation.\n%^RESET%^");
   set_lore("Such armor could only be the work of elvenkind, and these suits are extremely rare, even more so "
"than the chainmail armors crafted by their skilled artisans.  As most elvenkind prefer the lighter weight and "
"easier movement that chainmail allows, it is only a rare few among their warriors and cavaliers that request "
"such armor, and each is handcrafted for its owner.  This particular suit was not crafted at all, but a divine "
"gift to Rivorndir from Corellon himself, for his efforts in restoring the cursed members of his kindred.");
   set_property("lore",22);
   set_weight(40);
   set_value(20000);
   set_property("enchantment",5);
   set_item_bonus("charisma",2);
   set_item_bonus("magic resistance",1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_struck((:TO,"strikeme":));
}

int wearme() {
   if((string)ETO->query_name() != "rivorndir" && !avatarp(ETO)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The beautiful platemail is obviously not designed to fit one such as "
"you.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The beautiful platemail was obviously designed for someone other than "
+ETO->QCN+"%^BOLD%^%^WHITE%^, as it simply does not fit "+ETO->QO+".%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The platemail settles comfortably into place, as if it were made to fit "
"you.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^The ornate suit of platemail settles into place around "+ETO->QCN+"%^BOLD%^"
"%^WHITE%^, as if it were made to fit "+ETO->QO+" perfectly.%^RESET%^",ETO);
   return 1;
}

int removeme() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You feel a reluctance to remove the ornate platemail.%^RESET%^");
   return 1;
}

int strikeme(int damage, object what, object who) {
   if(!random(3)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^So well-crafted is your mithril platemail, that it deflects "
+who->QCN+"%^BOLD%^%^WHITE%^'s blow harmlessly aside!%^RESET%^");
     tell_object(who,"%^BOLD%^%^WHITE%^"+ETO->QCN+"%^BOLD%^%^WHITE%^'s mithril platemail is so well-crafted "
"that it deflects your blow harmlessly aside!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"%^BOLD%^%^WHITE%^'s mithril platemail is so well-crafted "
"that it deflects "+who->QCN+"%^BOLD%^%^WHITE%^'s blow harmlessly aside!%^RESET%^",({who,ETO}));
     return (-1)*damage;
   }
   return 1;
}
