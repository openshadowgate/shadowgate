// use the hard_setup function when creating one of these manually somewhere..  ob = new(wand); ob->hard_setup(blah blah)
//doubled weight to 10 and changed them so that they have between 11 and 3 charges - with a higher level spell having fewer charges
//this should still make them useful but should deter the insane collecting of them that is currently happening - Saide - 9/8/2016
#include <std.h>
#include <daemons.h>

// probably have to add more to these as we find/notice them.
#define BAD_SPELLS ({ "alter self","animate object","contingency","exigency","spellstaff","empower weapon","control object","divine weapon","divine shield","eldritch burst","eldritch blast","eldritch chain",\
                      "eldritch claws","eldritch glaive","garble","gate" })

#define CASTING_CLASSES ({ "bard","cleric","druid","mage","paladin","psion","psywarrior","ranger" })

#define TYPES ({ "wand","orb" })

#define GEM_TYPES ({ "diamond","sapphire","ruby","opal","amber","peridot","amethyst","aquamarine","citrine","spinel","topaz","zircon","emerald","quartz" })

#define MATERIALS ({ "bone","dragon bone","ash","maple","ivory","walnut","hickory","oak","pine" })

#define ORB_ADJECTIVES ({ "smooth","shining","glistening","glowing","pulsating" })

#define WAND_ADJECTIVES ({ "straight","twisted","gnarled","short","long","thin","thick" })


inherit OBJECT;


int SETUP,LEVEL,CHARGES,CASTER_LEVEL,TYPE;
string theclass, THE_SPELL;
mapping SPELL_MAP;


int use_wand(string str);
int calculate_charges(int level);
varargs void hard_setup(int max_level, string theclass, string spell, int charges);
varargs void setup_wand(int max_level, string theclass, string spell, int charges);
void calculate_value();
void describe_me();
string color_me(string str);


void create()
{
    LEVEL = 0;
    CHARGES = 0;
    SETUP = 0;
    theclass = 0;
    THE_SPELL = 0;
    CASTER_LEVEL = 0;
    TYPE = "wand";
    SPELL_MAP = ([]);

    ::create();

    set_property("treasure_type", "10A");

    set_weight(10);
    if(!SETUP)
    {
        call_out("setup_wand",0.1);
        //setup_wand();
        set_heart_beat(1);
    }
}


// should randomly setup the wand to a max spell level of 1/3rd of the level of the monster
// with the very large number of spells, high level useful wands should be pretty rare
void heart_beat()
{
    int level;
    if(SETUP)
    {
        set_heart_beat(0);
        return;        
    }
    if (!SETUP)
    {
        if (!objectp(TO)) { return; }
        if (!objectp(ETO)) { return; }
        if (!living(ETO)) { return; }
        level = (int)ETO->query_level();
        if (level > 50) { level = 50; }
        if (!level) { return; }
        level = level / 3;
        hard_setup(level);
        set_heart_beat(0);
        return;
    }
    return;
}


void init()
{
    ::init();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(living(ETO)) add_action("use_wand", "use");
    return;
}


int use_wand(string str)
{
    string *args,file, first_letter, argument,tmp,tmp2;
    object *stuff,wand;
    int spellcraft,roll,DC,failed_by,i;

    if (!SETUP) { return 0; }
    if (!str || str == "" || str == " ") { return 0; }
    if (!objectp(TO) || !objectp(ETO) || !objectp(EETO)) { return 0; }

    if (ETO->query_bound() || ETO->query_unconscious() || ETO->query_paralyzed()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if (!TO->query_wielded())
    {
        tell_object(ETO,"You need to be wielding the " + TYPE + " first.");
        return 1;
    }

    if (sscanf(str, "%s on %s", tmp, tmp2) != 2)
    {
        if (sscanf(str, "%s", tmp) != 1) { return 0; }
    }

    if (!objectp(wand = present(tmp, ETO))) { return 0; }
    if (TO != wand)
    {
        tell_object(ETO, "That's not the right " + TYPE);
        return 1;
    }

    if (tmp2) { str = TYPE + " on " + tmp2; }

    args = explode(str, " ");
    if (!sizeof(args)) { return 0; }

    if (CHARGES != -1)
    {
        if (!CHARGES) 
        { 
            tell_object(ETO,"Your " + TYPE + " has run out of charges.");
            return 1;
        }        
    }

    first_letter = arrange_string(THE_SPELL, 1);
    file = "/cmds/spells/" + first_letter + "/_" + replace_string(THE_SPELL, " ", "_") + ".c";

    spellcraft = (int)ETO->query_skill("spellcraft");
    roll = roll_dice(1, 20);
    DC = CASTER_LEVEL;

    if (theclass == "mage")
    {
        if (ETO->is_class("mage") || ETO->is_class("sorcerer")) { roll = 100; } // auto-pass if they're the same theclass as the wand's spell
    }
    else
    {
        if (ETO->is_class(theclass)) { roll = 100; } // auto-pass if they're the same theclass as the wand's spell
    }

    if ((spellcraft + roll) < DC) { failed_by = DC - (spellcraft + roll); }

    if (failed_by)
    {
        switch (failed_by)
        {
        case 0..4:

            CHARGES--;
            calculate_value();
            tell_object(ETO,"%^YELLOW%^You try to use the " + TYPE + " and a small spark comes out the end, but nothing else seems to happen.%^RESET%^");
            tell_room(EETO, "%^YELLOW%^" + ETO->QCN + " points " + ETO->QP + " " + TYPE + " and concentrates.  A second later a few sparks fizzle from the " + TYPE + ".  "
                "" + ETO->QCN + " looks disappointed.",ETO);
            return 1;

        case 5..10:

            CHARGES--;
            calculate_value();
            EETO->set_property("wild magic", 999);
            file = base_name(new(file)->WildMagicArea(EETO));
            EETO->set_property("wild magic", -999);
            new(file)->use_spell(ETO, ETO, CASTER_LEVEL, 100);
            return 1;

        default:

            CHARGES = 0;
            calculate_value();
            tell_object(ETO, "%^RED%^You try to use the " + TYPE + " and feel a sudden surge of power a split second before it EXPLODES in your hand!%^RESET%^");
            tell_room(EETO, "%^RED%^" + ETO->QCN + " tries to use a " + TYPE + " but it suddenly explodes in "+ETO->QP + " hand!%^RESET%^",ETO);

            ETO->cause_typed_damage(ETO, "left hand", roll_dice(CASTER_LEVEL, 12), "fire");

            stuff = all_inventory(ETO);
            if (sizeof(stuff))
            {
                for (i = 0;i < sizeof(stuff);i++)
                {
                    if (!objectp(stuff[i])) { continue; }
                    if (random(3)) { continue; }
                    tell_object(ETO, "%^YELLOW%^Your " + (string)stuff[i]->query_short() + " is damaged by the force of the explosion!%^RESET%^");
                    stuff[i]->repairMe(roll_dice(1, CASTER_LEVEL*-1));
                }
            }

            return 1;
        }
    }

    if (avatarp(ETO))
    {
        tell_object(ETO, "Debug info for avatars only: \n"
            "LEVEL: " + LEVEL + "\n"
            "CHARGES: " + CHARGES + "\n"
            "CASTER_LEVEL: " + CASTER_LEVEL + "\n"
            "theclass: " + theclass + "\n"
            "THE_SPELL: " + THE_SPELL + "\n");
    }

    if (sizeof(args) == 1)
    {
        new(file)->use_spell(ETO, ETO, CASTER_LEVEL, 100, theclass);
        if (CHARGES != -1) { CHARGES--; }
        calculate_value();
        return 1;
    }

    if (sizeof(args) > 1)
    {
        if (args[1] != "on" || (sizeof(args) < 3)) 
        { 
            tell_object(ETO, "You need to <use " + TYPE + " on target> or <use " + TYPE + " on argument>\n");
            return 1;
        }
    }

    argument = implode( args[2..(sizeof(args) - 1)], " ");

    if (argument == "me") { new(file)->use_spell(ETO, ETO, CASTER_LEVEL, 100, theclass); }
    else { new(file)->use_spell(ETO, argument, CASTER_LEVEL, 100, theclass); }
    if (CHARGES != -1) { CHARGES--; }
    calculate_value();
    return 1;
}


int calculate_charges(int level)
{
    int charges;
    if (!level) { return 1; }
    if (!random(1000)) { return -1; } // 1 out of 1000 chance to have infinite charges
    charges = 12 - level;
    //charges = roll_dice(charges, 6);
    //charges = charges + 4;
    return charges;
}


// this is done so that the treasure daemon can place wands dynamically based on monster level, use hard_setup to create a wand manually
varargs void hard_setup(int max_level, string theclass, string spell, int charges)
{
    SETUP = 1;
    if (objectp(ETO))
    {
        tell_object(ETO, "%^YELLOW%^You feel a surge of magical energy as the " + TYPE + " begins to change.");
    }    
    setup_wand(max_level, theclass, spell, charges);
    return;
}


varargs void setup_wand(int max_level, string theclass, string spell, int charges, int fixed)
{
    string *temp, *spells = ({});
    int i,level,clevel;
    
    if(SETUP && !fixed) { return; }

    if (!stringp(theclass) || theclass == "" || theclass == " " || (member_array(theclass, CASTING_CLASSES) == -1)) { theclass = CASTING_CLASSES[random(sizeof(CASTING_CLASSES))]; }

    theclass = theclass;

    if (!max_level || !intp(max_level)) { max_level = 9; }
    if (max_level < 1) { max_level = 1; }


    if (!stringp(spell) || spell == "" || spell == " ")
    {

        SPELL_MAP = MAGIC_D->query_index(theclass);

        if (!mapp(SPELL_MAP) || !sizeof(keys(SPELL_MAP)))
        {
            throw("ERROR, no spell exists for theclass " + theclass);
            return;
        }

        temp = keys(SPELL_MAP);

        for (i = 0;i < sizeof(temp);i++)
        {
            spell = temp[i];
            level = SPELL_MAP[spell];
            if (level > max_level) { continue; }
            if (member_array(spell, BAD_SPELLS) != -1) { continue; }
            spells += ({ spell });
        }

        if (!sizeof(spells))
        {
            throw("ERROR, no level " + max_level + " spells exist for " + theclass + ".");
            return;
        }
    }

    spell = spells[random(sizeof(spells))];
    level = SPELL_MAP[spell];
    clevel = level * 2;
    clevel = clevel + roll_dice(1, clevel);
    clevel = clevel + 2;

    if (!charges || !intp(charges)) { charges = calculate_charges(level); }
    
    CASTER_LEVEL = clevel;
    CHARGES = charges;
    LEVEL = level;
    THE_SPELL = spell;
    set_property("lore difficulty", CASTER_LEVEL);

    calculate_value();
    describe_me();
    init();
    return;
}


void calculate_value()
{
    int value;

    if (CHARGES == -1) { value = 5000; }
    else { value = CHARGES * 50; }
    value = value * LEVEL;
    value = value * (CASTER_LEVEL / 4);
    set_value(value);  // this may need to get changed at some point, depending on how frequently they end up dropping, observe
    return;
}


void describe_me()
{
    string type,adjective,gem,material;

    switch (theclass)
    {
    case "psion": case "psywarrior":
        type = "orb";
        break;
    default:
        type = "wand";
        break;
    }

    TYPE = type;

    switch (type)
    {
    case "orb":
        adjective = ORB_ADJECTIVES[random(sizeof(ORB_ADJECTIVES))];
        gem = GEM_TYPES[random(sizeof(GEM_TYPES))];
        break;
    case "wand":
        adjective = WAND_ADJECTIVES[random(sizeof(WAND_ADJECTIVES))];
        gem = GEM_TYPES[random(sizeof(GEM_TYPES))];
        material = MATERIALS[random(sizeof(MATERIALS))];
        break;
    }

    if (material) 
    { 
        set_id(({ type, adjective + " " + type,adjective + " " + material + " " + type,type + " of " + THE_SPELL,THE_SPELL }));
        set_name(adjective + " " + material + " " + type);
        set_obvious_short("a " + color_me(adjective) + " " + color_me(material) + " " + color_me(type));

        set_long("%^RESET%^%^BOLD%^This " + color_me(adjective) + " " + color_me(type) + " has been fashioned from a solid piece of " + color_me(material) + ".  "
            "A " + color_me(gem) + " has been fitted to the end of the " + color_me(type) + " and a slight glow can be seen in the heart of it.  "
            "A faint aura of magical power can be detected within the " + color_me(type) + ".");
    }
    else 
    { 
        set_id(({ type,gem + " " + type,type + " of " + THE_SPELL,THE_SPELL }));
        set_name(gem + " " + type);
        set_obvious_short("a " + color_me(adjective) + " " + color_me(gem) + " " + color_me(type));

        set_long("%^RESET%^%^BOLD%^This " + color_me(adjective) + " " + color_me(type) + " is perfectly spherical and would fit into the palm of a "
            "small human.  A faint aura of magical power can be detected deep within the "+color_me(gem)+" "+color_me(type)+".");
    }

    set_short(color_me(type) + " of " + THE_SPELL);

    if (CHARGES == -1) 
    { 
        set_property("added short", ({ "%^RED%^ %^RESET%^(%^RED%^glowing faintly%^RESET%^)%^RESET%^" }));
    }

    set_lore("%^RESET%^%^BOLD%^%^GREEN%^For hundreds of years the secret of imbuing wands with magical spells has been "
        "lost, known only to a very few enchanters who jealously guarded the secret.  Rumor has it that a sorcerer of "
        "Sune seduced an ancient arch mage and was able to steal this secret from the mage's personal collection.  The "
        "Sunite had many lovers and as time passed the knowledge of how to create these wands became more widespread.  "
        "The original formula that was stolen was improved upon many times, to the point where even psionic powers could "
        "be imbued into crystaline orbs.  %^RESET%^%^BOLD%^Your knowledge of academics "
        "tells you that this " + TYPE + " has been imbued with a spell of " + THE_SPELL);

    return;
}


string color_me(string str)
{
    string color;

    switch (str)
    {

    case "wand":            color = "%^ORANGE%^wand";                                                                                                       break;
    case "orb":             color = "%^CYAN%^orb";                                                                                                          break;
    case "diamond":         color = "%^CYAN%^d%^RESET%^i%^BOLD%^a%^RESET%^m%^BOLD%^o%^CYAN%^n%^RESET%^d";                                                   break;
    case "sapphire":        color = "%^BLUE%^s%^CYAN%^a%^RESET%^%^BOLD%^p%^RESET%^p%^RESET%^%^BOLD%^h%^CYAN%^i%^BLUE%^re";                                  break;
    case "ruby":            color = "%^RED%^ru%^RESET%^%^BOLD%^b%^RED%^y";                                                                                  break;
    case "opal":            color = "%^MAGENTA%^o%^RESET%^p%^BOLD%^a%^CYAN%^l";                                                                             break;
    case "amber":           color = "%^YELLOW%^a%^ORANGE%^m%^RESET%^%^BOLD%^b%^ORANGE%^e%^YELLOW%^r";                                                       break;
    case "peridot":         color = "%^GREEN%^p%^RESET%^%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^r%^RESET%^i%^GREEN%^d%^RESET%^%^BOLD%^%^BLACK%^o%^GREEN%^t";    break;
    case "amethyst":        color = "%^MAGENTA%^ame%^RESET%^t%^MAGENTA%^h%^YELLOW%^y%^MAGENTA%^st";                                                         break;
    case "aquamarine":      color = "%^CYAN%^aqu%^BLUE%^a%^CYAN%^mar%^RESET%^i%^CYAN%^ne";                                                                  break;
    case "citrine":         color = "%^YELLOW%^citr%^RESET%^i%^YELLOW%^ne";                                                                                 break;
    case "spinel":          color = "%^BLUE%^spi%^BOLD%^%^GREEN%^n%^BLUE%^el";                                                                              break;
    case "topaz":           color = "%^YELLOW%^t%^RESET%^%^BOLD%^o%^RESET%^p%^YELLOW%^az";                                                                  break;
    case "zircon":          color = "%^RESET%^z%^BOLD%^i%^CYAN%^r%^BLUE%^c%^CYAN%^o%^RESET%^n";                                                             break;           
    case "emerald":         color = "%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^m%^RESET%^%^BOLD%^e%^GREEN%^r%^RESET%^%^GREEN%^ald";                               break;
    case "quartz":          color = "%^RESET%^qua%^BOLD%^r%^BLACK%^t%^RESET%^z";                                                                            break;
    case "bone":            color = "%^BOLD%^%^BLACK%^bo%^RESET%^%^BOLD%^n%^BLACK%^e";                                                                     break;
    case "dragon bone":     color = "%^RED%^dragon %^BOLD%^%^BLACK%^bo%^RESET%^%^BOLD%^n%^BLACK%^e";                                                       break;
    case "ash":             color = "%^BOLD%^%^BLACK%^a%^RESET%^%^BOLD%^s%^BLACK%^h";                                                                      break;
    case "maple":           color = "%^MAGENTA%^m%^YELLOW%^a%^RESET%^%^BOLD%^p%^YELLOW%^l%^MAGENTA%^e";                                                     break;
    case "ivory":           color = "%^RESET%^i%^CYAN%^v%^RESET%^%^BOLD%^o%^CYAN%^r%^RESET%^y";                                                             break;
    case "walnut":          color = "%^ORANGE%^w%^RESET%^%^BOLD%^%^BLACK%^a%^YELLOW%^l%^RESET%^%^BOLD%^%^BLACK%^n%^ORANGE%^u%^YELLOW%^t";                   break;
    case "hickory":         color = "%^YELLOW%^hic%^RESET%^%^BOLD%^%^BLACK%^k%^YELLOW%^ory";                                                                break;
    case "oak":             color = "%^ORANGE%^oak";                                                                                                        break;
    case "pine":            color = "%^YELLOW%^p%^RESET%^i%^YELLOW%^ne";                                                                                    break;
    case "smooth":          color = "sm%^RESET%^o%^CYAN%^o%^RESET%^%^BOLD%^th";                                                                             break;
    case "shining":         color = "%^CYAN%^s%^BLUE%^h%^RESET%^i%^YELLOW%^n%^RESET%^i%^BLUE%^n%^CYAN%^g";                                                  break;
    case "glistening":      color = "%^RESET%^g%^CYAN%^l%^YELLOW%^i%^RESET%^s%^BOLD%^t%^RESET%^e%^YELLOW%^n%^CYAN%^i%^BLUE%^ng";                            break;
    case "glowing":         color = "%^YELLOW%^g%^RESET%^l%^MAGENTA%^o%^GREEN%^w%^BOLD%^%^GREEN%^i%^RESET%^n%^YELLOW%^g";                                   break;
    case "pulsating":       color = "%^BLUE%^p%^RESET%^u%^YELLOW%^l%^CYAN%^s%^YELLOW%^a%^RESET%^t%^MAGENTA%^i%^CYAN%^n%^BLUE%^g";                           break;
    case "straight":        color = "%^GREEN%^str%^RESET%^%^BOLD%^a%^YELLOW%^i%^GREEN%^ght";                                                                break;
    case "twisted":         color = "%^RESET%^%^BOLD%^%^BLACK%^tw%^BLUE%^i%^RESET%^%^BOLD%^s%^BLACK%^ted";                                                  break;
    case "gnarled":         color = "%^RESET%^%^GREEN%^gna%^RESET%^%^BOLD%^r%^GREEN%^l%^RESET%^%^GREEN%^ed";                                                break;
    case "short":           color = "%^MAGENTA%^sho%^RESET%^r%^MAGENTA%^t";                                                                                 break;
    case "long":            color = "%^RESET%^%^BOLD%^%^BLACK%^lo%^RESET%^n%^BOLD%^%^BLACK%^g";                                                             break;
    case "thin":            color = "%^CYAN%^th%^BLUE%^i%^CYAN%^n";                                                                                         break;
    case "thick":           color = "%^RESET%^%^BLUE%^th%^GREEN%^i%^BLUE%^ck";                                                                              break;    
    default:                color = "ERROR, color_me broken in random wands.";                                                                              break;
    }

    color = color + "%^RESET%^%^BOLD%^";
    return color;
}









