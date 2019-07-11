#include <std.h>
#include <daemons.h>
inherit FEAT;

void timer(object tp);

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("TwoHandedWeapons");
    feat_name("crushingstrike");
    feat_prereq("Strength 15");
    feat_syntax("crushingstrike TARGET");
    feat_desc("The CrushingStrike feat will strike a two handed weapon at the target in a single mighty swing. If the swing hits, it will do damage to the target and has a chance of rendering them unable to move for a time.");
    set_save("reflex");
    set_target_required(1);
    set_obsolete(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if((int)ob->query_base_stats("strength") < 15)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_crushingstrike(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    object *weapons;
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if(sizeof(weapons) < 2)
    {
        tell_object(caster,"You need to be wielding a two handed weapon to use "
            "this feat.");
        dest_effect();
        return;
    }
    if(weapons[0] != weapons[1])
    {
        tell_object(caster,"You need to be wielding a two handed weapon to use "
            "this feat.");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using twohandfeat") > time()) 
    {
        tell_object(caster,"You can't use crushingstrike again yet!");
        dest_effect();
        return;
    }
    ::execute_feat(); 
    if(!objectp(target) || !present(target,place)) 
    { 
        tell_object(caster,"You don't have a target!");
        dest_effect();
        return;
    }
    if(target == caster) 
    {
        tell_object(caster,"You shouldn't target yourself!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^RED%^You roar as you swing your "+weapons[0]->query_short()+" at "
        ""+target->QCN+" in a mighty overhand chop!%^RESET%^");
    tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" lets out a terrible roar as "
        ""+caster->QS+" swings "+caster->QP+" "+weapons[0]->query_short()+" down at you in an "
        "overhand chop!%^RESET%^");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" roars as "+caster->QS+" swings "+caster->QP+" "
        ""+weapons[0]->query_short()+" down at "+target->QCN+" in a mighty overhand "
        "chop!%^RESET%^",({caster,target}));

    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    caster->remove_property("using twohandfeat");
//    caster->set_property("using twohandfeat",time() + 15); 
    caster->set_property("using twohandfeat",time() + 30); //doubled timer to be on par with whirl etc. Nienne, 08/09.
    spell_kill(target,caster);
    return;
}

void execute_attack()
{
    object *weapons;
    int dam,mod,enchant,res;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    
    weapons = caster->query_wielded();

    if(sizeof(weapons) < 2)
    {
        tell_object(caster,"You need to be wielding a two handed weapon to use "
            "this feat!");
        caster->remove_property("using twohandfeat");
        dest_effect();
        return;
    }
    if(weapons[0] != weapons[1])
    {
        tell_object(caster,"You need to be wielding a two handed weapon to use "
            "this feat!");
        caster->remove_property("using twohandfeat");
        dest_effect();
        return;
    }
    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"Your target is no longer here!");
        caster->remove_property("using twohandfeat");
        dest_effect();
        return;
    }
    
    enchant = (int)weapons[0]->query_property("enchantment");

    if(!(res = thaco(target,enchant)))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^Your "+weapons[0]->query_short()+" barely misses "
            ""+target->QCN+", leaving you overbalanced!%^RESET%^");
        tell_object(target,"%^RESET%^%^BOLD%^"+caster->QCN+"'s "+weapons[0]->query_short()+" barely "
            "misses you, leaving "+caster->QCN+" off balance!%^RESET%^");
        tell_room(place,"%^RESET%^%^BOLD%^"+caster->QCN+"'s "+weapons[0]->query_short()+" barely "
            "misses "+target->QCN+" leaving "+caster->QCN+" off balance!%^RESET%^",({target,caster}));
        caster->set_paralyzed(roll_dice(1,6),"%^MAGENTA%^You are barely able to stay upright!%^RESET%^");
        dest_effect();
        return;
    }
    else if(res == -1)
    {
        if(stringp(caster->query("featMiss")))
        {
            tell_object(caster, caster->query("featMiss")+" " +query_feat_name()+"!");
            caster->delete("featMiss");
        }
        dest_effect();
        return;
    }

    dam = weapons[0]->query_large_wc();
    dam = (clevel/8 + 1) * dam;
    dam = roll_dice(2,dam);


    tell_object(caster,"%^RED%^You bring your "+weapons[0]->query_short()+" down in a brutal "
        "strike, maiming "+target->QCN+"!%^RESET%^");
    tell_object(target,"%^RED%^"+caster->QCN+" brings "+caster->QP+" "+weapons[0]->query_short()+ ""
        "down in a brutal attack, striking you painfully!%^RESET%^");
    tell_room(place,"%^RED%^"+caster->QCN+" brings "+caster->QP+" "+weapons[0]->query_short()+" down "
        "on "+target->QCN+", striking "+target->QO+" brutally!%^RESET%^",({target,caster}));

    target->do_damage("head",dam);
    
    if(!objectp(target)) 
    {
        dest_effect();
        return;
    }
    
    mod = dam;
    mod = mod * -1;

    if(!do_save(target,mod))
    {
        tell_object(caster,"%^YELLOW%^"+target->QCN+" is left staggered by the attack!%^RESET%^");
        tell_object(target,"%^YELLOW%^You are left staggered by "+caster->QCN+"'s attack and "
            "are unable to move!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+target->QCN+" is left staggered by "+caster->QCN+"'s attack "
            "and is unable to move!%^RESET%^",({caster,target}));
        target->set_paralyzed(roll_dice(2,4),"%^YELLOW%^You are struggling to move!%^RESET%^");
    }

    timer(caster);
//    dest_effect();
    return;
}

void timer(object tp)
{
   if(!objectp(tp))  return;  // added because it's in a callout *Styx*
   if(!tp->query_property("using twohandfeat")) dest_effect();
   if(!sizeof(tp->query_attackers())) { 
        tp->remove_property("using twohandfeat");
        dest_effect();
        return;
   }
   call_out("timer",1,tp);
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
