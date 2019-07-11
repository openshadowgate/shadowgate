/*==================================================================================================
Disease Daemon (Saide, May 2016) - used to:

**Tell if someone has a particular disease
**Someone has any diseases at all
**The string modifiers for a disease that will go on the long description of the player/creature infected
**Dispell Diseases from someone (or attempt to :P)
**Decrease incubation times/effect times/possibly make the disease permenant aside from a spell to remove it
**Call the effect of the disease - Exacerbate disease spell? 

====================================================================================================*/
#define DISEASE_DIR "/d/common/obj/diseases/"

#include <std.h>
#include <daemons.h>

//hopefully to make sure disease penalties get removed correctly
//in the event of the actual disease object somehow getting messed up 
mapping ACTIVE_DISEASES;

mixed my_obvious_disease_effects(object who);
mixed their_obvious_disease_effects(object who);
int query_infected_by(object who, string disease);
void infect_with_disease(object who, object targ, int flag);
mixed random_disease_object();
string cure_diseases(object who, object targ);
int advance_diseases(object victim, int dc);

int is_a_disease(object obj)
{
    if(!objectp(obj)) return 0;
    return (int)obj->is_disease();
}

mixed query_all_diseases(object who)
{
    object *inv;
    if(!objectp(who)) return 0;
    inv = all_inventory(who);
    inv = filter_array(inv, "is_a_disease", TO);
    if(!pointerp(inv)) return 0;
    if(!sizeof(inv)) return 0;
    return inv;   
}

//I'm assuming DC would be some combination of 
//level/class level, etc. of the person
//trying to advance the disease of the "victim"
//here
int advance_diseases(object victim, int dc)
{
    object *inv;
    int x, lev, flag, inc, aff;
    if(!objectp(victim)) return 0;
    lev = victim->query_highest_level();
    inv = query_all_diseases(victim);
    if(!pointerp(inv)) return 0;
    flag = 0;
    for(x = 0;x < sizeof(inv);x++)
    {
        if(!objectp(inv[x])) continue;
        if((roll_dice(1, 20) + (lev/2)) > dc) continue;
        if(aff = (int)inv[x]->query_incubation_period() > 0)
        {
            if(aff != -1)
            {
                aff -= ((25 + random(25)) * dc);
                if(aff < 0) aff = 0;
                inv[x]->set_incubation_period(aff);
                flag++;
                continue;
            }
        }
        continue;
        if(aff = (int)inv[x]->query_effect_rate() > 0)
        {
            if(aff != -1)
            {
                aff -= ((15 + random(15)) * dc);
                if(aff < 0) aff = 0;
                inv[x]->set_effect_rate(aff);
                flag++;
                continue;
            }
        }           
        if(aff = (int)inv[x]->query_disease_length() > 0)
        {
            //potentially lengthen a normal disease 
            //to require magical removal - those infected
            //by the disease will not have this 
            if(aff != -1)
            {
                if(!random(40))
                {
                    inv[x]->set_disease_length(-1);
                    flag++;
                    continue;
                }
            }
        }
        continue;
    }
    return flag;
}

//return a string of the names that were cured
string cure_diseases(object who, object targ)
{
    object *inv;
    int x, lev, dc;
    string curedDiseases = "";
    
    if(!objectp(who)) return "";
    if(!objectp(targ)) return "";
    inv = query_all_diseases(targ);
    if(!pointerp(inv)) return "";
    lev = who->query_level();
    for(x = 0;x < sizeof(inv);x++)
    {
       
        if(!objectp(inv[x])) continue;
        //not detectable during the incubation period - cannot be cured
        if((int)inv[x]->query_incubation_period() && !inv[x]->query_detectable()) continue;
        dc = (int)inv[x]->query_dc() + (int)inv[x]->query_dc_mod();
        if((roll_dice(4, 5) + (lev)) < dc) 
        {
            //tell_room(environment(who), "DC failed");
            //if()
            //who->force_me("say "+inv[x]->query_disease_name()+" is more powerful than I am. I cannot help with it.");
            continue;
        }
        curedDiseases += (string)inv[x]->query_disease_name() + "\n";
        inv[x]->disease_cured();
        continue;        
    }
    return curedDiseases;
}

mixed random_disease_object()
{
    string *files;
    string MyFile;
    object diseaseOb;
    
    files = get_dir(DISEASE_DIR+"*.c");
    if(!sizeof(files)) return;
    if(!pointerp(files)) return;
    files -= ({"disease_inherit.c"});
    if(!sizeof(files)) return;
    MyFile = files[random(sizeof(files))];
    if(catch(diseaseOb = new(DISEASE_DIR+MyFile))) return;
    return diseaseOb;
}

int check_disease(object diseaseOb, object targ)
{
    if(!objectp(diseaseOb)) return 1;
    if(!objectp(targ)) return 1;
    if((FEATS_D->usable_feat(targ, "purity of body") || FEATS_D->usable_feat(targ, "divine health")) && !diseaseOb->bypass_immunity())
    {
        diseaseOb->remove();
        return 1;
    }
    if(query_infected_by(targ, (string)diseaseOb->query_disease_name()))
    {
        diseaseOb->remove();
        return 1;
    }
    return 0;
}

//flag = 1 for an instantaneous infection
//of a disease 
void infect_with_disease(object who, object targ, int flag)
{
    object diseaseOb;
    string *files, MyFile, MyDisease;
    int charges;
    if(!objectp(targ)) return;
    if(!objectp(who)) return;
    if(stringp(MyDisease = who->query_property("infects disease")))
    {
        if(intp(charges = (int)who->query_property("infection uses")) && !living(who))
        {
            if(!charges && charges != -1) 
            {
                who->remove_property("infection uses");
                who->remove_property("infects disease");
                return;
            }           
        }
        if(MyDisease == "random")
        {
            diseaseOb = random_disease_object();
            if(!objectp(diseaseOb)) return;
        }
        else
        {
            MyFile = DISEASE_DIR + MyDisease + ".c";
            if(!file_exists(MyFile)) return;
            if(catch(diseaseOb = new(MyFile))) return;
        }
        diseaseOb->move(targ);
        if(check_disease(diseaseOb, targ)) return;
        diseaseOb->set_dc_mod(((int)who->query_level()/2));
        if(flag)
        {           
            diseaseOb->set_incubation_period(0);
            diseaseOb->disease_effect();
        }
        return;        
    }
    else 
    {
        //tell_object("/std/user#860785", "trying to get a random disease");
        diseaseOb = random_disease_object();
        //tell_object("/std/user#860785", "random disease = "+identify(diseaseOb));
        if(!objectp(diseaseOb)) return;
        //tell_object("/std/user#860785", "targ = "+identify(targ));
        if(check_disease(diseaseOb, targ)) return;
        //tell_object("/std/user#860785", "targ = "+identify(targ) + " didn't have the disease");
        diseaseOb->move(targ);
        //tell_object("/std/user#860785", "random disease still = "+identify(diseaseOb));
        diseaseOb->set_dc_mod(((int)who->query_level()/2));
        if(flag)
        {
            diseaseOb->set_incubation_period(0);            
        }
        return;
    }   
}

int query_infected_by(object who, string disease)
{
    object *inv;
    int x;
    if(!objectp(who)) return 0;
    if(!stringp(disease)) return 0;
    if(!pointerp(inv = query_all_diseases(who))) return 0;
    if(!sizeof(inv)) return 0;
    for(x = 0; x < sizeof(inv);x++)
    {
        if(!objectp(inv[x])) continue;
        if((string)inv[x]->query_disease_name() == disease && (string)inv[x]->query_infected() == (string)who->query_true_name()) return 1;
        continue;
    }
    return 0;    
}

mixed my_obvious_disease_effects(object who)
{
    object *inv;
    string mod = "", modtmp, tmp;
    int x;
    if(!objectp(who)) return 0;
    if(!pointerp(inv = query_all_diseases(who))) return 0;
    for(x = 0;x < sizeof(inv);x++)
    {
        tmp = inv[x]->query_personal_disease_string();
        if(!stringp(tmp)) continue;
        if(tmp == "") continue;
        /*tmp = replace_string(tmp, "$TNAM", "you");
        tmp = replace_string(tmp, "$TSUB", "you");
        tmp = replace_string(tmp, "$TOBJ", "you");
        tmp = replace_string(tmp, "$TPOS", "your");
        tmp = capitalize(tmp);*/
        mod += tmp+"\n";
        continue;
    }
    if(stringp(mod)) return mod;
    return 0;   
}

mixed their_obvious_disease_effects(object who)
{
    object *inv;
    string mod = "", modtmp, tmp;
    int x;
    if(!objectp(who)) return 0;
    if(!pointerp(inv = query_all_diseases(who))) return 0;
    for(x = 0;x < sizeof(inv);x++)
    {
        tmp = inv[x]->query_disease_string();
        if(!stringp(tmp)) continue;
        if(tmp == "") continue;
        tmp = replace_string(tmp, "$TSUB", who->QS);
        tmp = replace_string(tmp, "$TPOS", who->QP);
        tmp = replace_string(tmp, "$TOBJ", who->QO);
        tmp = replace_string(tmp, "$TNAM", who->QCN);
        tmp = capitalize(tmp);
        mod += tmp+"\n";
        continue;
    }
    if(stringp(mod)) return mod;
    return 0;    
}

mapping query_active_diseases() { return ACTIVE_DISEASES; }

//the following functions exists largely to make sure or at least
//ATTEMPT to make sure that should a disease object disappear
//then the penalties from it will disappear also
void register_disease(object infected, mapping effects)
{
    string pname, *tmp;
    int x, tar, cur;
    if(!objectp(infected)) return;
    if(!mapp(ACTIVE_DISEASES)) ACTIVE_DISEASES = ([]);
    if(!mapp(effects)) return;
    if(!userp(infected)) return;
    pname = infected->query_name();
    if(!ACTIVE_DISEASES[pname]) 
    {
        ACTIVE_DISEASES[pname] = (["effects 1": effects]);
        return;
    }
    if(!mapp(ACTIVE_DISEASES[pname]))
    {
        ACTIVE_DISEASES[pname] = (["effects 1": effects]);
        return;
    }
    tmp = keys(ACTIVE_DISEASES[pname]);
    tar = 1;
    for(x = 0;x < sizeof(tmp);x++)
    {
        cur = to_int(explode(tmp[x], " ")[1]);
        if(tar == cur) tar++;
        continue;
    }    
    ACTIVE_DISEASES[pname] += (["effects "+tar : effects]);
    return;
}

void unregister_disease(object infected, object disease)
{
    string pname, *tmp;
    int x, tar, cur;
    mapping effects;
    if(!objectp(infected)) return;
    if(!mapp(ACTIVE_DISEASES)) ACTIVE_DISEASES = ([]);
    if(!mapp(effects)) return;
    if(!userp(infected)) return;
    pname = infected->query_name();
    if(!ACTIVE_DISEASES[pname]) 
    {
        return;
    }
    if(!mapp(ACTIVE_DISEASES[pname]))
    {
        return;
    }
    effects = ACTIVE_DISEASES[pname];
    tmp = keys(effects);
    for(x = 0;x < sizeof(tmp);x++)
    {
        if(effects[tmp[x]]["object"] == disease) map_delete(effects, tmp[x]);
        continue;
    }
    if(!sizeof(keys(effects))) map_delete(ACTIVE_DISEASES, pname);
    else ACTIVE_DISEASES[pname] = effects;
    return;
}

void clear_invalid_diseases(object infected)
{
    string InfectedName, MyDiseases, effect, targ;
    mapping tmp, nlevels;
    int i, reversed_dam;
    object ob;
    
    if(!objectp(infected)) return;
    if(!mapp(ACTIVE_DISEASES))
    {
        ACTIVE_DISEASES = ([]);
        return;
    }
    if(!userp(infected)) return;
    InfectedName = infected->query_name();
    if(!ACTIVE_DISEASES[InfectedName]) return;
    if(!mapp(ACTIVE_DISEASES[InfectedName])) return;    
    tmp = ACTIVE_DISEASES[InfectedName];
    MyDiseases = keys(tmp);
    if(!sizeof(MyDiseases)) return;
    for(i = 0;i < sizeof(MyDiseases);i++)
    {
        if(objectp(tmp[MyDiseases[i]]["object"])) continue;
        //no longer an object - 
        if(!objectp(tmp[MyDiseases[i]]["object"])) continue;
        {
            effect = tmp[MyDiseases[i]]["effectType"];
            reversed_dam = tmp[MyDiseases[i]]["damage"] * -1;
            targ = tmp[MyDiseases[i]]["target"];
            if(effect == "negative level")
            {
                nlevels = infected->query("negative level");
                if(!mapp(nlevels)) continue;
                if(!nlevels[targ]) continue;
                nlevels[targ] += reversed_dam;
                if(nlevels[targ] > 0) map_delete(nlevels, targ);
                if(!sizeof(keys(nlevels))) infected->delete("negative level");
                else infected->set("negative level", nlevels);
                continue;
            }
            else if(effect == "exhaustion" || effect == "skill damage")
            {
                infected->add_skill_bonus(targ, reversed_dam);
                continue;
            }
            map_delete(tmp, MyDiseases[i]);
        }        
    }
    if(sizeof(keys(tmp))) ACTIVE_DISEASES[InfectedName] = tmp;
    else map_delete(ACTIVE_DISEASES, InfectedName);
}

void reverse_disease_effects(object disease, object infected, int quiet)
{
    int i, reversed_damage, flag, cur_stage;
    mapping effects, nlevels;
    int *effect_array;
    string effectType, target;
    
    if(!objectp(disease)) return;
    if(!objectp(infected)) return;
    
    effects = disease->query_disease_effects();
    
    if(!mapp(effects)) return;
    if(!sizeof(keys(effects))) return;
    effect_array = keys(effects);
    for(i = 0;i < sizeof(effect_array);i++)
    {
        if(!effects[effect_array[i]]) continue;
        cur_stage = effect_array[i];
        //if it has never been applied, skip it
        if(effects[cur_stage]["applied"] != 1) continue;
        effectType = effects[cur_stage]["effect type"];
        reversed_damage = effects[cur_stage]["damage"] * -1;
        //if it's never done any damage, skip it
        if(reversed_damage == 0) continue;
        target = effects[cur_stage]["target"];
        switch(effectType)
        {
            case "exhaustion": case "skill damage":
                infected->add_skill_bonus(target, reversed_damage);
                flag = 1;
                break;
            case "negative level":
                nlevels = infected->query("negative level");
                if(!mapp(nlevels)) continue;
                if(!nlevels[target]) continue;
                nlevels[target] += reversed_damage;
                if(nlevels[target] > 0) map_delete(nlevels, target);
                if(!sizeof(keys(nlevels))) infected->delete("negative level");
                else infected->set("negative level", nlevels);
                flag = 1;
                break;
        }        
        continue;
    }
    if(flag && !quiet) disease->cured_notify();
    unregister_disease(infected, disease);
    return;
}

void reapply_disease_effects(object disease, object infected)
{
    int i, damage, flag, cur_stage;
    mapping effects, nlevels;
    int *effect_array;
    string effectType, target;
    
    if(!objectp(disease)) return;
    if(!objectp(infected)) return;
    
    effects = disease->query_disease_effects();
    
    if(!mapp(effects)) return;
    if(!sizeof(keys(effects))) return;
    effect_array = keys(effects);
    for(i = 0;i < sizeof(effect_array);i++)
    {
        if(!effects[effect_array[i]]) continue;
        cur_stage = effect_array[i];
        //if it has never been applied, skip it
        if(effects[cur_stage]["applied"] != 1) continue;
        effectType = effects[cur_stage]["effect type"];
        damage = effects[cur_stage]["damage"];
        //if it's never done any damage, skip it
        if(damage == 0) continue;
        target = effects[cur_stage]["target"];
        switch(effectType)
        {
            //the only type that get actually reapplied
            case "exhaustion": case "skill damage":
                infected->add_skill_bonus(target, damage);
                register_disease(infected, (["target" : target, "damage" : damage, "type" : effectType, "object" : disease]) );
                break;
            //stays through logs out - so doesn't get reapplied but still registering it with the daemon
            case "negative level":
                register_disease(infected, (["target" : target, "damage" : damage, "type" : effectType, "object" : disease]) );
                break;
        }        
        continue;
    }
    return;
}

void parse_disease_effects(object disease, object infected)
{
    int dstage, bypass, i, cur_stage;
    mapping effects, myEffects, tmp;
    int damage, *effect_array;
    string effectType, target, *classes;
    
    if(!objectp(infected)) return;
    clear_invalid_diseases(infected);
    if(!objectp(disease)) return;
    bypass = disease->query_bypass_immunity();
    
    if(!bypass && (FEATS_D->usable_feat(infected, "purity of body") || FEATS_D->usable_feat(infected, "divine health"))) 
    {   
        disease->disease_cured();
        return;
    }
    effects = disease->query_disease_effects();
    if(!mapp(effects)) return;
    
    if(!sizeof(keys(effects))) return;
    
    dstage = disease->query_disease_stage();
    if(dstage == -1) effect_array = ({-1});
    if(dstage != -1) {  dstage++; effect_array = ({-1, dstage}); }
    
    for(i = 0;i < sizeof(effect_array);i++)
    {
        if(!effects[effect_array[i]]) continue;
        cur_stage = effect_array[i];
        effectType = effects[cur_stage]["effect type"];
        if(!living(infected)) continue;
        //tell_object(infected, "It is inside the disease daemon parse disease effects loop");
        if(!disease->disease_effect_save(infected, disease)) 
        {
            target = "";
            damage = 0;
            switch(effectType)
            {
                case "exhaustion":
                    damage = -1 * effects[cur_stage]["severity"];
                    target = "endurance";
                    infected->add_skill_bonus("endurance", damage);
                    effects[cur_stage]["damage"] += damage;
                    effects[cur_stage]["applied"] = 1;
                    effects[cur_stage]["passed save"] = 0;
                    effects[cur_stage]["target"] = "endurance";
                    break;
                case "negative level":
                    damage = -1 * effects[cur_stage]["severity"];                    
                    classes = target->query_classes();
                    target = classes[random(sizeof(classes))];
                    tmp = infected->query("negative level");
                    if(!mapp(tmp)) tmp = ([target : damage]);
                    else
                    {
                        if(tmp[target]) tmp[target] += damage;
                        else tmp += ([target : damage]);
                    }
                    infected->set("negative level", tmp);
                    effects[cur_stage]["applied"] = 1;
                    effects[cur_stage]["persistent"] = 1;
                    effects[cur_stage]["passed save"] = 0;
                    effects[cur_stage]["target"] = target;
                    effects[cur_stage]["damage"] += damage;
                    break;
                case "damage":
                    damage = effects[cur_stage]["severity"];
                    infected->cause_typed_damage(infected, "torso", damage, disease->query_damage_type());
                    effects[cur_stage]["applied"] = 1;
                    effects[cur_stage]["persistent"] = 1;
                    effects[cur_stage]["passed save"] = 0;
                    effects[cur_stage]["damage"] += damage;
                    break;
                case "paralyze":
                    damage = effects[cur_stage]["severity"];
                    infected->set_paralyzed(damage, "%^BOLD%^%^RED%^You are weakened by "+disease->query_disease_name()+"!");
                    effects[cur_stage]["applied"] = 1;
                    effects[cur_stage]["persistent"] = 1;
                    effects[cur_stage]["damage"] += damage;
                    effects[cur_stage]["passed save"] = 0;
                    break;
                case "blindness":
                    damage = effects[cur_stage]["severity"];
                    infected->set_temporary_blinded(damage, "%^BOLD%^%^RED%^You are blinded by "+disease->query_disease_name()+"!");
                    effects[cur_stage]["applied"] = 1;
                    effects[cur_stage]["persistent"] = 1;
                    effects[cur_stage]["damage"] += damage;
                    effects[cur_stage]["passed save"] = 0;
                    break;
                case "skill damage":
                    damage = -1 * effects[cur_stage]["severity"];
                    target = effects[cur_stage]["target"];
                    infected->add_skill_bonus(target, damage);
                    effects[cur_stage]["applied"] = 1;
                    effects[cur_stage]["passed save"] = 0;
                    effects[cur_stage]["damage"] += damage;
                    break;
                case "unique": 
                    //special case of a function in the disease object being called
                    target = effects[cur_stage]["severity"];
                    call_other(disease, target, infected);
                    break;
                default: break;
            }                  
            if(effectType != "unique")
            {
                if(target != "" && damage)
                {
                    register_disease(infected, (["target" : target, "damage" : damage, "type" : effectType, "object" : disease]) );
                    continue;
                }
            }
            disease->disease_effect_notify();
            continue;
        }
        else
        {
            effects[cur_stage]["passed save"] = 1;
            continue;
        }
    }
    disease->set_disease_stage(dstage);
    disease->set_disease_effects(effects);
    return;   
}
