#include <std.h>
#include <new_exp_table.h>

inherit OBJECT;
int TAR;
string *unlocked_to, *recorded;
string MYQUEST = "%^BOLD%^%^WHITE%^Achieved: %^BOLD%^%^CYAN%^Expanded The "+
                 "Cube of %^CYAN%^I%^WHITE%^nf%^CYAN%^"+
                 "i%^WHITE%^n%^CYAN%^i%^WHITE%^t%^CYAN%^e %^WHITE%^Kn%^CYAN%^"+
                 "owl%^WHITE%^edge%^RESET%^";
void create()
{
    ::create();
    set_name("strange cube");
    set_id(({"cube", "strange cube", "warped cube", "magical cube",
    "dimensional cube", "cube of infinite knowledge", "knowledge cube"}));
    
    set_short("%^BOLD%^%^WHITE%^Cube of %^CYAN%^I%^WHITE%^nf%^CYAN%^"+
    "i%^WHITE%^n%^CYAN%^i%^WHITE%^t%^CYAN%^e %^WHITE%^Kn%^CYAN%^"+
    "owl%^WHITE%^edge%^RESET%^");
    
    set_obvious_short("strange cube");
    
    set_long("%^BOLD%^%^WHITE%^This strange cube is composed from a "+
    "silver material. It is very sturdy and no amount of pressure seems to have "+
    "any impact on it. There are elaborate %^BOLD%^%^CYAN%^symbols%^BOLD%^%^WHITE%^"+
    " carved into each side of it. The symbols depict books, scrolls, and the knowledge "+
    "contained within them. However, they offer no hint at what that knowledge might be or "+
    "anyway in which it might be accessed. A profoundly powerful magical aura is being "+
    "given off by the cube, it is almost overwhelming.%^RESET%^");

    set_lore("%^BOLD%^%^WHITE%^This cube was a recent creation by a man named "+
    "Dygarius Elwood. Dygarius wanted to create a way to document all the knowledge "+
    "hidden through the realm, so he created this cube with the intention of using it "+
    "to absorb knowledge about items and creatures found through out the world. "+
    "It is rumored that he also locked the cube in such a way that only one who he thought"+
    " to %^CYAN%^bestow%^WHITE%^ access to could use it. If one were granted such access "+
    "he or she could use the cube to %^CYAN%^record%^WHITE%^ information about an item "+
    "or a creature. It is also rumored that the cube would only record information about "+
    "magical items or strange creatures that are not typically found wandering the "+
    "safe streets that Dygarius himself has been known to wander.%^RESET%^");
    set_property("lore difficulty", 10);
    set_value(10000);
    set_weight(1);
    recorded = ({});
    unlocked_to = ({"dygarius"});
    TAR = 100;
}


void init()
{
    ::init();
    add_action("bestow","bestow");
    add_action("record", "record");
}

void check_recorded()
{
    int y, perc, myExp, lvl;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!living(ETO)) return;
    if(!objectp(EETO)) return;
    if(member_array(ETO->query_true_name(), unlocked_to) == -1) return;
    y = sizeof(recorded);
    perc = percent(y, TAR);
    switch(perc)
    {
        case 0..10:
            tell_object(ETO, "%^BOLD%^%^WHITE%^The knowledge within the cube "+
            "is still miniscule compared what it is capable of understanding."+
            "%^RESET%^");
            return 1;
        case 11..25:
            tell_object(ETO, "%^BOLD%^%^WHITE%^The knowledge within the cube "+
            "is continuing to expand, but it still far from reaching capacity."+
            "%^RESET%^");
            return 1;
        case 26..50:
            tell_object(ETO, "%^BOLD%^%^WHITE%^The knowledge within the cube "+
            "continus to expand, approaching the half-way point of what it is "+
            "able to contain.%^RESET%^");
            return 1;
        case 51..75:
            tell_object(ETO, "%^BOLD%^%^WHITE%^The knowledge within the cube "+
            "grows closer to its apex.%^RESET%^");
            return 1;
        case 76..99:
            tell_object(ETO, "%^BOLD%^%^WHITE%^The knowledge within the cube "+
            "grows ever closer to its apex!%^RESET%^");
            return 1;
        case 100..200:
            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the powerful aura of magic "+
            "from the cube wash over you and you feel your mind flooded with knowledge!");
            lvl = (int)ETO->query_character_level();
            if(lvl < sizeof(EXP_NEEDED) && (lvl-1) < sizeof(EXP_NEEDED)) myExp = EXP_NEEDED[lvl] - EXP_NEEDED[(lvl-1)];
            else myExp = 100000;
            myExp / 2;
            if(member_array(MYQUEST, (string *)ETO->query_mini_quests()) == -1)
            {
                ETO->set_mini_quest(MYQUEST, myExp, MYQUEST);
                tell_object(ETO, "%^BOLD%^%^WHITE%^You feel more experienced!%^RESET%^");
                tell_object(ETO, "%^BOLD%^%^WHITE%^You have gained the innate ability to "+
                "cure moderate wounds!%^RESET%^");
                ETO->add_bonus_innate((["cure moderate wounds" : (["type" : "spell", "casting level" : 10, 
                "daily uses" : 2, "delay" : 1, "uses left" : 2]),]));        
            }
            
            tell_object(ETO, "%^BOLD%^%^WHITE%^The cube vanishes in an explosion of "+
            "harmless but %^BOLD%^%^YELLOW%^c%^MAGENTA%^o%^CYAN%^l%^BLACK%^o%^WHITE%^r"+
            "%^YELLOW%^f%^MAGENTA%^u%^CYAN%^l %^WHITE%^light!%^RESET%^");
            tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s cube vanishes in an explosion of "+
            "harmless but %^BOLD%^%^YELLOW%^c%^MAGENTA%^o%^CYAN%^l%^BLACK%^o%^WHITE%^r"+
            "%^YELLOW%^f%^MAGENTA%^u%^CYAN%^l %^WHITE%^light!%^RESET%^", ETO);
            TO->remove();
            return 1;
    }
    return;
}

int bestow(string str)
{
    object targ;
    string myName, theirName;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    myName = ETO->query_name();
    if(member_array(myName, unlocked_to) == -1) return 0;
    if(!str)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^Who do you wish to "+
        "bestow access to?");
        return 1;
    }
    if(!objectp(targ = present(str, EETO)))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^There is no one by "+
        "the name "+str+" here.");
        return 1;
    }
    if(!userp(targ))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You cannot bestow access to "+
        "the cube to "+targ->QCN+".");
        return 1;
    }
    theirName = targ->query_true_name();
    if(member_array(theirName, unlocked_to) != -1)
    {
        tell_object(TP, targ->QCN+"%^BOLD%^%^RED%^ already has access "+
        "to the cube.%^RESET%^");
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You focus intently on "+
    targ->QCN+" and bestow access to the cube to "+targ->QO+"!");
    
    tell_object(targ, ETOQCN+"%^BOLD%^%^WHITE%^ focuses intently on "+
    "you and you feel your knowledge expand as "+ETO->QS+" bestows access "+
    "to "+ETO->QP+" cube to you.%^RESET%^");
    
    tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ focuses intently on "+
    targ->QCN+"!%^RESET%^", ({targ, ETO}));
    unlocked_to += ({theirName});
    return 1;    
}

int record(string str)
{
    object targ;
    string myName, fileName;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    myName = ETO->query_name();
    if(member_array(myName, unlocked_to) == -1) return 0;
    if(!str)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^What do you wish to "+
        "use the cube to record?%^RESET%^");
        return 1;
    }
    if(!objectp(targ = present(str, ETO)))
    {
        if(!objectp(targ = present(str, EETO)))
        {
            tell_object(ETO, "%^BOLD%^%^RED%^There is no "+str+
            " here.%^RESET%^");
            return 1;
        }
    }
    if(targ == TO || base_name(targ) == base_name(TO))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The cube will not record "+
        "information about itself.%^RESET%^");
        return 1;
    }
    if(userp(targ))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The cube warms to your touch "+
        "for a brief instant but fails to record anything...%^RESET%^");
        return 1;
    }
    fileName = base_name(targ);
    if(!pointerp(recorded)) recorded = ({});
    if(member_array(fileName, recorded) != -1)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The cube warms to your touch "+
        "for a brief instant but does nothing, as it has already recorded "+
        "information about "+targ->QCN+"!%^RESET%^");
        return 1;
    }
    if(living(targ))
    {
        if(targ->is_townsman() && targ->is_npc())
        {
            tell_object(ETO, "%^BOLD%^%^RED%^The cube warms to your touch "+
            "for a brief instant but fails to record anything...%^RESET%^");
            return 1;
        }
        tell_object(ETO, "%^BOLD%^%^WHITE%^You focus on the cube and "+
        targ->QCN+" carefully, allowing the cube to record information "+
        "about "+targ->QCN+"!%^RESET%^");
        
        tell_object(targ, ETOQCN+"%^BOLD%^%^WHITE%^ starts focusing on "+
        ETO->QP+" cube and you intently... you feel something invisible probing "+
        "your mind for a brief instant... it does not feel intrusive.. before it "+
        "fades away.%^RESET%^");
        
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ starts focusing on "+
        ETO->QP+" cube and "+targ->QCN+" intently, as "+targ->QCN+" seems "+
        "momentarily perplexed!%^RESET%^", ({targ, ETO}));
        recorded += ({fileName});
        check_recorded();
        return 1;
    }
    if(!targ->isMagic())
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The cube warms to your touch "+
        "for a brief instant but does nothing.%^RESET%^");
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You focus on the cube and "+
    targ->QCN+" carefully, allowing the cube to record information "+
    "about "+targ->QCN+"!%^RESET%^");
    
    tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ starts focusing on "+
    ETO->QP+" cube and "+targ->QCN+" intently!%^RESET%^", ({ETO}));
    
    recorded += ({fileName});
    check_recorded();
    return 1;        
}
