#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create() 
{
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("MagusArcana");
    feat_name("arcane pool");
    feat_prereq("Magus L1");
    feat_classes("magus");
    feat_syntax("arcane_pool add|remove|on|off|check");
    feat_desc("The Shieldwall feat allows you to fight defensively using your shield to help deflect attacks and avoid incoming damage. The more defensively that you fight with your shield, the fewer melee attacks that you will get. You may increase your defensive ability with your shield until you have only one melee attack remaining. Using shieldwall defensively will also reduce the power of your spells. Using shieldwall defensively when you have the counter feat will also increase the damage of your attacks.");
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("magus")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_arcane_pool(string str)
{
    object feat;
    if (!objectp(TP)) { return 0; }
    if (str) str = lower_case(str);
    if (str != "add" &&
		str != "remove" &&
		str != "on" &&
		str != "off") {
		str = "check";
	}

    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

int check_my_status(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(ob->query_bound() || ob->query_unconscious() || ob->query_tripped())
    {
        tell_object(ob,"You are unable to move well enough to do that.");
        return 0;
    }
    return 1;
}

void execute_feat()
{
    int bonus;
    string featoption, buffoption;

    if(!check_my_status(caster))
    {
        dest_effect();
        return;
    }

    ::execute_feat();

    featoption = arg;

    switch(featoption)
    {

    case "add":
        buffoption = featoption;
        /*
        check valid options
        switch options
        check if option is active
        check option cost
        add cost
        add property        
        */
        if(option >= arcana_cap)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^You can't add this option!%^RESET%^");
            break;
        }

        tell_object(caster,"%^BOLD%^%^YELLOW%^You shift your stance, positioning your shield to better defend "
            "against all attacks!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" shifts "+caster->QP+" stance, positioning "
            ""+caster->QP+" shield to better defend against all attacks!%^RESET%^",caster);

        caster->set_property("shieldwall",1);
        //caster->add_ac_bonus(2); 
        caster->set_property("damage resistance",1);
        caster->set_property("shieldwall_bonus",1);
        caster->set_property("empowered",-1);
        break;

    case "remove":
        /*
        check valid options
        switch options
        check if option is active
        reduce cost
        remove property
        */

        if(!bonus)
        {
            tell_object(caster,"%^RESET%^%^MAGENTA%^You are no longer fighting defensively with your shield!%^RESET%^");
            break;
        }

        tell_object(caster,"%^BOLD%^%^YELLOW%^You shift your stance, moving from behind your shield into " +
            "better position to attack!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" shifts "+caster->QP+" stance, moving from " +
            "behind "+caster->QP+" shield and into a better position to attack!%^RESET%^", caster);

        caster->set_property("shieldwall",-1);
        //caster->add_ac_bonus(-2);
        caster->set_property("damage resistance",-1);
        caster->set_property("shieldwall_bonus",-1);
        caster->set_property("empowered",1);
        break;
		
	case "clear":
	    /*clear all options
        set cost to 1*/
		tell_object(caster,"%^BOLD%^%^YELLOW%^You shift your stance, positioning your shield to better defend " +
            "against all attacks!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" shifts "+caster->QP+" stance, positioning "
            + caster->QP + " shield to better defend against all attacks!%^RESET%^",caster);

        caster->set_property("shieldwall",MAX-bonus);
        caster->set_property("damage resistance",MAX-bonus);
        caster->set_property("shieldwall_bonus",MAX-bonus);
        caster->set_property("empowered",bonus-MAX);
        break;

    case "on":
        /*add property read by combat_d*/
        tell_object(caster, "%^BOLD%^%^YELLOW%^You shift your stance, moving from behind your shield into " +
            "better position to attack!%^RESET%^");
        tell_room(place, "%^BOLD%^%^YELLOW%^" + caster->QCN + " shifts " + caster->QP + " stance, moving from " +
            "behind " + caster->QP + " shield and into a better position to attack!%^RESET%^", caster);
        caster->set_property("shieldwall", -bonus);
        caster->set_property("damage resistance", -bonus);
        caster->set_property("shieldwall_bonus", -bonus);
        caster->set_property("empowered", bonus);
        break;

    case "off":
        /*remove property read by combat_d*/
        caster->remove_property("magus properties");
        break;

    case "check":
        tell_object(caster,"%^RESET%^%^GREEN%^You have shifted %^MAGENTA%^"+caster->query_property("shieldwall") +
            " %^RESET%^%^GREEN%^points into shieldwall.%^RESET%^");
        break;
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

