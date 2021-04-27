#include <std.h>
inherit "/d/common/obj/weapon/whip.c";

void create() {
    ::create();
   set_id(({"moonlit fire","whip","firewhip""whip of fiery moon","enrapture"}));
   set_name("%^BOLD%^%^RED%^En%^RESET%^%^RED%^r%^BOLD%^ap%^RESET%^%^RED%^t%^BOLD%^u%^RESET%^%^RED%^re%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^A %^CYAN%^hypnotically %^MAGENTA%^beautiful whip with long %^RED%^f%^BOLD%^i%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^%^RED%^y str%^BOLD%^a%^RESET%^%^RED%^nds%^RESET%^");
   set_short("%^BOLD%^%^RED%^En%^RESET%^%^RED%^r%^BOLD%^ap%^RESET%^%^RED%^t%^BOLD%^u%^RESET%^%^RED%^re%^RESET%^");
   set_long("%^RESET%^%^CYAN%^The handle of this beautifully crafted whip has been encrusted with more"
" %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^mm%^RESET%^er%^BOLD%^i%^RESET%^ng %^BOLD%^mo%^CYAN%^o%^WHITE%^n%^RESET%^s"
"%^BOLD%^t%^CYAN%^o%^WHITE%^n%^RESET%^e%^BOLD%^s %^RESET%^%^CYAN%^and %^BOLD%^%^RED%^d%^RESET%^%^RED%^e%^BOLD%^"
"e%^RESET%^%^RED%^p, %^BOLD%^ruby red %^RESET%^%^RED%^f%^BOLD%^i%^RESET%^%^RED%^re op%^BOLD%^a"
"%^RESET%^%^RED%^ls %^CYAN%^than"
" a person could ever hope to count.  Woven around each of the gems in an %^MAGENTA%^intricate pattern %^CYAN%^of"
" %^RED%^hearts %^CYAN%^and %^MAGENTA%^trellises%^CYAN%^, a single strand of %^MAGENTA%^exotic %^YELLOW%^g%^RESET%^"
"%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n lace %^RESET%^%^CYAN%^weaves its way from the tip of the"
" handle to the base.  Extending from the handle, the whip itself is composed of several %^RESET%^s%^BOLD%^i%^RESET%^"
"lky tend%^BOLD%^r%^RESET%^ils %^CYAN%^that are deceptively %^MAGENTA%^beautiful %^CYAN%^in appearance.  Ranging from"
" an %^RESET%^o%^BOLD%^pa%^RESET%^le%^BOLD%^sce%^RESET%^nt s%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r"
" %^CYAN%^resembling the finest of the %^BOLD%^%^WHITE%^moons rays %^RESET%^%^CYAN%^on a %^MAGENTA%^magical"
" %^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^v%^BOLD%^%^BLACK%^en%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ng"
" %^RESET%^%^CYAN%^to the %^BOLD%^%^RED%^d%^RESET%^%^RED%^ee%^BOLD%^p%^RESET%^%^RED%^est of reds %^CYAN%^found"
" in the finest %^RED%^s%^BOLD%^i%^RESET%^%^RED%^lks%^CYAN%^, the colors of each of the twelve strands seem to"
" dance with their own %^MAGENTA%^magnetic beauty.  %^CYAN%^Both %^BOLD%^enchanting %^RESET%^%^CYAN%^and"
" %^MAGENTA%^hypnotic %^CYAN%^at once, this whip has obviously been a collaborative effort of many talented"
" %^MAGENTA%^artisans.%^RESET%^");
   set_lore("%^RESET%^%^RED%^This whip is said to be wielded only by those favored by Lady Firehair, and only those fair enough to be worthy of such a blessing.");
   set("value",7000);
   set_cointype("gold");
   set_property("enchantment",4);  
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   if((int)ETO->query_level() < 25||(int)ETO->query_stats("charisma")<16) {
      tell_object(ETO,"%^RESET%^%^RED%^Disappointment overcomes you as you realize you cannot yet master such a fine weapon.");
                return 0;
   }
      tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETOQCN+" seems to become even more attractive as "+ETO->query_subjective()+" wraps "+ETO->query_objective()+" slender fingers around the handle of the whip.%^RESET%^",ETO);
      tell_object(ETO,"%^RESET%^%^RED%^You can't help but to feel more sensual and calm as your fingers wrap around the beautiful whip.%^RESET%^");
          ETO->add_stat_bonus("charisma",1);
          ETO->add_attack_bonus(1);
          ETO->add_damage_bonus(1);
                return 1;
}
int unwield_func(){
          ETO->add_stat_bonus("charisma",-1);
          ETO->add_attack_bonus(-1);
          ETO->add_damage_bonus(-1);
                return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 215){
      switch(random(3)){
         case 0..1:
            tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" raises the whip in "+ETO->query_objective()+" hand above "+ETO->query_objective()+" head and swings it around in a graceful, hypnotic arch before snapping it quickly forward, causing each of its twelve strands to inflict a shower of grevious wounds upon "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^RED%^You bring the whip in your hand above your head and swing it around in a graceful, hypnotic arch before snapping it quickly forward, causing each of its twelve strands to inflict a shower of grevious wounds upon "+target->query_cap_name()+"!%^RESET%^",target);
            tell_object(target,"%^RESET%^%^RED%^"+ETO->query_cap_name()+" raises the whip in "+ETO->query_objective()+" hand above "+ETO->query_objective()+" head and swings it around in a graceful, hypnotic arch before snapping it quickly forward, causing each of its twelve strands to inflict a shower of grevious wounds upon you!%^RESET%^");
		  return roll_dice(1,8)+1;
         case 3:
            tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^As "+ETO->query_name()+" swings the whip towards "+target->query_cap_name()+", it begins to glow soothingly, leaving "+target->query_objective()+" standing there unmoving.",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^MAGENTA%^As you swing the whip towards "+target->query_cap_name()+", it begins to glow soothingly, leaving "+target->query_objective()+" standing there unmoving.%^RESET%^",target);
            tell_object(target, "%^RESET%^%^MAGENTA%^As "+ETO->query_name()+" swings the whip towards you, it begins to glow soothingly, leaving the image of "+ETO->query_name()+"'s seductive eyes burnt in your mind.");
            target->set_paralyzed(20,"%^BOLD%^%^MAGENTA%^You cant get the image of those eyes out of your mind.");
                 return roll_dice(1,4)+1;
      }
   }
}

  




  