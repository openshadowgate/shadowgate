//      Magic Book for Wizard Characters [v2.0]
//      Thorn@Shadowgate
//      10/10/94 [2.0: 6/8/95]
//      General Wizard Class Items
//      magic_book.c

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <magic.h>
#include <ansi.h>

#define WIZ_LEV (int)TP->query_guild_level("mage")
#define WIZ_CLASS (string)TP->query_class()
#define CLS ESC+"[H"+ESC+"[2J"

public inherit OBJECT;

mapping spells;
string *magic, *mID, bookdesc;
int restore, temp, *spells_at_level, *in_mind;

void forget_all_spells();
int query_memorized(string str);
mapping query_all_memorized();
int forget_spell(string str);
int memorize_spell(string str);
void memorize2(string str, int sl);
/* int save_book(); */
void set_memorized(string str, int sl, int xmemorized);
void remote_set_spellbook(string spell);
void set_spellbook(string spell);
void remove_spellbook(string spell);
void remove_spell(string spell);

void create()
{
    ::create();
    spells = ([]);
    set_id( ({ "book", "bookx", "magic book", 
                 "spell book", "spellbook" }) );
    set_weight(10);
    set_value(0);
    set_name("magic book");
    set_short("A Book");
    set_long("This is a spellbook.");
}

void init()
{
    ::init();
    add_action("spells", "spells");
    add_action("memorize_spell", "memorize");
    add_action("forget_spell", "forget");
    add_action("copy", "copy");
    add_action("look", "look");
    add_action("help", "help");
    if(wizardp(TP)) add_action("remove_spell", "rmspell");
    if(wizardp(TP)) add_action("add_spell", "addspell");
}

void set_spellbook(string spell)
{
    string spell_file;
    int spell_level;
    if(spell)
    {
        spell_file="/cmds/wizard/_"+
            replace_string(spell," ","_")+".c";
        if(file_exists(spell_file))
        {
            spell_level=spell_file->query_spell_level();
            if(!spell_level) return;
            if(!spell) return;
            spells[spell] = spell_level;
            return 1;
        }
        return 0;
    }
    return 0;
}

void remove_spellbook(string spell)
{
    remove_spell(spell);
}

int remove_spell(string spell)
{
    if(!spell) return 1;
    map_delete(spells, spell);
    return 1;
}

int query_spellbook(string spell) { return spells[spell]; }

int look(string str)
{
    object ob;
    int x, temp1;
    mapping memorized;

    if(!str)
        return 0;
    if(!ob=present(str,TP))
        return 0;
    if( !(ob == TO) )
        return 0;
    if( !interactive(TP) &&
        (!((string)TP->query_class()=="mage") ||
        !wizardp(TP)) )
        {
            write("This book is nothing more than page after "+
                "page of words you can't comprehend.");
            return 1;
        }
    memorized = TP->query_all_memorized();
    magic = keys(spells);
    if(!memorized) memorized = ([]);
    write("This is a spell book.  The pages include the "+
        "following spells:");
    write(arrange_string("Spell:", 20) + arrange_string("Level:", 10)+
	"* Memorized:");
    write("--------------------------------------------------------");
    for(x = 0; x < sizeof(magic);x++)
    {
        if(member_array(magic[x], keys(memorized)) == -1)
            temp1 = 0;
        else
            temp1 = memorized[magic[x]];
        write(arrange_string(magic[x], 20) + 
            arrange_string(spells[magic[x]], 10) + temp1); 
    }
    write("--------------------------------------------------------\n");
    return 1;
}

int copy_to_scroll(string str)
{
    object paper, pen, ink, scroll;
    string copied_spell;
    int level_multipler, d, multiplier;
    if(!present("paperx", TP))
    {
        notify_fail("You cannot copy a spell without something "+
            "to write on.\n");
        return 0;
    }
    if(!present("penx", TP))
    {
        notify_fail("You cannot copy a spell without something "+
            "to write with.\n");
        return 0;
    }
    if(TP->query_guild_level("mage") == 0)
    {
        notify_fail("Only wizards can read spells, let alone"+
            "copy them.\n");
        return 0;
    }
    level_multipler = TP->query_guild_level("mage");
    multiplier = level_multipler * 5;
    if(!str)
    {
        notify_fail("Copy what spell?");
        return 0;
    }
    copied_spell = str;
    if(spells[str] < 1)
    {
        notify_fail("The spell '"+str+"' is not in this book!\n");
        return 0;
    }
    paper = present("paperx", TP);
    pen = present("penx", TP);
    ink = present("inkx", TP);
    if(random(100) + multiplier > 99)
    {
        notify_fail("Your skill fails you and you botch up the copy."+
            "  You throw away the piece of paper in disgust.\n");
        paper->remove();
        d = ink->query_uses();
        ink->set_uses(d-1);
        return 0;
    }
    scroll = new("/d/magic/scroll");
    scroll->set_spell_name(str);
    scroll->move(TP);
    paper->remove();
    d = ink->query_uses();
    ink->set_uses(d-1);
    write("Spell copied sucessfully!\n");
    return 1;
}

int spells()
{
}

/* Version 2.0 functions below ------------------v */
int memorize_spell(string str)
{
    int sl, allowed_sl;
    object ownr;
    mapping memorized;
    int *in_mind;

    if(!((int)TP->query_guild_level("mage")))
    {
        notify_fail("Only users with magical abilities may memorize spells!");
        return 0;
    }    
    if(!sl = query_spellbook(str))
    {
        notify_fail("You do not have that spell in your book to "+
            "memorize! ["+str+"]\n");
        return 0;
    }
    if(!(TP->query_attackers()))
    {
        notify_fail("You cannot memorize spells while in battle!");
        return 0;
    }
    in_mind = TP->query_in_mind();
    if(!in_mind) in_mind = ({ 0,0,0,0,0,0,0,0,0 });
    memorized = TP->query_all_memorized();
    if(!memorized)
    {
        memorized = ([]);
        temp = 0;
    }
    else
        temp = TP->query_memorized(str);
    allowed_sl = WIZ_CALCS->query_spell_limit( sl,
        TP->query_guild_level("mage"), TP->query_class() );
/* Test to see if they can memorize any more spells at the */
/* level of the spell being memorized. -- Thorn 950608 */
    if(in_mind[sl-1] >= allowed_sl)
    {
        notify_fail("You have memorized all of the spells that you are"+
            " allowed at this level.\n");
        return 0;
    }
    write("You sit down, open your spell book, and begin to "+
        "memorize the spell of "+str+".  This may take awhile.");
    write("Hit <RETURN> to cancel memorizing...");
    tell_room(environment(TP),TPQCN+" sits down and opens "+
        TP->query_possessive()+" book and starts studying it "+
        "intensely.", TP);
    temp = sl * MEMORIZE_DELAY;
    call_out("flip", 2, str, sl);
    input_to("check_activity", 1);
    TP->set_paralyzed(MEMORIZE_DELAY * 10);
    return 1;
}

int check_activity(string str)
{
    if(remove_call_out("memorize2") != -1)
    {
        tell_player(TP, "You stop memorizing to do something else!\n");
        TP->remove_paralyzed();
        return 1;
    }
    return 1;
}

void flip(string str, int sl)
{
    if(random(8) == 0)
    {
        tell_object(TP,"You flip to the next page.");
        tell_room(environment(TP),TPQCN+" flips to the next page "+
            "in "+TP->query_possessive()+" book.", TP);
    }
    temp -= 2;
    if(temp > 0)
        call_out("flip", 2, str, sl);
    else
    {
        memorize2(str, sl);
        temp = 0;
        return 1;
    }
}

void memorize2(string str, int sl)
{
    TP->set_memorized(str, 1);
    TP->set_in_mind(sl, 1);
    TP->remove_paralyzed();
    tell_room(environment(TP),TPQCN+" closes "+
        TP->query_possessive()+" book, and stands up.", TP);
    write("You have now finished memorizing the spell of "+
        str+".\nHit <RETURN> to continue...");
}

int forget_spell(string str)
{
    int temp, sl, allowed_sl;
    object ownr;
    mapping memorized;
    int *in_mind;

    if(!sl = query_spellbook(str))
    {
        notify_fail("You do not have that spell in your book to"+
            "forget! ["+str+"]");
        return 0;
    }
    in_mind = TP->query_in_mind();
    if(!in_mind) in_mind = ({ 0,0,0,0,0,0,0,0,0 });
    memorized = TP->query_all_memorized();
    if(!memorized)
    {
        memorized = ([]);
        temp = 0;
    }
    else
        temp = TP->query_memorized(str);
    TP->set_memorized(str, -1);
    if(in_mind[sl-1] <= 0)
    {
        notify_fail("The spell, \""+str+"\" is not in your memory!\n");
        return 0;
    }
    else
    {
        TP->set_in_mind(sl, -1);
        write("The spell, \""+str+"\" has been forgotten "+
            "successfully!\n");
    }
    return 1;
}

int add_spell(string str)
{
    int owner_level, limit, present_spells_at_level;
    string owner_class;
    int level;
    if(!str) return 1;
    str=lower_case(str);
    if(set_spellbook(str))
        write("Spell added successfully.");
    return 1;
}

int help(string str)
{
    int x, calc;
    if(!str)
        return 0;
    if (str != "spell book" &&
        str != "spellbook")
        return 0;
    if( !interactive(TP) ||
        (!((string)TP->query_class()=="mage") &&
        !wizardp(TP)) )
        return 0;
    write(CLS);
    write("Spell books are the pride possessions of the magi.");
    write("When you have a spell book, you can:");
    write("<memorize> spells");
    write("<forget> spells");
    write("<copy> spells to paper");
    if(wizardp(TP))
    {
        write("<rmspell> spells");
        write("<addspell> spells");
    }
    if(WIZ_LEV)
    {
        write("--------------------------------------------------------");
    write(arrange_string("Spell level:", 18)+"Number allowed:"+
        "    [Your level: "+WIZ_LEV+"]");
        write("--------------------------------------------------------");
        for(x = 1; x < 10;x++)
        {
            calc = (int)"/daemon/wiz_calcs"->query_spell_limit(x, WIZ_LEV,
                WIZ_CLASS);
            write(arrange_string(x, 18) + calc);
        }
        write("--------------------------------------------------------");
    }
    return 1;
}
