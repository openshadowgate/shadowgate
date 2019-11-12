// new command to pick up spell system and list all class spells available. -N.
//cleaned up gets_spells() and full_list() functions so that they are properly removing the spell objects once they get information from them
//previously they were stuck in memory until the game cleaned them up - Saide, March 30, 2016
#include <std.h>
#include <daemons.h>
inherit DAEMON;

mapping spells;
string *magic;
int get_spells(object player, string myclass);
int full_list(object player, string myclass);
void add_spell(string spellname, int lvl);
void sort();
void CleanUpSpellObjects();
private void swap(int i, int j);
void sort_two();
object *ToClean;


int cmd_spells(string str)
{
    string myclass, args, tmp;
    int x, temp1, level;
    mapping hate;

    if (!str) return notify_fail("Check <help spells> for syntax.\n");

    if(sscanf(str, "%s of level %d", myclass, level) == 2)
    {
        args = "of level "+level;
    }

    if (sscanf(str, "%s %s", myclass, args) != 2)
    {
        myclass = str;
        args = "by name";
    }

    spells = ([]);
    magic = ({});
    tmp = ({});

    if(myclass == "innate")
    {
        tell_object(TP,"%^BOLD%^You're probably looking for <recall innate spells>!");
        TP->force_me("recall innate spells");
        return 1;
    }

    if(myclass == "antipaladin") myclass = "paladin";
    if(args == "expanded knowledge")
    {
        if(!TP->is_class("psion") && !TP->is_class("psywarrior"))
        {
            tell_object(TP,"You cannot take the expanded knowledge feats!");
            return 1;
        }
        full_list(TP,myclass);
    }
    else
    {
        get_spells(TP,myclass);
    }
    magic = keys(spells);
    hate = TP->query_all_memorized(myclass);
    if(!sizeof(magic))
    {
        tell_object(TP, "There are no spells available to the "+myclass+" class!");
        return 1;
    }
    tell_object(TP, "\n%^RESET%^%^BLUE%^-=%^BOLD%^<%^WHITE%^Generating spell list for a %^ORANGE%^"+myclass+"%^BLUE%^>%^RESET%^%^BLUE%^=-");
    tell_object(TP, "%^MAGENTA%^"+arrange_string("Spell:", 24) + arrange_string("Level", 6));

    if (args == "by school" && (myclass == "mage" || myclass == "sorcerer"))
    {
        sort_by_school();
    }
    if (args != "by level" && args != "expanded knowledge")
        sort();
    else
        sort_two();

    for (x = 0; x < sizeof(magic);x++)
    {
        if(level && (spells[magic[x]] != level) ) { continue; }
        tell_object(TP,"%^GREEN%^%^BOLD%^"+arrange_string(magic[x], 26)+"%^RESET%^%^CYAN%^"+arrange_string(spells[magic[x]], 4)+(myclass=="mage"||myclass=="sorcerer"?"  "+MAGIC_D->query_index_row(magic[x])["sphere"]:""));
    }
    tell_object(TP,"\n");
    CleanUpSpellObjects();
    if(myclass == "monk")
    {
        tell_object(TP, "%^BOLD%^Use <ki> command or refer to <help monk> or <help WAY>");
    }
    return 1;
}

void CleanUpSpellObjects()
{
    int x;
    if(!sizeof(ToClean)) return;
    //tell_object(find_player("saide"), "It is getting here... spell objects should be cleaned up");
    for(x = 0;x < sizeof(ToClean);x++)
    {
        if(objectp(ToClean[x]))
        {
            //tell_object(find_player("saide"), ToClean[x]->query_name()+ " being cleaned.");
            ToClean[x]->remove();
        }
        continue;
    }
    return;
}

int get_spells(object player, string myclass)
{
    spells=MAGIC_D->index_spells_for_player(player,myclass);
}

int full_list(object player, string myclass)
{
    mapping tmp;
    tmp=MAGIC_D->query_index("psion")+MAGIC_D->query_index("psywarrior");
    if(myclass=="psywarrior")
        spells=filter_mapping(tmp,(:$2<6:));
    else
        spells=filter_mapping(tmp,(:$2<9:));
}


void add_spell(string spellname, int lvl)
{
    spellname = MAGIC_D->spell_file_to_spell_name(spellname);
    spells[spellname] = lvl;
}


void sort()
{
    int i,j;

    for (j=0;j<sizeof(magic);j++)
    {
        for (i=sizeof(magic)-1;i>j;i--)
        {
            if (magic[i] < magic[i-1])
            {
                swap(i-1,i);
            }
        }
    }
}


private void swap(int i, int j)
{
    string tmp;

    tmp = magic[i];
    magic[i]=magic[j];
    magic[j]=tmp;
}


void sort_two()
{
    int i,j;
    mapping tmp,tmp2;
    string spellname;

    for (j=0;j<sizeof(magic);j++)
    {
        for (i=sizeof(magic)-1;i>j;i--)
        {
            if (spells[magic[i]] < spells[magic[i-1]])
            {
                swap(i-1,i);
            }
        }
    }

}

void sort_by_school() {
    int i,j;

    for (j=0;j<sizeof(magic);j++)
        for (i=sizeof(magic)-1;i>j;i--) {
            if (MAGIC_D->query_index_row(magic[i])["sphere"] < MAGIC_D->query_index_row(magic[i-1])["sphere"]) {
                swap(i-1,i);
            }
        }
}



int *magic_arsenal_feat(object ob, int *spells)
{
    int i;

    if(FEATS_D->usable_feat(ob,"magic arsenal"))
    {
        for(i=0;i<sizeof(spells);i++)
        {
            if(!spells[i]) continue;
            spells[i] += 2;
        }
    }
    return spells;
}


int *bonus_spell_slots(object ob, int *spells)
{
    int i,extra;

    if(!objectp(ob)) return spells;

    extra = (int)ob->query_property("bonus_spell_slots");
    if(!intp(extra) || !extra) { return spells; }

    for(i=0;i<sizeof(spells);i++)
    {
        if(!spells[i]) continue;
        spells[i] += extra;
        if(spells[i] < 0) spells[i] = 0;
    }
    return spells;
}


void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

spells - list spells

%^CYAN%^SYNTAX%^RESET%^

spells %^ORANGE%^%^ULINE%^CLASS%^RESET%^ [by level|by school|of level %^ORANGE%^%^ULINE%^NUM%^RESET%^|expanded knowledge]

%^CYAN%^DESCRIPTION%^RESET%^

By default will list all spells available to your %^ORANGE%^%^ULINE%^CLASS%^RESET%^.

Optional suffix \"by level\" will sort given list by spell level, e.g. %^ORANGE%^<spells mage by level>%^RESET%^

If you append suffix \"of level %^ORANGE%^%^ULINE%^NUMBER%^RESET%^\" you'll be shown spells only of level %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ you specified, e.g. %^ORANGE%^<spells psion of level 3>%^RESET%^.

Psions and psywarriors may specify suffix \"expanded knowledge\" to view all spells available for expanded knowledge feat.

%^CYAN%^SEE ALSO%^RESET%^

prepare, forget, buff, recall, cast, dispell
"
        );
}
