#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("flower");
   set_id(({ "cerulean flower","flower","beautiful flower" }));
   set_short("%^BOLD%^%^BLUE%^bea%^BOLD%^%^CYAN%^u%^BOLD%^%^BLUE%^ti%^BOLD%^%^CYAN%^fu%^BOLD%^%^BLUE%^l %^BOLD%^%^CYAN%^c%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^r%^MAGENTA%^ul%^BLUE%^e%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^n %^BOLD%^%^BLUE%^flo%^BOLD%^%^CYAN%^w%^BOLD%^%^BLUE%^er%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a %^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^r%^BOLD%^"
"%^RED%^e%^RESET%^%^MAGENTA%^tty %^BOLD%^%^WHITE%^little flower, with large petals that "
"overlap each other as they spring forth from the deep %^RESET%^%^MAGENTA%^v%^BLUE%^io"
"%^MAGENTA%^le%^BLUE%^t %^BOLD%^%^WHITE%^centre of the blossom.  Each petal shifts in "
"color from %^RESET%^%^BLUE%^dusky cobalt %^BOLD%^%^WHITE%^toward the centre, to a more "
"brilliant shade of %^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^k%^BOLD%^%^CYAN%^y-bl%^BOLD%^"
"%^WHITE%^u%^BOLD%^%^CYAN%^e %^BOLD%^%^WHITE%^at the edges.  Somehow, the living flower "
"has been attached to a sturdy %^BOLD%^%^BLACK%^h%^RESET%^ai%^BOLD%^%^BLACK%^r%^RESET%^pi"
"%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^, allowing it to be worn in the hair.  A few %^RESET%^"
"%^GREEN%^glos%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^y %^BOLD%^%^WHITE%^leaves offset the "
"vivid color of the blossom, which emits an intoxicatingly %^BOLD%^%^MAGENTA%^s%^BOLD%^"
"%^RED%^w%^BOLD%^%^MAGENTA%^e%^BOLD%^%^RED%^e%^BOLD%^%^MAGENTA%^t %^BOLD%^%^WHITE%^scent "
"into the air around it.%^RESET%^\n");
   set_weight(1);
   set_value(3570);
   set_property("id difficulty",15);
   set_type("clothing");
   set_limbs(({"head"}));
   set_size(2);
   set_ac(0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_item_bonus("charisma",1);
   set_property("enchantment",3);
}

void init() {
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO)) set_size(TP->query_size());
}

int wear_fun(){
   tell_room(EETO,"%^RESET%^%^MAGENTA%^A sweet scent fills the air around you as "+ETOQCN+" places a lovely %^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^k%^BOLD%^%^CYAN%^y-bl%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^e %^RESET%^%^MAGENTA%^flower in "+ETO->QP+" hair.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^MAGENTA%^You place the pretty flower in your hair, breathing in its sweet scent.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETOQCN+" seems disappointed to remove the lovely flower from "+ETO->QP+" hair.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^MAGENTA%^It seems such a shame to remove the beautiful flower from your hair.%^RESET%^");
   return 1;
}
