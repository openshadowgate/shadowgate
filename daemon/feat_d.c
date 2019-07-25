//added several catch() checks so that a typo in a feat does not break heartbeat anymore - Saide - April 2016
#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <class_types.h>
#include <feats.h>
#include <schoolspells.h>

inherit DAEMON;

int can_gain_feat(object ob,string feat);
int can_gain_bonus_feat(object ob,string feat);
int can_gain_magic_feat(object ob,string feat);
int can_gain_hybrid_feat(object ob,string feat);
int add_my_feat(object ob,string type,string feat);
int remove_my_feat(object ob,string feat,int bypass);
int can_remove_feat(object ob,string feat);
string *get_all_removable_feats(object ob);
varargs int gain_feat(object ob, string type, string feat,int level);
int meets_requirements(object ob, string feat);
varargs int gain_feat(object ob, string type, string feat,int level);
int is_active(object ob,string feat);
void reverse_permanent_feat(object ob,string feat);
void execute_permanent_feat(object ob,string feat);
int is_permanent(object ob,string feat);
int can_use_feat(object ob,string feat);
int level_to_use(object ob,string feat);
int level_of_feat(object ob,string feat);
int has_feat(object ob, string feat);
int has_epic_feat(object ob);
int is_feat(string feat);
string get_feat_type(object ob,string feat);
void remove_feat(object ob,string type, string feat);
varargs void add_feat(object ob, string type, string feat,int level);
void give_feat(object ob,string feat);
void take_feat(object ob,string feat);
void set_feats(object ob,string type,mapping feats);
mapping get_feats(object ob,string type);
mapping player_data(object ob);
void build_feat_list();
string get_category(string featname);
mapping get_all_feats();
string format_category(string cat);
string pick_color(string feat,object targ);
string format_feat(string feat,object targ);
string *format_feats(string *left,string *right,object targ);
void display_feats(object ob,object targ,string mytype);
void clear_usable_feats();
void update_usable(object ob);
int usable_feat(object ob,string feat);
string *class_feat_array(string myclass,string spec);
int bought_as_class_feat(string feat,object targ);
int bought_as_bonus_feat(string feat,object targ);
int bought_as_magic_feat(string feat,object targ);
int bought_as_hybrid_feat(string feat,object targ);
int can_use_shifted(object ob, string feat);
int calculate_psionic_feats(object ob);
int filter_feats(object ob, string feat);

static mapping __ALL_FEATS;
static mapping __USABLE_FEATS;

void obsolete_feat(object ob) {
    string *obsolete, *bad_feats=({}), *removing_feats, mytype,*myspells,*schoolspells;
    int i,j,num,freebs;
    object feat_ob;

    if(!objectp(ob)) return;
    if(!interactive(ob)) return;
    if(!userp(ob)) { return; }

    obsolete = ({ "greater spell focus","crushingstrike","lightning reflexes","iron will","great fortitude",
        "blade block","unassailable parry","greater two weapon fighting","two weapon defense","calm","rapid shot",
        "wild shape dragon","hardenedminions","slippery caster","thick skinned caster","wild shape wolf",
        "archmage","body cognition","chronicler","presence of mind","shadow adept","shadowdancer",
        "versatile arcanist","wild shape dragon","wild shape elemental" });
        //"persistent rage","unyielding rage"

    for(i=0;i<sizeof(obsolete);i++) {
        if(has_feat(ob,obsolete[i])) bad_feats += ({ obsolete[i] });
    }
    if(!sizeof(bad_feats)) return;

    num = (int)ob->query("free_feats");
    freebs = num;

    for(i=0;i<sizeof(bad_feats);i++) {
        switch(bad_feats[i]) {

        case "greater spell focus":
            
            removing_feats = ({ "armored caster","greater spell penetration","spell penetration","greater spell focus" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
                tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat Greater Spell Focus has been marked "
                    "as obsolete and you have had the feats in the MagicAccuracy tree refunded.  For "
                    "each feat that you had in this tree you will recieve a free feat to spend that will "
                    "cost you no experience points.  It is not necessary to spend these free feats on "
                    "feats from the MagicAccuracy tree, feel free to spend them any way that you wish.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "crushingstrike":
            
            removing_feats = ({ "crushingstrike","blade block","impale","light weapon","sweepingblow" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
                tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat CrushingStrike has been marked "
                    "as obsolete and you have had the feats in the TwoHandedWeapons tree refunded.  For "
                    "each feat that you had in this tree you will recieve a free feat to spend that will "
                    "cost you no experience points.  It is not necessary to spend these free feats on "
                    "feats from the TwoHandedWeapons tree, feel free to spend them any way that you wish.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "lightning reflexes": case "iron will": case "great fortitude":
            
            removing_feats = ({ "lightning reflexes","iron will","great fortitude","improved resistance","increased resistance" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
                tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feats Great Fortitude, Iron Will and "
                    "Lightning Reflexes have been marked as obsolete and you have had the feats in "
                    "the MagicResistance tree refunded.  For each feat that you had in this tree you "
                    "will recieve a free feat to spend that will "
                    "cost you no experience points.  It is not necessary to spend these free feats on "
                    "feats from the MagicResistance tree, feel free to spend them any way that you wish.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "blade block": //revoking blade block for those now with the fighter or cavalier class parry feat

            if(has_feat(ob,"blade block") && has_feat(ob,"parry")) {
              mytype = get_feat_type(ob,"blade block");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"blade block",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^blade block");
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat Blade Block has been removed from your "
                    "list now that the fighter/cavalier class feat Parry is able to substitute for it.  "
                    "You have been refunded a free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "unassailable parry": //revoking feat for those now with the fighter or cavalier class parry feat
            
            if(has_feat(ob,"unassailable parry") && has_feat(ob,"parry")) {
              mytype = get_feat_type(ob,"unassailable parry");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free\
              if(mytype != "class") { // had to put this in cuz fighter/ranger multis were freaking out with the class feat! N, 6/15.
                remove_my_feat(ob,"unassailable parry",1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^unassailable parry");
                tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat Unassailable Parry has been removed from your "
                    "list now that the fighter/cavalier class feat Parry is able to substitute for it.  "
                    "You have been refunded a free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
                ob->set("free_feats",num);
              }
            }
            freebs = num;
            break;

        case "greater two weapon fighting": case "two weapon defense": //revising dual-wield tree feats

            removing_feats = ({ "greater two weapon fighting","two weapon defense" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The upper dual-wield tree feats have been revised, "
                    "and the obsolete ones have been removed from your list.  You have been refunded "
                    "equivalent free feat/s to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "calm": //revoking feat from non-bards
            
            if(has_feat(ob,"calm") && !ob->is_class("bard")) {
              mytype = get_feat_type(ob,"calm");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"calm",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^calm");
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat Calm has been removed from your "
                    "list as it is restricted to the bard class only.  You have been refunded a "
                    "free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "rapid shot": //revoking redundant archery feat
            
            if(has_feat(ob,"rapid shot")) {
              mytype = get_feat_type(ob,"rapid shot");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"rapid shot",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^rapid shot");
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat Rapid Shot has been removed from "
                    "your list as it is no longer in game.  You have been refunded a "
                    "free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "wild shape dragon": //revoking from non-hms if they had it before it was transferred.
            
            if(has_feat(ob,"wild shape dragon") && !high_mortalp(ob) && CONFIG_D->check_config("HM") == 0) {
              mytype = get_feat_type(ob,"wild shape dragon");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"wild shape dragon",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^wild shape dragon");
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat Wild Shape dragon has been removed from "
                    "your list as you are not a HM with access to it.  You have been refunded a "
                    "free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "hardenedminions": //revoking from those without the new pre-reqs.
            
            if(has_feat(ob,"hardenedminions") && !has_feat(ob,"spell power")) {
              mytype = get_feat_type(ob,"hardenedminions");
              if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
              remove_my_feat(ob,"hardenedminions",1);
              tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^hardenedminions");
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The feat Hardenedminions has been changed "
                    "to the spellpower tree and has new pre-requisites.  You may have been refunded a "
                    "free feat (if bought with levelling feats) to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "slippery caster": //removing upper magicprot tree

            removing_feats = ({ "slippery caster","tough skin","armoredtitan" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                mytype = get_feat_type(ob,removing_feats[j]);
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            // and since class feats can't be run through remove_my_feat:
            if(has_feat(ob,"thick skinned caster")) {
                mytype = get_feat_type(ob,"thick skinned caster");
                if(mytype == "class") {
                  remove_feat(ob,"class","thick skinned caster");
                  tell_object(ob,"%^YELLOW%^Removing class feat %^BLUE%^thick skinned caster");
                }
            }
            if(num > freebs) {
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The MagicProtection feats tree has been removed, "
                    "and the obsolete ones have been removed from your list.  You have been refunded "
                    "equivalent free feat/s to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "thick skinned caster": //had to add this as an extra for those who paid for the feat rather than got it free

            if(has_feat(ob,"thick skinned caster")) {
                mytype = get_feat_type(ob,"thick skinned caster");
                if(mytype == "class") continue; // let this be removed elsewhere (or just left alone, not hurting anything)
                if(mytype == "other") num ++;// this is used to keep track of how many they have removed so can gain them back for free
                remove_my_feat(ob,"thick skinned caster",1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            if(num > freebs) {
              tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The MagicProtection feats tree has been removed, "
                    "and since you had paid to buy 'thick skinned caster', you have been refunded an "
                    "equivalent free feat to spend that will cost you no experience points.  "
                    "Please type <feats allowed> for more information.%^RESET%^");
              ob->set("free_feats",num);
            }
            freebs = num;
            break;

        case "wild shape wolf":
            
            removing_feats = ({ "wild shape cat","wild shape large animal","wild shape bear","wild shape small animal","wild shape wolf" });
            for(j=0;j<sizeof(removing_feats);j++) {
                if(!has_feat(ob,removing_feats[j])) continue;
                remove_my_feat(ob,removing_feats[j],1);
                tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
            }
            tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^The class-based 'wild shape' feats have been marked "
                    "as obsolete and you have had the feats in that tree removed.  As these were all class "
                    "levelling feats, no free feats have been provided to replace them.  You may, however, "
                    "wish to <feats fix> as the druid class now has a new set of levelling feats.%^RESET%^");
            break;
            
        case "archmage":
        case "body cognition":
        case "chronicler":
        case "presence of mind":
        case "shadow adept":
        case "shadowdancer":
        case "versatile arcanist":
        case "wild shape dragon":
        case "wild shape elemental":
        
            removing_feats = ({ "archmage","body cognition","chronicler","presence of mind","shadow adept",
                    "shadowdancer", "versatile arcanist","wild shape dragon","wild shape elemental" });
            for(j=0;j<sizeof(removing_feats);j++) 
            {
                if(!has_feat(ob,removing_feats[j])) continue;
                
                feat_ob = find_object_or_load("/cmds/feats/"+removing_feats[j][0..0]+"/_"+replace_string(removing_feats[j]," ","_")+".c");
                if(objectp(feat_ob))
                {
                    if(feat_ob->is_obsolete() || !feat_ob->prerequisites(ob))
                    {
                        remove_my_feat(ob,removing_feats[j],1);
                        if(removing_feats[j] == "archmage")
                        {
                            tell_object(ob,"removing your spellmastery spell, please see an imm to get it added again.");
                            ob->delete("spellmastery_spell");
                        }
                        if(removing_feats[j] == "shadowdancer")
                        {
                            ob->InitInnate();                            
                        }                        
                        if(removing_feats[j] == "versatile arcanist")
                        {
                            if(ob->query("elementalist")) { ob->delete("elementalist"); }
                            myspells = (string *)ob->query_mastered_spells();
                            if(sizeof(myspells)) 
                            {
                                schoolspells = SCHOOLSPELLS;
                                for(i=0;i<sizeof(myspells);i++) 
                                {
                                    if(member_array(myspells[i],schoolspells) != -1) 
                                    {
                                        ob->remove_mastered_spell(myspells[i]);
                                    }
                                }
                            }
                        }

                        tell_object(ob,"%^YELLOW%^Removing feat %^BLUE%^"+removing_feats[j]+"");
                        num++;
                    }
                }
            }
            update_usable(ob);
            
            if(num > freebs) 
            {
                tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^Most of the epic feats have been removed and "
                    "converted into prestige classes instead.  Receiving free feats for epic feats that "
                    "you lost.%^RESET%^");
                ob->set("free_feats",num);
            }
            break;
 
        default:
            return;
        }
    }
    return;
}

void clear_usable_feats()
{
    __USABLE_FEATS = ([]);
    return;
}

int can_gain_feat(object ob,string feat)
{
    int MAX_ALLOWED;
    string type;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(has_feat(ob,feat)) { return 0; }
    if(!meets_requirements(ob,feat)) { return 0; }
    MAX_ALLOWED = ((int)ob->query_highest_level() / 3) + 1;
    if((int)ob->query_other_feats_gained() >= MAX_ALLOWED) { return 0; }
    return 1;
}

int can_gain_bonus_feat(object ob,string feat)
{
    int MAX_ALLOWED, i;
    string type, *myclasses, currentlvl;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(has_feat(ob,feat)) { return 0; }
    if(!meets_requirements(ob,feat)) { return 0; }
    myclasses = ob->query_classes();
    if(!sizeof(myclasses)) return 0;
    MAX_ALLOWED = 0;
    for(i=0;i<sizeof(myclasses);i++) {
      if(member_array(myclasses[i],CASTERCLASSES) != -1) continue; // caster classes get no bonus melee feats!
      if(member_array(myclasses[i],HYBRID) != -1) continue; // neither do hybrids!
      if(myclasses[i] == "fighter" || myclasses[i] == "paladin")
          currentlvl = (((int)ob->query_class_level(myclasses[i]) +4) / 5); 
      else
          currentlvl = (((int)ob->query_class_level(myclasses[i]) - 16) / 5); // melee classes @ L21 & every 5 levels thereafter
      if(currentlvl < 0) currentlvl = 0;
      MAX_ALLOWED += currentlvl;
    }
    if((int)ob->query_bonus_feats_gained() >= MAX_ALLOWED) { return 0; }
    return 1;
}

int can_gain_magic_feat(object ob,string feat)
{
    int MAX_ALLOWED, i;
    string type, *myclasses, currentlvl;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(has_feat(ob,feat)) { return 0; }
    if(!meets_requirements(ob,feat)) { return 0; }
    myclasses = ob->query_classes();
    if(!sizeof(myclasses)) return 0;
    MAX_ALLOWED = 0;
    for(i=0;i<sizeof(myclasses);i++) {
      if(member_array(myclasses[i],MELEECLASSES) != -1) continue; // melee classes get no bonus caster feats!
      if(member_array(myclasses[i],HYBRID) != -1) continue; // neither do hybrids!
      if(myclasses[i] == "psion" || myclasses[i] == "sorcerer")
          currentlvl = (((int)ob->query_class_level(myclasses[i]) +4) / 5);
      else
          currentlvl = (((int)ob->query_class_level(myclasses[i]) - 16) / 5);
      if(currentlvl < 0) currentlvl = 0;
      MAX_ALLOWED += currentlvl;
    }
    if((int)ob->query_magic_feats_gained() >= MAX_ALLOWED) { return 0; }
    return 1;
}

int can_gain_hybrid_feat(object ob,string feat){
    int MAX_ALLOWED, i, total;
    string type, *myclasses, currentlvl;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(has_feat(ob,feat)) { return 0; }
    if(!meets_requirements(ob,feat)) { return 0; }
    myclasses = ob->query_classes();
    if(!sizeof(myclasses)) return 0;
    MAX_ALLOWED = 0;
    for(i=0;i<sizeof(myclasses);i++) {
      if(member_array(myclasses[i],HYBRID) == -1) continue; 
      if(myclasses[i] == "psywarrior") currentlvl = ((int)ob->query_class_level(myclasses[i]) / 5); 
      else currentlvl = (((int)ob->query_class_level(myclasses[i]) - 16) / 5); // hybrid classes @ L21 & every 5 levels thereafter
      if(currentlvl < 0) currentlvl = 0;
      MAX_ALLOWED += currentlvl;
    }
    total = 0;
    total += (int)ob->query_hybrid_feats_gained();
    if(total >= MAX_ALLOWED) { return 0; }
    return 1;
}

mixed identify_hybrid() { return HYBRID; }

int add_my_feat(object ob,string type,string feat)
{
    int allowed,num,level,i,num_feats, mod;
    string *subset;
    if(!objectp(ob)) { return 0; }
    if(!stringp(type)) { return 0; }
    if(!stringp(feat)) { return 0; }

    level = (int)ob->query_other_feats_gained();
    if(!level) { level = 1; }
    else { level = level * 3; }

    switch(type)
    {
    case "class":
        if(gain_feat(ob,type,feat,(int)ob->query_character_level()))
        {
            num = (int)ob->query_class_feats_gained();
            if(!num) num = 0;
            num += 1;
            ob->set_class_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "bonus":
        subset = ob->query_classes(); // this is to get the current level to assign the feat to
        if(!sizeof(subset)) return 0;
        num = 0;
        for(i=0;i<sizeof(subset);i++) {
          if(member_array(subset[i],MELEECLASSES) == -1) num += ob->query_class_level(subset[i]);
          else {
            if(subset[i] != "fighter" && subset[i] != "paladin") {
              if(ob->query_class_level(subset[i]) > 20) num += 20;
              else num += ob->query_class_level(subset[i]);
            }
          }
        }
        num_feats = (((int)ob->query_bonus_feats_gained()+1)*5);
        num += num_feats;
        num -= 4; // to move feats back to 1/6/11/16/21/etc

        if(gain_feat(ob,type,feat,num))
        {
            num = 0;
            num = (int)ob->query_bonus_feats_gained();
            num += 1;
            ob->set_bonus_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "magic":
        subset = ob->query_classes(); // this is to get the current level to assign the feat to
        if(!sizeof(subset)) return 0;
        num = 0;
        for(i=0;i<sizeof(subset);i++) {
          if(member_array(subset[i],CASTERCLASSES) == -1) num += ob->query_class_level(subset[i]);
          else {
            if(subset[i] != "sorcerer" && subset[i] != "psion") {
              if(ob->query_class_level(subset[i]) > 20) num += 20;
              else num += ob->query_class_level(subset[i]);
            }
          }
        }
        num_feats = (((int)ob->query_magic_feats_gained()+1)*5);
        num += num_feats;
        num -= 4; // to move feats back to 1/6/11/16/21/etc

        if(gain_feat(ob,type,feat,num))
        {
            num = 0;
            num = (int)ob->query_magic_feats_gained();
            num += 1;
            ob->set_magic_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "hybrid": // please note - this needs a fix for the 1/7 progression for psywarriors. Currently running on 1/5. N, 9/15.
        subset = ob->query_classes();
        if(!sizeof(subset)) return 0;
        num = 0;
        for(i=0;i<sizeof(subset);i++) 
        {
            if(member_array(subset[i],HYBRID) == -1) num += ob->query_class_level(subset[i]);
            else 
            {
                if(subset[i] != "psywarrior") 
                {
                    if(ob->query_class_level(subset[i]) > 20) num += 20;
                    else num += ob->query_class_level(subset[i]);
                }
            }          
        }
        
        num_feats = (((int)ob->query_hybrid_feats_gained()+1)*5);
        num += num_feats;
        num -= 4; // to move feats back to 1/6/11/16/21/etc
        if(gain_feat(ob,type,feat,num))
        {
            num = 0;
            num = (int)ob->query_hybrid_feats_gained();
            num += 1;
            ob->set_hybrid_feats_gained(num);
            update_usable(ob);
            return 1;
        }
        else return 0;
    case "other":
        if(gain_feat(ob,type,feat,level)) 
        {
            num = (int)ob->query_other_feats_gained();
            if(!num) num = 0;
            num += 1;
            ob->set_other_feats_gained(num);
            if(get_category(feat) == "EpicFeats") { // to track
              num = (int)ob->query_epic_feats_gained();
              if(!num) num = 0;
              num += 1;
              ob->set_epic_feats_gained(num);
            }
            update_usable(ob);
            return 1;
        }
        else return 0;

    default: 
        return 0;
    }
    return 0;
}

int remove_my_feat(object ob,string feat,int bypass)
{
    string type;
    int num;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(!bypass && !can_remove_feat(ob,feat)) { return 0; }
    type = get_feat_type(ob,feat);
    if(type == "class") { return 0; }
    remove_feat(ob,type,feat);
    switch(type)
    {
    case "bonus":
        num = (int)ob->query_bonus_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_bonus_feats_gained(num);
        update_usable(ob);
        return 1;
    case "magic":
        num = (int)ob->query_magic_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_magic_feats_gained(num);
        update_usable(ob);
        return 1;
    case "hybrid":
        num = (int)ob->query_hybrid_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_hybrid_feats_gained(num);
        update_usable(ob);
        return 1;
    case "other":
        num = (int)ob->query_other_feats_gained();
        if(!num) num = 0;
        num -= 1;
        ob->set_other_feats_gained(num);
        if(get_category(feat) == "EpicFeats") { // to track
          num = (int)ob->query_epic_feats_gained();
          if(!num) num = 0;
          num -= 1;
          ob->set_epic_feats_gained(num);
        }
        update_usable(ob);
        return 1;
    }
    return 1;
}

int can_remove_feat(object ob,string feat)
{
    object myfeat;
    string *needed_feats,file,*player_feats, *replaced_by;
    int i;
    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(!has_feat(ob,feat)) { return 0; }
    if(member_array(feat,get_all_removable_feats(ob)) == -1) { return 0; }
    file = DIR_FEATS+"/"+feat[0..0]+"/_"+feat+".c";
    //if(find_player("saide")) tell_object(find_player("saide"), "file = "+file);
    file = replace_string(file," ","_");
    if(catch(myfeat = new(file))) { return 0; }    
    if(!objectp(myfeat)) { return 0; }
    needed_feats = myfeat->query_required_for();
    replaced_by = myfeat->query_replaced_by();
    destruct(myfeat);

    player_feats = (string *)ob->query_player_feats();
    if(pointerp(replaced_by) && sizeof(replaced_by)) { if(sizeof(player_feats - replaced_by) != sizeof(player_feats)) return 1; }
    if(pointerp(player_feats) && sizeof(player_feats))
    {
        for(i=0;i<sizeof(player_feats);i++)
        {
            if(player_feats[i] == feat) { continue; }
            
            if(member_array(player_feats[i],needed_feats) != -1) 
            { 
                
                return 0;
            }
        }
    }
    return 1;
}

string *get_all_removable_feats(object ob)
{
    string *feats,*cls_feats=({}),*classes,file,myspec;
    int i;

    if(!objectp(ob)) { return ({}); }
    classes = ob->query_classes();
    for(i=0;i<sizeof(classes);i++)
    {
        myspec = ob->query_combat_spec(classes[i]);
        file = DIR_CLASSES+"/"+classes[i]+".c";
        cls_feats += class_feat_array(classes[i],myspec);
    }
    feats = (string *)ob->query_player_feats();
    feats -= cls_feats;
    return feats;
}

void update_usable(object ob)
{
    __USABLE_FEATS[ob->query_name()] = ({});
    return;
}

mixed get_usable(object ob)
{
    if(__USABLE_FEATS[ob->query_name()]) return __USABLE_FEATS[ob->query_name()];
}

// gain_feat(player,(class bonus other), feat, level
varargs int gain_feat(object ob, string type, string feat,int level)
{
    if(!objectp(ob))   { return 0; }
    if(!stringp(type)) { return 0; }
    if(!stringp(feat)) { return 0; }
    
    if(has_feat(ob,feat))            { return 0; }
    
    if(!meets_requirements(ob,feat)) 
    { 
        tell_object(ob,"You do not meet the prerequisites for the "
            "feat "+feat+".");
        return 0; 
    }
    if(get_category(feat) == "EpicFeats" && (int)ob->query_epic_feats_gained() > 0) {
        tell_object(ob,"You have already bought one epic feat, you can't buy another.");
        return 0; 
    }
    if(member_array(type,({"class","bonus","magic","other","hybrid"})) == -1) { return 0; }

    add_feat(ob,type,feat,level);

    return 1;
}

int meets_requirements(object ob, string feat)
{
    object obj;
    string file;
    if(!objectp(ob))                { return 0; }
    if(!stringp(feat))              { return 0; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))          { return 0; }
    if(catch(obj = new(file)))      { return 0; }
    if(!obj->prerequisites(ob))    { return 0; }
    obj->dest_effect();
    if(objectp(obj)) obj->remove();
    return 1;
}

int display_meets_requirements(string feat, object ob)
{
	int x;
	if(!objectp(ob)) return 0;
	if(!stringp(feat)) return 0;
	return meets_requirements(ob, feat);
}

int filter_feats(object ob, string feat)
{
    object obj;
    string file;
    if(!objectp(ob))                { return 0; }
    if(!stringp(feat))              { return 0; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))          { return 0; }
    if(catch(obj = new(file)))      { return 0; }
//    if(!obj->prerequisites(ob))    { return 0; }
    obj->dest_effect();
    if(objectp(obj)) obj->remove();
    return 1;
}

int display_filtered_feats(string feat, object ob)
{
      int x;
	if(!objectp(ob)) return 0;
	if(!stringp(feat)) return 0;
	return filter_feats(ob, feat);
}

int is_temporary(object ob,string feat)
{
    string *tmp_feats = ({});

    if(!objectp(ob)) { return 0; }
    if(!stringp(feat)) { return 0; }
    if(!is_feat(feat)) { return 0; }

    tmp_feats = (string*)ob->query_temporary_feats();

    if(member_array(feat,tmp_feats) == -1) { return 0; }

    if(!has_feat(ob,feat)) { return 1; }

    ob->clear_temporary_feats();

    if(!usable_feat(ob,feat)) { return 1; }

    ob->set_temporary_feats(tmp_feats);

    return 0;
}

int is_active(object ob,string feat)
{
    object *feats;
    string *names=({}),name;
    int i;

    if(!objectp(ob))                    { return 0; }
    if(!stringp(feat))                  { return 0; }
    if(!has_feat(ob,feat))              { return 0; }
    feats = (object *)ob->query_property("active_feats");
    if(!pointerp(feats))                { return 0; }
    if(!sizeof(feats))                  { return 0; }
    for(i=0;i<sizeof(feats);i++)
    {
        if(!objectp(feats[i])) { continue; }
        names += ({ (string)feats[i]->query_feat_name() });
    }        
    if(member_array(feat,names) == -1)  { return 0; }
    return 1;
}

void reverse_permanent_feat(object ob,string feat)
{
    string file;
    int i;

    if(!objectp(ob))            { return; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))      { return; }
    if(!is_permanent(ob,feat))  { return; }
    file->reverse_permanent_effects(ob);
    file->dest_effect();
    return;
}

void execute_permanent_feat(object ob,string feat)
{
    string file;
    int i;

    if(!objectp(ob))            { return; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file_exists(file))      { return; }
    if(!is_permanent(ob,feat))  { return; }
    file->permanent_effects(ob);
    file->dest_effect();
    return;
}

int is_permanent(object ob,string feat)
{
    string file;
    if(!objectp(ob))                { return 0; }
    if(!stringp(feat))              { return 0; }
    file = FEAT_FILE + feat[0..0]+"/_"+feat+".c";
    file = replace_string(file," ","_");
    if(!file->is_permanent_feat())  { return 0; }
    file->dest_effect();
    return 1;
}

int can_use_feat(object ob,string feat)
{
    if(!objectp(ob))                    { return 0; }
    if(!stringp(feat))                  { return 0; }
    if(is_temporary(ob,feat))           { return 1; }
    if(!meets_requirements(ob,feat))    { return 0; }
    return 1;
}

int usable_feat(object ob,string feat)
{
    string *tmp,*feats;
    int i;
    
    if(!objectp(ob))                    { return 0; }
    if(!stringp(feat))                  { return 0; }
    if(!interactive(ob))                
    { 
        tmp = (string *)ob->query_monster_feats();
        if(!sizeof(tmp)) { return 0; }
        if(member_array(feat,tmp) == -1) { return 0; }
        else { return 1; }
    }
    if(!ob->query("new_class_type"))    { return 0; }
    
    feats = (string*)ob->query_temporary_feats();
    if(sizeof(feats)) 
    { 
        if(member_array(feat,feats) != -1) { return 1; } 
    }

    if(!avatarp(ob))
    {
        if(pointerp(__USABLE_FEATS[ob->query_name()]))
        {
            if(member_array(feat,__USABLE_FEATS[ob->query_name()]) != -1) { return 1; }
        }
    }

    if(avatarp(ob) && !ob->query("persona") && !ob->query("testing"))  { return 1; }
    if(!interactive(ob))                { return 1; }
    if(!has_feat(ob,feat))              { return 0; }
    if(!can_use_shifted(ob,feat))       { return 0; }
    if(!can_use_feat(ob,feat))          { return 0; }
    if(!level_to_use(ob,feat))          { return 0; }

    if(!mapp(__USABLE_FEATS)) { __USABLE_FEATS = ([]); }
    if(!pointerp(__USABLE_FEATS[ob->query_name()])) { __USABLE_FEATS[ob->query_name()] = ({}); }
    __USABLE_FEATS[ob->query_name()] += ({ feat });

    return 1;
}

int level_to_use(object ob,string feat)
{
    mapping player;
    int feat_level,player_level;

    if(!objectp(ob))        { return 0; }
    if(!stringp(feat))      { return 0; }
    if(!has_feat(ob,feat))  { return 0; }
    
    player       = player_data(ob);
    player_level = player["level"];
    feat_level   = level_of_feat(ob,feat);
    if(feat_level == -1)    { return 0; }
    if(feat_level > player_level) { return 0; }
    return 1;
}

int can_use_shifted(object ob, string feat)
{
    string file;
    object myfeat;

    if(!objectp(ob)) { return 0; }
    if(!has_feat(ob,feat)) { return 0; }

    if(!ob->query_property("shapeshifted")) { return 1; } // not shifted, don't bother to check

    file = DIR_FEATS+"/"+feat[0..0]+"/_"+feat+".c";
    //if(find_player("saide")) tell_object(find_player("saide"), "file = "+file);
    file = replace_string(file," ","_");
    if(catch(myfeat = new(file))) { return 0; }
    if(!objectp(myfeat)) { return 0; }

    if(!myfeat->allow_shifted()) 
    {
        destruct(myfeat);
        return 0; 
    }
    else 
    {
        destruct(myfeat);
        return 1; 
    }
}

int level_of_feat(object ob,string feat)
{
    mapping feats;
    string type,*tmp;
    int *levels,level,i;

    if(!objectp(ob))          { return -1; }
    if(!stringp(feat))        { return -1; }
    if(is_temporary(ob,feat)) { return (int)ob->query_character_level(); }
    if(!has_feat(ob,feat))    { return -1; }
    type   = get_feat_type(ob,feat);
    feats  = get_feats(ob,type);
    levels = keys(feats);
    if(!pointerp(levels))     { return -1; }
    if(!sizeof(levels))       { return -1; }
    for(i=0;i<sizeof(levels);i++)
    {
        tmp = feats[levels[i]];
        if(!pointerp(tmp)) { continue; }
        if(member_array(feat,tmp) == -1) { continue; }
        level = levels[i];
        return level;
    }

}

int has_feat(object ob, string feat)
{
    string *feats;
    if(!objectp(ob))                    { return 0; }
    if(!stringp(feat))                  { return 0; }
    if(!is_feat(feat))                  { return 0; }
    if(interactive(ob))
    {
        feats = ob->query_player_feats();
    }
    else
    {
        feats = ob->query_monster_feats();
    }
    if(!pointerp(feats))                { return 0; }
    if(!sizeof(feats))                  { return 0; }
    if(member_array(feat,feats) == -1)  { return 0; }        
    return 1;
}

int is_feat(string feat)
{
    mapping tmp;
    string *feats=({}),*cats,*hold;
    int i,j;

    tmp = get_all_feats();
    if(!mapp(tmp))      { return 0; }
    //this should be doing the same thing - but hopefully will cut down on 
    //processing time and too long evaluation errors - Saide April 2016
    cats = values(tmp);
    if(!pointerp(cats)) { return 0; }
    for(i=0;i<sizeof(cats);i++)
    {
        if(member_array(feat, cats[i]) != -1) { return 1; }
        continue;
    }
    return 0;
    
    /*cats = keys(tmp);
    if(!sizeof(cats))   { return 0; }
    for(i=0;i<sizeof(cats);i++)
    {
        hold = tmp[cats[i]];
        if(!pointerp(hold)) { continue; }
        if(!sizeof(hold))   { continue; }
        for(j=0;j<sizeof(hold);j++)
        {
            feats += ({ hold[j] });
        }
    }
    if(member_array(feat,feats) == -1) { return 0; }
    return 1;*/
}

string get_feat_type(object ob,string feat)
{
    mapping feats;
    string type,*tmp,*types;
    int i,j;
    
    if(!objectp(ob))        { return 0; }
    if(!stringp(feat))      { return 0; }
    if(!has_feat(ob,feat))  { return 0; }
    if(!is_feat(feat))      { return 0; }
    tmp = ({ "class","bonus","magic","other","hybrid" });
    for(i=0;i<sizeof(tmp);i++)
    {
        feats = get_feats(ob,tmp[i]);
        types  = keys(feats);
        if(!sizeof(types)) { continue; }
        for(j=0;j<sizeof(types);j++)
        {
            if(!pointerp(feats[types[j]])) { continue; }
            if(member_array(feat,feats[types[j]]) != -1) { return tmp[i]; }
        }
    }
    return 0;
}

void remove_feat(object ob,string type, string feat)
{
    mapping feats;
    int *levels,i,level;
    string *tmp;

    if(!objectp(ob))        { return; }
    if(!stringp(type))      { return; }
    if(!stringp(feat))      { return; }
    if(!is_feat(feat))      { return; }
    if(!has_feat(ob,feat))  { return; }

    feats = get_feats(ob,type);
    levels = keys(feats);
    level = -1;
    if(!sizeof(levels))     { return; }
    for(i=0;i<sizeof(levels) && level == -1;i++)
    {
        tmp = feats[levels[i]];
        if(member_array(feat,tmp) != -1)
        {
            level = levels[i];
        }
    }
    tmp -= ({ feat });
    feats[level] = tmp;
    if(is_permanent(ob,feat)) { reverse_permanent_feat(ob,feat); }
    set_feats(ob,type,feats);        
    //redundant since query_player_feat works entirely differently now - Saide
    //take_feat(ob,feat);
    return;
}

varargs void add_feat(object ob, string type, string feat,int level)
{
    mapping feats,player;
    int num;
    if(!objectp(ob))        { return; }
    if(!stringp(type))      { return; }
    if(!stringp(feat))      { return; }
    if(!is_feat(feat))      { return; }
    if(has_feat(ob,feat))   { return; }
    
    feats  = get_feats(ob,type);
    player = player_data(ob);
    if(level) { num = level; }
    else { num = player["level"]; }
    if(!pointerp(feats[num])) { feats[num] = ({ feat }); }
    else { feats[num] += ({ feat }); }
    if(is_permanent(ob,feat)) { execute_permanent_feat(ob,feat); }
    set_feats(ob,type,feats);
    //the following is redundant because of the way query_player_feats() now works - Saide
    //give_feat(ob,feat);
    return;
}

void give_feat(object ob,string feat)
{
    string *feats;
    if(!objectp(ob))    { return; }
    if(!stringp(feat))  { return; }
    feats = ob->query_player_feats();
    feats += ({ feat });
    ob->set_player_feats(feats);
    return;
}

void take_feat(object ob,string feat)
{
    string *feats;
    if(!objectp(ob))    { return; }
    if(!stringp(feat))  { return; }
    feats = ob->query_player_feats(); 
    feats -= ({ feat });
    ob->set_player_feats(feats);
    return;
}

void set_feats(object ob,string type,mapping feats)
{
    if(!objectp(ob))    { return; }
    if(!stringp(type))  { return; }
    if(!mapp(feats))    { return; }
    
    switch(type)
    {
    case "class":
        ob->set_class_feats(feats);
        break;
    case "bonus":
        ob->set_bonus_feats(feats);
        break;
    case "magic":
        ob->set_magic_feats(feats);
        break;
    case "hybrid":
        ob->set_hybrid_feats(feats);
        break;
    case "other":
        ob->set_other_feats(feats);
        break;
    }
    return;
}

mapping get_feats(object ob,string type)
{
    mapping feats;
    if(!objectp(ob)) { return ([]); }
    switch(type)
    {
    case "class":
        feats = ob->query_class_feats();
        break;
    case "bonus":
        feats = ob->query_bonus_feats();
        break;
    case "magic":
        feats = ob->query_magic_feats();
        break;
    case "hybrid":
        feats = ob->query_hybrid_feats();
        break;
    case "other":
        feats = ob->query_other_feats();
        break;
    }
    if(!mapp(feats)) 
    { 
        ob->init_feats();
        return ([]); 
    }
    return feats;
}




// expand this if I need it
mapping player_data(object ob)
{
    mapping data;
    data = ([ "level" : (int)ob->query_highest_level(), ]);
    return data;
}

int calculate_psionic_feats(object ob){
   string file, *featies=({});
   object tmp;
   int i, num=0;
   if(!objectp(ob)){ return 0; }
   featies += ob->query_player_feats();
   if(!sizeof(featies)){ return 0; }
   for(i=0;i<sizeof(featies);i++){
      if(!FEATS_D->is_feat(featies[i])) continue;
      file = DIR_FEATS+"/"+featies[i][0..0]+"/_"+featies[i]+".c";
      file = replace_string(file," ","_");
      if(!file_exists(file)) continue;
      if(catch(tmp = new(file))) continue;
      if(tmp->is_psionic_feat()) num++;
      if(objectp(tmp)) tmp->remove();
   }
   return num;
}

void create() 
{ 
    ::create(); 
    __ALL_FEATS = ([]);
    __USABLE_FEATS = ([]);
    build_feat_list();
}

void build_feat_list()
{
    string *folders=({}),category,name,file, *files = ({});
    mapping feats=([]);
    int i, y;

    folders = get_dir(FEAT_FILE);
    if(!sizeof(folders)) 
    {
        call_out("create",5); // An attempt to make the feat daemon kickstart itself if none of the feats load -Ares
        return; 
    }    
    for(i=0;i<sizeof(folders);i++)
    {
        files = get_dir(FEAT_FILE + folders[i] + "/");
        for(y = 0; y < sizeof(files); y++)
        {              
        // hopefully prevent backups an anything not ending in .c from bugging the daemon
            if(strsrch(files[y],".c") != (strlen(files[y]) - 2)) { continue; }
            //tell_object(find_player("saide"), "files[y] = "+files[y]);
            //continue;
        
            file     = FEAT_FILE + "" + folders[i] + "/" + files[y]+"";
            file     = replace_string(file," ","_");
            category = file->query_feat_category();
            name     = file->query_feat_name();
            file->dest_effect();
            if(!pointerp(feats[category])) { feats[category] = ({ name }); }
            else feats[category] += ({ name });
        }
    }
    __ALL_FEATS = feats;
    return;
}

string get_category(string featname)
{
    string category,name,file;

    file = FEAT_FILE + featname[0..0]+"/_"+featname+".c";
    file     = replace_string(file," ","_");
    if(!file_exists(file)) return "NIL";
    category = file->query_feat_category();
    name     = file->query_feat_name();
    file->dest_effect();
    if(category != "") return category;
    return name;
}

mapping get_all_feats()
{
    if(!mapp(__ALL_FEATS) || __ALL_FEATS == ([]))
    {
        build_feat_list();
    }
    return __ALL_FEATS;
}

////////////////////////////////////////////////
//  Display related stuff  /////////////////////
////////////////////////////////////////////////

string format_category(string cat)
{
    string *tmp,display;
    int i;

    tmp = explode(cat," ");
    
    tmp[0] = capitalize(tmp[0]);
    tmp[0] = "%^RESET%^%^MAGENTA%^"+tmp[0]+"%^RESET%^";
    display = "\n"+IDT+arrange_string(tmp[0],(ALIGN_SPACER -1));
    
    if(sizeof(tmp) == 2)
    {
        tmp[1] = capitalize(tmp[1]);
        tmp[1] = "%^RESET%^%^MAGENTA%^"+tmp[1]+"%^RESET%^";
        display += arrange_string(tmp[1],(ALIGN_SPACER-5));
    }
    return display;
}

string pick_color(string feat,object targ)
{
    int has,active,level_check,permanent,temporary;

    has         = has_feat(targ,lower_case(feat));
    active      = is_active(targ,lower_case(feat));
    level_check = usable_feat(targ,lower_case(feat));
    permanent   = is_permanent(targ,lower_case(feat));
    temporary   = is_temporary(targ,lower_case(feat));

    if(temporary)    { return "%^BOLD%^%^BLUE%^"; }
    if(!has)         { return "%^BOLD%^%^WHITE%^"; }
    if(!level_check) { return "%^RED%^"; }
    if(permanent)    { return "%^BOLD%^%^GREEN%^"; }
    if(active)       { return "%^YELLOW%^"; }

    return "%^BOLD%^%^CYAN%^";
}


//%^B_BLUE%^%^BOLD%^%^GREEN%^Retaining the below code so it can be restored if needed. Adjusting similar code below to address lack of colors%^RESET%^
string format_feat(string feat,object targ) {
    int level,level_check;
    string display,tmp;

    feat        = capitalize(feat);
    level_check = can_use_feat(targ,lower_case(feat));
    level       = level_of_feat(targ,lower_case(feat));
    if(!level || level == -1) tmp = "%^RESET%^--";
    else if(!level_check) tmp = "%^BOLD%^%^RED%^"+level+"%^RESET%^";
    else if(bought_as_class_feat(feat,targ)) tmp = "%^BOLD%^%^MAGENTA%^"+level+"%^RESET%^";
    else if(bought_as_bonus_feat(feat,targ)) tmp = "%^BOLD%^%^YELLOW%^"+level+"%^RESET%^";
    else if(bought_as_magic_feat(feat,targ)) tmp = "%^BOLD%^%^YELLOW%^"+level+"%^RESET%^";
    else if(bought_as_hybrid_feat(feat,targ)) tmp = "%^BOLD%^%^YELLOW%^"+level+"%^RESET%^";
    else tmp = "%^CYAN%^"+level+"%^RESET%^";
    if(level && level < 10 && level != -1) tmp = " "+tmp+"";

    if(feat == "")
        display = arrange_string(" ",LEVEL_SPACER)+arrange_string(" ",FEAT_SPACER);
    else {    
        display = arrange_string("%^RESET%^%^BOLD%^  "+tmp+"%^RESET%^",LEVEL_SPACER);
        //display += arrange_string(""+feat+"",FEAT_SPACER)+"%^RESET%^";
        display += arrange_string(""+pick_color(feat,targ)+feat+"",FEAT_SPACER)+"%^RESET%^";
    }
    return display;
}

/*
string format_feat(string feat,object targ) {
    int level,level_check;
    string display,tmp;

    feat        = capitalize(feat);
    level_check = can_use_feat(targ,lower_case(feat));
    level       = level_of_feat(targ,lower_case(feat));
    if(!level || level == -1) tmp = "%^RESET%^--";
    else if(!level_check) tmp = "%^BOLD%^%^RED%^"+level+"";
    else if(bought_as_class_feat(feat,targ)) tmp = "%^BOLD%^%^MAGENTA%^"+level+"%^GREEN%^";
    else if(bought_as_bonus_feat(feat,targ)) tmp = "%^BOLD%^%^YELLOW%^"+level+"%^GREEN%^";
    else if(bought_as_magic_feat(feat,targ)) tmp = "%^BOLD%^%^YELLOW%^"+level+"%^GREEN%^";
    else if(bought_as_hybrid_feat(feat,targ)) tmp = "%^BOLD%^%^YELLOW%^"+level+"%^GREEN%^";
    else tmp = "%^BOLD%^%^CYAN%^"+level+"%^GREEN%^";
    if(level && level < 10 && level != -1) tmp = " "+tmp+"";

    if(feat == "")
        display = arrange_string(" ",LEVEL_SPACER)+arrange_string(" ",FEAT_SPACER);
    else {    
        display = arrange_string("%^RESET%^%^BOLD%^  "+tmp+"",LEVEL_SPACER);
        //display += arrange_string(""+feat+"",FEAT_SPACER)+"%^RESET%^";
        display += arrange_string(pick_color(feat,targ)+feat+"",FEAT_SPACER)+"%^RESET%^";
    }
    return display;
}*/


string *format_feats(string *left,string *right,object targ)
{
    string *final=({}),display,left_feat,right_feat;
    int VERT_SPACER,i;
    if(sizeof(left) > sizeof(right)) { VERT_SPACER = sizeof(left); }
    else                             { VERT_SPACER = sizeof(right); }

    for(i=0;i<VERT_SPACER;i++)
    {
        if(i<sizeof(left))
        {
            left_feat = IDT+format_feat(left[i],targ);
        }
        else
        {
            left_feat = ""+IDT+format_feat("",targ)+"";
        }
        if(i<sizeof(right))
        {
            right_feat = format_feat(right[i],targ);            
        }
        else
        {
            right_feat = ""+format_feat("",targ)+"";
        }
        display = left_feat + right_feat;
        final += ({ display });
    }
    return final;
}

int is_feat_obsolete(string feat)
{
    object obj;
    string str;

    str = "/cmds/feats/"+feat[0..0]+"/_";
    //tell_object(find_player("saide"), "str = "+str);
    feat = replace_string(feat," ","_");
    str = str + feat +".c";
    if(!objectp(obj=find_object_or_load(str))) { return 0; }
    if(obj->is_obsolete()) { return 1; }
    return 0;
}    

// Designed to dynamically update itself when we add new categories and feats, so we don't have
// to mess with it again.  -Ares
void display_feats(object ob,object targ, string mytype)
{
    int i,j,tmp,tmp2;
    string *categories,*left_cats=({}),*right_cats=({}),*left_column,*right_column,display_cat,*display_feats,*classes,targ_class;
    string *display = ({}),*temp=({}),*good=({}),*currentlist=({}),*badcategories=({});
    mapping feats=([]),temp_feats=([]);
    object class_ob;

    temp_feats = get_all_feats();
    categories = keys(temp_feats);
    if(!mytype || mytype == "") mytype = "all";
    switch(mytype) {
      case "magic": currentlist += SPELLFEATS; break;
      case "melee": currentlist += MELEEFEATS; break;
      case "hybrid": currentlist += SPELLFEATS; currentlist += MELEEFEATS;  break;
      case "general": currentlist += GENERALFEATS; break;
      case "epic": currentlist += EPICFEATS; break;
      case "prestige": currentlist += PRESTIGE_FEATS; break;
      case "custom":
        if(sizeof(targ->query("custom_feat_array"))) currentlist += targ->query("custom_feat_array"); break;
      case "all": case "allowed": currentlist += SPELLFEATS; currentlist += MELEEFEATS; currentlist += GENERALFEATS; currentlist += EPICFEATS; currentlist += PRESTIGE_FEATS; break;
      default: currentlist += SPELLFEATS; currentlist += MELEEFEATS; currentlist += GENERALFEATS; currentlist += EPICFEATS; currentlist += PRESTIGE_FEATS; break;
    }

    if(!targ->is_class("bard") && !avatarp(targ)) { currentlist -= ({ "Performance" }); }
    if(!targ->is_class("druid") && !avatarp(targ)) { currentlist -= ({ "WildernessLore" }); currentlist -= ({ "SavageCombat" }); }
    if(!targ->is_class("psion") && !targ->is_class("psywarrior") && !avatarp(targ)) { currentlist -= ({ "Psionics" }); }
    if(!targ->is_class("fighter") && !targ->is_class("cavalier") && !targ->is_class("paladin") && !targ->is_class("antipaladin") && !avatarp(targ)) { currentlist -= ({ "WeaponMastery" }); }
    if(!high_mortalp(targ) && !avatarp(targ) && CONFIG_D->check_config("HM") == 0) { currentlist -= ({ "EpicFeats" }); }
    
    classes = targ->query_classes();
    for(i=0;i<sizeof(PRESTIGE_FEATS);i++)
    {
        targ_class = PRESTIGE_MAP[PRESTIGE_FEATS[i]];
        if(member_array(targ_class,classes) != -1) { continue; }
        if(avatarp(targ)) { continue; }
        currentlist -= ({ PRESTIGE_FEATS[i] });
    }
    

    for(i=0;i<sizeof(categories);i++)
    {
        if(member_array(categories[i],currentlist) != -1) {
          temp = temp_feats[categories[i]];
	    //added by saide to allow a player to get only 
	    //a list of feats they are allowed to take 
	    if(mytype == "allowed")
	    {
	    	  temp = filter_array(temp, "display_meets_requirements", TO, targ);
	    }
          good = ({});
          for(j=0;j<sizeof(temp);j++) {
              if(is_feat_obsolete(temp[j])) { continue; }
              good += ({ temp[j] });
          }
	    if(sizeof(good))
	    {
	        feats[categories[i]] = good;
	        continue;
          }
	    else badcategories += ({ categories[i] });
	    continue;
        }
        else badcategories += ({ categories[i] });
    }
    if(sizeof(badcategories)) categories -= badcategories;

    if(!objectp(ob))   { return; }
    if(!objectp(targ)) { return; }

    for(i=0;i<sizeof(categories);i++)
    {
        left_cats += ({ categories[i] });
        tmp = i + 1;
        if(tmp<sizeof(categories))
        {
            right_cats += ({ categories[tmp] });
            i++;
        }
    }    

    tell_object(ob,FEAT_HEADER);

    for(i=0;i<sizeof(left_cats);i++)
    {
        left_column = feats[left_cats[i]];
        display_cat = left_cats[i];
        
        if(i<sizeof(right_cats))
        {
            right_column = feats[right_cats[i]];
            display_cat += " "+right_cats[i];
        }
        else { right_column = ({}); }

        display_feats = format_feats(left_column,right_column,targ);
        display_cat = format_category(display_cat);
        display += ({ display_cat });
        for(j=0;j<sizeof(display_feats);j++)
        {
            display += ({ display_feats[j] });
        }
    }
    display += ({ FEAT_FOOTER });
    ob->more(display);
    return;
}

////////////////////////////////////////////////
//  End Display related stuff  /////////////////
////////////////////////////////////////////////

string *class_feat_array(string myclass,string spec) {
    string file, *feat_array;
    mapping cls_feats;
    int *featkeys, i;

    if(!myclass) return 0;
    file = DIR_CLASSES+"/"+myclass+".c";
    if(!file_exists(file)) return 0;
    cls_feats = file->class_featmap(spec);
    if(!mapp(cls_feats)) return 0;
    featkeys = keys(cls_feats);
    if(!sizeof(featkeys)) return 0;

    feat_array = ({});
    for(i=0;i<sizeof(featkeys);i++) {
      feat_array += cls_feats[featkeys[i]];
    }
    return feat_array;
}

int bought_as_class_feat(string feat,object targ) {
    string *feat_array;
    mapping class_feats;
    int *featkeys, i;

    feat = lower_case(feat);
    if(!has_feat(targ,feat)) return 0;
    class_feats = targ->query_class_feats();
    if(!mapp(class_feats)) return 0;
    featkeys = keys(class_feats);
    if(!sizeof(featkeys)) return 0;

    feat_array = ({});
    for(i=0;i<sizeof(featkeys);i++) feat_array += class_feats[featkeys[i]];
    if(!sizeof(feat_array)) return 0;
    if(member_array(feat,feat_array) == -1) return 0;
    return 1;
}

int bought_as_bonus_feat(string feat,object targ) {
    string *feat_array;
    mapping bonus_feats;
    int *featkeys, i;

    feat = lower_case(feat);
    if(!has_feat(targ,feat)) return 0;
    bonus_feats = targ->query_bonus_feats();
    if(!mapp(bonus_feats)) return 0;
    featkeys = keys(bonus_feats);
    if(!sizeof(featkeys)) return 0;

    feat_array = ({});
    for(i=0;i<sizeof(featkeys);i++) feat_array += bonus_feats[featkeys[i]];
    if(!sizeof(feat_array)) return 0;
    if(member_array(feat,feat_array) == -1) return 0;
    return 1;
}

int bought_as_magic_feat(string feat,object targ) {
    string *feat_array;
    mapping magic_feats;
    int *featkeys, i;

    feat = lower_case(feat);
    if(!has_feat(targ,feat)) return 0;
    magic_feats = targ->query_magic_feats();
    if(!mapp(magic_feats)) return 0;
    featkeys = keys(magic_feats);
    if(!sizeof(featkeys)) return 0;

    feat_array = ({});
    for(i=0;i<sizeof(featkeys);i++) feat_array += magic_feats[featkeys[i]];
    if(!sizeof(feat_array)) return 0;
    if(member_array(feat,feat_array) == -1) return 0;
    return 1;
}

int bought_as_hybrid_feat(string feat,object targ) {
    string *feat_array;
    mapping hybrid_feats;
    int *featkeys, i;

    feat = lower_case(feat);
    if(!has_feat(targ,feat)) return 0;
    hybrid_feats = copy(targ->query_hybrid_feats());
    if(!mapp(hybrid_feats)) return 0;
    featkeys = keys(hybrid_feats);
    if(!sizeof(featkeys)) return 0;

    feat_array = ({});
    for(i=0;i<sizeof(featkeys);i++) feat_array += hybrid_feats[featkeys[i]];
    if(!sizeof(feat_array)) return 0;
    if(member_array(feat,feat_array) == -1) return 0;
    return 1;
}
