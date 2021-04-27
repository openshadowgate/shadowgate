// pet spider monkey!
#include <std.h>
inherit "/std/riding_animal.c";

void create(){
    object ob;
    ::create();
    set_name("spider monkey");
    set_short("%^BOLD%^%^BLACK%^agi%^RESET%^l%^BOLD%^%^BLACK%^e spider mo%^RESET%^n%^BOLD%^%^BLACK%^key%^RESET%^");
    set_id( ({"monkey","spider monkey","agile monkey","agile spider monkey"}) );
    set_long("%^RESET%^This tiny creature is in constant %^RED%^mo"
"%^ORANGE%^t%^RED%^ion%^RESET%^, blinking its intelligent %^BLUE%^ink-black "
"%^RESET%^eyes as it peers around.  Its coat is mostly of a %^BOLD%^"
"%^BLACK%^dusty black%^RESET%^ shade, save for a portion of %^BOLD%^"
"%^WHITE%^white %^RESET%^around its face and upper shoulders.  It has "
"long, %^CYAN%^dex%^BOLD%^t%^RESET%^%^CYAN%^ero%^GREEN%^u%^CYAN%^s "
"%^RESET%^fingers and toes that would obviously serve it well to grip and "
"climb, and a long tail that curls at the end as if it were another "
"limb.");
    set_level(10);
    set_value(0);
    set_race("monkey");
    if(random(2)) set_gender("female");
    else set_gender("male");
    set_body_type("quadruped");
    set_attack_limbs( ({"left foreleg", "right foreleg"}) );
    set_size(1);
    set_max_hp(120);
    set_hd(10,1);
    set_hp(120);
    set_overall_ac(-3);
    set_exp(1);
    set_max_distance(250);
    set_attacks_num(2);
    set_damage(1,4);
    set_base_damage_type("bludgeoning");
    set_emotes(1, ({"%^GREEN%^The spider monkey blinks its inky black eyes, peering about with bright intelligence.%^RESET%^","%^BLUE%^The spider monkey scratches behind its ear with its long narrow fingers.%^RESET%^","%^ORANGE%^With a tilt of its head, the spider monkey lets out a small querilous screech.%^RESET%^"}), 0);
    command("message in scampers in.");
    command("message out scampers out $D.");
}

int enter(string str){
    notify_fail("You can't ride a monkey!\n");
    return 0;
}

int handle_critter(string str) {
    tell_room(ETP,"The monkey seems uninterested in "+TPQCN+"'s attempts to handle it.", TP);
    return notify_fail("The monkey blatantly ignores you.\n");
}

int give_me_away(string str){
    return notify_fail("Your monkey refuses to leave you!\n");
    return 0;
}
