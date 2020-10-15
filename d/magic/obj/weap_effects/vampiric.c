/*
  vampiric.c
  
  Adds the vampiric effect to a weapon. Used by vampiric weapon
  AKA vampiric blade in psywarrior spell list.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int vampiric_func(object ob)
{
    object room, player, spell, enemy;
    int amount;
    string pname, ename;
    mapping info;
    
    if(!objectp(ob))
        return 0;
    
    player = environment(ob);
    
    if(!userp(player))
        return 0;
    
    room = environment(player);
    
    if(!objectp(room))
        return 0;
    
    info = ob->query_property("temp_hit_bonus");
    spell = info["spell"];
    
    if(!objectp(spell))
        remove_prop(ob);
    
    enemy = player->query_current_attacker();
    
    if(!objectp(enemy))
        return 0;
    
    pname = capitalize(player->query_name());
    ename = capitalize(enemy->query_name());
    //SRD is WC / 2. This scales with level
    amount = ob->query_wc() * (1 + player->query_guild_level("psywarrior") / 10);
    
    if(!random(10))
    {
        tell_object(player, "%^GREEN%^Your weapon seems to draw upon " + ename + "'s life force!%^RESET%^");
        tell_object(enemy, "%^GREEN%^" + pname + "'s weapon seems to draw upon your life force!");
        tell_room(room, "%^GREEN%^" + pname + "'s weapon seems to draw upon " + ename + "'s life force!", ({ player, enemy }));
        player->add_hp(amount);
        damage_targ(enemy, enemy->return_target_limb(), ob->query_wc(), "negative energy");
    }
}

void remove_prop(object ob)
{
    object player;
    
    ob->remove_property_value("added short", ({ "%^MAGENTA%^ {vampiric}%^RESET%^" }) );
    ob->remove_property("temp_hit_bonus");
    
    player = environment(this_object());
    player && tell_object(player, "%^GREEN%^The vampiric energies fade from your weapon.%^RESET%^");
}
    
    
    
    
    
    
    