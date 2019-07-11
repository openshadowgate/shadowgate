inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "bill-guisarme" }));
   set_name("bill-guisarme");
   set_short("A bill-guisarme");
   set_long(
	"This is a combination pole arm. It has a spike and axe on one "
	"end, and a hook on the other end. "
   );
   set_weight(15);
   set_size(3);
   set("value", 7);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("pierce");
   set_prof_type("polearm");
   set_weapon_prof("martial");
   set_weapon_speed(10);
   
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("piercing");
}
