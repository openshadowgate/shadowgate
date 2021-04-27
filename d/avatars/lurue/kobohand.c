// Coded by Grendel
// changed "heal" to "healing" on the syntax, as it was interfering with the nwp. Nienne, 09/08.
#include <std.h>
#define KILL_D "/daemon/killing_d.c"
#define VECNA "%^BLACK%^%^BOLD%^V%^RESET%^%^BLUE%^e%^RED%^c%^BOLD%^%^BLUE%^n%^RED%^a%^RESET%^"
#define ADV_D "/adm/daemon/advance_d.c"
#define WAIT_TIME 10800  /* 60*60*3 or 3 hours */
#define LOGFILE "/d/dagger/marsh/tower/obj/handLOG"

inherit WEAPON;


int get_targ_exp_num(object tp);
int query_targ_exp();
int query_fail_percent(object tp);
int query_usable_power(string str);
void evil_msg(object targ);
void see_if_attack(object tp);

mapping USED;
int WIELDEDFLAG;
int FAILEDFLAG;
int ORIG_EXP;
int TARG_EXP;
int counter;

void create(){
    ::create();

    WIELDEDFLAG = 0;
    FAILEDFLAG = 0;
    ORIG_EXP = 0;
    TARG_EXP = 0;
    counter = 0;
    USED = ([]);
    USED["caress"] = 0;
    USED["heal"] = 0;
    USED["bolt"] = 0;
    USED["web"] = 0;
    USED["dis"] = 0;
    USED["fail"] = 0;

    set_name("Claw of the Dracolich");
    set_id( ({"claw","claw of the dracolich","dracolich claw","antediluvian claw"}) );
    set_obvious_short("%^BOLD%^%^BLACK%^an %^WHITE%^an%^RESET%^te%^BOLD%^%^BLACK%^dil%^RESET%^uv%^BOLD%^%^WHITE%^ian %^BLACK%^claw%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^C%^RED%^l%^RESET%^a%^BOLD%^%^BLACK%^w %^WHITE%^o%^BLACK%^f t%^RED%^h%^BLACK%^e %^BOLD%^%^RED%^D%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^ac%^RESET%^o%^BOLD%^%^BLACK%^li%^RESET%^%^RED%^c%^BOLD%^h%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This %^RESET%^%^ORANGE%^desiccated %^BOLD%^%^BLACK%^hand is tipped in claws covered in "
"%^RED%^dr%^RESET%^i%^RED%^e%^BOLD%^d bl%^RESET%^o%^RED%^o%^BOLD%^d%^BOLD%^%^BLACK%^. The flesh looks warped and decayed, "
"and the %^RESET%^%^RED%^dr%^ORANGE%^a%^RED%^co%^ORANGE%^n%^RED%^ic %^BOLD%^%^BLACK%^scales lining its skin look %^WHITE%^"
"crac%^BLACK%^k%^WHITE%^ed%^BLACK%^ and %^BLUE%^w%^RESET%^o%^BLUE%^r%^BOLD%^n%^BLACK%^. At the end of the wrist there is "
"a %^RED%^ragged raw wound %^BLACK%^that %^RESET%^%^GREEN%^o%^BOLD%^o%^BLUE%^z%^GREEN%^es %^BLACK%^with %^RED%^blood "
"%^BLACK%^where the hand had been %^YELLOW%^grafted %^BLACK%^to a its new host, yet never healed completely. The grafted "
"brace of talons seems to hold some %^MAGENTA%^profane %^BLACK%^power, %^YELLOW%^a%^CYAN%^e%^YELLOW%^ons %^BLACK%^old, "
"and %^WHITE%^tw%^BLACK%^i%^WHITE%^tch%^BLACK%^i%^WHITE%^ng %^BLACK%^with %^GREEN%^malice%^BLACK%^.%^RESET%^");
    set_lore("Slain by adventurers years ago, the great white wrym Qurell was nothing but ash and ruin and anger. Left to "
"the bitter nothingness of her icy tomb. Her soul endlessly tormented by the failure at loosing her precious hoard in the "
"twilight years of her life. Centuries of gathering, fighting, collecting, maintaining against the odds, against those "
"that were faster, smarter, meaner. That rage manifesting itself into a single, determined, will, to reclaim what was "
"hers. A rage that shook the mountains and the earth, shattering the walls of the tome and bringing what remained of her "
"down into the snow drifts to languish for a time. Till a brave little kobold happened upon what remained. Even as the "
"little beast scavenged through what remained of the wreckage, the spirit of Qurell scavenged through the kobold's mind, "
"till she happened upon a memory. A memory of a lich and a hand and a way to perhaps begin her quest to reclaim her own. "
"The driving need so strong that the ice slid, a perfect, razor sharp sheet, to sever her left fore-claw even as she "
"pulled all that she was into that small remaining bit. Like the lich of the kobold's memories, she would command this "
"off cast of the draconic line. Use his magic, his skills and his body to forward her own goals.");
    set_property("lore difficulty",10);
    set_wc(5,5);
    set_large_wc(5,5);
    set_weight(2);
    set("value", 10);
    set_size(1);
    set_property("enchantment", 2);
    set_property("able to cast", 1);
    set_prof_type("knuckles");
    set_type("slashing");
    set_wield( (:this_object(), "extra_wield":) );
    set_unwield( (:this_object(), "extra_remove":) );
    set_hit( (:this_object(), "extra_hit":) );
    while (query_property("enchantment") < 2) {
        remove_property("enchantment");
        set_property("enchantment", 2);
    }
}

void init(){
    ::init();
    if (WIELDEDFLAG && ETO==TP) TP->force_me("wield claw of the dracolich");
    add_action("attach", "attach");
    add_action("fatal_caress", "caress");
    add_action("full_heal", "healing");
    add_action("bolt", "bolt");
    add_action("do_web", "web");
    add_action("do_disin", "flame");
}

int extra_wield(){
    if (!WIELDEDFLAG) {
        tell_object(TP, "%^BLUE%^Yeah, right.  You wouldn't be able to hit anything from that.  To 'wield' that thing you'd have to cut off your own hand and attach it to your arm, but that would be insane!");
        return 0;
    }
    if ((string)TPQN != "vecna")
        write_file(LOGFILE, "Vecna's hand wielded on "+ctime(time())+" by "+TPQN+".\n");
    tell_object(TP, "%^RED%^You make a fist with your mummified hand.\n    %^MAGENTA%^A draconic voice whispers in your head:%^BOLD%^%^BLACK%^ We are one once again.");
    TP->add_align_adjust(-3);
    evil_msg(TP);
    return 1;
}

int attach(string str){
    if (!str) return 0;

    if (str != "hand" && str != "hand to arm") return 0;

    if (WIELDEDFLAG) return 0;

    if ((mixed *)TP->query_wielded() != ({})) {
        tell_object(TP, "You have a weapon in your hand.  I think you should unwield it first.");
        return 1;
    }
    if ((int)TP->query_highest_level() < 10) {
        tell_object(TP, "You need more experience to wield that weapon.");
        return 0;
    }
    tell_object(TP, "A strange calm enters your mind as you look at your wrist.\n Suddenly you lash out with the closest blade you can find and cut your hand from your arm!!!");
    tell_object(TP, "As your arm stump bleeds, the mummified hand starts to glow!\n   You slowly bring the hand towards the bloody stump end of your arm, and suddenly the hand reaches out with an unseen force and attaches itself to your arm!!!\n   You suddenly gain feeling in your new hand.");
    tell_object(TP, "%^MAGENTA%^A draconic voice whispers in your head:%^BLUE%^ Now, we are one.  I shall lead you to your proper glory.");
    tell_room(ETP, "You watch in horror as "+TPQCN+" chops off "+TP->QP+
    " own hand, and attaches a mummified hand to the stump of the arm!!!", TP);
	tell_object(TP,"%^B_BLUE%^%^CYAN%^You have attached the Claw of the Dracolich.  Please send an avatarmail to "
		"let the immortals know.%^RESET%^");
    WIELDEDFLAG = 1;
    set_property("death remove", 1);
    ORIG_EXP = TP->query_exp();
    TARG_EXP = get_targ_exp_num(TP);

    set_wc(1,5);
    set_large_wc(1,5);
    set_heart_beat(1);
    TP->add_align_adjust(-10);
    evil_msg(TP);
    if ((string)TPQN != "vecna")
        write_file(LOGFILE, "Vecna's hand attached on "+ctime(time())+" by "+TPQN+".\n");
    TP->force_me("wield claw of the dracolich");
    return 1;
}

int extra_remove(){
    if ((int)ETO->query_hp() < 0) return 1;
    tell_object(TP, "%^MAGENTA%^A draconic voice laughs in your head: %^BOLD%^%^BLACK%^We are one now, you shall never be rid of me!!%^RESET%^");
    return 0;
}

int drop(){
    if (WIELDEDFLAG && !((int)ETO->query_hp() < 0)) return 1;
}

int give(){
    if (WIELDEDFLAG) return 1;
}

void heart_beat(){
    object curr_room, newroom, tp;

    if(!query_wielded())
        return;
    tp = query_wielded();
    if(!objectp(tp))
       return;

    //changed to >= 100 to fix a bug with it never reseting when a mage was using warriors con - Ares
    if (FAILEDFLAG && ((int)tp->query_hp_percent() >= 100) && !tp->query_current_attacker()){
       if(query_usable_power("fail")) {
        FAILEDFLAG = 0;
        tell_object(ETO, "%^CYAN%^You feel the power of the hand flow back into you.");
       }
    }

    if (!curr_room)
        curr_room = environment(tp);
    
    newroom = environment(tp);
    
    if(!objectp(curr_room) || !objectp(newroom))
        return;

    if (newroom != curr_room) {
        curr_room = newroom;
        see_if_attack(ETO);
    }
}

int extra_hit(object targ){
    object tp;

    tp = query_wielded();
    if(!objectp(tp))
      return random(10);

    if ((tp->query_hp_percent() < query_fail_percent(tp) && !FAILEDFLAG) || !random(300)) {
        FAILEDFLAG = 1;
        ETO->set_disable(60);
        tell_object(ETO, "%^MAGENTA%^A draconic voice whispers in your ear:%^RESET%^%^BOLD%^%^BLACK%^YOU FOOL!!  You weak pathetic fool!  You have failed me, and now I shall fail you.");
        USED["fail"] = (time() - 10500);
    }
    if (FAILEDFLAG) return random(5);

    if (!random(8)) {


        tell_object(ETO, "%^BOLD%^%^BLACK%^As the claws %^RED%^slice %^BLACK%^through "+targ->QCN+"'s flesh, a %^GREEN%^horrible wilting %^BLACK%^of the surrounding flesh spreads from the wound! Before your eyes, the very skin ages a %^BLUE%^thousand years%^BLACK%^, turning to %^WHITE%^ash%^BLACK%^!%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLACK%^As "+ETO->QCN+"'s claws %^RED%^slice %^BLACK%^through your flesh, a %^GREEN%^horrible wilting %^BLACK%^of the surrounding flesh spreads from the wound! Before your eyes, the very skin ages a %^BLUE%^thousand years%^BLACK%^, turning to %^WHITE%^ash%^BLACK%^!%^RESET%^");
        tell_room(environment(query_wielded()), "%^BOLD%^%^BLACK%^As "+ETO->QCN+"'s claws %^RED%^slice %^BLACK%^through "+targ->QCN+"'s flesh, a %^GREEN%^horrible wilting %^BLACK%^of the surrounding flesh spreads from the wound! Before your eyes, the very skin ages a %^BLUE%^thousand years%^BLACK%^, turning to %^WHITE%^ash%^BLACK%^!%^RESET%^", ({ETO, targ}) );
        return roll_dice(5,7);
    }
    return roll_dice(3,5);
}

int fatal_caress(string str){
    object ob;
    int locflag;

    if (!str || !ob = present(str, ETP)) {
        tell_object(TP, "Caress who?");
        return 1;
    }
    if (FAILEDFLAG) {
        tell_object(TP, "The power of the hand is failing you!!");
        return 1;
    }
    if (!query_usable_power("caress")) {
        tell_object(TP, "It is too soon to use that again!");
        return 1;
    }
    if (!TO->query_wielded()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 1;
    }
    if (ob->query_property("no death")) {
        tell_object(TP, "You cannot caress that!");
        return 1;
    }

    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
        return 1;
    }
    locflag = 0;
    TP->add_align_adjust(-15);
    evil_msg(TP);
    tell_object(TP, "%^BOLD%^%^BLUE%^You reach out and caress "+ob->QCN+" with your mummified hand.");
    tell_object(ob, "%^BOLD%^%^BLACK%^You feel a great darkness overwhelm you as "+TPQCN+" caressses you with "+
    TP->QP+" diseased and mummified hand...\n    %^RESET%^%^BOLD%^YOU SCREAM IN AGONY!");
    tell_room(ETP, ""+ob->QCN+" screams in great agony as "+TPQCN+" caresses "+ob->query_objective()+" with a strange mummified hand!", ({TP, ob}));

    if (interactive(ob) && (!"daemon/saving_d"->saving_throw(ob,"paralyzation_poison_death"))) locflag = 1;
    if (!interactive(ob)) locflag = 1;

    if (locflag) {
        ob->set_hp(-1);
        ob->do_damage("torso", random(10));
        TP->kill_ob(ob, 0);
        USED["caress"] = time();
        write_file(LOGFILE, "Power caress used FULLY on "+ctime(time())+" by "+TPQN+".\n");
        return 1;
    } else {
        TP->set_paralyzed(10, "Your hand is throbbing in pain.");
        ob->set_hp((int)ob->query_hp()/5);
        ob->do_damage("torso", 1);
        TP->kill_ob(ob, 4);
        USED["caress"] = (time() - 10620); /* wait length is manually set to 3 minutes */
        write_file(LOGFILE, "Power caress used PARTIALLY on "+ctime(time())+" by "+TPQN+".\n");
        return 1;
    }
}

int full_heal(string str){

    if (FAILEDFLAG) {
        tell_object(TP, "The power of the hand is failing you!!");
        return 0;
    }
    if (!query_usable_power("heal")) {
        tell_object(TP, "It is too soon to use that again!");
        return 0;
    }
    if (!TO->query_wielded()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 0;
    }

    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
        return 1;
    }
    write_file(LOGFILE, "Power full heal used on "+ctime(time())+" by "+TPQN+".\n");
    tell_object(TP, "You chant a small oath and concentrate on the hand.");
    tell_room(ETP, "%^BLUE%^"+TPQCN+" chants a small phrase, and you see "+TP->query_possessive()+" body glow with an unholy black light.", TP);
    TP->heal((int)TP->query_max_hp()*2);
    USED["heal"] = time();
    TP->add_align_adjust(-5);
    evil_msg(TP);
    return 1;
}

int bolt(string str){
    object ob;

    if (!str || !ob = present(str, ETP)) {
        tell_object(TP, "Bolt who?");
        return 1;
    }
    if (FAILEDFLAG) {
        tell_object(TP, "The power of the hand is failing you!!");
        return 1;
    }
    if (!query_usable_power("bolt")) {
        tell_object(TP, "It is too soon to use that again!");
        return 1;
    }
    if (!TO->query_wielded()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 1;
    }

    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
    }
    write_file(LOGFILE, "Power bolt used on "+ctime(time())+" by "+TPQN+".\n");
    tell_object(ob, "%^YELLOW%^"+TPQCN+" points a rotten finger at you, and a bolt of pure energy jumps from it at you!");
    tell_object(TP, "%^YELLOW%^You point a finger at "+ob->QCN+" and a bolt of lightning jumps from your finger at "+ob->query_objective()+"!");
    tell_room(ETP, "A bolt of lightning jumps from "+TPQCN+"'s finger at "+ob->QCN+"!", ({TP, ob}));
    if (!"daemon/saving_d"->saving_throw(ob,"spell")) {
        set_property("magic", 1);
        ob->do_damage("torso", roll_dice((int)TP->query_highest_level(), 6));
        remove_property("magic");
    } else {
        set_property("magic", 1);
        ob->do_damage("torso", roll_dice((int)TP->query_highest_level(), 3));
        remove_property("magic");
    }
    USED["bolt"] = time();
    TP->add_align_adjust(-10);
    evil_msg(TP);
    TP->kill_ob(ob, 1);
    return 1;
}

int do_web(string str){
    object ob;

    if (!str || !ob = present(str, ETP)) {
        tell_object(TP, "Web who?");
        return 1;
    }
    if (FAILEDFLAG) {
        tell_object(TP, "The power of the hand is failing you!!");
        return 1;
    }
    if (!query_usable_power("web")) {
        tell_object(TP, "It is too soon to use that power again!");
        return 1;
    }
    if (!TO->query_wielded()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 1;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
        return 1;
    }
    if (ob->query_property("no web")) {
        tell_object(TP,  "You cannot web that!");
        return 1;
    }

    write_file(LOGFILE, "Power web used on "+ctime(time())+" by "+TPQN+".\n");
    new("/cmds/wizard/_web.c")->use_spell(TP, ob->query_name(),45);
    USED["web"] = time();
    TP->add_align_adjust(-10);
    evil_msg(TP);
    return 1;
}

int do_disin(string str){
    object ob;

    if (!str || !ob = present(str, ETP)) {
        tell_object(TP, "Flame who?");
        return 1;
    }
    if (FAILEDFLAG) {
        tell_object(TP, "The power of the hand is failing you!!");
        return 1;
    }
    if (!query_usable_power("dis")) {
        tell_object(TP, "It is too soon to use that again!");
        return 1;
    }
    if (!TO->query_wielded()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 1;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
        return 1;
    }

    tell_object(ob, "%^RED%^%^BOLD%^"+TPQCN+" hurls a great ball of burning death at you!");
    tell_object(TP, "%^BOLD%^%^RED%^You hurl a ball of flaming death at "+ob->QCN);
    tell_room(ETP, "%^BOLD%^%^RED%^"+TPQCN+" throws a flaming ball of death at "+ob->QCN+"!", ({TP, ob}) );
    write_file(LOGFILE, "Power flame used on "+ctime(time())+" by "+TPQN+".\n");

    if (!"daemon/saving_d"->saving_throw(ob,"spell")) {
        set_property("magic", 1);
        ob->do_damage("torso", roll_dice((int)TP->query_highest_level(), 6));
        remove_property("magic");
    } else {
        set_property("magic", 1);
        ob->do_damage("torso", roll_dice((int)TP->query_highest_level(), 3));
        remove_property("magic");
    }
    USED["dis"] = time();
    TP->add_align_adjust(-10);
    evil_msg(TP);
    TP->kill_ob(ob, 1);
    return 1;
}




int get_targ_exp_num(object tp){
    string *classes;
    int i, temp1, temp2;

    temp2 = 0;
    classes = tp->query_classes();
    if (wizardp(tp)) return 100000;
    for (i=0;i<sizeof(classes);i++) {
        temp1 = ADV_D->get_exp(tp->query_class_level(classes[i])+2,classes[i], tp);
        temp2 += temp1 - (ORIG_EXP/sizeof(classes));
    }
    if (temp2 < 250000) return 250000;
    temp2 = temp2 / sizeof(classes);
    return temp2;
}

int query_targ_exp() { return TARG_EXP;}

int query_fail_percent(object tp){
    int curr_exp, x;
    float per;

    curr_exp = tp->query_exp();
    curr_exp -= ORIG_EXP;
    if (curr_exp < 0) return -1;
    if (curr_exp < query_targ_exp()) return 15;
    curr_exp = curr_exp - query_targ_exp();
    per = (to_float(curr_exp)/to_float(1000000))*100;
    x = per;
    if (x > 75) x = 75;
    return x;
}

int query_usable_power(string str){
    int curr_time, used_time, temp;

    curr_time = time();
    used_time = USED[str];
    temp = curr_time - used_time;
    if (temp > WAIT_TIME) return 1;
    return 0;
}

void evil_msg(object targ){
    tell_object(targ, "%^YELLOW%^You can feel the evil of the hand corrupting you!");
    if (!wizardp(targ)) KILL_D->check_align(targ);
}

void see_if_attack(object tp){
    object *liv, ob;

    liv = all_living(environment(tp));
    liv -= ({tp});
    if (!sizeof(liv)) return;
    ob = liv[random(sizeof(liv))];
    if (sizeof(ETO->query_attackers())) return;
    if (!objectp(ob) || !living(ob)) return;
    if (random(100) > query_fail_percent(tp)) return;
    tell_object(ETO, "%^BOLD%^The claw of the dracolich demands blood!");
    ETO->force_me("kill "+ob->query_name());
}
int query_failed(){
    return FAILEDFLAG;
}
