#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("%^BLACK%^%^BOLD%^chain belt%^RESET%^");
   set_id(({"belt","chain","chain belt","torments links","links","torment's links","onyx belt","onyx links","chain belt of onyx","chain belt of onyx links"}));
   set_short("%^BLACK%^%^BOLD%^Tor%^RESET%^%^WHITE%^m%^BLACK%^%^BOLD%^ent's Lin%^RESET%^%^WHITE%^k%^BLACK%^%^BOLD%^s%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^a cha%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^n belt of on%^RESET%^%^WHITE%^y%^BLACK%^%^BOLD%^x links%^RESET%^");
   set_long("%^MAGENTA%^Smooth, flawless links of %^BLACK%^%^BOLD%^on%^RESET%^%^WHITE%^y%^BLACK%^%^BOLD%^x "
"stone%^RESET%^%^MAGENTA%^ have been joined together to form this loose chain belt.  Despite the usual manner "
"of such gems to be easily chipped, this substance seems uncommonly resiliant, strengthened by some unknown "
"means.  A carved tip is attached to one end, of a %^BLACK%^%^BOLD%^jet-black feline%^RESET%^%^MAGENTA%^ "
"crouching upon its belly, with both paws outstretched and %^RED%^%^BOLD%^fiendishly sharp tips%^RESET%^ "
"%^MAGENTA%^to the claws extended from them.  It has been designed for this carved tip to lock within any of "
"the chain links, allowing the wearer to secure the belt at a variety of comfortable sizes, to let the belt "
"rest loosely upon the wearer's hips, and the excess chain to simply trail from the side.  It has obviously "
"been designed for someone with a taste for elegance, and would make quite a fashionable "
"accessory.%^RESET%^\n");
   set_weight(3);
   set_value(2025);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"waist"}));
   set_lore("%^WHITE%^%^BOLD%^This belt was said not to be made by human hands, but rather was a divine gift "
"to the priestess Anshara, by the Maiden of Pain herself.  It was a blessing upon the half-drow priestess, "
"during the ceremony of her ascendance to the position of Truescar within the faith, reportedly one that "
"could be of equal use as a %^YELLOW%^weapon%^WHITE%^ as an accessory.  That same half-drow was also said to "
"be the path to Loviatar's eventual destruction, as the guardian of the Orb of Torment which, some tell, was "
"stolen by Durias and instrumental to his ascension over the Maiden to demi-godhood.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_property("enchantment",1);
   while((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
    add_action("wield_fun","wield");
}

int wear_fun() {
   if(ETO->query_level() < 21) {
     tell_object(ETO,"You are not experienced enough to use this equipment.");
     return 0;
   }
   tell_object(ETO,"%^MAGENTA%^You drape the chain belt around your waist, securing it comfortably with the "
"%^BLACK%^%^BOLD%^feline-shaped clasp%^RESET%^%^MAGENTA%^. As your hands run along its length, you suspect "
"it would work surprisingly well as a weapon...%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" drapes the chain belt around "+ETO->QP+" waist, securing it "
"comfortably with the %^BLACK%^%^BOLD%^feline-shaped clasp%^RESET%^%^MAGENTA%^.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You unclasp the belt, which falls free with a light clink.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" unclasps the chain belt from around "+ETO->QP+" "
"waist.%^RESET%^",ETO);
   return 1;
}

int wield_fun(string str) {
   object ob,*names;
   int i,ench;
   if (!str) {
     notify_fail("Wield what?");
     return 0;
   }
   if (member_array(str,TO->query_id()) == -1) {
     notify_fail("You can't wield that.\n");
     return 0;
   }
   if (TP != ETO) {
     notify_fail("You should pick that up first.\n");
     return 0;
   }
   if(!("/daemon/feat_d"->has_feat(TP,"exotic weapon proficiency"))) {
     notify_fail("You realise you don't have the aptitude to wield such a complex weapon.\n");
     return 0;
   }
   ob = new("/d/avatars/nienne/belt2");
   ob->move(ETO);
   ench = (int)ETO->query_level();
   ench = ench/7;
   while((int)ob->query_property("enchantment") != ench) {
     ob->remove_property("enchantment");
     ob->set_property("enchantment",ench);
   }
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       ob->add_identified(names[i]);
     }
   }
   ETO->force_me("wield torments lash");
   TO->remove();
   return 1;
}
