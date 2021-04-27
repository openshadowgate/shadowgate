#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create(){
   ::create();
    set_name("%^BOLD%^%^WHITE%^adamantium longsword%^RESET%^");
    set_id(({ "sword","longsword","long sword","adamantium sword","adamantium longsword","judgements edge","judgement's edge","Judgement's Edge"}));
    set_short("%^BOLD%^%^WHITE%^Jud%^YELLOW%^g%^BOLD%^%^WHITE%^ement's E%^YELLOW%^d%^BOLD%^%^WHITE%^ge%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^gl%^YELLOW%^e%^BOLD%^%^WHITE%^ami%^YELLOW%^n%^BOLD%^%^WHITE%^g adamantium longsword%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The %^CYAN%^excellent %^BOLD%^%^WHITE%^crafting "
"of this weapon is apparent even at a glance, its cruciform outline given to "
"perfect propotion and balance.  Bearing no excessive embellishments, the entire "
"piece has been crafted of %^RESET%^ad%^BOLD%^%^BLACK%^ama%^RESET%^nt"
"%^BOLD%^%^BLACK%^iu%^RESET%^m%^BOLD%^%^WHITE%^, polished to a %^YELLOW%^gleaming "
"%^BOLD%^%^WHITE%^finish.  Its hollow-ground blade sports a single ridge from tip "
"to cross-guard, with a razor-sharp edge running the length of either side.  Fine "
"%^RESET%^%^ORANGE%^leather %^BOLD%^%^WHITE%^wraps the grip, preventing slippage in "
"battle.  Upon the pommel has been marked a simple glyph of a %^BOLD%^%^BLACK%^wolf's "
"head%^BOLD%^%^WHITE%^, over which has been imposed the letter '%^BOLD%^%^GREEN%^M"
"%^BOLD%^%^WHITE%^'.%^RESET%^");
   set_lore("This fine weapon bears the marking of Marakesh Lirath, one of the "
"more skilled weaponcrafters of the Tyrran fold.  Faithful of the church for "
"the better part of three decades, he was once a soldier of their ranks, though "
"after taking an arrow to the knee in battle, he retired to ply his trade at the "
"forge instead.  His weapons still serve as the defense of the foremost members "
"of the Tyrran fold.");
   set_property("lore difficulty",15);
   set_property("enchantment",3);
   set_item_bonus("attack bonus",2);
   set_item_bonus("damage bonus",1);
   set_value(9200);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   tell_object(ETO,"%^YELLOW%^A great feeling of strength and righteousness "
"fills you as you take up the longsword.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" seems filled with confidence as "
+ETO->QS+" lifts the longsword.%^RESET%^",ETO);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^YELLOW%^The rush of confidence fades as you release the "
"longsword.");
   tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" becomes more subdued as "+ETO->QS+
" releases the longsword.%^RESET%^",ETO);
   return 1;
}

int hit_func(object targ) {
   targ = ETO->query_current_attacker();
   if(!objectp(targ) || !objectp(ETO)) return 1;
   if(random(1000) < 200) {
     switch(random(9)) {
        case 0..4:
          tell_object(targ,"%^YELLOW%^Light %^BOLD%^%^CYAN%^gleams off the "
"surface of "+ETO->QCN+"'s blade as "+ETO->QS+" makes a vicious attack upon "
"you!%^RESET%^");
          tell_room(EETO,"%^YELLOW%^Light %^BOLD%^%^CYAN%^gleams off the "
"surface of "+ETO->QCN+"'s blade as "+ETO->QS+" makes a vicious attack upon "
+targ->QCN+"!%^RESET%^",({targ,ETO}));
          tell_object(ETO,"%^YELLOW%^Light %^BOLD%^%^CYAN%^gleams off the "
"surface of your blade as you make a vicious attack upon "+targ->QCN+"!%^RESET%^");
          set_property("magic",1);
          targ->do_damage(targ->return_target_limb(),random(6)+15);
          set_property("magic",-1);
          break;
        case 5..8:
           ETO->execute_attack();
           tell_object(targ,"%^BOLD%^%^RED%^As "+ETO->QCN+" swings "+ETO->QP+
" %^YELLOW%^longsword %^RED%^in a wide arc, "+ETO->QS+" pulls back "+ETO->QP+
"elbow suddenly to make a second quick strike at you!%^RESET%^");
           tell_room(EETO,"%^BOLD%^%^RED%^As "+ETO->QCN+" swings "+ETO->QP+
" %^YELLOW%^longsword %^RED%^in a wide arc, "+ETO->QS+" pulls back "+ETO->QP+
"elbow suddenly to make a second quick strike at "+targ->QCN+"!%^RESET%^",({targ,ETO}));
           tell_object(ETO,"%^BOLD%^%^RED%^As you swing your %^YELLOW%^"
"longsword %^RED%^in a wide arc, you pull back your elbow to make another "
"quick strike at "+targ->QCN+"!%^RESET%^");
           break;
        default:
           break;
      }
   return 1;
   }
}
