#include <std.h>
inherit OBJECT;

int number, *shave;

void create(){
    ::create();
    set_name("six sided die");
    set_id(({"die","dice","six-sided die","dragonbone die"}));
    set_short("%^RESET%^%^ORANGE%^s%^GREEN%^i%^ORANGE%^x-s%^GREEN%^i%^ORANGE%^ded "
"d%^GREEN%^i%^ORANGE%^e made from %^BOLD%^%^BLACK%^dr%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^g"
"%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^nb%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ne%^RESET%^");
    set_long("%^CYAN%^C%^ORANGE%^arved from a single piece of %^BOLD%^%^BLACK%^dr"
"%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^g%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^nb%^RESET%^%^RED%^"
"o%^BOLD%^%^BLACK%^ne %^RESET%^%^ORANGE%^this die is %^WHITE%^smooth %^ORANGE%^to the "
"touch, and even though it feels lighter than a normal die, it also feels %^RED%^ind"
"%^BOLD%^e%^RESET%^%^RED%^str%^BOLD%^u%^RESET%^%^RED%^ct%^BOLD%^i%^RESET%^%^RED%^ble"
"%^ORANGE%^. Pieces of %^BOLD%^%^GREEN%^flawless e%^RESET%^%^CYAN%^m%^BOLD%^%^GREEN%^e"
"%^RESET%^%^GREEN%^r%^BOLD%^a%^RESET%^%^CYAN%^l%^BOLD%^%^GREEN%^d%^RESET%^%^ORANGE%^ on "
"the sides form numbering d%^CYAN%^o%^ORANGE%^ts from %^BOLD%^1 %^RESET%^%^ORANGE%^"
"through %^BOLD%^6%^RESET%^%^ORANGE%^.%^RESET%^");
    number = 1;
    set_value(25);
    set_weight(1);
}

string query_short(){
    string sshort;
    sshort = ::query_short();
    if(!living(ETO)) sshort += ", <"+number+"> up";
    return sshort;
}

void init(){
    ::init();
    add_action("roll","roll");
}

int roll(string str){
    if(ETO != TP || !id(str)) return notify_fail("Roll what?\n");

    tell_room(ETP, TPQCN+" throws the dice out and watches them roll",TP);
    tell_object(TP,"You throw the dice out and watch them roll.");

    number = random(7)+1;
    if(number > 6) number = 6; // weighted die!

    tell_room(ETP,"The die rolls, and stops with "+number+" up.");
    move(ETP);
    return 1;
}
