#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("blossom");
   set_id(({ "blossom","crimson blossom","flower" }));
   set_short("%^RESET%^%^RED%^cr%^BOLD%^i%^RESET%^%^RED%^mson blo%^MAGENTA%^s%^RED%^som%^RESET%^");
   set_long("%^ORANGE%^This is a pretty little flower, with %^RED%^large petals %^ORANGE%^that overlap each "
"other as they spring forth from the %^MAGENTA%^deep violet %^ORANGE%^centre of the blossom.  Each petal "
"shifts in color from %^RED%^deep red %^ORANGE%^toward the centre, to a more brilliant shade of%^BOLD%^%^RED%^ "
"crimson %^RESET%^%^ORANGE%^at the edges.  A few %^GREEN%^glossy leaves %^ORANGE%^offset the radiant color of "
"the blossom, which emits a beautifully sweet scent into the air around it.%^RESET%^\n");
   set_weight(0);
   set_value(0);
   set_lore("%^WHITE%^%^BOLD%^Such distinctly colored blossoms are known to be from a plant found only rarely "
"within the Moonstone Vale.  The dryads there are said to be drawn to it, fond of its beauty and sweet smell.  "
"Rumour tells that they occasionally gift these blossoms to others, if they believe them to be equal to the "
"beauty of the flower itself.%^RESET%^");
   set_property("lore difficulty",14);
   set_type("ring");
   set_limbs(({"head"}));
   set_size(2);
   set_ac(0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO)) set_size(TP->query_size());
}

int wear_fun(){
   tell_room(EETO,"%^RED%^A sweet scent fills the air around you as "+ETOQCN+" places a lovely %^BOLD%^crimson "
"blossom %^RESET%^%^RED%^ in "+ETO->QP+" hair.%^RESET%^",ETO);
   tell_object(ETO,"%^RED%^You place the pretty flower in your hair, breathing in its sweet scent.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^RED%^"+ETOQCN+" seems disappointed to remove the lovely flower from "+ETO->QP+" hair.%^RESET%^",ETO);
   tell_object(ETO,"%^RED%^It seems such a shame to remove the beautiful flower from your hair.%^RESET%^");
   return 1;
}
