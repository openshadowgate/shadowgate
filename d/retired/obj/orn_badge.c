#include <std.h>

inherit "/d/common/obj/jewelry/pin.c";
int trak;


void create(){
   ::create();
   set_name("badge");
   set_id(({ "badge", "ornbadge", "sheriff badge" }));
   set_short("%^BOLD%^Shiny badge%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^Sheriff badge%^RESET%^");
   set_long("%^GREEN%^This is a wooden and %^RESET%^silver%^GREEN%^ badge that "+
   "was given to show that the wearer protects a "+
   "certain group of elves.  The design is simple "+
   "yet elegant both at the same time.%^RESET%^");
   set_value(1000);
   set_property("lore_difficulty",35);
   set_lore("When Ashta'Rathai opened the door"+
   " after a very long period of isolation "+
   "Onrsul was the first non gold elf to ever"+
   " be given a position of authority in the city."+
   "  Because of his many deeds in defending the"+
   " wild and elven kind this honor was bestowed"+
   " upon him with this badge.  It is rumored this"+
   " badge grants the user the %^GREEN%^<death ward>%^RESET%^. ability");
}

int wearme(){
	tell_object(ETO,"You pin the badge on your chest.");
	tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+
    " pins the badge on their chest",ETO);
    ETO->add_temporary_feat("death ward");
    trak = 1;
	return 1;
}

int removeme(){
	tell_object(ETO,"You unpin the badge and fear a sudden death.");
	tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" removes"+
	" "+ETO->query_possessive()+" badge and looks a little worried.",ETO);
    if(trak){
        ETO->remove_temporary_feat("death ward");
        trak = 0;
    }
	return 1;
}
