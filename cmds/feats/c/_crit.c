#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Assassin");
    feat_name("crit");
    feat_syntax("crit TARGET");
    feat_prereq("Assassin L1");
    feat_desc("You perform a devastating attack that has a chance to kill your enemy instantly. The save throw gets a bonus from your intelligence score. If your target succeeds the save, either by being warded against death ot by being studry, it will still suffer greatly.");
    set_target_required(1);
    set_save("fort");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("assassin") < 1)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_crit(string str)
{
    object feat;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    mapping tempmap;
    int x;
    int damage, timerz, i, bonusdc;
    object *keyz, qob;
    ::execute_feat();
    if(!objectp(target))
    {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",caster);
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if(target == caster)
    {
        tell_object(caster,"There are better ways to kill yourself!");
        dest_effect();
        return;
    }
    if(!present(target, place))
    {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using crit");
    if(mapp(tempmap))
    {
        if(tempmap[target] > time())
        {
            tell_object(caster,"That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }

    caster->set_property("using instant feat",1);
    spell_kill(target,caster);

    tell_object(caster, "%^BOLD%^%^WHITE%^You study the place and your target, preparing yourself for a jump.%^RESET%^");
    tempmap = caster->query_property("using crit");
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,target);
    keyz = keys(tempmap);
    for(i=0;i<sizeof(keyz);i++)
    {
        if(!objectp(keyz[i])) map_delete(tempmap, keyz[i]);
        continue;
    }
    timerz = time() + 90;
    delay_subject_msg(target,90,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^crit%^WHITE%^ again.%^RESET%^");
    tempmap += ([ target : timerz ]);
    caster->remove_property("using crit");
    caster->set_property("using crit",tempmap);

    tell_object(caster, "%^RESET%^You find vulnerable spot to attack "+target->QCN+" at.%^RESET%^");

    bonusdc = clevel+10;
    bonusdc += BONUS_D->query_stat_bonus(caster, "intelligence");
    if((string)target->query_property("no death") || do_save(target,-bonusdc))
    {
        int todamage;
        tell_object(target,"%^BOLD%^%^WHITE%^The immense pain spreads from your back!!%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^You almost didn't see a shadow behind "+target->QCN+"'s back!",({target,caster}));
        tell_object(caster,"%^BOLD%^%^WHITE%^You phase quickly behind "+target->QCN+", but "+target->QS+" withstands your assault.");
        if(target->query_max_hp()<caster->query_max_hp())
            todamage = roll_dice(clevel,8);
        else
            todamage = roll_dice(clevel,8)+roll_dice(clevel,bonusdc);
        target->cause_typed_damage(target, target->query_target_limb(),todamage,"untyped");
    } else {
        tell_object(target,"%^BOLD%^%^WHITE%^Wait, what?! How did it happen?!%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^You almost didn't see a shadow behind "+target->QCN+"'s back!",({target,caster}));
        tell_object(caster,"%^BOLD%^%^WHITE%^You phase quickly behind "+target->QCN+" and put an end to them with a swift motion.");
        target->cause_typed_damage(target, target->query_target_limb(),target->query_max_hp()*2,"untyped");
    }
    return;
}

void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
