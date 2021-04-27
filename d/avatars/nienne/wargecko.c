// War-lizard concept for kinaro
#include <std.h>
inherit "/std/riding_animal.c";

void create(){
    object ob;
    ::create();
    set_name("gecko");
    set_short("%^RESET%^%^GREEN%^olive-green war-gecko%^RESET%^");
    set_id( ({"gecko","war gecko","war-gecko","green gecko","scaled gecko","scaled war-gecko","lizard"}) );
    set_long("%^CYAN%^Before you is the long reptilian form of an underground "
"lizard, commonly known as a gecko. Its entire hide is coated in scales of a "
"dull %^GREEN%^o%^ORANGE%^l%^GREEN%^ive-gr%^ORANGE%^e%^GREEN%^en %^CYAN%^hue, "
"fading at some points into a %^BOLD%^%^BLACK%^gray %^RESET%^%^CYAN%^shade, "
"probably allowing it a good amount of camouflage in its native environs. "
"However, this beast seems to serve another purpose, judging by the "
"%^RESET%^barded plates %^CYAN%^of armor affixed along its torso and across "
"the ridge of its head. Its feet follow through to narrow toes that each end "
"in a small bulb, which appear to be strongly %^RED%^adh%^MAGENTA%^e%^RED%^"
"sive %^CYAN%^to most surfaces. Its bulbous, lidless %^ORANGE%^amb%^YELLOW%^e"
"%^RESET%^%^ORANGE%^r eyes %^CYAN%^stare forth balefully at its surrounds, as "
"its long scaly tail flicks back and forth.%^RESET%^");
    set_level(10);
    set_value(0);
    set_race("gecko");
    if(random(2)) set_gender("female");
    else set_gender("male");
    set_body_type("reptile");
    set_attack_limbs( ({"left foreleg", "right foreleg"}) );
    set_size(2);
    set_max_hp(100);
    set_hd(10,1);
    set_hp(100);
    set_overall_ac(-3);
    set_exp(1);
    set_max_distance(250);
    set_enter_room("skuttles in on a barded gecko.");
    set_exit_room("skuttles out on a barded gecko.");
    set_vehicle_short("%^RESET%^%^GREEN%^olive-green war-gecko%^RESET%^");
    set_attacks_num(2);
    set_damage(2,4);
    set_base_damage_type("bludgeoning");
    set_emotes(1, ({"%^GREEN%^The gecko suddenly flicks out its%^BLUE%^ "
"tongue%^GREEN%^ to lick one of its eyes.%^RESET%^","%^GREEN%^The gecko "
"flicks its long tail.%^RESET%^","%^GREEN%^The gecko stares balefully around "
"with its %^ORANGE%^bulb%^YELLOW%^o%^RESET%^%^ORANGE%^us "
"eyes%^GREEN%^.%^RESET%^"}), 0);
    ob = new("/d/common/obj/armour/barding");
    ob->move(TO);
    ob->set_short("%^RESET%^protective mithril barding");
    command("wear barding");
    command("message in skuttles in.");
    command("message out skuttles out $D.");
}

int enter(string str){
    int lev, temp;

    lev = TP->query_highest_level();
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" seems unable to mount the gecko!", TP);
        return notify_fail("The gecko won't let you ride!\n");
    }
    set_level(lev*1/2);
    set_mlevel("fighter", lev*1/2);
    set_max_hp(temp*2/3);
    set_damage(2,4);
    set_overall_ac(6 - (lev/2));
    set_hp(query_max_hp());
    return ::enter(str);
    return 1;
}

int handle_critter(string str) {
    tell_room(ETP,"The gecko seems uninterested in "+TPQCN+"'s attempts to handle it.", TP);
    return notify_fail("The gecko blatantly ignores you.\n");
}

int give_me_away(string str){
    return notify_fail("Your gecko refuses to leave you!\n");
    return 0;
}
