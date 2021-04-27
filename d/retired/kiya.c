#include <std.h>
#include <daemons.h>
inherit MONSTER;

#define badbeasts ({ "bugbear", "gnoll", "goblin", "hobgoblin", "kobold", "ogre", "ogre-mage", "orc", "drow", "half-drow" })

void create()
{
    object ob;
    ::create();
    set_name("Kiya");
    set_short("%^RESET%^%^GREEN%^K%^BOLD%^i%^RESET%^%^GREEN%^ya El%^CYAN%^la%^GREEN%^ew%^BOLD%^y%^RESET%^%^GREEN%^n, %^RESET%^S%^BOLD%^e%^RESET%^l%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^n%^RESET%^e's M%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^on%^RESET%^s%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^a%^RESET%^d%^BOLD%^%^WHITE%^o%^RESET%^w");
    set_id(({ "kiya", "Kiya", "elf", "moonshadow", "moon shadow" }));
    set_long("%^RESET%^%^CYAN%^Kiya carries the common appearance of her kin, with smooth %^RESET%^ala%^BOLD%^b%^RESET%^ast"
             "%^BOLD%^e%^RESET%^r%^CYAN%^ skin, and the fine-boned features so distinct to elvenkind.  Her eyes are a deep shade of "
             "%^GREEN%^eme%^BOLD%^r%^RESET%^%^GREEN%^ald green%^CYAN%^, flecked with sparks of %^BOLD%^%^GREEN%^li%^YELLOW%^g%^GREEN%^"
             "ht%^RESET%^%^GREEN%^e%^BOLD%^r %^RESET%^%^CYAN%^color within.  Long, %^BOLD%^%^BLACK%^jet-black %^RESET%^%^CYAN%^hair is "
             "bound back in several intertwined braids, with a few loose strands falling about her face. Its midnight hue is broken by "
             "a single streak of %^RESET%^p%^BOLD%^ur%^RESET%^e s%^BOLD%^il%^RESET%^ve%^BOLD%^r %^RESET%^%^CYAN%^that %^RESET%^shi"
             "%^BOLD%^%^BLACK%^mm%^RESET%^ers %^CYAN%^with any movement.  From amidst the braided locks rise two pointed elven ears, "
             "a further tell-tale sign of her heritage.  Her %^RED%^li%^MAGENTA%^th%^RED%^e %^CYAN%^figure is shrouded in garments of "
             "%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^CYAN%^and %^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r"
             "%^CYAN%^, and is protected by a suit of gleaming %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^%^CYAN%^chainmail"
             ".%^RESET%^");
    set_race("elf");
    set_body_type("human");
    set_gender("female");
    set_alignment(4);
    set_class("fighter");
    set_class("cleric");
    set_hd(38, 8);
    set_guild_level("fighter", 36);
    set_mlevel("fighter", 36);
    set_guild_level("cleric", 36);
    set_mlevel("cleric", 36);
    set_max_hp(1500);
    set_hp(1500);
    set_exp(1);
    set_overall_ac(-25);
    set("aggressive", 0);
    set_stats("dexterity", 18);
    set_stats("strength", 18);
    set_property("full attacks", 1);
    set_property("no paralyze", 1);
    set_property("no trip", 1);
    set_property("no knockdown", 1);
    set_property("no disarm", 1);
    set_diety("selune");
    set_wielding_limbs(({ "left hand", "right hand" }));
    command("message in %^RESET%^%^GREEN%^stalks in with %^ORANGE%^soft footfalls%^GREEN%^.%^RESET%^");
    command("message out %^RESET%^%^GREEN%^steps quietly %^WHITE%^$D%^RESET%^%^GREEN%^, her cloak %^BOLD%^%^WHITE%^sw%^RESET%^i%^BOLD%^%^BLACK%^rl%^RESET%^i%^BOLD%^ng %^RESET%^%^GREEN%^around her.%^RESET%^");
    set_spoken("elven");
    command("speech %^RESET%^%^GREEN%^speak in %^ORANGE%^soft%^GREEN%^, %^CYAN%^flowing %^GREEN%^tones%^RESET%^");
    add_money("gold", random(100) + 400);
    add_money("platinum", random(30) + 200);
    add_money("electrum", random(100) + 500);
    ob = new("/d/avatars/nienne/elfboots");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wear boots");
    ob = new("/d/avatars/nienne/elvenchain");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wear chain");
    ob = new("/d/common/obj/sheath/sheath_medium");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    ob->set_short("%^BOLD%^%^WHITE%^white leather sheath%^RESET%^");
    command("wear sheath");
    ob = new("/d/retired/obj/moonblade2");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("sheath rapier");
    ob = new("/d/retired/obj/moonlight_robe");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wear robe");
    set_monster_feats(({ "parry" }));
    set_funcs(({ "flame_me", "flame_me", "flame_me", "zap_me" }));
    set_func_chance(30);
    set_property("add kits", 30);
    set_property("no steal", 1);
    set_moving(1);
    set_speed(90);
    set_nogo(({ "/d/player_houses/kiya/rooms/path1" }));
}

void flame_me(object targ)
{
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    if (!present(targ->query_name(), ETO)) {
        return;
    }
    if (!sizeof(TO->query_wielded())) {
        return;
    }
    tell_room(ETO, "%^BOLD%^%^CYAN%^Kiya lifts the rapier horizontally before her eyes, her free hand rising to press against the flat of the blade as she barks a word of command.%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^WHITE%^Sudden flames of s%^YELLOW%^e%^WHITE%^ari%^RED%^n%^WHITE%^g white burst into life around " + targ->QCN + ", momentarily enshrouding " + targ->QO + " in a pillar of blazing fire!%^RESET%^", targ);
    tell_object(targ, "%^BOLD%^%^WHITE%^Sudden flames of s%^YELLOW%^e%^WHITE%^ari%^RED%^n%^WHITE%^g white burst into life around you, coursing across your skin in a blaze of agony!%^RESET%^", targ);
    targ->do_damage(targ->return_target_limb(), roll_dice(36, 10));
}

void zap_me(object targ)
{
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    if (!present(targ->query_name(), ETO)) {
        return;
    }
    tell_room(ETO, "%^BOLD%^%^WHITE%^Spreading her arms wide, Kiya calls upon Selune as her hair flares wildly in a sudden charge of energy, a corona of %^BOLD%^%^BLACK%^sh%^RESET%^ad%^BOLD%^%^BLACK%^ow %^WHITE%^about her pale face.%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^YELLOW%^A crack of thunder echoes through the trees as an %^WHITE%^inca%^YELLOW%^n%^WHITE%^descent %^YELLOW%^bolt of white lightning races down from above to strike " + targ->QCN + " directly!%^RESET%^", targ);
    tell_object(targ, "%^BOLD%^%^YELLOW%^A crack of thunder echoes through the trees as an %^WHITE%^inca%^YELLOW%^n%^WHITE%^descent %^YELLOW%^bolt of white lightning races down from above to strike you directly!%^RESET%^", targ);
    targ->do_damage(targ->return_target_limb(), roll_dice(36, 8));
    targ->set_paralyzed(20 + random(5), "%^BOLD%^%^WHITE%^You're still shaking from the impact of the lightning!%^RESET%^");
}

void die(object ob)
{
    tell_room(ETO, "%^BOLD%^%^WHITE%^Kiya whispers an urgent prayer and disappears suddenly, leaving behind a few moonmotes fluttering to the ground!%^RESET%^");
    TO->move("/d/shadowgate/void");
    TO->remove();
}

void heart_beat()
{
    ::heart_beat();
    if (sizeof(TO->query_attackers()) && !sizeof(TO->query_wielded())) {
        tell_room(ETO, "%^BOLD%^%^WHITE%^Kiya skips back a pace and reaches for her weapon!%^RESET%^");
        force_me("draw rapier");
        tell_room(ETO, "%^BOLD%^%^WHITE%^She lifts the gleaming blade, her free hand falling to a defensive posture at her side.%^RESET%^");
    }
    if (!sizeof(TO->query_attackers()) && sizeof(TO->query_wielded())) {
        tell_room(ETO, "%^BOLD%^%^WHITE%^The threat gone, Kiya lowers her weapon.%^RESET%^");
        force_me("sheath rapier");
    }
}

void catch_say(string msg)
{
    string spoken;
    spoken = TP->query_spoken();
    call_out("reply_fun", 1, msg, TP, spoken);
}

void reply_fun(string msg, object who, string mylang)
{
    string name, myrace;
    name = who->query_name();
    myrace = (string)who->query_race();
    if (!msg || !objectp(who)) {
        return;
    }
    if (TP->query_invis()) {
        return;
    }

    if ((strsrch(msg, "ello") != -1 || strsrch(msg, "Hi") != -1 || strsrch(msg, "reeting") != -1 || strsrch(msg, "eya") != -1)) {
        if (myrace == "elf") {
            force_me("speak elven");
            force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M turns to $N with a smile.%^RESET%^");
            write("");
            force_me("say %^BLUE%^'%^CYAN%^greetings, cousin. My name is Kiahnlliya, and this is my home.%^BLUE%^'%^RESET%^");
            force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M gestures to the surrounding trees.%^RESET%^");
            write("");
            force_me("say %^BLUE%^'%^CYAN%^you are welcome to stay here for as long as you need.%^BLUE%^'%^RESET%^");
            if ((int)who->query_level() > 34) {
                force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M considers $N a moment longer.%^RESET%^");
                write("");
                force_me("say %^BLUE%^'%^CYAN%^you look to be quite the competent traveller, cousin. If it were not too much, might I ask your assistance with a task?%^BLUE%^'%^RESET%^");
                force_me("emoteat " + name + " %^BOLD%^%^WHITE%^A hopeful smile appears on $M's face.%^RESET%^");
                write("");
            }
            return;
        }
        force_me("speak common");
        if (member_array(myrace, badbeasts) == -1) {
            force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M turns to $N and gives a small nod.%^RESET%^");
            write("");
            force_me("say %^BLUE%^'%^CYAN%^greetings, stranger. My name is Kiya, and this is my home.%^BLUE%^'%^RESET%^");
            force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M gestures to the surrounding trees.%^RESET%^");
            write("");
            force_me("say %^BLUE%^'%^CYAN%^if you bring no trouble with you, you are welcome to stay for a time.%^BLUE%^'%^RESET%^");
            if ((int)who->query_level() > 34 && myrace == "half-elf") {
                force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M considers $N a moment longer.%^RESET%^");
                write("");
                force_me("say %^BLUE%^'%^CYAN%^you look to be quite the competent traveller, stranger. Might I ask your assistance with a task?%^BLUE%^'%^RESET%^");
                force_me("emoteat " + name + " %^BOLD%^%^WHITE%^A hopeful smile appears on $M's face.%^RESET%^");
                write("");
            }
            return;
        }
        force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M narrows her eyes as she notices $N.%^RESET%^");
        write("");
        force_me("say %^BLUE%^'%^CYAN%^begone from here, creature. I will warn you, but only once.%^BLUE%^'%^RESET%^");
        force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M gestures for $N to leave.%^RESET%^");
        write("");
        return;
    }
    if (strsrch(msg, "help") != -1 || strsrch(msg, "task") != -1 || strsrch(msg, "assistance") != -1) {
        if (myrace == "elf" || myrace == "half-elf") {
            force_me("speak elven");
            if (myrace == "half-elf") {
                force_me("speak common");
            }
            if ((int)who->query_level() > 34) {
                force_me("say %^BLUE%^'%^CYAN%^I've been tasked with the destruction of an artifact of power. A world-destroying blade, known as the Ragnarok.%^BLUE%^'%^RESET%^");
                force_me("say %^BLUE%^'%^CYAN%^if ever you come across such a weapon, please, return it to me that I might dispose of it. I would be glad to ask my Lady to reward you in kind for such efforts.%^BLUE%^'%^RESET%^");
                force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M smiles warmly.%^RESET%^");
                write("");
                return;
            }
            force_me("say %^BLUE%^'%^CYAN%^I'm afraid the task may yet be beyond you, my friend. In time, perhaps.%^BLUE%^'%^RESET%^");
            force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M smiles warmly.%^RESET%^");
            write("");
            return;
        }
        force_me("speak common");
        if (member_array(myrace, badbeasts) == -1) {
            force_me("say %^BLUE%^'%^CYAN%^My thanks for the offer, friend, but do not worry yourself.%^BLUE%^'%^RESET%^");
            force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M smiles warmly.%^RESET%^");
            write("");
            return;
        }
        force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M only frowns and shakes her head.%^RESET%^");
        write("");
        force_me("say %^BLUE%^'%^CYAN%^begone from here, creature. I will warn you, but only once.%^BLUE%^'%^RESET%^");
        return;
    }
}

void receive_given_item(object obj)
{
    string name, myrace;
    object ob;
    if (!objectp(obj)) {
        return;
    }
    if (!objectp(TP)) {
        return;
    }
    name = TPQN;
    myrace = (string)TP->query_race();
    if (myrace == "elf") {
        force_me("speak elven");
    }else {
        force_me("speak common");
    }

    if (base_name(obj) != "/d/islands/common/obj/new/ragnarok") {
        force_me("say %^BLUE%^'%^CYAN%^My thanks, but I have no need of this.%^BLUE%^'%^RESET%^");
        force_me("give " + obj->query_name() + " to " + name + "");
        return;
    }
    if (myrace == "elf") {
        force_me("speak elven");
        force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M smiles radiantly as she accepts the blade.%^RESET%^");
        write("");
        force_me("say %^BLUE%^'%^CYAN%^I cannot thank you enough, cousin. I shall see it dealt with immediately! But let my thanks, and that of my church, be more than words.%^BLUE%^'%^RESET%^");
        force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M lifts a hand, fingers loosely inwards as she makes a motion towards $N and speaks a prayer to Selune.%^RESET%^");
        write("");
        tell_room(ETO, "%^BOLD%^%^CYAN%^In a bright flash, a gleaming longsword appears in the grass at " + TP->QCN + "'s feet!%^RESET%^", TP);
        tell_object(TP, "%^BOLD%^%^CYAN%^In a bright flash, a gleaming longsword appears in the grass at your feet!%^RESET%^");
        ob = new("/d/retired/obj/moonblade");
        ob->move(ETO);
        force_me("say %^BLUE%^'%^CYAN%^use it well, cousin.%^BLUE%^'%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^WHITE%^Kiya whispers an urgent prayer and disappears suddenly, leaving behind a few moonmotes fluttering to the ground!%^RESET%^");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    if (myrace == "half-elf") {
        force_me("speak common");
        force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M smiles radiantly as she accepts the blade.%^RESET%^");
        write("");
        force_me("say %^BLUE%^'%^CYAN%^I cannot thank you enough, friend. I shall see it dealt with immediately! But let my thanks, and that of my church, be more than words.%^BLUE%^'%^RESET%^");
        force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M lifts a hand, fingers loosely inwards as she makes a motion towards $N and speaks a prayer to Selune.%^RESET%^");
        write("");
        tell_room(ETO, "%^BOLD%^%^CYAN%^In a bright flash, a gleaming longsword appears in the grass at " + TP->QCN + "'s feet!%^RESET%^", TP);
        tell_object(TP, "%^BOLD%^%^CYAN%^In a bright flash, a gleaming longsword appears in the grass at your feet!%^RESET%^");
        ob = new("/d/retired/obj/moonblade");
        ob->move(ETO);
        force_me("say %^BLUE%^'%^CYAN%^use it well, friend.%^BLUE%^'%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^WHITE%^Kiya whispers an urgent prayer and disappears suddenly, leaving behind a few moonmotes fluttering to the ground!%^RESET%^");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    force_me("speak common");
    force_me("emoteat " + name + " %^BOLD%^%^WHITE%^$M smiles radiantly as she accepts the blade.%^RESET%^");
    write("");
    force_me("say %^BLUE%^'%^CYAN%^I cannot thank you enough, friend. I shall see it dealt with immediately!%^BLUE%^'%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^WHITE%^Kiya whispers an urgent prayer and disappears suddenly, leaving behind a few moonmotes fluttering to the ground!%^RESET%^");
    TO->move("/d/shadowgate/void");
    TO->remove();
    return;
}
