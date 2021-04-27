#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("locust");
   setenv("MIN","$N buzzes in.");
   setenv("MOUT","$N buzzes $D.");
   set_id(({"locust","giant locust","green locust","giant green locust","insect","bug"}));
   set_short("%^RESET%^%^GREEN%^giant green locust%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This large locust is horrific to look upon. At "
"least the size of a man's fist, every detail of its insectoid form can "
"be seen in clear detail. The long slender body, the wide diaphanous "
"wings, the long powerful legs and a giant mouth, all the better to "
"consume things with. Colored in various shades of green and light gray, "
"this bug appears to be ravenous as it swarms forth and devours all that "
"get in its way.%^RESET%^");
   set_alignment(5);
   set_race("bug");
   set_gender("neuter");
   set_body_type("insectoid");
   set_hd(10,1);
   set_stats("strength",10);
   set_max_hp(45);
   set_hp(45);
   set_exp(1);
   set_property("magic",1);
   set_attacks_num(1);
   set_damage(1,3);
   set_damage_bonus(3);
   set_attack_bonus(3);
   set_size(1);
   set_weight(10000);
   set_overall_ac(7);
   set_property("knock unconscious",1);
   set_property("no animate",1);
   set_attack_limbs(({"right fore leg","left fore leg"}));
}
