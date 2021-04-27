#include <std.h>

inherit OBJECT;

#define SCRY_D "/daemon/ic_scry_locate_d"


object target,scry_control;
int orb_uses=0,orb_end_time;

void create()
{
    ::create();
    set_name("BehrahsHolyOrb");
    set_id(({ "orb", "holy orb" }));
	set_short("%^ORANGE%^Ho%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^y Orb %^BOLD%^%^WHITE%^of %^RESET%^%^ORANGE%^Sun%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^er%^RESET%^");
	set_obvious_short("%^ORANGE%^a strange orb%^RESET%^");
	set_long("%^ORANGE%^Gazing into the orb, you can see a haze of smoke swirling inside.  "
        "From deeper within the haze, you can make out a pulsating glow emitting a "
        "%^RED%^red light%^ORANGE%^.  It is roughly 6 inches in diameter making it "
        "easy to hold, yet the haze seems endless as if you could fit a whole room inside.%^RESET%^");
    set_weight(5);
    set_value(12000);
	set_lore("%^BOLD%^An aged priest of %^MAGENTA%^Mystra %^WHITE%^by the name of "
        "%^CYAN%^Tiberius Sunder %^WHITE%^(circa 456 SG) was said to have a great "
        "fondness for knowledge.  In his eyes he claimed \"Knowledge is the key by "
        "which all mortals will unlock the door to their own eternity.\"  So eager "
        "he was to keep an eye on everything around him, that he made seven glass "
        "orbs into which he embued a special magic to be able to see things beyond "
        "his own eyes.  These were some of the first scrying devices evident to "
        "withstand the test of time, and yet they are as powerful if not more than "
        "those found in the realm today.  They worked as simply as <lookin> on "
        "your target.%^RESET%^");
    set_property("lore difficulty",20);
}
void init() 
{
    ::init();
    add_action("lookin","lookin");
}

int lookin(string str) 
{
    string *map_keys,real;
    int i,matches,num,duration,power;
    mapping map;

    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(living(ETO))
    {
        if(!objectp(EETO)) { return 0; }
    }

    if(orb_uses == 0) 
    {
        orb_uses++;
        orb_end_time = time() + 86400;
    }
    else if(orb_uses == 1 || orb_uses == 2)
    {
        orb_uses++;
    }
    else if(orb_uses == 3)
    {
        if(time() < orb_end_time)
        {
            tell_object(ETO,"%^YELLOW%^The mist in the orb stirs lazily but nothing else happens.  "
                "Maybe it needs time to recharge?%^RESET%^");
            return 1;
        }
        else
        {
            orb_uses = 1;
            orb_end_time = time() + 86400;
        }
    }

    if(!str) 
    {
        notify_fail("What?\n");
        return 0;
    }

    target = lower_case(str);
    
    if(ETO->isKnown(target) || ((string)ETO->realName(target) != "") ) 
    {
        map = (mapping)ETO->getRelationships();
        map_keys = keys(map);
        for(i=0;i<sizeof(map_keys);i++) 
        {
            if (!stringp(map[map_keys[i]])) continue;
            if(lower_case(map[map_keys[i]]) == target) 
            {
                matches++;
                real = lower_case(map_keys[i]);
            }
        }
    }

    if(!matches)
    {
       tell_object(ETO,"You do not recall a person called "+target+"!");
       return 1;
    }

    if(matches > 1) 
    {
       tell_object(ETO,"You know too many people with the same name!");
       return 1;
    }

    target = find_player(real);
    
    if(!target) 
    {
        notify_fail("%^ORANGE%^Within the mist the %^RED%^red light %^ORANGE%^shifts "
            "slightly, but does nothing else!\n");
        return 0;
    }

    if(target == TP) 
    {
        notify_fail("%^RESET%^%^ORANGE%^From within the inner mist of the orb, a "
            "hazy %^RED%^red eye %^ORANGE%^forms within the %^RED%^light, %^ORANGE%^blinking "
            "slowly as it stares back at you!\n");
        return 0;
    }

    if(target->query_property("no scry"))
    {
        notify_fail("%^ORANGE%^Within the mist the %^RED%^red light %^ORANGE%^forms "
            "into an %^RED%^eye %^ORANGE%^which blinks slowly as it glances around with a confused expression.\n");
        return 0;
    }

    tell_object(ETO,"%^ORANGE%^As you stare into the hazy orb, the %^RED%^red "
        "light %^ORANGE%^within slowly shifts into the form of an %^RED%^eye "
        "%^ORANGE%^which blinks only once before shifting into a glowing "
        "image!%^RESET%^");
    tell_room(EETO,"%^ORANGE%^As "+TPQCN+"'s stares into the hazy orb, "
        "the %^RED%^red light %^ORANGE%^slowly shifts into a %^RED%^glowing "
        "red eye %^ORANGE%^which blinks once before forming a glowing image!",TP);

    scry_control = new("/d/magic/obj/eye_orb");
    scry_control->set_caster(ETO);
    power = 25 + random(20);
    scry_control->set_scry_power(power);
    scry_control->set_target(target);
    scry_control->move(environment(target));
    duration = 8 * random(50);
    if(avatarp(ETO)) duration = 400;
    call_out("dest_effect", duration);
    return 1;
}


void dest_effect() 
{
    if(objectp(scry_control)) 
    {
        SCRY_D->stop_scry(scry_control, 0);
        scry_control->dest_me();
    }
    if(objectp(ETO))
    {
        if(living(ETO))
        {
            if(objectp(EETO))
            {
                tell_room(EETO,"%^ORANGE%^The %^RED%^glowing red eye %^ORANGE%^within "
                    "the misty orb closes suddenly, once again becoming just a %^RED%^hazy "
                    "red light!%^RESET%^");
            }
        }
    }
    return;
}

void control_failure() 
{
    TO->remove_call_out("dest_effect");
    if(objectp(ETO))
    {
        if(living(ETO))
        {
            if(objectp(EETO))
            {
                tell_room(EETO,"%^ORANGE%^The %^RED%^glowing red eye %^ORANGE%^within "
                    "the misty orb closes suddenly, once again becoming just a %^RED%^hazy "
                    "red light!%^RESET%^");
            }
        }
    }
    return;
}
