/**
 * @file
 * @brief Innate abilities
 *
 * This file may contain remnants of previvous system. In current
 * varsion all innate abilities are cast at clevel equal to charlevel
 * and at will
 */

#include <std.h>
#include <daemons.h>

inherit LIVING;

mapping InnateAbilities;

void reset_racial_innate() { TO->delete("racial innate"); }

void InitInnate()
{
    string MyRaceFile,*oldmap,*newmap;
    int i;
    mixed RacialInnate;
    mapping feat_spells;
    //check_temp_innate();

    reset_racial_innate();

    if(TO->query("test_innate_allowed"))
    {
        //temp variable that allowed testing - moving past this now - Saide
        TO->delete("test_innate_allowed");
    }

    if((string)TO->query("racial innate") != (string)TO->query_race())
    {
        InnateAbilities = ([]);
        TO->set("racial innate", (string)TO->query_race());
        MyRaceFile = "/std/races/"+(string)TO->query_race()+".c";
        //tell_object(find_player("saide"), "MyRaceFile = "+MyRaceFile);
        if(file_exists(MyRaceFile))
        {
            RacialInnate = MyRaceFile->query_racial_innate(TO->query("subrace"));

            if(mapp(RacialInnate))
            {
                if(sizeof(keys(RacialInnate)))
                {
                    InnateAbilities += RacialInnate;
                }
            }
        }
    }

    //Template based spells go here as well

    if (TO->query_acquired_template()) {
        string template = TO->query_acquired_template();
        if (file_exists("/std/acquired_template/" + template + ".c")) {
            mapping innates = ("/std/acquired_template/" + template)->innate_spells();
            if (mapp(innates) && sizeof(innates)) {
                InnateAbilities += innates;
            }
        }
    }

    // adding in feat-based innate spells here! N, 11/16

    feat_spells = ([]);

    if(FEATS_D->usable_feat(TO,"undead cohort"))
    {
        feat_spells += ([
                            "vampiric touch" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                            "animate dead" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                            "exhume corpses" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                            "create undead" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                            "create greater undead" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
            ]);
    }
    if(FEATS_D->usable_feat(TO,"one with the shadows")) // shadow stride -1, darkvision -1, shadow double 1
    {
        feat_spells += ([
                                "darkvision" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                                "shadow stride" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                                "shadow double" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                                "greater shadow conjuration" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                                "shadow evocation" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                                "shadow necromancy" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                                "shadow body" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
            ]);
    }
    if(FEATS_D->usable_feat(TO,"command the stone")) // meld into stone -1, stoneskin 1, earthquake 2, conjure elemental -1
    {
        feat_spells += ([
            "strength of stone" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "meld into stone"   : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "stone body"        : (["type" : "spell", "daily uses" : 1, "level required" : 0 ]),
            "wall of stone"     : (["type" : "spell", "daily uses" : 1, "level required" : 0 ]),
            "statue"            : (["type" : "spell", "daily uses" : 1, "level required" : 0 ]),            
            "earthquake"        : (["type" : "spell", "daily uses" : 4, "level required" : 0 ]),
            "conjure elemental" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "earth reaver"      : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "shapechange"       : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            ]);
    }
    if(FEATS_D->usable_feat(TO, "slay the undead"))
    {
        feat_spells += ([
            "rope trick" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "detect undead" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "heart of metal" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "disrupting weapon" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            "undeath ward" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            ]);
    }
    
    if(FEATS_D->usable_feat(TO, "tricky spells"))
    {
        feat_spells += ([
            "spectral hand" : (["type" : "spell", "daily uses" : -1, "level required" : 0 ]),
            ]);
    }
    
    // to add new classes or reasons for innates, simply add to feat_spells here before this line.
    newmap = keys(feat_spells);

    if(sizeof(newmap)) // loop here to apply each, if uses is greater or unlimited, replace existing.
    {
        oldmap = keys(InnateAbilities);
        for(i=0;i<sizeof(newmap);i++)
        {
            if(member_array(newmap[i],oldmap) != -1)  // if they already know this innate from a racial
            {
                if(feat_spells[newmap[i]]["daily uses"] == InnateAbilities[newmap[i]]["daily uses"]) { continue; }// already matches existing
                if(feat_spells[newmap[i]]["daily uses"] != -1 && (feat_spells[newmap[i]]["daily uses"] < InnateAbilities[newmap[i]]["daily uses"])) { continue; }// if the new one they're learning doesn't have more uses than existing, ignore it
                map_delete(InnateAbilities,newmap[i]); // otherwise delete the old copy ready to add the new one!
            }
            InnateAbilities[newmap[i]] = feat_spells[newmap[i]];
        }
    }
    return;
}


void remove_bonus_innate(string *ability)
{
    int x;
    InitInnate();
    if(!mapp(InnateAbilities)) return;
    for(x = 0;x < sizeof(ability);x++)
    {
        if(member_array(ability[x], keys(InnateAbilities)) == -1)
        {
            continue;
        }
        if(InnateAbilities[ability[x]]["remove time"] == -1)
        {
            map_delete(InnateAbilities, ability[x]);
            continue;
        }
        InnateAbilities[ability[x]]["temp granted"] = 2;
        continue;
    }
}


void add_bonus_innate(mapping BonusInnate)
{
    string *tmp, *tmp2, *tmp3;
    mapping addThese = ([]);
    int x;
    if(!mapp(BonusInnate)) return;
    if(!mapp(InnateAbilities)) InitInnate();
    if(!mapp(InnateAbilities)) return;
    tmp = keys(BonusInnate);
    tmp2 = keys(InnateAbilities);
    tmp3 = ({});
    for(x = 0;x < sizeof(tmp);x++)
    {
        if(!mapp(BonusInnate[tmp[x]]) || member_array(tmp[x], tmp2) != -1)
        {
            continue;
        }
        BonusInnate[tmp[x]] += (["temp granted" : 1, "remove time" : -1]);
        if(!BonusInnate[tmp[x]]["type"])
        {
            BonusInnate[tmp[x]] += (["type" : "spell"]);
        }
        if(!BonusInnate[tmp[x]]["daily uses"])
        {
            BonusInnate[tmp[x]] += (["daily uses" : -1]);
        }
        continue;
    }
    for(x = 0;x < sizeof(tmp3);x++)
    {
        map_delete(BonusInnate, tmp3[x]);
        continue;
    }
    if(!mapp(BonusInnate)) return;
    if(!sizeof(keys(BonusInnate))) return;
    InnateAbilities += BonusInnate;
}


mixed query_innate_spells()
{
    string *tmp, *tmp2;
    int x;
    if(!objectp(TO)) return 0;
    if(!mapp(InnateAbilities)) InitInnate();
    if(!mapp(InnateAbilities)) return;
    if(!sizeof(keys(InnateAbilities))) return 0;
    tmp2 = keys(InnateAbilities);
    tmp = ({});
    for(x = 0; x < sizeof(tmp2);x++)
    {
        if(!mapp(InnateAbilities[tmp2[x]]))
        {
            tell_object(TO, "Not a mapping = "+identify(tmp2[x]));
            continue;
        }
        if(InnateAbilities[tmp2[x]]["type"] == "spell")
        {
            if(InnateAbilities[tmp2[x]]["temp granted"] == 2)
            {
                if(!can_use_innate_ability(tmp2[x])) continue;
            }
            tmp += ({tmp2[x]});
            continue;
        }
        continue;
    }
    if(sizeof(tmp)) return tmp;
    return 0;
}

int can_use_innate_ability(string ability)
{
    mixed tmp;
    if(!mapp(InnateAbilities)) InitInnate();
    if(!mapp(InnateAbilities)) return;
    if(member_array(ability, keys(InnateAbilities)) == -1) return 0;
    if(!mapp(InnateAbilities[ability])) return 0;
    return 1;
}


int query_innate_ability_uses_remaining(string ability)
{
    if(!can_use_innate_ability(ability)) return 0;
    return InnateAbilities[ability]["uses left"];
}


int query_innate_ability_total_uses(string ability)
{
    mixed tmp;
    if(!mapp(InnateAbilities)) InitInnate();
    if(!mapp(InnateAbilities)) return;
    if(member_array(ability, keys(InnateAbilities)) == -1) return 0;
    if(!mapp(InnateAbilities[ability])) return 0;
    return -1;
}

int query_innate_ability_level(string ability)
{
    int lvl, mod;
    string MyClass;
    if(!can_use_innate_ability(ability)) return 0;
    lvl = (int)TO->query_highest_level();
    lvl = to_int(lvl);
    if(lvl < 1) lvl = 1;
    return lvl;
}


int query_innate_useable_time(string ability)
{
    if(!query_innate_ability_total_uses(ability)) return 0;
    return InnateAbilities[ability]["refresh time"];
}


mixed query_innate_abilities()
{
    return InnateAbilities;
}
