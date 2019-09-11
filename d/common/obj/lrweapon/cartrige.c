#include <std.h>

inherit "/std/ammo";

void create(){
   ::create();
   set_id(({ "cartriges","cartrige" }));
   set_name("cartrige");
   set_short("pouch of cartriges");
   set_long("These are small paper cartriges, with alchemical charge at one end and bullet at the other.");
   set_ammo_type("cartrige");
   set_weight(1);

   set_shots(250);
   set_value(1);
   set_wc(1,4);
   set_large_wc(1,4);
}
