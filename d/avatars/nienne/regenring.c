#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("white-gold ring");
   set_id(({ "ring","ring of regeneration","gold ring","ring of vines","white gold ring","white-gold ring","white-gold ring of vines" }));
   set_short("%^BOLD%^%^WHITE%^Ri%^CYAN%^n%^WHITE%^g of %^YELLOW%^Re%^GREEN%^g%^YELLOW%^ener%^GREEN%^a%^YELLOW%^tion%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^whi%^CYAN%^t%^WHITE%^e-gold %^YELLOW%^ring of %^GREEN%^vi%^RESET%^%^GREEN%^ne%^BOLD%^s%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^This ring is formed of tiny threads of %^WHITE%^white-gold%^CYAN%^, woven around and back upon each other like tendrils of %^GREEN%^v%^RESET%^%^GREEN%^in%^BOLD%^e%^CYAN%^. Indeed, a few offshoots support glittering leaves of metal. A sprinkling of emerald dust breathes a lifelike quality into the piece, by way of a gentle %^RESET%^%^GREEN%^vi%^BOLD%^r%^RESET%^%^GREEN%^id%^YELLOW%^i%^RESET%^%^GREEN%^an %^BOLD%^%^CYAN%^sheen sparkling across its surface.%^RESET%^\n");
   set_weight(0);
   set_value(15200);
   set_lore("Extremely rare and prized, such rings are a more powerful variant of rings of fast healing. While these lesser rings work to heal the wounds of the wearer, the greater Ring of Regeneration can actually cause the wearer to regrow entire limbs, even after only a short while of wearing.");
   set_property("lore difficulty",14);
   set_type("ring");
   set_limbs(({"left hand","right hand"}));
   set_size(2);
   set_wear("%^YELLOW%^A feeling of energy and vitality fills you.%^RESET%^");
   set_remove("%^YELLOW%^You feel strangely... normal, again.%^RESET%^");
   set_heart_beat(7);
}

void heart_beat() {
   int maxhp, currhp;
   if(!TO->query_worn()) return;
   if(!userp(ETO)) return;
   maxhp = (int)ETO->query_max_hp();
   currhp = (int)ETO->query_hp();
   if(currhp >= maxhp) return;
   if(random(50) < 20) {
     tell_object(ETO,"%^YELLOW%^A pulse of invigorating energy runs through you!%^RESET%^");
     TO->set_property("magic",1);
     ETO->do_damage("torso",(-1)*(roll_dice(2,4)));
     TO->set_property("magic",-1);
   }
}
