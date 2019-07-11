// updating damage and size to be closer to 3rd ed per discussions with Cythera & Circe *Styx* 8/2/05

inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "whip"}));
   set_name("whip");
   set_short("A whip");
//   set_long( "This ordinary bullwhip really doesn't look like it'd be of much use, unless you were going to herd cattle.  Against an armored opponent its use would be laughable.");
   set_long("Interwoven strips of leather and steel have been braided together to "+
   "create this flexible whip.  The handle of the whip is crafted from leather, "+
   "creating a comfortable grip.  The tip of the whip has been dipped in molten "+
   "steel, adding an effective touch to the whip.");
   set_weight(2);
   set_size(2);
   set_value(5);
//   set_cointype("silver");
   set_wc(1,6);   // was 1,2
   set_large_wc(1,6);  // was 1,2
   set_type("lash");
   set_prof_type("whip");
   set_weapon_speed(8);
   set_weapon_prof("exotic");
   
   set_critical_threat_range(1);
   set_critical_hit_multiplier(2);
   set_property("repairtype",({"leatherwork"}));
   set_damage_type("slashing");
}
