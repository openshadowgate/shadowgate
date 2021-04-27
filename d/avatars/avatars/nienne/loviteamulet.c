#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("amulet");
   set_id(({"amulet","jet amulet","jet-black amulet","black amulet","amulet of the wand","amulet of the white wand"}));
   set_short("%^RED%^%^BOLD%^Amulet of the %^WHITE%^White Wand%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^a jet-black amulet%^RESET%^");
   set_long("%^MAGENTA%^This exquisite piece of jewelry consists of a large amulet, held by a chain of "
"%^BLACK%^%^BOLD%^blackened links%^RESET%^%^MAGENTA%^ that shine with a %^RED%^dull-red %^MAGENTA%^tint in "
"darker lighting.  They support the amulet itself, which is crafted from %^BLACK%^%^BOLD%^pure jet%^RESET%^"
"%^MAGENTA%^, flecked with strands of %^BOLD%^%^RED%^blood-red ruby%^RESET%^%^MAGENTA%^.  Etched within its "
"centre is the image of a long %^WHITE%^%^BOLD%^ice-white wand%^RESET%^%^MAGENTA%^, shaped from%^WHITE%^ "
"ivory%^MAGENTA%^.  The amulet is always %^CYAN%^%^BOLD%^ice-cold%^RESET%^%^MAGENTA%^ to the touch, no "
"matter how much it is warmed.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This amulet is a sacred artifact of the church of Loviatar.  The image of the "
"white wand is a symbol of her power to her faithful, and is said to be gifted only to those who carry out "
"her will by inflicting widespread suffering.  The amulet itself is shaped from an unholy merging of divine "
"power and necromantic arcana, and rumours speak of its ability to trap pieces of a living creature's own "
"soul and life-force.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_weight(3);
   set_ac(1);
   set_size(2);
   set_property("enchantment",1);
   set_value(5600);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if((string)ETO->query_diety() != "loviatar") {
     tell_object(ETO,"%^BLACK%^%^BOLD%^A burning pain runs through you as you try to wear the amulet!"
"%^RESET%^");
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" screams in pain as "+ETO->QS+" tries to wear the amulet."
"%^RESET%^",ETO);
     ETO->do_damage("head",random(5)+5);
     return 0;
   }
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" smiles darkly as "+ETO->QS+" wears the amulet."
"%^RESET%^",ETO);
   tell_object(ETO,"%^BLACK%^%^BOLD%^You are filled with self-confidence as you wear the amulet.%^RESET%^");
   ETO->set_property("magic resistance",10);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+"'s smile fades as "+ETO->QS+" removes the amulet."
"%^RESET%^",ETO);
   tell_object(ETO,"%^BLACK%^%^BOLD%^An icy chill runs down your spine as you remove the amulet.%^RESET%^");
   ETO->set_property("magic resistance",-10);
   return 1;
}

int struck_fun(int damage, object what, object target) {
   int dam2;
   dam2 = random(5)+5;
   if (!random(2)) {
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+target->QCN+" writhes in %^RED%^pain %^BLACK%^as "+ETOQCN+"'s amulet "
"glows %^RESET%^%^RED%^blood-red%^BLACK%^%^BOLD%^.%^RESET%^",({ETO,target}));
     target->do_damage("head",dam2);
     ETO->do_damage("head",(-1)*dam2);
     switch(random(3)) {
       case 0:
       tell_object(ETO,"%^BLACK%^%^BOLD%^Your amulet pulses %^RESET%^%^RED%^blood-red %^BLACK%^%^BOLD%^as "
+target->QCN+" screams in pain, and you can feel the sweet agony of the %^RED%^fire burning %^BLACK%^through "
+target->QP+" veins!%^RESET%^");
       tell_object(target,"%^BLACK%^%^BOLD%^"+ETO->QCN+"'s amulet pulses %^RESET%^%^RED%^blood-red%^BLACK%^"
"%^BOLD%^, and a wave of %^RED%^fire burns %^BLACK%^through your veins!%^RESET%^");
       break;

       case 1:
       tell_object(ETO,"%^BLACK%^%^BOLD%^Your amulet pulses %^RESET%^%^RED%^blood-red %^BLACK%^%^BOLD%^as "
+target->QCN+" screams in pain, and you can feel the sweet agony of the %^CYAN%^ice chilling %^BLACK%^"
+target->QO+" to the bone!%^RESET%^");
       tell_object(target,"%^BLACK%^%^BOLD%^"+ETO->QCN+"'s amulet pulses %^RESET%^%^RED%^blood-red%^BLACK%^"
"%^BOLD%^, and the bite of %^RED%^ice chills %^BLACK%^you to the bone!%^RESET%^");
       break;

       case 2:
       tell_object(ETO,"%^BLACK%^%^BOLD%^Your amulet pulses %^RESET%^%^RED%^blood-red %^BLACK%^%^BOLD%^as "
+target->QCN+" screams in pain, and you can feel the sweet agony of the %^RESET%^%^MAGENTA%^whip's lashes "
"%^BLACK%^%^BOLD%^across "+target->QP+" skin!%^RESET%^");
       tell_object(target,"%^BLACK%^%^BOLD%^"+ETO->QCN+"'s amulet pulses %^RESET%^%^RED%^blood-red%^BLACK%^"
"%^BOLD%^, and waves of pain like the %^RESET%^%^MAGENTA%^lashes of a whip %^BLACK%^%^BOLD%^race across your "
"skin!%^RESET%^");
       break;
     }
   }
   return 1;
}
