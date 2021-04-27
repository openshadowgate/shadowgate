#include <std.h>
#include <daemons.h>
inherit MONSTER;

void create(){
    ::create();
    set_id(({"priest","dark priest","cowled priest"}));
    set_name("banite priest");
    set_short("%^BOLD%^%^BLACK%^A dark cowled priest%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This man's blackened armor is marked with a "
"clenched gauntleted fist on the front, marking him as a servant of Bane. A "
"heavy cowl hides most of his features, but you catch an occasional glimpse "
"of dark eyes gleaming with a malign purpose. Despite the weapon at his side, "
"he seems more inclined to raise his hands to conjure fury directly.%^RESET%^");
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_class("cleric");
    set_class("paladin");
    set_diety("bane");
    set_mlevel("cleric",25);
    set_mlevel("paladin",15);
    set_guild_level("cleric",25);
    set_guild_level("paladin",15);
    set_hd(25,10);
    set_max_hp(1234);
    set_hp(1234);
    set_mob_magic_resistance("average");
    set_overall_ac(0);
    set_property("no rush",1);
    set_property("no dominate",1);
    set_exp(15000);
    set_stats("strength",18);
    set_stats("constitution",18);
    set_stats("dexterity",17);
    set_stats("charisma",17);
    set_alignment(3);
    add_money("gold",random(500)+150);
    add_money("platinum",random(10)+5);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/laerad/obj/pallyplate")->move(TO);
    present("plate",TO)->set_property("monsterweapon",1);
    command("wear armor");
    set_spells(({"hold person","call lightning","call lightning","dispel good","dispel good","cause critical wounds"}));
    set_spell_chance(70);
    set_property("knock unconscious",1);
}