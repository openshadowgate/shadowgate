#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create() {
    ::create();
    set_name("shining mithril fullplate");
    set_short("%^BOLD%^%^WHITE%^Plate of the %^RESET%^%^RED%^Crim%^BOLD%^s%^RESET%^%^RED%^on Wa%^BOLD%^r%^RESET%^%^RED%^bringer%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^shi%^RESET%^n%^BOLD%^%^WHITE%^ing mi%^RESET%^t%^BOLD%^%^WHITE%^hril fullp%^RESET%^l%^BOLD%^%^WHITE%^ate");
    set_id(({"plate","mithril fullplate","mithril plate","full plate","fullplate","armor","armour"}));
    set_long("%^RED%^This suit of plate armor has been crafted in the later Maximilian style, giving it a more "
"ornate appearance than many such standard pieces. Unusually %^CYAN%^light%^RED%^, yet sturdy plates overlap "
"to form a wall of defense over the wearer's body. The plates themselves are made from fine %^BOLD%^%^WHITE%^"
"mithril%^RESET%^%^RED%^, polished to a %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er%^RESET%^y-%^BOLD%^"
"%^WHITE%^wh%^RESET%^it%^BOLD%^%^WHITE%^e %^RESET%^%^RED%^sheen and possessing a %^BLUE%^strength %^RED%^not "
"found in other metals, making the entire suit a formidible defense against foes. Somehow an image has been "
"carved into the soild metal of the breastplate, depicting a %^YELLOW%^blazing sword %^RESET%^%^RED%^upon a "
"shield that has been tinted %^BOLD%^bright crimson %^RESET%^%^RED%^by some means of metalworking or magic. "
"The armor is certainly a work of art, rivalling even the most masterfully crafted pieces.%^RESET%^");
    set_lore("This suit of armor was crafted by the dwarven smiths of Barak Morndin, in the year 678SG. It was "
"a gift of thanks for the return of an artifact of the dwarven people, found by the warpriest of Tempus, "
"Cedric. The plate itself is rumored to have been crafted by the master smiths of the city, using only the "
"finest of their metals, and to have been blessed by their highpriest himself in the name of Tempus.");
        set_property("lore",14);
        set_weight(45);
        set_value(25000);
        set_property("enchantment",3);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
        set_struck((:TO,"strikeme":));
}

int wearme() {
   if((string)ETO->query_diety() != "tempus") {
     tell_object(ETO,"%^RED%^Some sort of magic or warding prevents you from "
"wearing the armor!%^RESET%^");
     tell_room(EETO,"%^RED%^"+ETO->QCN+" seems unable to wear the "
"%^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^ning fu%^BOLD%^l%^RESET%^%^WHITE%^"
"lpla%^BOLD%^t%^RESET%^%^WHITE%^e%^RED%^.%^RESET%^",ETO);
     return 0;
   }
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"%^RED%^The magic within the fullplate conflicts with "
"the items of %^BLUE%^darkness %^RED%^you're wearing, and you find you cannot "
"force it on!%^RESET%^");
      return 0;
   }
   tell_object(ETO,"%^RED%^The power and energy of battle rushes through you "
"as you pull on the suit of %^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^ning "
"fu%^BOLD%^l%^RESET%^%^WHITE%^lpla%^BOLD%^t%^RESET%^%^WHITE%^e%^RED%^."
"%^RESET%^");
   tell_room(EETO,"%^RED%^"+ETO->QCN+" seems invigorated as "+ETO->QS+" pulls "
"on the suit of %^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^ning fu%^BOLD%^l"
"%^RESET%^%^WHITE%^lpla%^BOLD%^t%^RESET%^%^WHITE%^e%^RED%^.%^RESET%^",ETO);
   ETO->set_property("good item",1);
   return 1;
}

int removeme() {
   tell_object(ETO,"%^RED%^You feel the heat of battle subside as you remove "
"the %^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^ning fu%^BOLD%^l%^RESET%^%^WHITE%^"
"lpla%^BOLD%^t%^RESET%^%^WHITE%^e%^RED%^.%^RESET%^");
   tell_room(EETO,"%^RED%^"+ETO->QCN+" seems to calm down as he removes the "
"%^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^ning fu%^BOLD%^l%^RESET%^%^WHITE%^lpla"
"%^BOLD%^t%^RESET%^%^WHITE%^e%^RED%^.%^RESET%^",ETO);
   ETO->set_property("good item",-1);
   return 1;
}

int strikeme(int damage, object what, object who) {
   if(!random(3)) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^Your vision swims, and you are "
"suddenly in a pitched battle with a thousand templars. They %^WHITE%^rush "
"%^BLACK%^past you against "+who->QCN+", knocking "+ETO->QO+" down!%^RESET%^");
     tell_object(who,"%^BOLD%^%^BLACK%^Just as you are about to "
"%^RESET%^%^RED%^strike %^BOLD%^%^BLACK%^"+ETO->QCN+", you watch in horror as "
"several ghostly figures seperate from "+ETO->QP+" armor and %^RED%^rush "
"%^BLACK%^towards you, knocking you from your feet!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^Just as "+who->QCN+" is about to "
"%^RESET%^%^RED%^strike %^BOLD%^%^BLACK%^"+ETO->QCN+", the air "
"sh%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^mm%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^"
"rs and ghostly warriors rush out from their armor to %^RESET%^%^RED%^strike "
"%^BOLD%^%^BLACK%^at "+who->QO+"!%^RESET%^",({who,ETO}));
     who->do_damage("head",roll_dice(2,10));
     who->set_paralyzed(12,"You're trying to get back to your feet!");
     return (-1)*damage;
   }
   return 1;
}
