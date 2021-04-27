
#include <std.h>

inherit OBJECT;

int number;

int *shave;



void create(){
    ::create();
    set_name("6 sided die");
    set_id(({"die","dice","6-sided dice"}));
    set_short("six-sided die");

    set_long("%^BOLD%^%^WHITE%^A carved cube of animal bone.  Each of the six sides has a %^RESET%^%^MAGENTA%^strange picture %^BOLD%^%^WHITE%^etched into its surface.%^RESET%^");

    number = 1;
    set_value(2);
    set_weight(2);

}

string query_short(){
    string sshort;
    sshort = ::query_short();
    if(!living(ETO)) {
        sshort += ",%^RESET%^%^CYAN%^ <"+number+"> up";
    }
    return sshort;
}

init(){
    ::init();

    add_action("roll","roll");
}


int roll(string str){
      if(ETO != TP || !id(str)){
        return notify_fail("Roll what?\n");
    }
  switch(random(6)){
   case 0:
    number = "%^BOLD%^%^BLACK%^the picture of a black stag%^RESET%^";
    break;
   case 1:
      number = "%^RESET%^a %^BOLD%^%^RED%^gl%^RESET%^%^RED%^o%^BOLD%^wing %^RESET%^%^RED%^red eye%^RESET%^";
    break;
   case 2:
    number = "%^RESET%^the carving of a skull";
    break;
   case 3:
    number = "the carving of %^BOLD%^%^BLACK%^black antlers %^RESET%^on a %^RED%^red field%^RESET%^";
    break;
   case 4:
    number = "%^BOLD%^%^WHITE%^the depiction of crossbones";
    break;
   case 5:
    number = "%^RESET%^the carving of a skull";
    break;
    }
    tell_room(ETP, TPQCN+" throws the dice out and watches them roll",TP);
    tell_object(TP,"You throw the dice out and watch them roll.");

    //shave logic

    tell_room(ETP,"The die rolls, and stops with "+number+" up.");
    move(ETP);
    return 1;
}
