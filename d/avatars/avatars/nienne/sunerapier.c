#include <std.h>
inherit "/d/common/obj/weapon/light_rapier.c";

void create() {
   ::create();
   set_name("silver rapier");
   set_id(({"rapier","silver rapier","elegant rapier","elegant silver rapier","grace","maryssas grace","maryssa's grace"}));
   set_short("%^BOLD%^%^WHITE%^Grace of the %^RESET%^%^ORANGE%^Go%^YELLOW%^ld%^RESET%^%^ORANGE%^en He%^YELLOW%^a%^RESET%^%^ORANGE%^rt%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^elegant %^RESET%^%^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en-hi%^YELLOW%^lt%^RESET%^%^ORANGE%^ed %^BOLD%^%^WHITE%^rapier%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This %^RESET%^%^MAGENTA%^be%^RED%^a%^MAGENTA%^"
"uti%^RED%^f%^MAGENTA%^ul %^BOLD%^%^WHITE%^weapon seems more designed for "
"show than actual combat. It consists of a narrow %^RESET%^si%^BOLD%^%^BLACK%^"
"lve%^RESET%^ry %^BOLD%^%^WHITE%^blade that is highly flexible, yet "
"surprisingly strong, that ends in a sharply-piercing tip. It has been "
"secured within an %^RESET%^%^CYAN%^or%^BOLD%^na%^RESET%^%^CYAN%^te "
"%^BOLD%^%^WHITE%^basket hilt plated in %^RESET%^%^ORANGE%^go%^YELLOW%^l"
"%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^. The hilt itself forms a protection "
"for the wielder's hand, and has been shaped into a meshwork of %^GREEN%^"
"vines %^WHITE%^and %^RESET%^%^GREEN%^lea%^BOLD%^v%^RESET%^%^GREEN%^es%^BOLD%^"
"%^WHITE%^, each blossoming into a beautiful %^RESET%^%^RED%^ro%^MAGENTA%^s"
"%^RED%^e %^BOLD%^%^WHITE%^set with tiny flecks of %^RED%^r%^RESET%^%^RED%^ub"
"%^BOLD%^y d%^RESET%^%^RED%^us%^BOLD%^t%^WHITE%^. It would be a terrible "
"shame to ruin such a weapon, but it seems unusually resistant to "
"damage.%^RESET%^\n");
   set_lore("This weapon is actually more than two centuries old, and was "
"originally crafted for a half-elven bardess known only as Maryssa of the "
"Golden Heart. Long faithful to Sune Firehair, Maryssa eventually retired "
"from her days as a defender of the church, and the rapier was passed down "
"through other faithful members of the faith, so as to always serve Lady "
"Love's will. It disappeared following Sune's banishment from the realms, but "
"must have been kept protected by the mortals who remained behind, as it has "
"been carefully preserved to this day.\n");
   set_property("lore difficulty",19);
   set_value(650);
   set_item_bonus("armor bonus",1);
   set_property("enchantment",1);
   set_wield((:TO,"wield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun() {
   TO->set_overallStatus(100);
   return 1;
}

int hit_fun(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You bring the rapier over in a "
"%^RESET%^%^MAGENTA%^gra%^RED%^c%^MAGENTA%^eful %^BOLD%^%^WHITE%^half-arc, "
"and use the momentum to carry you forward in a thrust at "
+targ->QCN+"!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" brings "+ETO->QP+
" rapier over in a %^RESET%^%^MAGENTA%^gra%^RED%^c%^MAGENTA%^eful "
"%^BOLD%^%^WHITE%^half-arc, and uses the momentum to carry "+ETO->QO+"self "
"forward in a thrust at you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" brings "+ETO->QP+
" rapier over in a %^RESET%^%^MAGENTA%^gra%^RED%^c%^MAGENTA%^eful "
"%^BOLD%^%^WHITE%^half-arc, and uses the momentum to carry "+ETO->QO+"self "
"forward in a thrust at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
      targ->do_damage(targ->return_target_limb(),roll_dice(2,3)+4);
      return 1;
   }
   if(!random(10)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^As you pierce "+targ->QCN+" with the "
"rapier, a tracing of %^RESET%^%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en "
"%^BOLD%^%^WHITE%^light glitters swiftly over its ornate basket hilt, and a "
"feeling of %^RESET%^%^CYAN%^in%^BOLD%^v%^RESET%^%^CYAN%^igor%^BOLD%^a"
"%^RESET%^%^CYAN%^tion %^BOLD%^%^WHITE%^fills you!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^WHITE%^As "+ETO->QCN+" pierces you with "
+ETO->QP+" rapier, you notice a tracing of %^RESET%^%^ORANGE%^gol%^YELLOW%^d"
"%^RESET%^%^ORANGE%^en %^BOLD%^%^WHITE%^light that glitters swiftly over its "
"ornate basket hilt!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^As "+ETO->QCN+" pierces "+targ->QCN+
" with "+ETO->QP+" rapier, you notice a tracing of %^RESET%^%^ORANGE%^gol"
"%^YELLOW%^d%^RESET%^%^ORANGE%^en %^BOLD%^%^WHITE%^light that glitters "
"swiftly over its ornate basket hilt!%^RESET%^",({ETO,targ}));
      dam = random(5)+6;
      ETO->do_damage("torso",(-1)*dam);
      targ->do_damage(targ->return_target_limb(),dam);
      return 1;
   }
}
