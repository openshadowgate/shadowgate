
#include <magic.h>
#include <daemons.h>
#include <master_limits.h>

/**
 * @file
 */

mapping CLASSMAP=(["mage":MAGEKNOWN,
                   "sorcerer":SORCKNOWN,
                   "psion":PSIONKNOWN,
                   "psywarrior":PWKNOWN,
                   "warlock":WARLOCKKNOWN]);

int cmd_master(string args)
{
    string myclass = TP->query_class();
    int slvl;
    string sarg,sarg2;
    if(sizeof(TP->query_classes())>1)
        write("%^CYAN%^You are posing as a %^BOLD%^%^WHITE%^"+myclass+"%^RESET%^%^CYAN%^. To change that use %^ORANGE%^<pose>%^CYAN%^.");
    if(member_array(myclass,keys(CLASSMAP))==-1)
    {
        write("%^ORANGE%^Your currently posed class doesn't master.");
        return 1;
    }
    if(args == "fix")
    {
        validate_mastered();
        return 1;
    }
    if(!args || args == "map")
    {
        int mylvl = TP->query_prestige_level(myclass);
        mapping spell_index = MAGIC_D->query_index(myclass);
        int i;
        int bonuslimit = 0;
        int *spelllevels = allocate(9);
        string sname;
        string *myspells = TP->query_mastered_base()[myclass];

        mylvl = mylvl>50?50:mylvl;

        if(sizeof(myspells))
            foreach(sname in myspells)
                spelllevels[spell_index[sname]-1]+=1;

        write("%^CYAN%^You have spells as follows:");
        for(i = 0; i < 9;i++)
            if(CLASSMAP[myclass][mylvl][i])
                write("%^CYAN%^Level "+(i+1)+": %^RESET%^"+spelllevels[i]+" of "+CLASSMAP[myclass][mylvl][i]);
        if(TP->usable_feat("spell knowledge"))
            bonuslimit+=2;
        if(TP->usable_feat("greater spell knowledge"))
            bonuslimit+=3;
        write("%^CYAN%^You can learn "+bonuslimit+" spells above limit due to your spell knowledge feat.");
        write("%^CYAN%^Type %^ORANGE%^<master bonus>%^CYAN%^ to see any bonus spells.");
        return 1;
    }
    if(args == "list")
    {
        mapping spell_index = MAGIC_D->query_index(myclass);
        string *myspells = TP->query_mastered_base()[myclass];
        string spell;
        mixed *spellist=allocate(9);
        int mylvl = TP->query_prestige_level(myclass);
        int i;

        if(sizeof(myspells))
            foreach(spell in myspells)
            {
                spellist[spell_index[spell]-1]=(spellist[spell_index[spell]-1]?spellist[spell_index[spell]-1]:({}))
                    +({spell}); //If LHS is not emply check
            }

        write("%^CYAN%^You have mastered:");

        for (i = 0; i < 9; i++)
            if(CLASSMAP[myclass][mylvl][i])
                write("%^CYAN%^Level "+(i+1)+": %^RESET%^"+
                      (spellist[i]?implode(spellist[i],", "):"none")); //Non empty check
        write("%^CYAN%^Type %^ORANGE%^<master bonus>%^CYAN%^ to see any bonus spells");
        return 1;
    }
    if(args == "bonus")
    {
        string *bonusspells = TP->query_mastered_bonus()[myclass];
        write("%^CYAN%^Additional spells you know:%^RESET%^");
        if(sizeof(bonusspells))
            write(implode(bonusspells,", "));
        else
            write("none");
        return 1;
    }
    if(sscanf(args,"level %d",slvl) == 1)
    {
        string *myspells = TP->query_mastered_base()[myclass];
        mapping spell_index = MAGIC_D->query_index(myclass);
        string *savail = keys(filter_mapping(spell_index,(:$2==$3:),slvl))-myspells;

        write("%^CYAN%^Spells available to master at level "+slvl+":%^RESET%^");
        if(sizeof(savail))
            write(implode(savail,", "));
        else
            write("none");
        return 1;
    }
    if(sscanf(args,"forget %s",sarg) == 1)
    {
        mapping spell_index = MAGIC_D->query_index(myclass);
        string *myspells = TP->query_mastered_base()[myclass];
        int forgettime = (int)TP->query("last_master_forget");

        {
            if(!spell_index[sarg])
            {
                write("%^ORANGE%^The spell %^BOLD%^%^RED%^"+sarg+"%^RESET%^%^ORANGE%^ does not exist.%^RESET%^");
                return 1;
            }
            if(member_array(sarg,myspells)==-1)
            {
                write("%^ORANGE%^You don't know %^BOLD%^%^RED%^"+sarg+"%^RESET%^%^ORANGE%^.%^RESET%^");
                return 1;
            }

            if(forgettime>time()-32400)
            {
                write("%^ORANGE%^You can forget a spell %^RED%^%^BOLD%^once per nine hours%^RESET%^%^ORANGE%^.%^RESET%^");
                return 1;
            }
        }

        TP->set("last_master_forget",time());
        TP->remove_mastered(myclass,sarg);
        write("%^CYAN%^You have forgotten %^BOLD%^%^WHITE%^"+sarg+"%^RESET%^%^CYAN%^.%^RESET%^");
        return 1;
    }
    {
        mapping spell_index = MAGIC_D->query_index(myclass);
        int mylvl = TP->query_prestige_level(myclass);
        int bonuslimit = 0;
        int *knownperlevel = allocate(9);
        int i;
        string sname;
        string *myspells = TP->query_mastered_base()[myclass];

        {
            if(!spell_index[args])
            {
                write("%^ORANGE%^The spell %^BOLD%^%^RED%^"+args+"%^RESET%^%^ORANGE%^ does not exist.%^RESET%^");
                return 1;
            }
            if(member_array(args,myspells)>-1)
            {
                write("%^ORANGE%^You already know %^BOLD%^%^RED%^"+args+"%^RESET%^%^ORANGE%^.%^RESET%^");
                return 1;
            }
        }

        foreach(sname in myspells)
        {
            knownperlevel[spell_index[sname]-1]+=1;
        }

        mylvl = mylvl>50?50:mylvl;

        {
            for(i=0; i<9; i++)
            {
                if(knownperlevel[i]>CLASSMAP[myclass][mylvl][i])
                    bonuslimit-=knownperlevel[i]-CLASSMAP[myclass][mylvl][i];
            }
            if(TP->usable_feat("spell knowledge"))
                bonuslimit+=2;
            if(TP->usable_feat("greater spell knowledge"))
                bonuslimit+=3;
        }

        if(knownperlevel[spell_index[args]-1]<CLASSMAP[myclass][mylvl][spell_index[args]-1] ||
            bonuslimit > 0)
        {
            TP->add_mastered(myclass,args);
            write("%^CYAN%^You have just mastered %^BOLD%^%^WHITE%^"+args+"%^RESET%^%^CYAN%^!%^RESET%^");
            return 1;
        }
        else
        {
            write("%^ORANGE%^You have exceeded your limit for level "+spell_index[sarg]+" spells!%^RESET%^");
        }
    }
    return 1;
}

void validate_mastered()
{
    string myclass;
    string myspell;
    mapping mymastered = TP->query_mastered_base();

    if(sizeof(mymastered))
        foreach(myclass in keys(mymastered))
        {
            string * spell_index = keys(MAGIC_D->query_index(myclass));
            foreach(myspell in mymastered[myclass])
            {
                if(member_array(myspell,spell_index)==-1)
                {
                    tell_object(TP,"Wrong spell, removing: "+myspell);
                    TP->remove_mastered(myclass,myspell);
                }
            }
        }
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

master - manage spells you know

%^CYAN%^SYNTAX%^RESET%^

master
master list
master [%^ORANGE%^%^ULINE%^SPELL%^RESET%^]
master forget %^ORANGE%^%^ULINE%^SPELL%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command is an extensive interface to your knowledge of spells. Some caster classes use it to learn spells, some don't. This command is essential for sorcerers, warlocks, psions and psywarriors. Without spell being on their mastered list they won't be able to cast it. Mages can expand their spell knowledge through this command, although the main way they obtain new spells is through the spellbook.

Without an argument this command will display all available knowledge slots for each level.

To learn the %^ORANGE%^%^ULINE%^SPELL%^RESET%^, use %^ORANGE%^<master %^ORANGE%^%^ULINE%^SPELL%^RESET%^%^ORANGE%^>%^RESET%^ where %^ORANGE%^%^ULINE%^SPELL%^RESET%^ is the name of the spell you want to learn.

To get a detailed list of all spells you mastered use %^ORANGE%^<master list>%^RESET%^.

Once per nine hours you can forget already known spell with %^ORANGE%^<master forget>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

cast, prepare, buff, spellbook, classes, warlock, psion, sorcerer, psywarrior.
");
}
