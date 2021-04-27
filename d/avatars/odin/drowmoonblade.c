#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/elvencurvedblade.c";

int glowing, owned, rune1, rune2, rune3, rune4, rune5;
string obvshort, short, owner;

void create()
{
    ::create();
    short = "%^BOLD%^%^WHITE%^G%^CYAN%^i%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^r'%^BOLD%^%^WHITE%^E%^RESET%^%^CYAN%^v%^BOLD%^e%^RESET%^%^CYAN%^ra%^BOLD%^e %^RESET%^%^CYAN%^- %^BOLD%^%^BLACK%^G%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^a%^CYAN%^r%^RESET%^%^CYAN%^di%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^n %^BOLD%^o%^RESET%^%^CYAN%^f t%^BOLD%^%^BLUE%^h%^RESET%^%^CYAN%^e P%^BOLD%^%^BLUE%^e%^CYAN%^o%^RESET%^%^CYAN%^pl%^BOLD%^%^BLUE%^e%^RESET%^";

    obvshort = "%^CYAN%^An elegant %^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^t%^RESET%^h%^BOLD%^r%^CYAN%^i%^WHITE%^l c%^CYAN%^u%^RESET%^r%^BOLD%^v%^CYAN%^e%^WHITE%^d bl%^CYAN%^a%^WHITE%^d%^RESET%^e %^CYAN%^bearing %^BOLD%^e%^WHITE%^lv%^CYAN%^e%^WHITE%^n %^CYAN%^r%^WHITE%^u%^BLUE%^n%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^and a %^BOLD%^%^BLACK%^dr%^CYAN%^a%^BLACK%^con%^CYAN%^i%^BLACK%^c h%^CYAN%^i%^BLACK%^lt%^RESET%^";

    set_name("mithril elven curved blade");
    set_id(({ "mithril elven curved blade", "elven curved blade", "sword", "curved blade", "blade", "moonblade", "Gisir'Everae", "gisir'everae", "guardian of the people", "Guardian of the People" }));
    set_short(short);
    set_obvious_short(obvshort);

    set_long("%^BOLD%^%^CYAN%^Essentially a longer version of a scimitar, but with a thinner blade, the elven curve blade is exceptionally rare. The curved mirror-like blade is made of %^WHITE%^gle%^CYAN%^a%^WHITE%^ming m%^CYAN%^i%^WHITE%^th%^CYAN%^r%^WHITE%^il%^CYAN%^, with a tapered point that allows for effective thrusting attacks against heavily armored foes. From the tip, it broadens slightly and then curves down in a crescent shape almost to the hilt, the %^BLACK%^r%^WHITE%^a%^BLACK%^zor-sh%^WHITE%^a%^BLACK%^rp %^WHITE%^e%^BLACK%^dg%^WHITE%^e %^CYAN%^allowing for vicious cutting attacks. In from the edge, the blade broadens in a lenticular shape, but is prevented from reaching thickness at the center by the inlay of a wide fuller. A series of e%^BLACK%^lv%^CYAN%^e%^BLACK%^n %^CYAN%^r%^WHITE%^u%^BLUE%^n%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^s %^CYAN%^thread their way down the middle of this indentation, until the blade straightens at the last to meet raised ridges before the hilt, which then flare to either side as the spreading %^BLACK%^sc%^CYAN%^a%^BLACK%^led w%^CYAN%^i%^BLACK%^ngs %^CYAN%^of a %^BLACK%^dr%^CYAN%^a%^BLACK%^gon%^CYAN%^. Its long, narrow throat extends yet further, leaving space enough to hold the grip firmly in both hands, before the beast's head rises to serve as a pommel to the weapon. A %^WHITE%^gl%^CYAN%^e%^WHITE%^am%^CYAN%^i%^WHITE%^ng mo%^CYAN%^o%^WHITE%^nst%^CYAN%^o%^WHITE%^ne %^CYAN%^is grasped within its fanged maw, offering a greater counterweight to balance the swing of the blade. The entire effect is given of a masterworked weapon of unmatched craftsmanship, heavy enough to be effective in both hands, while still maintaining an elegance of form. It would serve as a %^BLACK%^de%^BLUE%^a%^BLACK%^dly w%^BLUE%^e%^BLACK%^ap%^BLUE%^o%^BLACK%^n %^CYAN%^in the hands of an experienced user.%^RESET%^\n");

    set_lore("  Lo, for it was conceived among the elders of the Realm of Promises Fulfilled, that blades would "
             "be blessed and woven within the High Art, that they might discern among elvenkind the most worthy and wise to "
             "be rulers of the People.  The High Mages of the court gathered, each conducting ritual over those blades "
             "created, and above them all stood the Grand Mage Ethlando.  By his hand all these rituals were bound as one, "
             "and together a great weaving was made across Toril to bind all of the High Mages in solemn ceremony.\n"
             "  And when it was done, it came to each clan's heir to take up the blade and be judged for their worthiness "
             "to rule.  Within the blades was imbued the ability to grant power and protection to those of rightful morals, "
             "and death to any other who attempted to harness their power.  Of the few hundred who stood forward at the "
             "First Claiming Ceremony, near half their number perished, and dozens of Gold Elf houses stood humbled as "
             "their heirs were judged unworthy to rule elvenkind.  And so they were named the moonblades, for at the last, "
             "greatest among those judged worthy were Moon Elf clans.\n"
             "  Left was the promise of the Grand Mage Ethlando, as he spake prophecy to the rightful heirs that remained.  "
             "'When the blades number a score and four, they shall ring out the time for the Ascension Ceremony.  The one "
             "clan and one clan heir chosen worthiest by the moonblades shall unify the elves in their truest homeland, "
             "where the heir shall rule over all.  Never again shall a tyrant ruin all that is great among the People, for "
             "both the Seldarine and the Weave shall choose through the swords' magic.'\n  - from 'The crafting of the "
             "Moonblades', recorded by Lor'dressil the Learned.");

    set_property("lore difficulty", 35);
    set_property("id difficulty", 35);
    set_value(23200);
    set_property("enchantment", 7);
    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);
    set_item_bonus("sight bonus", 3);
    set_special_material_type("silver");
    glowing = 0;
    owned = 0;
    set_heart_beat(1);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_hit((: TO, "hit_func" :));
}

int wield_func()
{
    int myflag, i;
    object* mywielded;
    rune1 = 0;
    rune2 = 0;
    rune3 = 0;
    rune4 = 0;
    rune5 = 0;
    if ((string)ETO->query_name() != "ryzan" && !avatarp(ETO)) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You attempt to take up the sword, and the runes upon the blade flare "
                    "an angry shade of %^GREEN%^vi%^RESET%^%^GREEN%^r%^BOLD%^id%^RESET%^%^GREEN%^i%^BOLD%^an%^WHITE%^!  A shock of "
                    "%^RED%^ag%^MAGENTA%^on%^RED%^y %^WHITE%^runs through your body, and you can't help but to drop the weapon."
                    "%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + "%^BOLD%^%^WHITE%^ attempts to take up the sword, and the "
                  "runes upon the blade flare an angry shade of %^GREEN%^vi%^RESET%^%^GREEN%^r%^BOLD%^id%^RESET%^%^GREEN%^i"
                  "%^BOLD%^an%^WHITE%^!  " + capitalize(ETO->QS) + " lets out a gasp and drops the weapon.%^RESET%^", ETO);
        TO->set_property("magic", 1);
        ETO->do_damage("torso", roll_dice(20, 10));
        TO->set_property("magic", -1);
        ETO->force_me("drop gisir'everae");
        return 0;
    }
    if (ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
        tell_object(ETO, "%^BOLD%^%^WHITE%^You reach out to grasp the blade, and the weapon already in your hand "
                    "seems to radiate with denial.  You find yourself unwilling even to lift the second weapon!");
        tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + " reaches out to grasps the blade, but then hesitates, and "
                  "stops.", ETO);
        return 0;
    }
    if (!owned) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^As you grasp the blade, a feeling runs through you of a presence "
                    "watching... judging... and then a calm %^RESET%^%^GREEN%^acceptance %^BOLD%^%^WHITE%^washes over you.  You "
                    "realise it must have been the weapon in your hand, testing you somehow.  And fortunately, it seems you passed!"
                    "%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^WHITE%^An intense look comes briefly over " + ETO->QCN + "%^BOLD%^%^WHITE%^'s face, "
                  "before " + ETO->QS + " relaxes again.%^RESET%^", ETO);
        owned = 1;
        owner = ETO->query_name();
    }else {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The sword's patterned grip rests %^BOLD%^%^BLUE%^e%^CYAN%^as%^BLUE%^il"
                    "%^CYAN%^y %^WHITE%^in your hands as you take up the weapon.%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^WHITE%^The sword's patterned grip rests %^BOLD%^%^BLUE%^e%^CYAN%^as%^BLUE%^il"
                  "%^CYAN%^y %^WHITE%^in " + ETO->QCN + "'s hands as " + ETO->QS + " takes up the weapon.%^RESET%^", ETO);
    }
    ETO->set_property("good item", 1);
    ETO->set_property("master weapon", 1);
    return 1;
}

int unwield_func()
{
    rune1 = 0;
    rune2 = 0;
    rune3 = 0;
    rune4 = 0;
    rune5 = 0;
    tell_object(ETO, "%^BOLD%^%^WHITE%^You release your hold on the %^BLACK%^com%^RESET%^%^ORANGE%^fo%^BOLD%^"
                "%^BLACK%^rtab%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e %^WHITE%^grip of the sword.%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + "%^BOLD%^%^WHITE%^ releases hold on the grip of the sword.%^RESET%^", ETO);
    ETO->set_property("good item", -1);
    ETO->set_property("master weapon", -1);
    return 1;
}

int get_evils(object ob)
{
    if (ob == ETO) {
        return 0;
    }
    if (ob->query_true_invis()) {
        return 0;
    }
    if ((int)ob->query_property("hidden alignment") % 3) {
        return 0;
    }
    if ((int)ob->query_property("hidden alignment") && !((int)ob->query_property("hidden alignment") % 3)) {
        return 1;
    }
    if ((int)ob->query_alignment() % 3) {
        return 0;
    }
    return 1;
}

void heart_beat()
{
    object holder, location, * people, * ids;
    int tracker, i;
    if (!objectp(ETO)) {
        return;
    }
    if (!objectp(EETO)) {
        return;
    }
    tracker = 0;
    ids = TO->query_id();
    holder = ETO;
    location = environment(holder);
    people = all_living(location);
    for (i = 0; i < sizeof(people); i++) {
        if (get_evils(people[i])) {
            tracker = 1;
        }
    }
    if (tracker && !glowing) {
        if (!TO->query_wielded()) {
            return;
        }
        if (!holder->query_invis()) {
            tell_room(location, "%^BOLD%^%^WHITE%^The " + ids[0] +
                      " in " + holder->QCN + "'s hands takes on a %^CYAN%^pale ra%^GREEN%^d%^CYAN%^iance"
                      "%^BOLD%^%^WHITE%^.%^RESET%^", holder);
        }
        tell_object(holder, "%^BOLD%^%^WHITE%^The " + ids[0] + " in your hand takes on "
                    "a %^CYAN%^pale ra%^GREEN%^d%^CYAN%^iance%^BOLD%^%^WHITE%^, warning of danger "
                    "nearby.%^RESET%^");
        TO->set_short(short + " %^BOLD%^%^CYAN%^(glowing softly)%^RESET%^");
        TO->set_obvious_short(obvshort + " %^BOLD%^%^CYAN%^(glowing softly)%^RESET%^");
        glowing = 1;
    }else {
        if (glowing && (!TO->query_wielded() || !tracker)) {
            if (!holder->query_invis()) {
                tell_room(location, "%^BOLD%^%^WHITE%^The " + ids[0] +
                          " in " + holder->QCN + "'s hands stops glowing again.%^RESET%^", holder);
            }
            if (!TO->query_wielded()) {
                tell_object(holder, "%^BOLD%^%^WHITE%^The " + ids[0] + " stops glowing "
                            "again as you release contact with it.%^RESET%^");
            }else {
                tell_object(holder, "%^BOLD%^%^WHITE%^The " + ids[0] + " in your hand stops "
                            "glowing again, the danger past.%^RESET%^");
            }
            TO->set_short(short);
            TO->set_obvious_short(obvshort);
            glowing = 0;
        }
    }
    return;
}

int special_damage()
{
    int sdamage;
    string bonus_stat;
    int mysize;
    mysize = (int)ETO->query_size();
    if (mysize == 1) {
        mysize++;             //run small creatures as normal size please.
    }
    mysize -= (int)TO->query_size();
    if (FEATS_D->usable_feat(ETO, "weapon finesse") && (mysize >= 0)) { // if has-feat & weapon is smaller than/equal to user
        bonus_stat = "dexterity";
    }else {
        bonus_stat = "strength";
    }
    sdamage = TO->query_wc() + (int)TO->query_property("enchantment") + (int)ETO->query_damage_bonus() + (int)BONUS_D->new_damage_bonus(ETO, ETO->query_stats(bonus_stat));
    return sdamage;
}

int hit_func(object targ)
{
    int rand;
    object ob;
    if (!objectp(ETO)) {
        return 0;
    }
    if (!objectp(EETO)) {
        return 0;
    }
    targ = ETO->query_current_attacker();
    if (!objectp(targ)) {
        return 0;
    }
    if (random(1000) + 1 > 600) {
        if (rune1 == 1 && rune2 == 1 && rune3 == 1 && rune4 == 1 && rune5 == 1) {
            rune1 = 0; //turn off all runes before we go into death blossom
            rune2 = 0;
            rune3 = 0;
            rune4 = 0;
            rune5 = 0;
            call_out("death_blossom", 0.5);
            return 1;
        }

        switch (random(11)) {

        case 0..2: //double damage
            tell_object(ETO, "%^BOLD%^%^CYAN%^The first rune upon the blade fl%^WHITE%^a%^CYAN%^r%^WHITE%^e%^CYAN%^s br%^WHITE%^i%^CYAN%^ll%^WHITE%^i%^CYAN%^antly and the air grows chill as it cuts a frosted, bloodless line through " + targ->QCN + "'s flesh!%^RESET%^");

            tell_object(targ, "%^BOLD%^%^CYAN%^The first rune upon " + ETO->QCN + "'s blade fl%^WHITE%^a%^CYAN%^r%^WHITE%^e%^CYAN%^s b%^WHITE%^r%^CYAN%^ill%^WHITE%^i%^CYAN%^antl%^WHITE%^y %^CYAN%^and the air grows chill as it cuts a frosted, bloodless line through your flesh!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^CYAN%^The first rune upon " + ETO->QCN + "'s blade fl%^WHITE%^a%^CYAN%^r%^WHITE%^e%^CYAN%^s b%^WHITE%^r%^CYAN%^ill%^WHITE%^i%^CYAN%^antl%^WHITE%^y %^CYAN%^and the air grows chill as it cuts a frosted, bloodless line through " + targ->QCN + "'s flesh!%^RESET%^", ({ ETO, targ }));

            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage() * 150 / 100, TO->query_damage_type());
            rune1 = 1;
            break;

        case 3..4: //temporary blindness
            tell_object(ETO, "%^BOLD%^The second rune upon the blade emits a b%^RESET%^u%^BOLD%^rst of s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^ry l%^RESET%^i%^BOLD%^ght as it crashes into " + targ->QCN + "!%^RESET%^");

            tell_object(targ, "%^BOLD%^The second rune upon " + ETO->QCN + "'s blade emits a b%^RESET%^u%^BOLD%^rst of s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^ry l%^RESET%^i%^BOLD%^ght as it crashes into you and the world disappears in a blinding white afterimage!%^RESET%^");

            tell_room(EETO, "%^BOLD%^The second rune upon " + ETO->QCN + "'s blade emits a b%^RESET%^u%^BOLD%^rst of s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^ry l%^RESET%^i%^BOLD%^ght as it crashes into " + targ->QCN + ", nearly blinding you!%^RESET%^", ({ ETO, targ }));

            targ->set_temporary_blinded(2);
            rune2 = 1;
            break;

        case 5..6: //paralyze
            tell_object(ETO, "%^BOLD%^%^BLUE%^The third rune upon the blade %^CYAN%^fl%^WHITE%^a%^CYAN%^sh%^WHITE%^e%^CYAN%^s %^BLUE%^to life as it carves through " + targ->QCN + " and a wave of %^WHITE%^fr%^CYAN%^o%^WHITE%^st %^BLUE%^cascades into them, encasing them in %^WHITE%^i%^CYAN%^c%^WHITE%^e%^BLUE%^!%^RESET%^");

            tell_object(targ, "%^BOLD%^%^BLUE%^The third rune upon " + ETO->QCN + "'s blade %^CYAN%^fl%^WHITE%^a%^CYAN%^sh%^WHITE%^e%^CYAN%^s %^BLUE%^to life as it carves through you and a wave of %^WHITE%^fr%^CYAN%^o%^WHITE%^st %^BLUE%^cascades into you, encasing you in %^WHITE%^i%^CYAN%^c%^WHITE%^e%^BLUE%^!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^BLUE%^The third rune upon " + ETO->QCN + "'s blade %^CYAN%^fl%^WHITE%^a%^CYAN%^sh%^WHITE%^e%^CYAN%^s %^BLUE%^to life as it carves through " + targ->QCN + "and a wave of %^WHITE%^fr%^CYAN%^o%^WHITE%^st %^BLUE%^cascades into them, encasing them in %^WHITE%^i%^CYAN%^c%^WHITE%^e%^BLUE%^!%^RESET%^", ({ ETO, targ }));

            targ->set_paralyzed(roll_dice(1, 10) + 10, "%^BOLD%^%^WHITE%^You are struggling break free of the %^BLUE%^i%^WHITE%^c%^BLUE%^e%^WHITE%^!%^RESET%^");
            rune3 = 1;
            break;

        case 7..8: //extra attack x 2
            tell_object(ETO, "%^CYAN%^The fourth rune upon the blade %^BOLD%^p%^RESET%^%^CYAN%^u%^BOLD%^ls%^RESET%^%^CYAN%^e%^BOLD%^s %^RESET%^%^CYAN%^and the world slows around you allowing you to strike twice in the space of a single %^BOLD%^%^WHITE%^breath%^RESET%^%^CYAN%^!%^WHITE%^");

            tell_room(EETO, "%^CYAN%^The fourth rune upon " + ETO->QCN + "'s blade %^BOLD%^p%^RESET%^%^CYAN%^u%^BOLD%^ls%^RESET%^%^CYAN%^e%^BOLD%^s %^RESET%^%^CYAN%^and he suddenly moves faster than the eye can follow to strike twice in the space of a single %^BOLD%^%^WHITE%^breath%^RESET%^%^CYAN%^!%^WHITE%^", ETO);

            ETO->execute_attack();
            ETO->execute_attack();
            rune4 = 1;
            break;

        case 9: //shadow double or tandem attack
            if (!present("drowshadow", EETO)) { //shadow double
                tell_object(ETO, "%^BOLD%^%^BLACK%^The fifth rune upon the blade gl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rkl%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^, and as you blink you realize the shadowy silhouette of a drow figure stands at your side in a protective stance.%^RESET%^");

                tell_room(EETO, "%^BOLD%^%^BLACK%^The fifth rune upon the blade gl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rkl%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^, and as you blink you realize the shadowy silhouette of a drow figure stands at " + ETO->QCN + "'s side in a protective stance.%^RESET%^", ETO);

                ob = new("/d/avatars/odin/drowshadow.c");
                ob->move(EETO);
                ob->force_me("protect " + ETO->query_name());
                ETO->add_follower(ob);
                rune5 = 1;
                break;
            }else { //tandem attack, triple damage ignores 10DR
                tell_object(ETO, "%^BOLD%^%^BLACK%^The fifth rune upon the blade gl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rkl%^RESET%^%^MAGENTA%^y %^BOLD%^%^BLACK%^as it slashes toward " + targ->QCN + " and your shadow guardian shifts to %^CYAN%^flank %^BLACK%^them striking simultaneously from behind!%^RESET%^");
                tell_object(targ, "%^BOLD%^%^BLACK%^The fifth rune upon " + ETO->QCN +"'s blade gl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rkl%^RESET%^%^MAGENTA%^y %^BOLD%^%^BLACK%^as it slashes toward you and their shadow guardian shifts to %^CYAN%^flank %^BLACK%^you striking simultaneously from behind!%^RESET%^");
                tell_room(EETO, "%^BOLD%^%^BLACK%^The fifth rune upon " + ETO->QCN + "'s blade gl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rkl%^RESET%^%^MAGENTA%^y %^BOLD%^%^BLACK%^as it slashes toward " + targ->QCN + " and the shadow guardian shifts to %^CYAN%^flank %^BLACK%^them striking simultaneously from behind!%^RESET%^", ({ ETO, targ }));

                TO->set_property("magic", 1);
                targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage() * 2, TO->query_damage_type());
                TO->remove_property("magic");
                rune5 = 1;
            }
            break;
        }
    }
    return 0;
}

void death_blossom()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^All five r%^WHITE%^u%^BLUE%^n%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^s %^CYAN%^upon your blade f%^WHITE%^l%^BLUE%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^e %^CYAN%^in unison and the area %^WHITE%^fl%^BLUE%^a%^WHITE%^sh fr%^BLUE%^e%^WHITE%^ez%^BLUE%^e%^WHITE%^s %^CYAN%^as a %^WHITE%^c%^CYAN%^h%^WHITE%^i%^BLUE%^l%^CYAN%^l w%^WHITE%^i%^CYAN%^nd envelopes your %^RESET%^%^CYAN%^bl%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^de %^BOLD%^and with a %^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^i%^RESET%^%^CYAN%^ngl%^BOLD%^%^BLACK%^e %^RESET%^%^CYAN%^sl%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^sh %^BOLD%^you unleash a %^BLACK%^v%^CYAN%^i%^BLACK%^ol%^CYAN%^e%^BLACK%^nt fl%^CYAN%^u%^BLACK%^rr%^CYAN%^y that visibly severs even the %^WHITE%^fr%^BLUE%^o%^WHITE%^zen %^BLUE%^ai%^WHITE%^r%^CYAN%^!%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^CYAN%^All five r%^WHITE%^u%^BLUE%^n%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^s %^CYAN%^upon " + ETO->QCN + "'s blade f%^WHITE%^l%^BLUE%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^e %^CYAN%^in unison and the area %^WHITE%^fl%^BLUE%^a%^WHITE%^sh fr%^BLUE%^e%^WHITE%^ez%^BLUE%^e%^WHITE%^s %^CYAN%^as a %^WHITE%^c%^CYAN%^h%^WHITE%^i%^BLUE%^l%^CYAN%^l w%^WHITE%^i%^CYAN%^nd envelopes his %^RESET%^%^CYAN%^bl%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^de %^BOLD%^and with a %^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^i%^RESET%^%^CYAN%^ngl%^BOLD%^%^BLACK%^e %^RESET%^%^CYAN%^sl%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^sh %^BOLD%^unleashes a %^BLACK%^v%^CYAN%^i%^BLACK%^ol%^CYAN%^e%^BLACK%^nt fl%^CYAN%^u%^BLACK%^rr%^CYAN%^y that visibly severs even the %^WHITE%^fr%^BLUE%^o%^WHITE%^zen %^BLUE%^ai%^WHITE%^r%^CYAN%^!%^RESET%^", ETO);

    ETO->execute_attack();
    ETO->execute_attack();
    ETO->execute_attack();
    if (!random(4)) {
        ETO->execute_attack();
    }
    if (!random(10)) {
        ETO->execute_attack();
    }
}

int setbound(string thename)
{
    owned = 1;
    owner = thename;
    return 1;
}
