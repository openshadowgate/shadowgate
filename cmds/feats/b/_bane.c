/*
  _bane.c
  
  Inquisitor feat from PF SRD.
  Temporarily buffs your weapon against a specific enemy type.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <favored_types.h>

#define COOLDOWN 500

inherit FEAT;

object weapon, feat;
string *valid_choices;

void create()
{
    ::create();
    
    valid_choices = keys(VALID_ENEMY);
    
    set_author("tlaloc");
    feat_type("instant");
    feat_category("Inquisition");
    feat_name("bane");
    feat_prereq("Inquisitor L5");
    feat_syntax("bane [TYPE]");
    feat_desc("This feat allows the inquisitor to infuse the weapon in their main " +
"hand with divine power that targets a specific type of enemy. This infusion has a " +
"chance to do divine damage, based on weapon dice. The chance of this bane hitting and the " +
"damage done increases with your Inquisitor levels. " +
"You can select from the following bane enemy types: \n\n" + "%^CYAN%^BOLD%^" + implode(valid_choices, "\n"));
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {
        return 0;
    }
    if(ob->query_class_level("inquisitor") < 5)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_bane(string str)
{   
    if(!this_player())
        return 0;

    feat = new(base_name(this_object()));
    feat->setup_feat(this_player());
    return 1;
}

void execute_feat()
{
    string type;
    mapping info;
    int timer;
    
    if(!caster)
        return;
    
    weapon = caster->query_wielded()[0];
    
    if((int)caster->query_property("using instant feat"))
    {
        write("You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    if(caster->query_current_attacker())
    {
        write("You cannot infuse your weapon with a bane during combat.");
        dest_effect();
        return;
    }
    
    if(this_player()->query_property("bane reset") > time() - COOLDOWN)
    {
        write("You may only change your favored enemy once every three weeks.");
        return;
    }
    
    if(member_array(arg, valid_choices) < 0)
    {
        write("Valid bane choices are : " + implode(valid_choices, ", "));
        dest_effect();
        return;
    }
    
    if(!weapon)
    {
        write("You must be wielding a weapon in your main hand to use Bane.");
        dest_effect();
        return;
    }
    
    if(weapon->query_property("tmp_hit_bonus"))
    {
        write("Your weapon is already magically enhanced.");
        dest_effect();
        return;
    }
    
    write("%^BOLD%^You fuse your weapon with the might of your god, giving it extra potency against %^CYAN%^" + arg + "%^RESET%^BOLD%^ enemies.");
    info = ([  ]);
    info["file"] = "/d/magic/obj/weap_effects/bane";
    info["func name"] = "bane_func";
    info["spell"] = this_object();
    weapon->set_property("temp_hit_bonus", info);
    weapon->set_property("added short", ({ "%^CYAN%^BOLD%^ [bane]%^RESET%^" }) );
    caster->set_property("using instant feat",1);
    timer = 1 + this_player()->query_guild_level("inquisitor");
    call_out("dest_effect", timer);
}

void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }   
    delay_subject_msg(caster, COOLDOWN, "%^BOLD%^You can infuse your weapon with a bane once again.%^RESET%^");
    caster->set_property("bane reset", time());
    caster->remove_property("using instant feat");
    ::execute_attack();
}
       

void dest_effect()
{
    if(objectp(weapon))
        load_object("/d/magic/obj/weap_effects/bane")->remove_prop(weapon);
    ::dest_effect();
    remove_feat(this_object());
    return;
}
    