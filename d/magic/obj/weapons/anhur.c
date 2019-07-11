//Anhur Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create(){
   ::create();
   set_name("Righteous Vindication");
   set_short("%^BOLD%^%^BLUE%^R%^CYAN%^i%^WHITE%^g%^CYAN%^h%^BLUE%^"+
      "t%^CYAN%^e%^WHITE%^o%^CYAN%^u%^BLUE%^s %^RED%^V%^RESET%^"+
      "%^RED%^i%^BOLD%^n%^RESET%^%^RED%^d%^BOLD%^i%^RESET%^%^RED%^"+
      "c%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^i%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^");
   set_id(({"khopesh","sword","weapon","vindication","righteous vindication","Righteous Vindication"}));
   set_long("%^RED%^Crafted from %^BOLD%^fever iron%^RESET%^"+
      "%^RED%^, the blade of this khopesh curves and is sharpened "+
      "on both sides, making it a viscious weapon.  The fever iron "+
      "has been etched with images of %^YELLOW%^lightning bolts "+
      "%^RESET%^%^RED%^interspersed with wheeling %^BOLD%^hawks"+
      "%^RESET%^%^RED%^, all of which have been filled with "+
      "molten %^YELLOW%^gold %^RESET%^%^RED%^to make them glitter "+
      "as the blade whirls through the air.  The handle has been "+
      "wrapped in %^BOLD%^%^BLACK%^black leather %^RESET%^%^RED%^"+
      "and topped with a %^BOLD%^scarlet cord%^RESET%^%^RED%^, the "+
      "ends of which are left to dangle and support spiked spheres "+
      "of %^BOLD%^fever iron%^RESET%^%^RED%^ that are used to "+
      "rake the skin of an opponent.%^RESET%^");
   set_value(0);
   set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;

   if(!random(10)){
      tell_object(ETO,"%^BOLD%^%^RED%^The spheres of %^RESET%^%^RED%^"+
         "fever iron %^BOLD%^tear into "+targ->QCN+" as you whirl "+
         "the khopesh against "+targ->QP+" skin!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^RED%^As "+ETOQCN+" slices into "+
         "you with "+ETO->QP+" khopesh, small spheres of %^RESET%^"+
         "%^RED%^fever iron %^BOLD%^tear into your flesh as well!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" slices "+ETO->QP+" "+
         "khopesh deeply into "+targ->QCN+", the movement causing "+
         "small spheres of %^RESET%^%^RED%^fever iron %^BOLD%^to "+
         "gash "+targ->QO+" as well!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(4)+4);
      return 1;
   }
}