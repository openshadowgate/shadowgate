#include <std.h>

inherit "/std/monster";

/**
 * Designed and described by Sierra.
 */
void create()
{
    object weapon;
    int level = 60;

    ::create();
    set_name("wyvern");
    set_id(({"wyvern","bone wyvern","undead", "bonewyvern"}));
    set_short("%^BOLD%^%^WHITE%^B%^BLACK%^o%^RESET%^%^WHITE%^n%^BOLD%^e w%^RESET%^y%^BOLD%^%^BLACK%^v%^RESET%^%^WHITE%^e%^BOLD%^rn%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This beast is a clear mimicry of those smaller cousins of dragonkin, but devoid of flesh and organs. It doesn't appear to quite be simply reanimated; rather, some sort of undead construct, as it is actually formed of humanoid bones. The skull appears to be made up of the smashed remnants of humanoid ones, arranged in a draconic visage and held together by the unnatural %^BLACK%^d%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^r%^BLACK%^kn%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^s%^BLACK%^s %^WHITE%^that grants its horrid semblance of %^CYAN%^life%^WHITE%^. Not one, but three series of vertebrae arranged in pyramid fashion, form the spine that makes up the bulk of the beast's six meter length. The spikes upon its back appear to be phalanges curled away from the fore of its body. Twisting humeri warped into a double-helix protrude from its spindly torso, tipped with 'fingers' several ribs in length to form its seemingly useless wings. The body appears to move ever so slightly when idle, using its wings as forelegs, a rhythmic bob emulating breaths in time with the faint %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^ol%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^BOLD%^%^WHITE%^pulsing from its %^RESET%^%^BLUE%^s%^BOLD%^%^BLUE%^h%^BLACK%^a%^RESET%^%^BLUE%^d%^BOLD%^%^BLUE%^o%^BLACK%^w%^RESET%^%^BLUE%^y %^CYAN%^core%^BOLD%^%^WHITE%^.");
    set_race("wyvern");
    set_attack_limbs( ({ "maw","head","torso","right claw", "left claw", "right arm","right arm","left leg","left rear claw","right leg","right rear claw","tail","right wing","left wing" }) );
    set_gender("other");

    set_size(3);
    set_class("fighter");

    set("aggressive",2);
    set_property("swarm",0);

    set_nogo(({"/d/dagger/road/p7",
               "/d/dagger/road/tempusportal",
               "/d/dagger/road/road35",
               "/d/dagger/road/road25"
               }));

    set_level(level);
    set_guild_level("fighter", level);
    set_guild_level("mage", level);
    set_mlevel("fighter", level);
    set_mlevel("mage", level);
    set_hd(level, 10);

    set_max_hp(level * 14 + 100);
    set_hp(query_max_hp());

    set_wielding_limbs(({"right hand","left hand"}));
    set_property("undead", 1);
    set_body_type("dragon");
    set_property("full attacks", 1);

    set_skill("perception", 40);
    set_skill("athletics", 40);
    set_skill("spellcraft", 40);

    set_stats("strength", 20);
    set_stats("dexterity", 18);
    set_stats("constitution", 18);
    set_stats("intelligence", 22);
    set_stats("wisdom", 10);
    set_stats("charisma", 8);

    set_new_exp("normal", 35);

    set_property("cast and attack", 1);
    
    set_spells(({
                 "acid breath",
                 "necrophage",
                 "acid fog"
                 "nightmare maw",
                 "unholy aura",
                 "frightful aspect"
              }));
                 
    set_spell_chance(30);
    set_property("fast healing", 5);
    set_resistance_percent("slashing", 10);
    set_resistance_percent("bludgeoning", -10);
    set_alignment(9);

    add_search_path("/cmds/feats");
    add_search_path("/cmds/fighter");

    set_monster_feats(({
                "resistance",
                "rapid strikes",
                "evasion",
                "knockdown",
                "perfect caster",
                }));

    set_fighter_style("soldier");
    command("flaps in on deathly wings.");
    command("flaps out $D.");
}
