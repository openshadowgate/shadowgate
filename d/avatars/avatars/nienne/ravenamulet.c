#include <std.h>
inherit "/std/armour";

int mytracker;

void create() {
   ::create();
      set_name("amber amulet");
      set_id(({"amulet","amber amulet","mark","ravenlord's mark","Ravenlord's Mark"}));
      set_short("%^RESET%^%^ORANGE%^Ra%^BOLD%^%^BLACK%^v%^RESET%^%^ORANGE%^enl%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^rd's M%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rk%^RESET%^");
      set_obvious_short("%^RESET%^an %^ORANGE%^a%^YELLOW%^m%^RESET%^%^ORANGE%^ber %^RESET%^amulet encasing a %^BOLD%^%^BLACK%^ra%^RESET%^%^ORANGE%^ve%^BOLD%^%^BLACK%^n's %^RESET%^feather%^RESET%^");
      set_long("%^RESET%^This is a simple, rustic looking piece of jewelry that at first "
"glance is fairly unremarkable, save for its unusual size.  It consists primarily of an "
"egg-sized piece of %^ORANGE%^a%^YELLOW%^m%^RESET%^%^ORANGE%^ber%^RESET%^ that offers a "
"deep golden reflection of the %^YELLOW%^l%^BOLD%^%^WHITE%^ig%^YELLOW%^ht %^RESET%^it "
"catches.  Entrapped within its depths is a single slender %^BOLD%^%^BLACK%^eb%^RESET%^"
"%^BLUE%^o%^BOLD%^%^BLACK%^n fe%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ther%^RESET%^, perhaps "
"that of a raven or similar bird.  A single hole at the top of the fossilized resin allows "
"a loop of %^ORANGE%^tanned leather %^RESET%^to slip through, which has been tied & then "
"serves as a strap to secure the pendant about the wearer's neck.  While very simplistic, "
"there is a certain %^GREEN%^ch%^CYAN%^ar%^GREEN%^m %^RESET%^to the ornament, perhaps due "
"to its unique nature.\n%^RESET%^");
      set_lore("This amulet is said to have been a gift of Rillifane "
"to his faithful follower, the elf Erynion. Together with a gathering "
"of elvenkind, a ritual was enacted to beseech the Seldarine to restore "
"the drow allies of Rilynath, once elves, to their rightful forms "
"following a curse put upon them by the sun elves of Selu'havessthyr. "
"With the combined strength of the elves, Erynion aided in the ritual's "
"success, and was blessed by the touch of Rillifane for his efforts.");
    set_property("lore difficulty",25);
    set_weight(5);
    set_value(23000);
    set_ac(0);
    set_type("ring");
    set_limbs(({"neck"}));
    set_size(-1);
//    set_property("enchantment",5);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"unwearme":));
}

int wearme(string str){
    if((string)ETO->query_name() != "erynion" && !avatarp(ETO)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You feel a little uneasy handling the amulet, and decide against wearing it.%^RESET%^");
      return 0;
    }
    tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" ties the amulet into place, and "+ETO->QP+" eyes take on a distant look.%^RESET%^",ETO);
    tell_object(ETO,"%^GREEN%^You tie the amulet into place, and feel the call of the winds tugging at your senses.%^RESET%^");
    if(member_array("wild shape bird",(string*)ETO->query_temporary_feats()) == -1) {
      ETO->add_temporary_feat("wild shape bird");
      mytracker = 1;
    }
    return 1;
}

int unwearme(string str){
    tell_room(EETO,"%^GREEN%^"+ETOQCN+" reluctantly removes the amulet.%^RESET%^",ETO);
    tell_object(ETO,"%^GREEN%^The call of the winds fades.%^RESET%^");
    if(mytracker) ETO->remove_temporary_feat("wild shape bird");
    return 1;
}

int drop(){ return 1;}
