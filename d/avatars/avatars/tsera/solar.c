#include <std.h>
inherit MONSTER;
int DEATH = 0;
object blurgle;
int asked;

void create() {
    ::create();
   set_name("%^BOLD%^%^BLACK%^Solar%^RESET%^");
    set_id(({"solar", "Solar", "SOLAR"}));
   set_short("%^BOLD%^%^BLACK%^SOLAR%^RESET%^");
    set_long(
"%^BOLD%^%^BLACK%^This incredible spirit stands boldly before you.  It has an incredible dark aura about it and it stares at you with intent %^RED%^red eyes.  %^BLACK%^Obviously corrupted by some unnatural force, the evil emminating from it is emmense. "
    );
   set_class("antipaladin");
    set_hd(60,7);
   set_overall_ac(-60);
    set_gender("male");
    set_race("spirit");
   set_guild_level("antipaladin",60);
   set_mlevel("antipaladin",60);
    set_hp(30000);
   set_max_hp(30000);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_exp(50000);
    set_size(3);
    set_body_type("human");
    set_wielding_limbs(({"right hand","left hand"}));
   set_stats("strength",30);
   set_alignment(9);
    set_stats("dexterity",30);
    set_stats("charisma",30);
    set_stats("constitution",30);
    set_stats("wisdom",30);
    set_stats("intelligence",30);
    set_attack_bonus(10);
   set_damage_bonus(10);
    set_property("knock unconscious",1);
    set_emotes(3, ({
"The %^BOLD%^%^WHITE%^SOLAR%^RESET%^ gazes into your soul.",
"%^BOLD%^%^BLACK%^SOLAR says:  Are you strong enough to challenge "
      "the impending threat?%^RESET%^",
	"The %^WHITE%^%^BOLD%^SOLAR%^RESET%^ sizes you up."
      }),0);
   new("/d/attaya/obj/scimitar")->move(TO);
    command("wield sword");
}
