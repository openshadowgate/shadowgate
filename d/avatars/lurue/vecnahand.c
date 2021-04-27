#include <std.h>
#include <daemons.h>
#define WAIT_TIME 28800  /* 8 hours */
inherit ARMOUR;

int query_usable_power(string str);
mapping USED;
int WORNFLAG;

void create(){
    ::create();
    USED = ([]);
    USED["caress"] = 0;
    USED["heal"] = 0;
    USED["bolt"] = 0;
    set_name("a blackened hand");
    set_id( ({"hand", "blackened hand"}) );
    set_short("%^BOLD%^%^BLACK%^a blackened hand%^RESET%^");
    set_long("%^RESET%^The surface of this hand is %^BOLD%^%^BLACK%^black "
"%^RESET%^and shriveled, as though through some form of damage.  %^RED%^Burnt "
"%^RESET%^perhaps, or %^BLUE%^rotted%^RESET%^, it is hard to tell.  The fingers "
"are permanently curled forwards, as if they can no longer straighten fully.  "
"Oddly, the damaged effect only travels as far as the wrist, where it is cut "
"off abruptly and met with normal, %^BOLD%^%^WHITE%^healthy %^RESET%^skin.");
    set_type("ring");
    set_weight(2);
    set_value(0);
    set_size(2);
    set_limbs( ({ "left hand" }) );
    set_property("enchantment",-1);
    set_ac(1);
    set_wear((:TO, "extra_wear":));
    set_remove((:TO, "extra_remove":));
    WORNFLAG = 0;
}

void init(){
    ::init();
    if (WORNFLAG && ETO==TP) TP->force_me("wear blackened hand");
    add_action("fatal_caress", "caress");
    add_action("full_heal", "healing");
    add_action("bolt", "bolt");
}

int extra_wear(){
    tell_object(TP, "%^BOLD%^%^BLACK%^The blackened skin of your hand reminds you of Vecna's power.%^RESET%^");
   TO->set_overallStatus(100);
    if(!WORNFLAG) WORNFLAG = 1;
    return 1;
}

int extra_remove(){
    tell_object(TP, "%^BOLD%^%^BLACK%^A voice laughs in your head: "
"%^RESET%^%^MAGENTA%^We are one now, you shall never be rid of me as long as "
"you live!%^RESET%^");
    return 1;
}

int query_usable_power(string str){
    int curr_time, used_time, temp;

    curr_time = time();
    used_time = USED[str];
    temp = curr_time - used_time;
    if (temp > WAIT_TIME) return 1;
    return 0;
}

int fatal_caress(string str){
    object ob;
    int locflag;

    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
        return 1;
    }
    if (!str || !ob = present(str, ETP)) {
        tell_object(TP, "Caress who?");
        return 1;
    }
    if (!query_usable_power("caress")) {
        tell_object(TP, "It is too soon to use that again!");
        return 1;
    }
    if (!TO->query_worn()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 1;
    }
    if (ob->query_property("no death")) {
        tell_object(TP, "You cannot caress that!");
        return 1;
    }
    if (interactive(ob) && (!"daemon/saving_d"->saving_throw(ob,"paralyzation_poison_death")))
      locflag = 1;
    if (!interactive(ob)) locflag = 1;

    if (locflag) {
      if (((int)ob->query_max_hp() - (int)ob->query_hp()) < ((int)ob->query_max_hp()/2)) {
        tell_object(TP, "%^BOLD%^%^BLACK%^You reach out and caress "+ob->QCN+
" with your blackened hand, but it seems to have no effect.%^RESET%^");
        tell_object(ob, "%^BOLD%^%^BLACK%^You feel a great darkness tugging at "
"your senses as "+TPQCN+" caressses you with "+TP->QP+" blackened hand... but "
"nothing happens.%^RESET%^");
        tell_room(ETP, "%^BOLD%^%^BLACK%^"+ob->QCN+" shivers as "+TPQCN+
" caresses "+ob->QO+" with "+TP->QP+" blackened hand, but nothing happens"
".%^RESET%^", ({TP, ob}));
        return 1;
      }
      tell_object(TP,"%^BOLD%^%^BLACK%^You reach out and caress "+ob->QCN+
" with your blackened hand, and "+ob->QS+" screams in agony!%^RESET%^");
      tell_object(ob, "%^BOLD%^%^BLACK%^You feel a great darkness overwhelm you "
"as "+TPQCN+" caressses you with "+TP->QP+" blackened hand, and a wave of agony "
"washes over you!%^RESET%^");
      tell_room(ETP, "%^BOLD%^%^BLACK%^"+ob->QCN+" screams in great agony as "
+TPQCN+" caresses "+ob->QO+" with "+TP->QP+" blackened "
"hand!%^RESET%^", ({TP, ob}));
        ob->set_hp(((int)ob->query_max_hp()/2));
        TP->kill_ob(ob, 0);
    } else {
        tell_object(TP, "%^BOLD%^%^BLACK%^You reach out and caress "+ob->QCN+
" with your blackened hand, but it seems to have no effect.%^RESET%^");
        tell_object(ob, "%^BOLD%^%^BLACK%^You feel a great darkness tugging at "
"your senses as "+TPQCN+" caressses you with "+TP->QP+" blackened hand... but "
"nothing happens.%^RESET%^");
        tell_room(ETP, "%^BOLD%^%^BLACK%^"+ob->QCN+" shivers as "+TPQCN+
" caresses "+ob->QO+" with "+TP->QP+" blackened hand, but nothing happens"
".%^RESET%^", ({TP, ob}));
        TP->set_paralyzed(3, "Your hand is throbbing in pain.");
        TP->kill_ob(ob, 2);
    }
    USED["caress"] = time();
    return 1;
}

int full_heal(string str){
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
        return 1;
    }
    if (!query_usable_power("heal")) {
        tell_object(TP, "It is too soon to use that again!");
        return 0;
    }
    if (!TO->query_worn()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 0;
    }
    tell_object(TP, "%^MAGENTA%^You chant a small oath and concentrate on the "
"hand.%^RESET%^");
    tell_room(ETP, "%^MAGENTA%^"+TPQCN+" chants a small phrase, and you see "
+TP->QP+" body glow with an unholy black light.%^RESET%^", TP);
    TP->heal((int)TP->query_max_hp()*2);
    USED["heal"] = time();
    return 1;
}

int bolt(string str){
    object ob;

    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",TP);
    }
    if (!str || !ob = present(str, ETP)) {
        tell_object(TP, "Bolt who?");
        return 1;
    }
    if (!query_usable_power("bolt")) {
        tell_object(TP, "It is too soon to use that again!");
        return 1;
    }
    if (!TO->query_worn()) {
        tell_object(TP, "You cannot control the hand if it is not part of you!");
        return 1;
    }
    tell_object(ob, "%^YELLOW%^"+TPQCN+" points a blackened finger at you, and "
"a bolt of pure energy jumps from it at you!%^RESET%^");
    tell_object(TP, "%^YELLOW%^You point a finger at "+ob->QCN+" and a bolt of "
"lightning jumps from your finger at "+ob->QO+"!%^RESET%^");
    tell_room(ETP, "%^YELLOW%^A bolt of lightning jumps from "+TPQCN+"'s finger "
"at "+ob->QCN+"!%^RESET%^", ({TP, ob}));
    if (!"daemon/saving_d"->saving_throw(ob,"spell")) {
        set_property("magic", 1);
        ob->do_damage("torso", roll_dice((int)TP->query_highest_level(),4));
        remove_property("magic");
    } else {
        set_property("magic", 1);
        ob->do_damage("torso", roll_dice((int)TP->query_highest_level(),2));
        remove_property("magic");
    }
    USED["bolt"] = time();
    TP->kill_ob(ob, 1);
    return 1;
}
