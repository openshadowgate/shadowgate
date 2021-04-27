
//Templar Reinforcer - LoKi - 18-02-2008

#include <std.h>
inherit OBJECT;

object ob;


void create(){
    ::create();
    set_name("reinforcer");
    set_id(({"reinforcer","Reinforcer"}));
    set_short("%^RESET%^%^ORANGE%^Temple Reinforcer%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Birthed in the depths of LoKi's mind, "+
"this will 'reinforce' with a templar of your choice. Simply 'reinforce "+
"<challenge> of <diety>. Possible challenges are lowbie, midbie, highbie"+
" or highmortal. Dieties are self explanatory.%^RESET%^\n\n");
    set_weight(1);
    set_value(1);
}

void init() {
   ::init();
   add_action("reinforce","reinforce");
}

void reinforce(string str){
string challenge, diety;
int hp,level,mr,ac,attacks,spellchance;

    if(!str) {
       tell_object(TP, "Try: 'reinforce <challenge>  of <diety> (example "+
"%^YELLOW%^reinforce midbie of torm%^RESET%^). ");
       return 1;
    }
    if(sscanf(str, "%s of %s", challenge, diety)<2){
       tell_object(TP, "Try: 'reinforce <challenge>  of <diety> (example "+
"%^YELLOW%^reinforce midbie of torm%^RESET%^). ");
    }

sscanf(str, "%s of %s", challenge, diety);
        switch(challenge){
            case "lowbie":
                hp = 40;
                ac = 10;
                level = 6;
                mr = 0;
                attacks = 1;
                spellchance = 0;
            break;

            case "midbie":
                hp = 100;
                ac = 5;
                level = 15;
                mr = 10;
                attacks = 2;
                spellchance = 0;
            break;

            case "highbie":
                hp = 250;
                ac = 0;
                level = 20;
                mr = 25;
                attacks = 3;
                spellchance = 10;
            break;

            case "highmortal":
                hp = 400;
                ac = 0;
                level = 40;
                mr = 25;
                attacks = 4;
                spellchance = 20;
            break;

            case "avatar":
                hp = 500;
                ac = 0;
                level = 50;
                mr = 35;
                attacks = 3;
                spellchance = 30;
            break;

            default:
                tell_object(TP, "%^RESET%^%^RED%^That is not a valid "+
"challenge. Challenges are %^BOLD%^lowbie, midbie, highbie, and "+
"highmortal%^RESET%^");
                return 1;
            break;
        }
    
    tell_object(TP,"%^GREEN%^You reinforce the faith of "+diety+" "+
"with a "+challenge+" templar!");
        switch(diety){
            case "akadi":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("akadi");
                ob->set_spell_chance(spellchance);
                ob->set_id(({"templar,templar of Akadi,Akadi templar"}));
                ob->set_short("%^RESET%^a templar of Akadi %^RESET%^"+
"dressed in an immaculate %^BOLD%^%^CYAN%^sky blue %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at "+
"the ready, this templar serves as a protector of the faith.  Dressed"+
" for combat, the trappings of the %^BOLD%^%^CYAN%^Church of Akadi "+
"%^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^CYAN%^sky "+
"blue %^RESET%^%^CYAN%^tabard.  A %^BOLD%^%^WHITE%^white cloud %^RESET%^"+
"%^CYAN%^upon a %^BOLD%^%^BLUE%^blue %^RESET%^%^CYAN%^background "+
"%^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol"+
" is painted upon the sturdy targe shield worn on the right arm.  Under"+
" the tabard, protecting the warrior, is a suit of chainmail armor "+
"that is well maintained and fitted for the wearer's use.  Within quick"+
" reach is a flail, easily taken up if a threat were to loom against "+
"the temple or one of the faithful.%^RESET%^");
                ob->set_speech("say with a wistful tone");
                ob->move(EETO);
            break;

            case "anhur":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("anhur");
                ob->set_id(({"templar,templar of Anhur,Anhur templar"}));
                ob->set_short("%^RESET%^a templar of Anhur %^RESET%^dressed"+
" in an immaculate %^BOLD%^%^RED%^ruby %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the "+
"ready, this templar serves as a protector of the faith.  Dressed for combat,"+
" the trappings of the %^YELLOW%^Church of Anhur %^RESET%^%^CYAN%^are clearly"+
" displayed on the %^BOLD%^%^RED%^ruby %^RESET%^%^CYAN%^tabard.  A %^RESET%^"+
"%^RED%^hawk-headed %^YELLOW%^falchion %^RESET%^%^CYAN%^bound with a %^BOLD%^"+
"%^BLUE%^cord %^RESET%^%^CYAN%^is sewn across the front while a matching holy"+
" symbol is painted upon the sturdy targe shield worn on the right arm.  Under "+
"the tabard, protecting the warrior, is a suit of platemail armor that is well "+
"maintained and fitted for the wearer's use.  Within quick reach is a scimitar,"+
" easily taken up if a threat were to loom against the temple or one of the "+
"faithful.%^RESET%^");
                ob->set_speech("say directly");
                ob->move(EETO);
            break;

            case "auppenser":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("auppenser");
                ob->set_spell_chance(spellchance);
                ob->set_id(({"templar,templar of Auppenser,Auppenser templar"}));
                ob->set_short("%^RESET%^a templar of Auppenser %^RESET%^dressed in an "+
"immaculate %^BOLD%^%^BLUE%^a%^CYAN%^z%^BLUE%^ure %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this "+
"templar serves as a protector of the faith.  Dressed for combat, the trappings of "+
"the %^BOLD%^%^BLUE%^Church of Auppenser %^RESET%^%^CYAN%^are clearly displayed on "+
"the %^BOLD%^%^BLUE%^a%^CYAN%^z%^BLUE%^ure %^RESET%^%^CYAN%^tabard.  A styalized "+
"%^BOLD%^%^BLUE%^blue eye %^RESET%^%^CYAN%^within a %^ORANGE%^bronze oval %^RESET%^"+
"%^CYAN%^is sewn across the front while a matching holy symbol is painted upon the "+
"sturdy targe shield worn on the right arm.  Under the tabard, protecting the warrior,"+
" is a suit of platemail armor that is well maintained and fitted for the wearer's use."+
"  Within quick reach is a kukri, easily taken up if a threat were to loom against the "+
"temple or one of the faithful.%^RESET%^");
                ob->set_speech("give thought before saying");
                ob->move(EETO);
            break;

            case "auril":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("auril");
                ob->set_id(({"templar,templar of Auril,Auril templar"}));
                ob->set_short("%^RESET%^a templar of Auril %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^WHITE%^white %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^WHITE%^"+
"Church of Auril %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^WHITE%^white %^RESET%^"+
"%^CYAN%^tabard.  A %^BOLD%^%^WHITE%^white snowflake %^RESET%^%^CYAN%^superimposed over a %^BOLD%^"+
"%^BLACK%^gray diamond %^RESET%^%^CYAN%^with a %^BOLD%^%^WHITE%^white border %^RESET%^%^CYAN%^is "+
"sewn across the front while a matching holy symbol is painted upon the sturdy targe shield worn "+
"on the right arm.  Under the tabard, protecting the warrior, is a suit of platemail armor that "+
"is well maintained and fitted for the wearer's use.  Within quick reach is a battleaxe, "+
"easily taken up if a threat were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("voice in a cold timber");
                ob->move(EETO);
            break;

            case "bane":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("bane");
                ob->set_spell_chance(spellchance);
                ob->set_id(({"templar,templar of Bane,Bane templar"}));
                ob->set_short("%^RESET%^a templar of Bane %^RESET%^dressed in an "+
"immaculate %^BOLD%^%^GREEN%^green %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this "+
"templar serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^"+
"%^GREEN%^Church of Bane %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^GREEN%^green"+
" %^RESET%^%^CYAN%^tabard.  A %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^, guantleted fist with "+
"rays of %^BOLD%^%^GREEN%^green lightning %^RESET%^%^CYAN%^extending from the knuckles "+
"%^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted upon "+
"the sturdy targe shield worn on the right arm.  Under the tabard, protecting the warrior, "+
"is a suit of platemail armor that is well maintained and fitted for the wearer's use.  "+
"Within quick reach is a morningstar, easily taken up if a threat were to loom against "+
"the temple or one of the faithful.%^RESET%^");
                ob->set_speech("command");
                ob->move(EETO);
            break;

            case "beshaba":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_spell_chance(spellchance);
                ob->set_diety("beshaba");
                ob->set_id(({"templar,templar of Beshaba,Beshaba templar"}));
                ob->set_short("%^RESET%^a templar of Beshaba %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^MAGENTA%^mauve %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^"+
"%^MAGENTA%^Church of Beshaba %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^"+
"%^MAGENTA%^mauve %^RESET%^%^CYAN%^tabard.  A %^BOLD%^%^RED%^red field %^RESET%^%^CYAN%^"+
"with a set of %^BOLD%^%^BLACK%^black antlers %^RESET%^%^CYAN%^in the foreground "+
"%^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted "+
"upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting the "+
"warrior, is a suit of bandedmail armor that is well maintained and fitted for the "+
"wearer's use.  Within quick reach is a scourage, easily taken up if a threat were "+
"to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("lilt with a suggestive arrogance");
                ob->move(EETO);
            break;

            case "cyric":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_id(({"templar,templar of Cyric,Cyric templar"}));
                ob->set_diety("cyric");
                ob->set_short("%^RESET%^a templar of Cyric %^RESET%^dressed in an immaculate "+
"%^RESET%^%^MAGENTA%^purple %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this "+
"templar serves as a protector of the faith.  Dressed for combat, the trappings of "+
"the %^RESET%^%^MAGENTA%^Church of Cyric %^RESET%^%^CYAN%^are clearly displayed on "+
"the %^RESET%^%^MAGENTA%^purple %^RESET%^%^CYAN%^tabard.  A %^BOLD%^%^BLACK%^black "+
"sunburst %^RESET%^%^CYAN%^with a jawless %^RESET%^white skull %^CYAN%^superimposed "+
"%^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted "+
"upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting "+
"the warrior, is a suit of platemail armor that is well maintained and fitted for "+
"the wearer's use.  Within quick reach is a longsword, easily taken up if a threat "+
"were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("cackle with delight");
                ob->move(EETO);
            break;

            case "grumbar":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_diety("grumbar");
                ob->set_spell_chance(spellchance);
                ob->set_id(({"templar,templar of Grumbar,Grumbar templar"}));
                ob->set_short("%^RESET%^a templar of Grumbar %^RESET%^dressed in an immaculate"+
" %^RESET%^%^ORANGE%^brown %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this "+
"templar serves as a protector of the faith.  Dressed for combat, the trappings of the"+
" %^RESET%^%^ORANGE%^Church of Grumbar %^RESET%^%^CYAN%^are clearly displayed on the "+
"%^RESET%^%^ORANGE%^brown %^RESET%^%^CYAN%^tabard.  A %^ORANGE%^mountain range %^CYAN%^"+
"illuminated by a %^MAGENTA%^purple field %^RESET%^%^CYAN%^is sewn across the front "+
"while a matching holy symbol is painted upon the sturdy targe shield worn on the right"+
" arm.  Under the tabard, protecting the warrior, is a suit of platemail armor that is "+
"well maintained and fitted for the wearer's use.  Within quick reach is a warhammer, "+
"easily taken up if a threat were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("intone with a earthy timber");

                ob->move(EETO);
            break;

            case "helm":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("helm");
                ob->set_spell_chance(spellchance);
                ob->set_id(({"templar,templar of Helm,Helm templar"}));
                ob->set_short("%^RESET%^a templar of Helm %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^BLUE%^royal blue %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this "+
"templar serves as a protector of the faith.  Dressed for combat, the trappings of the "+
"%^BOLD%^%^BLUE%^Church of Helm %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^"+
"%^BLUE%^royal blue %^RESET%^%^CYAN%^tabard.  A %^RESET%^steel war guantlet %^CYAN%^with "+
"a watching %^BLUE%^blue eye %^RESET%^%^CYAN%^is sewn across the front while a matching "+
"holy symbol is painted upon the sturdy targe shield worn on the right arm.  Under the "+
"tabard, protecting the warrior, is a suit of platemail armor that is well maintained "+
"and fitted for the wearer's use.  Within quick reach is a bastardsword, easily taken "+
"up if a threat were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("direct with knowledgeable command");
                ob->move(EETO);
            break;

            case "istishia":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("istishia");
                ob->set_id(({"templar,templar of Istishia,Istishia templar"}));
                ob->set_short("%^RESET%^a templar of Istishia %^RESET%^dressed in an immaculate "+
"%^RESET%^%^CYAN%^s%^GREEN%^e%^CYAN%^a g%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^CYAN%^n %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^BLUE%^"+
"Church of Istishia %^RESET%^%^CYAN%^are clearly displayed on the %^RESET%^%^CYAN%^s%^GREEN%^e"+
"%^CYAN%^a g%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^CYAN%^n %^RESET%^%^CYAN%^tabard.  A %^BOLD%^"+
"%^WHITE%^white capped %^RESET%^%^CYAN%^cresting %^BLUE%^wave %^RESET%^%^CYAN%^is sewn across "+
"the front while a matching holy symbol is painted upon the sturdy targe shield worn on the right"+
" arm.  Under the tabard, protecting the warrior, is a suit of leather armor that is well "+
"maintained and fitted for the wearer's use.  Within quick reach is a warhammer, easily taken"+
" up if a threat were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("speak with fluid rolling words");
                ob->move(EETO);
            break;

            case "kelemvor":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("kelemvor");
                ob->set_spell_chance(spellchance);
                ob->set_id(({"templar,templar of Kelemvor,Kelemvor templar"}));
                ob->set_short("%^RESET%^a templar of Kelemvor %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^BLACK%^"+
"Church of Kelemvor %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^BLACK%^gr%^RESET%^"+
"a%^BOLD%^%^BLACK%^y %^RESET%^%^CYAN%^tabard.  A set of %^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^"+
"ld%^YELLOW%^e%^RESET%^%^ORANGE%^n s%^YELLOW%^c%^RESET%^%^ORANGE%^al%^YELLOW%^e%^RESET%^%^ORANGE%^s"+
" %^CYAN%^held by a %^BOLD%^%^WHITE%^skeletal arm %^RESET%^%^CYAN%^is sewn across the front while "+
"a matching holy symbol is painted upon the sturdy targe shield worn on the right arm.  Under the "+
"tabard, protecting the warrior, is a suit of platemail armor that is well maintained and fitted "+
"for the wearer's use.  Within quick reach is a bastardsword, easily taken up if a threat were to "+
"loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("state in a solemn voice");
                ob->move(EETO);
            break;

            case "kossuth":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_spell_chance(spellchance);
                ob->set_diety("kossuth");
                ob->set_id(({"templar,templar of Kossuth,Kossuth templar"}));
                ob->set_short("%^RESET%^a templar of Kossuth %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^RED%^flame red %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^RED%^"+
"Church of Kossuth %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^RED%^flame red %^RESET%^"+
"%^CYAN%^tabard.  A %^RED%^t%^BOLD%^w%^YELLOW%^i%^WHITE%^r%^YELLOW%^l%^RED%^i%^RESET%^%^RED%^ng "+
"red fl%^YELLOW%^a%^RESET%^%^RED%^me %^RESET%^%^CYAN%^is sewn across the front while a matching "+
"holy symbol is painted upon the sturdy targe shield worn on the right arm.  Under the tabard, "+
"protecting the warrior, is a suit of platemail armor that is well maintained and fitted for the "+
"wearer's use.  Within quick reach is a spiked chain, easily taken up if a threat were to loom "+
"against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("say quickly and with passion");
                ob->move(EETO);
            break;

            case "lathander":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("lathander");
                ob->set_id(({"templar,templar of Lathander,Lathander templar"}));
                ob->set_short("%^RESET%^a templar of Lathander %^RESET%^dressed in an immaculate %^BOLD%^%^"+
"MAGENTA%^a%^RESET%^%^MAGENTA%^m%^WHITE%^e%^MAGENTA%^t%^BOLD%^hy%^RESET%^%^MAGENTA%^s%^BOLD%^t %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar serves as a"+
" protector of the faith.  Dressed for combat, the trappings of the %^YELLOW%^Church of Lathander %^RESET%^"+
"%^CYAN%^are clearly displayed on the %^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^m%^WHITE%^e%^MAGENTA%^t%^BOLD%^"+
"hy%^RESET%^%^MAGENTA%^s%^BOLD%^t %^RESET%^%^CYAN%^tabard.  A jewel toned %^YELLOW%^gold%^RESET%^%^CYAN%^, "+
"%^RED%^%^BOLD%^red %^RESET%^%^CYAN%^and %^BOLD%^%^MAGENTA%^rose %^RESET%^%^CYAN%^sunrise lifting from a "+
"field of %^GREEN%^green %^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted"+
" upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting the warrior, is a suit"+
" of platemail armor that is well maintained and fitted for the wearer's use.  Within quick reach is a "+
"heavy mace, easily taken up if a threat were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("lilt with joyous harmony");
                ob->move(EETO);
            break;

            case "malar":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_guild_level("cleric",level);
                ob->set_spell_chance(spellchance);
                ob->set_guild_level("fighter",level);
                ob->set_diety("malar");
                ob->set_id(({"templar,templar of Malar,Malar templar"}));
                ob->set_short("%^RESET%^a templar of Malar %^RESET%^dressed in an immaculate "+
"%^RESET%^%^RED%^blood red %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^RED%^"+
"Church of Malar %^RESET%^%^CYAN%^are clearly displayed on the %^RESET%^%^RED%^blood red "+
"%^RESET%^%^CYAN%^tabard.  A %^ORANGE%^fur covered %^CYAN%^beastial claw with %^RED%^bloody "+
"talons %^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted "+
"upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting the "+
"warrior, is a suit of leather armor that is well maintained and fitted for the wearer's "+
"use.  Within quick reach is a claw, easily taken up if a threat were to loom against the"+
" temple or one of the faithful.%^RESET%^");
                ob->set_speech("growl");
                ob->move(EETO);
            break;

            case "mask":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("mask");
                ob->set_id(({"templar,templar of Mask,Mask templar"}));
                ob->set_short("%^RESET%^a templar of Mask %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^BLACK%^dark gray %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^BLACK%^"+
"Church of Mask %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^BLACK%^dark gray "+
"%^RESET%^%^CYAN%^tabard.  A %^BOLD%^%^BLACK%^black velvet mask %^RESET%^%^CYAN%^tinged with"+
" %^RED%^red %^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted"+
" upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting the warrior"+
", is a suit of leather armor that is well maintained and fitted for the wearer's use.  Within "+
"quick reach is a short sword, easily taken up if a threat were to loom against the temple or "+
"one of the faithful.%^RESET%^");
                ob->set_speech("suggest with soft tones");
                ob->move(EETO);
            break;

            case "mielikki":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("mielikki");
                ob->set_id(({"templar,templar of Mielikki,Mielikki templar"}));
                ob->set_short("%^RESET%^a templar of Mielikki %^RESET%^dressed in an immaculate "+
"%^RESET%^%^GREEN%^forest green %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^RESET%^%^GREEN%^"+
"Church of Mielikki %^RESET%^%^CYAN%^are clearly displayed on the %^RESET%^%^GREEN%^forest green "+
"%^RESET%^%^CYAN%^tabard.  A %^BOLD%^%^BLUE%^blue eyed %^BOLD%^%^WHITE%^unicorn head%^RESET%^"+
"%^CYAN%^ with a %^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^ld%^YELLOW%^e%^RESET%^%^ORANGE%^n"+
"%^CYAN%^ horn %^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is "+
"painted upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting"+
" the warrior, is a suit of leather armor that is well maintained and fitted for the wearer's"+
" use.  Within quick reach is a scimitar, easily taken up if a threat were to loom against"+
" the temple or one of the faithful.%^RESET%^");
                ob->set_speech("speak with a gentle voice");
                ob->move(EETO);
            break;

            case "mystra":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_spell_chance(spellchance);
                ob->set_property("magic resistance",mr);
                ob->set_diety("mystra");
                ob->set_id(({"templar,templar of Mystra,Mystra templar"}));
                ob->set_short("%^RESET%^a templar of Mystra %^RESET%^dressed in an immaculate "+
"%^RESET%^%^BLUE%^midnight blue %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^BLUE%^"+
"Church of Mystra %^RESET%^%^CYAN%^are clearly displayed on the %^RESET%^%^BLUE%^midnight blue "+
"%^RESET%^%^CYAN%^tabard.  A curl of %^RED%^red mist %^CYAN%^rising within a ring of seven "+
"%^BOLD%^%^WHITE%^silver stars %^RESET%^%^CYAN%^is sewn across the front while a matching "+
"holy symbol is painted upon the sturdy targe shield worn on the right arm.  Under the tabard"+
", protecting the warrior, is a suit of bandedmail armor that is well maintained and fitted "+
"for the wearer's use.  Within quick reach is a shuriken, easily taken up if a threat were to"+
" loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("offer contemplatively");
                ob->move(EETO);
            break;

            case "oghma":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_spell_chance(spellchance);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("oghma");
                ob->set_id(({"templar,templar of Oghma,Oghma templar"}));
                ob->set_short("%^RESET%^a templar of Oghma %^RESET%^dressed in an immaculate "+
"%^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^ld %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^RESET%^%^ORANGE%^"+
"Church of Oghma %^RESET%^%^CYAN%^are clearly displayed on the %^RESET%^%^ORANGE%^g%^YELLOW%^o"+
"%^RESET%^%^ORANGE%^ld %^RESET%^%^CYAN%^tabard.  A %^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^ld"+
"%^YELLOW%^e%^RESET%^%^ORANGE%^n s%^YELLOW%^c%^RESET%^%^ORANGE%^r%^YELLOW%^o%^RESET%^%^ORANGE%^"+
"ll%^CYAN%^ void of writing %^RESET%^%^CYAN%^is sewn across the front while a matching holy "+
"symbol is painted upon the sturdy targe shield worn on the right arm.  Under the tabard, "+
"protecting the warrior, is a suit of platemail armor that is well maintained and fitted for"+
" the wearer's use.  Within quick reach is a longsword, easily taken up if a threat were to "+
"loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("consider and then suggests");
                ob->move(EETO);
            break;

            case "selune":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("selune");
                ob->set_id(({"templar,templar of Selune,Selune templar"}));
                ob->set_short("%^RESET%^a templar of Selune %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^WHITE%^"+
"Church of Selune %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^BLACK%^s%^RESET%^i"+
"%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^RESET%^%^CYAN%^tabard.  A set of %^BOLD%^"+
"feminine eyes %^RESET%^%^CYAN%^surrounded by a ring of seven %^BOLD%^%^BLACK%^s%^RESET%^i"+
"%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er s%^RESET%^t%^BOLD%^%^WHITE%^a%^BLACK%^rs "+
"%^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted upon the"+
" sturdy targe shield worn on the right arm.  Under the tabard, protecting the warrior, is "+
"a suit of platemail armor that is well maintained and fitted for the wearer's use.  Within"+
" quick reach is a heavy mace, easily taken up if a threat were to loom against the temple "+
"or one of the faithful.%^RESET%^");
                ob->set_speech("offers with a delicate suggestion");
                ob->move(EETO);
            break;

            case "shar":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("shar");
                ob->set_id(({"templar,templar of Shar,Shar templar"}));
                ob->set_short("%^RESET%^a templar of Shar %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^BLACK%^black %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar"+
" serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^BLACK%^"+
"Church of Shar %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^BLACK%^black %^RESET%^"+
"%^CYAN%^tabard.  A %^BOLD%^%^BLACK%^black disk %^RESET%^%^CYAN%^surrounded by a %^MAGENTA%^dark"+
" purple border %^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted"+
" upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting the warrior, "+
"is a suit of platemail armor that is well maintained and fitted for the wearer's use.  Within "+
"quick reach is a chakram, easily taken up if a threat were to loom against the temple or one of"+
" the faithful.%^RESET%^");
                ob->set_speech("keep something back while saying");
                ob->move(EETO);
            break;

            case "shaundakul":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_spell_chance(spellchance);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("shaundakul");
                ob->set_id(({"templar,templar of Shaundakul,Shaundakul templar"}));
                ob->set_short("%^RESET%^a templar of Shaundakul %^RESET%^dressed in an immaculate "+
"%^RESET%^%^CYAN%^b%^BOLD%^%^BLACK%^l%^RESET%^u%^CYAN%^e g%^BOLD%^%^BLACK%^r%^RESET%^a%^CYAN%^y "+
"%^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^RESET%^"+
"%^MAGENTA%^Church of Shaundakul %^RESET%^%^CYAN%^are clearly displayed on the %^RESET%^"+
"%^CYAN%^b%^BOLD%^%^BLACK%^l%^RESET%^u%^CYAN%^e g%^BOLD%^%^BLACK%^r%^RESET%^a%^CYAN%^y "+
"%^RESET%^%^CYAN%^tabard.  A %^MAGENTA%^deep purple field%^CYAN%^ with a %^BOLD%^%^BLACK%^s"+
"%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er%^RESET%^%^CYAN%^ left hand "+
"encircled by %^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^i%^MAGENTA%^p%^WHITE%^p%^MAGENTA%^l%^CYAN%^i"+
"%^BOLD%^%^BLACK%^ng w%^RESET%^%^CYAN%^i%^MAGENTA%^n%^WHITE%^d%^BOLD%^%^BLACK%^s%^RESET%^ "+
"%^CYAN%^in the foreground %^RESET%^%^CYAN%^is sewn across the front while a matching holy"+
" symbol is painted upon the sturdy targe shield worn on the right arm.  Under the tabard,"+
" protecting the warrior, is a suit of leather armor that is well maintained and fitted for"+
" the wearer's use.  Within quick reach is a greatsword, easily taken up if a threat were to"+
" loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("offer jauntily");
                ob->move(EETO);
            break;

            case "sune":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_spell_chance(spellchance);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("sune");
                ob->set_id(({"templar,templar of Sune,Sune templar"}));
                ob->set_short("%^RESET%^a templar of Sune %^RESET%^dressed in an immaculate "+
"%^RESET%^%^RED%^crimson %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^RED%^"+
"Church of Sune %^RESET%^%^CYAN%^are clearly displayed on the %^RESET%^%^RED%^crimson %^RESET%^"+
"%^CYAN%^tabard.  A feminine face with %^RED%^crimson hair%^CYAN%^, %^BOLD%^%^WHITE%^ivory skin"+
"%^RESET%^%^CYAN%^ and bright %^GREEN%^%^BOLD%^green eyes %^RESET%^%^CYAN%^is sewn across the "+
"front while a matching holy symbol is painted upon the sturdy targe shield worn on the right "+
"arm.  Under the tabard, protecting the warrior, is a suit of platemail armor that is well "+
"maintained and fitted for the wearer's use.  Within quick reach is a whip, easily taken up "+
"if a threat were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("state with passion and desire");
                ob->move(EETO);
            break;

            case "talos":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_spell_chance(spellchance);
                ob->set_diety("talos");
                ob->set_id(({"templar,templar of Talos,Talos templar"}));
                ob->set_short("%^RESET%^a templar of Talos %^RESET%^dressed in an immaculate "+
"%^YELLOW%^yellow %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^YELLOW%^Chuch"+
" of Talos %^RESET%^%^CYAN%^are clearly displayed on the %^YELLOW%^yellow %^RESET%^%^CYAN%^tabard"+
".  A set of three %^YELLOW%^li%^BLACK%^gh%^WHITE%^tn%^BLACK%^in%^YELLOW%^g b%^BLACK%^o%^WHITE%^"+
"l%^BLACK%^ts %^RESET%^%^CYAN%^radiating from a central point %^RESET%^%^CYAN%^is sewn across the"+
" front while a matching holy symbol is painted upon the sturdy targe shield worn on the right arm"+
".  Under the tabard, protecting the warrior, is a suit of platemail armor that is well maintained"+
" and fitted for the wearer's use.  Within quick reach is a spear, easily taken up if a threat were"+
" to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("storm with a booming voice");
                ob->move(EETO);
            break;

            case "tempus":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_diety("tempus");
                ob->set_id(({"templar,templar of Tempus,Tempus templar"}));
                ob->set_short("%^RESET%^a templar of Tempus %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^RED%^red %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^RED%^"+
"Church of Tempus %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^RED%^red %^RESET%^"+
"%^CYAN%^tabard.  A blazing %^BOLD%^%^WHITE%^silver sword %^RESET%^%^CYAN%^over a %^RED%^blood"+
" red shield %^RESET%^%^CYAN%^is sewn across the front while a matching holy symbol is painted"+
" upon the sturdy targe shield worn on the right arm.  Under the tabard, protecting the warrior"+
", is a suit of platemail armor that is well maintained and fitted for the wearer's use.  Within"+
" quick reach is a battleaxe, easily taken up if a threat were to loom against the temple or "+
"one of the faithful.%^RESET%^");
                ob->set_speech("command with power");
                ob->move(EETO);
            break;
            case "torm":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_spell_chance(spellchance);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("torm");
                ob->set_id(({"templar,templar of Torm,Torm templar"}));
                ob->set_short("%^RESET%^a templar of Torm %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^BLUE%^s%^WHITE%^a%^RESET%^%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i%^BOLD%^re %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar"+
" serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^"+
"%^BLUE%^Church of Torm %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^BLUE%^s%^WHITE%^"+
"a%^RESET%^%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i%^BOLD%^re %^RESET%^%^CYAN%^tabard.  A right"+
" %^BOLD%^%^BLACK%^ga%^RESET%^u%^BOLD%^%^WHITE%^n%^RESET%^t%^BOLD%^%^BLACK%^le%^RESET%^t%^BOLD%^"+
"%^WHITE%^e%^BLACK%^d %^RESET%^%^CYAN%^hand held upright with the palm facing forward %^RESET%^"+
"%^CYAN%^is sewn across the front while a matching holy symbol is painted upon the sturdy targe"+
" shield worn on the right arm.  Under the tabard, protecting the warrior, is a suit of platemail"+
" armor that is well maintained and fitted for the wearer's use.  Within quick reach is a "+
"greatsword, easily taken up if a threat were to loom against the temple or one of the "+
"faithful.%^RESET%^");
                ob->set_speech("say with thoughtful words");
                ob->move(EETO);
            break;

            case "tymora":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_property("magic resistance",mr);
                ob->set_spell_chance(spellchance);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_diety("tymora");
                ob->set_id(({"templar,templar of Tymora,Tymora templar"}));
                ob->set_short("%^RESET%^a templar of Tymora %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^BLUE%^blue %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this templar "+
"serves as a protector of the faith.  Dressed for combat, the trappings of the %^BOLD%^%^BLUE%^"+
"Church of Tymora %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^%^BLUE%^blue %^RESET%^"+
"%^CYAN%^tabard.  A %^BOLD%^%^WHITE%^silver coin %^RESET%^with a woman's face surrounded by "+
"%^BOLD%^%^GREEN%^shamrocks %^RESET%^%^CYAN%^is sewn across the front while a matching holy "+
"symbol is painted upon the sturdy targe shield worn on the right arm.  Under the tabard, "+
"protecting the warrior, is a suit of chainmail armor that is well maintained and fitted for "+
"the wearer's use.  Within quick reach is a shuriken, easily taken up if a threat were to "+
"loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("exclaim with gaiety");
                ob->move(EETO);
            break;

            case "tyr":
                ob=new("/realms/loki/templars/mobs/templar.c");
                ob->set_max_hp(hp);
                ob->set_overall_ac(ac);
                ob->set_level(level);
                ob->set_mlevel("fighter",level);
                ob->set_mlevel("cleric",level);
                ob->set_spell_chance(spellchance);
                ob->set_guild_level("cleric",level);
                ob->set_guild_level("fighter",level);
                ob->set_property("magic resistance",mr);
                ob->set_diety("tyr");
                ob->set_id(({"templar,templar of Tyr,Tyr templar"}));
                ob->set_short("%^RESET%^a templar of Tyr %^RESET%^dressed in an immaculate "+
"%^BOLD%^%^WHITE%^platinum %^RESET%^tabard");
                ob->set_long("%^RESET%^%^CYAN%^Standing alert and at the ready, this "+
"templar serves as a protector of the faith.  Dressed for combat, the trappings of the "+
"%^BOLD%^%^WHITE%^Church of Tyr %^RESET%^%^CYAN%^are clearly displayed on the %^BOLD%^"+
"%^WHITE%^platinum %^RESET%^%^CYAN%^tabard.  A set of balanced %^YELLOW%^scales %^RESET%^"+
"%^CYAN%^resting over a %^BOLD%^%^BLACK%^war hammer %^RESET%^%^CYAN%^is sewn across the "+
"front while a matching holy symbol is painted upon the sturdy targe shield worn on the "+
"right arm.  Under the tabard, protecting the warrior, is a suit of platemail armor that "+
"is well maintained and fitted for the wearer's use.  Within quick reach is a longsword, "+
"easily taken up if a threat were to loom against the temple or one of the faithful.%^RESET%^");
                ob->set_speech("state in a direct manner");
                ob->move(EETO);
            break;
           
            default:
                tell_object(TP,"%^RESET%^%^RED%^That is not a valid diety.%^RESET%^");
                return 1;
            break;
}
    return 1;


}


