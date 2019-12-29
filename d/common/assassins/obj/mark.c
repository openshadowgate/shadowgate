#include <std.h>
#include <terrain.h>
#include "../assassin_den.h"

inherit OBJECT;

int tracker;
string reason;

void create()
{
    ::create();
    set_name("assassins mark");
    set_id( ({ "mark999"}) );
    set_short("");
    set_long("");
    set_weight(0);
    set_property("no animate",1);
    set_heart_beat(2);
    tracker = time() + 3600+random(82800);
    reason = "";
}

int set_timer(int x)
{
    tracker = time()+x;
}

void set_reason(string why) { reason = why; }

void heart_beat()
{
    object creature;
    int level;
    int logintime;

    if(!objectp(ETO))
        return;
    if(!objectp(EETO))
        return;
    if(!interactive(ETO))
        return;

    //send assassin if not in city
    if (tracker > time())
        return;
    //wait a day before attack
    if(member_array(EETO->query_terrain(), CIVILIZATION) != -1)
        return;
    if(EETO->query_property("no teleport"))
        return;
    if(ETO->query_invis())
        return;

    logintime = (int)ETO->query_login_time();
    if(time() < logintime+600)
        return;

    if(present("voidhuntress",EETO))
        return;

    creature = new(MON+"voidhuntress");

    tell_room(EETO, "%^RED%^An assassin steps out of shadows and attacks "+ ETO->QCN + "!");

    level = ETO->query_character_level();

    creature->set_property("fighter_attacks_mod",level/4);
    creature->set_property("magic resistance",level + 30);
    creature->set_property("spell damage resistance",level);
    creature->add_damage_bonus(8+(level/8));
    creature->add_attack_bonus(8+(level/8));
    creature->set_hd(level + 5,20);
    creature->set_mlevel("fighter",level);
    creature->set_mlevel("thief",level);

    creature->set_max_hp(level*12+300);
    creature->set_hp(ETO->query_max_hp());
    creature->set_overall_ac(-1 * level -10);

    creature->move(EETO);
    creature->force_me("speak wizzish");
    creature->force_me("speech %^BOLD%^%^MAGENTA%^pu%^RESET%^%^MAGENTA%^r%^MAGENTA%^r%^BOLD%^%^BLACK%^ in a %^RESET%^%^MAGENTA%^s%^MAGENTA%^m%^BOLD%^%^MAGENTA%^ok%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^ voice%^RESET%^");
    creature->force_me("say %^BOLD%^%^MAGENTA%^You have been chosen to %^RED%^die%^MAGENTA%^.%^RESET%^");
    creature->set_target(ETO->query_name());
    creature->set_reason(reason);
    creature->kill_ob(ETO);
    TO->remove();
    return;
}
