#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit ARMOUR;

int OWNED, charges, active;
string owner;
void set_my_lore();
void turnoff(object myuser);

void create(){
   ::create();
   set_name("tinted lenses");
   set_id(({"glasses","lenses","tinted lenses","crystal lenses","lenses of true seeing"}));
   set_short("%^RESET%^%^CYAN%^Lenses of T%^BOLD%^r%^RESET%^%^CYAN%^ue See%^BOLD%^i%^RESET%^%^CYAN%^ng%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^tin%^BOLD%^t%^RESET%^%^CYAN%^ed crystal lenses%^RESET%^");
   set_long("%^RESET%^A pair of %^CYAN%^cry%^BOLD%^s%^RESET%^%^CYAN%^tal%^BOLD%^"
"%^WHITE%^l%^RESET%^%^CYAN%^ine %^RESET%^lenses have been set into a "
"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^"
"%^WHITE%^r %^RESET%^frame, forming this striking pair of glasses. The "
"frame is light but durable, making you wonder if the otherwise fragile "
"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^"
"%^WHITE%^r %^RESET%^has been magically enhanced. Within their grasp are "
"the two lenses, each formed of semi-transparent crystal the color of a "
"%^BOLD%^%^CYAN%^clear s%^WHITE%^p%^CYAN%^ring sky%^RESET%^. They glitter "
"in light, each perfectly shaped to allow the wearer flawless vision "
"through their glassy surface. Oddly though, from the opposite side the "
"glasses carry a %^CYAN%^ti%^GREEN%^nt%^CYAN%^ed %^RESET%^sheen that "
"makes viewing the wearer's features much more difficult.\n");
   set_type("clothing");
   set_limbs(({"head"}));
   set_ac(0);
   set_size(2);
   set_weight(2);
   set_value(1600);
   set_property("lore difficulty",20);
   set_property("enchantment",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   charges = 25+ random(6);
   active = 0;
   set_my_lore();
}

void init(){
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO)) set_size(TP->query_size());
   add_action("see_fun","activate");
   add_action("unsee_fun","deactivate");
}

int wear_fun(){
   if((int)TP->query_highest_level() < 25 && !avatarp(ETO)) {
     tell_object(ETO,"The glasses seem not to fit you.");
     return 0;
   }
   if((OWNED && (string)ETO->query_name() == owner) || !OWNED || avatarp(ETO)) {
     tell_room(EETO,"%^GREEN%^"+ETO->QCN+" slides on the %^BOLD%^"
"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
"%^RESET%^%^GREEN%^frames and adjusts them on "+ETO->QP+" nose.%^RESET%^",ETO);
     tell_object(ETO,"%^GREEN%^You slide on the %^BOLD%^%^WHITE%^s"
"%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^"
"%^GREEN%^frames and adjust them to sit comfortably.%^RESET%^");
     if(interactive(ETO) && !OWNED && !avatarp(ETO)) {
       owner = ETO->query_name();
       OWNED = 1;
     }
     if(member_array(ETO->query_race(),PLAYER_D->night_races()) != -1) ETO->add_sight_bonus(-3);
     else ETO->add_sight_bonus(3);
     return 1;
   }
   tell_object(ETO,"The glasses seem not to fit you.");
   return 0;
}

int remove_fun(){
   if(active) turnoff(ETO);
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" removes the %^CYAN%^crys%^BOLD%^t"
"%^RESET%^%^CYAN%^al %^GREEN%^lenses and folds them closed.%^RESET%^",ETO);
   tell_object(ETO,"%^GREEN%^You remove the %^CYAN%^crys%^BOLD%^t"
"%^RESET%^%^CYAN%^al %^GREEN%^lenses and fold them closed.%^RESET%^");
   if(member_array(ETO->query_race(),PLAYER_D->night_races()) != -1) ETO->add_sight_bonus(3);
   else ETO->add_sight_bonus(-3);
   return 1;
}

void see_fun(string str) {
    if(!str) {
      notify_fail("What do you want to activate?\n");
      return 0;
    }
    if(str != "glasses" && str != "lenses") {
      notify_fail("You can't activate that.\n");
      return 0;
    }
    if(!userp(ETO)) {
      notify_fail("You must be wearing the lenses to activate them.\n");
      return 0;
    }
    if(!(int)TO->query_worn()) {
      notify_fail("You must be wearing the lenses to activate them.\n");
      return 0;
    }
    if(ETO->detecting_invis() && !avatarp(ETO)) {
      notify_fail("You are already detecting invisible creatures.\n");
      return 0;
    }
    if(active) {
      notify_fail("The lenses are already active.\n");
      return 0;
    }
    if(!charges){
      notify_fail("The lenses don't react. They seem to be out of charges.\n");
      return 0;
    }
    tell_object(ETO,"%^GREEN%^You tap the edge of the glasses, and a "
"%^CYAN%^soft g%^BOLD%^l%^RESET%^%^CYAN%^ow %^GREEN%^appears across its "
"crystalline lenses.%^RESET%^");
    tell_room(EETO,"%^GREEN%^"+ETO->QCN+" taps the edge of "+ETO->QP+
" glasses, and a %^CYAN%^soft g%^BOLD%^l%^RESET%^%^CYAN%^ow %^GREEN%^"
"appears across its crystalline lenses.%^RESET%^",ETO);
    charges--;
    active = 1;
    set_my_lore();
    set_short("%^RESET%^%^CYAN%^Lenses of T%^BOLD%^r%^RESET%^%^CYAN%^ue See%^BOLD%^i%^RESET%^%^CYAN%^ng %^YELLOW%^(glowing)%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^tin%^BOLD%^t%^RESET%^%^CYAN%^ed crystal lenses %^YELLOW%^(glowing)%^RESET%^");
    ETO->set_detecting_invis(1);
    call_out("turnoff", 35*ROUND_LENGTH,ETO);
    return 1;
}

void unsee_fun(string str) {
    if(!str) {
      notify_fail("What do you want to deactivate?\n");
      return 0;
    }
    if(str != "glasses" && str != "lenses") {
      notify_fail("You can't deactivate that.\n");
      return 0;
    }
    if(!userp(ETO)) {
      notify_fail("You must be holding the lenses to deactivate them.\n");
      return 0;
    }
    if(!active){
      notify_fail("The lenses aren't active.\n");
      return 0;
    }
    turnoff(ETO);
    return 1;
}

void turnoff(object myuser) {
    if(!objectp(TO)) return;
    if(!objectp(myuser)) return;
    if(!active) return;
    tell_object(myuser,"%^GREEN%^The %^CYAN%^glow %^GREEN%^around the "
"lenses fades again.%^RESET%^");
    tell_room(environment(myuser),"%^GREEN%^The %^CYAN%^glow %^GREEN%^"
"around "+myuser->QCN+"'s lenses fades again.%^RESET%^",myuser);
    set_short("%^RESET%^%^CYAN%^Lenses of T%^BOLD%^r%^RESET%^%^CYAN%^ue See%^BOLD%^i%^RESET%^%^CYAN%^ng%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^tin%^BOLD%^t%^RESET%^%^CYAN%^ed crystal lenses%^RESET%^");
    myuser->set_detecting_invis(0);
    active = 0;
}

void set_my_lore() {
    set_lore("These lenses, perfected over the ages, were originally a "+
"gnomish creation, prized as much for their aid in vision as for their "+
"stylish appearance. Many decades of experimentation and shattered "+
"crystals of all kinds eventually led to their creation most commonly "+
"from pale aquamarines, often leftovers from their gemcutters who held "+
"the lighter gemstones to be less valuable. As it was, these stones seemed "+
"best to hold the magic required, and thus while many different gemstones "+
"are used to create such lenses, the most effective ones made are still of "+
"the same pale azure gemstone.\n\n"+
"You remember from your research that users are able to %^YELLOW%^"+
"<activate lenses>%^RESET%^ to magically enhance their vision, beyond "+
"even the latent magics in the glasses themselves, and in the same way "
"you can %^YELLOW%^<deactivate lenses>%^RESET%^. You can tell that there "
"are approximately %^YELLOW%^"+charges+"%^RESET%^ charges remaining in the "
"lenses of this ability.");
}