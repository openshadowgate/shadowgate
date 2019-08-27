//     Casts spells
//     Written by Kayla@Shadowgate
//     Added a check for scrambling to keep people from casting while scrambling 11/20/04 -Tsera
//     Converting to global spell command. Nienne, 05/10.
// Updated to use power points for psychic characters by ~Circe~ 9/17/15
#include <std.h>
#include <daemons.h>
#include <cleric_spells.h>
#include <schoolspells.h>
#include <disciplinespells.h>

inherit DAEMON;

void help();

int light_armor_filter(object ob){
    if(!objectp(ob)) return 0;
    if(ob->query_armor_prof() == "light") return 0;
    return 1;
}

int armor_filter(object ob){
    if(!objectp(ob)) return 0;
    if(ob->query_armor_prof() == "light" || ob->query_armor_prof() == "medium" || ob->query_armor_prof() == "heavy") return 1;
    return 0;
}

int cmd_cast(string str)
{
    object targ, *armor,*wielded;
    int i,j, align, healharm, schoolspell,mylvl,*mapkeys;
    string str2,tmp, type, spell, tar, *known, myschool, myexp, myexp1, myexp2, myexp3;
    mapping mymapp = ([]),mymapp2 = ([]);

    seteuid(getuid());
    if(!str) {
        write("Cast what on/at what?");
        return 1;
    }
    type = "none";

    if(TP->query_casting() && objectp(TP->query_property("spell_casting")))
        return notify_fail("You are already doing something!\n");

    if(TP->query_property("using instant feat")) // a clever player noticed this only goes one way! Fixing that...
        return notify_fail("You are already doing something!\n");

// clerical checks for spontaneous healing/harming casts
    if (strsrch(str, "as healing") != -1)
    {
        healharm=1;
        str=replace_string(str,"as healing","",1);
    }
    else
    {
        if (strsrch(str, "as harming") != -1 )
        {
            healharm=-1;
            str=replace_string(str,"as harming","",1);
        }
        else healharm = 0;
    }

// here, type is the class casting the spell (eg/ mage), str2 is the spell name, tar is the target (or arguments)
    if(!sscanf(str,"%s %s",type,str2)) return notify_fail("Syntax: <cast classname spell-syntax>\n");

    if(!sscanf(str2,"%s on %s",str2,tar))
        if(!sscanf(str2,"%s at %s",str2,tar))
            if(!sscanf(str2,"%s to %s",str2,tar))
                if(!sscanf(str2,"%s as %s",str2, tar))
                    tar = 0;

    if(!TP->is_class(type) && !avatarp(TP) && type != "innate")
        return notify_fail("You can't cast spells as a "+type+"!\n");

    align = TP->query_true_align();
    if (healharm) {
        if (type != "cleric") {
            write("Sorry, only clerical spells can be cast as healing or harming magic.");
            return 1;
        }
        if((align % 3 == 1 && healharm < 0) || (align % 3 == 0 && healharm > 0)) {
//            tell_object(TP,"Picking up base alignment "+TP->query_true_align()+".");
            write("Sorry, your alignment does not allow you to do that!");
            return 1;
        }
        str2=replace_string(str2,"  "," ",1);
        if (str2[0] == ' ') str2=replace_string(str2," ","",1);
        if (str2[strlen(str2)-1] == ' ') str2=arrange_string(str2,strlen(str2)-1);
    }

    if(type == "bard" && align < 4)
        return notify_fail("You cannot use your bard spells unless you are of a non-lawful alignment!\n");

    if(type == "monk" && align > 3)
        return notify_fail("You cannot use your monk spells unless you are of a lawful alignment!\n");

    if((type == "paladin" || type == "antipaladin") && (align < 1 || align > 3))
        return notify_fail("You cannot use your paladin spells unless you are of a lawful alignment!\n");

    if(type == "sorcerer" ||
       type == "psion" ||
       type == "psywarrior")
    {
        known = TP->query_mastered_spells(type);
        if(member_array(str2,known) == -1) {
            tell_object(TP,"You haven't mastered such a power!");
            return 1;
        }
    }

    if(type == "bard")
    {
        if(TP->is_wearing_type("armor") && !avatarp(TP))
        {
            tell_object(TP,"You can't cast in all that armor.");
            return 1;
        }
    }

    if(type == "monk")
    {
        known = TP->query_ki_spells();
        if(member_array(str2,known) == -1)
        {
            tell_object(TP,"You know no such ability!");
            return 1;
        }
        if(!TP->is_ok_armour("barb"))
        {
            tell_object(TP, "You must be unarmored in order to use your monk spells.");
            return 1;
        }
        wielded == (object *)TP->query_wielded();
        for(i = 0;i < sizeof(wielded);i++)
        {
            if(!objectp(wielded[i])) continue;
            if((int)wielded[i]->query_size() > 1)
            {
                tell_object(TP, "Your "+wielded[i]->query_short()+" interferes "+
                "with your ability to cast your monk spells!%^RESET%^");
                return 1;
            }
        }
    }

    if(type == "wizard" || type == "mage" || type == "sorcerer" || type == "warlock")
    {
        armor = TP->all_armour();
        armor = distinct_array(armor);
        armor = filter_array(armor,"armor_filter",TO);
        if(FEATS_D->usable_feat(TP,"armored caster") || type == "warlock") armor = filter_array(armor,"light_armor_filter",TO);
    }
    if(type == "psywarrior" || type == "psion")
    {
        if(FEATS_D->usable_feat(TP,"armored manifester") || FEATS_D->usable_feat(TP,"mind before matter"))
        {
            armor = ({});
        }
        else
        {
            armor = TP->all_armour();
            armor = distinct_array(armor);
            armor = filter_array(armor,"armor_filter",TO);
            if(FEATS_D->usable_feat(TP,"armored caster")) armor = filter_array(armor,"light_armor_filter",TO);
        }
    }
    if (FEATS_D->usable_feat(TP,"eldritch conditioning"))
        armor = ({});
    if(sizeof(armor) && !avatarp(TP))
    {
        tell_object(TP,"You cannot cast while wearing all that armor!");
        return 1;
    }

    if(strsrch((string)TP->query("relationship_profile"),"druid_")>=0)
        if(TP->query_property("shapeshifted") && type != "innate" && type != "druid")
        {
            tell_object(TP,"You can only cast druid spells or innate abilities while in druidic form.");
            return 1;
        }


    spell = replace_string(str2," ","_");
    tmp = "/cmds/spells/"+spell[0..0]+"/_"+spell+".c";
    if(!file_exists(tmp))
	{
        write("Either that spell does not exist, or you do not know it!");
        return 1;
    }

    if(healharm)
    {
        targ = find_object_or_load(tmp);
        if (healharm > 0) tmp = HEALS[(int)targ->query_spell_level(type)-1];
        else tmp = HARMS[(int)targ->query_spell_level(type)-1];
        if(!file_exists(tmp))
        {
            write("Garrett fucked up the spell conversions...");
            return 1;
        }
    }

    if(!tar) tar = 0;
    targ = new(tmp);
    if (healharm) targ->set_property("improvised",spell);
    spell = "level "+(int)tmp->query_spell_level(type); //spontaneous caster classes!
    if (type == "bard" || type == "sorcerer" || type == "psywarrior" || type == "psion") targ->set_property("improvised",spell);
    TP->remove_property("spell_casting");
    TP->set_property("spell_casting",targ);
    if(type != "innate")
    {
        targ->wizard_interface(TP,type,tar);
    }
    if(type == "innate")
    {
        targ->use_spell(TP, tar, (int)TP->query_innate_ability_level(str2), 100, "innate");
    }
    return 1;
}

void help() {

    write(
"
%^CYAN%^NAME%^RESET%^

cast

%^CYAN%^SYNTAX%^RESET%^

cast %^ORANGE%^%^ULINE%^CLASS%^RESET%^ %^ORANGE%^%^ULINE%^SPELL%^RESET%^
cast cleric %^ORANGE%^%^ULINE%^SPELL%^RESET%^ as healing|harming

%^CYAN%^DESCRIPTION%^RESET%^

Ivokes %^ORANGE%^%^ULINE%^SPELL%^RESET%^ using character's %^ORANGE%^%^ULINE%^CLASS%^RESET%^.

A %^ORANGE%^%^ULINE%^SPELL%^RESET%^ might or might not have arguments.

See individual spell help files for specific syntax.

%^CYAN%^CLERICS%^RESET%^

Clerics utilize spontaneous casting.

If you're of good alignment you can add the keywords %^ORANGE%^<as healing>%^RESET%^ to your cast invocation to convert the spell you name into a relevant healing (positive energy) spell.

If you're of evil alignment you can add the keywords %^ORANGE%^<as healing>%^RESET%^ to your cast invocation to convert the spell you name into a relevant harming (negative energy) spell.

Neutral clerics can do both.

For example, if you have light spell prepared you can cast it as cure/cause light wounds the next way:

    %^ORANGE%^<cast cleric cure light wounds on %^ORANGE%^%^ULINE%^TARGET%^RESET%^ %^ORANGE%^as healing>%^RESET%^
    %^ORANGE%^<cast cleric cure light wounds on %^ORANGE%^%^ULINE%^TARGET%^RESET%^ %^ORANGE%^as harming>%^RESET%^

Positive energy heals living and harms undead.
Negative energy harms living and heals undead.

%^CYAN%^SEE ALSO%^RESET%^

forget, buff, prepare, spells, recall, dispell
"
        );
}
