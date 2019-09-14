#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

object *exclude = ({});

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("EldritchKnight");
    feat_name("eldritch warfare");
    feat_prereq("Eldritch Knight L4");
    feat_syntax("eldritch_warfare");    
    feat_desc("Eldritch knight becomes one with magic during combat, if they so wish, knight can divide his attention and cast during combat at the price of potency of their spells.");
}


int allow_shifted() { return 0; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("eldritch_knight") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_eldritch_warfare(string str) 
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

string cm(string str) 
{
    return CRAYON_D->color_string(str,"dark black");
}

void execute_feat()
{
    string YOU,YOUS;
    object obj;
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    if(FEATS_D->is_active(caster,"eldritch warfare"))
    {
        obj = query_active_feat("eldritch warfare");
        tell_object(caster,cm("You release your concentration on warsongs."));
        obj->dest_effect();
        dest_effect();
        return;
    }
    
    tell_object(caster,cm("You concentrate on your warsongs, starting moving rhythmically."));
    tell_room(place,cm(""+caster->QCN+"starts moving rhythmically in unison with "+caster->QP+" warsongs."), caster);   
    caster->set_property("active_feats",({TO}));
    caster->set_property("cast and attack",1);
    ::execute_feat();
    return;
}

void dest_effect()
{
    if(objectp(caster)) 
    {
        caster->remove_property_value("active_feats",({TO}));
        caster->remove_property("cast and attack");
        tell_object(caster,"%^BOLD%^%^BLUE%^Your concentration on warsongs fades.");        
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}

