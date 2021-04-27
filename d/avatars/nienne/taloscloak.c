#include <std.h>
#include <daemons.h>
inherit PARMOUR;

void create() {
   ::create();
   set_name("shroud");
   set_id(({"cloak","shroud","black cloak","black shroud","ragged shroud","ragged black shroud","shroud of the destroyer","Shroud of the Destroyer"}));
   set_short("%^BOLD%^%^WHITE%^S%^YELLOW%^h%^BOLD%^%^WHITE%^r%^RESET%^o%^BOLD%^%^BLACK%^u%^RESET%^d o%^YELLOW%^f %^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^h%^BOLD%^%^WHITE%^e %^RESET%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^o%^YELLOW%^y%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^ragged black shroud%^RESET%^");
   set_long("%^CYAN%^This cloak is long and %^MAGENTA%^fl%^RED%^ui%^MAGENTA%^d%^CYAN%^, likely able to enshroud the "
"entire body of a normal person if it were pulled closed.  Dyed a shade of %^BOLD%^%^BLACK%^midnight black%^RESET%^%^CYAN%^, "
"it appears to be made of fine satin that ripples like %^CYAN%^l%^BOLD%^i%^WHITE%^qu%^CYAN%^i%^RESET%^%^CYAN%^d%^CYAN%^.  "
"Its glossy outer surface is shot through with %^BOLD%^%^WHITE%^gl%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^aming %^RESET%^%^CYAN%^"
"teardrops and jagged, %^BOLD%^%^YELLOW%^cr%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^ckl%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^ng "
"%^RESET%^%^CYAN%^lines of gold and silver.  The hem is %^RESET%^ragged %^CYAN%^and %^RED%^torn%^CYAN%^, despite the fine "
"quality of the rest of the cloak. It is gathered at the throat with a fine %^BOLD%^%^WHITE%^mithr%^CYAN%^i%^WHITE%^l "
"%^RESET%^%^CYAN%^collar shaped at either side like a bolt of lightning, which maintains the garment's shape and pulls the cloth "
"upwards to frame the neck, held in place across the neck with a small mithril chain.%^RESET%^\n");
   set_lore("Such a cloak, and ones like it, are usually worn as a sign of loyalty to Talos, the Stormlord. While the greatest "
"among his ranks often create or are gifted with enchanted versions of these, that may spark and ripple with energy, even lesser "
"followers will often attempt to create one, even if it is only mundane in nature. Such garments have attracted them the "
"unflattering name of 'Doom Crows' across the realms, as they preach destruction wherever they go.");
   set_property("lore difficulty",25);
   set_limbs(({"neck"}));
   set_weight(2);
   set_value(8200);
   set_size(2);
   set_ac(0);
   set_property("enchantment",4);
   while(TO->query_property("enchantment")< 4){
      remove_property("enchantment");
      set_property("enchantment",4);
   }
   set_item_bonus("charisma",2);
   set_item_bonus("caster level",1);
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_heart_beat(1);
}

int wear_fun() {
   if((string)ETO->query_name() == "pangretor" || avatarp(ETO)) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^The shroud %^BOLD%^%^YELLOW%^cr%^BOLD%^%^WHITE%^a"
"%^BOLD%^%^YELLOW%^ckl%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^s %^BOLD%^%^BLACK%^with energy "
"as you swirl it about your shoulders.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^The shroud %^BOLD%^%^YELLOW%^cr%^BOLD%^%^WHITE%^a"
"%^BOLD%^%^YELLOW%^ckl%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^s %^BOLD%^%^BLACK%^with energy "
"as "+ETO->QCN+" swirls it about "+ETO->QP+" shoulders.%^RESET%^",ETO);
     tell_object(ETO,"%^BOLD%^%^WHITE%^You realise your Lord will grant you the power to "
"conjure an elemental of lightning!%^RESET%^");
     ETO->set_property("talossian elementalist",1);
     return 1;
   }
   tell_object(ETO,"The ragged cloak doesn't seem to fit you.");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^It's a disappointment to set such a "
"magnificent garment aside.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" %^BOLD%^%^BLUE%^looks almost "
"disappointed to set aside the cloak.%^RESET%^",ETO);
   ETO->set_property("talossian elementalist",-1);
   return 1;
}

void heart_beat() {
    int xx,yy;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    if(!TO->query_worn()) return;
    if(ETO->query_invis()) return;

    xx = random(750);
    yy = random(50);
    
    if((xx > 745)) {
      switch(yy) {
        case 0..9:
          tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s ragged cloak ripples, "
"and a sudden thunderous %^RED%^boom %^BLUE%^shakes the area.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^Your ragged cloak ripples, and "
"a sudden thunderous %^RED%^boom %^BLUE%^shakes the area.%^RESET%^");
          break;
        case 10..19:
          tell_room(EETO,"%^BOLD%^%^BLUE%^Glittering light plays across the "
"%^WHITE%^spa%^RESET%^r%^BOLD%^%^BLACK%^kl%^RESET%^i%^BOLD%^%^WHITE%^ng "
"%^BLUE%^teardrops of "+ETO->QCN+"'s cloak.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^Glittering light plays across the "
"%^WHITE%^spa%^RESET%^r%^BOLD%^%^BLACK%^kl%^RESET%^i%^BOLD%^%^WHITE%^ng "
"%^BLUE%^teardrops of your cloak.%^RESET%^");
          break;
        case 20..29:
          tell_room(EETO,"%^BOLD%^%^BLUE%^A brief %^CYAN%^cr%^WHITE%^a"
"%^CYAN%^ckle %^BLUE%^of energy passes along the metal collar of "+ETO->QCN+
"'s cloak.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^A brief %^CYAN%^cr%^WHITE%^a"
"%^CYAN%^ckle %^BLUE%^of energy passes along the metal collar of your "
"cloak.%^RESET%^");
          break;
        case 30..39:
          tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s cloak swirls gently "
"about "+ETO->QP+" frame, even with no breeze or movement to lift its "
"folds.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^Your cloak swirls gently about "
"your frame, even with no breeze or movement to lift its folds.%^RESET%^");
          break;
        case 40..49:
          tell_room(EETO,"%^BOLD%^%^BLUE%^A sudden %^BOLD%^%^WHITE%^bo%^YELLOW%^l"
"%^BOLD%^%^WHITE%^t %^BOLD%^%^BLUE%^of energy runs across the jagged lines on "
+ETO->QCN+"'s cloak, like the crack of lightning across the night sky.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^A sudden %^BOLD%^%^WHITE%^bo%^YELLOW%^l"
"%^BOLD%^%^WHITE%^t %^BOLD%^%^BLUE%^of energy runs across the jagged lines on your "
"cloak, like the crack of lightning across the night sky.%^RESET%^");
          break;
      }
    }
}
