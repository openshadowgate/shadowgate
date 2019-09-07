/*Part of combat code is duplicated in this file. A similar duplication was causing problems in weaponless_monsters,
and I removed it there. If/when this file becomes active, please explore the duplications and see if they should be removed. ~Circe~ 2/12/13*/

//For hand to hand monsters

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit "/std/spellcaster";

/**
 * @file
 * @brief Weaponless combatans
 */

static mapping static_weaponless = ([]);

void set_damage(int num, int dice);
void set_attacks_num(int number);
void set_nat_weapon_type(string type);
void set_attack_limbs(string *limbs);
string *query_attack_limbs();
void set_hit_funcs(mapping stuff);
private int get_hand_damage(string limb, int damage, object attacked);


void create()
{
    static_weaponless = ([]);

    static_weaponless["attack_funcs"] = ([]);
    static_weaponless["num_dice"] = 1;
    static_weaponless["type"] = 4;
    static_weaponless["num_hand"] = 0;
    static_weaponless["weapon_type"] = "bludgeon";
    static_weaponless["attack_limbs"] = ({ "right hand", "left hand" });

    ::create();
}
// not used for shapeshifting, maybe old code somewhere? -Ares
void toggle_polymorphed()
{
   static_weaponless["polymorphed"]?static_weaponless["polymorphed"] = 0:static_weaponless["polymorphed"]=1;
}

int query_polymorphed() { return static_weaponless["polymorphed"];}

int is_weaponless()
{
   if(sizeof(TO->query_wielded()) > 0) return 0;
   return 1;
}


void set_hit_funcs(mapping stuff)
{
    static_weaponless["attack_funcs"] = ([]);
    static_weaponless["attack_funcs"] = stuff;
}


void set_damage(int num, int dice)
{
    static_weaponless["num_dice"] = num;
    static_weaponless["type"] = dice;
}


void set_attacks_num(int number)
{
    static_weaponless["num_hand"] = number;
}


int query_attacks_num()
{
   return static_weaponless["num_hand"];
}


void set_nat_weapon_type(string type)
{
    static_weaponless["weapon_type"] = type;
}


string query_nat_weapon_type()
{
    return static_weaponless["weapon_type"];
}


void set_attack_limbs(string *limbs)
{
    static_weaponless["attack_limbs"] = limbs;
    //static_weaponless["polymorphed"] = 1;
}


string *query_attack_limbs()
{
    return static_weaponless["attack_limbs"];
}


int query_num_natural_attacks()
{
   return sizeof(static_weaponless["attack_limbs"]);
}


string return_attack_limb()
{
    string *limbs;
    limbs = static_weaponless["attack_limbs"];
    return limbs[random(sizeof(limbs))];
}

string *return_attack_limbs()
{
    return static_weaponless["attack_limbs"];
}

mapping return_attack_funcs()
{
    return static_weaponless["attack_funcs"];
}

int get_hand_damage(string limb1, int damage, object attacked)
{
    return "/daemon/combat_d.c"->get_hand_damage(TO, limb1, damage, attacked);
}

int query_unarmed_damage()
{
    if(objectp(TO))
    {
        if(userp(TO)) return (int)"/daemon/combat_d.c"->calculate_unarmed_damage(TO);
    }
    return roll_dice(static_weaponless["num_dice"],static_weaponless["type"]);
}
