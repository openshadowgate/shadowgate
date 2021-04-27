#include <std.h>
#include <daemons.h>

inherit OBJECT;

int uses;

void create()
{
    ::create();

    set_id(({"bottle","liquid","oil","oil of burning"}));

    set_name("oil of burning");
    set_obvious_short(cm("A bottle of glowing red oil"));
    set_short(cm("Oil of Burning"));

    set_long(cm("This small bottle of liquid glows an angry red color.  The bottle itself is cool, but just "
        "looking at the liquid you are sure that it would be incredibly hot to the touch.  Perhaps some "
        "enchantment contained in the bottle keeps the liquid from melting its container.  You could "
        "probably") + " %^RESET%^%^BOLD%^%^MAGENTA%^<apply oil to (weapon)>%^RESET%^ " + cm("and the weapon "
        "would burn enemies that it touched."));

    set_weight(2);
    set_value(5000);

    uses = roll_dice(1,50) + 150;
}

string cm(string str) { return CRAYON_D->color_string(str,"dark red"); }

void init() 
{
    ::init();
    add_action("apply","apply");
}


int apply(string str)
{
    mapping info = ([]);
    object obj;
    function func;

    if(!stringp(str) || str == "" || str == " ") { return 0; }
    if(!objectp(TP)) { return 0; }

    str = replace_string(str,"oil to ","");

    if(!objectp(obj=present(str,TP)))
    {
        tell_object(TP,"You don't seem to have a "+str+".");
        return 1;
    }

    if(obj->query_property("temp_hit_bonus"))
    {
        tell_object(TP,"That "+str+" already seems to have something on it.");
        return 1;
    }
    
    info["file"] = base_name(TO);
    info["func name"] = "burn_func";

    obj->set_property("temp_hit_bonus",info);  

    tell_object(TP,cm("You coat the "+obj->query_short()+" with the oil and it bursts "
        "into flames."));
    tell_room(ETP,cm(""+TP->QCN+" coats the "+obj->query_short()+" with oil and it "
        "bursts into flames."));

    obj->set_property("added short",({ "%^RED%^ (flaming)%^RESET%^" }));
    TO->move("/d/shadowgate/void.c");
    TO->remove();
    return 1;
}



int burn_func(object obj)
{
    object targ, tp, etp;
    
    if(!objectp(obj)) { return 0; }
    if(!objectp(environment(obj)) || !living(environment(obj))) { return 0; }
    
    tp = environment(obj);
    etp = environment(tp);
    if(!objectp(etp)) { return 0; }
    
    targ = tp->query_current_attacker();
    if(!objectp(targ)) { return 0; }

    if(uses < 1) // need to remove the burning effect here.  This will be the case for any effect that should end.  -Ares
    {
        tell_object(tp,"%^BLUE%^The fire on your "+obj->query_short()+"%^BLUE%^ sputters and dies, as the last of the oil is exhausted.%^RESET%^");
        tell_room(etp,"%^BLUE%^The fire on "+tp->QCN+"'s "+obj->query_short()+"%^BLUE%^ sputters and dies.%^RESET%^",tp);

        obj->remove_property("temp_hit_bonus");
        obj->remove_property_value("added short",({ "%^RED%^ (flaming)%^RESET%^" }));
        return 1;
    }

    tell_object(tp,"%^RED%^The fire on your "+obj->query_short()+"%^RED%^ burns "+targ->QCN+"%^RED%^ as you strike "+targ->QO+"%^RED%^.%^RESET%^");
    tell_object(targ,"%^RED%^The fire on "+tp->QCN+"%^RED%^'s "+obj->query_short()+"%^RED%^ burns as it strikes you!%^RESET%^");
    tell_room(etp,"%^RED%^The fire on "+tp->QCN+"%^RED%^'s "+obj->query_short()+"%^RED%^ burns "+targ->QCN+"%^RED%^ as it strikes "+targ->QO+"%^RED%^.%^RESET%^",({tp,targ}));

    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1,8),"fire");

    uses--;
    return 1;
}
