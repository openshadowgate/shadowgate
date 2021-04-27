#include <std.h>
#include <daemons.h>
inherit PARMOUR;

void create() {
   ::create();
   set_name("cloak");
   set_id(({"cloak","shroud","blue cloak","magnificent cloak","sapphire cloak","sapphire-blue cloak","sapphire blue cloak","shroud of arcanistry","Shroud of Arcanistry"}));
   set_short("%^BOLD%^%^WHITE%^S%^RESET%^h%^BOLD%^r%^RESET%^ou%^BOLD%^d of %^CYAN%^A%^BLUE%^r%^CYAN%^c%^RESET%^%^CYAN%^a%^BLUE%^%^BOLD%^n%^RESET%^%^BLUE%^i%^CYAN%^s%^BOLD%^t%^WHITE%^r%^CYAN%^y%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLUE%^magnificent sa%^RESET%^%^BLUE%^p%^BOLD%^phire-b%^CYAN%^l%^BLUE%^ue cloak%^RESET%^");
   set_long("%^GREEN%^This cloak is long and %^MAGENTA%^fl%^RED%^ui%^MAGENTA%^d%^GREEN%^, likely able to enshroud the "
"entire body of a normal person if it were pulled closed.  Dyed a shade of vivid %^BOLD%^%^BLUE%^sa%^CYAN%^p%^BLUE%^phire "
"bl%^RESET%^%^BLUE%^u%^BOLD%^e%^RESET%^%^GREEN%^, it appears to be made of fine satin that ripples like %^CYAN%^l%^BOLD%^"
"i%^WHITE%^qu%^CYAN%^i%^RESET%^%^CYAN%^d%^GREEN%^.  Its glossy outer surface is marked with tiny pinpoints of %^RESET%^s"
"%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r %^GREEN%^that glitter with movement, like a tiny galaxy of stars.  It is "
"gathered at the throat with a fine %^BOLD%^%^WHITE%^mithr%^CYAN%^i%^WHITE%^l %^RESET%^%^GREEN%^collar, which maintains "
"the garment's shape and pulls the cloth upwards to frame the neck.  A delicate chain holds it in place across the neck, "
"with a %^RED%^de%^MAGENTA%^c%^RED%^ora%^MAGENTA%^t%^RED%^ive %^GREEN%^upwards curl of metal at either side.  Sewn into "
"the inner layer of the cloak is a small %^ORANGE%^pocket%^GREEN%^, capable of keeping a few little items safe and "
"hidden.%^RESET%^\n");
   set_lore(".");
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
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_heart_beat(1);
   set_max_internal_encumbrance(10);
}

int wear_fun() {
   if(ETO->query_level() > 25) {
     tell_object(ETO,"%^BOLD%^%^BLUE%^The cloak swirls about your shoulders in a sh%^RESET%^%^BLUE%^i%^BOLD%^mmer%^CYAN%^i%^BLUE%^ng wave.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" %^BOLD%^%^BLUE%^swirls the "
"cloak about "+ETO->QP+" shoulders in a sh%^RESET%^%^BLUE%^i%^BOLD%^mmer"
"%^CYAN%^i%^BLUE%^ng wave.%^RESET%^",ETO);
     return 1;
   }
   tell_object(ETO,"The magnificent cloak doesn't seem to fit you.");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^BOLD%^%^BLUE%^It's a disappointment to set such a "
"magnificent garment aside.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" %^BOLD%^%^BLUE%^looks almost "
"disappointed to set aside the cloak.%^RESET%^",ETO);
   return 1;
}

void heart_beat() {
    int xx,yy;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    if(!TO->query_worn()) return;
    if(ETO->query_invis()) return;

    xx = random(750);
    yy = random(60);
    
    if((xx > 745)) {
      switch(yy) {
        case 0..9:
          tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s cloak ripples "
"softly, its surface like a sheet of %^RESET%^%^BLUE%^liquid"
"%^BOLD%^%^BLUE%^.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^Your cloak ripples softly, its "
"surface like a sheet of %^RESET%^%^BLUE%^liquid%^BOLD%^%^BLUE%^.%^RESET%^");
          break;
        case 10..19:
          tell_room(EETO,"%^BOLD%^%^BLUE%^A wink of %^RESET%^lig"
"%^BOLD%^%^WHITE%^h%^RESET%^t %^BOLD%^%^BLUE%^passes across the silver-spotted "
"surface of "+ETO->QCN+"'s cloak and is gone, as fleeting as a falling "
"star.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^A wink of %^RESET%^lig"
"%^BOLD%^%^WHITE%^h%^RESET%^t %^BOLD%^%^BLUE%^passes across the silver-spotted "
"surface of your cloak and is gone, as fleeting as a falling star.%^RESET%^");
          break;
        case 20..29:
          tell_room(EETO,"%^BOLD%^%^BLUE%^Glittering light plays across the "
"%^WHITE%^si%^RESET%^l%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^WHITE%^ry "
"%^BLUE%^pinpoints of "+ETO->QCN+"'s cloak.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^Glittering light plays across the "
"%^WHITE%^si%^RESET%^l%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^WHITE%^ry "
"%^BLUE%^pinpoints of your cloak.%^RESET%^");
          break;
        case 30..39:
          tell_room(EETO,"%^BOLD%^%^BLUE%^A brief %^CYAN%^cr%^WHITE%^a"
"%^CYAN%^ckle %^BLUE%^of energy passes along the metal collar of "+ETO->QCN+
"'s cloak.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^A brief %^CYAN%^cr%^WHITE%^a"
"%^CYAN%^ckle %^BLUE%^of energy passes along the metal collar of your "
"cloak.%^RESET%^");
          break;
        case 40..49:
          tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s cloak swirls gently "
"about "+ETO->QP+" frame, even with no breeze or movement to lift its "
"folds.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^Your cloak swirls gently about "
"your frame, even with no breeze or movement to lift its folds.%^RESET%^");
          break;
        case 50..59:
          tell_room(EETO,"%^BOLD%^%^BLUE%^The patterning of silver pinpoints "
"on "+ETO->QCN+"'s cloak shifts and swirls like a galaxy of %^WHITE%^sta"
"%^YELLOW%^r%^WHITE%^s%^BLUE%^.%^RESET%^",ETO);
          tell_object(ETO,"%^BOLD%^%^BLUE%^The patterning of silver pinpoints "
"on your cloak shifts and swirls like a galaxy of %^WHITE%^sta%^YELLOW%^r"
"%^WHITE%^s%^BLUE%^.%^RESET%^");
          break;
      }
    }
}
