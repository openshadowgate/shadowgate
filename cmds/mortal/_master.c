// _master.c
// SC mage spell progression, allowing them to "learn" one spell per spell level. Nienne, Feb 2009.
// Added sorcs to support spells-known framework, since sorc/mage can't multi. N, 5/11.
// Added psywarriors ~Circe~ 9/20/15

#include <std.h>
#include <magic.h>
#include <daemons.h>
#include <psions.h>
#include <master_limits.h>
#include <spellsbylevel.h>
#include <schoolspells.h>
#include <powersbylevel.h>
#include <disciplinespells.h>
#include <invocations.h>
inherit DAEMON;

string mydisc;
mapping powersbydiscipline;
string first,second,currentmsg,thespell,filename,filename2,buggy_spell,*spellsknown,*holder,*schoolspells;
object ob;
int *available,i,j,thelvl,spelllevel,spelllevel2,mylvl,myint,runtally,master_flag;
mapping sorcmap,holder2,pwmap;

int mage_master(string str)
{
    if(!str) 
    {
        available = ({});
        available += TP->query_masterable_spells();
        if(member_array(42,available) != -1) available -= ({42});
        if(!sizeof(available)) 
        {
            tell_object(TP,"You have learnt all the spells you are able to master.");
            return 1;
        }
        currentmsg = "";
        for(i = 0;i< sizeof(available);i++) 
            currentmsg +=" "+available[i];

        tell_object(TP,"You may still master one spell from each of the following levels: "+currentmsg+"");
        return 1;
    }
    if(str == "list") 
    {
        spellsknown = ({});
        spellsknown += TP->query_base_mastered_spells();
        if(!sizeof(spellsknown)) {
            tell_object(TP,"You haven't yet mastered any spells.");
            return 1;
        }
        currentmsg = spellsknown[0];
        if(sizeof(spellsknown) > 1) {
            for(i = 1;i< sizeof(spellsknown);i++) {
                currentmsg = currentmsg+", "+spellsknown[i]+"";
            }
        }
        tell_object(TP,"You have already mastered: "+currentmsg+".");
        return 1;
    }
    if(sscanf(str,"level %d",thelvl) == 1) 
    {
        holder = ({});
        holder+=keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"mage"),
                (:$2==$3:),thelvl));       
        if(!sizeof(holder))
            return notify_fail("There are no spells at level "+thelvl+" to master.");
        currentmsg = holder[0];
        if(sizeof(holder) > 1) 
            for(i = 1;i< sizeof(holder);i++) 
                currentmsg += ", "+holder[i];
        tell_object(TP,"Available spells for level "+thelvl+": "+currentmsg+".");
        return 1;
    }
    available = ({});
    available += TP->query_masterable_spells();
    spellsknown = ({});
    spellsknown += TP->query_mastered_spells();
    if(member_array(MAGIC_D->query_index("mage")[str],available) == -1) {
        tell_object(TP,"This spell is not available");
        return 1;
    }
    if(member_array(str,spellsknown) != -1) { // should never see this
        tell_object(TP,"You have already mastered this spell!");
        return 1;
    }
    holder = ({});
    holder+=keys(
            MAGIC_D->index_spells_for_player(TP,"mage"));
    if(member_array(str,holder) == -1) {
        tell_object(TP,"This is not a common spell that you can master.");
        return 1;
    }
    mylvl = TP->query_level();
    myint = TP->query_stats("intelligence");
    spelllevel = (int)MAGIC_D->query_index("mage")[str];
    if(WIZ_CALCS->query_spell_limit(MAGIC_D->query_index("mage")[str],mylvl,"mage",myint)) {
        TP->remove_masterable(spelllevel);
        TP->add_mastered_spell(str);
        tell_object(TP,"Through your studies, you have just mastered "+str+"!");
        return 1;
    }
    tell_object(TP,"You haven't yet learnt enough to master "+str+"!");
    return 1;
    tell_object(TP,"No such spell exists. Please see <help master>.");
    return 1;
}

int sorcerer_master(string str)
{
    int knownbonus;
     mylvl = TP->query_prestige_level("sorcerer");
     if(mylvl < 1) {
       tell_object(TP,"You have no sorcerer level! Please contact a wiz.");
       return 1;
     }
     if(mylvl > 50) mylvl = 50;
     available = SORCKNOWN[mylvl];
     sorcmap = ([ 1 : ({}), 2 : ({}), 3 : ({}), 4 : ({}), 5 : ({}), 6 : ({}), 7 : ({}), 8 : ({}), 9 : ({}), ]);
     spellsknown = ({});
     spellsknown += TP->query_base_mastered_spells();
     if(sizeof(spellsknown)) {
       for(i=0;i<sizeof(spellsknown);i++) {
         thespell = spellsknown[i];
         filename = "/cmds/spells/"+thespell[0..0]+"/_"+replace_string(thespell," ","_")+".c";
         if(file_exists(filename)) {
           if(buggy_spell = catch(spelllevel = filename->query_spell_level("mage"))) {
               tell_object(TP,thespell+" has a level error, removing it.");
               TP->remove_mastered_spell(thespell);
               continue;
           }
           if(!spelllevel) 
           {
               tell_object(TP,thespell+" has a level error, removing it.");
               TP->remove_mastered_spell(thespell);
               continue;
           }
           holder = sorcmap[spelllevel];
           holder += ({ thespell });
           sorcmap[spelllevel] = holder;
         }
       }
     }
     if(!str) {
       tell_object(TP,"You have spells known as follows:");
       for(i=1;i<10;i++) {
         myint = sizeof(sorcmap[i]);
         tell_object(TP,"Level "+i+": "+myint+"/"+(available[(i-1)])+" mastered.");
       }
       if(FEATS_D->usable_feat(TP,"greater spell knowledge"))
           tell_object(TP,"You may exceed these spells ang go above the limit by five spells in total overall.");
       else
           if(FEATS_D->usable_feat(TP,"spell knowledge"))
               tell_object(TP,"You may exceed these spells and go above the limit by two spells in total overall.");
       return 1;
     }
     if(str == "list") {
       tell_object(TP,"You have already mastered the following:");
       for(i=1;i<10;i++) {
         spellsknown = sorcmap[i];
         if(!sizeof(spellsknown)) {
           if(FEATS_D->usable_feat(TP,"gift of the shadows")) {
             if(i == 1) { tell_object(TP,"Level "+i+": shield of shadows."); continue; }
             if(i == 2) { tell_object(TP,"Level "+i+": umbral sight."); continue; }
             if(i == 7) { tell_object(TP,"Level "+i+": shadow double."); continue; }
             if(i == 9) { tell_object(TP,"Level "+i+": shadow nova."); continue; }
           }
           tell_object(TP,"Level "+i+": nil.");
           continue;
         }
         currentmsg = spellsknown[0];
         if(sizeof(spellsknown) > 1) {
           for(j = 1;j< sizeof(spellsknown);j++) currentmsg = currentmsg+", "+spellsknown[j]+"";
         }
         if(FEATS_D->usable_feat(TP,"shadow adept") || FEATS_D->usable_feat(TP,"gift of the shadows")) {
           if(i == 1) currentmsg += ", shield of shadows";
           if(i == 2) currentmsg += ", umbral sight";
           if(i == 7) currentmsg += ", shadow double";
           if(i == 9) currentmsg += ", shadow nova";
         }
         tell_object(TP,"Level "+i+": "+currentmsg+".");
       }
       return 1;
     }
     if(sscanf(str,"level %d",thelvl) == 1) {
       holder = ({});
       holder+=keys(
           filter_mapping(
               MAGIC_D->index_spells_for_player(TP,"sorcerer"),
               (:$2==$3:),thelvl));
       if(!sizeof(holder))
         return notify_fail("There are no spells at level "+thelvl+" to master.");
       currentmsg = holder[0];
       if(sizeof(holder) > 1) {
         for(i = 1;i< sizeof(holder);i++) {
           currentmsg += ", ";
           currentmsg += holder[i];
         }
       }
       tell_object(TP,"Available spells for level "+thelvl+": "+currentmsg+".");
       tell_object(TP,"Please see <help master> for further syntax.");
       return 1;
     }

// swapping sorc spells (same level unless spell knowledge is taken)
     if(sscanf(str,"swap %s for %s",first, second) == 2) {
       i = (int)TP->query("last_swapped_spells") + 36000; //require either 12hrs, or to have hit an even level, to swap a spell.
       if(!TP->query("can_swap_spells") && (i > time())) {
         tell_object(TP,"You cannot swap known spells so often! You can only do so after reaching an even level, or after a considerable wait from your last exchange.");
         return 1;
       }

       filename = "/cmds/spells/"+first[0..0]+"/_"+replace_string(first," ","_")+".c"; //known
       if(file_exists(filename)) {
         if(buggy_spell = catch(spelllevel = filename->query_spell_level("mage"))) {
           tell_object(TP,"The first spell has a level error, please contact a wiz.");
           return 1;
         }
         if(!spelllevel) {
           tell_object(TP,"The first spell has a level error, please contact a wiz.");
           return 1;
         }
         spellsknown = sorcmap[spelllevel];
         if(member_array(first,spellsknown) == -1) {
           tell_object(TP,"You don't know the "+first+" spell!.");
           return 1;
         }
       }
       filename2 = "/cmds/spells/"+second[0..0]+"/_"+replace_string(second," ","_")+".c"; //new
       if(file_exists(filename2)) {
         if(buggy_spell = catch(spelllevel2 = filename2->query_spell_level("mage"))) {
           tell_object(TP,"The second spell has a level error, please contact a wiz.");
           return 1;
         }
         if(!spelllevel2) {
           tell_object(TP,"The second spell has a level error, please contact a wiz.");
           return 1;
         }
         if(spelllevel != spelllevel2) {
           if(!FEATS_D->usable_feat(TP,"spell knowledge")) {
             tell_object(TP,"You can only swap two spells of the same level, unless you have the spell knowledge feat.");
             return 1;
           }
           if(FEATS_D->usable_feat(TP,"spell knowledge"))
               knownbonus = 1;
           if(FEATS_D->usable_feat(TP,"greater spell knowledge"))
               knownbonus = 4;
           // run totals here to allow spell knowledge to exceed overall only by 2
           if(sizeof(sorcmap[spelllevel2]) >= available[(spelllevel2-1)]) { // if already at native cap on this level!
             for(i=1;i<10;i++) {
               myint = sizeof(sorcmap[i]);
               if(myint > available[(i-1)]) runtally += (myint - available[(i-1)]);
             }
             if(runtally > knownbonus && (sizeof(sorcmap[spelllevel]) <= available[(spelllevel-1)])) {

                 tell_object(TP,"You've already mastered your extra spells for the spell knowledge feat.");
                 tell_object(TP,"To learn another above that level's cap, you must swap it for an existing extra spell.");
                 return 1;
             }
           }
         }
       }

       holder = ({});
       holder+=keys(
           MAGIC_D->index_spells_for_player(TP,"sorcerer"));
       if(member_array(second,holder) == -1) {
         tell_object(TP,"This is not a common spell that you can master.");
         return 1;
       }
       schoolspells = SCHOOLSPELLS;
       TP->remove_mastered_spell(first);
       TP->add_mastered_spell(second);
       TP->set("last_swapped_spells",time());
       TP->delete("can_swap_spells");
       tell_object(TP,"You have forgotten "+first+" and learned "+second+"!");
       return 1;
     }

// learning base sorc spells
     filename = "/cmds/spells/"+str[0..0]+"/_"+replace_string(str," ","_")+".c";
     if(file_exists(filename)) {
       if(buggy_spell = catch(spelllevel = filename->query_spell_level("mage"))) {
         tell_object(TP,"This spell has a level error, please contact a wiz.");
         return 1;
       }
       if(!spelllevel) {
         tell_object(TP,"This spell has a level error, please contact a wiz.");
         return 1;
       }
       myint = available[(spelllevel-1)] - (sizeof(sorcmap[spelllevel]));
       if(myint < 1) {
         if(!FEATS_D->usable_feat(TP,"spell knowledge")) {
           tell_object(TP,"You can't learn any further spells of level "+spelllevel+".");
           return 1;
         }
         if(FEATS_D->usable_feat(TP,"spell knowledge"))
             knownbonus = 1;
         if(FEATS_D->usable_feat(TP,"greater spell knowledge"))
             knownbonus = 4;
         // run totals here to allow spell knowledge to exceed overall only by 2
         for(i=1;i<10;i++) {
           myint = sizeof(sorcmap[i]);
           if(myint > available[(i-1)]) runtally += (myint - available[(i-1)]);
         }
         if(runtally > knownbonus) {
           tell_object(TP,"You've already mastered your extra spells for the spell knowledge feats.");
           tell_object(TP,"To learn another above that level's cap, you must swap it for an existing extra spell.");
           return 1;
         }
       }
       spellsknown = ({});
       spellsknown += TP->query_base_mastered_spells();
       if(member_array(str,spellsknown) != -1) {
         tell_object(TP,"You have already mastered this spell!");
         return 1;
       }
       holder = ({});
       holder+=keys(
           MAGIC_D->index_spells_for_player(TP,"sorcerer"));
       if(member_array(str,holder) == -1) {
         tell_object(TP,"This is not a common spell that you can master.");
         return 1;
       }
       mylvl = TP->query_level();
       myint = TP->query_stats("charisma");
       if(WIZ_CALCS->query_spell_limit(spelllevel,mylvl,"sorcerer",myint)) {
         TP->add_mastered_spell(str);
         tell_object(TP,"You have just mastered "+str+"!");
         return 1;
       }
       tell_object(TP,"You haven't yet learnt enough to master "+str+"!");
       return 1;
     }
     tell_object(TP,"No such spell exists. Please see <help master>.");
     return 1;
}

int psywarrior_master(string str)
{
    mylvl = TP->query_prestige_level("psywarrior");
    if(mylvl < 1) 
    {
        tell_object(TP,"You have no psywarrior level! Please contact a wiz.");
        return 1;
    }
    if(mylvl > CHARACTER_LEVEL_CAP) mylvl = CHARACTER_LEVEL_CAP;
    available = PWKNOWN[mylvl];
    pwmap = ([ 1 : ({}), 2 : ({}), 3 : ({}), 4 : ({}), 5 : ({}), 6 : ({}), ]);
    spellsknown = ({});
    spellsknown += TP->query_base_mastered_spells();
    if(sizeof(spellsknown)) {
        for(i=0;i<sizeof(spellsknown);i++) {
            thespell = spellsknown[i];
            filename = "/cmds/spells/"+thespell[0..0]+"/_"+replace_string(thespell," ","_")+".c";
            if(file_exists(filename)) {
                if(buggy_spell = catch(spelllevel = filename->query_spell_level("psywarrior"))) {
                    tell_object(TP,thespell+" has a level error, removing it.");
                    TP->remove_mastered_spell(thespell);
                    continue;
                }
                if(!spelllevel) 
                {
                    tell_object(TP,thespell+" has a level error, removing it.");
                    TP->remove_mastered_spell(thespell);
                    continue;
                }
                holder = pwmap[spelllevel];           
                holder += ({ thespell });
                pwmap[spelllevel] = holder;
            }
        }
    }

    if(!str) 
    {
        tell_object(TP,"You have powers known as follows:");
        for(i=1;i<7;i++) 
        {
            myint = sizeof(pwmap[i]);
            tell_object(TP,"Level "+i+": "+myint+"/"+available[(i-1)]+" mastered. (PP Cost Per Spell: %^BOLD%^%^CYAN%^"+COSTPERLEVEL[i-1]+"%^RESET%^)");
        }
        tell_object(TP, "Power points: "+TP->query_mp()+"/"+TP->query_max_mp());
        return 1;
    }
    if(str == "list") {
        tell_object(TP,"You have already mastered the following:");
        for(i=1;i<7;i++) {
            spellsknown = pwmap[i];
            if(!sizeof(spellsknown)) {
                if(!master_flag){
                    if(FEATS_D->usable_feat(TP,"presence of mind") || FEATS_D->usable_feat(TP,"mental fortress")) tell_object(TP,"You have already mastered timeless body.");
                    if(FEATS_D->usable_feat(TP,"body cognition") || FEATS_D->usable_feat(TP,"mind over matter")) tell_object(TP,"You have already mastered true metabolism.");
                    master_flag++;
                }
                tell_object(TP,"Level "+i+": nil.");
                continue;
            }
            currentmsg = spellsknown[0];
            if(sizeof(spellsknown) > 1) {
                for(j = 1;j< sizeof(spellsknown);j++) currentmsg = currentmsg+", "+spellsknown[j]+"";
            }
            tell_object(TP,"Level "+i+": "+currentmsg+".");
        }
        if(FEATS_D->usable_feat(TP,"expanded knowledge 1")){
            tell_object(TP,"%^RED%^Expanded Knowledge 1 Power: %^RESET%^"+(string)TP->query("expanded_knowledge_1")+"");
        }
        if(FEATS_D->usable_feat(TP,"expanded knowledge 2")){
            tell_object(TP,"%^RED%^Expanded Knowledge 2 Power: %^RESET%^"+(string)TP->query("expanded_knowledge_2")+"");
        }
        if(FEATS_D->usable_feat(TP,"expanded knowledge 3")){
            tell_object(TP,"%^RED%^Expanded Knowledge 3 Power: %^RESET%^"+(string)TP->query("expanded_knowledge_3")+"");
        }
        if(FEATS_D->usable_feat(TP,"presence of mind") || FEATS_D->usable_feat(TP,"mental fortress")){
            tell_object(TP,"%^RED%^Mental Fortress Power: %^RESET%^timeless body");
        }
        if(FEATS_D->usable_feat(TP,"body cognition") || FEATS_D->usable_feat(TP,"mind over matter")){
            tell_object(TP,"%^RED%^Mind Over Matter Power: %^RESET%^true metabolism");
        }
        return 1;
    }

    if(sscanf(str,"level %d",thelvl) == 1) {
        holder = ({});
        holder+=keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"psywarrior"),
                (:$2==$3:),thelvl));
        if(!sizeof(holder))
            return notify_fail("There are no spells at level "+thelvl+" to master.");
        currentmsg = holder[0];
        if(sizeof(holder) > 1) {
            for(i = 1;i< sizeof(holder);i++) {
                currentmsg += ", ";
                currentmsg += holder[i];
            }
        }
        tell_object(TP,"Available spells for level "+thelvl+": "+currentmsg+".");
        tell_object(TP,"Please see <help master> for further syntax.");
        return 1;
    }

// swapping psywarrior spells (same level)
    if(sscanf(str,"swap %s for %s",first, second) == 2) {
        i = (int)TP->query("last_swapped_spells") + 43200; //require either 12hrs, or to have hit an even level, to swap a spell.
        if(!TP->query("can_swap_spells") && (i > time())) {
            tell_object(TP,"You cannot swap known spells so often! "
                        "You can only do so after reaching an even level, or "
                        "after a considerable wait from your last exchange.");
            return 1;
        }

        filename = "/cmds/spells/"+first[0..0]+"/_"+replace_string(first," ","_")+".c"; //known
        if(file_exists(filename)) {
            if(buggy_spell = catch(spelllevel = filename->query_spell_level("psywarrior"))) {
                tell_object(TP,"The first spell has a level error, please contact a wiz.");
                return 1;
            }
            if(!spelllevel) {
                tell_object(TP,"The first spell has a level error, please contact a wiz.");
                return 1;
            }
            if(spelllevel > 6){
                tell_object(TP,"You can only swap powers you master normally!");
                return 1;
            }
            spellsknown = pwmap[spelllevel];
            if(member_array(first,spellsknown) == -1) {
                tell_object(TP,"You don't know the "+first+" spell!.");
                return 1;
            }
        }
        filename2 = "/cmds/spells/"+second[0..0]+"/_"+replace_string(second," ","_")+".c"; //new
        if(file_exists(filename2)) {
            if(buggy_spell = catch(spelllevel2 = filename2->query_spell_level("psywarrior"))) {
                tell_object(TP,"The second spell has a level error, please contact a wiz.");
                return 1;
            }
            if(!spelllevel2) {
                tell_object(TP,"The second spell has a level error, please contact a wiz.");
                return 1;
            }
            if(spelllevel2 > 6){
                tell_object(TP,"You can only swap powers you master normally!");
                return 1;
            }
            if(spelllevel != spelllevel2) {
                tell_object(TP,"You can only swap two spells of the same level, unless you have the spell knowledge feat.");
                return 1;
            }
        }

        holder = ({});
        holder+=keys(
            MAGIC_D->index_spells_for_player(TP,"psywarrior"));
        if(member_array(second,holder) == -1) {
            tell_object(TP,"This is not a common spell that you can master.");
            return 1;
        }

        TP->remove_mastered_spell(first);
        TP->add_mastered_spell(second);
        TP->set("last_swapped_spells",time());
        TP->delete("can_swap_spells");
        tell_object(TP,"You have forgotten "+first+" and learned "+second+"!");
        return 1;
    }

// learning base psywarrior spells
    filename = "/cmds/spells/"+str[0..0]+"/_"+replace_string(str," ","_")+".c";
    if(file_exists(filename)) {
        if(buggy_spell = catch(spelllevel = filename->query_spell_level("psywarrior"))) {
            tell_object(TP,"This spell has a level error, please contact a wiz.");
            return 1;
        }
        if(!spelllevel) {
            tell_object(TP,"This spell has a level error, please contact a wiz.");
            return 1;
        }
        myint = available[(spelllevel-1)] - (sizeof(pwmap[spelllevel]));
        if(myint < 1) {
            tell_object(TP,"You can't learn any further spells of level "+spelllevel+".");
            return 1;
        }
        spellsknown = ({});
        spellsknown += TP->query_mastered_spells();
        if(member_array(str,spellsknown) != -1) {
            tell_object(TP,"You have already mastered this spell!");
            return 1;
        }
        holder = ({});
        holder+=keys(
           MAGIC_D->index_spells_for_player(TP,"psywarrior"));
        if(member_array(str,holder) == -1) {
            tell_object(TP,"This is not a common spell that you can master.");
            return 1;
        }

        mylvl = TP->query_level();
        myint = TP->query_stats("intelligence");
        if(WIZ_CALCS->query_spell_limit(spelllevel,mylvl,"psywarrior",myint)) {
            TP->add_mastered_spell(str);
            tell_object(TP,"You have just mastered "+str+"!");
            return 1;
        }
        tell_object(TP,"You haven't yet learned enough to master "+str+"!");
        return 1;
    }
    tell_object(TP,"No such spell exists. Please see <help master>.");
    return 1;
}

int psion_master(string str)
{
    mylvl = TP->query_prestige_level("psion");
    if(mylvl < 1) {
        tell_object(TP,"You have no psion level! Please contact a wiz.");
        return 1;
    }
    if(mylvl > CHARACTER_LEVEL_CAP) mylvl = CHARACTER_LEVEL_CAP;
    available = PSIONKNOWN[mylvl];
    pwmap = ([ 1 : ({}), 2 : ({}), 3 : ({}), 4 : ({}), 5 : ({}), 6 : ({}), 7: ({}), 8: ({}), 9: ({}) ]);
    spellsknown = ({});
    spellsknown += TP->query_base_mastered_spells();
    if(sizeof(spellsknown)) {
        for(i=0;i<sizeof(spellsknown);i++) {
            thespell = spellsknown[i];
            filename = "/cmds/spells/"+thespell[0..0]+"/_"+replace_string(thespell," ","_")+".c";
            if(file_exists(filename)) {
                if(buggy_spell = catch(spelllevel = filename->query_spell_level("psion"))) {
                    tell_object(TP,thespell+" has a level error, removing it.");
                    TP->remove_mastered_spell(thespell);
                    continue;
                }
                if(!spelllevel) 
                {
                    tell_object(TP,thespell+" has a level error, removing it.");
                    TP->remove_mastered_spell(thespell);
                    continue;
                }
                holder = pwmap[spelllevel];
                holder += ({ thespell });
                pwmap[spelllevel] = holder;
            }
        }
    }

    if(!str) {
        tell_object(TP,"You have powers known as follows:");
        for(i=1;i<10;i++) {
            myint = sizeof(pwmap[i]);
            tell_object(TP,"Level "+i+": "+myint+"/"+available[(i-1)]+" mastered. (PP Cost Per Spell: %^BOLD%^%^CYAN%^"+COSTPERLEVEL[i-1]+"%^RESET%^)");
        }
        mydisc = (string)TP->query_discipline();
        if(stringp(mydisc) && mydisc != "") {
            powersbydiscipline = DISCIPLINESPELLSBYDISCIPLINE;
            schoolspells = powersbydiscipline[mydisc];
            if(sizeof(schoolspells)){
                if(mydisc == "egoist"){
                    tell_object(TP,"As an "+mydisc+", you also have access to the following powers:");
                }else{
                    tell_object(TP,"As a "+mydisc+", you also have access to the following powers:");
                }
                for(i=0;i<sizeof(schoolspells);i++){
                    tell_object(TP,""+schoolspells[i]+"");
                }
                tell_object(TP,"%^BOLD%^%^RED%^Please see the help files for descriptions and casting information.%^RESET%^");
            }
        }
        tell_object(TP, "Power points: "+TP->query_mp()+"/"+TP->query_max_mp());
        return 1;
    }
    if(str == "list") {
        tell_object(TP,"You have already mastered the following:");
        for(i=1;i<10;i++) {
            spellsknown = pwmap[i];
            if(!sizeof(spellsknown)) {
                if(!master_flag){
                    if(FEATS_D->usable_feat(TP,"presence of mind") || FEATS_D->usable_feat(TP,"mental fortress")) tell_object(TP,"You have already mastered timeless body.");
                    if(FEATS_D->usable_feat(TP,"body cognition") || FEATS_D->usable_feat(TP,"mind over matter")) tell_object(TP,"You have already mastered true metabolism.");
                    master_flag++;
                }
                tell_object(TP,"Level "+i+": nil.");
                continue;
            }
            currentmsg = spellsknown[0];
            if(sizeof(spellsknown) > 1) {
                for(j = 1;j< sizeof(spellsknown);j++) currentmsg = currentmsg+", "+spellsknown[j]+"";
            }
            tell_object(TP,"Level "+i+": "+currentmsg+".");
        }
        mydisc = (string)TP->query_discipline();
        if(stringp(mydisc) && mydisc != "") {
            powersbydiscipline = DISCIPLINESPELLSBYDISCIPLINE;
            schoolspells = powersbydiscipline[mydisc];
            if(sizeof(schoolspells)){
                if(mydisc == "egoist"){
                    tell_object(TP,"As an "+mydisc+", you also have access to the following powers:");
                }else{
                    tell_object(TP,"As a "+mydisc+", you also have access to the following powers:");
                }
                for(i=0;i<sizeof(schoolspells);i++){
                    tell_object(TP,""+schoolspells[i]+"");
                }
            }
        }
        if(FEATS_D->usable_feat(TP,"expanded knowledge 1")){
            tell_object(TP,"%^RED%^Expanded Knowledge 1 Power: %^RESET%^"+(string)TP->query("expanded_knowledge_1")+"");
        }
        if(FEATS_D->usable_feat(TP,"expanded knowledge 2")){
            tell_object(TP,"%^RED%^Expanded Knowledge 2 Power: %^RESET%^"+(string)TP->query("expanded_knowledge_2")+"");
        }
        if(FEATS_D->usable_feat(TP,"expanded knowledge 3")){
            tell_object(TP,"%^RED%^Expanded Knowledge 3 Power: %^RESET%^"+(string)TP->query("expanded_knowledge_3")+"");
        }
        if(FEATS_D->usable_feat(TP,"presence of mind") || FEATS_D->usable_feat(TP,"mental fortress")){
            tell_object(TP,"%^RED%^Presence of Mind Power: %^RESET%^timeless body");
        }
        if(FEATS_D->usable_feat(TP,"body cognition") || FEATS_D->usable_feat(TP,"mind over matter")){
            tell_object(TP,"%^RED%^Body Cognition Power: %^RESET%^true metabolism");
        }
        return 1;
    }

    if(sscanf(str,"level %d",thelvl) == 1) {
        holder = keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"psion"),
                (:$2==thelvl:)));
        if(!sizeof(holder))
            return notify_fail("There are no spells at level "+thelvl+" to master.");
        currentmsg = holder[0];
        if(sizeof(holder) > 1) {
            for(i = 1;i< sizeof(holder);i++) {
                currentmsg += ", ";
                currentmsg += holder[i];
            }
        }
        tell_object(TP,"Available spells for level "+thelvl+": "+currentmsg+".");
        tell_object(TP,"Please see <help master> for further syntax.");
        return 1;
    }

// swapping psion spells (same level)
    if(sscanf(str,"swap %s for %s",first, second) == 2) {
        i = (int)TP->query("last_swapped_spells") + 43200; //require either 12hrs, or to have hit an even level, to swap a spell.
        if(!TP->query("can_swap_spells") && (i > time())) {
            tell_object(TP,"You cannot swap known spells so often! "
                        "You can only do so after reaching an even level, or "
                        "after a considerable wait from your last exchange.");
            return 1;
        }

        filename = "/cmds/spells/"+first[0..0]+"/_"+replace_string(first," ","_")+".c"; //known
        if(file_exists(filename)) {
            if(buggy_spell = catch(spelllevel = filename->query_spell_level("psion"))) {
                tell_object(TP,"The first spell has a level error, please contact a wiz.");
                return 1;
            }
            if(!spelllevel) {
                tell_object(TP,"The first spell has a level error, please contact a wiz.");
                return 1;
            }
            if(spelllevel > 9){
                tell_object(TP,"You can only swap powers you master normally!");
                return 1;
            }
            spellsknown = pwmap[spelllevel];
            if(member_array(first,spellsknown) == -1) {
                tell_object(TP,"You don't know the "+first+" spell!.");
                return 1;
            }
        }
        filename2 = "/cmds/spells/"+second[0..0]+"/_"+replace_string(second," ","_")+".c"; //new
        if(file_exists(filename2)) {
            if(buggy_spell = catch(spelllevel2 = filename2->query_spell_level("psion"))) {
                tell_object(TP,"The second spell has a level error, please contact a wiz.");
                return 1;
            }
            if(!spelllevel2) {
                tell_object(TP,"The second spell has a level error, please contact a wiz.");
                return 1;
            }
            if(spelllevel2 > 9){
                tell_object(TP,"You can only swap powers you master normally!");
                return 1;
            }
            if(spelllevel != spelllevel2) {
                tell_object(TP,"You can only swap two spells of the same level, unless you have the spell knowledge feat.");
                return 1;
            }
        }

        holder = keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"psion"),
                (:$2==spelllevel2:)));
        if(member_array(second,holder) == -1) {
            tell_object(TP,"This is not a common spell that you can master.");
            return 1;
        }
        schoolspells = DISCIPLINESPELLS;
        if(member_array(second,schoolspells) != -1) { 
            tell_object(TP,"You cannot master a discipline-specific power!");
            return 1;
        }
        TP->remove_mastered_spell(first);
        TP->add_mastered_spell(second);
        TP->set("last_swapped_spells",time());
        TP->delete("can_swap_spells");
        tell_object(TP,"You have forgotten "+first+" and learned "+second+"!");
        return 1;
    }

// learning base psion spells
    filename = MAGIC_D->get_spell_file_name(str);
    if(file_exists(filename)) {
        if(buggy_spell = catch(spelllevel = filename->query_spell_level("psion"))) {
            tell_object(TP,"This spell has a level error, please contact a wiz.");
            return 1;
        }
        if(!spelllevel) {
            tell_object(TP,"This spell has a level error, please contact a wiz.");
            return 1;
        }
        myint = available[(spelllevel-1)] - (sizeof(pwmap[spelllevel]));
        if(myint < 1) {
            tell_object(TP,"You can't learn any further spells of level "+spelllevel+".");
            return 1;
        }
        spellsknown = ({});
        spellsknown += TP->query_mastered_spells();
        if(member_array(str,spellsknown) != -1) {
            tell_object(TP,"You have already mastered this spell!");
            return 1;
        }
        holder = keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"psion"),
                (:$2==spelllevel:)));
        if(member_array(str,holder) == -1) {
            tell_object(TP,"This is not a common spell that you can master.");
            return 1;
        }
        schoolspells = DISCIPLINESPELLS;
        if(member_array(str,schoolspells) != -1) { 
            tell_object(TP,"You cannot master a discipline-specific power!");
            return 1;
        }
        mylvl = TP->query_level();
        myint = TP->query_stats("intelligence");
        if(WIZ_CALCS->query_spell_limit(spelllevel,mylvl,"psion",myint)) {
            TP->add_mastered_spell(str);
            tell_object(TP,"You have just mastered "+str+"!");
            return 1;
        }
        tell_object(TP,"You haven't yet learned enough to master "+str+"!");
        return 1;
    }
    tell_object(TP,"No such spell exists. Please see <help master>.");
    return 1;
}

int warlock_master(string str)
{
    mylvl = TP->query_prestige_level("warlock");
    if(mylvl < 1) {
        tell_object(TP,"You have no warlock level! Please contact a wiz.");
        return 1;
    }
    if(mylvl > CHARACTER_LEVEL_CAP) mylvl = CHARACTER_LEVEL_CAP;
    available = WARLOCKKNOWN[mylvl];
    sorcmap = ([ 1 : ({}), 2 : ({}), 3 : ({}), 4 : ({}), ]);
    spellsknown = ({});
    spellsknown += TP->query_base_mastered_spells();
    if(sizeof(spellsknown)) {
        for(i=0;i<sizeof(spellsknown);i++) {
            thespell = spellsknown[i];
            filename = "/cmds/spells/"+thespell[0..0]+"/_"+replace_string(thespell," ","_")+".c";
            if(file_exists(filename)) {
                if(buggy_spell = catch(spelllevel = filename->query_spell_level("warlock"))) {
                    tell_object(TP,thespell+" has a level error, removing it.");
                    TP->remove_mastered_spell(thespell);
                    continue;
                }
                if(!spelllevel) 
                {
                    tell_object(TP,thespell+" has a level error, removing it.");
                    TP->remove_mastered_spell(thespell);
                    continue;
                }
                holder = sorcmap[spelllevel];
                holder += ({ thespell });
                sorcmap[spelllevel] = holder;
            }
        }
    }

    if(!str) {
        tell_object(TP,"You have spells known as follows:");
        for(i=1;i<5;i++) {
            myint = sizeof(sorcmap[i]);
            switch(i) {
            case 1: currentmsg = "Least invocations: "; break;
            case 2: currentmsg = "Lesser invocations: "; break;
            case 3: currentmsg = "Greater invocations: "; break;
            case 4: currentmsg = "Ancestral invocations: "; break;
            }
            tell_object(TP,""+currentmsg+myint+"/"+available[(i-1)]+" mastered.");
        }
        return 1;
    }
    if(str == "list") {
        tell_object(TP,"You have already mastered the following:");
        for(i=1;i<5;i++) {
            spellsknown = sorcmap[i];
            switch(i) {
            case 1: currentmsg = "Least invocations: "; break;
            case 2: currentmsg = "Lesser invocations: "; break;
            case 3: currentmsg = "Greater invocations: "; break;
            case 4: currentmsg = "Ancestral invocations: "; break;
            }
// let's patch in the default spells the class comes with!
            if(i == 1) {
                currentmsg += "eldritch blast, eldritch claws, summon companion";
                if(mylvl > 1) currentmsg += ", detect magic";
            }
            if(i == 2) {
                if(mylvl > 4) currentmsg += "eldritch chain";
            }
            if(i == 3) {
                if(mylvl > 10) currentmsg += "eldritch glaive, eldritch bow";
            }
            if(i == 4) {
                if(mylvl > 14) currentmsg += "eldritch burst";
            }
            if(!sizeof(spellsknown)) { // if no default shape yet learnt at this level, show nil only.
                if(strsrch(currentmsg,"eldritch") == -1) currentmsg += "nil";
            }
            else { // at this point clearly they've mastered something of that level, so let's stack them on!
                currentmsg += ", ";
                currentmsg += spellsknown[0];
                if(sizeof(spellsknown) > 1) {
                    for(j = 1;j< sizeof(spellsknown);j++) currentmsg = currentmsg+", "+spellsknown[j]+"";
                }
            }
            tell_object(TP,""+currentmsg+".");
        }
        return 1;
    }
    if(sscanf(str,"%s invocations",thespell) == 1) {
        int lvl;
        holder = ({});
        switch(thespell) {
        case "least":
            lvl = 1; break;
        case "lesser":
            lvl = 2; break;
        case "greater":
            lvl = 3; break;
        case "ancestral":
            lvl = 4; break;
        default: tell_object(TP,"Invalid invocation level - see <help master>\n");
            return 1; break;
        }
        holder+=keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"warlock"),
                (:$2==$3:),lvl));
        if(!sizeof(holder))
            return notify_fail("There are no "+thespell+" invocations to master.");
        currentmsg = holder[0];
        if(sizeof(holder) > 1) {
            for(i = 1;i< sizeof(holder);i++) {
                currentmsg += ", ";
                currentmsg += holder[i];
            }
        }
        tell_object(TP,"Available "+thespell+" invocations: "+currentmsg+".");
        tell_object(TP,"Please see <help master> for further syntax.");
        return 1;
    }

// swapping warlock spells (same level only)
    if(sscanf(str,"swap %s for %s",first, second) == 2) {
        i = (int)TP->query("last_swapped_spells") + 43200; //require either 12hrs, or to have hit an even level, to swap a spell.
        if(!TP->query("can_swap_spells") && (i > time())) {
            tell_object(TP,"You cannot swap known invocations so often! You can only do so after reaching an even level, or after a considerable wait from your last exchange.");
            return 1;
        }

        filename = "/cmds/spells/"+first[0..0]+"/_"+replace_string(first," ","_")+".c"; //known
        if(file_exists(filename)) {
            if(buggy_spell = catch(spelllevel = filename->query_spell_level("warlock"))) {
                tell_object(TP,"The first invocation has a level error, please contact a wiz.");
                return 1;
            }
            if(!spelllevel) {
                tell_object(TP,"The first invocation has a level error, please contact a wiz.");
                return 1;
            }
            spellsknown = sorcmap[spelllevel];
            if(member_array(first,spellsknown) == -1) {
                tell_object(TP,"You don't know the "+first+" invocation!.");
                return 1;
            }
        }
        filename2 = "/cmds/spells/"+second[0..0]+"/_"+replace_string(second," ","_")+".c"; //new
        if(file_exists(filename2)) {
            if(buggy_spell = catch(spelllevel2 = filename2->query_spell_level("warlock"))) {
                tell_object(TP,"The second invocation has a level error, please contact a wiz.");
                return 1;
            }
            if(!spelllevel2) {
                tell_object(TP,"The second invocation has a level error, please contact a wiz.");
                return 1;
            }
            if(spelllevel != spelllevel2) {
                tell_object(TP,"You can only swap two invocations of the same type.");
                return 1;
            }
        }

        holder = ({});
        holder+=keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"warlock"),
                (:$2==$3:),spelllevel2));
        if(member_array(second,holder) == -1) {
            tell_object(TP,"This is not an invocation that you can master.");
            return 1;
        }
        TP->remove_mastered_spell(first);
        TP->add_mastered_spell(second);
        TP->set("last_swapped_spells",time());
        TP->delete("can_swap_spells");
        tell_object(TP,"You have forgotten "+first+" and learned "+second+"!");
        second = "";
        second += (string)TP->query("warlock_blast_type");
        second += " blast";
        if(first == second) { // ie. if they've just unmastered their active blast type
            TP->delete("warlock_blast_type");
            tell_object(TP,"You have just forgone your knowledge of "+first+", so your active blast essence has been reset!");
        }
        return 1;
    }

// learning base warlock spells
    filename = "/cmds/spells/"+str[0..0]+"/_"+replace_string(str," ","_")+".c";
    if(file_exists(filename)) {
        if(buggy_spell = catch(spelllevel = filename->query_spell_level("warlock"))) {
            tell_object(TP,"This invocation has a level error, please contact a wiz.");
            return 1;
        }
        if(!spelllevel) {
            tell_object(TP,"This invocation has a level error, please contact a wiz.");
            return 1;
        }
        myint = available[(spelllevel-1)] - (sizeof(sorcmap[spelllevel]));

        switch(spelllevel) {
        case 1: thespell = "least"; break;
        case 2: thespell = "lesser"; break;
        case 3: thespell = "greater"; break;
        case 4: thespell = "ancestral"; break;
        }
        if(myint < 1) {
            tell_object(TP,"You can't learn any further "+thespell+" invocations.");
            return 1;
        }
        spellsknown = ({});
        spellsknown += TP->query_base_mastered_spells();
        if(member_array(str,spellsknown) != -1) {
            tell_object(TP,"You have already mastered this invocation!");
            return 1;
        }
        holder = ({});
        holder+=keys(
            filter_mapping(
                MAGIC_D->index_spells_for_player(TP,"warlock"),
                (:$2==$3:),spelllevel));
        if(member_array(str,holder) == -1) {
            tell_object(TP,"This is not an invocation that you can master.");
            return 1;
        }
        TP->add_mastered_spell(str);
        tell_object(TP,"You have just mastered "+str+"!");
        return 1;
    }
    tell_object(TP,"No such invocation exists. Please see <help master>.");
    return 1;
}

int univ_master(string str)
{
    
}

int cmd_master(string str) 
{
   if(TP->is_class("mage"))
       return mage_master(str);
   if(TP->is_class("sorcerer")) 
       return sorcerer_master(str);
   if(TP->is_class("psywarrior"))
       return psywarrior_master(str);
   if(TP->is_class("psion"))
       return psion_master(str);
   if(TP->is_class("warlock"))
       return warlock_master(str);

   return notify_fail("You cannot master spells.\n");
}

int help(){
    if(TP->is_class("mage")) {
      write(
@OLI

    %^YELLOW%^master%^RESET%^

    This will list the levels at which a spell is available to learn.

    %^YELLOW%^master list #%^RESET%^

    This will list the spells you have already mastered.

    %^YELLOW%^master level #%^RESET%^

    This will list the available spells for the specified level.

    %^YELLOW%^master spellname%^RESET%^
    
    This will allow the caster to master a selected spell, "
"representing the mage's research and learning over time.  One 
spell is available per spell level, allowing a maximum of 9 
spells to be mastered in entirety. You will also see your mage 
school spells appear automatically on this list. Please be 
cautious in selecting spells, as you may only choose once for 
each spell level. Mastered spells will update themselves 
automatically into your spellbook next time it moves into your 
immediate inventory, and they will remain with the character 
permanently, you even through loss of spellbook backups.

OLI
    );
    return 1;
    }

    if(TP->is_class("sorcerer")) {
      write(
@OLI

    %^YELLOW%^master%^RESET%^

    This will list the number of spells already used on each 
level, and how many are available in total.

    %^YELLOW%^master list #%^RESET%^

    This will list the spells you have already mastered.

    %^YELLOW%^master level #%^RESET%^

    This will list the available spells for the specified level.

    %^YELLOW%^master spellname%^RESET%^
    
    This will allow the sorcerer to master a certain selected 
spell, a sorcerer's innate understanding of spellcraft. Numbers 
of spells will become open as further levels are gained. Any 
spell must be mastered before it can be cast.

    %^YELLOW%^master swap known-spellname for new-spellname%^RESET%^

    This will let a sorcerer trade an already known spell for 
a new one of the same level. This can be done once every two 
levels, or after an extended length of time since the last swap 
was made.

OLI
    );
    return 1;
    }

    if(TP->is_class("psywarrior") || TP->is_class("psion")) {
      write(
@OLI

    %^YELLOW%^master%^RESET%^

    This will list the number of powers already used on each 
level, and how many are available in total.

    %^YELLOW%^master list #%^RESET%^

    This will list the powers you have already mastered.

    %^YELLOW%^master level #%^RESET%^

    This will list the available powers for the specified level.

    %^YELLOW%^master powername%^RESET%^
    
    This will allow the psionic character to manifest a certain selected 
power, drawn from the psionic character's innate mental abilities.
Numbers of powers will become open as further levels are gained. Any 
power must be manifested before it can be cast.

    %^YELLOW%^master swap known-powername for new-powername%^RESET%^

    This will let a psionic character trade an already known power for 
a new one of the same level. This can be done once every two 
levels, or after an extended length of time since the last swap 
was made.

OLI
    );
    return 1;
    }

    if(TP->is_class("warlock")) {
      write(
@OLI

    %^YELLOW%^master%^RESET%^

    This will list the number of invocations already used on each 
level, and how many are available in total.

    %^YELLOW%^master list%^RESET%^

    This will list the invocations you have already mastered. Note 
that eldritch blast is automatically learned at level 1, and that 
detect magic is automatically learned at level 2. Neither of these 
invocations will use up the available slots.

    %^YELLOW%^master least/lesser/greater/ancestral invocations%^RESET%^

    This will list the available invocations for the specified type.

    %^YELLOW%^master invocation-name%^RESET%^
    
    This will allow the warlock to learn a particular invocation, 
which can then be cast at will without preparation.

    %^YELLOW%^master swap known-invocation for new-invocation%^RESET%^

    This will let a warlock trade an already known invocation for 
a new one of the same level. This can be done once every two 
levels, or after an extended length of time since the last swap 
was made.

OLI
    );
    return 1;
    }

      write(
@OLI

    This command allows mages and sorcerers to learn spells as 
they level, either by study or by an innate understanding of 
spellcraft.

OLI
    );
    return 1;
}
