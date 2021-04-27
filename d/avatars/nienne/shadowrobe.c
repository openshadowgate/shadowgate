#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("ragged robe");
   set_id(({"ragged robe","robe"}));
   set_short("%^RESET%^%^BLUE%^the ragged remains of a robe%^RESET%^");
   set_long("%^RESET%^Nothing more than %^CYAN%^air %^RESET%^and %^BLUE%^shadows %^RESET%^make up this robe, barely holding together.  They look like the tattered remains of what might have once been an expensive garment, showing traces of %^YELLOW%^golden embroidery %^RESET%^and patterning over finely-woven cloth.  Now, though, even through their misty substance "
"you can see %^BOLD%^%^BLACK%^raggedly torn edges %^RESET%^and %^ORANGE%^smudges %^RESET%^of insubstancial dirt.  You can't tell if they are truly real or not, but either way they seem not to hold value as they once might have done.\n");
   set_type("clothing");
   set_limbs(({"torso","neck","head","waist","left foot","right foot","left leg","right leg","left arm","right arm","left hand","right hand"}));
   set_size(2);
   set_property("enchantment",1);
   set_weight(4);
   set_value(0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_heart_beat(1);
}

void init() {
   ::init();
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !avatarp(TP)) {
     tell_object(TP,"The robe disintegrates into a fine mist, falling free of your hands.");
     TO->remove();
   }
}

int wear_fun() {
   if(!avatarp(ETO)) {
     tell_object(ETO,"The robe disintegrates into a fine mist, falling free of your hands.");
     TO->remove();
     return 0;
   }
   ETO->set_missChance(50);
   return 1;
}

int remove_fun() {
   ETO->set_missChance(0);
   return 1;
}

int struck_fun(int damage,object what,object who){
   tell_room(EETO,"%^RESET%^%^BLUE%^"+who->QCN+"'s blow passes right "
"through "+ETOQCN+"%^RESET%^%^BLUE%^!%^RESET%^",({ETO,who}));
   tell_object(ETO,"%^RESET%^%^BLUE%^"+who->QCN+"'s blow passes right through you!%^RESET%^");
   tell_object(who,"%^RESET%^%^BLUE%^Your blow passes straight through "
+ETOQCN+"%^RESET%^%^BLUE%^!%^RESET%^");
   return (-1)*damage;
}

void heart_beat() {
   if(!userp(ETO)) return;
   if(!avatarp(ETO)) return;

   if((int)ETO->query_hp() < 0) {
     tell_room(EETO,"%^RESET%^%^BLUE%^The shadowy figure lets out a low wail, "
"its arms raised high as if to reach out to the ceiling above, and it "
"disintegrates into nothingness.%^RESET%^");
     ETO->move("/d/dagger/avalounge");
     ETO->set_hp((int)ETO->query_max_hp());
     return;
   }
}
