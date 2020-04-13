#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <magic.h>
#include <schoolspells.h>
inherit "/std/innate";

/**
 * @file
 */


void set_cast_type(string str);

int set_memorized(string myclass, string spell, int num);
int forget_memorized(string myclass, string spell);
int query_memorized(string myclass, string spell);
int can_memorize(string myclass, string spell);
int check_memorized(string myclass, string spell);
int query_num_spells_level(string myclass, int lvl);
mixed* query_all_memorized(string myclass);
mixed* query_justs_spells(string myclass);
mixed* query_all_level(string myclass, int lvl);
void forget_all_spells();
void forget_class_spells(string myclass);
void resetMemorized();
void add_mem_class(string myclass);

void restrict_spell(string classname, string spellname);
void unrestrict_spell(string classname, string spellname);
string* query_spells_restricted(string classname);
int query_spell_level_restricted(string classname);
void set_spell_level_restricted(string classname, int level);

mapping get_spell_skills();
string* query_mastered_spells();
string* query_base_mastered_spells();
void add_mastered_spell(string newspell);

void prepare(string str, int temp, string myclass, int num);
void prepare2();

string typeSpell;
mapping spells_memorized;
mapping lost_spells, lost_spell_level;
mapping spell_skills;
mapping mastered;
string* masteredspells;
int* masterable;
int mypp, mymax, myneeded;

int magic_arsenal_feat(int num)
{
    if (!intp(num) || !num) {
        return num;
    }
    if (!objectp(TO)) {
        return num;
    }

    if (FEATS_D->usable_feat(TO, "magic arsenal")) {
        num += 2;
    }
    if (FEATS_D->usable_feat(TO, "greater arsenal")) {
        num += 5;
    }
    if (FEATS_D->usable_feat(TO, "gift of the shadows")) {
        num += 4;
    }
    return num;
}

int bonus_spell_slots_by_level(int lev, int num)
{
    int extra;
    if (!intp(num) || !num) {
        return num;
    }
    if (!intp(lev) || !lev) {
        return num;
    }
    if (!objectp(TO)) {
        return num;
    }
    extra = (int)TO->query_property("bonus_spell_slots_" + lev);
    if (!intp(extra) || !extra) {
        return num;
    }
    num += extra;
    return num;
}

int bonus_spell_slots(int num)
{
    int extra;
    if (!intp(num) || !num) {
        return num;
    }
    if (!objectp(TO)) {
        return num;
    }
    extra = (int)TO->query_property("bonus_spell_slots");
    if (!intp(extra) || !extra) {
        return num;
    }
    num += extra;
    return num;
}

void create()
{
    string* myclasses;
    int i;
    ::create();

    lost_spell_level = ([]);
    myclasses = get_dir("/std/class/*.c");
    if (!sizeof(myclasses)) {
        return;
    }
    for (i = 0; i < sizeof(myclasses); i++) {
        lost_spell_level[myclasses[i]] = 9;
    }
}

int query_spell_prof_level(string spell)
{
    if (!spell_skills) {
        spell_skills = ([]);
    }
    if (!spell_skills[spell]) {
        return 0;
    }
    return spell_skills[spell][0];
}

int query_spell_research_level(string spell)
{
    if (!spell_skills) {
        spell_skills = ([]);
    }
    if (!spell_skills[spell]) {
        return 0;
    }
    return spell_skills[spell][1];
}

int set_spell_prof_level(string spell, int level)
{
    if (!spell_skills) {
        spell_skills = ([]);
    }
    spell_skills[spell] = ({ level, 0 });
}

int set_spell_research_level(string spell, int level)
{
    if (!spell_skills) {
        spell_skills = ([]);
    }
    if (!spell_skills[spell]) {
        error("researching spell unknown");
    }
    spell_skills[spell][1] = level;
}

mapping get_spell_skills()
{
    return spell_skills;
}

void set_cast_type(string str)
{
    typeSpell = str;
}

int set_memorized(string myclass, string spell, int num)
{
    int level;

    if (!spells_memorized) {
        resetMemorized();
    }
    if (!num) {
        num = 1;
    }
    if (!spell) {
        return 0;
    }
    if (myclass == "bard" ||
        myclass == "sorcerer" ||
        myclass == "oracle" ||
        myclass == "inquisitor") { //get spontaneous settings
        if (sscanf(spell, "level %d", level) != 1) {
            return 0;
        }
        spell = "generic";
    }else if (myclass == "psywarrior" || myclass == "psion") { //add psions when ready for power points
        return 1;
    }else {
        level = (int)MAGIC_D->query_spell_level(myclass, spell);
        if (!level) {
            return 0;
        }
    }

    if (!mapp(spells_memorized[myclass])) {
        add_mem_class(myclass);
    }
    if (spells_memorized[myclass][level][spell]) {
        spells_memorized[myclass][level][spell] = spells_memorized[myclass][level][spell] + num;
        return 1;
    }
    spells_memorized[myclass][level][spell] = num;
    return 1;
}

varargs int forget_memorized(string myclass, string spell, int forced)
{
    int level, stat;
    mapping tmp;
    int i;

    if (!spell) {
        return 0;
    }
    if (!spells_memorized) {
        resetMemorized();
    }
    if (myclass == "psywarrior") {
        return 1;
    }
    if (myclass == "monk") {
        return 1;
    }
    if (myclass == "psion") {
        return 1;
    }
    if (myclass == "warlock") {
        return 1;
    }
    if (myclass == "bard" ||
        myclass == "inquisitor" ||
        myclass == "oracle" ||
        myclass == "sorcerer") { //get spontaneous settings
        if (sscanf(spell, "level %d", level) != 1) {
            level = (int)MAGIC_D->query_spell_level(myclass, spell);
        }
        if (!level) {
            return 0;
        }
        spell = "generic";
    }

    if (!mapp(spells_memorized[myclass])) {
        add_mem_class(myclass);
    }
    if (forced != 1) {
        if (TO->query_property("clearcasting")) {
            TO->remove_property("clearcasting");
            tell_object(TO, "%^BOLD%^%^WHITE%^Your concentration is so great that you keep memory of the spell even after its casting!%^RESET%^");
            return 1;
        }
        if (TO->is_class("sorcerer") ||
            TO->is_class("mage")) {
            if (FEATS_D->usable_feat(TO, "arcane perfection")) {
                if (TO->is_class("sorcerer")) {
                    stat = TO->query_stats("charisma");
                }else {
                    stat = TO->query_stats("intelligence");
                }

                stat += 30;
                if (roll_dice(1, 100) < stat) {
                    tell_object(TO, "%^RESET%^%^MAGENTA%^Your %^BOLD%^%^CYAN%^k%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^owledge%^RESET%^%^MAGENTA%^ of the %^BOLD%^%^CYAN%^Wea%^RESET%^%^CYAN%^v%^CYAN%^e%^MAGENTA%^ is so %^CYAN%^pe%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^f%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^ct%^MAGENTA%^ that you %^BOLD%^%^CYAN%^retain%^RESET%^%^MAGENTA%^ the spell in memory!%^RESET%^");
                    return 1;
                }
            }
        }
        if (TO->is_class("hierophant") ||
            TO->is_class("archdruid")) {
            if (FEATS_D->usable_feat(TO, "natural perfection") ||
                FEATS_D->usable_feat(TO, "theurgic perfection")) {
                if (TO->is_class("oracle")) { //this is a workaround for now. assuming that oracles do not multiclass with druids or clerics.  Will figure more specifics out later - Odin 3/22/2020
                    stat = TO->query_stats("charisma");
                }else {
                    stat = TO->query_stats("wisdom");
                }
                stat += 30;
                if (roll_dice(1, 100) < stat) {
                    if (TO->is_class("druid")) {
                        tell_object(TO, "%^BOLD%^%^GREEN%^You are so in tune with the natural world around you that you retain the spell in memory!");
                    }else {
                        tell_object(TO, "%^BOLD%^%^CYAN%^You are so in tune with the divine forces around you that you retain the spell in memory!");
                    }
                    return 1;
                }
            }
        }
    }

    if (myclass == "bard" ||
        myclass == "inquisitor" ||
        myclass == "oracle" ||
        myclass == "sorcerer") {
        spells_memorized[myclass][level][spell] = spells_memorized[myclass][level][spell] - 1;

        if (spells_memorized[myclass][level][spell] <= 0) {
            tmp = spells_memorized[myclass][level];
            map_delete(tmp, spell);
            spells_memorized[myclass][level] = tmp;
        }
        return 1;
    }
    foreach(i in keys(spells_memorized[myclass]))
    {
        spells_memorized[myclass][i][spell] = spells_memorized[myclass][i][spell] - 1;
        if (spells_memorized[myclass][i][spell] <= 0) {
            tmp = spells_memorized[myclass][i];
            map_delete(tmp, spell);
            spells_memorized[myclass][i] = tmp;
        }
    }
    return 1;
}

int query_memorized(string myclass, string spell)
{
    int lvl;
    string* myknown;
    object class_ob;

    if (!spells_memorized) {
        resetMemorized();
    }
    if (!stringp(spell) || spell == "") {
        return 0;
    }
    if (spell == (string)TO->query("spellmastery_spell") && FEATS_D->usable_feat(TO, "spellmastery")) {
        return 1;                                                                                             // spellmastery spell is always in memory!
    }
    if (myclass == "psywarrior") {
        return 1;
    }
    if (myclass == "psion") {
        return 1;
    }
    if (myclass == "warlock") {
        myknown = TO->query_mastered_spells(myclass);
        if (!sizeof(myknown)) {
            return 0;
        }
        if (member_array(spell, myknown) != -1) {
            return 1;
        }
        return 0;
    }
    if (myclass == "monk") {
        myknown = TO->query_ki_spells();
        if (!sizeof(myknown)) {
            return 0;
        }
        if (member_array(spell, myknown) != -1) {
            return 1;
        }
        return 0;
    }
    if (myclass == "bard" ||
        myclass == "inquisitor" ||
        myclass == "oracle" ||
        myclass == "sorcerer") {
        if (sscanf(spell, "level %d", lvl) != 1) {
            lvl = (int)MAGIC_D->query_spell_level(myclass, spell);
        }
        if (!lvl) {
            return 0;
        }
        spell = "generic";
    }else {
        lvl = (int)MAGIC_D->query_spell_level(myclass, spell);
        if (!lvl) {
            return 0;
        }
    }

    if (!mapp(spells_memorized[myclass])) {
        add_mem_class(myclass);
    }

    // re-orders the memorized mapping to fit the spell level the master of versatility
    // is trying to cast, if it has enough spell levels possible to do so
    if (spell == "generic" && FEATS_D->usable_feat(TO, "master of versatility")) {
        if (!spells_memorized[myclass][lvl][spell]) {
            class_ob = find_object_or_load(DIR_CLASSES + "/versatile_arcanist.c");
            spells_memorized[myclass] = class_ob->reorder_memorized(TO, lvl);
        }
    }

    if (!spells_memorized[myclass][lvl][spell]) {
        return 0;
    }
    return spells_memorized[myclass][lvl][spell];
}

int can_memorize(string myclass, string spell)
{
    int lvl, max, curr, class_level;
    string mystat, subrace;

    if (!spells_memorized) {
        resetMemorized();
    }
    if (myclass == "bard" ||
        myclass == "inquisitor" ||
        myclass == "oracle" ||
        myclass == "sorcerer") {
        if (sscanf(spell, "level %d", lvl) != 1) {
            return 0;
        }
    }else {
        lvl = MAGIC_D->query_spell_level(myclass, spell);
        if (!lvl) {
            return 0;
        }
    }
    if ((query_spell_level_restricted(myclass)) && lvl >= query_spell_level_restricted(myclass)) {
        return SPELL_RESTRICTED;
    }
    if (member_array(spell, query_spells_restricted(myclass)) != -1) {
        return SPELL_RESTRICTED;
    }

    curr = query_num_spells_level(myclass, lvl);
    max = 0;
    switch (myclass) {
    case "cleric":
    case "paladin":
    case "ranger":
    case "druid":
    case "inquisitor":
        mystat = "wisdom"; break;

    case "bard":
    case "sorcerer":
    case "oracle":
        mystat = "charisma"; break;

    default:
        mystat = "intelligence"; break;
    }

    class_level = TO->query_prestige_level(myclass); // calculated in /std/user.c

    if (myclass == "paladin" && !TO->is_class("paladin") && TO->is_class("antipaladin")) {
        max = WIZ_CALCS->query_spell_limit(lvl, class_level, myclass, (int)TO->query_stats(mystat));
    }else {
        max = WIZ_CALCS->query_spell_limit(lvl, class_level, myclass, (int)TO->query_stats(mystat));
    }

    max = magic_arsenal_feat(max);
    max = bonus_spell_slots(max);
    max = bonus_spell_slots_by_level(lvl, max);
    if (lvl == 1 && (string)TO->query_race() == "human") {
        subrace = (string)TO->query("subrace");
        if (subrace) {
            if (subrace == "senzokuan") {
                max++;                    // +1 to slots at L1 for human Senzokuan ethnicity
            }
        }
    }

    if (curr >= max) {
        return TOO_MANY;
    }
    if (lvl > (query_stats(mystat) - 10)) {
        return TOO_STUPID;
    }
    return MEM_OK;
}

int check_memorized(string myclass, string spell)
{
    if (!spells_memorized) {
        resetMemorized();
    }
    if (!query_memorized(myclass, spell)) {
        return 0;
    }
    if (!forget_memorized(myclass, spell)) {
        return 0;
    }
    return 1;
}

int query_num_spells_level(string myclass, int lvl)
{
    mapping tmp;
    string* ky;
    int num, i;

    if (!spells_memorized) {
        resetMemorized();
    }
    num = 0;
    if (!mapp(spells_memorized[myclass])) {
        add_mem_class(myclass);
    }
    tmp = spells_memorized[myclass][lvl];
    if (!tmp) {
        return -1;
    }
    ky = keys(tmp);
    for (i = 0; i < sizeof(tmp); i++) {
        num += tmp[ky[i]];
    }
    return num;
}

mixed* query_all_memorized(string myclass)
{
    if (!spells_memorized) {
        resetMemorized();
    }
    if (!mapp(spells_memorized[myclass])) {
        add_mem_class(myclass);
    }
    return spells_memorized[myclass];
}

mixed* query_just_spells(string myclass)
{
    mapping tmp;
    int i;

    if (!spells_memorized) {
        resetMemorized();
    }
    tmp = ([]);
    for (i = 1; i <= 9; i++) {
        tmp += spells_memorized[myclass][i];
    }
    return tmp;
}

mixed* query_all_level(string myclass, int lvl)
{
    if (!spells_memorized) {
        resetMemorized();
    }
    return spells_memorized[myclass][lvl];
}

void forget_all_spells()
{
    resetMemorized();
}

void forget_class_spells(string myclass)
{
    if (!spells_memorized) {
        resetMemorized();
    }
    map_delete(spells_memorized, myclass);
}

void resetMemorized()
{
    string* myclasses;
    int i, j;
    spells_memorized = ([]);
    myclasses = get_dir("/std/class/*.c");
    if (!sizeof(myclasses)) {
        return;
    }
    for (i = 0; i < sizeof(myclasses); i++) {
        myclasses[i] = replace_string(myclasses[i], ".c", "");
        spells_memorized[myclasses[i]] = ([]);
// iterate 9 spell-levels of empty mappings for all classes as safety, as mappings implode without lower levels set! -N
        for (j = 0; j <= 9; j++) {
            spells_memorized[myclasses[i]][j] = ([]);
        }
    }
}

void add_mem_class(string myclass)
{
    int j;
    spells_memorized[myclass] = ([]);
    for (j = 0; j <= 9; j++) {
        spells_memorized[myclass][j] = ([]);
    }
}

//Spell restriction code
void restrict_spell(string classname, string spellname)
{
    string* restrictkeys;
    if (!lost_spells) {
        lost_spells = ([]);
    }
    if (!mapp(lost_spells)) {
        lost_spells = ([]);
    }
    if (!TO->is_class(classname)) {
        return;
    }
    if (member_array(spellname, lost_spells[classname]) == -1) {
        lost_spells[classname] += ({ spellname });
    }
}

void unrestrict_spell(string classname, string spellname)
{
    if (!lost_spells) {
        lost_spells = ([]);
    }
    if (!mapp(lost_spells)) {
        lost_spells = ([]);
    }
    if (!TO->is_class(classname)) {
        return;
    }
    if (spellname == "all") {
        lost_spells[classname] = ({});
        return;
    }
    if (member_array(spellname, lost_spells[classname]) != -1) {
        lost_spells[classname] -= ({ spellname });
    }
}

string* query_spells_restricted(string classname)
{
    if (!lost_spells) {
        lost_spells = ([]);
    }
    if (!mapp(lost_spells)) {
        lost_spells = ([]);
    }
    if (!lost_spells[classname]) {
        return ({});
    }
    return lost_spells[classname];
}

int query_spell_level_restricted(string classname)
{
    string* myclasses;
    int i;
    if (!lost_spell_level) {
        lost_spell_level = ([]);
        myclasses = get_dir("/std/class/*.c");
        if (!sizeof(myclasses)) {
            return 0;
        }
        for (i = 0; i < sizeof(myclasses); i++) {
            lost_spell_level[myclasses[i]] = 9;
        }
    }
    if (!mapp(lost_spell_level)) {
        lost_spell_level = ([]);
        myclasses = get_dir("/std/class/*.c");
        if (!sizeof(myclasses)) {
            return 0;
        }
        for (i = 0; i < sizeof(myclasses); i++) {
            lost_spell_level[myclasses[i]] = 9;
        }
    }

    if (!lost_spell_level[classname]) {
        return 0;
    }
    return lost_spell_level[classname];
}

void set_spell_level_restricted(string classname, int level)
{
    string* myclasses;
    int i;
    if (!lost_spell_level) {
        lost_spell_level = ([]);
        myclasses = get_dir("/std/class/*.c");
        if (!sizeof(myclasses)) {
            return;
        }
        for (i = 0; i < sizeof(myclasses); i++) {
            lost_spell_level[myclasses[i]] = 9;
        }
    }
    if (!mapp(lost_spell_level)) {
        lost_spell_level = ([]);
        myclasses = get_dir("/std/class/*.c");
        if (!sizeof(myclasses)) {
            return;
        }
        for (i = 0; i < sizeof(myclasses); i++) {
            lost_spell_level[myclasses[i]] = 9;
        }
    }
    if (level < 0) {
        lost_spell_level[classname] = 0;
    }else if (level < 9) {
        lost_spell_level[classname] = level;
    }else {
        lost_spell_level[classname] = 9;
    }
}

// mage spells gained freely stuff - 'master' command
int* query_masterable_spells()   // 42 to avoid array emptying
{
    if (!masterable) {
        masterable = ({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 42, });
    }
    return masterable;
}

void remove_masterable(int removing)   // 42 to avoid array emptying
{
    if (!masterable) {
        masterable = ({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 42, });
    }
    if (!removing) {
        return;
    }
    if (member_array(removing, masterable) != -1) {
        masterable -= ({ removing });
    }
}

void add_masterable(int adding)   // 42 to avoid array emptying
{
    if (!masterable) {
        masterable = ({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 42, });
    }
    if (!adding) {
        return;
    }
    if (member_array(adding, masterable) == -1 && adding < 10 && adding > 0) {
        masterable += ({ adding });
    }
}

string* query_mastered_spells(string theclass)
{
    string myclass;
    string* retarray;
    if (!stringp(theclass)) {
        myclass = TO->query_class();
    }else {
        myclass = theclass;
    }

    retarray = ({});
    if (member_array(myclass, keys(query_mastered_base())) > -1) {
        retarray += query_mastered_base()[myclass];
    }
    if (member_array(myclass, keys(query_mastered_bonus())) > -1) {
        retarray += query_mastered_bonus()[myclass];
    }
    return retarray;
}

/**
 * Spells player mastered without any feats.
 */
mapping query_mastered_base()
{
    mapping tmp = mastered;

    //2019 conversion
    if (!sizeof(tmp) && sizeof(masteredspells)) {
        mastered = allocate_mapping(1);
        mastered[TO->query_class()] = masteredspells + ({});
    }

    tmp = mastered;
    return tmp ? tmp : ([]);
}

/**
 * Returns bonus spells
 */
mapping query_mastered_bonus()
{
    mapping tmp = ([]);

    if (TO->is_class("psion")) {
        string mydis = (string)TO->query_discipline();
        if (stringp(mydis)) {
            tmp["psion"] = MAGIC_SS_D->query_class_special_spells("psion", mydis);;
        }
    }

    if (TO->is_class("sorcerer")) {
        string mybl = (string)TO->query_bloodline();

        if (stringp(mybl)) {
            tmp["sorcerer"] = MAGIC_SS_D->query_class_special_spells("sorcerer", mybl);
        }
    }

    if (TO->is_class("oracle")) {
        string mybl = (string)TO->query_mystery();

        if (stringp(mybl)) {
            tmp["oracle"] = MAGIC_SS_D->query_class_special_spells("oracle", mybl);
            tmp["oracle"] += MAGIC_SS_D->query_class_special_spells("oracle", "all");
        }
    }


    if (TO->is_class("shadow_adept")) {
        if (FEATS_D->usable_feat(TO, "gift of the shadows")) {
            string baseclass = TO->query("shadow_adept_base_class");
            if (!arrayp(tmp[baseclass])) {
                tmp[baseclass] = ({});
            }
            tmp[baseclass] += MAGIC_SS_D->query_class_special_spells("shadow_adept", "all");
        }
    }

    if (TO->is_class("psion") || TO->is_class("psywarrior")) {
        string theclass = TO->is_class("psion") ? "psion" : "psywarrior";
        if (TO->is_class(theclass) && !tmp[theclass]) {
            tmp[theclass] = ({});
        }

        if (!arrayp(tmp[theclass])) {
            tmp[theclass] = ({});
        }

        if (FEATS_D->usable_feat(TO, "expanded knowledge 1")) {
            tmp[theclass] += ({ TO->query("expanded_knowledge_1") });
        }
        if (FEATS_D->usable_feat(TO, "expanded knowledge 2")) {
            tmp[theclass] += ({ TO->query("expanded_knowledge_2") });
        }
        if (FEATS_D->usable_feat(TO, "expanded knowledge 3")) {
            tmp[theclass] += ({ TO->query("expanded_knowledge_3") });
        }
    }

    if (TO->is_class("psywarrior")) {
        if (FEATS_D->usable_feat(TO, "mind over matter")) {
            tmp["psywarrior"] += (({ "true metabolism" }));
        }
        if (FEATS_D->usable_feat(TO, "mental fortress")) {
            tmp["psywarrior"] += (({ "timeless body" }));
        }
    }

    if (TO->is_class("warlock")) {
        tmp["warlock"] = MAGIC_SS_D->query_class_special_spells("warlock", "all");

        if (TO->is_class("hellfire warlock")) {
            tmp["warlock"] += ({ "brimstone blast" });
        }
        if (FEATS_D->usable_feat(TO, "infernal practitioner")) {
            tmp["warlock"] += ({ "hellfire shield", "infernal rain" });
        }
    }

    return tmp ? tmp : ([]);
}

void add_mastered(string myclass, string addspell)
{
    mapping tmp;
    tmp = query_mastered_base();
    if (!addspell) {
        return;
    }
    if (!myclass) {
        return;
    }
    if (!sizeof(tmp[myclass])) {
        tmp[myclass] = ({});
    }
    if (member_array(addspell, tmp[myclass]) == -1) {
        tmp[myclass] += ({ addspell });
    }
    mastered = tmp;
}

void remove_mastered(string myclass, string remspell)
{
    mapping tmp;
    tmp = query_mastered_base();
    if (!remspell) {
        return;
    }
    if (!myclass) {
        return;
    }
    if (member_array(remspell, tmp[myclass]) != -1) {
        tmp[myclass] -= ({ remspell });
    }
    mastered = tmp;
}

string* query_base_mastered_spells()
{
    if (!masteredspells) {
        masteredspells = ({});
    }
    return masteredspells;
}

void add_mastered_spell(string newspell)
{
    string spellfile;
    if (!masteredspells) {
        masteredspells = ({});
    }
    if (!newspell) {
        return;
    }
    spellfile = "/cmds/spells/" + newspell[0..0] + "/_" + replace_string(newspell, " ", "_") + ".c";
    if (file_exists(spellfile)) {
        masteredspells += ({ newspell });
    }
}

void remove_mastered_spell(string remspell)
{
    if (!masteredspells) {
        masteredspells = ({});
    }
    if (!remspell) {
        return;
    }
    if (member_array(remspell, masteredspells) != -1) {
        masteredspells -= ({ remspell });
    }
}

void reset_mastered()
{
    masteredspells = 0;
    masterable = 0;
    mastered = ([]);
}

void prepare(string str, int temp, string myclass, int num)
{
    object obt;
    if (!objectp(obt = TO->query_property("memorizing")) && (obt != TO)) {
        return;
    }
    if (random(8) == 0) {
        switch (myclass) {
        case "cleric":
        case "paladin":
        case "ranger":
            tell_object(TO, "You feel the power of your god.");
            tell_room(ETO, TO->QCN + " wavers a second before you.", TO);
            break;

        case "bard":
            tell_object(TO, "You carefully commit tone, rhythm and pitch to memory.");
            tell_room(ETO, TO->QCN + " hums a note as if testing its tone and pitch.", TO);
            break;

        case "psion":
        case "psywarrior":
            tell_object(TO, "The intricacies of the power swirl within your mind.");
            tell_room(ETO, TO->QCN + "'s head bows as " + TO->QS + " sways before you.", TO);
            break;

        case "druid":
            tell_object(TO, "The energies of the wilderness thrum through you.");
            tell_room(ETO, TO->QCN + " seems momentarily at peace.", TO);
            break;

        case "sorcerer":
            tell_object(TO, "The arcane power hums through your body.");
            tell_room(ETO, TO->QCN + " focusses intently.", TO);
            break;

        default:
            tell_object(TO, "You concentrate carefully on committing the spell to memory.");
            tell_room(ETO, TO->QCN + "'s expression conveys deep concentration.", TO);
            break;
        }
    }
    temp -= 2;

    if (myclass == "psywarrior" || myclass == "psion") {
        mymax = TO->query_max_mp();
        if (!mymax) {
            if (objectp(TO)) {
                tell_object(TO, "Something is wrong with your maximum power points. Please contact a wiz.");
            }
            return 1;
        }
        mypp = TO->query_mp();
        if (mypp < 0) {
            mypp = 0;
        }
        myneeded = mymax - mypp;
        if (myneeded < 1) {
            prepare2();
            return 1;
        }
        if (num > myneeded) {
            num = myneeded;
        }
        if (num > 5) {
            TO->add_mp(5); // began as 17 (points required for 9th level power), was way too fast. Trying 5, may need to be adjusted
            num = num - 5;
            call_out("prepare", 2, str, temp, myclass, num);
            return 1;
        }else {
            TO->add_mp(num);
            prepare2();
            return 1;
        }
    }

    if (temp > 0 && (can_memorize(myclass, str) == MEM_OK)) {
        if (num > 1 && !random(3)) {
            set_memorized(myclass, str, 1);
            num--;
        }
        call_out("prepare", 2, str, temp, myclass, num);
    }else {
        if (num > 1) {
            while (num--) {
                if (can_memorize(myclass, str) == MEM_OK) {
                    set_memorized(myclass, str, 1);
                }
            }
        }else {
            if (num && (can_memorize(myclass, str) == MEM_OK)) {
                set_memorized(myclass, str, 1);
            }
        }
        prepare2();
        return 1;
    }
}

void prepare2()
{
    if (TO->query_property("memorizing")) {
        TO->remove_property("memorizing");
    }
    tell_room(ETO, TO->QCN + " completes " + TO->QP + " preparations.", TO);
    tell_object(TO, "%^BOLD%^%^GREEN%^You have finished preparing your spells.");
}

int add_aoe(string spellname)
{
    if (TO->set_property("aoe list", ({ spellname }))) {
        return 1;
    }else {
        return 0;
    }
}

int subtract_aoe(string spellname)
{
    string* aoelist;

    if (!arrayp(TO->query_property("aoe list"))) {
        return 0;
    }
    aoelist = TO->query_property("aoe list");
    aoelist -= ({ spellname });
    TO->remove_property("aoe list");
    TO->set_property("aoe list", aoelist);
    return 1;
}

int has_aoe(string spellname)
{
    if (!arrayp(TO->query_property("aoe list"))) {
        return 0;
    }
    if (member_array(spellname, TO->query_property("aoe list")) != -1) {
        return 1;
    }else {
        return 0;
    }
}
