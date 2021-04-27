#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("ornate bracers");
   set_id(({"bracers","ornate bracers","adamantium bracers","tazinyons bindings","bindings"}));
   set_short("%^BOLD%^%^BLACK%^Ta%^CYAN%^z%^BLACK%^iny%^GREEN%^o%^BLACK%^n's "
"Bind%^RED%^i%^BLACK%^ngs%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^or%^RESET%^%^ORANGE%^na%^BOLD%^"
"%^BLACK%^te ad%^RESET%^am%^BOLD%^an%^RESET%^ti%^BOLD%^%^BLACK%^um "
"br%^RESET%^%^ORANGE%^ace%^BOLD%^%^BLACK%^rs%^RESET%^");
   set_long("Brightly polished %^BOLD%^%^WHITE%^adamantium %^RESET%^forms "
"this pair of bracers, both carved in %^BOLD%^%^BLACK%^or%^RESET%^%^ORANGE%^"
"na%^BOLD%^%^BLACK%^te %^RESET%^whirling patterns that would run the length "
"of the wearer's forearms. They seem to hold no deliberate pattern to their "
"design, with broad, %^BOLD%^%^RED%^c%^CYAN%^h%^RESET%^%^GREEN%^a%^MAGENTA%^o"
"%^YELLOW%^t%^BOLD%^%^BLUE%^i%^CYAN%^c %^RESET%^swirls that double back "
"around like %^BOLD%^%^WHITE%^silver ripples%^RESET%^, and in no way match each other. They seem impossibly %^CYAN%^thin "
"%^RESET%^and lightweight, as though they could be snapped in half, yet no "
"amount of force seems to bend them even slightly.%^RESET%^");
   set_ac(1);
   set_size(2);
   set_property("enchantment",4);
   set_value(6350);
   set_lore("These beautiful bracers belonged to the drow general Tazinyon, "
"highly respected and feared for his battle prowess and his cold, merciless "
"personality. Custom made for him and him alone, they were imbued with many "
"protective magics to serve him in the forays he led. It was said that he met "
"his end during the invasion of Daggerdale in the year 678SG, to a group of "
"defenders who opposed his army and prevailed.");
   set_property("lore difficulty",27);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_item_bonus("reflex",2);
   set_item_bonus("fortitude",2);
   set_item_bonus("will",2);
}

int check(){
   ::check();
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" slides the ornate bracers over "
+ETO->QP+" forearms.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^You can feel the protection from the bracers "
"as you slide them over your forearms.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" slides the ornate bracers free of "
+ETO->QP+" forearms.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^You feel far less protected after removing the "
"bracers.%^RESET%^");
   return 1;
}
