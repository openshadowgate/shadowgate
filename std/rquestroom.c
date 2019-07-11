// making quests_low in the list function use generic list added to /daemon/quests_low
// only immortals now see the actual list for low/mids, leaving high in detail
// since it's less likely to have ooc info abuse & it often takes a party to get them
// *Styx*  1/15/03

#include <std.h>

inherit VAULT;

int waiting;

string QUEST_D = "/daemon/quests";
void create(){
    ::create();
    set_property("no_ckpt", 1);
    set_items(([
        "sign":"You can <read list> for a list of quests or <claim> the reward from a quest."
    ]));
}

void set_quest_daemon(string daemon){
     QUEST_D = daemon;
}

string query_quest_daemon(){ 
    return QUEST_D;
}

void init(){
    ::init();
    add_action("read_list","read");
    add_action("claim","claim");
}

int read_list(string str)
{
    string questlist, *questkeys;
    mapping quests;
    int i,exp;
    string item, file, which, name;
    
    if(!str || str!="list") return 0;
    //added by Saide - May 2016 
    if(QUEST_D == "/daemon/quests_high")
    {
        if((int)TP->query_character_level() < 25 && !avatarp(TP)) 
        {
            tell_object(TP, "%^BOLD%^You are far too inexperienced to be attempting to recover "+
            "items from this quest list. OOC: You must now be level 25 or above to "+
            "see this quest list or claim items here.%^RESET%^");
            return 1;            
        }
    }
    
    if(QUEST_D == "/daemon/quests_low")
    {
        if((int)TP->query_character_level() > 15 && !avatarp(TP)) 
        {
            tell_object(TP, "%^BOLD%^You are far too experienced to be attempting to claim "+
            "items from this quest list. OOC: You must now be level 15 or below to "+
            "see this quest list or claim items here.%^RESET%^");
            return 1;            
        }
    }
    
    if(QUEST_D == "/daemon/quests_mid")
    {
        if((int)TP->query_character_level() > 25 && !avatarp(TP) || ((int)TP->query_character_level() < 15 && !avatarp(TP))) 
        {
            tell_object(TP, "%^BOLD%^You are far too experienced to be attempting to claim "+
            "items from this quest list. OOC: You must now be between level 15 and 25 "+
            "see this quest list or claim items here.%^RESET%^");
            return 1;            
        }
    }    
        
   
    // this section added 1/15/03
    if(QUEST_D == "/daemon/quests_low") {
        questkeys = QUEST_D->query_generic_list();
    	questlist = "%^BOLD%^The following areas often have mini-quest items to be found\n"
            "%^BOLD%^and claimed here for an appropriate reward for low and mid levels.\n"
            "%^BOLD%^There is another board for the much greater challenges to be sought\n"
            "%^BOLD%^once you have conquered these areas and have proven yourself worthy.\n";
        questlist += "%^BOLD%^%^CYAN%^"
            "====================================================================\n%^RESET%^";
    }
    quests = QUEST_D->queryQuests();
    questkeys = keys(quests);
    questlist = "%^BOLD%^The following quests are available:\n";
    questlist += "%^BOLD%^%^CYAN%^-=--=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n%^RESET%^";
    for(i=0;i<sizeof(questkeys);i++){
        item = questkeys[i];
        if(!pointerp(quests[item])) continue;
        which = quests[item][0];
        file = quests[item][1];
        exp = quests[item][2];
        name = quests[item][3];
        if(which =="monster"){
           questlist += "Retrieve the "+item+"%^RESET%^ possessed by \n  "+name;
           if(wizardp(TP)) {
                questlist += "%^BOLD%^%^GREEN%^%^ ("+file+")%^RESET%^";
           }
           questlist += "\n  before "+ctime(quests[item][4])+" (MST) for "+exp+" experience.\n";
        }
        else if(which =="room"){
           questlist += "Retrieve the "+item+"%^RESET%^ last seen in\n  "+name;
           if(wizardp(TP)) {
                questlist += " %^BOLD%^%^GREEN%^("+file+")%^RESET%^";
           }
           questlist += "\n  before "+ctime(quests[item][4])+" (MST) for "+exp+" experience.\n";
        }
    }
    questlist += "\n";
    TP->more(explode(questlist,"\n"));
    return 1;    
}

int claim(string str){
    mapping quests;
    string *questkeys;
    object ob,ob2;
    string name;
    
    if(!str) return notify_fail("Claim <item name>.\n");
    if(waiting) return notify_fail("Please wait a moment while I clean up this mess the last person left.\n");
    quests = QUEST_D->queryQuests();
    questkeys = keys(quests);
    ob = present(str,TP);
    if(!objectp(ob)) return notify_fail("You don't have that.\n");
    //Added by Saide - May 2016
    if(QUEST_D == "/daemon/quests_high")
    {
        if((int)TP->query_character_level() < 25) 
        {
            tell_object(TP, "%^BOLD%^You are far too inexperienced to be attempting to claim "+
            "items from this quest list. OOC: You must now be level 25 or above to "+
            "see this quest list or claim items here.%^RESET%^");
            return 1;            
        }
    }
    
    if(QUEST_D == "/daemon/quests_low")
    {
        if((int)TP->query_character_level() > 15) 
        {
            tell_object(TP, "%^BOLD%^You are far too experienced to be attempting to claim "+
            "items from this quest list. OOC: You must now be level 15 or below to "+
            "see this quest list or claim items here.%^RESET%^");
            return 1;            
        }
    }
    
    if(QUEST_D == "/daemon/quests_mid")
    {
        if((int)TP->query_character_level() > 25 || (int)TP->query_character_level() < 15) 
        {
            tell_object(TP, "%^BOLD%^You are far too experienced to be attempting to claim "+
            "items from this quest list. OOC: You must now be between level 15 and 25 to "+
            "see this quest list or claim items here.%^RESET%^");
            return 1;            
        }
    }    
    
    if (!TO->query_property("no_ckpt")) TO->set_property("no_ckpt", 1);
    name = ob->query("short");
     waiting = 1;
    call_out("delay",5);
    if(member_array(name,questkeys) != -1){
        if(ob2=present("questor",TO))
            if(!random(5))
                ob2->thank();
        QUEST_D->claimExp(name,TP,ob->query_ob_level());
        ob->remove();
        return 1;
    }    
}
void delay(){waiting = 0;}

void reset()
{
    object questor;
    ::reset();
    if(!present("questor"))
    {
        questor = new("/d/common/mons/questor");
        questor ->move(TO);
    }
}


