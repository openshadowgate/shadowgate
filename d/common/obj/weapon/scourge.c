// updating damage and size to be closer to 3rd ed per discussions with Cythera & Circe *Styx* 8/2/05
//removed mention of Loviatar ~Circe~ 4/27/11

inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "scourge", "whip", "scourge whip" }));
   set_name("scourge");
   set_short("A scourge whip");
   set_long(
	"Nine long leather lashes have been affixed to a"+
        " wooden base.  Braided into the leather lashes of"+
        " this scourage are sharp iron barbs, made to slice"+
        " and pierce the flesh.  Each lash is held in place"+
        " with a round metal stud, which has been hammered "+
        "deep into the dark wooden base." );
   set_weight(2);
   set_size(2);   // was size 1
   set_prof_type("whip");
   set_value(10);
   set_wc(2,3);  // was 1,4
   set_large_wc(2,3);  // was 1,2
   set_type("lash");
   set_weapon_speed(5);
   set_weapon_prof("exotic");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(2);
   set_property("repairtype",({"leatherwork"}));
   set_damage_type("piercing");
}
