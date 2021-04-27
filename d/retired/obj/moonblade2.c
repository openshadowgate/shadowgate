#include <std.h>
inherit "/d/common/obj/weapon/rapier.c";

int glowing;
string obvshort, short;

void create()
{
    ::create();
    set_name("mithril rapier");
    set_id(({ "rapier", "mithril rapier", "blade", "ornate rapier", "haera evaliir", "Haera Evaliir", "song of the oceans", "Song of the Oceans" }));
    set_short("%^YELLOW%^H%^BOLD%^%^WHITE%^a%^YELLOW%^er%^WHITE%^a %^YELLOW%^Ev%^WHITE%^a%^YELLOW%^li%^WHITE%^i%^YELLOW%^r %^WHITE%^- %^BOLD%^%^BLUE%^H%^WHITE%^e%^CYAN%^a%^BLUE%^rt %^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^f t%^CYAN%^h%^BLUE%^e O%^RESET%^%^BLUE%^ce%^CYAN%^a%^BOLD%^%^BLUE%^ns%^RESET%^");
    set_obvious_short("%^RESET%^a %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^rapier with an %^BOLD%^%^BLUE%^or%^CYAN%^na%^BLUE%^te %^RESET%^swept hilt");
    set_long("This weapon is known as a rapier, characterised by the long and narrow blade and its complex, "
             "protective hilt.  The blade itself is made of %^BOLD%^%^WHITE%^gle%^CYAN%^a%^WHITE%^ming mith%^CYAN%^r"
             "%^WHITE%^il%^RESET%^, barely broad enough to cut, and only sharpened from the midpoint to the tip, leaving "
             "its true potency in thrusting attacks.  However, the portion of the weapon that has been sharpened, has been "
             "done so to a %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r's edge%^RESET%^.  A series of %^GREEN%^e"
             "%^BOLD%^l%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^n %^BOLD%^r%^RESET%^%^GREEN%^u%^BOLD%^n%^RESET%^"
             "%^GREEN%^e%^BOLD%^s %^RESET%^thread their way down the slender blade to the %^BOLD%^%^BLACK%^b%^RESET%^a"
             "%^BOLD%^%^BLACK%^n%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^d crosspiece, decorated along its length with receding "
             "%^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^rings that finish in a small knob on either side.  This "
             "meets with the thick pommel of the weapon, finished with a similar style of rings to form a %^ORANGE%^"
             "comfortable grip %^RESET%^for the wielder, and finished in an identical knob of %^BOLD%^%^WHITE%^pol%^CYAN%^i"
             "%^WHITE%^shed mith%^CYAN%^r%^WHITE%^il%^RESET%^.  Around this sweeps a contour of shining metal strands like "
             "a %^BOLD%^%^BLUE%^ri%^CYAN%^si%^BLUE%^ng w%^WHITE%^a%^BLUE%^ve %^RESET%^of the ocean, swirling in a "
             "decorative arc that actually serves as a sturdy guard.  It flows down over the crosspiece and ricasso in "
             "ornate fashion, and back across the hilt to protect the wielder's hand. The entire effect is given of a "
             "masterworked weapon of unparalleled craftsmanship, light and elegant but potentially %^RED%^da%^MAGENTA%^ng"
             "%^RED%^e%^MAGENTA%^ro%^RED%^us %^RESET%^in the hands of an experienced user.\n");
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
    set_property("enchantment", 5);
    while (query_property("enchantment") != 5) {
        remove_property("enchantment");
        set_property("enchantment", 5);
    }
    set_item_bonus("attack bonus", 3);
    set_item_bonus("damage bonus", 3);
    set_item_bonus("sight bonus", 3);
    set_special_material_type("silver");
    glowing = 0;
    short = "%^YELLOW%^H%^BOLD%^%^WHITE%^a%^YELLOW%^er%^WHITE%^a %^YELLOW%^Ev%^WHITE%^a%^YELLOW%^li%^WHITE%^i%^YELLOW%^r %^WHITE%^- %^BOLD%^%^BLUE%^H%^WHITE%^e%^CYAN%^a%^BLUE%^rt %^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^f t%^CYAN%^h%^BLUE%^e O%^RESET%^%^BLUE%^ce%^CYAN%^a%^BOLD%^%^BLUE%^ns%^RESET%^";
    obvshort = "%^RESET%^a %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^rapier with an %^BOLD%^%^BLUE%^or%^CYAN%^na%^BLUE%^te %^RESET%^swept hilt";
    set_heart_beat(1);
    set_ac(1);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_hit((: TO, "hit_func" :));
}

int wield_func()
{
    if ((userp(ETO) && !avatarp(ETO)) || (int)ETO->query_alignment() % 3 != 1) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You attempt to take up the rapier, and "
                    "the runes upon the blade flare an angry shade of %^GREEN%^vi%^RESET%^%^GREEN%^"
                    "r%^BOLD%^id%^RESET%^%^GREEN%^i%^BOLD%^an%^WHITE%^!  A shock of %^RED%^ag"
                    "%^MAGENTA%^on%^RED%^y %^WHITE%^runs through your body, and you can't help but "
                    "to drop the weapon.%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + "%^BOLD%^%^WHITE%^ attempts to "
                  "take up the rapier, and the runes upon the blade flare an angry shade of "
                  "%^GREEN%^vi%^RESET%^%^GREEN%^r%^BOLD%^id%^RESET%^%^GREEN%^i%^BOLD%^an%^WHITE%^"
                  "!  " + ETO->QS + " lets out a gasp and drops the weapon.%^RESET%^", ETO);
        TO->set_property("magic", 1);
        ETO->do_damage("torso", roll_dice(20, 10));
        TO->set_property("magic", -1);
        ETO->force_me("drop haera evaliir");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^The rapier's contoured guard rests "
                "%^BOLD%^%^BLUE%^s%^CYAN%^mo%^BLUE%^ot%^CYAN%^hl%^BLUE%^y %^WHITE%^over your "
                "hand as you take up the weapon.%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^WHITE%^The rapier's contoured guard rests "
              "%^BOLD%^%^BLUE%^s%^CYAN%^mo%^BLUE%^ot%^CYAN%^hl%^BLUE%^y %^WHITE%^over "
              + ETO->QCN + "'s hand as " + ETO->QS + " takes up the weapon.%^RESET%^", ETO);
    return 1;
}

int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You release your hold on the "
                "%^BLACK%^com%^RESET%^%^ORANGE%^fo%^BOLD%^%^BLACK%^rtab%^RESET%^%^ORANGE%^l"
                "%^BOLD%^%^BLACK%^e %^WHITE%^grip of the rapier.%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + "%^BOLD%^%^WHITE%^ releases hold "
              "on the grip of the rapier.%^RESET%^", ETO);
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
    if (random(100) > 36) {
        return 1;
    }
    rand = roll_dice(1, 10);

    if ((rand > 0 && rand < 5) || (rand == 10 && present("elfshadow", EETO))) {
        tell_object(ETO, "%^BOLD%^%^CYAN%^The first rune upon the longsword's blade flares %^GREEN%^br%^RESET%^"
                    "%^GREEN%^i%^BOLD%^llia%^YELLOW%^n%^GREEN%^tly %^CYAN%^as it draws a line of blood across " + targ->QCN + "'s "
                    "flesh!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^CYAN%^The first rune upon the blade of " + ETO->QCN + "'s longsword flares "
                    "%^GREEN%^br%^RESET%^%^GREEN%^i%^BOLD%^llia%^YELLOW%^n%^GREEN%^tly %^CYAN%^as it draws a line of blood across "
                    "your flesh!%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^CYAN%^The first rune upon the blade of " + ETO->QCN + "'s longsword flares "
                  "%^GREEN%^br%^RESET%^%^GREEN%^i%^BOLD%^llia%^YELLOW%^n%^GREEN%^tly %^CYAN%^as it draws a line of blood across "
                  + targ->QCN + "'s flesh!%^RESET%^", ({ ETO, targ }));
        TO->set_property("magic", 1);
        targ->do_damage(targ->return_target_limb(), roll_dice(2, 10) + 2);
        TO->remove_property("magic");
    }

    if (rand > 3 && rand < 7) {
        tell_object(ETO, "%^BOLD%^%^GREEN%^The longsword's second rune emits a sudden flash of %^RESET%^%^GREEN%^"
                    "virid%^YELLOW%^i%^RESET%^%^GREEN%^an %^BOLD%^light.  " + targ->QCN + " struggles to blink away the blinding "
                    "afterimage.%^RESET%^");
        tell_object(targ, "%^BOLD%^%^GREEN%^" + ETO->QCN + "'s longsword emits a sudden flash of %^RESET%^%^GREEN%^"
                    "virid%^YELLOW%^i%^RESET%^%^GREEN%^an %^BOLD%^light, and the world disappears in a blinding white afterimage!"
                    "%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^GREEN%^" + ETO->QCN + "'s longsword emits a sudden flash of %^RESET%^%^GREEN%^"
                  "virid%^YELLOW%^i%^RESET%^%^GREEN%^an %^BOLD%^light from the fourth rune upon its blade, and you barely turn "
                  "away in time to avoid being blinded by it!%^RESET%^", ({ ETO, targ }));
        targ->set_temporary_blinded(2);
    }

    if (rand > 5 && rand < 8) {
        tell_object(ETO, "%^BOLD%^%^BLUE%^The third rune upon the longsword %^GREEN%^c%^YELLOW%^r%^GREEN%^ack"
                    "%^WHITE%^l%^GREEN%^es %^BLUE%^with light, and a sudden burst of energy races down the blade to throw "
                    + targ->QCN + " to the ground!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLUE%^The third rune upon " + ETO->QCN + "'s longsword %^GREEN%^c%^YELLOW%^r"
                    "%^GREEN%^ack%^WHITE%^l%^GREEN%^es %^BLUE%^with light, and a sudden burst of energy races down the blade to "
                    "throw you to the ground!%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^BLUE%^The third rune upon " + ETO->QCN + "'s longsword %^GREEN%^c%^YELLOW%^r"
                  "%^GREEN%^ack%^WHITE%^l%^GREEN%^es %^BLUE%^with light, and a sudden burst of energy races down the blade to "
                  "throw " + targ->QO + " to the ground!%^RESET%^", ({ ETO, targ }));
        targ->set_paralyzed(roll_dice(1, 10) + 10, "You are struggling to stand up!");
    }

    if (rand > 7 && rand < 10) {
        targ->do_damage("torso", roll_dice(2, 10) + 2);
        tell_object(ETO, "%^YELLOW%^The longsword's fourth rune %^RESET%^%^GREEN%^pul%^BOLD%^s%^RESET%^%^GREEN%^"
                    "es %^YELLOW%^brightly, and a burst of speed runs through your body to lead you into another strike!%^RESET%^");
        tell_room(EETO, "%^YELLOW%^The fourth rune upon " + ETO->QCN + "'s blade %^RESET%^%^GREEN%^pul%^BOLD%^s"
                  "%^RESET%^%^GREEN%^es %^YELLOW%^brightly, and " + ETO->QS + " strikes again in a sudden burst of speed!"
                  "%^RESET%^", ETO);
        ETO->execute_attack();
    }

    if (rand == 10 && !present("elfshadow", EETO)) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The fifth rune upon the longsword's blade lights up with a %^RESET%^"
                    "%^GREEN%^soft j%^CYAN%^ad%^GREEN%^e glow%^BOLD%^%^WHITE%^, and as you blink, you realise the %^RESET%^%^BLUE%^"
                    "shadowy silhouette %^BOLD%^%^WHITE%^of an elven figure stands at your side in a protective stance!%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^WHITE%^The fifth rune upon " + ETO->QCN + "'s blade lights up with a %^RESET%^"
                  "%^GREEN%^soft j%^CYAN%^ad%^GREEN%^e glow%^BOLD%^%^WHITE%^, and as you blink, you realise the %^RESET%^%^BLUE%^"
                  "shadowy silhouette %^BOLD%^%^WHITE%^of an elven figure stands at " + ETO->QP + " side in a protective "
                  "stance!", ETO);
        ob = new("/d/retired/obj/elfshadow.c");
        ob->move(EETO);
        ob->force_me("protect " + ETO->query_name());
        ETO->add_follower(ob);
    }
    return 1;
}
