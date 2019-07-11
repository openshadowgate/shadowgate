#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit FEAT;

int FLAG;

int light_armor_filter(object ob) {
    if(!objectp(ob)) { return 0; }
    if(ob->query_armor_prof("light")) { return 0; }
    return 1;
}

int armor_filter(object ob) {
    if(!objectp(ob)) { return 0; }
    if(ob->query_armor_prof("light")) { return 1; }
    if(ob->query_armor_prof("medium")) { return 1; }
    if(ob->query_armor_prof("heavy")) { return 1; }
    return 0;
}

void create() {
    ::create();
    feat_type("premanent");
    feat_category("MagicDamage");
    feat_name("spellmastery");
    feat_prereq("Not Warlock");
    feat_desc("When selecting the SpellMastery feat, the character will be prompted to pick a spell that they are able to cast. From that point forward the character will be able to cast that spell at will at any time without needing components or memorization. Only spells of 1st and 2nd level may be picked for SpellMastery. If you have more than one class able to use the same spell, the power of the SpellMastery (as well as armor checks, etc) will be based upon the highest of these.

%^BOLD%^N.B.%^RESET%^ Spellmastery is not connected to <master> in any way. It just allows you to cast the spell without memorization or component cost. You still have to know the spell to cast it, have it in your spellbook, mastered or in your spell list.");

    permanent(1);
    allow_tripped(1);
    set_required_for(({"spell power","improved spell power","greater spell power","hardenedminions","magic arsenal"}));
    set_replaces_feat("expanded knowledge 1"); 
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    string *classes,file;
    int i;
    if(!objectp(ob)) { return 0; }

    if(ob->is_class("warlock")){
        return 0;
    }
    classes = (string *)ob->query_classes();
    for(i=0;i<sizeof(classes);i++) 
    {
        file = DIR_CLASSES+"/"+classes[i]+".c";        
        if(file->caster_class()) { return ::prerequisites(ob); }
    }
    return 0;
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void execute_feat() {
    ::execute_feat();
    dest_effect();
    return;
}

void dest_effect() 
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

