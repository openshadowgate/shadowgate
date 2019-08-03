inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "pike", "awlpike" }));
   set_name("awlpike");
   set_short("A awlpike");
   set_long(
    "A spear 12-20 feet long, with a spiked point"
	" on the end. "
   );
   set_weight(10);
   set_size(3);
   set("value", 5);
   set_wc(3,4);
   set_large_wc(3,4);
   set_type("pierce");
   set_prof_type("polearm");
   set_weapon_prof("martial");
   set_weapon_speed(10);
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
}
