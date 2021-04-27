#include <std.h>
#include <move.h>
inherit "/d/common/obj/misc/quiver";

void create(){
   ::create();
   set_name("quiver");
   set_id(({"quiver","trailblazer's quiver","trailblazer quiver","silk-draped quiver","silk quiver"}));
   set_short("%^BOLD%^%^BLACK%^Tra%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^lblaz%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r's Q%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^iver%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a s%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^lk-d%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^aped quiver%^RESET%^");
   set_long("%^CYAN%^This quiver consists primarily of soft, tanned leather dyed a "
"%^BOLD%^%^BLACK%^deep jet-black%^RESET%^%^CYAN%^, forming an open-ended sleeve to "
"contain a large number of arrows.  The outer surface, however, has been half-wrapped in "
"layers of pale, %^MAGENTA%^mu%^BOLD%^%^CYAN%^l%^RESET%^%^MAGENTA%^ti-"
"co%^BLUE%^l%^MAGENTA%^oured s%^CYAN%^i%^MAGENTA%^lks%^CYAN%^, the ends of which have "
"been left loose to drape over the sleeve and sway in the %^BOLD%^br%^WHITE%^e%^CYAN%^eze"
"%^RESET%^%^CYAN%^.  A strap of the same %^BOLD%^%^BLACK%^dark leather%^RESET%^%^CYAN%^ "
"is attached to hold the quiver within easy reaching range on the wearer's back, also "
"wrapped in %^MAGENTA%^s%^BOLD%^%^CYAN%^i%^RESET%^%^MAGENTA%^lks%^CYAN%^, making it very "
"soft and comfortable to wear. It is quite a unique and beautiful creation.%^RESET%^\n");
   set_lore("%^CYAN%^These quivers are rarely found, and are specially crafted for the "
"followers of Shaundakul's faith.  Some say they are drawn from the very essence of the "
"winds, gifted only to those travelling from place to place, carrying the Rider's message "
"as they go.%^RESET%^");
   set_property("lore difficulty",11);
   set_type("sheath");
   set_weight(5);
   set_value(850);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
   add_action("whirl_fun","whirl");
}

int wear_fun() {
   if((string)TP->query_diety() != "shaundakul" && !avatarp(TP)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The quiver doesn't fit you!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" tries to force the quiver on, but "
"fails.%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^MAGENTA%^You are filled with confidence as you slide the quiver "
"on.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" slides the quiver on with an air of "
"assurance.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You already miss the brush of the silken quiver as you "
"remove it.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" looks disappointed to remove the "
"quiver.%^RESET%^",ETO);
   return 1;
}

void whirl_fun(string str) {
   if(!objectp(TP)) return 0;
   if(!TP->is_class("ranger")) return 0;
   if(!TO->query_worn()) return 0;
   if(!sizeof(TP->query_attackers())) return 0;
   if(!sizeof(TP->query_wielded())) return 0;
   if(random(4)) return 0;

   tell_room(ETP,"%^CYAN%^The %^BOLD%^w%^WHITE%^i%^CYAN%^nds %^RESET%^%^CYAN%^pick up "
"around "+TP->QCN+" as "+TP->QS+" strikes, leading "+TP->QP+" weapons in%^MAGENTA%^ "
"graceful %^CYAN%^strokes!%^RESET%^",TP);
   tell_object(TP,"%^CYAN%^The %^BOLD%^w%^WHITE%^i%^CYAN%^nds %^RESET%^%^CYAN%^pick up "
"around you as you spin, leading your weapons in %^MAGENTA%^graceful "
"%^CYAN%^strokes!%^RESET%^");
   return 0;
}
