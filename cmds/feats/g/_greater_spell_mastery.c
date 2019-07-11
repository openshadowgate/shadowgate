#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;
int choosing; 

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Archmage");
    feat_name("greater spell mastery");
    feat_syntax("greater_spell_mastery");
    feat_prereq("Archmage L4 or Hierophant L4");
    feat_desc("With the greater spell mastery feat, casters are able to use up to a 5th level spell with the spellmastery feat. Because of caster's undestanding of magic, they are able to change this spell after a period of time (20 real life hours).");
    permanent(1);
    set_required_for(({"arcane perfection"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("archmage") < 4 )
    {
        ob->delete("gspm_chosen");
        dest_effect();        
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void can_choose(object ob, string str)
{
    int num,level, okclasslvl, i, amt;
    object spell;
    string file, *myclasses, tmp;
    if(!objectp(ob)) { TO->remove(); return;}
    myclasses=({"mage"});
    if(!sizeof(myclasses)) 
    {
        tell_object(ob,"Your classes are broken! Contact a wiz!");        
        return -1;
    }    
    tmp = MAGIC_D->get_spell_file_name(str);
    if (tmp == "")
    {
        tell_object(ob,"No spell named "+str+" found.  Aborting...");
        return -1;
    }
    
    spell=new(tmp);
    level=min(
        filter_array(
            map_array(
                myclasses,"query_spell_level",spell),
            (:$1>0:)));
    spell->remove();    
    if(level>5)
    {
        tell_object(ob,"You can not cast the spell "+str+".  Aborting...");
        return -1;        
    }
    return 1;
}

varargs void my_choice(string str, object who)
{
    if(!objectp(who))
    {
        TO->is_choosing(0);
        TO->remove();
        return;
    }
    if(str == "**")
    {
        tell_object(who, "Aborting.... greater spell mastery spell not chosen.");
        TO->is_choosing(0);
        TO->remove();
        return;
    }
    if(!stringp(str) || undefinedp(str) || can_choose(who, str) == -1)
    {
        tell_object(who, "%^BOLD%^%^WHITE%^Please enter the name of the spell that you want "+
        "to work with your greater spell mastery feat. This can be any spell between levels 1 and "+
        "5 that you are able to cast. You may enter ** to abort.%^RESET%^");
        input_to("my_choice", who);
        return;
    }
    tell_object(who, "%^BOLD%^%^WHITE%^You have chosen to use the spell "+str+" as your greater spell mastery spell.");
    who->set("gspm_chosen", time());
    who->set("spellmastery_spell", str);
    TO->is_choosing(0);
    TO->remove();
    return;    
}

void mychoice(object who)
{
    if(!objectp(who)) { TO->is_choosing(0); TO->remove(); return; }
    if(who->query_class_level("archmage") < 4) { TO->is_choosing(0); TO->remove(); return; }
    if(time() < ((60 * 60 * 20) + (int)who->query("gspm_chosen")))
    {
        tell_object(who, "%^YELLOW%^You have already choosen a spell for your greater "+
        "spell mastery feat. You must wait at least 24 RL hours to change this.%^RESET%^");
        TO->is_choosing(0);
        TO->remove();
        return;
    }
    tell_object(who, "%^BOLD%^%^WHITE%^Please enter the name of the spell that you want "+
    "to work with your greater spell mastery feat. This can be any spell between levels 1 and "+
    "5 that you are able to cast. You may enter ** to abort.%^RESET%^");
    input_to("my_choice", who);
    return;
}

int is_choosing(int x) { choosing = x; }

int cmd_greater_spell_mastery(string str)
{
    object feat;
    if(!objectp(TP)) return 0;
    feat = new(base_name(TO));
    if(objectp(feat))
    {
        feat->is_choosing(1);
        feat->mychoice(TP);
    }
    return 1;    
    
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    if(choosing) return;
    ::dest_effect();
    remove_feat(TO);
    return;
}

void remove()
{
    if(choosing) return;
    return ::remove();
}
