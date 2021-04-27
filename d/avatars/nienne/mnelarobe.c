#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("gown");
   set_id(({"gown","silver gown","white gown","silvery-white gown","silvery white gown","fluid gown","compx"}));
   set_short("%^BOLD%^%^WHITE%^a fluid si%^RESET%^l%^BOLD%^%^WHITE%^ve%^RESET%^r%^BOLD%^%^WHITE%^y-white gown%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This gown is light and flowing, remeniscent of "
"%^RESET%^liquid metal %^BOLD%^%^WHITE%^in its fluidity.  Crafted from some "
"unknown cloth with a lustrous surface, it shines like a sheet of white-silver "
"across the skin of the wearer.  The cloth is only thin, serving as cover to "
"the body without truly hiding anything of the wearer's shape as it hugs to the "
"figure.  Most definitely designed for a %^RESET%^%^MAGENTA%^female %^BOLD%^"
"%^WHITE%^form, it has lace-thin straps support it over both shoulders, which "
"lead down to layered folds over the breasts.  Beneath this, the main section "
"of the garment flows downwards in a fitted outline, clinging to the hips and "
"legs before flaring out at ankle-length like %^BLUE%^rippl%^CYAN%^i%^BLUE%^ng "
"waves %^WHITE%^that nearly brush the ground.  No other decorations have been "
"added, leaving the dress simple and yet breathtaking in its "
"elegance.%^RESET%^\n");
   set_ac(0);
   set_size(2);
   set_weight(5);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_value(6350);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun(){
   if(!avatarp(ETO)) {
     tell_object(ETO,"The gown doesn't fit you.");
     return 0;
   }
   ETO->set_property("damage resistance",10);
   ETO->set_property("magic resistance",50);
   ETO->add_saving_bonus("all",3);
   return 1;
}

int remove_fun(){
   ETO->set_property("damage resistance",-10);
   ETO->set_property("magic resistance",-50);
   ETO->add_saving_bonus("all",(-3));
   return 1;
}

int struck_fun(int damage, object what, object target) {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You step gracefully aside and "
+target->QCN+"'s blow whistles ineffectively through the air!%^RESET%^");
   tell_object(target,"%^BOLD%^%^WHITE%^"+ETO->QCN+" steps gracefully aside and "
"your blow whistles ineffectively through the air!%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" steps gracefully aside and "
+target->QCN+"'s blow whistles ineffectively through the "
"air!%^RESET%^",({ETO,target}));
   return (-1)*damage;
}
