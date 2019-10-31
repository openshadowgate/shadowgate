#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <schoolspells.h>
#include <psions.h>
#include <monks.h>

#define NO_EFFECT -100
inherit DAEMON;

#include <spellcomponents.h>

/**
 * @file
 * @brief Parent for all spells
 */


string spell_name,
    spell_type,
    rspell_name,
    spell_sphere,
    cast_string,
    cname,
    arg,
    my_diety,
    mydiscipline,
    *my_class,
    *immune,
    spell_domain,
    damage_desc,
    save_type,
    syntax,
    description,
    casting_stat,
    psyclass,
    aoe_message,
    *supreme_healer_spells,
    *natures_gift_spells;

static int FULL_EFFECT = 100;

mixed WildMagicArea(object where);

int spell_level,
    silent_casting,
    target_required,
    spell_duration,
    affixed_level,
    clevel,
    sdamage,
    sdamage_adjustment,
    duration,
    non_living_ok,
    xp_bonus,
    verbal_comp,
    somatic_comp,
    arg_needed,
    peace,
    cast_time,
    swarm,
    toattack,
    any_attack,
    hasBeenCast,
    preloaded,
    reg_num,
    quest_spell,
    mage_only,
    save_debug,
    help_or_harm,
    casting_stat_bonus,
    wasreflected,
    pcost,
    mypp,
    mycost,
    healing_spell,
    aoe_spell,
    traveling_aoe_spell,
    splash_spell,
    permanent,
    evil_spell;



object *attackers,
        caster,
        target,
        place,
        original_caster,
        original_target;

mapping spell_levels;
mapping components;
mapping feats_required;
mapping magic_resisted = ([]);

//  Function Prototypes

void set_diety(string who);
void set_spell_name(string name);
void set_spell_level(mapping levels);
void set_spell_sphere(string sphere);
void set_components(mapping temp);
string query_components_value(string myclass);
void set_feats_required(mapping temp);
string query_feat_required(string myclass);
void set_syntax(string synt);
void set_description(string descript);
void set_cast_string(string str);
void set_silent_casting(int a);
void set_target_required(int a);
void wizard_interface(object user, string type, string targ);
varargs void use_spell(object ob, mixed targ, int ob_level, int prof, string classtype);
//fsvoid spell_effect(int prof);
void dest_effect();
void before_cast_dest_effect();
void spell_successful();
void set_spell_duration();
void set_verbal_comp();
void set_somatic_comp();
void set_immunities(string *arr);
void set_xp_bonus(int xp);
void define_clevel();
varargs void damage_targ(object victim, string hit_limb, int wound, string damage_type);
varargs void do_spell_damage(object victim, string hit_limb, int wound, string damage_type);
void death_check(object fool);
void set_arg_needed();
void set_non_living_ok(int ok);
void set_discipline(string what);
void set_save(string save);
void debug_saves(int num);
void set_helpful_spell(int x);
void get_casting_stat();
void set_caster(object ob);

int preSpell();
int query_spell_duration();
int check_light(object caster);
int query_target_required();
int query_xp_bonus();
int check_fizzle(object ob);
int spell_kill(object victim, object caster);
int ok_to_kill(object targ);
int remove();
int query_helpful();
int check_point_cost(int plvl);
int evade_splash(object splashtarg);

varargs int checkMagicResistance(object victim, int mod);
string get_save();

object query_caster();
object query_target();
object query_place();

void set_target(object ob);

string query_diety();
string query_discipline();
string query_spell_level(string classtype);
string *query_immunities();
void    removeSpellFromCaster();

varargs int do_saving_throw(object player, string type, int mod);

// Added for use with the new cleric domain spells
void set_spell_domain(string domain);
string get_spell_domain();

// New saving throw
varargs int do_save(object targ,int mod);

// Interface for the permanent spell daemon to use to reactivate
// persistent spells upon startup.
int preload_interface(
    int arg_reg_num,
    object arg_target,
    string arg_cname,
    int arg_clevel
);

//END prototypes

int clean_up() {
    if(objectp(caster)) { return 1; }
    ::clean_up();
    return 1;
}

void check_me()
{
    if(!objectp(caster))
    {
	//adding this so that if a mob casts a spell
	//such as chill touch on a player and the mob dies,
	//spell should not get removed if the target is still valid - Saide
		if(query_target_required() && !objectp(target))
    	{
			if(objectp(TO)) { TO->remove(); }
			return;
		}
    }
	//believe this is really screwing spells, like
	//phantasmal killer, that are cast on a target but
	//later don't require the target to still be alive up - Saide
    /*if(query_target_required() && !objectp(target))
    {
        if(objectp(TO)) { TO->remove(); }
    }*/
    call_out("check_me",5);
}


void create() {
    ::create();
    immune = allocate(10);
    call_out("check_me",5);
}

void set_diety(string who) {
    if (!who) my_diety = "me";
    else my_diety = who;
}

string query_diety() {
    if (my_diety) return my_diety;
    else return "me";
}

void set_discipline(string who) {
    if (!who) mydiscipline = "me";
    else mydiscipline = who;
}

string query_discipline() {
    if (mydiscipline) return mydiscipline;
    else return "me";
}

void set_mage_only(int mystate) { //used for non-sorcerer school-specific spells for mages. -N, 8/10.
    mage_only = mystate;
}

int query_mage_only() {
    return mage_only;
}

void set_non_living_ok(int ok) {
    non_living_ok = 1;
}

void set_spell_name(string name) {
    spell_name = name;
}

void set_spell_level(mapping levels) {
    int i;
    string *levelkeys;

    spell_levels = levels;
    levelkeys = keys(levels);
    spell_level = 0;
    for(i=0;i<sizeof(levelkeys);i++) {
      if(spell_levels[levelkeys[i]] > spell_level) spell_level = spell_levels[levelkeys[i]];
    }
}

void set_affixed_spell_level(int x)
{
    if(x)
        affixed_level = x;
    else
        affixed_level = 1;
}

void set_components(mapping temp) {
    if (!components) components = ([]);
    components = temp;
}

int query_components_value(string myclass) {
    string *compkeys;
    int i, value;
    mapping compmap;

    if (!components) components = ([]);
    if(myclass == "sorcerer") myclass = "mage";
    if(!components[myclass]) return 0;
    compkeys = keys(components[myclass]);
    if(!sizeof(compkeys)) return 0;
    value = 0;
    compmap = COMPONENTS1;
    for(i=0;i<sizeof(compkeys);i++) {
      if(compmap[compkeys[i]]) value += (compmap[compkeys[i]] * components[myclass][compkeys[i]]);
    }
    return value;
}

void set_description(string descript) {
    if(!descript) description = "";
    description = descript;
}

void set_syntax(string synt) {
    if(!synt) syntax = "";
    syntax = synt;
}

void set_damage_desc(string desc)
{
    damage_desc = desc;
}

void set_spell_duration() {    duration = 1; }
void set_spell_sphere(string sphere) { spell_sphere = sphere; }
void set_cast_string(string str) {  cast_string = str; }
void set_silent_casting(int a) {    silent_casting = a; }
void set_target_required(int a) {   target_required = a; }
void set_verbal_comp() {    verbal_comp = 1; }
void set_somatic_comp() {   somatic_comp = 1; }
void aoe_spell(int num) { aoe_spell = num; }
int query_aoe_spell() { return aoe_spell; }
void traveling_aoe_spell(int num) { traveling_aoe_spell = num; }
int query_traveling_aoe_spell() { return traveling_aoe_spell; }
void set_healing_spell(int num) { healing_spell = num; }
int query_healing_spell() { return healing_spell; }
void evil_spell(int num) { evil_spell = num; }
int query_evil_spell() { return evil_spell; }
void splash_spell(int num) { splash_spell = num; }
int query_splash_spell() {return splash_spell;}
void set_aoe_message(string str) { aoe_message = str; }
string query_aoe_message() { return aoe_message; }

void set_feats_required(mapping temp) {
    if (!feats_required) feats_required = ([]);
    feats_required = temp;
}

string query_feat_required(string myclass) {
    if(!feats_required) feats_required = ([]);
    if(feats_required[myclass]) return feats_required[myclass];
    return "me";
}

mapping query_feats_required() {
    if(!feats_required)
        feats_required = ([]);
    return feats_required;
}

void startCasting()
{
    object *inven;
    int i,j,roll,targroll,displayflag;
    string displaystring, printstring;

    if (silent_casting)
        return;

    inven = all_living(ETP);
    roll = TP->query_skill("spellcraft")+ roll_dice(1,20);
    if(TP->usable_feat("elusive spellcraft"))
        roll += roll_dice(1,20);
    displaystring = (string)TO->query_cast_string()+"\n";
    if(displaystring == "0\n") displaystring = "%^BOLD%^%^WHITE%^"+TPQCN+" starts casting a spell.%^RESET%^\n";
    if(displaystring == "display\n") displayflag = 1;
    if(!TP->query_invis() && userp(target)) printstring = "%^YELLOW%^You recognize this spell as "+spell_name+", aimed at "+target->QCN+"!%^RESET%^";
    else printstring = "%^YELLOW%^You recognize this spell as "+spell_name+"!%^RESET%^";

    j = sizeof(inven);
    for (i=0;i<j;i++) {
      if(inven[i] == TP) continue;
      if(!objectp(inven[i])) continue;
      targroll = inven[i]->query_skill("spellcraft") + roll_dice(1,20);
      if(roll <= targroll) {
        if(!displayflag) tell_object(inven[i],displaystring+printstring);
        else tell_object(inven[i],printstring);
      }
      else {
        if(roll <= (targroll - 10)) {
          if(!displayflag) tell_object(inven[i],displaystring);
        }
      }
    }
    return;
}

object find_compbag(string component, int amnt, string myclass){
   object compBag;
   int i = 1;
   while (compBag = present("compx "+i, caster))
   {
        if ((int)compBag->query_comp(component) >= amnt) return compBag;
        i++;
   }
}

// used to remove the perfect caster feat from a player after they have reflected a spell
// need this to prevent parties from killing each other because of reflection
void remove_reflection_effects(object o_caster,object o_targ)
{
    if(objectp(o_caster))
    {
        o_caster->set_casting(0);
        original_caster = 0;
    }

    if(objectp(o_targ))
    {
        o_targ->set_casting(0);
        if(!o_targ->query_property("temp_perfect_caster"))
        {
            o_targ = 0;
            return;
        }
        o_targ->remove_property("temp_perfect_caster");
        o_targ->remove_temporary_feat("perfect caster");
    }
    return;
}

int query_helpful() { return help_or_harm; }
void set_helpful_spell(int x)
{
	help_or_harm = x;
}


int check_reflection()
{
    int turnperc, flagz;
    object temp;

    if(!objectp(caster)) { return 0; }
    if(!objectp(target)) { return 0; }
    if(target == caster)   { return 0; }
    if(target->query_unconscious() || target->query_ghost() || target->query_bound()) { return 0; }

    //should prevent any spells labeled as helpful from being reflected - Saide
    if((int)TO->query_helpful()) return 0;

    //adding new property for spellturning spells and items
    // changing this to prevent stacking feats, and allow them to stack one-off with armor - aligned with current balance meta. N, 7/15.

    flagz = 0;
    if(FEATS_D->usable_feat(target,"spell reflection")) flagz = 1;
    if(FEATS_D->usable_feat(target,"reflection") && target->is_wearing_type("shield")) flagz = 2;
    switch(flagz)
    {
    case 1:
        turnperc = (int)target->query_skill("spellcraft")/3;
        break;
    case 2:
        turnperc = (int)target->query_skill("athletics")/3;
        break;
    default:
        turnperc = 0;
        break;
    }
    if(!turnperc)
        if(flagz==1||flagz==2)
            turnperc = 15;

    turnperc += (int)target->query_property("spellturning");
    if(turnperc < 0) turnperc = 0;
    if(turnperc > 85) turnperc = 85;
    if(!turnperc) return 0;

    if(turnperc > roll_dice(1,100))
    {
        if(!FEATS_D->usable_feat(target,"perfect caster"))
        {
            target->add_temporary_feat("perfect caster");
            target->set_property("temp_perfect_caster",1);
        }

        if(flagz == 2)
        {
            tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+"'s spell is reflected off of your "
                "shield back at "+caster->QO+"!%^RESET%^");
            tell_object(caster,"%^BOLD%^%^RED%^Your spell is reflected back at you off of "
                ""+target->QCN+"'s shield!%^RESET%^");
            tell_room(environment(target),"%^BOLD%^%^RED%^"+caster->QCN+"'s spell is reflected "
                "off of "+target->QCN+"'s shield!%^RESET%^",({caster,target}));
            if(FEATS_D->usable_feat(target,"counter"))
            {
                if(random(2)) { target->counter_attack(target); }
            }
        }
        else
        {
            tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+"'s spell bounces harmlessly off your "
                "ward and reflects back at "+caster->QO+"!%^RESET%^");
            tell_object(caster,"%^BOLD%^%^RED%^Your spell is reflected back at you off of "
                +target->QCN+"'s ward!%^RESET%^");
            tell_room(environment(target),"%^BOLD%^%^RED%^"+caster->QCN+"'s spell bounces "
                "harmlessly off "+target->QCN+"'s ward and reflects back "
                "at "+caster->QCN+"!%^RESET%^",({caster,target}));
        }
        original_caster = caster;
        original_target = target;
        temp = caster;
        caster = target;
        target = temp;
        wasreflected = 1;
        return 1;
    }
    return 0;
}

//Wizard interface is what's called from _cast (_chant).
//  user is the caster, targ is the string arguments sent to the spell.
//  added "whatsit" to designate between spell/power for psions ~C~ 7/15/05
void wizard_interface(object user, string type, string targ)
{
    int mp_req, x;
    mapping comp;
    string *comp_names, msg, whatsit, whatdo, improv, old_spell_type, featneeded, altclass,way;
    object *weaps, compbag, wildspell, wpcaster, shapeob;
    int nodo, i, casting_level;

    if(!type)
    {
        tell_object(caster, "Something has gone wrong, the spell has no type specified!");
        TO->remove();
        return;
    }
    spell_type = type;
    if(spell_type == "antipaladin") spell_type = "paladin"; // casting til the antipaladin class is removed.

    switch(type)
    {
    case "psion": case "psywarrior":
        whatsit = "power"; whatdo = "manifest"; old_spell_type = "psionics";
        break;
    case "monk":
        whatsit = "spell"; whatdo = "focus"; old_spell_type = "wizard";
        break;
    case "bard":
        whatsit = "song"; whatdo = "intone"; old_spell_type = "wizard";
        break;
    case "priest": case "cleric": case "ranger": case "paladin":
        whatsit = "spell"; whatdo = "chant"; old_spell_type = "priest";
        break;
    case "warlock":
        whatsit = "invocation"; whatdo = "cast"; old_spell_type = "wizard";
        break;
    default:
        whatsit = "spell"; whatdo = "cast"; old_spell_type = "wizard";
        break;
    }


    if(user->is_class("psion")){ psyclass = "psion"; altclass = "psywarrior"; }
    if(user->is_class("psywarrior")){ psyclass = "psywarrior"; altclass = "psion"; }

    if(user->is_class("psion") || user->is_class("psywarrior"))
    {
        if(FEATS_D->usable_feat(user,"expanded knowledge 3") && ((string)TO->query_spell_name() == (string)user->query("expanded_knowledge_3")))
        {
            if(!TO->query_spell_level(psyclass))
            {
                spell_type = altclass;
            }
        }
        if(FEATS_D->usable_feat(user,"expanded knowledge 2") && ((string)TO->query_spell_name() == (string)user->query("expanded_knowledge_2")))
        {
            if(!TO->query_spell_level(psyclass))
            {
                spell_type = altclass;
            }
        }
        if(FEATS_D->usable_feat(user,"expanded knowledge 1") && ((string)TO->query_spell_name() == (string)user->query("expanded_knowledge_1")))
        {
            if(!TO->query_spell_level(psyclass))
            {
                spell_type = altclass;
            }
        }
        if( (FEATS_D->usable_feat(user,"body cognition") || FEATS_D->usable_feat(user,"mind over matter")) && ((string)TO->query_spell_name() == "true metabolism"))
        {
            if(!TO->query_spell_level(psyclass))
            {
                spell_type = altclass;
            }
        }
        if( ( FEATS_D->usable_feat(user,"presence of mind") || FEATS_D->usable_feat(user, "mental fortress") ) && ((string)TO->query_spell_name() == "timeless body"))
        {
            if(!TO->query_spell_level(psyclass))
            {
                spell_type = altclass;
            }
        }
    }

    casting_level = query_spell_level(spell_type);

    if(!casting_level)
    {
        tell_object(user, "The "+spell_type+" class cannot cast such a spell!\n");
        TO->remove();
        return;
    }

    comp = TO->query_components(spell_type);
    comp_names = ({});
    if (!comp) comp = ([]);
    if (!user) return 0;

    set_caster(user); ////
    seteuid(getuid());

    if(query_aoe_spell())
    {
        if(sizeof(caster->query_property("aoe list"))>2)
        {
            tell_object(caster,"You can't concentrate on that many effects!");
            ::remove();
            return;
        }
        if(caster->has_aoe(query_spell_name()))
        {
            tell_object(caster,"You can't concentrate on more than one area effect at a time!");
            ::remove();
            return;
        }
    }

    cname = caster->query_name();
    //If we get an argument string from the cast command
    if (targ)
    {
        //If we DON'T need argument.  E.G. we want to specify
        //  a target object and not send args to the spell
        if (!arg_needed)
        {
            if ( (targ == "me") || (targ == "self") || (targ == "myself"))
                target = caster;
            else
                if ( (targ == "here") || (targ == "room") )
                    target = environment(caster);

            if (!target && (objectp(targ) || stringp(targ)) )
                target = present(targ, environment(caster));
            if (!target)
            {
                tell_object(caster, "That is not here!");
                TO->remove();
                return;
            }

            if ((!living(target)) && (!non_living_ok))
            {
                tell_object(caster, "That is not a living being!");
                TO->remove();
                return;
            }
        }
        else
        {
            arg = targ;
        }
    }

    //Set the room the spell was cast in
    place = environment(caster);
    if(objectp(place))
    {
        if(interactive(place)) { place = environment(environment(caster)); }
    }

    //We need a target, but we don't have one!
    if(target_required)
    {
        if (!targ)
        {
            tell_object(caster,"You must CHOOSE a target for this "+whatsit+"!");
            TO->remove();
            return;
        }
        if ((!(check_light(caster)) && target != caster && target != environment(caster)) ||
        (caster->query_blind() && target != caster && target != environment(caster)) )
        {
            tell_object(caster,"You can't see your target!");
            TO->remove();
            return;
        }
    }

    //If you can't be in combat to cast the spell
    if (peace)
    {
        if ((object *)caster->query_attackers() != ({}))
        {
            tell_object(caster,"You must be at peace to use this "+whatsit+".");
            TO->remove();
            return;
        }
    }

    //If you need to be able to move your hands to cast
    if (somatic_comp)
    {
/* if we decide to check for having hands to support morph spells denial or lost hands
* I think this should do it but it needs tested *Styx* 8/21/05
*	if( (member_array("right hand", caster->query_limbs()) == -1)
*  || (member_array("left hand", caster->query_limbs()) == -1) ) {
*            tell_object(caster, "You have no hands with which to "+whatdo+" this "+whatsit+"!");
*	    TO->remove();
*	    return;
*        }
*/
        weaps = caster->query_wielded();
        if (weaps != ({}) &&
            (!caster->query_property("shapeshifted") ||
             (string)TP->query("relationship_profile") == "spell_alter_self_999" ||
             (string)TP->query("relationship_profile") == "shadow_apotheosis"))
        {
            for (i=0;i<sizeof(weaps);i++)
            {
                if(spell_type == "monk")
                {
                    if((int)weaps[i]->query_size() > 1)
                    {
                        tell_object(caster, "Your "+weaps[i]->query_short()+" interferes "+
                            "with your attempt to cast your monk spell!");
                        TO->remove();
                        return;
                    }
                    else continue;
                }
                if (!weaps[i]->query_property("able to cast"))
                    nodo = 1;
            }
            if(spell_type == "psywarrior" || spell_type == "psion")
            {
                if(FEATS_D->usable_feat(caster,"combat manifester") ||
                   FEATS_D->usable_feat(caster,"mind before matter"))
                {
                    nodo = 0;
                }
            }
            if (FEATS_D->usable_feat(caster,"eldritch conditioning"))
                nodo = 0;
            if (FEATS_D->usable_feat(caster,"bladesong") &&
                sizeof(weaps)==1 &&
                !caster->is_wearing_type("shield"))
                nodo = 0;
            if (nodo)
            {
                tell_object(caster, "Your hands must be free to "+whatdo+" this "+whatsit+"!");
                TO->remove();
                return;
            }
        }
        if(caster->query_bound())
        {
            TP->send_paralyzed_message("info",TP);
            TO->remove();
            return;
        }
    }

    //If you need to be able to speak to cast the spell
    if (verbal_comp)
    {
        if(place->query_property("silence") || caster->query_gagged())
        {
            tell_object(caster, "You must be able to speak to "+whatdo+" this "+whatsit+"!");
            TO->remove();
            return;
        }
    }

    // welcome to the new casting restrictions on melee-powered forms! Currently applies to druid shapeshifts (except elemental), as well as rage & transformation spells.
    // this only allows the casting of helpful spelltypes, and only if non- or self-targetted with no arguments. Ie. no complex casting or nuking. N, 10/15.
    if(caster->query_property("raged") ||
       caster->query_property("transformed"))
    {
        if (!FEATS_D->usable_feat(caster, "ragecaster"))
        {
            if(!help_or_harm)
            {
                tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                TO->remove();
                return;
            }
            if(arg_needed || (target_required && target != caster))
            {
                tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                TO->remove();
                return;
            }
        }
    }
    if(caster->query_property("shapeshifted"))
    {
        shapeob = caster->query_property("shapeshifted");
        if(!objectp(shapeob))
        {
            tell_object(caster, "Your shapeshift has glitched! Please contact an imm.");
            TO->remove();
            return;
        }
        if(strsrch((string)caster->query("relationship_profile"),"druid_")>=0)
            if((string)caster->query("relationship_profile") != "druid_elemental_999" &&
               !FEATS_D->usable_feat(caster, "ragecaster"))
            {
                if(!shapeob->can_cast())
                {
                    tell_object(caster, "You can't cast while shapeshifted unless you have the wild spellcraft feat.");
                    TO->remove();
                    return;
                }
                if(!help_or_harm)
                { // only spells flagged as helpful work in these states
                    tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                    TO->remove();
                    return;
                }
                if(arg_needed || (target_required && target != caster))
                { // only non-arg and non- or self-targetted spells
                    tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                    TO->remove();
                    return;
                }
            }
        if(!shapeob->can_cast())
        {
            tell_object(caster, "You can't cast while in this form!");
            TO->remove();
            return;
        }
    }

    //Need components bag present

    if(spell_type == "sorcerer")
    {
        if (mapp(components["mage"])) comp_names = keys(components["mage"]);
    }
    else if(spell_type == "monk")
    {
        comp_names = ({});
    }
    else
    {
        if (mapp(components[spell_type])) comp_names = keys(components[spell_type]);
    }

    //Check to see if the caster can actually cast that spell.
    // using old_spell_type so the daemon doesn't have to be modified at this point.
    // Psywarriors cannot use the old cast type
    if(caster->is_class("psywarrior"))
    {
        caster->set_cast_type("psywarrior");
    }
    else
    {
        caster->set_cast_type(lower_case(old_spell_type));
    }

    if (!"/daemon/magic_d"->can_cast(caster, casting_level, spell_type, spell_name, spell_duration) &&
        (!stringp(improv=query_property("improvised")) ||
         !"/daemon/magic_d"->can_cast(caster, casting_level, spell_type, improv, spell_duration) ) )
    {
        tell_object(caster, "You cannot "+whatdo+" that "+whatsit+".\n");
        TO->remove();
        return;
    }

    //add psion when they switch to power points - remember to adjust for spellmastery, if they get it
    if(spell_type == "psywarrior" || (spell_type == "psion"))
    {
        mycost = check_point_cost(casting_level);
        if(!mycost)
        {
            tell_object(caster,"Something is wrong with the point cost for this "+whatsit+". Please contact a wiz.");
            TO->remove();
            return;
        }
        else
        {
            mypp = caster->query_mp();
            if(mypp < mycost)
            {
                tell_object(caster,"You do not have enough power points to "+whatdo+" that "+whatsit+"!");
                TO->remove();
                return;
            }
        }
    }

    if(spell_type == "monk")
    {
        way = caster->query("monk way");
        if(FEATS_D->usable_feat(caster,"grandmaster of the way")) { way = "grandmaster of the way"; }

        if(!stringp(way))
        {
            tell_object(caster, "You do not have a monk specialization set. You must visit your temple and "+
            "choose one!");
            TO->remove();
            return;
        }
        if(!KI_COST[way])
        {
            tell_object(caster, "Something is wrong with the ki cost for this "+whatsit+". Please contact a wiz.");
            TO->remove();
            return;
        }
        mycost = KI_COST[way][spell_name];
        if(!mycost)
        {
            tell_object(caster, "Something is wrong with the ki cost for this "+whatsit+". Please contact a wiz.");
            TO->remove();
            return;
        }
        if(!caster->spend_ki(mycost))
        {
            tell_object(caster, "You do not have enough available ki to "+whatdo+" that "+whatsit+"!");
            TO->remove();
            return;
        }
    }

    // time for a new check for feat-based spells! N, 7/15.
    featneeded = query_feat_required(spell_type);
    if(featneeded != "me" && !FEATS_D->usable_feat(caster,featneeded))
    {
        tell_object(caster, "You cannot "+whatdo+" that "+whatsit+".\n");
        TO->remove();
        return;
    }

    define_clevel();
    define_base_spell_level_bonus();
    define_base_damage(0);

    msg = caster->get_static("spell interrupt");
    if(stringp(msg))
    {
        tell_object(caster,msg);
        remove();
        return;
    }
    if (!preSpell())
    {
        if(objectp(TO)) { TO->remove(); }
        return;
    }

    supreme_healer_spells = ({ "cure light wounds", "cure moderate wounds", "cure serious wounds", "cure critical wounds", "mass cure light wounds", "mass cure moderate wounds", "mass cure serious wounds", "mass cure critical wounds", "regeneration", "aura of healing", });

    natures_gift_spells = ({ "faerie fire","entangle","animal messenger","spider climb","meld into nature",
        "wall of thorns","treestride","insect plague","wall of stone","regeneration" });

// improv code; if nothing supplied, improv defaults to the spell being cast
    if (!stringp(improv=query_property("improvised"))) improv=spell_name;
    spell_name = replace_string(spell_name,"_"," ");
    improv = replace_string(improv,"_"," ");

    if((!FEATS_D->usable_feat(caster,"spellmastery") || (spell_name != (string)caster->query("spellmastery_spell"))) &&
    (!FEATS_D->usable_feat(caster,"supreme healer") || (member_array(spell_name,supreme_healer_spells) == -1)) &&
    (!FEATS_D->usable_feat(caster,"natures gift") || (member_array(spell_name,natures_gift_spells) == -1)) &&
    (!FEATS_D->usable_feat(caster,"expanded knowledge 1") || (spell_name != (string)caster->query("expanded_knowledge_1"))) &&
    (!FEATS_D->usable_feat(caster,"expanded knowledge 2") || (spell_name != (string)caster->query("expanded_knowledge_2"))) &&
    (!FEATS_D->usable_feat(caster,"expanded knowledge 3") || (spell_name != (string)caster->query("expanded_knowledge_3"))) &&
    ((!FEATS_D->usable_feat(caster,"body cognition") && !FEATS_D->usable_feat(caster,"mind over matter")) || (spell_name != "true metabolism")) &&
    ((!FEATS_D->usable_feat(caster,"presence of mind") && !FEATS_D->usable_feat(caster, "mental fortress")) || (spell_name != "timeless body")))
    {
// only bother checking memorized if it's not spellmastered or part of expanded knowledge/epic feats
        if(!caster->check_memorized(spell_type,improv))
        {
            tell_object(caster, "You cannot "+whatdo+" this "+whatsit+" at this time.");
            TO->remove();
            return;
        }
    }

    caster->set_casting(1);
    if (0)
    {
        if(target) TP->setAdminBlock(100);
        else TP->setAdminBlock(100);
    }

    tell_object(caster,"You begin to "+whatdo+" the "+whatsit+"!");

    if(objectp(target)) { check_reflection(); } // this is needed for PCs, uses different function than mobs
    if(wasreflected) { caster->set_casting(0); }

    startCasting();

    if(query_aoe_spell()) {
        caster->add_aoe(query_spell_name());
        if(stringp(aoe_message))
            place->set_property("aoe_messages",({ aoe_message }));
        else
            place->set_property("aoe_messages",({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
    }

    if(objectp(wildspell = WildMagicArea(environment(caster))))
    {
        caster->remove_property("spell_casting");
        caster->set_property("spell_casting", wildspell);
        if (cast_time) { place->set_round(wildspell,(int)place->query_stage()+cast_time); }
        else { place->set_round(wildspell,(int)place->query_stage()+casting_level); }
        TO->remove();
        return;
    }

    if (cast_time) { place->set_round(TO,(int)place->query_stage()+cast_time); }
    else { place->set_round(TO,(int)place->query_stage()+casting_level); }
    return;
}


//Function to copy variables from this spell to a new one
//in order to make wild magic function like I intend - Saide
void init_vars(object cast, object targ, object where, int lev)
{
	caster = cast;
	target = targ;
	place = where;
	clevel = lev;
}
//End

//Filter Function to make sure spells like
//mind net and whispering wind aren't being picked....
//may have to add more if it bugs or figure out a way to handle
//these spells

mixed special_spell_handling(string which)
{
	string *bad_spells = ({"whispering wind", "mindnet", "minor creation"});
	if(!stringp(which)) return 0;
	if(member_array(which, bad_spells) != -1) return 0;
	return 1;
}

//End filter function


//This is the function that checks if an area is a wild magic area
//if it is - this function is going to figure out which new spell
//to make happen - or if a new spell will happen - basically
//this is the meat of the wild magic code - Saide
//Wanna have wild magic function with two properties set in the
//room - the first one - set_property("wild magic", % chance)
//the second one - set_property("wild magic affect",
//({"same" || "random" || "specific class", For the type of spell - same class by default
//"same level" || "random level" || "specific level", For the level of spell cast - same level
//by default
//"psion immune" - 1 for immune, 0 for not - 1 by default, since their powers are mental - Ungrim/Josephs
//thought and it makes sense

mixed WildMagicArea(object where)
{
    object nspell;
    int psi_immune, slev, count;
    mixed wmlev, *wm_affect = ({});
    string wmclass, file, rspell, wm_notify;
    string *aoelist;

    psi_immune = 1;
    slev = query_spell_level(spell_type);
    wmlev = slev;
    wmclass = spell_type;

    if(!objectp(where))
    {
        return 0;
    }

    if(where->query_property("wild magic") > roll_dice(1, 100))
    {
        wm_affect = where->query_property("wild magic affect");
        if(!stringp(wm_notify = where->query_property("wild magic warning")))
        {
            wm_notify = "%^BOLD%^%^RED%^You sense an unseen force "+
            "manipulating your incantation!%^RESET%^";
        }
        if(!sizeof(wm_affect))
        {
            //if(spell_type == "psion") return 0;
            rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
            count = 0;
            while(!special_spell_handling(rspell))
            {
                count++;
                if(count > 5) return 0;
                rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
            }
            file = MAGIC_D->get_spell_file_name(rspell);
            if(!file_exists(file)) return 0;
            nspell = new(file);
            nspell->init_vars(caster, target, place, clevel);
            tell_object(caster, wm_notify);
            return nspell;
        }

        switch(sizeof(wm_affect))
        {
            case 1:
                wmclass = wm_affect[0];
                break;
            case 2:
                wmclass = wm_affect[0];
                wmlev = wm_affect[1];
                break;
            case 3:
                wmclass = wm_affect[0];
                wmlev = wm_affect[1];
                if(intp(wm_affect[2])) psi_immune = wm_affect[2];
                break;
        }

        if(wmclass == "same") wmclass = spell_type;
        if(wmlev == "same") wmlev = slev;
        if(wmlev == "random") wmlev = -1;
        if(!intp(wmlev)) wmlev = slev;
        if(psi_immune != 1) psi_immune = 0;
        if(spell_type == "psion" && psi_immune == 1) return 0;
        rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
        count = 0;
        while(!special_spell_handling(rspell))
        {
            count++;
            if(count > 5) return 0;
            rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
        }
        file = MAGIC_D->get_spell_file_name(rspell);
        if(!file_exists(file)) return 0;
        nspell = new(file);
        if(!objectp(caster)) return 0;
        if(!objectp(target)) target = caster;
        if(!objectp(place)) place = environment(caster);
        nspell->init_vars(caster, target, place, clevel);
        tell_object(caster, wm_notify);

        if(!nspell->query_aoe_spell()) {
            caster->subtract_aoe(nspell->query_spell_name());
            if(stringp(aoe_message))
                place->remove_property_value("aoe_messages",({ aoe_message }));
            else
                place->remove_property_value("aoe_messages",({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
        }

        return nspell;

    }
    return 0;
}

varargs void use_spell(object ob, mixed targ, int ob_level, int prof, string classtype)
{
    string msg, whatsit, whatdo, *myclasses;
    mixed innate_spells;

    if(!objectp(TO)) { return; }
    if(!objectp(ob)) { return; }

    set_caster(ob);
    clevel = ob_level;
    seteuid(getuid());

    if(classtype == "innate")
    {
        if(!(innate_spells = caster->query_innate_spells()))
        {
            tell_object(caster, "You have no innate spell of "+
            spell_name+".");
            TO->remove();
            return;
        }
        if(member_array(spell_name, innate_spells) == -1)
        {
            tell_object(caster, "You have no innate spell of "+
            spell_name+".");
            TO->remove();
            return;
        }
        if(!caster->can_use_innate_ability(spell_name))
        {
            tell_object(caster, "You cannot use the innate spell "+
            spell_name+" at this time.");
            TO->remove();
            return;
        }
        if(clevel < 1) clevel = 1;
    }

    myclasses = keys(spell_levels);
    if (!sizeof(myclasses))
    {
        tell_object(caster, "No classes specified for this spell, contact a wiz.");
        TO->remove();
        return;
    }

    if(stringp(classtype))
        spell_type = classtype;
    else
        spell_type = myclasses[0];

    if (member_array(spell_type,myclasses) == -1 && spell_type != "innate" && spell_type != "potion")
    {
        tell_object(caster, "Invalid caster class specified to "+
        "invoke this spell, contact a wiz.");
        TO->remove();
        return;
    }

    if(spell_type == "psion" || spell_type == "psywarrior")
    {
        whatdo = "manifest";
        whatsit = "power";
    }
    else if(spell_type == "innate")
    {
        whatdo = "use";
        whatsit = "innate spell";
    }
    else
    {
        whatdo = "cast";
        whatsit = "spell";
    }

    cname = caster->query_name();

    if (!targ && target_required)
    {
        tell_object(caster, "Target needed.");
        TO->remove();
        return;
    }
    if(!prof) prof == FULL_EFFECT;

    if(targ)
    {
        if (arg_needed)
        {
            arg = targ;
            place = environment(caster);
        }
        else
        {
            if(caster->is_room()) target = present(targ,caster);
            else if(objectp(environment(caster))) target = present(targ,environment(caster));
        }

        if(!target)
        {
            if(objectp(environment(caster)) && objectp(environment(environment(caster))))
            {
                if (environment(environment(caster))) target = present(targ,environment(environment(caster)));
                if (!target)
                {
                    tell_object(caster, "That is not here!\n");
                    TO->remove();
                    return;
                }
            }
        }
        place=environment(caster);
    }

    else
    {
        if(objectp(environment(caster))) place=environment(caster);
        else
        {
            if(objectp(environment(environment(caster)))) place=environment(environment(caster));
        }
        if(interactive(place) && objectp(environment(environment(caster)))) place=environment(environment(caster));
    }

    if(!objectp(place))
    {
        TO->remove();
        return;
    }

    // giving them the ability to cast from items while they're interrupted -Ares
    // changing this so that it's only skipped for users (eg/ using contingency, items, scrolls etc),
    // as it is preventing any silence effects from working on NPCs/mobs. N, 8/12.
    if(!userp(caster))
    {
        msg = caster->query_property("spell interrupt");
        if (!msg) msg = caster->get_static("spell interrupt");
        if(stringp(msg))
        {
            tell_object(caster,msg);
            remove();
            return;
        }
    }
    define_base_spell_level_bonus();
    define_base_damage(0);

    if(!preSpell())
    {
        TO->remove();
        return;
    }

    if(query_aoe_spell())
    {
        if(caster->has_aoe(query_spell_name()))
        {
            tell_object(caster,"You can't concentrate on more than one area effect at a time!");
            ::remove();
            return;
        }
    }

    // moving this up here cuz otherwise the prof dies (for backfires) and it gets cast locked. N, 6/15.
    if(spell_type == "potion")
    {
        TO->spell_effect(prof);
        return 1;
    }

    if (living(caster) && base_name(PO) != "/d/magic/obj/contingency")
    {
        tell_object(caster,"You begin to "+whatdo+" the "+whatsit+"!");
        if(spell_type!="innate")
            tell_room(environment(caster),caster->QCN+
                      " begins to "+whatdo+" a "+whatsit+"!", caster);

        if(objectp(target) && target != caster) { check_reflection(); }

        if (cast_time)
        {
            place->set_round(TO,(int)place->query_stage()+cast_time);
        }
        else
        {
            place->set_round(TO,(int)place->query_stage()+spell_level);
        }

        caster->set_casting(1);
        if(query_aoe_spell()) {
            caster->add_aoe(query_spell_name());
            if(stringp(aoe_message))
                place->set_property("aoe_messages",({ aoe_message }));
            else
                place->set_property("aoe_messages",({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
        }
    }
    else
    {
        TO->spell_effect(prof);
    }
    return 1;
}

string query_spell_name() {  return spell_name; }
string query_name() {        return spell_name; }

int query_spell_level(string classtype) {
  if(!mapp(spell_levels)) spell_levels = ([]);

// safeguards til we can filter the old class types out of the system. Nienne, 05/10
  if(affixed_level)
      return affixed_level;
  if(classtype == "priest" && spell_levels["cleric"]) return spell_levels["cleric"];
  if(classtype == "priest" && spell_levels["ranger"]) return spell_levels["ranger"];
  if(classtype == "priest" && spell_levels["paladin"]) return spell_levels["paladin"];
  if(classtype == "wizard" && spell_levels["mage"]) return spell_levels["mage"];
  if(classtype == "wizard" && spell_levels["bard"]) return spell_levels["bard"];
  if(classtype == "psionics" && spell_levels["psion"]) return spell_levels["psion"];
  if(classtype == "sorcerer") return spell_levels["mage"];


  if(!spell_levels[classtype])
      return 0;
  return spell_levels[classtype];
}

int query_spell_level_map() { if(!mapp(spell_levels)) spell_levels = ([]); return spell_levels; }

mapping query_components(string classtype) {
  if(!mapp(components)) components = ([]);
  if(classtype == "sorcerer") classtype = "mage";
  if(!mapp(components[classtype])) return ([]);
  return components[classtype];
}

string query_spell_type() {  return spell_type; }
string query_spell_sphere() { return spell_sphere; }
string query_cast_string() { }
int query_silent_casting() {  return silent_casting; }

void set_caster(object ob){
   caster = ob;
   get_casting_stat();
}

object query_caster() {
    if (living(previous_object()))
        if ( (previous_object()->query_hp()) < 1 ) {
            if(!objectp(caster)) { return 0; }
            if (living(environment(caster)))
                return environment(caster);
        }
    return caster;
}

object query_target_object() { return target; }

void set_target(object targ){  target = targ; }

int query_target_required() {  return target_required; }

int query_clevel() {    return clevel; }

int query_place() {    return place; }

int query_spell_duration() {
    if (!duration)
        return 0;
    else
        return ROUND_LENGTH * spell_level;
}

// local function to get saving throws -- Thorn 950620
varargs int do_saving_throw(object player, string type, int mod) {
    int temp;
    if(FEATS_D->usable_feat(caster,"spell focus"))          { mod -= 4; }

    if (!type) temp = "/daemon/saving_d.c"->saving_throw(player, "spell", mod);
    else temp = "/daemon/saving_d.c"->saving_throw(player, type, mod);
    return temp;
}

int check_light(object caster) {
    if(!caster->light_blind(0)) return 1;
    if (caster->query_blind()) return 0;
    else return 1;
}

string *query_immunities() {    return immune; }

void set_immunities(string *arr) {
    immune=arr;
    return 1;
}

void set_xp_bonus(int xp) {    xp_bonus = xp; }
int query_xp_bonus() {    return xp_bonus; }

void execute_attack() { check_fizzle(caster); }

void init() { }

void check_fizzle(object ob) {
    int fizzle, i,  prof;
    string *immunities, before, after, whatsit;
    whatsit = "spell";
    if(spell_type == "psion") whatsit = "power";

    fizzle=0;
//    caster = ob;
    if(!objectp(ob) && objectp(caster)) ob = caster;
    else if(caster != ob && objectp(ob)) set_caster(ob);
    if (hasBeenCast) {
        return;
    }
    hasBeenCast = 1;

    if (!caster || !objectp(caster)) {
        TO->remove();
        return;
    }
    caster->set_casting(0);
     if ((object)caster->query_property("spell_casting") == TO)
     caster->remove_property("spell_casting");
    if (objectp(place)) {
        place->remove_combatant(TO);
    }

    if (target_required && !target) {
        caster->removeAdminBlock();
        TO->remove();
        return;
    }

    if(objectp(target))
        if(!(spell_type=="warlock" ||
             spell_type=="monk"))
            if((int)target->query_property("spell invulnerability")>query_spell_level(spell_type))
            {
                tell_object(caster,"%^CYAN%^Your "+whatsit+" f%^BOLD%^i%^RESET%^%^CYAN%^zzles harmlessly.");
                tell_room(place,"%^CYAN%^"+caster->QCN+"'s "+whatsit+" f%^BOLD%^i%^RESET%^%^CYAN%^zzles harmlessly .",caster);
                caster->removeAdminBlock();
                TO->remove();
                return;
            }

    if (fizzle || place->query_property("no magic")) {
        tell_object(caster,"%^CYAN%^Your "+whatsit+" fizzles harmlessly.");
        tell_room(place,"%^CYAN%^"+caster->QCN+"'s "+whatsit+" fizzles harmlessly.");
        caster->removeAdminBlock();
        TO->remove();
        return;
    }

    if (clevel < place->query_property("antimagic field"))
    {
        tell_object(caster,"%^CYAN%^Your "+whatsit+" fizzles harmlessly.");
        tell_room(place,"%^CYAN%^"+caster->QCN+"'s "+whatsit+" fizzles harmlessly.");
        caster->removeAdminBlock();
        TO->remove();
        return;
    }

    prof = TO->calculate_prof_state();

/*
    if((string)caster->query_name() == "tristan") {
        tell_object(caster,"prof = "+prof);
    }
*/
        caster->removeAdminBlock();
    if(prof >= FULL_EFFECT)
    {
        TO->spell_effect(prof);
    } else if(prof < random(100)) {
        TO->do_spell_blowup(prof);
    } else {
        TO->spell_effect(prof);
    }

    if (objectp(caster)) {
        caster->increment_stamina(spell_level*2);
    }
    return 1;
}

int calculate_prof_state(){
    if(query_spell_type() != "mage" && query_spell_type() != "bard") {
        return FULL_EFFECT;
    }
    if(!caster->query_property("spell test")) {
        return FULL_EFFECT;
    }
/*
    if((string)caster->query_name() == "tristan") {
        tell_object(caster,"real prof = "+caster->query_spell_prof_level(query_spell_name()));
    }
*/
    return (caster->query_spell_prof_level(query_spell_name())+(random(60)-30));
}

void do_spell_blowup(int prof){
    MAGIC_D->spell_failure(TO,prof);
}

void spell_successful() //revoked exp bonuses from casting. This function seems redundant now? Nienne, 06/10.
{
    int stat;
    if (!objectp(TO) || !objectp(caster)) return;
    remove_reflection_effects(original_caster,original_target);

    if(mycost && (caster->is_class("psion") || caster->is_class("psywarrior")) )
    {
        if(FEATS_D->usable_feat(caster,"perfect manifesting"))
        {
            stat = caster->query_stats("intelligence");
            stat += 30;
            if(random(100) < stat)
            {
                tell_object(caster,"%^BOLD%^%^WHITE%^Your concentration is so perfect that you feel no loss of power points as you manifest the power!%^RESET%^");
                return 1;
            }
        }
        if(caster->query_property("clearcasting"))
        {
            caster->remove_property("clearcasting");
            tell_object(caster,"%^BOLD%^%^WHITE%^Your concentration is so great that you feel no loss of power points as you manifest the power!%^RESET%^");
            return 1;
        }
        mycost = mycost*-1;
        caster->add_mp(mycost);
        if((int)caster->query_mp() < 0) caster->set_mp(0); //fail safe to avoid problems with negative points
        mycost = 0; // on the off chance something calls spell_successful() more than once, don't charge them twice
    }

    return 1;
}

void before_cast_dest_effect()
{
    remove_reflection_effects(original_caster,original_target);
    removeSpellFromCaster();
    if(query_aoe_spell())
    {
        if(objectp(caster) &&
           caster->has_aoe(query_spell_name()))
            caster->subtract_aoe(query_spell_name());
        if(objectp(place)) {
            if(stringp(aoe_message))
                place->remove_property_value("aoe_messages",({ aoe_message }));
            else
                place->remove_property_value("aoe_messages",({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
        }
    }
    if(objectp(TO)) TO->remove();
    return;
}

void dest_effect()
{
    if(query_aoe_spell() &&
       objectp(caster) &&
       caster->has_aoe(query_spell_name()))
        caster->subtract_aoe(query_spell_name());
    before_cast_dest_effect();
    return;
}

int remove()
{
    if(!objectp(TO)) return 1;
    if(query_aoe_spell() &&
       objectp(caster) &&
       caster->has_aoe(query_spell_name()))
        caster->subtract_aoe(query_spell_name());
    return ::remove();
}

int is_spell() {    return 1; }

void sendDisbursedMessage(object victim){
    string whatsit;
    whatsit = "magic";
    if(spell_type == "psion" || spell_type == "psywarrior") whatsit = "power";
    if(!objectp(victim)) return;
    if(objectp(caster)) {
        tell_object(victim,"%^BOLD%^%^YELLOW%^"+caster->QCN+"'s "+whatsit+" disperses futilely around you.%^RESET%^");
        if (present(caster,environment(victim))) {
            tell_object(caster,"%^BOLD%^%^YELLOW%^Your "+whatsit+" disperses futilely around "+victim->QCN+".%^RESET%^");
        }
        tell_room(environment(victim),"%^BOLD%^%^YELLOW%^"+caster->QCN+"'s "+whatsit+" disperses futilely around "+victim->QCN+".",({ victim, caster}) );
        return 1;
    }
    tell_object(victim,"%^BOLD%^%^YELLOW%^The "+whatsit+" disperses futilely around you.%^RESET%^");
    tell_room(environment(victim),"%^BOLD%^%^YELLOW%^The "+whatsit+" cast from a dead or unknown source disperses futilely around "+victim->QCN+".",({victim}));
    return 1;
}

varargs int damage_targ(object victim, string hit_limb, int wound, string damage_type) {
    if (!victim)
        return 1;

    if (!objectp(caster))
        return 1;

    do_spell_damage(victim,hit_limb, wound,damage_type);
}

varargs int do_spell_damage( object victim, string hit_limb, int wound,string damage_type)
{
    int nokill, reduction, spmod;
    string *limbs=({});
    nokill = 1;

    if(!objectp(victim)) { return; }
    if(!living(victim)) { return; }

    limbs = victim->query_limbs();

    if(!sizeof(limbs)) { return notify_fail(""+identify(victim)+" has no valid limbs."); }

    if(member_array(hit_limb,limbs) == -1) { hit_limb = limbs[random(sizeof(limbs))]; }

    if(objectp(caster))
    {
        if(caster->ok_to_kill(victim))
            nokill=0;
    }

    spmod = clevel; // spmod = base spell penetration
    if(!spmod)
        spmod = 1;
    spmod += (int)caster->query_property("spell penetration"); // add spell pen to base caster level

    if(checkMagicResistance(victim,spmod) || nokill)
    {
        sendDisbursedMessage(victim);
        return 1;
    }

    if(!(spell_type=="warlock"||
         spell_type=="monk"))
        if(victim->query_property("spell invulnerability")>query_spell_level(spell_type))
        {
            tell_object(caster,"%^CYAN%^Your spell dissipates around "+victim->QCN+".");
            tell_room(place,"%^CYAN%^"+caster->QCN+"'s spell dissipates around "+victim->QCN+".",caster);
            TO->remove();
            return 1;
        }

    if(place->query_property("antimagic field")>clevel)
    {
        tell_object(caster,"%^CYAN%^Your spell dissipates around "+victim->QCN+".");
        tell_room(place,"%^CYAN%^"+caster->QCN+"'s spell dissipates around "+victim->QCN+".",caster);
        TO->remove();
        return 1;
    }

    if(!stringp(damage_type) || damage_type == "" || damage_type == " ") { damage_type = "untyped"; }

    wound = (int)COMBAT_D->typed_damage_modification(caster, victim, hit_limb, wound, damage_type);

    victim->cause_damage_to(victim, hit_limb, wound);

    if(victim != caster &&
       victim != environment(caster) &&
       !victim->query_ghost() &&
       !nokill &&
       wound > 0)
    {
        if(present(victim, caster) ||
           present(victim, environment(caster)))
        {
            spell_kill(victim,caster);
            victim->add_attacker(caster);
        }
        else
        {
            victim->add_attacker(TO);
            victim->check_death();
            victim->remove_attacker(TO);
        }
        victim->set_toattack(1);
    }

    return 1;
}

void define_clevel()
{
    int highest;

    clevel = caster->query_guild_level(spell_type);

    if(spell_type == "psion" || spell_type == "psywarrior")
        clevel = max(({caster->query_guild_level("psion"),caster->query_guild_level("psywarrior")}));
    if(spell_type == "monk" && FEATS_D->usable_feat(caster, "elemental attunement"))
        clevel += 5;
    if(spell_type == "mage" && caster->query_school())
    {
        if(spell_sphere == caster->query_school())
        {
            clevel += caster->query_guild_level("mage")/12;
            if(FEATS_D->usable_feat(caster, "school familiarity"))
                clevel += 6;
        }
        else if (spell_sphere == SCHOOL_OPPOSITION[caster->query_school()])
        {
            clevel -= caster->query_guild_level("mage")/12;
            if(FEATS_D->usable_feat(caster, "school familiarity"))
                clevel -= 6;
        }
        if(caster->is_class("shadow_adept"))
            if(FEATS_D->usable_feat(caster, "elusive spellcraft"))
                if(spell_sphere == "necromancy" ||
                   spell_sphere == "illusion" ||
                   spell_sphere == "enchantment_charm")
                    clevel+=2;
    }
    if(spell_type == "cleric" ||
       spell_type == "druid")
        if(FEATS_D->usable_feat(caster, "mastery of power")) clevel += 4;
    if(FEATS_D->usable_feat(caster, "eldritch conditioning"))
        if(spell_type == caster->query("eldritch_knight_base_class"))
            clevel = caster->query_character_level();

    if (FEATS_D->usable_feat(caster, "ragecaster"))
    {
        clevel = caster->query_character_level();
        if(caster->query_property("raged"))
            clevel += 6;
    }
    if((int)caster->query_property("empowered"))
        clevel += (int)caster->query_property("empowered");
    clevel = clevel<0?1:clevel;
}

void define_base_spell_level_bonus()
{
    sdamage_adjustment = 0;
    if (query_splash_spell())
        sdamage_adjustment-=1;
    if(spell_type=="psywarrior")
        sdamage_adjustment-=2;
    if(spell_type=="bard")
        sdamage_adjustment+=1;
    sdamage_adjustment=sdamage_adjustment<0?0:sdamage_adjustment;
}

void define_base_damage(int adjust)
{
    if(query_aoe_spell() ||
       query_traveling_aoe_spell())
    {
        sdamage = roll_dice(1,20)*(clevel/18+1);
    }
    else if(spell_type=="warlock")
    {
        string blasttype;
        blasttype = (string)caster->query("warlock_blast_type");
        if(blasttype=="utterdark")
            sdamage = roll_dice(clevel,10);
        else
            sdamage = roll_dice(clevel,8);
    }
    else if(spell_type=="monk")
    {
        sdamage = roll_dice(clevel,10);
    }
    else
    {
        int slevel;
        slevel = query_spell_level(spell_type);
        slevel+=adjust;
        slevel-=sdamage_adjustment;
        slevel = slevel<1?1:slevel;
        switch(slevel)
        {
        case 1: sdamage = roll_dice(clevel,6); break;
        case 2: sdamage = roll_dice(clevel,6)+roll_dice(1,clevel/2); break;
        case 3: sdamage = roll_dice(clevel,7); break;
        case 4: sdamage = roll_dice(clevel,7)+roll_dice(1,clevel/2); break;
        case 5: sdamage = roll_dice(clevel,8); break;
        case 6: sdamage = roll_dice(clevel,8)+roll_dice(1,clevel/2); break;
        case 7: sdamage = roll_dice(clevel,9); break;
        case 8: sdamage = roll_dice(clevel,9)+roll_dice(1,clevel/2); break;
        case 9: sdamage = roll_dice(clevel,10); break;
        case 10..20: sdamage = roll_dice(clevel,10); break;
        default: sdamage = roll_dice(clevel,8); break;
        }
    }

    if(FEATS_D->is_active(caster,"eldritch warfare"))
        sdamage = roll_dice(6,sdamage/8);

}

int query_base_damage()
{
    return sdamage;
}

int preSpell() { return 1; }

void spell_effect(int prof)
{
	spell_successful(); //adding this call to hopefully fix any problems with
				  //a spell being reflected and the original caster
				  //never being able to cast again - Saide

}

void death_check(object fool) {
    if (!fool) TO->dest_effect();
}

void stat_change(object victim, string stat, int change) {
    if (member_array(stat,({"strength","constitution","wisdom","dexterity","intelligence","charisma"})) ==(-1) )
        return;
    victim->add_stat_bonus(stat,change);
    return;
}

void set_arg_needed() {  arg_needed = 1; }
int query_arg_needed() { return arg_needed; }
string query_arg() {     return arg; }
void set_arg(string str){ arg = str; }

void set_casting_time(int tmpnum) {    cast_time = tmpnum; }
int query_casting_time() {    return cast_time; }

void set_peace_needed(int x) {    peace = x; }
int query_peace_needed() {    return peace; }

int spell_kill(object victim, object caster) {
    object *borg_people, *inven;
    int i, initiative, k;
    string *pkill;

    pkill = ({});
    if (!objectp(victim)) return 0;
    if (!objectp(caster)) return 0;
    if (!objectp(environment(caster))) return 0;
    if (!objectp(environment(victim))) return 0;
    borg_people = (object *)victim->query_attackers();
    if (!borg_people) borg_people = ({});
    if (victim == caster) return 0;
    if (!swarm) {
        if (interactive(caster)) {
            inven = all_living(environment(victim));
            k = sizeof(inven);
            for (i=0;i<k;i++) {
                if (objectp(inven[i])) {
                    if (inven[i]->query_property("swarm")) {
                        swarm = 1;
                        spell_kill(inven[i],caster);
                    }
                }
            }
        }
    }
    if (!objectp(victim)) return 0;
    if (!caster->ok_to_kill(victim)) return 0;
    if (!(environment(victim)->query_property("arena"))) {
        if (member_array(caster, borg_people) == -1) {
            if (interactive(caster) && interactive(victim)) {
                if (!avatarp(caster) && !avatarp(victim)) {
                    log_file("killers","       ##"+caster->QCN+" attacked "+victim->QCN+" at "+ctime(time())+".\n");
                }
            }
        }
        KILLING_D->check_actions(caster,victim);
    }
    environment(caster)->add_combatant(victim);
    environment(caster)->add_combatant(caster);
    caster->add_attacker(victim);
    victim->add_attacker(caster);
    swarm = 0;
    return 1;
}

//updated to show arguments for spells that are on the list - Saide - May 5th, 2016
string querySpellDisplay()
{
    if (!objectp(target))
    {
        if(!query_arg()) return spell_name;
        return spell_name +" ("+query_arg()+")";
    }
    else
    {
        if(!query_arg()) return spell_name+" on "+target->getParsableName()+".";
        return spell_name + " (" +query_arg()+ ") on "+ target->getParsableName()+".";
    }
}

void removeSpellFromCaster(){
   object *spells;

   if (!objectp(caster))
      return;
   if (!pointerp(caster->query_property("dispellable spells")) ){
      return;
   }else {
      spells = caster->query_property("dispellable spells");
   }
   if (member_array(TO, spells) != -1) {
      spells-= ({TO});
	  spells -= ({0});
      caster->remove_property("dispellable spells");
      caster->set_property("dispellable spells",spells);
   }
}

void addSpellToCaster(){
   object *spells;

   if (!objectp(caster))
      return;

   if (!pointerp(caster->query_property("dispellable spells")) ){
      spells = ({});
   } else {
      spells = caster->query_property("dispellable spells");
   }
   spells+= ({TO});
   caster->remove_property("dispellable spells");
   caster->set_property("dispellable spells",spells);
}

void addSpellToTarget(){
   object *spells;

   if (!objectp(target))
      return;

   if (!pointerp(target->query_property("dispellable spells")) ){
      spells = ({});
   } else {
      spells = target->query_property("dispellable spells");
   }
   spells+= ({TO});
   target->remove_property("dispellable spells");
   target->set_property("dispellable spells",spells);
}

void reverse_spell(){
    if(query_target_required() && target != caster) {
        target = caster;
    }
    spell_effect(FULL_EFFECT);
}

// PSS Preload Interface for use with the Permanent Spell System
// permspell daemon.
int preload_interface(int arg_reg_num,object arg_target,string arg_cname,int arg_clevel) {
    clevel = arg_clevel;
    reg_num = arg_reg_num;
    arg_target->set_property("spelled",({TO}));
    preloaded = 1;
    return 1;
}

string query_caster_name() { return cname; }

int query_reg_num() { return reg_num; }

int thaco(object target, int bonus){
    int result;

    if(!objectp(target)){
        return 0;
    }
    if (!objectp(caster)) {
        return 0;
    }
    caster->add_attack_bonus(bonus);
    result = caster->Thaco(1,target,0);
    caster->add_attack_bonus(-1 * bonus);
    return result;
}

// changing this to roll every time damage is done -Ares
varargs int checkMagicResistance(object victim, int mod)
{
    int res=0;

    if (!intp(mod)) { mod = 1; }
    if(!objectp(victim)) { return 0; }

// vitriolic blast does not require a MR/SR save
    if(spell_name == "eldritch blast" || spell_name == "eldritch chain" || spell_name == "eldritch burst") {
      if((string)caster->query("warlock_blast_type") == "vitriolic") return 0;
    }

    if(help_or_harm)
        return 0;

    if(victim->query_property("magic resistance")) { res = (int)victim->query_property("magic resistance"); }

    if( (roll_dice(1,100) + mod) > res ) { return 0; }
    return 1;
}

string QCN {
  string hold;

  hold = CASTER->QCN;
  if (objectp(CASTER) && stringp(hold) && hold != "Someone")
    return hold;
  else return query_name();
}

string query_vis_name() { return QCN; }
string query_vis_cap_name() { return QCN; }

 // For potions to use dest_effect nicely.
void potion_dest_effect(int duration) {
  call_out("dest_effect",duration);
  return;
}

void set_spell_domain(string domain) {
    if(stringp(domain)) spell_domain = domain;
}

string get_spell_domain() { return spell_domain; }

int spell_domain_check(object player) {
    string *domains;
    domains = player->query_divine_domain();
    if(!objectp(player))                                { return 0; }
    if(avatarp(player))                                 { return 1; }
    if(!stringp(spell_domain) || spell_domain == "" )   { return 1; }
    if(spell_domain && !domains || domains == ({}))     { return 0; }
    if(member_array(spell_domain,domains) == -1)        { return 0; }
    return 1;
}

// Must evaluate to true for quest spells. - Ares
void set_quest_spell(int x) { quest_spell = x; }

int is_quest_spell() { return quest_spell; }

int quest_spells_check(object player,string spell) {
    string *spells;
    if(!objectp(player)) { return 0; }
    if(!stringp(spell)) { return 0; }
    if(!quest_spell) { return 1; }
    spells = player->query_quest_spells();
    if(!pointerp(spells) || spells == ({}) ) { return 0; }
    spell = replace_string(spell,"_","",1);
    spell = replace_string(spell,".c","",1);
    spell = replace_string(spell,"_"," ");
    if(member_array(spell, spells) == -1) { return 0; }
    return 1;
}

void set_save(string save) {
    if(stringp(save)) { save_type = save; }
    return;
}

string get_save() { return save_type; }

int calculate_bonus(int stat) {
    if(stat < 10) { return (stat - 11)/2; }
    return (stat - 10)/2;
}

int is_caster(string myclass) {
   string *casterclasses;
   casterclasses = (({ "mage", "sorcerer", "cleric", "druid", "bard", "psion", "psywarrior" }));
   if(member_array(myclass,casterclasses) != -1) return 1;
   return 0;
}

void debug_saves(int num) {
	if(intp(num)) { save_debug = num; }
	return;
}

// can display a LOT of debug info.  Use <debug_saves(1)> in the spell's create() to enable
varargs int do_save(object targ,int mod) {
    string type,stat,*myclasses;
    int caster_bonus,target_level,num,casting_level, classbonus, i, classlvl;
    mapping debug_map=([]);

    if(!objectp(caster)) { return 1; }
	if(!objectp(targ)) { return notify_fail("invalid target object."); }
	if(!intp(mod)) { mod = 0; }

    caster_bonus += (int)caster->query_property("spell dcs");
//    if(FEATS_D->usable_feat(caster,"spell focus"))          { caster_bonus += 2; }
// spell focus feat & item "empowered" prop is now picked up together in the "spell dcs" property.

	if(save_debug) {
		tell_object(caster,"Presenting saving throw debug info:\n");
		tell_object(caster,"Caster name: "+caster->query_true_name()+"");
		tell_object(caster,"Target name: "+targ->query_true_name()+"");
        tell_object(caster,"Pre calculation modifier (mod): "+mod+"");
        tell_object(caster,"Adding 10 to the DC initial DC check as per 3.xx rules.");
	}

    casting_level = query_spell_level(spell_type);

	switch(spell_type) {
    case "wizard":
    case "mage":
    case "psion":
    case "psionics":
    case "psywarrior":
	if(save_debug) tell_object(caster,"Caster's casting stat:  Intelligence");
        stat = "intelligence";
        break;
    case "priest":
    case "cleric":
    case "ranger":
    case "paladin":
    case "antipaladin":
    case "druid":
    case "monk":
	if(save_debug) tell_object(caster,"Caster's casting stat:  Wisdom");
        stat = "wisdom";
        break;
    case "bard":
    case "sorcerer":
	if(save_debug) tell_object(caster,"Caster's casting stat:  Charisma");
        stat = "charisma";
        break;
    default:
	if(save_debug) tell_object(caster,"Caster's casting stat:  Intelligence");
        stat = "intelligence";
        break;
    }

    type         = get_save();
	if(save_debug)
	{
		tell_object(caster,"Save type: "+type+"");
	}

    target_level = (int)targ->query_level();
	if(save_debug)
	{
		tell_object(caster,"Target's level: "+target_level+"");
	}

    caster_bonus += 10; // initial DC of 10 for opposed spells, all the other caster mods gets added to this
    caster_bonus += calculate_bonus((int)caster->query_stats(stat));

	if(save_debug)
	{
		tell_object(caster,"Bonus from caster's casting stat: "+caster_bonus+"");
	}

    caster_bonus += casting_level;

// adding in level-based bonuses here since our system is only user-friendly to L20. Need DCs to be feasible up to 40! N, 9/15.
// to parallel saving throws, this currently grants level/2 for any caster class levels (including current class past L20),
// or grants level/3 for any non-caster class levels.
    myclasses = caster->query_classes();
    num = 0;
    if(sizeof(myclasses)) {
      for(i=0;i<sizeof(myclasses);i++) {
        if(myclasses[i] == spell_type) { // only give bonuses for current caster class past L20
          classlvl = caster->query_class_level(spell_type);
          classlvl -= 20;
          if(classlvl < 0) classlvl = 0;
          if(is_caster(spell_type)) num += (classlvl+1)/2;
          else num += classlvl/3;
        }
        else {
          if(caster->query("new_class_type")) { // don't run this for 2e style classing, eg/ mobs; they already have full in all classes.
            classlvl = caster->query_class_level(myclasses[i]);
            if(classlvl < 0) classlvl = 0;
            if(is_caster(spell_type)) num += (classlvl+1)/2;
            else num += classlvl/3;
          }
        }
      }
    }
    if(save_debug) tell_object(caster,"Bonus from non-class and L20+ class levels: "+num+"");
    caster_bonus += num;
    num = 0;

    if(FEATS_D->usable_feat(caster,"shadow adept") || caster->is_class("shadow_adept")) { // shadow adept casters get a bonus when casting charm/illusion/necromancy spell types
      if(spell_sphere == "enchantment_charm" || spell_sphere == "illusion" || spell_sphere == "necromancy") caster_bonus += 2;
    }

// racial saves from spells here
    if((string)targ->query_race() == "dwarf") { //shield & gold dwarf, +2 on saves vs spells
      if((string)targ->query("subrace") == "shield dwarf" || (string)targ->query("subrace") == "gold dwarf")
        caster_bonus -= 2;
    }
    if((string)targ->query_race() == "orc" || (string)targ->query_race() == "half-orc")
      caster_bonus -= 1; //orc and half-orc, +1 on saves vs spells
    if((string)targ->query_race() == "human") { // human ethnicity 'heartlander'
      if((string)targ->query("subrace") == "heartlander")
        caster_bonus -= 1;
    }

    if((string)targ->query_race() == "gnome" && spell_sphere == "illusion") { // rock & forest gnome, +2 vs illusions
      if((string)targ->query("subrace") == "rock gnome" || (string)targ->query("subrace") == "forest gnome")
        caster_bonus -= 2;
    }
    if((string)targ->query_race() == "elf" || (string)targ->query_race() == "half-elf") {
      if(spell_sphere == "enchantment_charm") caster_bonus -= 2; //elves & half-elves, +2 vs charm
    }
    if((string)targ->query_race() == "drow" || (string)targ->query_race() == "half-drow") {
      if(spell_sphere == "enchantment_charm") caster_bonus -= 2; //drow & half-drow, +2 vs charm
    }
    if(FEATS_D->usable_feat(targ,"shadow adept") || targ->is_class("shadow_adept")) { // shadow adept targets get a bonus vs charm/illusion/necromancy spell types
      if(spell_sphere == "enchantment_charm" || spell_sphere == "illusion" || spell_sphere == "necromancy") caster_bonus -= 2;
    }

	if(save_debug)
	{
		tell_object(caster,"Level of spell: "+casting_level+"");
	}

    caster_bonus = caster_bonus * -1;

	if(intp(mod)) { caster_bonus += mod; }

	if(save_debug)
	{
		tell_object(caster,"%^RESET%^%^BOLD%^Total modifiers from caster's side "
			"BEFORE d20 roll: "+caster_bonus+"%^RESET%^");
	}

    // this is directly copied below for the shadowdancer reroll - if anything changed here, change there too plz!
    switch(lower_case(type))
    {
    case "fortitude": case "fort":
		if(save_debug) debug_map = "/daemon/saving_throw_d"->debug_fort_save(targ,caster_bonus);
		else num = "/daemon/saving_throw_d"->fort_save(targ,caster_bonus);
        break;
    case "reflex":
		if(save_debug) debug_map = "/daemon/saving_throw_d"->debug_reflex_save(targ,caster_bonus);
		else num = "/daemon/saving_throw_d"->reflex_save(targ,caster_bonus);
        break;
    case "willpower": case "will":
		if(save_debug) debug_map = "/daemon/saving_throw_d"->debug_will_save(targ,caster_bonus);
		else num = "/daemon/saving_throw_d"->will_save(targ,caster_bonus);
        break;
    default:
        num = 0;
        break;
    }

	if(save_debug) {
		tell_object(caster,"Type of save actually used in daemon: "+debug_map["save_type"]+"");
		tell_object(caster,"Saving throw number before any rolls: "+debug_map["final_saving_throw"]+"");
		tell_object(caster,"DC of saving throw: "+debug_map["dc"]+"");
		tell_object(caster,"Save result (1 pass, 0 fail): "+debug_map["save_result"]+"");
		tell_object(caster,"Throw passed or failed by: "+debug_map["pass_or_fail_by"]+"");
	}

      // one reroll chance for shadowdancers if they fail an enchantment spell save
      if( (FEATS_D->usable_feat(caster,"shadowdancer") || caster->is_class("shadowdancer")) && !num && spell_sphere == "enchantment_charm") {
          // this is a direct copy of the above - if anything changed there, change here too plz!
          switch(lower_case(type)) {
            case "fortitude": case "fort":
		    if(save_debug) debug_map = "/daemon/saving_throw_d"->debug_fort_save(targ,caster_bonus);
                else num = "/daemon/saving_throw_d"->fort_save(targ,caster_bonus);
                break;
            case "reflex":
		    if(save_debug) debug_map = "/daemon/saving_throw_d"->debug_reflex_save(targ,caster_bonus);
		    else num = "/daemon/saving_throw_d"->reflex_save(targ,caster_bonus);
                break;
            case "willpower": case "will":
		    if(save_debug) debug_map = "/daemon/saving_throw_d"->debug_will_save(targ,caster_bonus);
		    else num = "/daemon/saving_throw_d"->will_save(targ,caster_bonus);
                break;
            default:
                num = 0;
                break;
          }
      }

	if(save_debug) {
		tell_object(caster,"Shadowdancer reroll on failed enchantment-sphere save!");
		tell_object(caster,"Type of save actually used in daemon: "+debug_map["save_type"]+"");
		tell_object(caster,"Saving throw number before any rolls: "+debug_map["final_saving_throw"]+"");
		tell_object(caster,"DC of saving throw: "+debug_map["dc"]+"");
		tell_object(caster,"Save result (1 pass, 0 fail): "+debug_map["save_result"]+"");
		tell_object(caster,"Throw passed or failed by: "+debug_map["pass_or_fail_by"]+"");
	}

	if(save_debug) return debug_map["save_result"];
	else return num;
}


object *ob_party(object obj)
{
    string party_name;
    if(!objectp(obj)) { return ({}); }

    party_name = obj->query_party();
    if(!party_name) { return ({ obj }); }
    return PARTY_D->query_party_members(party_name);
}


object *target_filter(object *targets)
{
    object *newtargs = ({});
    int i;
    targets -= ({ 0 });

    if(!objectp(caster)) { return ({}); }

    if(sizeof(targets))
    {
        targets = filter_array(targets,"is_non_immortal",FILTERS_D);
    }

    if(!query_helpful())
    {
        if(FEATS_D->usable_feat(caster, "perfect caster") || FEATS_D->usable_feat(caster, "flawless control"))
        {
            if(sizeof(targets)) { targets = filter_array(targets, "perfect_filter", TO); }
        }

        if(sizeof(targets))
        {
            if(stringp(get_save()) && get_save() == "reflex")
            {
                for(i=0;i<sizeof(targets);i++)
                {
                    if(!evade_splash(targets[i])) { newtargs += ({ targets[i] }); }
                }
                return newtargs;
            }
        }
    }

    return targets;
}


// filter for perfect casting to remove party members and their
// fodder from list of stuff that spells will hit.. hopefully
int perfect_filter(object obj){
    object *party=({}),*followers=({}), ally;
    string tmp;
    int i;

    if(!objectp(obj)) { return 0; }
    if(!objectp(caster)) { return 0; }
    if(!interactive(caster) && !caster->is_merc())
    {
        //basically adding this so that we can
        //have monsters allied together and not
        //hurting one another with aoe spells -
        //as long as they have the perfect caster feat - Saide
        if(!caster->is_monster()) return 1;
        if(member_array(obj,(object)caster->query_followers()) != -1) { return 0; }
        ally = obj->query_property("allied_with");
        if(!objectp(ally)) return 1;
        if(ally == caster) return 0;
        return 1;
    }
    if(obj->id(""+(string)caster->query_name()+" retainer")) { return 0; } //to keep retainers from being hit by their caster's spells ~Circe~ 3/21/16
    party = ob_party(caster);
    party = distinct_array(party);

    if(member_array(obj,party) != -1) { return 0; } // 0 to filter out anybody in the party

    //lets set the property minion on any summoned creatures
    //some already do - such as animate object
    //then check for this property - if it's an object check it against party members
    //and the caster - hopefully will make perfect caster always work - Saide - April 2016
    if(objectp(ally = obj->query_property("minion")))
    {
        if(ally == caster) { return 0; }
        if(member_array(ally, party) != -1) { return 0; }
    }
    for(i=0;i<sizeof(party);i++)
    {
        if(!objectp(party[i]) && !living(party[i])) { continue; }
        followers += (object *)party[i]->query_followers();
        if(objectp(party[i]->query_in_vehicle()))
        {
            followers += ({ party[i]->query_in_vehicle() });
        }
        followers += ({ party[i] });
    }

    if(member_array(obj,followers) != -1) { return 0; } // 0 to filter if it's following ANYONE in the party
    return 1;
}

void get_casting_stat()
{
    string mycastingstat;

    if(!objectp(caster)) return;
    if(!interactive(caster))
    {
        mycastingstat = "intelligence";
        return mycastingstat;
    }
    switch(spell_type)
    {
    case "wizard":  case "mage":        mycastingstat = "/std/class/mage.c"->query_casting_stat(caster);        break;
    case "psion":   case "psionics":    mycastingstat = "/std/class/psion.c"->query_casting_stat(caster);       break;
    case "priest":  case "cleric":      mycastingstat = "/std/class/cleric.c"->query_casting_stat(caster);      break;
    case "ranger":                      mycastingstat = "/std/class/ranger.c"->query_casting_stat(caster);      break;
    case "paladin": case "antipaladin": mycastingstat = "/std/class/paladin.c"->query_casting_stat(caster);     break;
    case "druid":                       mycastingstat = "/std/class/druid.c"->query_casting_stat(caster);       break;
    case "bard":                        mycastingstat = "/std/class/bard.c"->query_casting_stat(caster);        break;
    case "sorcerer":                    mycastingstat = "/std/class/sorcerer.c"->query_casting_stat(caster);    break;
    case "warlock":                     mycastingstat = "/std/class/warlock.c"->query_casting_stat(caster);     break;
    case "psywarrior":                  mycastingstat = "/std/class/psywarrior.c"->query_casting_stat(caster);  break;
    default:                            mycastingstat = "intelligence";                                         break;
    }
    casting_stat = mycastingstat;
    return mycastingstat;
}

string query_casting_stat() { return casting_stat; }

//setting up cost here in case other functions need it
int check_point_cost(int plvl){
   int pcost;
   if(!plvl || plvl < 0) return 0;
   plvl--;
   if(plvl < 0) plvl = 0;
   pcost = COSTPERLEVEL[plvl];
   return pcost;
}

int light_armor_filter(object ob) {
    if(!objectp(ob)) { return 0; }
    if((string)ob->query_armor_prof() == "heavy") { return 1; }
    if((string)ob->query_armor_prof() == "medium") { return 1; }
    return 0;
}

int evade_splash(object splashtarg) {
   object *worn;
   int evbonus = 0;

   if(!FEATS_D->usable_feat(splashtarg,"evasion")) return 0; // can't evade without the feat active!
   worn = splashtarg->all_armour();
   worn = distinct_array(worn);
   worn = filter_array(worn,"light_armor_filter",TO);
//allowing users of Evade Burst to avoid damage per spell and class abilities ~Circe~ 10/26/19
   if(sizeof(worn) && !splashtarg->query_property("evadeburst")) return 0; //wearing something too heavy!
   if(splashtarg->query_property("evadeburst")) evbonus += splashtarg->query_property("evadeburst");

   if(!do_save(splashtarg,evbonus)) return 0;

   tell_object(splashtarg,"%^BOLD%^%^WHITE%^You scramble out of the spell's path!%^RESET%^");
   tell_room(place,"%^BOLD%^%^WHITE%^"+splashtarg->QCN+" scrambles out of spell's path!%^RESET%^",splashtarg);
   return 1;
}


int race_immunity_check(object obj, string type)
{
    string myrace,mysubrace;
    int num;
    if(!objectp(obj)) { return 0; }
    myrace = obj->query_race();
    mysubrace = obj->query("subrace");

    switch(type)
    {
    case "sleep":
        switch(myrace)
        {
        case "elf":
        case "drow":
        case "half-elf":
        case "half-drow":
            tell_object(obj,"%^BOLD%^%^WHITE%^Your innate immunity to sleep enchantment shrugs off the spell!%^RESET%^");
            tell_object(caster,"%^BOLD%^%^WHITE%^%^"+obj->QCN+" seems to shrug off the spell effortlessly!%^RESET%^");
            return 1;
        default:
            return 0;
        }
        return 0;

    case "fear":
    case "fear silent":

        switch(myrace)
        {
        case "half-elf":    num = 15;   break;
        case "half-drow":   num = 15;   break;
        case "beastman":    num = 30;   break;
        case "firbolg":     num = 8;    break;
        case "drow":        num = 30;   break;
        case "elf":         num = 35;   break;
        case "human":
            if(mysubrace == "attayan") num = 200; break;
        default:            num = -100;   break;
        }
        if(FEATS_D->usable_feat(obj,"no fear of the flame")) num = 200; // fear immunity for L1 hellfire warlock class.

        if(random(100) < num)
        {
            if((myrace == "human" && mysubrace == "attayan") || FEATS_D->usable_feat(obj,"no fear of the flame"))
            {
                if(type != "fear silent")
                {
                    tell_object(obj, "%^RESET%^%^BOLD%^You feel the insidious effects of the "
                        "spell, but you are fearless and it has no effect on you!%^RESET%^");
                    tell_room(place, "%^RESET%^%^BOLD%^"+obj->QCN+" seems completely fearless and "
                        "unaffected!",obj);
                }
                return 1;
            }
            else
            {
                if(type != "fear silent")
                {
                    tell_object(obj, "%^RESET%^%^BOLD%^You shudder but manage to resist the fear "
                        "effect!");
                    tell_room(place,"%^RESET%^%^BOLD%^"+obj->QCN+" sudders but manages to "
                        "resist the fear effect!",obj);
                }
                return 1;
            }
        }
        return 0;

    default:
        return 0;
    }

    return 0;
}

int mind_immunity_check(object obj, string type)
{
    if(!objectp(obj)) { return 0; }

    // can add other types here if you want a different message to be sent,
    // easier to have these all in one place rather than duplicate the code in a dozen spells
    switch(type)
    {
    case "silent": // no messages
        if(FEATS_D->usable_feat(obj,"unyielding soul") || FEATS_D->usable_feat(obj, "presence of mind") || FEATS_D->usable_feat(obj, "mind partition")) { return 1; }

    case "default":
    default:
        if(FEATS_D->usable_feat(obj,"unyielding soul"))
        {
            tell_object(obj, "%^BOLD%^%^WHITE%^You feel an invocation trying to take hold of your mind, but such is the strength of your soul that you manage to shake it off!%^RESET%^");
            tell_object(caster,"%^BOLD%^%^WHITE%^%^"+obj->QCN+" struggles momentarily, before shaking off the invocation's effects!%^RESET%^");
            return 1;
        }
        if(FEATS_D->usable_feat(obj, "presence of mind") || FEATS_D->usable_feat(obj, "mind partition"))
        {
            tell_object(obj,"%^BOLD%^%^WHITE%^You feel a spell trying to take hold of your mind, but such is your mental strength that you manage to shake it off!%^RESET%^");
            tell_object(caster,"%^BOLD%^%^WHITE%^%^"+obj->QCN+" struggles momentarily, before shaking off the spell's effects!%^RESET%^");
            return 1;
        }
    }
    return 0;
}

void help() {
    mapping mycomps, compmap;
    string *classkeys, printclass, *compskeys, *mapkeys, printcomps;
    int i, j;
    write("%^BOLD%^%^RED%^Spell:%^RESET%^ "+spell_name);
    classkeys = keys(spell_levels);
    if(!sizeof(classkeys)) printclass = "error";
    else {
        if(classkeys[0] == "mage" && !mage_only) printclass = "mage/sorc L"+spell_levels[classkeys[0]];
        else printclass = classkeys[0]+" L"+spell_levels[classkeys[0]];
        if(sizeof(classkeys) > 1)
            for(i = 1;i < sizeof(classkeys); i++) {
                if(classkeys[i] == "mage") printclass += ", mage/sorc L"+spell_levels[classkeys[i]];
                else printclass += ", "+classkeys[i]+" L"+spell_levels[classkeys[i]];
            }
    }
    write("%^BOLD%^%^RED%^Class:%^RESET%^ "+(affixed_level?("(L"+affixed_level+" fixed) "):"")+printclass);
    if(!spell_sphere)
        spell_sphere = "";
    if(spell_sphere != "")
        write("%^BOLD%^%^RED%^Sphere:%^RESET%^ "+spell_sphere+(evil_spell?" [evil]":""));
    if(!spell_domain)
        spell_domain = "";
    if(spell_domain != "")
        write("%^BOLD%^%^RED%^Domain:%^RESET%^ "+spell_domain);
    if(!mydiscipline)
        mydiscipline = "";
    if(mydiscipline != "")
        write("%^BOLD%^%^RED%^Discipline:%^RESET%^ "+mydiscipline);
    if(!save_type)
        save_type = "";
    if(save_type != "")
        write("%^BOLD%^%^RED%^Saving throw:%^RESET%^ "+save_type);
    else
        write("%^BOLD%^%^RED%^Saving throw:%^RESET%^ n/a");
    if(stringp(damage_desc))
        write("%^BOLD%^%^RED%^Spell effect:%^RESET%^ "+damage_desc);
    if(!syntax)
        syntax = "contact a wiz - not initialized";
    if(!description)
        description = "contact a wiz - not initialized";
    write("%^BOLD%^%^RED%^Syntax:%^RESET%^ "+syntax+"\n");
    write(description+"\n");
//fixed up some typos in the following messages ~Circe~ 7/29/19
    if(peace)
        write("%^BOLD%^%^RED%^Only at peace:%^RESET%^ This spell can be cast only when you aren't in combat.");
    if(silent_casting)
        write("%^BOLD%^%^RED%^Silent casting:%^RESET%^ This spell is silent to cast.");
    if(evil_spell)
        write("%^BOLD%^%^RED%^Evil spell:%^RESET%^ For one reason or another, this is an evil, selfish spell. Good characters won't use it unless in dire need.");
    if(aoe_spell)
        write("%^BOLD%^%^RED%^AOE spell:%^RESET%^ This is an area of effect spell. It will affect all targets in the room over time. It uses a special damage table. Two spells of the same effect can't be used by the same caster simultaneously. More than three area of effect spells can't be maintained by the same caster.");
    if(traveling_aoe_spell)
        write("%^BOLD%^%^RED%^TravAOE spell:%^RESET%^ This is a travelling area of effect spell. It affects everyone in the room that the caster is in. It uses a special damage table.");
    if(splash_spell)
        write("%^BOLD%^%^RED%^Splash spell:%^RESET%^ This is a splash damage spell. It has a chance of affecting multiple targets at the price of the spell level.");

    if(mapp(feats_required)) {
      compskeys = ([]);
      compskeys = keys(feats_required);
      if(sizeof(compskeys)) {
        printcomps = "\n%^BOLD%^%^RED%^Feat requirements:%^RESET%^ ";
        if(compskeys[0] == "mage") printcomps += "mage/sorc ("+feats_required[compskeys[0]]+")";
        else printcomps += compskeys[0]+" ("+feats_required[compskeys[0]]+")";
        if(sizeof(compskeys) > 1) {
          for(i = 1;i < sizeof(compskeys); i++) {
            if(compskeys[i] == "mage") printcomps += ", mage/sorc ("+feats_required[compskeys[i]]+")";
            else printcomps += ", "+compskeys[i]+" ("+feats_required[compskeys[i]]+")";
          }
        }
        write(printcomps);
      }
    }

}

int query_has_been_cast() { return hasBeenCast; }

int save_me(string file)
{
    if(!permanent) { return 0; }
}
