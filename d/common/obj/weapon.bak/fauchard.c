inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "fauchard" }));
   set_name("fauchard");
   set_short("A fauchard");
   set_long(
   "This eight foot wooden shaft holds a massive, curved blade at its end."
   "  The blade is reminiscent of a that of a scythe with its curve and backward edge, but it has been mounted straight rather than from the side of the pole."
   );
   set_weight(7);
   set_size(3);
   set("value", 7);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("slash");
   set_prof_type("polearm");
   set_weapon_prof("martial");
   set_weapon_speed(8);
   
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
}
