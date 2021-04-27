#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create() {
   ::create();
   set_name("onyx bracers");
   set_short("Seer's Guards");
   set_obvious_short("copper-chased bracers of onyx");
   set_id(({"bracer","bracers","onyx bracers","bracers of onyx","copper-chased bracers"}));
   set_long("These matching pair of bracers are precisely cut from solid onyx, each a perfect circular cuff.  Jagged veins of ochre and amber coloration split its otherwise dark surface, polished to glitter under light.  Upon the upper surface of each, etchings outline the edges of the bracers, as well as cutting the outline of a single open eye.  Each indentation has been filled with molten bronze to accentuate their shape.\n");
   set_value(1025);
   set_lore("These bracers mark the wearer as a faithful of Auppenser, the Lord "
"of Reason.  The bronze and onyx are precious substances to his clergy, and the "
"eye is used as the symbol of the enlightenment they seek in his name.  These "
"are usually only worn by the priesthood, or other equally favored members of "
"the faith.\n");
   set_property("lore difficulty",10);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
}

int check() {
   ::check();
   if((string)TP->query_diety() != "auppenser") {
     tell_object(ETO,"The bracers don't seem to fit you.");
     tell_room(EETO,"The bracers don't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
   return 1;
}

int remove_fun() {
   return 1;
}

int struck_fun(int damage, object what, object target) {
   if (!random(2)) {
     tell_object(ETO,"The shadowy bracers seem to solidify, just enough to
harmlessly deflect "
+target->QCN+"'s attack!");
     tell_object(target,""+ETO->QCN+"'s shadowy bracers seem to solidify,
just enough to harmlessly "
"deflect your attack!");
     tell_room(EETO,""+ETO->QCN+"'s shadowy bracers seem to solidify, just
enough to harmlessly "
"deflect "+ETO->QP+"'s attack!",({ETO,target}));
     return (-1)*damage;
   }
   return 1;
}
