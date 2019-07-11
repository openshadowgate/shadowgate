/*=====================================
useruc_d.c - using uc_d.c to dictate that the daemon
handles something in the user chain - I did not do this with combat_d.c
but from here on out it is plan - the files will be located in /daemon/userchain/

this is the daemon that will handle user.c functions

Saide January 2017

=======================================*/
#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>
#include <rooms.h>
#include <damage_types.h>
#include <security.h>
#include <langs.h>
#include <move.h>
#include <objects.h>
#include <class_types.h>
#define STATS ({"strength", "dexterity", "constitution", "intelligence", "wisdom", "charisma"})
#define YUCK_D ("/daemon/yuck_d")
#define VOID "/d/shadowgate/void"
#include <schoolspells.h>
#include <psions.h>
#include <new_exp_table.h>
#define KEPTMESSAGES ({"reply","notify","broadcast","say","emote","whisper","party","honey","emoteto", "discuss"})
#define MAX_ENCUMBRANCE ({15,25,35,45,60,85,105,125,145,160,180,195,210,225,235,245,255,270,285,300, 305,310,315,320,325,330,335,340,345,350,355,\
                          360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450,455,460,465,470,475,480,485,495,500,505,510,\
                          515,520,525,530,535,540,545,550,555,565,576,585,590,595,600,605,610})
#define OVERRIDE_IGNORE_MSG ({ "damage","broadcast", "info", "more", "room_description", "room_exits","smell","listen","write","say", "system", "prompt", "inanimate_item", "living_item"})
inherit DAEMON;
//FUNCTIONS
int is_align_type(object ob, int *align);
int racial_stat_mod(object ob, string stat);
int age_mod(object who, string stat);
string query_real_age_cat(object who);
mixed check_file(string type, string arg);
//END OF FUNCTION DECLERATIONS
mixed check_file(string type, string arg)
{
    string myfile;
    switch(type)
    {
        case "race":
            if(!stringp(arg)) return 0;   
            myfile = "/std/races/"+arg+".c";
            if(!file_exists(myfile)) return 0;
            return myfile;
    }
    return 0;
}

int is_align_type(object ob, int *align)
{
    if(!objectp(ob)) return 0;
    if(!pointerp(align)) return 0;
    if(member_array(ob->query_alignment(), align) == -1) return 0;
    return 1;
}

int racial_stat_mod(object ob, string stat)
{
    int *mystats, i;
    string mysubrace;
    mixed myfile;
    if(!objectp(ob)) return 0;
    if(!stringp(stat)) return 0;
    if(avatarp(ob)) return 0;
    if(!myfile = check_file("race", (string)ob->query_race())) return 0;
    mysubrace = (string)ob->query("subrace");
    mystats = (int *)myfile->stat_mods(mysubrace);
    if(sizeof(mystats) != 6) return 0;    
    if((i = member_array(stat, STATS)) == -1) return 0;
    return mystats[i];
}

int age_mod(object who, string stat) 
{
   int i, ignore_negative, mod;
   string agebracket;
   mapping AGE_MODS;
   if(!objectp(who)) return 0;
   if(!stringp(stat)) return 0;
   if(avatarp(who)) return 0;
   AGE_MODS = (["child" : ({-1, 1, -1, -1, 1}), "middle" : ({-1, -1, -1, 1, 1, 1}),
   "old" : ({-2, -2, -2, 2, 2, 2}), "venerable" : ({-3, -3, -3, 3, 3, 3})]);
   if((i = member_array(stat, STATS)) == -1) return 0;
   agebracket = who->query_real_age_cat();
   if(member_array(agebracket, keys(AGE_MODS)) == -1) return 0;
   mod = AGE_MODS[agebracket][i];
   if(FEATS_D->usable_feat(who, "timeless body") && agebracket != "child") ignore_negative = 1;
   if(mod < 0 && ignore_negative) return 0;
   return mod;
}

string query_real_age_cat(object who) 
{
    string myfile, myrace;
    int *agecats, real_age;
    if(!objectp(who)) return "error";
    if(avatarp(who)) return "immortal";
    if(!myfile = check_file("race", (string)who->query_race())) return "error";
    agecats = (int *)myfile->age_brackets();
    if(sizeof(agecats) < 4) return "error in array";
    real_age = who->query_real_age();
    if(real_age >= agecats[3]) return "venerable";
    if(real_age >= agecats[2]) return "old";
    if(real_age >= agecats[1]) return "middle";
    if(real_age >= agecats[0]) return "normal";
    return "child";
}

void clean_up_feats(object who, string type, int start_point)
{
    mapping tempmap = ([]), featmap, call_map;
    int newpoint, i, j;
    string *subarray, *subset;    
    call_map = (["other" : ([ "funcs" : ({"query_other_feats", "set_other_feats"}), "classes" : ({}), "add" : 3, "special classes" : ({}),]), 
                 "bonus" : ([ "funcs" : ({"query_bonus_feats", "set_bonus_feats"}), "classes" : MELEECLASSES, "add" : 5, "special classes" : ({"fighter"}), ]),
                 "magic" : ([ "funcs" : ({"query_magic_feats", "set_magic_feats"}), "classes" : CASTERCLASSES, "add" : 5, "special classes" : ({"sorcerer", "psion"}), ]),
                 "hybrid" : ([ "funcs" : ({"query_hybrid_feats", "set_hybrid_feats"}), "classes" : HYBRIDCLASSES, "add" : 5, "special classes" : ({"psywarrior"}), ]),]);       
                 
    if(member_array(type, keys(call_map)) == -1) return;
    featmap = call_other(who, call_map[type]["funcs"][0]);
    if(!sizeof(keys(featmap))) return;
    if(sizeof(call_map[type]["classes"]))
    {
        subset = who->query_classes();
        if(!sizeof(subset)) return;
        newpoint = 0;
        for(i = 0; i < sizeof(subset);i ++)
        {
            if(member_array(subset[i],call_map[type]["classes"]) == -1) { newpoint += who->query_class_level(subset[i]); }
            else
            {
                if(member_array(subset[i],call_map[type]["special classes"] == -1)) 
                {
                    if(who->query_class_level(subset[i]) > 20) newpoint += 20;
                    else newpoint += who->query_class_level(subset[i]);
                }
            }
            continue;
        } 
        newpoint++;
    }
    else newpoint = start_point;
    for(j = 0;j < sizeof(keys(featmap));j++)
    {
        if(!pointerp(subarray = featmap[j])) continue;
        for(i = 0; i < sizeof(subarray);i++)
        {
            tempmap[newpoint] = ({ subarray[i] });
            if(newpoint == 1 && type == "other") newpoint = 3;
            else newpoint += call_map[type]["add"];
            continue;
        }        
    }
    call_other(who, call_map[type]["funcs"][1], tempmap);
    return;
}

void tidy_feats(object who) 
{   
    if(!objectp(who)) return;
    clean_up_feats(who, "other", 1);
    clean_up_feats(who, "bonus", -1);
    clean_up_feats(who, "magic", -1);
    clean_up_feats(who, "hybrid", -1);
    return;
}

mixed query_feats_by_type(mixed featlist, mapping featmap)
{
    int i;
    string *myreturn;
    if(!mapp(featmap)) return ({});
    if(!featlist) featlist = ({"class", "bonus", "magic", "hybrid", "other", "epic"});
    myreturn = ({});
    if(pointerp(featlist))
    {
        for(i = 0; i < sizeof(featlist);i++)
        {
            if(mapp(featmap[featlist[i]])) 
            { 
                foreach(string *tmp in values(featmap[featlist[i]])) 
                { 
                    foreach(string feat in tmp) { myreturn += ({feat}); }
                }
            }
            continue;
        }
        return myreturn;
    }
    if(stringp(featlist)) 
    { 
        if(mapp(featmap[featlist])) { return featmap[featlist]; }
        else return ([]);        
    }
    return myreturn;
}

void set_temporary_feats(object who, string *feats)
{
    if(!pointerp(feats) || !objectp(who)) { return; }
    who->set_static("temporary feats", feats);
    return;
}

string *query_temporary_feats(object who)
{
    string *tempfeats;
    if(!objectp(who) || !pointerp(tempfeats = who->get_static("temporary feats"))) return ({});
    return tempfeats;
}

void adjust_temporary_feats(object who, string feat, string which)
{
    string *tempfeats;
    if(!stringp(feat) || !objectp(who)) { return; }
    if(!"/daemon/feat_d.c"->is_feat(feat)) { return; }
    if(!pointerp(tempfeats = who->get_static("temporary feats"))) 
    { 
        if(which == "add") tempfeats = ({feat}); 
        else if(which == "remove") tempfeats = ({});
    }
    else if(member_array(feat, tempfeats) == -1 && which == "add") { tempfeats += ({feat}); }
    else if(member_array(feat, tempfeats) != -1 && which == "remove") { tempfeats -= ({feat}); }
    else return;
    who->set_static("temporary feats", tempfeats);
    return;
}

void initialize_feats(object who, int x)
{
    mapping featmap;
    if(!objectp(who)) return;
    if(!mapp(who->query_featmap()) || x == 1) 
    {
        featmap = (["class" : ([]), "bonus" : ([]), "hybrid" : ([]), "magic" : ([]), "other" : ([]),
        "epic" : ([]), "class_feats_gained" : 0, "bonus_feats_gained" : 0, "magic_feats_gained" : 0, "hybrid_feats_gained" : 0,
        "other_feats_gained" : 0, "epic_feats_gained" : 0]); 
        who->set_featmap(featmap);
    }
    if(!pointerp(who->query_player_feats()) || x == 1) who->set_player_feats(({}));
    return;
}

int advance_death_time(object who)
{
    if(!objectp(who)) return 0;
	if(who->query("just_been_pkilled"))
	{
		who->set("pk_death_age", who->queryplayer_age());
		who->set("pk_death_time", (time() + PK_DEATH_RL_TIME));
	}
    who->set_death_time(time() + PK_DEATH_RL_TIME);	
  	return 1;
}

int filter_autowear(string awstr, object who) 
{
    if(!objectp(who) || undefinedp(awstr) || awstr == 0) return 0;
    if (explode(awstr,"##")[1] != who->query_true_name()) return 0;
    return 1;
}

int sort_autowear(string awstr1, string awstr2)
{
    int aw1, aw2;
    if (awstr1 == 0 || awstr1 == "") return -1;
    if (awstr2 == "" || awstr2 == 0) return 1;
    aw1 =atoi(explode(awstr1,"##")[0]);
    aw2 =atoi(explode(awstr2,"##")[0]);
    if (aw1 == aw2) return 0;
    if (aw1 < aw2) return -1;
    return 1;
}

int execute_autowear(string awstr, object who)
{
    string to_force;
    if(!objectp(who)) return 0;
    if (stringp(to_force=(explode(awstr,"##")[3])) )
    {
        if (who->force_me("wear "+to_force)) return 1;
        if (who->force_me("wear "+to_force+" on "+explode(awstr,"##")[2])); return 1;
    } 
    else if (stringp(to_force=explode(awstr,"##")[2])) if ( who->force_me(to_force)) return 1;
    return 0;
}

int do_autowear(object who) 
{
    string *to_wear;
    if(!objectp(who)) return 0;
    to_wear = all_inventory(who)->query_wear_order();
    to_wear = filter_array(to_wear, "filter_autowear",TO, who);
    to_wear = sort_array(to_wear, "sort_autowear",TO);
    who->set_property("silent_equip",1);
    who->set_property("ultimate_equip",1);
    to_wear = filter_array(to_wear, "execute_autowear", TO, who);
    who->remove_property("silent_equip");
    who->remove_property("ultimate_equip");
}

void convert_to_new_class_type(object who)
{
    if(!objectp(who) || avatarp(who)) { return; }
    if(!who->query("new_class_type")) 
    {
        "/d/shadowgate/conversion/conversion1.c"->summon_me(who);
        return;
    }
    if(!who->query("new_stat_type2")) 
    {
        who->delete("new_stat_type");
        "/d/shadowgate/conversion/stats1.c"->summon_me(who);
        return;
    }
}

void make_new_hitpoint_rolls(object obj)
{
    string *classes;
    int hp=20,i,j,num,level,old,*rolls;

    if(!objectp(obj)) { return; }
    if(avatarp(obj)) { return; }
    if(!obj->query("ranger_hp_rolled") && pointerp(obj->query("hp_array")) && obj->is_class("ranger")) { obj->delete("hp_array"); }
    if(pointerp(obj->query("hp_array"))) { return; }
    
    classes = (string *)obj->query_classes();
    old = (int)obj->query_max_hp();
    
    for (i= 0;i< sizeof(classes);i++) 
    {        
        for (j=1;j<=(int)obj->query_class_level(classes[i]);j++) 
        {
            level++;
            hp += ADVANCE_D->get_hp_bonus(classes[i],obj->query_base_stats("constitution"),level,obj);
        }
    }

    hp = 20;
    rolls = (int*)obj->query("hp_array");
    for(i=0;i<(int)obj->query_character_level()+1;i++)
    {
        hp += rolls[i];
    }        

    obj->set_max_hp(hp);
    obj->set_hp((int)obj->query_max_hp());

    tell_object(obj,"%^RESET%^%^B_BLUE%^Rolling new hitpoints, old total: "+old+"\nNew "
        "total: "+(int)obj->query_max_hp()+"%^RESET%^");
    log_file("old_hitpoints","Old hitpoints for " +(string)obj->query_true_name()+": "+old+", new "
        "hitpoints "+(int)obj->query_max_hp()+"\n");
    obj->set("ranger_hp_rolled",1);
    obj->delete("new_hp_rolled");
    obj->delete("new_hp_rolled_one");
    obj->delete("new_hp_rolled_two");
    return;
}

void change_my_domains(object who)
{
    string *domains;
    if(!objectp(who)) { return; }
   if(!(who->is_class("cleric")) && sizeof(who->query_divine_domain())) 
    {
        who->set_divine_domain(({})); // reset domains now that divine can multi! Ranger/pali etc.
        tell_object(who,"%^BOLD%^%^RED%^Vaping divine domains as a non-cleric to prevent multiclass bugging.");
    }
    if(who->query("domains_changed") || !who->is_class("cleric")){ return; }
    tell_object(who,"%^BOLD%^%^RED%^There has been a shifting of domains, "+
      "and you must visit your temple to reselect your domains.  "+
      "Please see <help deities> or the individual help file for your "+
      "deity for the list of domains your deity can access.%^RESET%^");
    tell_object(who,"%^YELLOW%^NOTE: %^WHITE%^Not all deities had their "+
      "domains changed, but many of the spells within domains did "+
      "change.  Please take a few moments to review <help domains> to "+
      "see the spells listed for each domain and then review the help "+
      "file for each spell before making your choice.  Once your choice "+
      "is made, it will not be undone.%^RESET%^");
    who->set_divine_domain(({}));
    who->set("domains_changed",1);
    return;
}

void redo_my_languages(object who) 
{
    int mylang = 0;
    string race;
    race = who->query_race();

    if(!objectp(who) || avatarp(who) || who->query("new_langs_set3")) { return; }
    if(strsrch(race,"half-") != -1) 
    {
        who->set_lang("common",100);
        who->set_lang(LANGS[race][0],100);
    }
    else 
    {
        if(member_array(race,PLAYER_D->night_races()) == -1) { who->set_lang("common",100); }
        else { who->set_lang("undercommon",100); }
    }
    set("new_langs_set3",1);
  
    if(who->query("new_langs_set2")) { return; }

    if((int)who->query_lang("ogrish"))
    {
        mylang = who->query_lang("ogrish");
        who->remove_lang("ogrish");
    }
    if((int)who->query_lang("ogre-magi") > mylang) 
    {
        mylang = who->query_lang("ogre-magi");
        who->remove_lang("ogre-magi");
    }
    if(mylang) 
    {
        who->set_lang("giant",mylang);
        tell_object(who,"%^BOLD%^%^RED%^Reinitializing your languages, "
        "please contact a wiz if anything seems wrong.%^RESET%^");
    }
    who->delete("new_langs_set");
    who->set("new_langs_set2",1);
    return;
}

void new_hm_cap(object who)
{
    int posxxx;
    if(!objectp(who) || avatarp(who) || !who->query("new_hm_cap_set")) { return; }
    if(who->query("new_hm_cap_set")) 
    { 
        tell_object(who, "Non-HM level cap has been removed, effective January 20th, 2017.");
        who->delete("new_hm_cap_set");
        who->delete("no advance");
        return; 
    }
    tell_object(who,"Non-HM level cap set to level 30.");
    who->set("no advance",30);
	who->set("new_hm_cap_set",1);
    if(member_array("Quest for the Swords",who->query_quests()) == -1){ return;} 
    who->set("advanced_player",1);  
    return;
}   

void cull_levels(object who)
{
    int i, cap, current_exp, needed_exp, lost_exp, total_lost=0;
    string classes, *display=({}), info, TS_D, CMD_NOTE, player_position;

    if(!objectp(who) || avatarp(who) || who->query("advanced_player") || 
    !pointerp(classes = who->query_classes())) { return; }
    TS_D = "/daemon/treesave_d.c";
    CMD_NOTE = "/cmds/avatar/_note.c";
    if(OB_ACCOUNT->is_high_mortal(who->query_true_name())) { player_position = "high mortal"; }
    else player_position = who->query_position();    
    switch(player_position)
    {
        case "high mortal":
            cap = 100;
            tell_object(who, "%^RESET%^%^B_BLUE%^Max levels for players have been changed.  The maximum level for "
            "a single class character is now "+cap+".  Your levels and hitpoints have been adjusted accordingly.  "
            "Your lost experience has been noted.%^RESET%^");        
            break;
        case "player": case "newbie":
            cap = 100;
            if(who->query("no advance") != cap && !who->query("new_hp_rolled_two"))
            {
                info = CMD_NOTE->format_checkpoint(who->query_name(),"%^CYAN%^"+who->query_name()+"'s level cap set to "+cap+"");
                TS_D->add_value_to_array("notes",who->query_name(),capitalize(who->query_name())+", "+ctime(time())+" "+info+"");
                who->set("no advance",cap);
            }
            tell_object(who, "%^RESET%^%^B_BLUE%^You are not flagged for advanced player status, so your maximum "
            "level has been reduced in accordance with the current levelcap standards.  The new level cap "
            "for single class players who are not AP rank has been changed to "+cap+".  Your experience points "
            "and hitpoints have been reduced and your loss "
            "has been noted.  Please notify an immortal if you think this is in error.%^RESET%^");
            break;
        default:
            return;
    }
    for(i=0;i<sizeof(classes);i++)
    {
        if(who->query_class_level(classes[i]) <= cap) { continue; } 
        current_exp = who->get_general_exp(classes[i]);
        needed_exp  = ADVANCE_D->get_exp(cap+1,classes[i],who);
        lost_exp    = current_exp - needed_exp;
        total_lost  += lost_exp;
        display     += ({ " "+lost_exp+" exp in "+classes[i]+" " });
        who->add_general_exp(classes[i],(lost_exp * -1));
    }
    if(total_lost == 0) { return; }
    who->resetLevelForExp(sizeof(classes)*-1);
    info = CMD_NOTE->format_checkpoint(who->query_name(),"%^RESET%^%^BOLD%^"+who->query_name()+" lost "+implode(display,"and")+" total lost: "+total_lost+"");
    TS_D->add_value_to_array("notes",who->query_name(),capitalize(who->query_name())+", "+ctime(time())+" "+info+"");
    return;
}

void do_encumbrance(object who)
{    
    if (!objectp(who) || who->query_stats("strength") <= 0 ) return;    
    who->set_max_internal_encumbrance(MAX_ENCUMBRANCE[who->query_stats("strength")]);
    return;
}

string query_time_logged_in(object who) 
{
    int temp, hour, min, sec;
    string output, tmp;
    if(!objectp(who)) return "";
    
    temp = (time() - (int)who->query_start_time());
    hour = to_int(temp / 3600);
    temp -= (hour*3600);
    min = to_int(temp / 60);
    temp -= (min*60);
    sec = temp;
    tmp = hour+" hours, "+min+" minutes, "+sec+" seconds.";
    output = tmp;
    return output;
}

int query_down_time(object who) 
{ 
    int dt;
    if(!objectp(who)) return 0;
    dt = who->get_down_time();
    if ((dt && dt < time()) && (int)who->query_age() > ((int)who->query("down_time_age") + 28800) ) { who->remove_down_time(); }
    return dt;
}

void remove_down_time(object who) 
{ 
    if(!objectp(who)) return;
    tell_object(who, "Your PK protection from your recent return has been lifted.");
    who->delete("down_time_age");
    who->set_down_time(0);
}

void describe_current_room(object who, int verbose) 
{
    object env;
    string borg;
    mixed tmp;
    int light, bonus, flag;
    if(!objectp(who) || !objectp(env = environment(who))) return;
    bonus = who->query_sight_bonus();
    if (wizardp(who)) borg = file_name(env)+"\n";
    else borg = "";

    if (who->query_unconscious()) 
    {
        message("room_description","You have the sensation of being moved.",who);
        return;
    }
    if ((light=who->light_blind(0)) || who->query_blind()) 
    {
        if (who->query_blind()) borg += "You have been blinded and cannot see anything.";
        else if (member_array(who->query_race(),(string)PLAYER_D->night_races() ) != -1)
        {
            if (light >= 1) borg += "It is too dark to see.";
            else if (light >= -1) borg += "It is bright.";
            else if (light >= -2) borg += "It is quite bright.";
            else if (light >= -3) borg += "It is very bright.";
            else borg += "It is dazzlingly bright..";
        }
        else 
        {
            if (light >= 1) borg += "It is too bright to see.";
            else if (light >= -1) borg += "It is dark.";
            else if (light >= -2) borg += "It is quite dark.";
            else if (light >= -3) borg += "It is very dark.";
            else borg += "It is completely dark.";
        }
        message("room_description", borg, who);
        flag = 1;
    }     
    else if (who->light_blind(1) >= 1 ) borg += "It is somewhat bright.\n";
    else if (who->light_blind(1) <= -1) borg += "It is somewhat dark.\n";
    if(!flag) {
        borg += (verbose ? (string)env->query_long(0)+" " : (string)env->query_short());
        message("room_description", borg, who);
    }
    if (!verbose)
        message("room_exits", (string)env->query_short_exits(), who);
    if (verbose && stringp(tmp=(mixed)env->query_smell("default")))
        message("smell", tmp, who);
    else if (verbose && functionp(tmp))
        message("smell",(string)((*tmp)("default")), who);
    if (verbose && stringp(tmp=(mixed)env->query_listen("default")))
        message("listen", tmp, who);
    else if (verbose && functionp(tmp))
        message("listen", (string)((*tmp)("default")), who);
    if (stringp(tmp=(string)WEATHER_D->Check_Weather(who)))
        message("weather", "%^MAGENTA%^"+tmp+"%^RESET%^", TO);
    if (verbose && (tmp=(string)env->query_long_exits()) && tmp != "")
        message("room_exits", sprintf("\n%s\n", tmp), who);
    if ((tmp=(string)env->describe_living_contents(({who})))!="" && !flag)
        message("living_item", tmp, who);
    if ((tmp=(string)env->describe_item_contents(({})))!="" && !flag)
        message("inanimate_item", tmp, who);
    return;
}

varargs void move_player(object who, mixed dest, string msg) 
{
    object prev, *inv, mount;    
    string here,going,temp1,temp2,temp3;
    int i, illum, bzbd, adj, tmp;
    if(!objectp(who)) return;
    prev = environment(who);
    here = file_name(prev);
    
    if (stringp(dest)) 
    {
        if (sscanf(dest,"/%s",temp1)!=1) 
        {
            sscanf(here,"/%s",temp1);
            going = "";
            
            while (sscanf(temp1,"%s/%s",temp2,temp3)==2) 
            {
	            going = going + "/"+temp2;
	            temp1 = temp3;
            }      
            temp1 = dest;
            if (file_size(going+"/"+temp1+".c") != -1) 
            {
	            dest = going +"/"+temp1;
            }
        }
    }
  
    if (objectp(mount = who->query_in_vehicle())) { if(!mount->move_forward()) { return; } }
    if (who->query_property("posed")) who->remove_property("posed");
    if (who->move(dest) != MOVE_OK ) { tell_object(who, "You remain where you are."); return; }
    who->reset_hidden_seen();
  
    if (!hiddenp(who) && !(avatarp(who) && who->query_true_invis())) 
    {
        inv = all_inventory(prev);
        inv += all_inventory(environment(who));
        inv -= ({who});
        for (i=0, bzbd = sizeof(inv); i<bzbd; i++) 
        {
            if (!living(inv[i]) || ((who->query_hidden() || who->query_magic_hidden())  && !inv[i]->detecting_invis())) continue;   
            if (!msg || msg == "") 
            {
                if(environment(inv[i]) == prev) message("mmout", who->query_mmout(inv[i]),inv[i]);
                else message("mmin",who->query_mmin(inv[i]),inv[i]);
            }
            else 
            {
	            if (objectp(mount)) 
                {
                    if(environment(inv[i]) == prev) message("mout",who->QCN+" rides "+mount->QCN+" "+msg+".",inv[i]);
                    else message("min", who->QCN+" enters riding "+mount->QCN+".", inv[i]);
	            } 
                else    
                {
                    if(environment(inv[i]) == prev) message("mout", who->query_mout(msg,inv[i]), inv[i]);
                    else message("min",who->query_min(inv[i]),inv[i]);
                }
            }
            continue;
        }
        if (who->query_followers()) who->move_followers(prev);
    }
    who->describe_current_room(who->get_static("verbose_moves"));
    return;
}

// * New Spell Breaking Function added 10-17-2002
void break_all_spells(object who) 
{       
    object *spells_on, shape, *tmp;       
    if(!objectp(who)) return;
    if(objectp(shape = who->query_property("shapeshifted")))
    {
        shape->remove();
        who->set("relationship_profile","default");
    }
    spells_on = ({});
    if(pointerp(tmp = who->query_property("dispellable spells"))) { spells_on += tmp; }
    if(pointerp(tmp = who->query_property("spelled"))) { spells_on += tmp; }
    spells_on = distinct_array(spells_on);
    foreach(object spell in spells_on)
    {
        if(!objectp(spell)) continue;
        spell->removeSpellFromCaster();
        spell->dest_effect();
    }
    who->remove_property("dispellable spells");
    who->remove_property("spelled");                                                 
}

int quit(object who, int quit_type) 
{
    if(!objectp(who)) return 0;
    who->break_all_spells();
    who->set_hidden(0);
    who->set_magic_hidden(0);
    if (who->query_followers()) who->clear_followers();
    
    if(objectp(environment(who))) { who->set_primary_start(file_name(environment(who))); }
    else { who->set_primary_start("/d/shadow/room/pass/pass3"); }
    
    if (who->query_invis() && !wizardp(who)) who->set_invis();
    
    who->remove_stat_bonuses();
    who->save_player( who->query_name() );
    
    if(!quit_type) 
    {
        message("environment", "Please rejoin the ShadowGate adventure REAL soon!!!", who);
        log_file("enter", who->query_name()+" (quit)\n");
    //  NOTIFY_D->logon_notify("%^YELLOW%^A player leaves the ShadowGate adventure.%^RESET%^",TO);
        if(objectp(environment(who))) message("emote",who->QCN+" leaves the Shadowgate Adventure!",environment(who));
        NOTIFY_D->mud_notify("left",who);
        AVERAGE_AGE_D->register_player(who);
    }
    else  
    {
        message("environment", "You have died, it is time to leave this world!!!", who);
        if(objectp(environment(who))) message("emote",who->QCN+"'s soul has truly left this world!",environment(who));
        log_file("enter", who->query_name()+" (dead)\n");
        NOTIFY_D->logon_notify("%^YELLOW%^"+who->query_vis_cap_name()+"'s %^YELLOW%^soul has truly left this world!%^RESET%^",who);
    }   
    
    PLAYER_D->add_player_info();
    LAWBOUNTY_D->add_hm_info(who);
    //TO->move("/d/shadowgate/freezer");
    foreach(object ob in all_inventory(who)) 
    { 
        if(objectp(ob)) { ob->unequip(); }
    }
    YUCK_D->save_inventory(who);    
    foreach(object ob in all_inventory(who)) 
    { 
        if(objectp(ob)) { ob->remove(); }
    }
    if(pointerp(who->get_static("pets")))
    {   
        foreach(object ob in who->get_static("pets"))
        {   
            if(objectp(ob))
            {
                ob->move(VOID);
                if(objectp(ob)) ob->remove();
            }
        }
    }
    who->remove();
    return 1;
}

void new_body(object who) 
{
    mapping borg;
    int newmax, mylvl, flag;
    string myrace;
    if(!objectp(who)) return;
    who->init_limb_data();
    who->set_static("stage", 60);
    if (!stringp(myrace = who->query_race())) return;
    if(mylvl = (int)who->query_class_level("psywarrior")) flag = 1;
    else mylvl = (int)who->query_class_level("psion");
    if(mylvl) 
    {
        mylvl--;
        if(mylvl < 0) mylvl = 0;
        if(mylvl > 39) mylvl = 39;
        if(flag) newmax = PWPOINTS[mylvl];
        else newmax = PSIONPOINTS[mylvl];
        who->set_max_mp(newmax);
    }
    who->set_heal_rate(2);
    who->set_overall_ac(10-(int)RACE_D->query_ac(myrace));
    borg = (mapping)RACE_D->body(who);
    who->set_start_time(time());
    foreach(string limb in keys(borg))
    {
        who->add_limb(limb, borg[limb]["limb_ref"], borg[limb]["max_dam"], 0, 0);
    }
    if (member_array("neck",(string *)who->query_limbs()) == -1) who->add_limb("neck","neck",who->query_hp(),0,0);
    who->set_wielding_limbs((string *)RACE_D->query_wielding_limbs(myrace));
    who->set_fingers((int)RACE_D->query_fingers(myrace));
    who->do_encumbrance();
    who->set_attack_limbs(({"right hand","left hand","right foot","left foot","head","right elbow","left elbow","right knee","left knee"}));
    return;
}

void setup_messages(object who) 
{
    mapping tmp = ([]);
    if(!objectp(who)) return;
    who->set_static("saveable", (who->query_channels()+KEPTMESSAGES));
    foreach(string keep in (who->query_channels() + KEPTMESSAGES))
    {
        tmp[keep] = ({});
    }
    who->set_static("pastMessages", tmp);
    return;
}

void check_guilds(object who)
{
    if(!objectp(who)) return;
    foreach(string guild in who->query_guild())
    { 
        if(!GUILDS_D->is_member(guild, who->query_name())) who->remove_guild(guild);
    }
    return;
}

void setup(object who) 
{
    int holder1, holder2;
    string tmp, *myknown, myrace, mysubrace, vroom;
    object ob;
    
    if(!objectp(who)) return;
    if (!who->query_stats()) who->init_stats();
    if (!who->query_skills()) who->init_skills(0);   
    who->init_living();
    who->basic_commands();    
    who->set_ip(query_ip_name(who));    
    who->set_last_on(ctime(time()-7200-random(7201)));
    who->set_real_last_on(ctime(time()));
    who->set_static("time_of_login", time());
    who->set_static("time_of_last_logout", who->query_quit_time());
    if (who->query_quit_time() + _TWO_WEEKS_IN_SECONDS_ < time() && !avatarp(who))
    {
        who->set_down_time(time() + 604800); 
        who->set("down_time_age", who->query_age());       
    }
    else if(!avatarp(who)) who->query_down_time();          
    if (!who->query_body()) who->new_body();
    if (!who->query_birthday()) who->set_birthday(time());    
    who->do_encumbrance();
    who->set_id(({"player"}));
    who->fix_limbs();
    if (who->is_class("assassin")) 
    {
        who->set_class("thief");
        who->set_mlevel("thief",who->query_class_level("assassin"));
        who->remove_class("assassin");
        who->set_posed("thief");
    }
    if(who->query("is_assassin")) who->delete("is_assassin");
    who->register_channels();

    if (!who->query_original_site()) who->set_original_site(query_ip_number(who));
    if (!sizeof(who->query_aliases())) 
    {
        message("environment", "Resetting alias data.", who);
        who->init_aliases();
        who->force_me("alias -reset");
    }    
    who->set_property("light", -who->query_property("light"));
    myrace = who->query("race");
    if (!myrace) 
    {
        who->set_logon_notify(1);  /* default login/out messages turned on */
        who->move(ROOM_SETTER);
        tell_room(environment(who),who->QCN + " is a new ShadowGate adventurer.",who);
        NOTIFY_D->logon_notify("%^YELLOW%^"+capitalize(who->query_name())+" is a new ShadowGate adventurer.%^RESET%^",who);
    } 
    else 
    {
        if (member_array(myrace, who->query("id")) == -1) { who->add_id(myrace); }
        if(stringp(mysubrace = who->query("subrace")) && member_array(mysubrace, who->query("id")) == -1) { who->add_id(mysubrace); }
        if (myrace == "drow" && mysubrace == "ssri tel quessir") 
        {
            who->delete("subrace");
            who->set_hair_color("white"); //default settings; if they have enough charisma they can ask for custom modified. N, 1/14.
            who->set_eye_color("red");
            tell_object(who, "A sense of loss fills you, as you look down at "+
            "your once-again blackened hands, and your bone-white hair. "
            "It seems the elven high magical rite did its work...");
        }
        if (who->is_class("sorcerer")) 
        {
            if(!FEATS_D->has_feat(who,"versatile arcanist")) 
            {
                myknown = (string *)who->query_base_mastered_spells();
                if(sizeof(myknown) && member_array("sunburst", myknown) != -1) 
                {
                    who->remove_mastered_spell("sunburst");
                    tell_object(who,"Sunburst is now a mage specialty school spell and has been removed from your mastery list.");
                }
            }
        }
        if (who->is_class("mage") && (myrace == "kobold" || myrace == "voadkyn")) 
        {
            who->set_class("sorcerer");
            who->set_mlevel("sorcerer",who->query_class_level("mage"));
            who->set_guild_level("sorcerer",who->query_guild_level("mage"));
            who->set_mlevel("mage",0);
            who->set_guild_level("mage",0);
            who->remove_class("mage");
            who->set_posed("sorcerer");
            if((string)who->query("active_class") == "mage") who->set("active_class","sorcerer");
            tell_object(who,"You have been converted to a sorcerer, as your race no longer supports mages!"
            " Please see <help sorcerer>.");
        }
        if (who->is_class("antipaladin")) 
        {
            who->set_class("paladin");
            who->set_mlevel("paladin",who->query_class_level("antipaladin"));
            who->set_guild_level("paladin",who->query_guild_level("antipaladin"));
            who->set_mlevel("antipaladin",0);
            who->set_guild_level("antipaladin",0);
            who->remove_class("antipaladin");
            who->set_posed("paladin");
            if((string)who->query("active_class") == "antipaladin") who->set("active_class","paladin");
            tell_object(who,"You have been converted to the paladin class! Please see <help paladin>.");
        }
        if(FEATS_D->has_feat(who,"wild shape dragon") && !(int)who->query_epic_feats_gained()) who->set_epic_feats_gained(1);

        who->add_sight_bonus((int)RACE_D->query_sight_bonus(myrace));
        if (!who->query_primary_start()) who->set_primary_start(who->getenv("start"));
        if (who->query_property("spell_points")) holder1 = who->query_property("spell_points");
        if (who->query_property("where block")) holder2 = who->query_property("where block");
        who->remove_all_properties();
        who->set_property("where block",holder2);
        who->set_property("spell_points",holder1);
        who->set("reply",0);
        if (!stringp(tmp = who->getenv("TERM"))) who->setenv("TERM", tmp = "unknown");
        who->set_static("term_info", (mapping)TERMINAL_D->query_term_info(tmp));
        who->write_messages();
        who->set_overall_ac(10 - (int)RACE_D->query_ac(myrace));
        who->set_max_internal_encumbrance(20000);
        who->add_extra_hp((int)who->query_extra_hp() * -1); 
        YUCK_D->load_inventory(who);
        who->do_autowear();
        //who->cull_levels();
        if(who->query("new_class_type")) who->make_new_hitpoint_rolls(who);
        who->convert_to_new_class_type();
        who->change_my_domains();
        who->redo_my_languages();
        who->new_hm_cap();
        who->convert_relationships();
        if(who->query("relationship_profile") && objectp(to_object("/daemon/description_d")))
        {
            ob = new("/daemon/description_d");
            ob->set("relationship_profile","default");
            if(!ob->restore_profile_settings(who,"default")) // restore description of default profile on login
            {
                ob->initialize_profile(who);
            }
        }
        if(objectp(find_object_or_load("/daemon/feat_d.c")) && who->query("new_class_type"))
        {    
            find_object_or_load("/daemon/feat_d.c")->obsolete_feat(who);        
        }   
        who->init_feats();
        //who->load_autoload_obj(); /* Truilkan@TMI 01/18/92 MOVE THIS LINE & DIE - THORN */
        /* code for the prison and new deaths... */
        if (PERMA_DEATH_D->is_perma_deathed(who->query_name()) || (int)who->query("in_the_afterlife")) 
        {
            tmp=new(DEATH_ROOM);
            who->set_property("death_room",tmp);
            who->move(tmp);

            tell_room(environment(who),who->QCN+" joins the ShadowGate adventure in the AFTERLIFE.",who);
    //      NOTIFY_D->logon_notify("%^YELLOW%^Another player enters the ShadowGate Adventure (IN THE AFTERLIFE).%^RESET%^",this_player());
            NOTIFY_D->mud_notify("joined",who," (IN THE AFTERLIFE)");
        }    
        else if (PRISON_D->is_imprisoned(who->query_name())) 
        {
            who->move(JAIL);
            tell_room(environment(who),who->QCN+" joins the ShadowGate adventure in JAIL.",who);
    //      NOTIFY_D->logon_notify("%^YELLOW%^Another player enters the ShadowGate Adventure (IN OOC JAIL).%^RESET%^",this_player());
            NOTIFY_D->mud_notify("joined", who, "(IN OOC JAIL)");
        }
        else 
        {
            if(stringp(vroom = who->query("my_virtual_room")) && objectp(ob = VIRTUAL_ROOM_D->restore_virtual_room(vroom)) && who->move(ob) != MOVE_OK)
            {
                if(who->move(ob) != MOVE_OK) who->delete("my_virtual_room");               
            }       
            else if(!objectp(environment(who)))
            {
                who->delete("my_virtual_room");
                if (!((tmp = who->getenv("start")) && stringp(tmp) && who->move(tmp)==MOVE_OK)) who->move(ROOM_START);
                who->setenv("start", who->query_primary_start());
            }
            tell_room(environment(who),who->QCN+" joins the ShadowGate adventure.",who);
        //      NOTIFY_D->logon_notify("%^YELLOW%^Another player enters the ShadowGate adventure.%^RESET%^",this_player());
            NOTIFY_D->mud_notify("joined",who);
        }
        who->do_encumbrance();
        if (environment(who)->query_inn()) environment(who)->remove_tenant(who->query_name());
    }
    PLAYER_D->add_player_info(who);
    
    log_file("enter", who->query_name()+" (enter): "+ctime(time())+" from "+who->query_ip_name()+
    " with\n"+who->query_exp()+" exp, "+who->query_money("platinum")+" platinum, "+who->query_money("gold")+" gold, "+
    who->query_money("electrum")+" electrum, "+who->query_money("silver")+" silver, "+who->query_money("copper")+" copper\n");
    
    NEWS_D->read_news();
    if (!(PRISON_D->is_imprisoned(who->query_name()))) 
    {
        if(!who->query_body_type() && myrace != "unborn")
            who->move_player("/realms/vetri/bodyhold");
        else if(!who->query_eye_color() && myrace != "unborn")
            who->move_player("/realms/crystal/colorhold");
        else
            who->load_pets();
    }
    who->convert_kills();
    //if (who->query_property("inactive")) remove_property("inactive");
    if (who->query_invis() && !wizardp(who)) who->set_invis();
    who->setup_messages();
    who->init_mud_guilds();
    who->init_spellcaster();

    if(who->query_condition() < -100) { who->set_condition((who->qury_max_stamina()+100)); }
    who->update_channels();
    if(avatarp(who) && (int)who->query_level() > 100) 
    { 
        if(!who->query_true_invis()) { who->set_true_invis(); }
    }
    who->set_static("verbose_moves", 1);
    AVERAGE_AGE_D->register_player(who);
    return;
}

void init_mud_guilds(object who) 
{
    string *tmp, *guild, shguild;
    if(!objectp(who)) return;
    if(!pointerp(guild = who->query_guild())) { who->clear_guilds(); }
    if(!pointerp(shguild = who->query_shguild())) { who->clear_shguild(); }
    if(avatarp(who)) return;
    if(!pointerp(guild)) return;
    tmp = GUILDS_D->query_all_guilds();
    foreach(string guildname in guild)
    {
        if(member_array(guildname, tmp) == -1 || (!(int)GUILDS_D->is_member(guildname, who->query_name())))
        {
            who->remove_guild(guildname);
        }
    }
}

void init_spellcaster(object who)
{
    string theschool, *myknown;
    int i;
    if(!objectp(who)) return;
    if(!who->query("Greset_mage_sp_2K"))
    {
        who->resetMemorized();
        who->set("Greset_mage_sp_2K", 1);
    }
    if(!who->query("Greset_cl_restr"))
    {
        who->set("Greset_cl_restr", 1);
    } 
    if( (who->is_class("mage") || who->is_class("bard")) && !who->query("Greset_mage_restr"))
    {
        who->set("Greset_mage_restr", 1);
    }
    if(who->is_class("mage")) 
    {
        theschool = who->query_school();
        if(!theschool) return;
        myknown = who->query_base_mastered_spells();
        foreach(string spell in myknown)
        {
            if(member_array(spell, SCHOOLSPELLS) != -1) { who->remove_mastered_spell(spell); }
        }
    }
}

void user_heart_beat(object who) 
{
    object ewho;
    int i, max, player_age, blink, watched;
    object ob, myspl;

    if(!objectp(who)) { return; }
    if(objectp(environment(who))) ewho = environment(who);
    if(!avatarp(who) && interactive(who)) { who->count_down_timed_tax(); }
    who->adjust_player_age(2);
    player_age = who->query_player_age();
    who->adjust_ok_to_heal(2);
    if (who->query_property("fled") < time()) { who->remove_property("fled"); }
    if (who->query_property("PKfled") < time()) { who->remove_property("PKfled"); }
    if (who->query_property("lay_on_hands_delay") > 0) { who->set_property("lay_on_hands_delay",-1); }
    if (who->query_property("cause_wrack_delay") > 0) { who->set_property("cause_wrack_delay",-1); }
    if (who->query_disable()) who->iterate_disable();
    who->iterate_combat();
    who->query_down_time();
    if(who->get_pk_death_flag())
	{
        if(!(int)who->query("pk_death_age")) { who->set("pk_death_age", player_age); }
        if(!(int)who->query("pk_death_time")) { who->set("pk_death_time", (time() + PK_DEATH_RL_TIME)); }
        if(player_age > ((int)who->query("pk_death_age") + PK_DEATH_FLAG_LOGIN_TIME) && time() > (int)who->query("pk_death_time"))
        {
            who->remove_pk_death_flag();
        }
    }
    if (player_age > who->get_static("autosave")) 
    {
        if (!wizardp(who)) message("environment", "Autosaving.", who);
        if(objectp(environment(who))) { who->set_primary_start(file_name(environment(who))); }
        else { who->set_primary_start("/d/shadow/room/pass/pass3"); }
        who->save_player(who->query_name());
        YUCK_D->save_inventory(who);
        who->set_static("autosave", player_age + 500);
    }
    // adding signals that they are getting hungry and thirsty *Styx*  12/04/04
    max = who->query_formula();
    if(!random(100) && !avatarp(who)) 
    {  // don't give a message every time
        if(who->query_stuffed() < (max / 6)) 
        {
            tell_object(who, "You notice some hunger pangs and your stomach growls.");
            if(!random(3)) { if(objectp(ewho)) { tell_room(ewho, who->QCN+"%^RESET%^'s stomach is growling from hunger.", who); } }
        }
        if(who->query_quenched() < (max / 6)) 
        {
            tell_object(who, "Your mouth is dry and you're feeling parched from thirst.");
            if(!random(5)) { if(objectp(ewho)) { tell_room(ewho, who->QCN+" %^RESET%^ is looking parched from thirst."); } }
        }
    }
    if (!who->get_static("stage"))
    {
        if (!wizardp(who) && who->query_level() > 1) 
        {
            ob = new("/std/Object");
            if (!who->query_stuffed() && !ewho->query_property("no starve") && random(2))
            {                
                ob->set_name("Hunger");
                who->do_damage("torso",roll_dice(2,who->query_level()/2));
                message("environment","You are getting weaker from Starvation!",who);
                who->add_attacker(ob);
                who->continue_attack();
                who->remove_attacker(ob);
            }
            if (!who->query_quenched() && !ewho->query_property("no starve") && !random(2))
            {
                ob->set_name("Thirst");
                who->do_damage("torso",roll_dice(2,who->query_level()/2));
                message("environment","You are getting weaker from Thirst!",who);
                who->add_attacker(ob);
                who->continue_attack();
                who->remove_attacker(ob);
            }
            if(objectp(ob)) ob->remove();
        }
        who->set_static("stage", 60);
    } 
    who->set_static("stage", ((int)who->get_static("stage") - 1));
    
    if (who->query_dying() > 0) 
    {
        who->reduce_dying();
        message("environment","You are slowly slipping closer to death.",who);
        if (who->query_dying() <= 0) 
        {
            message("environment","You have finally died.",who);
            who->dying();
            return;
        }       
    }
    if (who->ok_to_attack()) { who->continue_attack(); }
    if (who->query_parrying() && (!sizeof(who->query_wielded())) && !FEATS_D->usable_feat(who, "unarmed parry")) 
    {
        tell_object(who, "You no longer have a weapon wielded, so you let down your defenses.");
        who->set_parrying(0);
    }    
    if (who->query_property("dodging") && !sizeof(who->query_attackers())) 
    {
        tell_object(who, "With combat over, you have no one to dodge.");
        who->remove_property("dodging");
    }
    
    if ((blink = who->get_static("blinking")))
    {
        if(blink < 0) blink++;
        else blink--;
        who->set_static("blinking", blink);
        if(!who->get_static("blinking"))
        {            
            while(objectp(myspl = MAGIC_D->get_spell_from_array(who->query_property("spelled"), "blink")))
            {
                who->remove_property_value("spelled", ({myspl}));
                myspl->dest_effect();
            }
        }
    }
    if (who->query_disable() &&  (!(ob=who->query_current_attacker()))) { who->remove_disable(); }
    if (player_age > who->query_ok_to_heal()) who->do_healing(who->calculate_healing());
    else who->calculate_healing();
    if(interactive(who) && (query_idle(who) >= 5400) && (!avatarp(who)) && (!who->query("test_character")) ) 
    {
        MESSAGING_D->avatars_message("notify","%^BOLD%^Imm: %^YELLOW%^<< "+who->query_name() + " has idled out. ["+who->query_time_logged_in()+"] >>%^RESET%^", ({ }) );
        who->force_me("quit");
        return;
    }
    if(interactive(who) && (query_idle(who) >= 600) && (!avatarp(who)) && (!who->query("test_character")))
        who->force_me("inactive");
    if (!sizeof(who->query_attackers()) && who->query("protecting")) who->set("protecting",0);
    if ((watched = who->get_static("watched")) && !who->is_class("barbarian")) watched--;
    else if(who->is_class("barbarian") && watched < who->query_class_level("barbarian") * 2) watched = who->query_class_level("barbarian") * 2;
    who->set_static("watched", watched);    
    if(who->query_offensive_bonus())
    {
        if(who->get_static("stance") > 120) 
        {
            who->reset_offensive_scale();
            tell_object(who, "%^BOLD%^You relax your stance.");
            tell_room(ewho, "%^BOLD%^"+who->QCN+" relaxes "+who->QP+" stance.",who);
            who->set_static("stance", 0);            
        }
        if (sizeof(who->query_attackers()) == 0) who->set_static("stance", ((int)who->get_static("stance") + 1));
        else who->set_static("stance", 0);
    }
    
    if(objectp(who) && (FEATS_D->usable_feat(who, "regeneration") || who->query_race() == "shade"))
    {
        if(who->query_hp() < who->query_max_hp()) { who->add_hp((roll_dice(1,6)+roll_dice(1,BONUS_D->query_stat_bonus(who, "constitution")))); }
    }
    if(objectp(who) && sizeof(who->query_attackers())) 
    {
        if(who->query_property("stabs_available")) who->remove_property("stabs_available");
        if(FEATS_D->usable_feat(who,"combat reflexes")) 
        {
            i = ((int)who->query_class_level("thief")+9)/10;
            who->set_property("stabs_available",i);
        }
    }
    return;
}

void net_dead2(object who) 
{ 
    if(objectp(who)) 
    {
        MESSAGING_D->avatars_message("notify","%^BOLD%^Imm: %^YELLOW%^<< "+who->query_name() + " has disconnected and quit. "+
        "["+who->query_time_logged_in()+"] >>%^RESET%^", ({ }) );
        who->force_me("quit"); 
    }
    return;
}
//since I am changing net_dead to basically work like quit - so that HOPEFULLY people who 
//get disconnected do not end up losing their gear/etc, then this function is irrelevant - Saide
void restart_heart() { return; }

void resetLevelForExp(object who, int expLoss)
{
    mapping my_levels;
    string *classes,curclass,myclass,active_class;
    int i, hp_loss,*rolls,tmp;
    if(!objectp(who)) return;
    if (expLoss) 
    { 
        log_file("resetLevelForExp",identify(previous_object(-1))+" needs to consider using general_exp_adjust_perc() function?\n");
    }

    who->add_exp(expLoss);
    
    if(who->query("new_class_type"))
    {
        if(active_class = (string)who->query("active_class"));
        {
            if(member_array(active_class,(string *)who->query_classes()) == -1)
            {
                tell_object(who, "Your active_class is set to a class that you do not currently have, "
                    "please notify an immortal immediately.");
                return;
            }

            my_levels = who->query_levels();

            while((int)EXP_NEEDED[who->query_character_level()] > who->query_exp() && (my_levels[active_class] > 1))
            {
                	hp_loss = ADVANCE_D->get_hp_bonus(active_class, who->query_base_stats("constitution"),who->query_base_character_level(),who);
                	who->set_mlevel(active_class,who->query_class_level(active_class) - 1);                  
                	rolls = (int*)who->query("hp_array");
                	tmp = 20;
                	for(i= 0 ; i < who->query_base_character_level()+1; i++)
                	{
                 		tmp += rolls[i];
                	}
                    who->set_max_hp(tmp);

                    who->reduce_my_skills(active_class);
                    who->reduce_guild_level(active_class);
                	NWP_D->reduce_player(who,active_class,who->query_class_level(active_class));
            }

        }

        who->setenv("TITLE", (string)ADVANCE_D->get_new_title(who));
        return;
    }    

    if(myclass = who->get_dual_class()) { classes = ({ myclass }); }
    else { classes = who->query_classes(); }
    for (i=0;i<sizeof(classes);i++) 
    {
        curclass = classes[i];
        while ((int)ADVANCE_D->get_exp(who->query_class_level(curclass),curclass, who) > (who->get_general_exp(curclass))) 
        {
            hp_loss = ADVANCE_D->get_hp_bonus(curclass,who->query_base_stats("constitution"),who->query_class_level(curclass),who);
            who->set_mlevel(curclass,who->query_class_level(curclass)-1);
            who->set_max_hp(who->query_true_max_hp() - hp_loss);
            who->reduce_my_skills(curclass);
            who->reduce_guild_level(curclass);
            NWP_D->reduce_player(who,curclass,who->query_class_level(curclass));
        }
    }
    who->setenv("TITLE", (string)ADVANCE_D->get_new_title(who));
}

void die(object who) 
{
    object ob, corpse, money_ob, *stuff, klr,*keeping=({}),*debind=({}), ewho;
    string *currs,curclass, seen, msg_death, reztype;
    int tmp, hp_loss, i,j, room,num;
    if(!objectp(who) || who->query_ghost()) return;
    if (wizardp(who) && !who->query_killable() ) 
    {
        message("death", "You are immortal and cannot die.", who);
        who->set_hp(who->query_max_hp());
        return;
    }
    klr = who->query_current_attacker();
    if ( (objectp(klr)) && (klr->is_guardsman()) ) // Added to remove local bounties if a guard kills the player -Ares 8/29/05
    {
        klr->remove_fines_and_bounties(who);
    }    
    if (objectp(ewho = environment(who)) && ewho->query_property("arena")) 
    {
        if (wizardp(klr) || !objectp(klr) || (!interactive(klr) && !klr->query_property("rabid mon") ) ||
        (who->query_property("safe arena") && klr->query_property("safe arena")) ||
        environment(klr)->query_property("arena entrance") ) 
        {
            object *arenaman;
            tell_object(who,"You have been defeated in combat.");
            tell_room(ewho,who->QCN+" has been defeated in combat.",who);
            who->set_hp(who->query_max_hp());
            who->reset_all_status_problems();
            who->cease_all_attacks();
            if (who->query_property("arena allowed")) who->remove_property("arena allowed");
            if (who->query_property("safe arena")) who->remove_property("safe arena");
            if (room = ewho->query_property("deathmove")) who->move_player(room);
            return;
        }
    }
    who->set_ghost(1);
    ob = who;
    who->set_static("died here", ewho);
      
    if(objectp(who) && !avatarp(who) && (int)who->query_character_level() > (int)who->query("death level"))
    {
        who->set("death level",(int)who->query_character_level());        
    }
    who->set_death_age(who->query_player_age());
    while(present("corpse",who))
    {
        if(objectp(ewho)) { present("corpse",who)->move(ewho); }
        else { break; }
    }
    if(who->query_property("rebirth") || who->query_property("foresight"))
    {
        if(who->query_property("rebirth")) reztype = "rebirth";
        if(who->query_property("foresight")) reztype = "foresight";
        who->cease_all_attacks();
        if(objectp(klr)) klr->cease_all_attacks();
        who->reset_all_status_problems();
        who->break_all_spells();
        who->remove_stat_bonuses();
        who->set_in_vehicle(0);
        if(who->query_property("rally")) who->remove_property("rally");
        ob = new("/d/magic/obj/rebirther");
        ob->set_reztype(reztype);
        ob->move(who);
        return;
    }
    message("death", "You die.\nYou feel the sensations of nothingness " +
    "as you rise above your corpse.\nYou arrive at a destination in a reality " +
    "not like your own.", who);
    if (!avatarp(who) || !who->query_disguised()) seen = who->getParsableName();
    else seen = who->query_vis_name();
    
    switch(random(12)+1) 
    {
        case 1:
            msg_death="%^BOLD%^%^RED%^The fires of hell blaze with an unholy light as "+seen+" succumbs to death's grip!";
            break;
        case 2:
            msg_death="%^BOLD%^%^BLUE%^A wave of bitter sorrow washes over you as "+seen+" passes from the realms and into the afterlife!";
            break;
        case 3:
            msg_death="%^BOLD%^%^RED%^"+seen+"'s death brings to you the harsh realization that survival of the fittest has become a reality at Shadowgate!";
            break;
        case 4:
            msg_death="%^BOLD%^%^MAGENTA%^"+seen+" lets out a final scream of agony as the Grim Reaper removes "+who->query_possessive()+" soul!";
            break;
        case 5:
            msg_death="%^BOLD%^%^RED%^The Grim Reaper lays down the Welcome Mat and greets "+seen+" with open arms!";
            break;
        case 6:
            msg_death="%^BOLD%^%^CYAN%^The funeral bells begin to chime as "+seen+"'s life comes to an abrupt halt!";
            break;
        case 7:
            msg_death="%^BOLD%^%^BLUE%^A dark shadow passes overhead as "+seen+"'s soul is whisked up into the heavens!";
            break;
        case 8:
            msg_death="%^BOLD%^%^RED%^All the demons of the Abyss gather happily together as "+seen+"'s death brings them a new soul to torment for eternity!";
            break;
        case 9:
            msg_death="%^BOLD%^%^CYAN%^A new gravestone is carved from pure marble and placed beside "+seen+"'s fresh grave!";
            break;
        case 10:
            msg_death="%^BOLD%^%^GREEN%^The citizens of the land suddenly wonder what great foe was responsible for "+seen+"'s untimely demise!";
            break;
        case 11:
            msg_death="%^BOLD%^%^GREEN%^The thieves of the land suddenly wonder where "+seen+"'s corpse might be found!";
            break;
        default:
            msg_death="%^BOLD%^%^RED%^Death hast taken "+seen+" from our midsts!";
            break;
    }
    MESSAGING_D->first_death_message( "death",msg_death,all_inventory(ewho), ({ who }) );
    MESSAGING_D->handle_death_messages(who, who->query_property("watching_death_objects"), who->query("watching_death_objects"));
    
    corpse = new(OB_CORPSE);
    corpse->set_name(capitalize(seen));    
    corpse->add_id("corpse of "+who->query_vis_name()); // adds name to corpse ids -Ares 8/29/05-
    corpse->copy_body(who);
    corpse->move(ewho);
    corpse->set_true_name(who->query_true_name());
    corpse->set_was_user(1);
    who->cease_all_attacks();
    who->reset_all_status_problems();
    who->break_all_spells();    
    DEATH_EFFECTS_D->death_notification(who);
    if(objectp(klr) && klr->is_player() && who->is_player()) 
    {
        who->set("just_been_pkilled",1); // new to hopefully prevent missing PKflags.
        who->remove_all_pets(); // please only remove mounts on PK death now. N, 12/12.
    }	
  	if (!newbiep(who) && CONFIG_D->check_config("death") == 0)
	{
		money_ob = new("/std/obj/coins");
		currs = who->query_currencies();
		for (i=0, tmp= sizeof(currs); i<tmp; i++) 
        {
            money_ob->set_money(currs[i], who->query_money(currs[i]));
            who->add_money(currs[i],-who->query_money(currs[i]));
            money_ob->set_property("died time",time());
	    }
        money_ob->move(corpse);
        stuff = all_inventory(who);        

        if((objectp(klr)) && !klr->is_player() && who->is_player()) 
        {
            num = (sizeof(stuff)*10)/100;  // the *10 is the percent of stuff they keep, so 10% currently -Ares
            if(num && sizeof(stuff)) 
            {
                i=0; // just in case somehow the only items they have are death keep, it'll stop after a while
                while(sizeof(keeping) != num && i<50) 
                {
                    i++;
                    ob = stuff[random(sizeof(stuff))];
                    if(!ob->query_property("monsterweapon") || !ob->query_property("death remove") || !ob->query_property("death keep")) 
                    {
                        keeping += ({ ob });
                        keeping = distinct_array(keeping);
                    }
                }
            }
		}       
		for (i=0;i<sizeof(stuff);i++) 
        {
            if (!objectp(stuff[i])) continue;
	        if(member_array(stuff[i],keeping) != -1)
            { 
                if(!objectp(stuff[i])) { continue; }
                if (stuff[i]->is_armor() && stuff[i]->query_worn()) { stuff[i]->set_not_equipped(); }
                if (stuff[i]->query_wielded()) { stuff[i]->set_not_inhand(); }
                continue; 
            }
            if(!objectp(stuff[i])) continue; // need this check now for self-vaping weapons on unwield. N, 3/16.
            if (stuff[i]->query_property("monsterweapon") || stuff[i]->query_property("death remove"))	
            {
                stuff[i]->remove();
                continue;
      		}
            if (stuff[i]->query_property("death keep")) continue;
      		if(stuff[i]->query_item_owner_prop("death_clear")) { stuff[i]->clear_item_owners(); }
            else if(stuff[i]->query_item_owner_prop("death_remove")) { stuff[i]->remove_item_owner(TO->query_name()); }
      		if (!stuff[i]->drop()) stuff[i]->move(corpse);
            if(!objectp(stuff[i])) continue; // need this check now for self-vaping weapons on unwield. N, 3/16.
            if(stuff[i]->query_property("soulbound")) 
            { // need to remove binding on death AFTER drop check; players must replace the binding. N, 4/15.
                stuff[i]->remove_property("soulbound");
                if(stuff[i]->is_sheath()) 
                {
                    debind = all_inventory(stuff[i]);
                    if(sizeof(debind)) debind[0]->remove_property("soulbound");
                }
            }
            stuff[i]->set_property("died time",time());
            continue;
		}
  	}  
	else 
    {
        stuff=all_inventory(who);
		for (i=0;i<sizeof(stuff);i++) 
        {                       
            if (stuff[i]->is_armor() && stuff[i]->query_worn()) stuff[i]->set_not_equipped();            
            if (stuff[i]->query_wielded()) stuff[i]->set_not_inhand();
            if(!objectp(stuff[i])) continue;
            if(CONFIG_D->check_config("death") == 1 && !newbiep(who)) 
            {
                stuff[i]->set_overallStatus((int)stuff[i]->query_overallStatus()/2);
            }
    	} // do unequipping...
	 } // end newbie else.
    //End of Item Removal Code - Saide

    who->set_in_vehicle(0);
    who->move("/d/shadowgate/death/death_room");
    if(who->query_property("rally")) who->remove_property("rally");
    who->save_player( who->query_name() );
    PLAYER_D->add_player_info();
    FEATS_D->update_usable(who);
    return;
}

void write_messages(object who) 
{
    string myname;
    mapping mail_stat;
    int i, dt;
    
    if(!objectp(who)) return;
    message("login", sprintf("\n        >>> Terminal currently set to %s <<<", who->getenv("TERM")), who);
    who->force_me("bboard info");
    tell_object(who,"\n");
    myname = who->query_name();
    mail_stat = (mapping)LOCALPOST_D->mail_status(myname);
    if (mail_stat["unread"]) 
    {
        message("login", sprintf("\n        >>> %d of your %d %s are unread! <<<", mail_stat["unread"], mail_stat["total"], (mail_stat["total"]>1 ? "letters" : "letter")), who);
    }
    if (who->query_invis()) message("login", "        You are currently invisible.", who);
    if (wizardp(who)) 
    {
        if (file_exists("/log/errors/"+myname))
            message("login", "\n        >>> You have errors in /log/errors/"+myname+" <<<", who);
        if (file_exists("/log/reports/"+myname))
            message("login", "\n        >>> You have reports in /log/reports/"+myname+" <<<", who);
    }
    if ((dt = who->query_down_time())) 
    {
        message("login", 
@GARRETT
%^YELLOW%^You've been away for more than two weeks! We've given you a temporary PK 
protection to help you get back in the game, it will expire 
in 7 calendar days and eight hours of play time, unless you are away for another two weeks...
GARRETT
     , who);
        if (who->get_static("down_time") != dt)
        {
            message("login", "%^ORANGE%^... PK downtime adjusted again.", who);
            message("login", "%^GREEN%^PK Downtime ends at: "+ctime(dt), who);
        }
    }
    return;
}

string query_title(object who) 
{
    string str, mod = "", foo, fii, known;    
    if(!objectp(who)) return "";
    if (who->query_ghost()) mod = "A ghost of ";    
    if(who->query_death_flag())
        mod = "%^BOLD%^%^RED%^D %^GREEN%^" + mod;
    if(who->get_pk_death_flag())
        mod = "%^BOLD%^%^MAGENTA%^PK %^GREEN%^" + mod;
    if (newbiep(who)) 
        mod = "%^BOLD%^%^CYAN%^N %^GREEN%^" + mod;
    
    else if(objectp(TP) && (TP->knownAs(who->query_true_name()) || wizardp(TP) && TP->query("AlwaysSeeRealNames"))) 
    {
        if(wizardp(who) || (wizardp(TP) && TP->query("AlwaysSeeRealNames"))) { known = who->query_name(); } 
        else { known = TP->knownAs(who->query_true_name()); }
    } 
    else 
    {
        if(wizardp(who)) { known = who->query_name(); } 
        else known = who->knownAs(who->query_true_name());
    }
    if(stringp(known)) str = mod + capitalize(known)+", "+who->getWholeDescriptivePhrase();
    else str = mod + who->getWholeDescriptivePhrase();
    
    if( wizardp(who) && who->query("wiz titles") )
    {
        str = who->getenv( "TITLE" );
        if ( !str ) 
        {
            str = mod + capitalize(known);
        } 
        else 
        {
            if( !sscanf(str, "%s$N%s", foo,fii) )
                str = mod + capitalize(known) + " " + str;
            else
                str = mod + substr( str, "$N", capitalize(known));
        }
    } 
    return str;
}

string query_short(object who) 
{
    string str,*short_info=({}), descr = "";
    int i;
    if(!objectp(who)) return "";
    if (interactive(who) && who->get_static("disguised")) descr = who->query_disguise();
    else if (interactive(who) && !who->get_static("disguised")) descr = who->query_title();
    else if (!interactive(TO)) descr = (who->query_title() + " (link-dead)");
    if(who->query_unconscious() || who->query_asleep() || who->query_bound() || who->query_tripped() ||
    who->query_gagged() || who->query_blindfolded() || who->query_paralyzed())
    {
        descr += " (";
        if (who->query_unconscious() && !who->query_asleep()) descr = descr + " unconscious";
        if (who->query_asleep()) { descr = descr + " asleep"; }
        if (who->query_bound()) { descr = descr + " bound"; }
        if (who->query_tripped()) { descr = descr + " prone"; }
        if (who->query_gagged()) { descr = descr+ " gagged"; }
        if (who->query_blindfolded()) { descr = descr + " blindfolded"; }
        if (who->query_paralyzed()) {  descr = descr + " immobile"; }
        descr += " ) ";
    }
    if (who->query_property("inactive")) { descr = descr + " %^RESET%^%^RED%^[INACTIVE]%^RESET%^"; }
    if (who->in_edit() || who->in_input()) { descr = descr + " %^BOLD%^%^CYAN%^*in edit*%^RESET%^"; }
    if (who->query_property("working")) { descr = descr + " %^CYAN%^("+who->query_property("working")+")%^RESET%^"; }
    if (who->query_property("added short"))
    {
        short_info = (string *)who->query_property("added short");
        if(pointerp(short_info)) foreach(string mod in short_info) { descr += mod; }
    }
    if(who->query_property("posed")) descr = descr + " %^YELLOW%^[%^RESET%^"+who->query_property("posed")+"%^YELLOW%^]%^RESET%^";
    return descr;
}

int set_position(object who, string pos)
{
    if(!objectp(who) || !stringp(pos) || pos == "" || pos == " ") { return 0; }
    pos = lower_case(pos);
    switch(pos)
    {
        case "newbie":
        case "player":
        case "advanced player":
        case "high mortal":
            break;
        default:
            if(member_array(to_object("/cmds/adm/_xmote.c"), previous_object(-1)) == -1 && 
            member_array(to_object("/cmds/adm/_avmaker.c"), previous_object(-1)) == -1)
            {
                log_file("position_change","%^RED%^"+identify(previous_object(-1))+" tried to change "+who->query_true_name()+"'s "
                "position to "+pos+"\n");
                return 0;
            }
            break;
    }
    if(objectp(PO)) { log_file("position_change",""+identify(previous_object(-1))+" changed "+who->query_true_name()+"'s position to "+pos+".\n"); }
    return 1;
}

mixed receive_message(object player, string msg_class, string msg) 
{
    string *words, str, pre, post, intro, who, blah, blah2, known,the_lang,tmp="",temp, omsg, pname;
    int i, max, x, do_wrap,first_words,second_words;
    function fp;
    object ob;
    mapping TermInfo;
    if(!objectp(player)) return;
    
    while(sscanf(msg,"%s$&$%s$&$%s",blah,who,blah2) > 1) 
    {
        if(!stringp(who)) { error("bad message "+msg); }         
        if (!avatarp(player) && player->query_blind() && objectp(ob=find_player(lower_case(who))) && (!wizardp(ob)) )
        {
            known = "Someone";
        }
        else 
        {            
            if(!avatarp(player)) 
            { 
                if(objectp(ob) && wizardp(ob)) known = capitalize(ob->query_true_name());
                else known = player->knownAs(who); 
            }
            else { known = capitalize(who); }            
            if(!known)
            {
	            ob = find_player(lower_case(who));
	            if(!objectp(ob) || wizardp(ob) || avatarp(player)) 
                {
                    if(wizardp(ob)) known = capitalize(USERCALL->user_call(who, "query_name"));
	                else known = USERCALL->user_call(who,"getWholeDescriptivePhrase");
	                if(!stringp(known)) known = capitalize(who);
	            } 
                else 
                {
                    if(objectp(ob) && wizardp(ob)) known = capitalize(who);
	                else known = capitalize(ob->getWholeDescriptivePhrase());
	            }
            }
            else { known = capitalize(known); }
        }    
        msg = replace_string(msg, "$&$"+who+"$&$",known);  
    }    
    //msg += "who = "+who + " and msg_class = "+msg_class;
    switch (msg_class) 
    {
        case "room_exits": 
            msg = "%^BOLD%^%^CYAN%^"+msg; 
            break;
        case "smell": 
            msg = "%^ORANGE%^"+msg; 
            break;
        case "listen": 
            msg = "%^GREEN%^"+msg; 
            break;
        case "tell": 
            if (sscanf(msg, "%s:%s", pre, post) == 2)
            msg = "%^BOLD%^RED%^"+pre+":%^RESET%^"+post;
            break;
        case "shout": 
            if (sscanf(msg, "%s:%s", pre, post) == 2)
            msg = "%^BOLD%^BLUE%^"+pre+":%^RESET%^"+post;
            break;
        case "mmin": case "min": case "mmout": case "mout":
            msg = "%^BOLD%^GREEN%^"+msg; 
            break;
        case "living_item": case "Nliving_item":
            msg = "%^BOLD%^RED%^"+msg; 
            break;
        case "inanimate_item": case "Ninanimate_item": 
            msg = "%^BOLD%^MAGENTA%^"+msg; 
            break;
        case "animal_emote":
            msg = "%^RESET%^%^YELLOW%^"+msg;
            break;
        case "emote":
        if(objectp(TP))
        {
            words = explode(msg,"#@&");
		    //safeguard to see if this fixes shutdown problem which uses emote to deliver the message that you quit - Saide
            ob = find_player(who);   
            if(objectp(ob)) the_lang = (string)ob->query_spoken();  
            else if(objectp(TP)) the_lang = (string)TP->query_spoken();  
            else if(objectp(player)) the_lang = (string)player->query_spoken();
		    else the_lang = "common"; 

            if(sizeof(words))
            {
                for(i=0;i<sizeof(words);i++)
                {
                    if(i%2 == 0)
                    {
                        tmp += words[i];
                    }
                    else
                    {
                        if(words[i] == "mumbles through the gag" && player != TP)
                        {
                            tmp += "\""+words[i]+"\"";
                        }
                        else
                        {
                            if(member_array(the_lang,ANIMAL_LANGS) != -1)
                            {
                                if(objectp(ob)) temp = LANGUAGE_D->animal_translate(words[i],the_lang,ob);
                                if(stringp(temp)) temp = LANGUAGE_D->animal_translate(temp,the_lang,player);
                                else temp = LANGUAGE_D->translate(words[i], the_lang, player);
                            }
                            else
                            {
                                if(objectp(ob)) temp = LANGUAGE_D->translate(words[i], the_lang, ob);
                                if(stringp(temp)) temp = LANGUAGE_D->animal_translate(temp,the_lang, player);
                                else temp = LANGUAGE_D->translate(words[i], the_lang, player);
                            }                        
                            tmp += "\""+temp+"\"";
                        }
                    }
                }
            }
            msg = tmp;
        }
        break;
    }    
    if(!stringp(str=player->getenv("SCREEN"))) { str = "75"; }
    omsg = msg;
    x = atoi(str);
    if (msg_class[0] == 'N') { msg_class = msg_class[1..sizeof(msg_class)-1]; }  
    else if (msg_class != "prompt") 
    { 
        TermInfo = "/daemon/user_d.c"->myTerm(player);
        msg = terminal_colour(msg + "%^RESET%^\n", TermInfo, x, 0);
    }
    if (msg_class == "system" || msg_class == "more") 
    {
        TermInfo = "/daemon/user_d.c"->myTerm(player);
        msg = terminal_colour(msg + "%^RESET%^\n", TermInfo, x, 0);
        return msg;
    }  
    if (player->query_blocked(msg_class) && member_array(msg_class, OVERRIDE_IGNORE_MSG) == -1) { return; }
    if (msg_class == "say" || msg_class == "whisper" || msg_class == "reply" || msg_class == "party" || msg_class == "honey" || msg_class == "tell") 
    {
        if(sscanf(msg,"%s:%s:%s",intro, pname, str) != 3 && msg_class == "tell")
        {
            msg = msg;
        }
        else 
        {
            if(msg_class != "tell") sscanf(msg,"%s:%s",intro,str);
            ob = find_player(who);   
            if(!objectp(ob) && msg_class == "tell") the_lang = "wizish";
            else if(objectp(ob)) the_lang = (string)ob->query_spoken();  
            else if(objectp(TP)) the_lang = (string)TP->query_spoken();  
            else if(objectp(player)) the_lang = (string)player->query_spoken();
            else the_lang = "common"; 
            if(player->query_property("understand_all_langs") || wizardp(player)) { str = str; }
            else if(objectp(ob) && FEATS_D->usable_feat(ob, "tongue of the sun and moon")) { str = str; }
            else
            {       
                if(member_array(the_lang,ANIMAL_LANGS) == -1)            
                { 
                    if(objectp(ob) && !FEATS_D->usable_feat(player, "tongue of the sun and moon")) str = LANGUAGE_D->translate(str, the_lang, ob);
                    str = LANGUAGE_D->translate(str, the_lang, player);
                    if(stringp(pname) && msg_class == "tell") msg = intro+":"+pname+":"+str+"\n";
                    else msg = intro+":"+str+"\n"; 
                }
                else 
                { 
                    first_words = sizeof(explode(str," "));
                    if(objectp(ob) && !FEATS_D->usable_feat(TO, "tongue of the sun and moon")) str = LANGUAGE_D->animal_translate(str,the_lang,ob);
                    str = LANGUAGE_D->animal_translate(str, the_lang, TO);
                    second_words = sizeof(explode(str," "));

                    if(second_words >= first_words) // understood everything
                    {
                        if(stringp(pname) && msg_class == "tell") msg = intro+":"+pname+": ("+the_lang+") "+str+"\n";
                        else msg = intro+": ("+the_lang+") "+str+"\n"; // exactly like normal language
                    }
                    else if(!second_words && player != TP) // understood nothing
                    {
                        msg = "%^MAGENTA%^You think "+known+" was trying to communicate, but you couldn't understand.\n";
                    }
                    else if(player != TP)
                    {
                        msg = "%^MAGENTA%^You think "+known+" was trying to say ("+the_lang+"):%^RESET%^ "+str+"\n";
                    }
                } // animal languages are handled differently -Ares
            }
        }
//Next three lines Added by Lujke to make it possible to make 
// players obey commands when drugged - also see obey_command func
        if (player != ob && player->query_property("compliant"))
        {
            //call_other("obey command", )
            //call_out("obey_command", 1, str, player); 
        } 
    }
        
    if (msg_class == "reading") 
    {
        ob = previous_object(1);
        msg = LANGUAGE_D->translate(msg,ob->query_language(),player,1) + "\n";
    }
    
    if (!player->get_static("term_info")) { player->reset_terminal(); }
  
    for (i=0, max=sizeof(words=explode(msg, "%^")); i<max; i++)
    {
        if (player->get_static("term_info")[words[i]]) 
        {
            words[i] = player->get_static("term_info")[words[i]];
        }
    }
    if (player->query_unconscious() && (member_array(msg_class, OVERRIDE_IGNORE_MSG) == -1 || msg_class == "say")&& !avatarp(player)) 
    {
        string name;
        if (msg_class == "tell") 
        {
            if (objectp(environment(player))) 
            {
	            name = base_name(environment(player));
	            if (name[0..18] != "/d/shadowgate/death") { return 0; }
            }
        } 
        else { return 0; }
    }
  
    player->save_messages(msg_class, omsg);
    return (implode(words, "")+player->get_static("term_info")["RESET"]);
}

void set_primary_start(object who, string str) 
{
    object ob;
    string file;
    if(!objectp(who)) return;
    if (!(ob = find_object_or_load(str))) return;
    if(!clonep(ob)) 
    {
        if((string)who->query("my_virtual_room")) 
        {
            VIRTUAL_ROOM_D->remove_from_room_info((string)who->query("my_virtual_room"), who);
        }
    }
    if (clonep(ob)) { if(!virtualp(ob)) { VIRTUAL_ROOM_D->register_virtual_room(ob); return; } }
    if ( base_name(ob) == ROOM_FREEZER ) return;
    if ( base_name(ob) == "/d/shadowgate/void" ) return;        
    if (base_name(ob) == JAIL ) return;
    who->setenv("start",str);   
}

void revive(object who, int xploss) 
{
    float faithless;
    if(!objectp(who)) return;
    if(!who->query_diety() || (string)who->query_diety() == "pan") 
    {
        faithless = xploss * 1.5;
        xploss = to_int(ceil(faithless));
    }
    who->delete("just_been_pkilled");
    if (intp(xploss) && (xploss < 0))
    if((int)CONFIG_D->check_config("death") == 0) 
    {
        who->general_exp_adjust_perc(xploss);
        who->remove_XP_tax("death");
    }
    else if((int)CONFIG_D->check_config("death") == 1) who->set_XP_tax(0, 0, "death"); 
    message("my_action", "You return from the dead!", who);
    who->remove_property("stomached_kits");
    if(objectp(environment(who))) message("other_action", who->QCN+ " returns from the dead.", environment(who), who);
    who->new_body();
    who->reset_condition();
    who->set_ghost(0);
    who->save_player( who->query_name() );
}
